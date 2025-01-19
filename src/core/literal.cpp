/*
 * Project OpenOrienteering Mapper
 * 
 * Copyright (C) Kai Pastor
 *
 * OpenOrienteering is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenOrienteering is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenOrienteering.  If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <QLatin1String>

namespace OpenOrienteering
{

#ifndef Mapper_CORE_LITERAL_EXPORT
#define Mapper_CORE_LITERAL_EXPORT extern
#endif

/**
 * A namespace which collects various string constants of type QLatin1String.
 */

namespace literal
{
	Mapper_CORE_LITERAL_EXPORT const QLatin1String count("count");
	Mapper_CORE_LITERAL_EXPORT const QLatin1String flags("flags");
	Mapper_CORE_LITERAL_EXPORT const QLatin1String grid("grid");
	Mapper_CORE_LITERAL_EXPORT const QLatin1String map("map");
	Mapper_CORE_LITERAL_EXPORT const QLatin1String name("name");
	Mapper_CORE_LITERAL_EXPORT const QLatin1String object("object");
	Mapper_CORE_LITERAL_EXPORT const QLatin1String objects("objects");
	Mapper_CORE_LITERAL_EXPORT const QLatin1String opacity("opacity");
	Mapper_CORE_LITERAL_EXPORT const QLatin1String part("part");
	Mapper_CORE_LITERAL_EXPORT const QLatin1String parts("parts");
	Mapper_CORE_LITERAL_EXPORT const QLatin1String rotation("rotation");
	Mapper_CORE_LITERAL_EXPORT const QLatin1String scale("scale");
	Mapper_CORE_LITERAL_EXPORT const QLatin1String symbol("symbol");
	Mapper_CORE_LITERAL_EXPORT const QLatin1String template_string("template");
	Mapper_CORE_LITERAL_EXPORT const QLatin1String templates("templates");
	Mapper_CORE_LITERAL_EXPORT const QLatin1String type("type");
	Mapper_CORE_LITERAL_EXPORT const QLatin1String x("x");
	Mapper_CORE_LITERAL_EXPORT const QLatin1String y("y");
}  // namespace literal
    
}  // namespace OpenOrienteering
