//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// IndieZen Game Engine Framework
//
// Copyright (C) 2001 - 2010 Tony Richards
// Copyright (C) 2008 - 2010 Matthew Alan Gray
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
//	Matthew Alan Gray mgray@indiezen.org
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#include "TerrainServiceFactory.hpp"
#include "TerrainService.hpp"

#include <OgreTerrain.h>

#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/lexical_cast.hpp>

#include <stddef.h>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace ZOgreTerrain {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
TerrainServiceFactory::TerrainServiceFactory()
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
TerrainServiceFactory::~TerrainServiceFactory()
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
static TerrainServiceFactory sm_terrainServiceFactory;

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
TerrainServiceFactory&
TerrainServiceFactory::getSingleton()
{
    return sm_terrainServiceFactory;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
TerrainServiceFactory::pTerrainService_type
TerrainServiceFactory::create(const std::string& _type, Engine::World::I_TerrainServiceFactory::config_type& _config)
{
    Ogre::TerrainGlobalOptions* pOptions = new Ogre::TerrainGlobalOptions();

    /// TODO Set the terrain global options based on _config contents.
    //pOptions->setSkirtSize(boost::lexical_cast<Ogre::Real,std::string>(_config["skirtSize"]));
    //pOptions->setDefaultResourceGroup(_config["resourceGroup"]);
    //pOptions->setMaxPixelError(boost::lexical_cast<Ogre::Real,std::string>(_config["pixelError"]));
    //pOptions->setCompositeMapDistance(boost::lexical_cast<Ogre::Real,std::string>(_config["compositeMapDistance"]));
    pOptions->setLightMapDirection(Ogre::Vector3(0,-1,0));
    pOptions->setCompositeMapAmbient(Ogre::ColourValue());
    pOptions->setCompositeMapDiffuse(Ogre::ColourValue());

    TerrainService* pRawService = new TerrainService(pOptions);

    return TerrainServiceFactory::pTerrainService_type(
        pRawService, 
        boost::bind(&TerrainServiceFactory::destroy, this, _1)
    );
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
TerrainServiceFactory::destroy(wpTerrainService_type _pService)
{
    /// Fire the service's onDestroyEvent.
    _pService->onDestroyEvent(_pService);

    /// Delete the service
    TerrainService* pService = dynamic_cast<TerrainService*>(_pService.get());

    if (pService != NULL)
    {
        delete pService;
    }
    else
    {
        // TODO Error!
    }
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace ZOgreTerrain
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
