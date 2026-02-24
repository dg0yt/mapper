/*
 *    Copyright 2026 Kai Pastor
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

#include <QtTest>
#include <QTransform>



class QTransformTest : public QObject
{
Q_OBJECT
	
private slots:
	void directTest()
	{
		QTransform qt;
		qt.translate(0.12, -0.02);
		qt.rotate(-0.0);
		qt.scale(1.2, 0.7);
		
		QTransform qt2;
		qt2.setMatrix(qt.m11(), qt.m12(), qt.m13(), qt.m21(), qt.m22(), qt.m23(), qt.m31(), qt.m32(), qt.m33());
		QCOMPARE(qt2, qt);
	}
	
};  // class QTransformTest



QTEST_APPLESS_MAIN(QTransformTest)
#include "qtransform_t.moc"  // IWYU pragma: keep
