//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Spaces
//
// Copyright (C) 2001 - 2009 Tony Richards
//
// Licensed under the Games by Sarge Publishing License - See your licensing
// agreement for terms and conditions.
//
// Do not redistribute this source code.
//
// Tony Richards trichards@gamesbysarge.com
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// This is generated by the Zen Spaces Code Generator.  Do not modify!
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef WORLDBUILDER_I_ZONEFOLDER_DATA_MAP_HPP_INCLUDED
#define WORLDBUILDER_I_ZONEFOLDER_DATA_MAP_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Memory/managed_ptr.hpp>

#include <Zen/Enterprise/Database/I_DatabaseConnection.hpp>
#include <Zen/Enterprise/Database/I_DatabaseService.hpp>
#include <Zen/Enterprise/Database/I_DatabaseTransaction.hpp>

#include <boost/cstdint.hpp>

#include <boost/noncopyable.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace WorldBuilder {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class I_ZoneFolderDomainObject;
class I_ZoneFolderDataCollection;

class WORLDBUILDERMODEL_DLL_LINK I_ZoneFolderDataMap
:	public boost::noncopyable
{

    /// @name Types
    /// @{
public:
//    typedef Zen::Memory::managed_ptr<I_ZoneFolderDomainObject>   pZoneFolderDomainObject_type;
//    typedef Zen::Memory::managed_ptr<I_ZoneFolderDataCollection>     pZoneFolderDataCollection_type;
    typedef Zen::Memory::managed_ptr<I_ZoneFolderDataMap>        pZoneFolderDataMap_type;

    typedef Zen::Database::I_DatabaseService::pDatabaseConnection_type      pDatabaseConnection_type;

    typedef Zen::Memory::managed_ptr<I_ZoneFolderDataCollection>  pZoneFolderDataCollection_type;
    typedef Zen::Event::future_return_value<pZoneFolderDataCollection_type>  FutureZoneFolderDataCollection_type;
	typedef Zen::Memory::managed_ptr<FutureZoneFolderDataCollection_type>    pFutureZoneFolderDataCollection_type;
    
    typedef Zen::Memory::managed_ptr<I_ZoneFolderDomainObject>  pZoneFolderDomainObject_type;
    typedef Zen::Event::future_return_value<pZoneFolderDomainObject_type>  FutureZoneFolderDomainObject_type;
	typedef Zen::Memory::managed_ptr<FutureZoneFolderDomainObject_type>    pFutureZoneFolderDomainObject_type;
    /// @}

    /// @name I_ZoneFolderDataMap interface
    /// @{
public:
    /// Create a new ZoneFolderDomainObject.
    virtual pZoneFolderDomainObject_type createNew() = 0;
    
    /// Get an object by primary key.
    virtual pFutureZoneFolderDomainObject_type getByKey(boost::uint64_t _primaryKeyValue) = 0;

    /// Delete an object by primary key.
    virtual void deleteByKey(boost::uint64_t _primaryKeyValue) = 0;

    /// Get a collection of Zone Folders by explorerNodeId.    
    virtual pFutureZoneFolderDataCollection_type getByExplorerNodeId(const boost::uint64_t _explorerNodeId) = 0;

    /// Get all of the records.
    virtual pFutureZoneFolderDataCollection_type getAll() = 0;

    /// Update a ZoneFolderDomainObject.
    /// If the ZoneFolderDomainObject hasn't been inserted yet, it will be inserted.
    virtual Zen::Database::I_DatabaseTransaction::pFutureKey_type update(pZoneFolderDomainObject_type _pZoneFolderDomainObject) = 0;
    /// @}

    /// @name Static class factory
    /// @{
public:
    static pZoneFolderDataMap_type create(pDatabaseConnection_type _pDatabaseConnection);
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_ZoneFolderDataMap();
    virtual ~I_ZoneFolderDataMap();
    /// @}

};  // interface I_ZoneFolderDataMap

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace WorldBuilder
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

namespace Zen {
namespace Memory {
    /// I_ZoneFolderDataMap is a managed by factory
    template<>
    struct is_managed_by_factory<WorldBuilder::I_ZoneFolderDataMap> : public boost::true_type{};
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Memory
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // WORLDBUILDER_I_ZONEFOLDER_DATA_MAP_HPP_INCLUDED