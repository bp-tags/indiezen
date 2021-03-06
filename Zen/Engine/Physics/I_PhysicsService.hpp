//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Game Engine Framework
//
// Copyright (C) 2001 - 2010 Tony Richards
// Copyright (C) 2008 - 2009 Matthew Alan Gray
// Copyright (C) 2008 - 2009 Walt Collins
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
//  Walt Collins (Arcanor) - wcollins@indiezen.com
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_ENGINE_PHYSICS_I_PHYSICS_SERVICE_HPP_INCLUDED
#define ZEN_ENGINE_PHYSICS_I_PHYSICS_SERVICE_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Engine/Physics/I_PhysicsFrameListener.hpp>

#include <Zen/Core/Memory/managed_ptr.hpp>
#include <Zen/Core/Memory/managed_weak_ptr.hpp>
#include <Zen/Core/Memory/managed_self_ref.hpp>

#include <Zen/Core/Event/Event.hpp>

#include <Zen/Core/Math/Math.hpp>
#include <Zen/Core/Math/Vector3.hpp>

#include <Zen/Core/Scripting.hpp>

#include <boost/noncopyable.hpp>
#include <string>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Engine {
namespace Physics {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class I_PhysicsZone;

class PHYSICS_DLL_LINK I_PhysicsService
:   public virtual Zen::Scripting::I_ScriptableType
,   public Zen::Memory::managed_self_ref<I_PhysicsService>
,   public I_PhysicsFrameListener
,   boost::noncopyable
{
    /// @name Types
    /// @{
public:
typedef std::string                                             index_type;

    typedef Zen::Memory::managed_ptr<I_PhysicsService>          pScriptObject_type;
    typedef Zen::Scripting::ObjectReference<I_PhysicsService>   ScriptObjectReference_type;

    typedef Memory::managed_ptr<I_PhysicsService>               pPhysicsService_type;
    typedef Memory::managed_weak_ptr<I_PhysicsService>          wpPhysicsService_type;

    typedef Event::Event<wpPhysicsService_type>                 serviceEvent_type;
    typedef Zen::Math::Real                                     frameDelta_type;
    typedef Event::Event<frameDelta_type>                       frameEvent_type;
    typedef Memory::managed_ptr<I_PhysicsZone>                  pPhysicsZone_type;
    typedef Memory::managed_weak_ptr<I_PhysicsZone>             wpPhysicsZone_type;
    /// @}

    /// @name I_ScriptableType implementation
    /// @{
public:
    virtual const std::string& getScriptTypeName();
    /// @}

    /// @name I_PhysicsService interface
    /// @{
public:
    /// Create a physics zone.
    /// A physics zone contains all of the physics actors that make up a
    /// standalone physics simulation.  Actors within on zone do not
    /// interact with actors within another zone.
    /// @note Some physics plugins do not support muliple zones.  If
    ///     this is the case, the plugin should throw an exception
    ///     if an application attempts to create more than one zone.
    virtual pPhysicsZone_type createZone() = 0;

    /// @todo Should this be moved to I_ScriptableType?
    virtual void registerScriptModule(Zen::Scripting::script_module& _module) = 0;
    /// @}

    /// @name Static methods
    /// @{
public:
    static const std::string& getNamespace();
    static const std::string& getExtensionPointName();
    /// @}

    /// @name Events
    /// @{
public:
    /// Fired immediately before this object is destroyed.
    /// The payload is about to be destroyed, so do not keep a reference to it.
    serviceEvent_type onDestroyEvent;

    /// This event is fired after every frame is rendered
    /// The payload is the number of elapsed seconds since
    /// the previous frame event.
    frameEvent_type     onFrameEvent;
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_PhysicsService();
    virtual ~I_PhysicsService();
    /// @}

};  // interface I_PhysicsService

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Physics
}   // namespace Engine
namespace Memory
{
    /// I_PhysicsService is managed by a I_PhysicsServiceFactory
    template<>
    struct is_managed_by_factory<Zen::Engine::Physics::I_PhysicsService> : public boost::true_type{};
}   // namespace Memory
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_ENGINE_PHYSICS_I_PHYSICS_SERVICE_HPP_INCLUDED
