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
#ifndef GAMEBUILDER_GAMEOBJECTFOLDER_DOMAIN_OBJECT_HPP_INCLUDED
#define GAMEBUILDER_GAMEOBJECTFOLDER_DOMAIN_OBJECT_HPP_INCLUDED

#include "../I_GameObjectFolderDomainObject.hpp"

#include <map>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace GameBuilder {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~


class GameObjectFolderDomainObject
:	public I_GameObjectFolderDomainObject
{
    /// @name Types
    /// @{
public:
    typedef std::map<std::string, pElement_type>    FieldElementMap_type;
    /// @}

    /// @name Getter / Setter methods
    /// @{
public:
    /// Get the GameObjectFolderId element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setGameObjectFolderId().
    virtual ElementReference_type getGameObjectFolderId() const;
    
    /// Set the GameObjectFolderId element value.
    /// This method does not directly update the database.  
    /// You must use the I_GameObjectFolderDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setGameObjectFolderId(const boost::any& _value);

    /// Get the ExplorerNodeId element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setExplorerNodeId().
    virtual ElementReference_type getExplorerNodeId() const;
    
    /// Set the ExplorerNodeId element value.
    /// This method does not directly update the database.  
    /// You must use the I_GameObjectFolderDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setExplorerNodeId(const boost::any& _value);

    /// Get the Name element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setName().
    virtual ElementReference_type getName() const;
    
    /// Set the Name element value.
    /// This method does not directly update the database.  
    /// You must use the I_GameObjectFolderDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setName(const boost::any& _value);
    
    virtual Zen::Enterprise::DataModel::I_DataElement& getElement(const std::string& _fieldName);
    /// @}

    /// @name Member Variables
    /// @{
private:
    pElement_type               m_pGameObjectFolderId;
    pElement_type               m_pExplorerNodeId;
    pElement_type               m_pName;

    FieldElementMap_type            m_elements;
    /// @}

    /// @name 'Structors
    /// @{
public:
             GameObjectFolderDomainObject();
    virtual ~GameObjectFolderDomainObject();
    /// @}

};  // class GameObjectFolderDomainObject

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace GameBuilder
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~


#endif // GAMEBUILDER_GAMEOBJECTFOLDER_DOMAIN_OBJECT_HPP_INCLUDED
