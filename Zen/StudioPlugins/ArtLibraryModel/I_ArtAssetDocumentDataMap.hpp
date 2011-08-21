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
#ifndef ARTLIBRARY_I_ARTASSETDOCUMENT_DATA_MAP_HPP_INCLUDED
#define ARTLIBRARY_I_ARTASSETDOCUMENT_DATA_MAP_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Memory/managed_ptr.hpp>

#include <Zen/Enterprise/Database/I_DatabaseConnection.hpp>
#include <Zen/Enterprise/Database/I_DatabaseService.hpp>
#include <Zen/Enterprise/Database/I_DatabaseTransaction.hpp>

#include <boost/cstdint.hpp>

#include <boost/noncopyable.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace ArtLibrary {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class I_ArtAssetDocumentDomainObject;
class I_ArtAssetDocumentDataCollection;

class ARTLIBRARYMODEL_DLL_LINK I_ArtAssetDocumentDataMap
:	public boost::noncopyable
{

    /// @name Types
    /// @{
public:
//    typedef Zen::Memory::managed_ptr<I_ArtAssetDocumentDomainObject>   pArtAssetDocumentDomainObject_type;
//    typedef Zen::Memory::managed_ptr<I_ArtAssetDocumentDataCollection>     pArtAssetDocumentDataCollection_type;
    typedef Zen::Memory::managed_ptr<I_ArtAssetDocumentDataMap>        pArtAssetDocumentDataMap_type;

    typedef Zen::Database::I_DatabaseService::pDatabaseConnection_type      pDatabaseConnection_type;

    typedef Zen::Memory::managed_ptr<I_ArtAssetDocumentDataCollection>  pArtAssetDocumentDataCollection_type;
    typedef Zen::Event::future_return_value<pArtAssetDocumentDataCollection_type>  FutureArtAssetDocumentDataCollection_type;
	typedef Zen::Memory::managed_ptr<FutureArtAssetDocumentDataCollection_type>    pFutureArtAssetDocumentDataCollection_type;
    
    typedef Zen::Memory::managed_ptr<I_ArtAssetDocumentDomainObject>  pArtAssetDocumentDomainObject_type;
    typedef Zen::Event::future_return_value<pArtAssetDocumentDomainObject_type>  FutureArtAssetDocumentDomainObject_type;
	typedef Zen::Memory::managed_ptr<FutureArtAssetDocumentDomainObject_type>    pFutureArtAssetDocumentDomainObject_type;
    /// @}

    /// @name I_ArtAssetDocumentDataMap interface
    /// @{
public:
    /// Create a new ArtAssetDocumentDomainObject.
    virtual pArtAssetDocumentDomainObject_type createNew() = 0;
    
    /// Get an object by primary key.
    virtual pFutureArtAssetDocumentDomainObject_type getByKey(boost::uint64_t _primaryKeyValue) = 0;

    /// Delete an object by primary key.
    virtual void deleteByKey(boost::uint64_t _primaryKeyValue) = 0;

    /// Get a collection of Art Asset Documents by explorerNodeId.    
    virtual pFutureArtAssetDocumentDataCollection_type getByExplorerNodeId(const boost::uint64_t _explorerNodeId) = 0;

    /// Get all of the records.
    virtual pFutureArtAssetDocumentDataCollection_type getAll() = 0;

    /// Update a ArtAssetDocumentDomainObject.
    /// If the ArtAssetDocumentDomainObject hasn't been inserted yet, it will be inserted.
    virtual Zen::Database::I_DatabaseTransaction::pFutureKey_type update(pArtAssetDocumentDomainObject_type _pArtAssetDocumentDomainObject) = 0;
    /// @}

    /// @name Static class factory
    /// @{
public:
    static pArtAssetDocumentDataMap_type create(pDatabaseConnection_type _pDatabaseConnection);
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_ArtAssetDocumentDataMap();
    virtual ~I_ArtAssetDocumentDataMap();
    /// @}

};  // interface I_ArtAssetDocumentDataMap

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace ArtLibrary
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

namespace Zen {
namespace Memory {
    /// I_ArtAssetDocumentDataMap is a managed by factory
    template<>
    struct is_managed_by_factory<ArtLibrary::I_ArtAssetDocumentDataMap> : public boost::true_type{};
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Memory
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ARTLIBRARY_I_ARTASSETDOCUMENT_DATA_MAP_HPP_INCLUDED