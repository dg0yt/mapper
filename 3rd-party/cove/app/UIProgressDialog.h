/*
 * Copyright (c) 2005-2019 Libor Pecháček.
 *
 * This file is part of CoVe 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef COVE_PROGRESSDIALOG_H
#define COVE_PROGRESSDIALOG_H

#include <QObject>
#include <QProgressDialog>
#include <QString>
#include <Qt>

#include "libvectorizer/Vectorizer.h"

class QWidget;

namespace cove {
class UIProgressDialog : public QObject, public ProgressObserver
{
	Q_OBJECT
protected:
	bool canceled;
	QProgressDialog pDialog;

public:
	UIProgressDialog(const QString& labelText, const QString& cancelButtonText,
	                 QWidget* creator = nullptr, Qt::WindowFlags f = {});
	~UIProgressDialog() override;
	void percentageChanged(int percentage) override;
	bool getCancelPressed() override;

signals:
	void percentageUpdated(int percentage);
};
} // cove

#endif