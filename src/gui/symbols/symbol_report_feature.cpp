/*
 *    Copyright 2024 Kai Pastor
 *
 *    This file is part of OpenOrienteering.
 *
 *    OpenOrienteering is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    OpenOrienteering is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with OpenOrienteering.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "symbol_report_feature.h"

#include <QAction>
#include <QDesktopServices>
#include <QSaveFile>
#include <QUrl>

#include "core/symbols/html_symbol_report.h"
#include "gui/file_dialog.h"
#include "gui/main_window.h"
#include "gui/map/map_editor.h"
#include "gui/util_gui.h"

namespace OpenOrienteering {


namespace {

QString htmlFileFilter()
{
	static const QString filter_template(QLatin1String("%1 (%2)"));
	QStringList filters = {
	    filter_template.arg(::OpenOrienteering::SymbolReportFeature::tr("HTML"), QLatin1String("*.htm")),
	    ::OpenOrienteering::SymbolReportFeature::tr("All files (*.*)")
	};
	return filters.join(QLatin1String(";;"));
}

}

SymbolReportFeature::SymbolReportFeature(MapEditorController& controller)
: QObject{nullptr}
, controller{controller}
{
	show_action = new QAction(tr("Create symbol set report"), this);
	show_action->setMenuRole(QAction::NoRole);
	show_action->setWhatsThis(Util::makeWhatThis("symbols_menu.html"));
	connect(show_action, &QAction::triggered, this, &SymbolReportFeature::showDialog);
}

SymbolReportFeature::~SymbolReportFeature() = default;

void SymbolReportFeature::setEnabled(bool enabled)
{
	show_action->setEnabled(enabled);
}

void SymbolReportFeature::showDialog()
{
	const auto* map = controller.getMap();
	auto* window = controller.getWindow();
	if (!map || !window)
		return;
	
	const auto file_path = FileDialog::getSaveFileName(
	    window,
	    ::OpenOrienteering::MainWindow::tr("Save file"),
	    {},
	    htmlFileFilter() );
	if (file_path.isEmpty())
		return;
	
	QSaveFile file(file_path);
	if (file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		const auto report = makeHTMLSymbolReport(*map);
		file.write(report.toUtf8());
		if(file.commit())
			QDesktopServices::openUrl(QUrl::fromLocalFile(file_path));
	}
}

}
