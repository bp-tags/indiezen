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
#ifndef ARTLIBRARY_I_ARTASSETEXPLORERNODE_DATA_COLLECTION_HPP_INCLUDED
#define ARTLIBRARY_I_ARTASSETEXPLORERNODE_DATA_COLLECTION_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Memory/managed_ptr.hpp>


#include <boost/noncopyable.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace ArtLibrary {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class I_ArtAssetExplorerNodeDomainObject;

class ARTLIBRARYMODEL_DLL_LINK I_ArtAssetExplorerNodeDataCollection
:	public boost::noncopyable
{
    /// @name Types
    /// @{
public:
    typedef Zen::Memory::managed_ptr<I_ArtAssetExplorerNodeDomainObject>  pArtAssetExplorerNodeDomainObject_type;

    /// Declared below
    struct I_CollectionVisitor;
    /// @}

    /// @name I_ArtAssetExplorerNodeDataCollection interface.
    /// @{
public:
    /// Push a domain object onto the end of the collection.
    /// This is normally only used by the DomainMap implementation.
    virtual void push_back(pArtAssetExplorerNodeDomainObject_type _pDomainObject) = 0;
    
    /// Get all of the docmain objects in this collection using a visitor.
    virtual void getAll(I_CollectionVisitor& _visitor) = 0;
    
    /// @return true if this collection is empty.
    virtual bool isEmpty() const = 0;
    /// @}

    /// @name Inner Classes
    /// @{
public:
    struct I_CollectionVisitor
    {
        virtual void begin() = 0;
        virtual void visit(pArtAssetExplorerNodeDomainObject_type _pDomainObject) = 0;
        virtual void end() = 0;
    };  // interface I_CollectionVisitor

    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_ArtAssetExplorerNodeDataCollection();
    virtual ~I_ArtAssetExplorerNodeDataCollection();
    /// @}

};  // interface I_ArtAssetExplorerNodeDataCollection

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace ArtLibrary
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

namespace Zen {
namespace Memory {
    /// I_ArtAssetExplorerNodeDataCollection is a managed by factory
    template<>
    struct is_managed_by_factory<ArtLibrary::I_ArtAssetExplorerNodeDataCollection> : public boost::true_type{};
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Memory
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ARTLIBRARY_I_ARTASSETEXPLORERNODE_DATA_COLLECTION_HPP_INCLUDED