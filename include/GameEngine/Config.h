/*------------------------------------------------------------------------------
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
/// \brief Defines the macros used by all the modules

#ifndef CONFIG__H
#define CONFIG__H

#if defined(_WIN32) || defined(__CYGWIN__)

    ////////////////////////////////////////////////////////////////////////////
    /// \def
    /// \brief Is defined when you compile with Windows
    ////////////////////////////////////////////////////////////////////////////
    #define WINDOWS_SYSTEM

#elif defined(linux)

    ////////////////////////////////////////////////////////////////////////////
    /// \def
    /// \brief Is defined when you compile with Linux
    ////////////////////////////////////////////////////////////////////////////
    #define LINUX_SYSTEM

#elif defined(__unix) || defined(__unix__)

	////////////////////////////////////////////////////////////////////////////
	/// \def
	/// \brief Is defined when you compile on a Unix system
	////////////////////////////////////////////////////////////////////////////
	#define UNIX_SYSTEM

#else
    #error Your platform is not supported
#endif

////////////////////////////////////////////////////////////////////////////////
/// \def DEBUG
/// \brief Is defined when the cmake tool is configured to compile the engine in
///        Debug mode
////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG
    #define DEBUG
#elif defined(_DEBUG)
    #define DEBUG
#endif

////////////////////////////////////////////////////////////////////////////////
/// \def GAME_ENGINE_EXPORT
///
/// \brief Allow to export classes, functions, ... to Windows DLL
///
/// \details Have the value \c __declspec(dllexport) with Windows and is just
///          defined on others OS
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
/// \def GAME_ENGINE_IMPORT
///
/// \brief Allow to import classes, functions, ... from Windows DLL
///
/// \details Have the value \c __declspec(dllimport) with Windows and is just
///          defined on others OS
////////////////////////////////////////////////////////////////////////////////

#ifdef WINDOWS_SYSTEM
	#define GE_IMPORT __declspec(dllimport)
	#define GE_EXPORT __declspec(dllexport)
#else
    #define GE_IMPORT
    #define GE_EXPORT
#endif


////////////////////////////////////////////////////////////////////////////////
/// \dir GameEngine
/// \brief Directory of the header files of the project
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
/// \dir GameEngine/Common
/// \brief Directory of the header files of the \link common \endlink module
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// \brief Contains all the classes, structures, ... used in all the modules
////////////////////////////////////////////////////////////////////////////////
namespace common {} //Just for doxygen

////////////////////////////////////////////////////////////////////////////////
/// \dir GameEngine/Common/Debug
/// \brief Directory of the header files of the debug tools
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
/// \dir GameEngine/Window
/// \brief Directory of the header files of the \link window \endlink module
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// \brief Contains the classes, structures, ... to manage windows and their
///        events
////////////////////////////////////////////////////////////////////////////////
namespace window {} //Just for doxygen

////////////////////////////////////////////////////////////////////////////////
/// \dir GameEngine/Window/Win32
/// \brief Directory of the header files for the Win32 window implementation
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// \dir GameEngine/Window/X
/// \brief Directory of the header files for the X.org window implementation
////////////////////////////////////////////////////////////////////////////////

#endif //CONFIG__H