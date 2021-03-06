//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Engine Game Tutorial
//
// Copyright (C) 2001 - 2010 Tony Richards
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
// This project is part of the Zen Engine Tutorials
//
// For more details, click on the link below for the IndieZen.org documentation:
//
// http://www.indiezen.org/wiki/wiki/zoss/Engine/Tutorials
//
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#include "GameClient.hpp"
#include "AvatarGameObject.hpp"

#include "BehaviorGroup.hpp"

#include <Zen/Core/Math/Vector3.hpp>
#include <Zen/Core/Math/Quaternion4.hpp>

#include <Zen/Core/Scripting/I_ScriptEngine.hpp>
#include <Zen/Core/Scripting/I_ScriptModule.hpp>
#include <Zen/Core/Scripting/I_ScriptType.hpp>
#include <Zen/Core/Scripting/ObjectReference.hpp>

#include <Zen/Core/Event/I_ActionMap.hpp>

#include <Zen/Engine/Core/I_GameGroup.hpp>
#include <Zen/Engine/Core/I_GameObjectBehaviors.hpp>

#include <Zen/Engine/Physics/I_PhysicsActor.hpp>
#include <Zen/Engine/Physics/I_PhysicsMaterial.hpp>

#include <Zen/Engine/Rendering/I_RenderingCanvas.hpp>
#include <Zen/Engine/Rendering/I_SceneService.hpp>
#include <Zen/Engine/Rendering/I_SceneNode.hpp>
#include <Zen/Engine/Rendering/I_Light.hpp>
#include <Zen/Engine/Rendering/I_Camera.hpp>

#include <Zen/Engine/Resource/I_ResourceService.hpp>
#include <Zen/Engine/Rendering/I_RenderableResource.hpp>

#include <Zen/Engine/Input/I_InputService.hpp>
#include <Zen/Engine/Input/I_KeyMap.hpp>

#include <Zen/Engine/World/I_TerrainService.hpp>
#include <Zen/Engine/World/I_Terrain.hpp>
#include <Zen/Engine/World/I_Sky.hpp>

#include <boost/filesystem.hpp>
#include <boost/filesystem/operations.hpp>

#include <boost/bind.hpp>

#include <stddef.h>
#include <iostream>


