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
#ifndef ZEN_ENTERPRISE_ACCOUNT_CLIENT_I_ACCOUNT_SERVICE_HPP_INCLUDED
#define ZEN_ENTERPRISE_ACCOUNT_CLIENT_I_ACCOUNT_SERVICE_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Enterprise/Account/I_AccountService.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
	namespace Networking {
		class I_Endpoint;
	}	// namespace Networking
namespace Enterprise {
namespace Account {
namespace Client {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

/// Account Service interface.
/// @see I_ApplicationServer::getApplication() to get an instance of an
///     implementation of this interface.
class ACCOUNT_CLIENT_DLL_LINK I_AccountService
:   public Zen::Enterprise::Account::I_AccountService
{
    /// @name Types
    /// @{
public:
	typedef Zen::Memory::managed_ptr<Zen::Networking::I_Endpoint>	pEndpoint_type;
    /// @}

    /// @name I_AccountService interface
    /// @{
public:
    /// Authenticate an account.
    /// When an authentication operation is executed, the authentication event
    /// is fired.
    /// @see getAuthenticationEvent().
    virtual boost::uint64_t authenticate(pEndpoint_type _pDestinationEndpoint,
                                         pResourceLocation_type _pDestLocation,
                                         const std::string& _name,
                                         const std::string& _password) = 0;
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_AccountService();
    virtual ~I_AccountService();
    /// @}

};  // interface I_AccountService

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Client
}   // namespace Account
}   // namespace Enterprise
namespace Memory {
	/// I_AccountService is managed by factory
	template<>
    struct is_managed_by_factory<Zen::Enterprise::Account::Client::I_AccountService>
	:	public boost::true_type{};
}	// namespace Memory
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_ENTERPRISE_ACCOUNT_CLIENT_I_ACCOUNT_SERVICE_HPP_INCLUDED
