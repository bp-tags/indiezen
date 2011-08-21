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
#ifndef ZEN_COMMUNITY_CHAT_I_ALLOWUSER_DATA_MAP_HPP_INCLUDED
#define ZEN_COMMUNITY_CHAT_I_ALLOWUSER_DATA_MAP_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Memory/managed_ptr.hpp>

#include <Zen/Enterprise/Database/I_DatabaseConnection.hpp>
#include <Zen/Enterprise/Database/I_DatabaseService.hpp>
#include <Zen/Enterprise/Database/I_DatabaseTransaction.hpp>

#include <boost/cstdint.hpp>
#include <Zen/Community/AccountCommon/I_Account.hpp>
#include <Zen/Community/ChatCommon/I_Channel.hpp>

#include <boost/noncopyable.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Community {
namespace Chat {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class I_AllowUserDomainObject;
class I_AllowUserDataCollection;

class CHATMODEL_DLL_LINK I_AllowUserDataMap
:	public boost::noncopyable
{

    /// @name Types
    /// @{
public:
//    typedef Zen::Memory::managed_ptr<I_AllowUserDomainObject>   pAllowUserDomainObject_type;
//    typedef Zen::Memory::managed_ptr<I_AllowUserDataCollection>     pAllowUserDataCollection_type;
    typedef Zen::Memory::managed_ptr<I_AllowUserDataMap>        pAllowUserDataMap_type;

    typedef Zen::Database::I_DatabaseService::pDatabaseConnection_type      pDatabaseConnection_type;

    typedef Zen::Memory::managed_ptr<I_AllowUserDataCollection>  pAllowUserDataCollection_type;
    typedef Zen::Event::future_return_value<pAllowUserDataCollection_type>  FutureAllowUserDataCollection_type;
	typedef Zen::Memory::managed_ptr<FutureAllowUserDataCollection_type>    pFutureAllowUserDataCollection_type;
    
    typedef Zen::Memory::managed_ptr<I_AllowUserDomainObject>  pAllowUserDomainObject_type;
    typedef Zen::Event::future_return_value<pAllowUserDomainObject_type>  FutureAllowUserDomainObject_type;
	typedef Zen::Memory::managed_ptr<FutureAllowUserDomainObject_type>    pFutureAllowUserDomainObject_type;
    /// @}

    /// @name I_AllowUserDataMap interface
    /// @{
public:
    /// Create a new AllowUserDomainObject.
    virtual pAllowUserDomainObject_type createNew() = 0;
    
    /// Get an object by primary key.
    virtual pFutureAllowUserDomainObject_type getByKey(boost::uint64_t _primaryKeyValue) = 0;

    /// Delete an object by primary key.
    virtual void deleteByKey(boost::uint64_t _primaryKeyValue) = 0;

    /// Get a collection of allowed accounts by channel.    
    virtual pFutureAllowUserDataCollection_type getByChannel(Common::I_Channel& _channel) = 0;

    /// Get a collection of channels an account is allowed to access.    
    virtual pFutureAllowUserDataCollection_type getByAccount(Common::I_Account& _account) = 0;

    /// Get all of the records.
    virtual pFutureAllowUserDataCollection_type getAll() = 0;

    /// Update a AllowUserDomainObject.
    /// If the AllowUserDomainObject hasn't been inserted yet, it will be inserted.
    virtual Zen::Database::I_DatabaseTransaction::pFutureKey_type update(pAllowUserDomainObject_type _pAllowUserDomainObject) = 0;
    /// @}

    /// @name Static class factory
    /// @{
public:
    static pAllowUserDataMap_type create(pDatabaseConnection_type _pDatabaseConnection);
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_AllowUserDataMap();
    virtual ~I_AllowUserDataMap();
    /// @}

};  // interface I_AllowUserDataMap

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Community
}   // namespace Chat
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

namespace Zen {
namespace Memory {
    /// I_AllowUserDataMap is a managed by factory
    template<>
    struct is_managed_by_factory<Zen::Community::Chat::I_AllowUserDataMap> : public boost::true_type{};
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Memory
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_COMMUNITY_CHAT_I_ALLOWUSER_DATA_MAP_HPP_INCLUDED