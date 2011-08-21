//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Game Engine Framework
//
// Copyright (C) 2001 - 2009 Tony Richards
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
/// @brief GameClientManager implementation
///
/// Declaration of the GameClientManager interface.
///
///
/// @author Tony Richards trichards@indiezen.com
/// @author Matthew Alan Gray mgray@indiezen.org
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_ENGINE_CLIENT_GAME_CLIENT_MANAGER_HPP_INCLUDED
#define ZEN_ENGINE_CLIENT_GAME_CLIENT_MANAGER_HPP_INCLUDED

#include "../I_GameClientManager.hpp"

#include "../I_GameClientFactory.hpp"
#include "../I_GameClient.hpp"

#include <Zen/Core/Plugins/ServiceCache.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Engine {
namespace Client {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class GameClientManager
:   public I_GameClientManager
{
    /// @name Types
    /// @{
public:
    typedef Zen::Plugins::ServiceCache<I_GameClient, I_GameClientFactory>   serviceCache_type;
    /// @}

    /// @name I_SoundManager implementation
    /// @{
public:
    virtual pService_type create(const std::string& _type, config_type& _config);
    /// @}

    /// @name GameClientManager implementation
    /// @{
public:
    void onFrame(frameDelta_type frameDelta);
    /// @}

    /// @name 'Structors
    /// @{
public:
             GameClientManager();
    virtual ~GameClientManager();
    /// @}

    /// @name Member variables
    /// @{
private:
    serviceCache_type  m_serviceCache;
    /// @}

};  // class SoundManager

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Client
}   // namespace Engine
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_ENGINE_CLIENT_GAME_CLIENT_MANAGER_HPP_INCLUDED