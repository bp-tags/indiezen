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
#ifndef ZEN_STUDIO_WORKBENCH_I_SPREADSHEETCOLUMN_DATA_MAP_HPP_INCLUDED
#define ZEN_STUDIO_WORKBENCH_I_SPREADSHEETCOLUMN_DATA_MAP_HPP_INCLUDED

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

class I_SpreadSheetColumnDomainObject;
class I_SpreadSheetColumnDataCollection;

class WORKBENCHMODEL_DLL_LINK I_SpreadSheetColumnDataMap
:	public boost::noncopyable
{

    /// @name Types
    /// @{
public:
//    typedef Zen::Memory::managed_ptr<I_SpreadSheetColumnDomainObject>   pSpreadSheetColumnDomainObject_type;
//    typedef Zen::Memory::managed_ptr<I_SpreadSheetColumnDataCollection>     pSpreadSheetColumnDataCollection_type;
    typedef Zen::Memory::managed_ptr<I_SpreadSheetColumnDataMap>        pSpreadSheetColumnDataMap_type;

    typedef Zen::Database::I_DatabaseService::pDatabaseConnection_type      pDatabaseConnection_type;

    typedef Zen::Memory::managed_ptr<I_SpreadSheetColumnDataCollection>  pSpreadSheetColumnDataCollection_type;
    typedef Zen::Event::future_return_value<pSpreadSheetColumnDataCollection_type>  FutureSpreadSheetColumnDataCollection_type;
	typedef Zen::Memory::managed_ptr<FutureSpreadSheetColumnDataCollection_type>    pFutureSpreadSheetColumnDataCollection_type;
    
    typedef Zen::Memory::managed_ptr<I_SpreadSheetColumnDomainObject>  pSpreadSheetColumnDomainObject_type;
    typedef Zen::Event::future_return_value<pSpreadSheetColumnDomainObject_type>  FutureSpreadSheetColumnDomainObject_type;
	typedef Zen::Memory::managed_ptr<FutureSpreadSheetColumnDomainObject_type>    pFutureSpreadSheetColumnDomainObject_type;
    /// @}

    /// @name I_SpreadSheetColumnDataMap interface
    /// @{
public:
    /// Create a new SpreadSheetColumnDomainObject.
    virtual pSpreadSheetColumnDomainObject_type createNew() = 0;
    
    /// Get an object by primary key.
    virtual pFutureSpreadSheetColumnDomainObject_type getByKey(boost::uint64_t _primaryKeyValue) = 0;

    /// Delete an object by primary key.
    virtual void deleteByKey(boost::uint64_t _primaryKeyValue) = 0;

    /// Get SpreadSheet columns by spreadSheetDocumentId.    
    virtual pFutureSpreadSheetColumnDataCollection_type getByDocumentId(const boost::uint64_t _spreadSheetDocumentId) = 0;

    /// Get all of the records.
    virtual pFutureSpreadSheetColumnDataCollection_type getAll() = 0;

    /// Update a SpreadSheetColumnDomainObject.
    /// If the SpreadSheetColumnDomainObject hasn't been inserted yet, it will be inserted.
    virtual Zen::Database::I_DatabaseTransaction::pFutureKey_type update(pSpreadSheetColumnDomainObject_type _pSpreadSheetColumnDomainObject) = 0;
    /// @}

    /// @name Static class factory
    /// @{
public:
    static pSpreadSheetColumnDataMap_type create(pDatabaseConnection_type _pDatabaseConnection);
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_SpreadSheetColumnDataMap();
    virtual ~I_SpreadSheetColumnDataMap();
    /// @}

};  // interface I_SpreadSheetColumnDataMap

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Studio
}   // namespace Workbench
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

namespace Zen {
namespace Memory {
    /// I_SpreadSheetColumnDataMap is a managed by factory
    template<>
    struct is_managed_by_factory<Zen::Studio::Workbench::I_SpreadSheetColumnDataMap> : public boost::true_type{};
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Memory
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_STUDIO_WORKBENCH_I_SPREADSHEETCOLUMN_DATA_MAP_HPP_INCLUDED
