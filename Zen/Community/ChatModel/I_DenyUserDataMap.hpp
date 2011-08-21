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
#ifndef ZEN_COMMUNITY_CHAT_I_DENYUSER_DATA_MAP_HPP_INCLUDED
#define ZEN_COMMUNITY_CHAT_I_DENYUSER_DATA_MAP_HPP_INCLUDED

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

class I_DenyUserDomainObject;
class I_DenyUserDataCollection;

class CHATMODEL_DLL_LINK I_DenyUserDataMap
:	public boost::noncopyable
{

    /// @name Types
    /// @{
public:
//    typedef Zen::Memory::managed_ptr<I_DenyUserDomainObject>   pDenyUserDomainObject_type;
//    typedef Zen::Memory::managed_ptr<I_DenyUserDataCollection>     pDenyUserDataCollection_type;
    typedef Zen::Memory::managed_ptr<I_DenyUserDataMap>        pDenyUserDataMap_type;

    typedef Zen::Database::I_DatabaseService::pDatabaseConnection_type      pDatabaseConnection_type;

    typedef Zen::Memory::managed_ptr<I_DenyUserDataCollection>  pDenyUserDataCollection_type;
    typedef Zen::Event::future_return_value<pDenyUserDataCollection_type>  FutureDenyUserDataCollection_type;
	typedef Zen::Memory::managed_ptr<FutureDenyUserDataCollection_type>    pFutureDenyUserDataCollection_type;
    
    typedef Zen::Memory::managed_ptr<I_DenyUserDomainObject>  pDenyUserDomainObject_type;
    typedef Zen::Event::future_return_value<pDenyUserDomainObject_type>  FutureDenyUserDomainObject_type;
	typedef Zen::Memory::managed_ptr<FutureDenyUserDomainObject_type>    pFutureDenyUserDomainObject_type;
    /// @}

    /// @name I_DenyUserDataMap interface
    /// @{
public:
    /// Create a new DenyUserDomainObject.
    virtual pDenyUserDomainObject_type createNew() = 0;
    
    /// Get an object by primary key.
    virtual pFutureDenyUserDomainObject_type getByKey(boost::uint64_t _primaryKeyValue) = 0;

    /// Delete an object by primary key.
    virtual void deleteByKey(boost::uint64_t _primaryKeyValue) = 0;

    /// Get a collection of denied accounts by channel.    
    virtual pFutureDenyUserDataCollection_type getByChannel(Common::I_Channel& _channel) = 0;

    /// Get a collection of channels an account is denied access.    
    virtual pFutureDenyUserDataCollection_type getByAccount(Common::I_Account& _account) = 0;

    /// Get all of the records.
    virtual pFutureDenyUserDataCollection_type getAll() = 0;

    /// Update a DenyUserDomainObject.
    /// If the DenyUserDomainObject hasn't been inserted yet, it will be inserted.
    virtual Zen::Database::I_DatabaseTransaction::pFutureKey_type update(pDenyUserDomainObject_type _pDenyUserDomainObject) = 0;
    /// @}

    /// @name Static class factory
    /// @{
public:
    static pDenyUserDataMap_type create(pDatabaseConnection_type _pDatabaseConnection);
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_DenyUserDataMap();
    virtual ~I_DenyUserDataMap();
    /// @}

};  // interface I_DenyUserDataMap

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Community
}   // namespace Chat
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

namespace Zen {
namespace Memory {
    /// I_DenyUserDataMap is a managed by factory
    template<>
    struct is_managed_by_factory<Zen::Community::Chat::I_DenyUserDataMap> : public boost::true_type{};
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Memory
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_COMMUNITY_CHAT_I_DENYUSER_DATA_MAP_HPP_INCLUDED