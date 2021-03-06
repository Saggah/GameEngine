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
/// \brief Provide a base implementation of a window

#ifndef BASEIMPLWINDOW__H
#define BASEIMPLWINDOW__H

#include <stdint.h>
#include "Config.h"

namespace window
{
	
//Forward declaration
class Event;
class WindowAttributes;

/// \brief Abstract class for an implementation of a window system
class BaseImplWindow
{
public:
	GE_WINDOW virtual ~BaseImplWindow();

	virtual void start(WindowAttributes * const attributes) = 0;

    ////////////////////////////////////////////////////////////////////////////
    /// \brief Destroy the window.
    ////////////////////////////////////////////////////////////////////////////
    virtual void close() = 0;

    ////////////////////////////////////////////////////////////////////////////
    /// \brief Allow to know is the window exist
    ///
    /// \return \c true if the window exist, \c false is the window has been
    ///         destroyed
    ////////////////////////////////////////////////////////////////////////////
    virtual bool const isAlive() = 0;

	////////////////////////////////////////////////////////////////////////////
	/// \brief Method to herited to handle events
	///
	/// \param[in] p_event The event structure received
	////////////////////////////////////////////////////////////////////////////
	virtual void onEvent(Event const * const p_event) = 0;

    ////////////////////////////////////////////////////////////////////////////
    /// \brief Get the horizontal position of the window
    ///
    /// \sa getPosY()
    /// \sa move()
    ////////////////////////////////////////////////////////////////////////////
    virtual uint16_t const getPosX() = 0;

    ////////////////////////////////////////////////////////////////////////////
    /// \brief Get the vertical position of the window
    ///
    /// \sa getPosX()
    /// \sa move()
    ////////////////////////////////////////////////////////////////////////////
    virtual uint16_t const getPosY() = 0;

    ////////////////////////////////////////////////////////////////////////////
    /// \brief Move the window on the desktop
    ///
    /// \param[in] posX The new horizontal position on the desktop
    /// \param[in] posY The new vertical position on the desktop
    ///
    /// \sa resize()
	/// \sa moveResize()
    ////////////////////////////////////////////////////////////////////////////
    virtual void move(uint16_t const posX, uint16_t const posY) = 0;

    ////////////////////////////////////////////////////////////////////////////
    /// \brief Get the width of the window (in pixel)
    ///
    /// \sa getHeight()
    /// \sa resize()
    ////////////////////////////////////////////////////////////////////////////
    virtual uint16_t const getWidth() = 0;

    ////////////////////////////////////////////////////////////////////////////
    /// \brief Get the height of the window (in pixel)
    ///
    /// \sa getWidth()
    /// \sa resize()
    ////////////////////////////////////////////////////////////////////////////
    virtual uint16_t const getHeight() = 0;

    ////////////////////////////////////////////////////////////////////////////
    /// \brief Allow to resize the window
    ///
    /// \param[in] width The new width of the window
    /// \param[in] height The new height of the window
    ///
    /// \sa move()
	/// \sa moveResize()
    ////////////////////////////////////////////////////////////////////////////
    virtual void resize(uint16_t const width, uint16_t const height) = 0;
	
    ////////////////////////////////////////////////////////////////////////////
	/// \Allow to move and resize the window
	///
	/// \param[in] posX The new horizontal position on the desktop
	/// \param[in] posY The new vertical position on the desktop
	/// \param[in] width The new width of the window
	/// \param[in] height The new height of the window
	///
	/// \sa move()
	/// \sa resize()
    ////////////////////////////////////////////////////////////////////////////
	virtual void moveResize(uint16_t const posX, uint16_t const posY,
							uint16_t const width, uint16_t const height) = 0;

    ////////////////////////////////////////////////////////////////////////////
    /// \brief Allow to show or hide the window
    ///
    /// \details This function don't iconify/maximize the window
    ///
    /// \param[in] visibility \c true to show the window or \c false to hide
    ///
    virtual void setState(char const visibility) = 0;

    ////////////////////////////////////////////////////////////////////////////
    /// \brief Enable or disable the fullscreen mode
	///
	/// \param[in] inFullScreen \c true to switch in fullscreen mode and \c
	///            false to go back in windowed mode
    ////////////////////////////////////////////////////////////////////////////
    virtual void displayFullScreenMode(bool const inFullScreen) = 0;

	////////////////////////////////////////////////////////////////////////////
	/// \brief Show or hide the cursor
	///
	/// \details Useful for example to use your own cursor with a 3D UI
	///
	/// \param[in] isCursorDisplayed \c true to display the cursor and \c false
	///            to hide it
	////////////////////////////////////////////////////////////////////////////
	virtual void displayCursor(bool const isCursorDisplayed) = 0;

	////////////////////////////////////////////////////////////////////////////
	/// \brief Move the cursor to the specified location
	///
	/// \param[in] posX The horizontal position of the cursor
	/// \param[in] posY The vertical position of the cursor
	////////////////////////////////////////////////////////////////////////////
	virtual void moveCursor(uint16_t const posX, uint16_t const posY) = 0;

protected:
    GE_WINDOW static Event s_event;

private:
	virtual void run(WindowAttributes* const attributes) = 0;
};

}

#endif // BASEIMPLWINDOW__H
