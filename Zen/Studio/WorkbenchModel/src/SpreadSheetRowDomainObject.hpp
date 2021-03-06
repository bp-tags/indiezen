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
#ifndef ZEN_STUDIO_WORKBENCH_SPREADSHEETROW_DOMAIN_OBJECT_HPP_INCLUDED
#define ZEN_STUDIO_WORKBENCH_SPREADSHEETROW_DOMAIN_OBJECT_HPP_INCLUDED

#include "../I_SpreadSheetRowDomainObject.hpp"

#include <map>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Studio {
namespace Workbench {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~


class SpreadSheetRowDomainObject
:	public I_SpreadSheetRowDomainObject
{
    /// @name Types
    /// @{
public:
    typedef std::map<std::string, pElement_type>    FieldElementMap_type;
    /// @}

    /// @name Getter / Setter methods
    /// @{
public:
    /// Get the SpreadSheetRowId element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setSpreadSheetRowId().
    virtual ElementReference_type getSpreadSheetRowId() const;
    
    /// Set the SpreadSheetRowId element value.
    /// This method does not directly update the database.  
    /// You must use the I_SpreadSheetRowDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setSpreadSheetRowId(const boost::any& _value);

    /// Get the SpreadSheetDocumentId element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setSpreadSheetDocumentId().
    virtual ElementReference_type getSpreadSheetDocumentId() const;
    
    /// Set the SpreadSheetDocumentId element value.
    /// This method does not directly update the database.  
    /// You must use the I_SpreadSheetRowDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setSpreadSheetDocumentId(const boost::any& _value);

    /// Get the RowNumber element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setRowNumber().
    virtual ElementReference_type getRowNumber() const;
    
    /// Set the RowNumber element value.
    /// This method does not directly update the database.  
    /// You must use the I_SpreadSheetRowDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setRowNumber(const boost::any& _value);

    /// Get the RowText element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setRowText().
    virtual ElementReference_type getRowText() const;
    
    /// Set the RowText element value.
    /// This method does not directly update the database.  
    /// You must use the I_SpreadSheetRowDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setRowText(const boost::any& _value);
    
    virtual Zen::Enterprise::DataModel::I_DataElement& getElement(const std::string& _fieldName);
    /// @}

    /// @name Member Variables
    /// @{
private:
    pElement_type               m_pSpreadSheetRowId;
    pElement_type               m_pSpreadSheetDocumentId;
    pElement_type               m_pRowNumber;
    pElement_type               m_pRowText;

    FieldElementMap_type            m_elements;
    /// @}

    /// @name 'Structors
    /// @{
public:
             SpreadSheetRowDomainObject();
    virtual ~SpreadSheetRowDomainObject();
    /// @}

};  // class SpreadSheetRowDomainObject

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Studio
}   // namespace Workbench
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~


#endif // ZEN_STUDIO_WORKBENCH_SPREADSHEETROW_DOMAIN_OBJECT_HPP_INCLUDED
