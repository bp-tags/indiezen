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
#ifndef ZEN_STUDIO_WORKBENCH_PROJECT_DATA_COLLECTION_HPP_INCLUDED
#define ZEN_STUDIO_WORKBENCH_PROJECT_DATA_COLLECTION_HPP_INCLUDED

#include "../I_ProjectDataCollection.hpp"

#include <list>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Studio {
namespace Workbench {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~


class ProjectDataCollection
:	public I_ProjectDataCollection
{
    /// @name I_ProjectDataCollection implementation.
    /// @{
public:
    virtual void push_back(pProjectDomainObject_type _pDomainObject);
    virtual void getAll(I_CollectionVisitor& _visitor);
    virtual bool isEmpty() const;
    /// @}

    /// @name 'Structors
    /// @{
public:
             ProjectDataCollection();
    virtual ~ProjectDataCollection();
    /// @}

    /// @name Member Variables
    /// @{
private:
    typedef std::list<pProjectDomainObject_type>  Collection_type;
    Collection_type                                     m_objects;
    /// @}
    
};  // class ProjectDataCollection

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Studio
}   // namespace Workbench
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~


#endif // ZEN_STUDIO_WORKBENCH_PROJECT_DATA_COLLECTION_HPP_INCLUDED