//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Game {
namespace Client {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

GameClient::GameClient(WindowHandle_type _pParent)
:   m_baseClient(Zen::Engine::Base::I_BaseGameClient::getSingleton())
,   m_baseGame(Zen::Engine::Base::I_BaseGame::getSingleton())
,   m_pScriptObject(NULL)
,   m_moveZDelta(0)
,	m_moveXDelta(0)
,   m_pPlayer(NULL)
,   m_behaviorManager(*this)
{
    m_baseClient.setWindowHandle(_pParent);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
GameClient::~GameClient()
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
const GameClient::WindowHandle_type
GameClient::getHandle() const
{
    return m_baseClient.getWindowHandle();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Zen::Scripting::I_ObjectReference*
GameClient::getScriptObject()
{
    return m_pScriptObject;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::registerScriptEngine(pScriptEngine_type _pScriptEngine)
{
    // This isn't really used with the Base Starter kit since ZGameLoader 
    // registers the script engine with the BaseGameClient.

    // Just ignore this method.
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
bool
GameClient::init()
{
    // Initialize Rendering
    initRendering();

    // Initialize Physics
    initPhysics();

    // For some reason the sky service must be initialized after physics
    game().initSkyService("ZSky");

    // Terrain must be initialized after physics
    game().initTerrainService("ZTerrain");

    // Initialize the Input service
    // Note: "keyboard" actually initializes the ZInput Keyboard and Mouse
    // combined input service.
    m_baseClient.initInputService("keyboard");

    // Initialize resources
    initResources();

    // Possibly the rest of this should be done later and we should show
    // an initial game screen or splash screens here.

    createActions();
    createDefaultMapping();
    createBehaviors();

    // Normally, createScene() is done after other things like
    // displaying some splash screens, etc.  But for now lets
    // just do it here.
    createScene();

    m_baseClient.onBeforeFrameRenderedEvent.connect(boost::bind(&GameClient::beforeRender, this, _1));

    return true;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::initRendering()
{
    m_baseClient.initRenderingService("ogre");
    m_baseClient.initSceneService("ogre");
    m_baseClient.initRenderingResourceService("ogre");

    Zen::Engine::Rendering::I_RenderingCanvas& canvas = m_baseClient.getRenderingCanvas();

    // Select the default camera.  No need to create it since it always exists
    Zen::Engine::Rendering::I_Camera& camera = canvas.selectCamera("default");

    // TODO Need to implement something like this
   	//canvas.setBackgroundColour(Zen::Engine::Rendering::ColorValue(0, 0, 0.2f));

    camera.setNearClipDistance(0.01f);
    camera.setAspectRatio((Zen::Math::Real)canvas.getWidth() / (Zen::Math::Real)canvas.getHeight());
    camera.setHorizontalFOV(Zen::Math::Degree(60));
    camera.setPosition(0.0, 200.0, 100.0);

}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::initResources()
{
    boost::filesystem::path rootPath = boost::filesystem::system_complete(boost::filesystem::path("resources", boost::filesystem::native)).normalize();
    m_baseClient.getRenderingResourceService().addResourceLocation(rootPath.string(), "FileSystem", "General", true);
}


//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::initPhysics()
{
    m_baseGame.initPhysicsService("ZNewton");
    m_baseGame.initPhysicsResourceService("ZNewton");
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::run()
{
    m_baseClient.run();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Zen::Engine::Widgets::I_WidgetService&
GameClient::getWidgetService()
{
    return m_baseClient.getWidgetService();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Zen::Engine::Rendering::I_RenderingCanvas&
GameClient::getRenderingCanvas()
{
    return m_baseClient.getRenderingCanvas();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Zen::Engine::Resource::I_ResourceService&
GameClient::getRenderingResourceService()
{
    return m_baseClient.getRenderingResourceService();
}
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Zen::Engine::World::I_TerrainService&
GameClient::getTerrainService()
{
    return m_baseClient.getTerrainService();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Zen::Engine::World::I_SkyService&
GameClient::getSkyService()
{
    return m_baseClient.getSkyService();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
bool
GameClient::initRenderingService(const std::string& _type, const std::string& _title, int _xRes, int _yRes)
{
    return m_baseClient.initRenderingService(_type, _title, _xRes, _yRes);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
bool
GameClient::initRenderingResourceService(const std::string& _type)
{
    return m_baseClient.initRenderingResourceService(_type);
}
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
bool
GameClient::initTerrainService(const std::string& _type)
{
    return game().initTerrainService(_type);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
bool
GameClient::initSkyService(const std::string& _type)
{
    return game().initSkyService(_type);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
bool
GameClient::initInputService(const std::string& _type)
{
    return m_baseClient.initInputService(_type);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
bool
GameClient::initWidgetService(const std::string& _type)
{
    return m_baseClient.initWidgetService(_type);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::activateGameClientScriptModule()
{
    createScriptTypes();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::createScriptTypes()
{
    // TODO Register additional script types here

    // Tell m_base we're done.  After the modules are activated then you cannot
    // modify any script types.
    m_baseClient.activateScriptModules();

    // Create the script object for this game client
    m_pScriptObject = new ScriptObjectReference_type
        (base().getScriptModule(), base().getScriptModule()->getScriptType(getScriptTypeName()), getSelfReference().lock());
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::createScene()
{
    // Resize the Physics World
    Zen::Math::Vector3 minSize(-2000.0f, -4000.0f, -2000.0f);
    Zen::Math::Vector3 maxSize( 2000.0f,  2000.0f,  2000.0f);
    m_baseGame.getCurrentPhysicsZone()->setBoundary(minSize, maxSize);

    // Create the terrain

    game().getTerrainService()->setPhysicsZone(m_baseGame.getCurrentPhysicsZone());

    // load our terrain
    Zen::Math::Matrix4 matXfm(Zen::Math::Matrix4::INIT_IDENTITY);
    matXfm.setXYZRotation(Zen::Math::Degree(0), Zen::Math::Degree(0),Zen::Math::Degree(0));
    matXfm.setPosition(0.0f, 0.0f, 0.0f);

    // TODO Change according to Tutorial4
    //m_pTerrain = m_base.getTerrainService().createTerrain();
    throw Zen::Utility::runtime_exception("GameClient::createScene(): Error, not implemented");

    m_pTerrain->loadVisualization(std::string("terrain.cfg"), matXfm);
    // NOTE - you will need to use loadPhysicsFromRaw() one time (below) to create the collision
    //   binary, then you can use loadPhysicsFromSerialization() which loads MUCH faster.
    std::string terrainRawFile("resources/terrain.raw");
    if (!m_pTerrain->loadPhysicsFromSerialization(terrainRawFile + std::string(".collision"), matXfm))
    {
        m_pTerrain->loadPhysicsFromRaw(terrainRawFile, 513, 200.0f, 4.0f, matXfm, true);
    }

    // Create a sky box

    Zen::Engine::World::I_SkyService::config_type skyConfig;
    skyConfig["type"] = "skybox";
    skyConfig["resourceName"] = "SteveCube";
    m_pSky = game().getSkyService()->createSky(skyConfig);

    m_baseClient.getSceneService()->setAmbientLight(0.8f, 0.8f, 0.8f, 1.0f);
    Zen::Engine::Rendering::I_SceneService::pLight_type pLight = m_baseClient.getSceneService()->createLight("default", "Light");
    pLight->setPosition(5000.0f, 5000.0f, 5000.0f);

    // Create the player
    m_pPlayer = new AvatarGameObject(*this, m_baseGame.getRootGroup(), "player");

    // Set the player behaviors
    behaviorGroup("player").attach(*m_pPlayer);

    // Load the Ninja!
    m_pPlayer->loadRenderable("ninja.mesh");

    m_pPlayer->base().setScale(0.005f, 0.005f, 0.005f);
    m_pPlayer->base().setPosition(146.0f, 101.0f, 221.0f, true);


	//m_pPlayer->base().getPhysicsActor()->setAngularVelocity(Zen::Math::Vector3(0.0f,0.0f,0.0f));

    Zen::Engine::Rendering::I_RenderingCanvas& canvas = m_baseClient.getRenderingCanvas();

    // Create the chase camera
    canvas.createCamera("chase");

    // Select the chase camera
    Zen::Engine::Rendering::I_Camera& camera = canvas.selectCamera("chase");

    camera.setNearClipDistance(0.01f);
    camera.setFarClipDistance(99999*6);
    camera.setAspectRatio((Zen::Math::Real)canvas.getWidth() / (Zen::Math::Real)canvas.getHeight());
    camera.setHorizontalFOV(Zen::Math::Degree(60));

    //Zen::Math::Vector3 offset(0, 1.2f, 2.8f);
    Zen::Math::Vector3 offset(0.0f, 80.0f, 0.0f);
    Zen::Math::Quaternion4 rotation(Zen::Math::Quaternion4::identity());

    m_pPlayer->base().getSceneNode()->attachObject("camera", camera, offset, rotation);
    camera.setPosition(0.0f, 0.5f, 2.0f);

	m_pPlayer->base().setBehaviors(m_behaviorManager.getAvatarBehaviors());

    // Now switch back to the default camera
    //canvas.selectCamera("default");

    m_baseClient.onBeforeFrameRenderedEvent.connect(boost::bind(&GameClient::beforeRender, this, _1));
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::createActions()
{
    // Create some actions
    m_baseGame.getActionMap().createAction("Quit", boost::bind(&Zen::Engine::Base::I_BaseGameClient::quit, &m_baseClient, _1));

    m_baseGame.getActionMap().createAction("Move Left", boost::bind(&GameClient::moveLeft, this, _1));
    m_baseGame.getActionMap().createAction("Move Right", boost::bind(&GameClient::moveRight, this, _1));
    m_baseGame.getActionMap().createAction("Move Forward", boost::bind(&GameClient::moveForward, this, _1));
    m_baseGame.getActionMap().createAction("Move Backward", boost::bind(&GameClient::moveBackward, this, _1));

}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::createDefaultMapping()
{
    // Map some keys to actions
    m_baseClient.getKeyMap().mapKeyInput("q", m_baseGame.getActionMap()["Quit"]);

    // Using wasd for movement, using w to go forward
    //m_base.getKeyMap().mapKeyInput("w", m_base.getActionMap()["Move Forward"]);

}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::createBehaviors()
{
    m_behaviorManager.init();

    //behaviorGroup("player").add("gravity");
	//behaviorGroup("player").add("AvatarCollision");
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Zen::Engine::Base::I_BaseGameClient&
GameClient::base()
{
    return m_baseClient;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Zen::Engine::Base::I_BaseGame&
GameClient::game()
{
    return m_baseGame;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
BehaviorGroup&
GameClient::behaviorGroup(const std::string& _name)
{
    return m_behaviorManager.getGroup(_name);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::beforeRender(double _elapsedTime)
{

    // TODO: Do everything else that needs to be done before the screen is rendered

	Zen::Math::Vector3 oldvel, oldangvel;

    m_pPlayer->base().getPhysicsActor()->getOrientation(m_pPlayer->m_orientation);
    m_pPlayer->base().getPhysicsActor()->getLinearVelocity(oldvel);
	oldangvel = m_pPlayer->base().getPhysicsActor()->getAngularVelocity();

	//really should rip this entire chunk out and replace it with a controledMovementBehavior (don't look for it, it's just a name atm)
    //
    // Walking forward/backward
    //
    if (m_moveZDelta > 0)
    {
        // move the player backward (+Z local axis)
		//when walking, we put one leg in front of the other, but first, we step upwards hence, stepHeight
		Zen::Math::Vector3 deltaV(0.0f, _elapsedTime * m_pPlayer->m_stepHeight, _elapsedTime * m_pPlayer->m_moveSpeed);
        Zen::Math::Vector3 newvel = m_pPlayer->m_orientation.rotate(deltaV);
        newvel = newvel + oldvel;
        m_pPlayer->base().getPhysicsActor()->setLinearVelocity(newvel);
    }
    if (m_moveZDelta < 0)
    {
        // move the player forward (-Z local axis)
        Zen::Math::Vector3 deltaV(0.0f, _elapsedTime * m_pPlayer->m_stepHeight, _elapsedTime * -m_pPlayer->m_moveSpeed);
        Zen::Math::Vector3 newvel = m_pPlayer->m_orientation.rotate(deltaV);
        newvel = newvel+oldvel;
        m_pPlayer->base().getPhysicsActor()->setLinearVelocity(newvel);
    }

    //
    // turning left/right (since we already demonstrated linear movement - bjr)
    //
    if (m_moveXDelta > 0)
    {
        // move the player backward (+X local axis)
        Zen::Math::Vector3 deltaV(0.0f,  _elapsedTime * -m_pPlayer->m_turnSpeed, 0.0f);
        Zen::Math::Vector3 newangvel = m_pPlayer->m_orientation.rotate(deltaV);
        newangvel = newangvel + oldangvel;
        m_pPlayer->base().getPhysicsActor()->setAngularVelocity(newangvel);
    }
    if (m_moveXDelta < 0)
    {
        // move the player forward (-X local axis)
        Zen::Math::Vector3 deltaV(0.0f, _elapsedTime * m_pPlayer->m_turnSpeed, 0.0f);
        Zen::Math::Vector3 newangvel = m_pPlayer->m_orientation.rotate(deltaV);
        newangvel = newangvel + oldangvel;
        m_pPlayer->base().getPhysicsActor()->setAngularVelocity(newangvel);
    }

	// This updates all physics worlds we've created:
	m_baseGame.getPhysicsService()->stepSimulation(_elapsedTime);

	//m_pPlayer->base().getPhysicsActor()->setOrientation(m_pPlayer->m_orientation);

    m_baseClient.getRenderingCanvas().selectCamera("chase").update();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::moveLeft(boost::any& _parameter)
{
    Zen::Engine::Input::I_InputService::pKeyEventPayload_type pEvent =
        boost::any_cast<Zen::Engine::Input::I_InputService::pKeyEventPayload_type>(_parameter);

    if( pEvent->getPressedState() )
    {
        m_moveXDelta = -1;
    }
    else
    {
        m_moveXDelta = 0;
    }
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::moveRight(boost::any& _parameter)
{
    Zen::Engine::Input::I_InputService::pKeyEventPayload_type pEvent =
        boost::any_cast<Zen::Engine::Input::I_InputService::pKeyEventPayload_type>(_parameter);

    if( pEvent->getPressedState() )
    {
        m_moveXDelta = 1;
    }
    else
    {
        m_moveXDelta = 0;
    }
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::moveForward(boost::any& _parameter)
{
    Zen::Engine::Input::I_InputService::pKeyEventPayload_type pEvent = boost::any_cast<Zen::Engine::Input::I_InputService::pKeyEventPayload_type>(_parameter);

    if (pEvent->getPressedState())
    {
        m_moveZDelta = -1;
    }
    else
    {
        m_moveZDelta = 0;
    }
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::moveBackward(boost::any& _parameter)
{
    Zen::Engine::Input::I_InputService::pKeyEventPayload_type pEvent =
        boost::any_cast<Zen::Engine::Input::I_InputService::pKeyEventPayload_type>(_parameter);

    if( pEvent->getPressedState() )
    {
        m_moveZDelta = 1;
    }
    else
    {
        m_moveZDelta = 0;
    }
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Client
}   // namespace Game
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
