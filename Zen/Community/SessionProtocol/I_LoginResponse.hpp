//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Community Framework
//
// Copyright (C) 2001 - 2010 Tony Richards
// Copyright (C) 2008 - 2010 Matthew Alan Gray
//
//  This software is provided 'as-is', without any express or implied
//  warranty.  In no event will the authors be held liable for any damages
//  arising from the use of this software.
//
//  Permission is granted to anyone to use this software for any purpose,
//  including commercial applications, and to alter it and redistribute it
//  freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not
//     claim that you wrote the original software. If you use this software
//     in a product, an acknowledgment in the product documentation would be
//     appreciated but is not required.
//  2. Altered source versions must be plainly marked as such, and must not be
//     misrepresented as being the original software.
//  3. This notice may not be removed or altered from any source distribution.
//
//  Tony Richards trichards@indiezen.com
//  Matthew Alan Gray mgray@indiezen.org
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// This is generated by the Zen Protocol Code Generator.  Do not modify!
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_COMMUNITY_SESSION_PROTOCOL_I_LOGIN_RESPONSE_HPP_INCLUDED
#define ZEN_COMMUNITY_SESSION_PROTOCOL_I_LOGIN_RESPONSE_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Memory/managed_ptr.hpp>
#include <Zen/Core/Memory/managed_weak_ptr.hpp>

#include <Zen/Community/SessionProtocol/I_Message.hpp>

#include <Zen/Enterprise/AppServer/I_Response.hpp>

#include <boost/serialization/string.hpp>
#include <string>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Community {
namespace Session {
namespace Protocol {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class SESSIONPROTOCOL_DLL_LINK I_LoginResponse
:   public virtual Zen::Enterprise::AppServer::I_Response
{
    /// @name Types
    /// @{
public:
    typedef Zen::Memory::managed_ptr<Zen::Enterprise::AppServer::I_Response>   pResponse_type;

    /// Session State.
    enum SessionState_type
    {
        INITIALIZED,
        CONNECTED,
        NOT_AUTHORIZED,
        DISCONNECTED
    };
    /// @}

    /// @name Getter / Setter methods
    /// @{
public:
    /// Get the status element.
    virtual const I_LoginResponse::SessionState_type& getStatus() const = 0;
    
    /// Set the status element value.
    virtual void setStatus(const I_LoginResponse::SessionState_type& _status) = 0;

    /// Get the sessionId element.
    virtual const boost::uint32_t& getSessionId() const = 0;
    
    /// Set the sessionId element value.
    virtual void setSessionId(const boost::uint32_t& _sessionId) = 0;
    /// @}

    /// @name Static methods
    /// @{
public:
    static pResponse_type create(pEndpoint_type _pSourceEndpoint,
                                pEndpoint_type _pDestinationEndpoint, boost::uint32_t _requestMessageId);

    static pMessageType_type getStaticMessageType();
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_LoginResponse();
    virtual ~I_LoginResponse();
    /// @}

};  // interface I_LoginResponse

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Community
}   // namespace Session
}   // namespace Protocol
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Memory {
    // I_LoginResponse is managed by factory
    template<>
    struct is_managed_by_factory<Zen::Community::Session::Protocol::I_LoginResponse> : public boost::true_type{};
}   // namespace Memory
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_COMMUNITY_SESSION_PROTOCOL_I_LOGIN_RESPONSE_HPP_INCLUDED