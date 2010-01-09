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
#ifndef ZEN_STUDIO_WORKBENCH_I_PROPERTIES_DATA_MAP_HPP_INCLUDED
#define ZEN_STUDIO_WORKBENCH_I_PROPERTIES_DATA_MAP_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Memory/managed_ptr.hpp>

#include <Zen/Enterprise/Database/I_DatabaseConnection.hpp>
#include <Zen/Enterprise/Database/I_DatabaseService.hpp>
#include <Zen/Enterprise/Database/I_DatabaseTransaction.hpp>

#include <boost/cstdint.hpp>

#include <boost/noncopyable.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Studio {
namespace Workbench {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class I_PropertiesDomainObject;
class I_PropertiesDataCollection;

class WORKBENCHMODEL_DLL_LINK I_PropertiesDataMap
:	public boost::noncopyable
{

    /// @name Types
    /// @{
public:
//    typedef Zen::Memory::managed_ptr<I_PropertiesDomainObject>   pPropertiesDomainObject_type;
//    typedef Zen::Memory::managed_ptr<I_PropertiesDataCollection>     pPropertiesDataCollection_type;
    typedef Zen::Memory::managed_ptr<I_PropertiesDataMap>        pPropertiesDataMap_type;

    typedef Zen::Database::I_DatabaseService::pDatabaseConnection_type      pDatabaseConnection_type;

    typedef Zen::Memory::managed_ptr<I_PropertiesDataCollection>  pPropertiesDataCollection_type;
    typedef Zen::Event::future_return_value<pPropertiesDataCollection_type>  FuturePropertiesDataCollection_type;
	typedef Zen::Memory::managed_ptr<FuturePropertiesDataCollection_type>    pFuturePropertiesDataCollection_type;
    
    typedef Zen::Memory::managed_ptr<I_PropertiesDomainObject>  pPropertiesDomainObject_type;
    typedef Zen::Event::future_return_value<pPropertiesDomainObject_type>  FuturePropertiesDomainObject_type;
	typedef Zen::Memory::managed_ptr<FuturePropertiesDomainObject_type>    pFuturePropertiesDomainObject_type;
    /// @}

    /// @name I_PropertiesDataMap interface
    /// @{
public:
    /// Create a new PropertiesDomainObject.
    virtual pPropertiesDomainObject_type createNew() = 0;
    
    /// Get an object by primary key.
    virtual pFuturePropertiesDomainObject_type getByKey(boost::uint64_t _primaryKeyValue) = 0;

    /// Delete an object by primary key.
    virtual void deleteByKey(boost::uint64_t _primaryKeyValue) = 0;

    /// Get all of the records.
    virtual pFuturePropertiesDataCollection_type getAll() = 0;

    /// Update a PropertiesDomainObject.
    /// If the PropertiesDomainObject hasn't been inserted yet, it will be inserted.
    virtual Zen::Database::I_DatabaseTransaction::pFutureKey_type update(pPropertiesDomainObject_type _pPropertiesDomainObject) = 0;
    /// @}

    /// @name Static class factory
    /// @{
public:
    static pPropertiesDataMap_type create(pDatabaseConnection_type _pDatabaseConnection);
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_PropertiesDataMap();
    virtual ~I_PropertiesDataMap();
    /// @}

};  // interface I_PropertiesDataMap

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Studio
}   // namespace Workbench
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

namespace Zen {
namespace Memory {
    /// I_PropertiesDataMap is a managed by factory
    template<>
    struct is_managed_by_factory<Zen::Studio::Workbench::I_PropertiesDataMap> : public boost::true_type{};
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Memory
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_STUDIO_WORKBENCH_I_PROPERTIES_DATA_MAP_HPP_INCLUDED
