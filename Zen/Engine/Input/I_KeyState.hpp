//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Game Engine Framework
//
// Copyright (C) 2001 - 2010 Tony Richards
// Copyright (C)        2006 Phillip Castaneda (pjcast -- www.wreckedgames.com)
// Copyright (C) 2008 - 2009 Matthew Alan Gray
//
//  This software is provided 'as-is', without any express or implied
//  warranty.  In no event will the authors be held liable for any damages
//  arising from the use of this software.
//
//  Permission is granted to anyone to use this software for any purpose,
//  including commercial applications, and to alter it and redistribute it
//  freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not
//     claim that you wrote the original software. If you use this software
//     in a product, an acknowledgment in the product documentation would be
//     appreciated but is not required.
//  2. Altered source versions must be plainly marked as such, and must not be
//     misrepresented as being the original software.
//  3. This notice may not be removed or altered from any source distribution.
//
//  Tony Richards trichards@indiezen.com 
//  Matthew Alan Gray mgray@indiezen.org
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_ENGINE_INPUT_I_KEY_STATE_HPP_INCLUDED
#define ZEN_ENGINE_INPUT_I_KEY_STATE_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Engine/Input/KeyCodes.hpp>
#include <Zen/Engine/Input/I_KeyModifierState.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Engine {
namespace Input {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class INPUTMANAGER_DLL_LINK I_KeyState
{
    /// @name Types
    /// @{
public:
    /// @}

    /// @name I_KeyState interface
    /// @{
public:
    virtual KeyCode_enum getKeyCode() const = 0;
    
    virtual const I_KeyModifierState& getModifierState() const = 0;

    virtual bool operator==(KeyCode_enum _rhs) const = 0;

    virtual bool operator==(const I_KeyModifierState& _rhs) const = 0;

    virtual bool operator|=(const I_KeyModifierState& _rhs) const = 0;

    virtual bool operator==(const I_KeyState& _rhs) const = 0;

    virtual bool operator<(const I_KeyState& _rhs) const = 0;
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_KeyState();
    virtual ~I_KeyState();
private:
    I_KeyState(const I_KeyState& _keyState);
    I_KeyState& operator=(const I_KeyState& _keyState);
    /// @}

};  // I_KeyState interface

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Input
}   // namespace Engine
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_ENGINE_INPUT_I_KEY_STATE_HPP_INCLUDED
