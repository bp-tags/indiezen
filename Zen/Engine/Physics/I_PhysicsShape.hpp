//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Game Engine Framework
//
// Copyright (C) 2001 - 2009 Tony Richards
// Copyright (C) 2008 - 2009 Walt Collins
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
//  Walt Collins (Arcanor) - wcollins@indiezen.com
//  Matthew Alan Gray mgray@indiezen.org
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_ENGINE_PHYSICS_I_PHYSICS_SHAPE_HPP_INCLUDED
#define ZEN_ENGINE_PHYSICS_I_PHYSICS_SHAPE_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Math/Math.hpp>
#include <Zen/Core/Math/Vector3.hpp>
#include <Zen/Core/Math/Quaternion4.hpp>
#include <Zen/Core/Math/Matrix4.hpp>
#include <Zen/Core/Memory/managed_ptr.hpp>
#include <Zen/Core/Memory/managed_weak_ptr.hpp>
#include <Zen/Core/Event/Event.hpp>

#include <Zen/Core/Scripting/I_ScriptableType.hpp>
#include <Zen/Core/Scripting/ObjectReference.hpp>

#include <Zen/Engine/Core/I_GameObject.hpp>

#include <string>
#include <map>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
    namespace Math {
        class Matrix4;
        class Vector3;
        class Point3;
    }   // namespace Math
