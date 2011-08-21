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
#ifndef ZEN_COMMUNITY_CHAT_CHATLOG_DOMAIN_OBJECT_HPP_INCLUDED
#define ZEN_COMMUNITY_CHAT_CHATLOG_DOMAIN_OBJECT_HPP_INCLUDED

#include "../I_ChatLogDomainObject.hpp"

#include <map>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Community {
namespace Chat {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~


class ChatLogDomainObject
:	public I_ChatLogDomainObject
{
    /// @name Types
    /// @{
public:
    typedef std::map<std::string, pElement_type>    FieldElementMap_type;
    /// @}

    /// @name Getter / Setter methods
    /// @{
public:
    /// Get the ChatLogId element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setChatLogId().
    virtual ElementReference_type getChatLogId() const;
    
    /// Set the ChatLogId element value.
    /// This method does not directly update the database.  
    /// You must use the I_ChatLogDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setChatLogId(const boost::any& _value);

    /// Get the ChannelId element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setChannelId().
    virtual ElementReference_type getChannelId() const;
    
    /// Set the ChannelId element value.
    /// This method does not directly update the database.  
    /// You must use the I_ChatLogDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setChannelId(const boost::any& _value);

    /// Get the AccountId element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setAccountId().
    virtual ElementReference_type getAccountId() const;
    
    /// Set the AccountId element value.
    /// This method does not directly update the database.  
    /// You must use the I_ChatLogDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setAccountId(const boost::any& _value);

    /// Get the MessageType element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setMessageType().
    virtual ElementReference_type getMessageType() const;
    
    /// Set the MessageType element value.
    /// This method does not directly update the database.  
    /// You must use the I_ChatLogDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setMessageType(const boost::any& _value);

    /// Get the Message element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setMessage().
    virtual ElementReference_type getMessage() const;
    
    /// Set the Message element value.
    /// This method does not directly update the database.  
    /// You must use the I_ChatLogDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setMessage(const boost::any& _value);

    /// Get the LogTime element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setLogTime().
    virtual ElementReference_type getLogTime() const;
    
    /// Set the LogTime element value.
    /// This method does not directly update the database.  
    /// You must use the I_ChatLogDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setLogTime(const boost::any& _value);
    
    virtual Zen::Enterprise::DataModel::I_DataElement& getElement(const std::string& _fieldName);
    /// @}

    /// @name Member Variables
    /// @{
private:
    pElement_type               m_pChatLogId;
    pElement_type               m_pChannelId;
    pElement_type               m_pAccountId;
    pElement_type               m_pMessageType;
    pElement_type               m_pMessage;
    pElement_type               m_pLogTime;

    FieldElementMap_type            m_elements;
    /// @}

    /// @name 'Structors
    /// @{
public:
             ChatLogDomainObject();
    virtual ~ChatLogDomainObject();
    /// @}

};  // class ChatLogDomainObject

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Community
}   // namespace Chat
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~


#endif // ZEN_COMMUNITY_CHAT_CHATLOG_DOMAIN_OBJECT_HPP_INCLUDED
