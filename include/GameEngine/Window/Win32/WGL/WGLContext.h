﻿/*------------------------------------------------------------------------------
| Copyright (C) 2013  Kévin Seroux <kevin.seroux@orange.fr>                    |
|                                                                              |
| GameEngine is free software: you can redistribute it and/or modify it under  |
| it under the terms of the GNU Lesser General Public License as published by  |
| the Free Software Foundation, either version 3 of the License, or (at your   |
| option) any later version.                                                   |
|                                                                              |
| GameEngine is distributed in the hope that it will be useful, but WITHOUT    |
| ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or        |
| FITNESS FOR A PARTICULAR PURPOSE.  See the Lesser GNU General Public License |
| for more details.                                                            |
|                                                                              |
| You should have received a copy of the GNU Lesser General Public License     |
| along with GameEngine.  If not, see <http://www.gnu.org/licenses/>.          |
\_____________________________________________________________________________*/

/// \file
/// \brief Allow to create a windows context for OpenGL

#ifndef WGL_CONTEXT__H
#define WGL_CONTEXT__H

#include <windows.h>
#include "../../Config.h"
#include <stdint.h>

namespace window
{

//Forward declarations
class WindowAttributes;

/// \brief The class to create an OpenGL context for windows
class WGLContext
{
public:
	GE_WINDOW WGLContext();
	GE_WINDOW ~WGLContext();
	GE_WINDOW void init(WindowAttributes * const attributes,
		HWND const p_handle);
	GE_WINDOW void destroy();

	GE_WINDOW void enable() const;
	void disable() const;
	void swapBuffers() const;

private:
	HDC m_hdc;
	HGLRC m_hglrc;
	HWND m_windowHandle;
	bool m_isDestroyed;
};

inline void WGLContext::disable() const
{
	wglMakeCurrent(m_hdc, 0);
}

inline void WGLContext::swapBuffers() const
{
	SwapBuffers(m_hdc);
}

////////////////////////////////////////////////////////////////////////////////

namespace exception
{

struct GE_WINDOW PixelFormatNotFound
{
	PixelFormatNotFound(const char* const pFile, uint16_t const pLine);

	const char* file;
	uint16_t line;
};

struct GE_WINDOW BadOpenGLVersion
{
	BadOpenGLVersion(char const pMinorVersion, char const pMajorVersion);

	char minorVersion;
	char majorVersion;
};

}

}

#endif //WGL_CONTEXT__H
