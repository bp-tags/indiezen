//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Game Engine Framework
//
// Copyright (C) 2001 - 2009 Tony Richards
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
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_ENGINE_RENDERING_SCENE_MANAGER_HPP_INCLUDED
#define ZEN_ENGINE_RENDERING_SCENE_MANAGER_HPP_INCLUDED

#include <Zen/Core/Scripting.hpp>

#include "../I_SceneManager.hpp"

#include "../I_SceneServiceFactory.hpp"
#include "../I_SceneService.hpp"

#include <Zen/Core/Plugins/ServiceCache.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Engine {
namespace Rendering {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class SceneManager
:   public I_SceneManager
{
    /// @name Types
    /// @{
public:
    typedef Zen::Plugins::ServiceCache<I_SceneService, I_SceneServiceFactory>   SceneServiceCache_type;
    /// @}

    /// @name I_SceneManager implementation
    /// @{
public:
    virtual pSceneService_type create(const std::string& _type, const std::string& _sceneName, const int _sceneType);
    virtual void registerDefaultScriptEngine(pScriptEngine_type _pEngine);
    virtual pScriptModule_type getDefaultSceneScriptModule();
    /// @}

    /// @name Additional Implementation
    /// @{
private:
    /// Register the script module with all of the previously created scene services.
    void registerSceneScriptModule();
    /// @}

    /// @name 'Structors
    /// @{
public:
             SceneManager();
    virtual ~SceneManager();
    /// @}

    /// @name Member Variables
    /// @{
private:
    SceneServiceCache_type          m_sceneServiceCache;

    pScriptEngine_type              m_pDefaultScriptEngine;

    bool                            m_scriptTypesInitialized;

    Zen::Scripting::script_module*	m_pSceneModule;
    /// @}

};	// class SceneManager

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Rendering
}   // namespace Engine
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_ENGINE_RENDERING_SCENE_MANAGER_HPP_INCLUDED
