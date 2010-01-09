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
#ifndef ZEN_STUDIO_WORKBENCH_I_SPREADSHEETDOCUMENT_DOMAIN_OBJECT_HPP_INCLUDED
#define ZEN_STUDIO_WORKBENCH_I_SPREADSHEETDOCUMENT_DOMAIN_OBJECT_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Memory/managed_ptr.hpp>

#include <Zen/Enterprise/DataModel/I_DataElement.hpp>

#include <boost/noncopyable.hpp>
#include <boost/any.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Studio {
namespace Workbench {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~


class WORKBENCHMODEL_DLL_LINK I_SpreadSheetDocumentDomainObject
:	public boost::noncopyable
{
    /// @name Types
    /// @{
public:
    typedef Zen::Memory::managed_ptr<Zen::Enterprise::DataModel::I_DataElement> pElement_type;
    typedef Zen::Enterprise::DataModel::I_DataElement&                          ElementReference_type;
    /// @}

    /// @name Getter / Setter methods
    /// @{
public:
    /// Get the SpreadSheetDocumentId element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setSpreadSheetDocumentId().
    virtual ElementReference_type getSpreadSheetDocumentId() const = 0;
    
    /// Set the SpreadSheetDocumentId element value.
    /// This method does not directly update the database.  
    /// You must use the I_SpreadSheetDocumentDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setSpreadSheetDocumentId(const boost::any& _value) = 0;

    /// Get the ExplorerNodeId element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setExplorerNodeId().
    virtual ElementReference_type getExplorerNodeId() const = 0;
    
    /// Set the ExplorerNodeId element value.
    /// This method does not directly update the database.  
    /// You must use the I_SpreadSheetDocumentDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setExplorerNodeId(const boost::any& _value) = 0;
    
    virtual Zen::Enterprise::DataModel::I_DataElement& getElement(const std::string& _fieldName) = 0;
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_SpreadSheetDocumentDomainObject();
    virtual ~I_SpreadSheetDocumentDomainObject();
    /// @}

};  // interface I_SpreadSheetDocumentDomainObject

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Studio
}   // namespace Workbench
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

namespace Zen {
namespace Memory {
    /// I_SpreadSheetDocumentDomainObject is a managed by factory
    template<>
    struct is_managed_by_factory<Zen::Studio::Workbench::I_SpreadSheetDocumentDomainObject> : public boost::true_type{};
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Memory
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_STUDIO_WORKBENCH_I_SPREADSHEETDOCUMENT_DOMAIN_OBJECT_HPP_INCLUDED
