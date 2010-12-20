//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Enterprise Framework
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

#include "MessageFactory.hpp"
#include "Message.hpp"

#include "AuthenticateRequest.hpp"
#include "AuthenticateResponse.hpp"

#include <Zen/Enterprise/AppServer/I_NumericTypeMessageRegistry.hpp>
#include <Zen/Enterprise/AppServer/I_MessageHeader.hpp>

#include <Zen/Enterprise/Networking/I_Endpoint.hpp>

#include <Zen/Core/Utility/runtime_exception.hpp>

#include <iostream>

#include <stddef.h>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Enterprise {
namespace Account {
namespace Protocol {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
MessageFactory::MessageFactory()
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
MessageFactory::~MessageFactory()
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
MessageFactory::destroy(MessageFactory::wpMessage_type _pMessage)
{
    Message* pMessage = dynamic_cast<Message*>(_pMessage.get());

    if (pMessage != NULL)
    {
        delete pMessage;
    }
    else
    {
        // TODO Error
    }
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
MessageFactory::pMessage_type
MessageFactory::create(pMessageHeader_type _pMessageHeader, pEndpoint_type _pSourceEndpoint, pEndpoint_type _pDestinationEndpoint)
{
    switch(getMessageType(_pMessageHeader))
    {
        case AuthenticateRequest::type:
            return pMessage_type(
                new AuthenticateRequest(
                    _pMessageHeader,
                    _pSourceEndpoint,
                    _pDestinationEndpoint
                ),
                &destroy
            );

        case AuthenticateResponse::type:
            return pMessage_type(
                new AuthenticateResponse(
                    _pMessageHeader,
                    _pSourceEndpoint,
                    _pDestinationEndpoint
                ),
                &destroy
            );
    }

    // TODO Throw an exception?
    std::cout << "Zen::Enterprise::Account::ProtocolMessageFactory::getMessageType(): Error, wrong message type - " <<
            getMessageType(_pMessageHeader) << std::endl;

    return pMessage_type();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
boost::uint64_t
MessageFactory::getMessageType(pMessageHeader_type _pMessageHeader)
{
    // Assume this is a numeric type.
    Zen::Enterprise::AppServer::I_NumericTypeMessageRegistry::I_NumericType*
        pType = dynamic_cast<Zen::Enterprise::AppServer::I_NumericTypeMessageRegistry::I_NumericType*>
            (_pMessageHeader->getMessageType().get());

    if (pType != NULL)
    {
        return pType->getType();
    }
    else
    {
        throw Zen::Utility::runtime_exception("MessageFactory::getMessageType(): Error, invalid message type.");
    }
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Protocol
}   // namespace Account
}   // namespace Enterprise
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