namespace Engine {
namespace Physics {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class I_PhysicsZone;
class I_PhysicsMaterial;

class PHYSICS_DLL_LINK I_CollisionShape
:   public virtual Zen::Scripting::I_ScriptableType
{
    /// @name Types
    /// @{
public:
    typedef I_CollisionShape*                                pScriptObject_type;
    typedef Scripting::ObjectReference<I_CollisionShape>     ScriptObjectReference_type;

    class I_TransformEventData;
    class I_ApplyForcesEventData;
	class I_BeginCollisionEventData;
    class I_DuringCollisionEventData;
    class I_EndCollisionEventData;

    typedef std::map<std::string, std::string>             config_type;
    typedef Memory::managed_weak_ptr<I_PhysicsZone>       wpPhysicsZone_type;
    typedef Memory::managed_ptr<I_CollisionShape>            pCollisionShape_type;
    typedef Memory::managed_ptr<I_PhysicsMaterial>         pPhysicsMaterial_type;
    typedef Memory::managed_weak_ptr<I_PhysicsMaterial>    wpPhysicsMaterial_type;
    typedef Memory::managed_weak_ptr<I_CollisionShape>       wpCollisionShape_type;
    typedef Event::Event<wpCollisionShape_type>              CollisionShapeEvent_type;
    typedef Event::Event<I_TransformEventData&>            TransformEvent_type;
    typedef Event::Event<I_ApplyForcesEventData&>          ApplyForcesEvent_type;
	typedef Event::Event<I_BeginCollisionEventData&>       BeginCollisionEvent_type;
	typedef Event::Event<I_DuringCollisionEventData&>      DuringCollisionEvent_type;
	typedef Event::Event<I_EndCollisionEventData&>         EndCollisionEvent_type;
	typedef Memory::managed_ptr<Zen::Engine::Core::I_GameObject> pOwningObject_type;
    /// @}

    /// @name I_CollisionShape interface
    /// @{
public:
    virtual void setMaterial(pPhysicsMaterial_type _material) = 0;
    virtual pPhysicsMaterial_type getMaterial() = 0;
    virtual void* getBodyPtr() = 0;
    virtual wpPhysicsZone_type getPhysicsZone() = 0;
    virtual const std::string& getName() = 0;
    virtual void setName(const std::string& _name) = 0;

    virtual float getMass() = 0;
    virtual void setMass(Zen::Math::Real _mass) = 0;
    virtual void setScale(Zen::Math::Real _x, Zen::Math::Real _y, Zen::Math::Real _z) = 0;
    virtual void setPosition(const Math::Point3& _position) = 0;
    virtual void getPosition(Math::Point3& _position) = 0;

    /// Get the orientation (XYZ rotation) as a quaternion
    virtual void getOrientation(Math::Quaternion4& _orient) = 0;

    /// Set the orientation (XYZ rotation) as a quaternion
    virtual void setOrientation(const Math::Quaternion4& _orient) = 0;

    /// Get the orientation (XYZ rotation) as a 4x4 matrix
    virtual void getOrientation(Math::Matrix4& _orient) = 0;

    /// Set the orientation (XYZ rotation) as a 4x4 matrix
    virtual void setOrientation(const Math::Matrix4& _orient) = 0;

    virtual void setVelocity(const Math::Vector3& _velocity) = 0;
    virtual void getVelocity(Math::Vector3& _velocity) = 0;
    virtual void getTorque(Math::Vector3& _torque) = 0;
    virtual Math::Vector3 getAngularMomentum() = 0;
    virtual void setAngularMomentum(const Math::Vector3& _omega) = 0;
    virtual Math::Vector3 getAngularDamping() = 0;
    virtual void setAngularDamping(const Math::Vector3& _damping) = 0;
    virtual Math::Real getLinearDamping() = 0;
    virtual void setLinearDamping(Zen::Math::Real _damping) = 0;
    virtual void setAutoFreeze(bool _bFreeze) = 0;

    //TODO: remove this entire list, and implement via physicsResource primitives
    virtual bool initNullShape(void) = 0;
    virtual bool initBoxShape(Zen::Math::Real _dx = 1.0f, Zen::Math::Real _dy = 1.0f, Zen::Math::Real _dz = 1.0f) = 0;
    virtual bool initOvoidShape(Zen::Math::Real _radiusX = 1.0f, Zen::Math::Real _radiusY = 1.0f, Zen::Math::Real _radiusZ = 1.0f) = 0;
    virtual bool initCapsuleShape(Zen::Math::Real _radius = 1.0f, Zen::Math::Real _height = 1.0f) = 0;

    virtual bool initHeightFieldShapeFromRaw(std::string _filename, size_t _size, float _maxHeight, float _scaleXY, const Math::Matrix4& _transform, bool _bSerialize) = 0;
    virtual bool initHeightFieldShapeFromSerialization(std::string _filename, const Math::Matrix4& _transform) = 0;
    virtual bool initConvexHullShape(std::string _filename) = 0;
    virtual bool initTreeCollisionShape(std::string _filename) = 0;
    // end list

    virtual void setAdvancedCollisionPrediction(bool _mode) = 0;
    virtual bool getAdvancedCollisionPrediction(void) = 0;
	virtual void setCollisionGroup(int _collisionGroup) = 0;
	virtual int getCollisionGroup() = 0;
    
	///provides a shortcut to the owning object for utilization with behaviors (ie: the player that has this body, not just the body)
	virtual void setOwner(pOwningObject_type _pOwner) = 0;
	virtual pOwningObject_type getOwner() = 0;

    /// @}

    /// @name I_ScriptableType implementation
    /// @{
public:
    /// This is implemented to return "CollisionShape"
    /// Override this method if you create a derived type
    virtual const std::string& getScriptTypeName();
    /// @}

    /// @name Events
    /// @{
public:
    /// This event is fired immediately before this object
    /// is destroyed.
    CollisionShapeEvent_type onDestroyEvent;

    /// This event is fired when the physics shape
    /// transformation changes.
    TransformEvent_type onTransformEvent;

    /// This event is fired before forces are applied to the physics
    /// shape for every frame that it is active.
    ApplyForcesEvent_type onApplyForcesEvent;

	/// This event is fired once the Axis Aligned Bounding Box (AABB) of the shape intersects that of another
	BeginCollisionEvent_type onBoundBoxCollisionEvent;

	/// This event is fired while the physics engine determines two objects are colliding
	DuringCollisionEvent_type onCollisionEvent;
	
	/// This event is fired after the physics engine determines two objects are colliding and acts on it
	EndCollisionEvent_type onCollisionResolutionEvent;

    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_CollisionShape();
    virtual ~I_CollisionShape();
    /// @}

    /// @name Inner Types
    /// @{
public:
    class PHYSICS_DLL_LINK I_TransformEventData
    {
    public:
        /// Get the Physics Shape related to this event.
        virtual I_CollisionShape& getShape() = 0;

        /// Get the matrix of the future transform.
        virtual const Math::Matrix4& getTransform() const = 0;

    protected:
                 I_TransformEventData();
        virtual ~I_TransformEventData();
    };  // interface I_TransformEventData

    class PHYSICS_DLL_LINK I_ApplyForcesEventData
    {
    public:
        /// Get the physics shape associated with this event
        virtual I_CollisionShape& getShape() = 0;

        /// Apply a force to this shape
        virtual void applyForce(const Math::Vector3& _force) = 0;

        /// Apply torque to this shape
        virtual void applyTorque(const Math::Vector3& _torque) = 0;
    protected:
                 I_ApplyForcesEventData();
        virtual ~I_ApplyForcesEventData();
    };  // interface I_ApplyForcesEventData


    class PHYSICS_DLL_LINK I_CollisionEventData
    {
    public:
        /// Get the Physics Shape related to this event.
        virtual I_CollisionShape& getShape() = 0;

        /// Get the Other Physics Shape related to this event.
        virtual I_CollisionShape& getOtherShape() = 0;

    protected:
                 I_CollisionEventData();
        virtual ~I_CollisionEventData();
    };  // interface I_CollisionEventData

    class PHYSICS_DLL_LINK I_BeginCollisionEventData
    :   public virtual I_CollisionEventData
    {
    public:
        /// Call this method in order to ignore this collision
        virtual void ignoreCollision() = 0;

    protected:
                 I_BeginCollisionEventData();
        virtual ~I_BeginCollisionEventData();
    };  // interface I_BeginCollisionEventData

    class PHYSICS_DLL_LINK I_DuringCollisionEventData
    :   public virtual I_CollisionEventData
    {
    public:
        /// Disable the effects of this contact.
        /// This will force the phyiscs engine to ignore this contact and not 
        /// process any reactions that this contact might cause.
        virtual void disableContact() const = 0;

        /// Get the speed of this contact along the normal vector of the contact.
        virtual Math::Real getContactSpeed() const = 0;

        /// Get the force of this contact.
        /// This is only valid if the colliding shapes are at rest (i.e. their
        /// speed relative to each other is zero.)  You can use this to determine
        /// how "hard" one object is pressing against another.
        virtual void getContactForce(Math::Vector3& _forceVector) const = 0;

        /// Get the position of this contact in world coordinates.
        virtual void getContactPosition(Math::Point3& _contactPosition) const = 0;

        /// Get the normal of this contact.
        virtual void getContactNormal(Math::Vector3& _contactNormal) const = 0;

        /// Get the contact position and normal in a single call.
        /// This is more efficient to call once than calling getContactPosition() and getContactNormal() separately.
        virtual void getContactPositionAndNormal(Math::Point3& _contactPosition, Math::Vector3& _contactNormal) const = 0;

        /// Get the contact tangent vector to the contact point.
        virtual void getContactTangentDirections(Math::Vector3& _direction0, Math::Vector3& _direction1) const = 0;

        /// Get the contact speed of either the primary or secondary contact
        /// tangent.
        virtual Math::Real getContactTangentSpeed(bool _primary = true) const = 0;

        /// Set the default elasticity (coefficient of restitution) value for this contact. 
        virtual void setContactRestitution(Math::Real _restitution) = 0;

        /// Set the contact friction for either the primary or secondary contact
        /// tangent.
        /// @param _state A value of 0 makes the contact frictionless along the
        ///         specified contact tangent.
        virtual void setContactFrictionState(int _state, bool _primary = true) = 0;

        /// Set the static coefficient of friction for this contact. 
        /// @param _coefficent Must be positive
        virtual void setStaticFrictionCoefficient(Math::Real _coefficent, bool _primary = true) = 0; 

        /// Set the kinetic coefficient of friction for this contact. 
        /// @param _coefficent Normally a positive number from 0.0 to 1.0 although values as
        ///     high as 2.0 (for synthetic materials) are allowed.
        virtual void setKineticFrictionCoefficient(Math::Real _coefficent, bool _primary = true) = 0; 

        /// Force the contact point to have a non-zero accelleration along the
        /// surface plane.
        virtual void setContactTangentAcceleration(Math::Real _acceleration, bool _primary = true) = 0; 

        /// Override the contact tangent vector
        virtual void setContactTangentVector(Math::Vector3 _tangent) = 0;

    protected:
                 I_DuringCollisionEventData();
        virtual ~I_DuringCollisionEventData();
    };  // interface I_DuringCollisionEventData

    class PHYSICS_DLL_LINK I_EndCollisionEventData
    :   public virtual I_CollisionEventData
    {
    public:

    protected:
                 I_EndCollisionEventData();
        virtual ~I_EndCollisionEventData();
    };  // interface I_EndCollisionEventData

    /// @}
	public:
		bool m_IsStatic;
		Math::Real m_mass;
};  // interface I_CollisionShape

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Physics
}   // namespace Engine
namespace Memory 
{
    /// I_CollisionShape is managed by a I_PhysicsZone
    template<>
    struct is_managed_by_factory<Zen::Engine::Physics::I_CollisionShape> : public boost::true_type{};
}   // namespace Memory
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_ENGINE_PHYSICS_I_PHYSICS_SHAPE_HPP_INCLUDED
