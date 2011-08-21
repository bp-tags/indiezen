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
#ifndef GAMEBUILDER_GAMEOBJECTTYPE_DATA_MAP_HPP_INCLUDED
#define GAMEBUILDER_GAMEOBJECTTYPE_DATA_MAP_HPP_INCLUDED

#include "../I_GameObjectTypeDataMap.hpp"

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace GameBuilder {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~


class GameObjectTypeDataMap
:	public I_GameObjectTypeDataMap
{
    /// @name I_GameObjectTypeDataMap implementation
    /// @{
public:
    virtual pGameObjectTypeDomainObject_type createNew();
    virtual pFutureGameObjectTypeDomainObject_type getByKey(boost::uint64_t _primaryKeyValue);
    virtual void deleteByKey(boost::uint64_t _primaryKeyValue);
    virtual pFutureGameObjectTypeDataCollection_type getByExplorerNodeId(const boost::uint64_t _explorerNodeId);
    virtual pFutureGameObjectTypeDataCollection_type getAll();
    virtual Zen::Database::I_DatabaseTransaction::pFutureKey_type update(pGameObjectTypeDomainObject_type _pGameObjectTypeDomainObject);
    /// @}

    /// @name GameObjectTypeDataMap implementation
    /// @{
public:
    /// Escape the string to prevent SQL injection
    std::string escapeString(const std::string& _value) const;

    /// Get a comma separated list of the fields in this table.
    static const std::string& getFieldNames();

    /// Get a comma separated list of the fields in this table
    /// sans the primary key (gameObjectTypeId).
    static const std::string& getNonPKFieldNames();
    
    /// Get the name of the table this class maps.
    static const std::string& getTableName();

	pDatabaseConnection_type getDatabaseConnection() const;
    /// @}

	/// @name Member Variables
	/// @{
public:
	pDatabaseConnection_type			m_pDatabaseConnection;
	/// @}

    /// @name 'Structors
    /// @{
public:
             GameObjectTypeDataMap(pDatabaseConnection_type _pDatabaseConnection);
    virtual ~GameObjectTypeDataMap();
    /// @}

};  // class GameObjectTypeDataMap

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace GameBuilder
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~


#endif // GAMEBUILDER_GAMEOBJECTTYPE_DATA_MAP_HPP_INCLUDED