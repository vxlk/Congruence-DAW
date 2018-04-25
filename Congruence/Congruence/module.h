/*
==============================================================================

This file is part of the Congruence library.
Copyright (c) 2017 - Tyler Small.

Congruence is an open source library subject to commercial or open-source
licensing.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

CONGRUENCE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES, WHETHER
EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR PURPOSE, ARE
DISCLAIMED.

See license file for details.

==============================================================================
*/

#pragma once

#include "vst3Header.h"

namespace VST3 {

	class ClassInfo {

	private:

	protected:

	public:

	};

	class PluginFactory {
		using ClassInfos = std::vector<ClassInfo>;
		using PluginFactoryPtr = Steinberg::IPtr<Steinberg::IPluginFactory>;

	private:

	protected:

	public:
		explicit PluginFactory(const PluginFactoryPtr& factory) noexcept;
	};

	class module {
	private:

	protected:

	public:
		virtual ~module() noexcept = default;
		virtual bool load(const std::string& path, std::string& errorDescription) = 0;

		PluginFactory factory{ nullptr };
		std::string name;
		std::string path;
	};

} //VST3
