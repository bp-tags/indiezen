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
#include "ProjectDataMap.hpp"

#include "ProjectDomainObject.hpp"
#include "ProjectDataCollection.hpp"

#include <Zen/Core/Memory/managed_weak_ptr.hpp>

#include <Zen/Enterprise/Database/I_DatabaseStaticQuery.hpp>
#include <Zen/Enterprise/Database/I_DatabaseResult.hpp>
#include <Zen/Enterprise/Database/I_DatabaseColumn.hpp>
#include <Zen/Enterprise/Database/I_DatabaseRow.hpp>

#include <Zen/Core/Utility/runtime_exception.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Studio {
namespace Workbench {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

ProjectDataMap::ProjectDataMap(pDatabaseConnection_type _pDatabaseConnection)
:   m_pDatabaseConnection(_pDatabaseConnection)
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ProjectDataMap::~ProjectDataMap()
{
}

static void 
destroyObject(Zen::Memory::managed_weak_ptr<I_ProjectDomainObject> _wpObject);

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace {
struct FieldHandler
:   public Zen::Database::I_DatabaseRow::I_FieldVisitor
{
    virtual void begin()    {}

    virtual void visit(const Zen::Database::I_DatabaseColumn& _column, const boost::any& _value)
    {
        m_pValue->getElement(_column.getFieldName()).setAnyValue(_value);
    }

    virtual void end()      {}

    FieldHandler(ProjectDataMap::pProjectDomainObject_type _pValue)
    : m_pValue(_pValue)
    {
    }

    virtual ~FieldHandler()
    {
    }

private:
    ProjectDataMap::pProjectDomainObject_type       m_pValue;
};

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
struct RowHandler
:   public Zen::Database::I_DatabaseResult::I_ResultVisitor
{
    virtual void begin()
    {
    }

    virtual void visit(const Zen::Database::I_DatabaseRow& _databaseRow)
    {
        FieldHandler fieldHandler(m_pValue);

        _databaseRow.getFields(fieldHandler);
    }

    virtual void end()
    {
    }

    RowHandler(ProjectDataMap::pProjectDomainObject_type _pValue)
    : m_pValue(_pValue)
    {
    }

    virtual ~RowHandler()
    {
    }
    
private:
    ProjectDataMap::pProjectDomainObject_type           m_pValue;
};

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class ResultHandler
:   public Zen::Database::I_DatabaseTransaction::I_QueryResultHandler
{
public:
    virtual void handleResult(pDatabaseResult_type _pResult)
    {
        RowHandler rowHandler(m_pValue);

        _pResult->getResults(rowHandler);

        m_pFutureValue->setValue(m_pValue);

        // Done, so commit the transaction.
        m_pTransaction->commit();
    }

    /// @param _pTransaction - We want to keep a reference to the transaction so it does 
    ///         not go out of scope until the results have been fully handled.
    ResultHandler(Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type _pTransaction,
                 ProjectDataMap::pFutureProjectDomainObject_type _pFutureValue,
                 ProjectDataMap::pProjectDomainObject_type _pValue)
    :   m_pTransaction(_pTransaction)
    ,   m_pFutureValue(_pFutureValue)
    ,   m_pValue(_pValue)
    {
    }

    virtual ~ResultHandler()
    {
    }

private:
    Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type  m_pTransaction;
    ProjectDataMap::pFutureProjectDomainObject_type     m_pFutureValue;
    ProjectDataMap::pProjectDomainObject_type           m_pValue;
};

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
struct CollectionRowHandler
:   public Zen::Database::I_DatabaseResult::I_ResultVisitor
{
    virtual void begin()
    {
    }

    virtual void visit(const Zen::Database::I_DatabaseRow& _databaseRow)
    {
        ProjectDataMap::pProjectDomainObject_type pValue(new ProjectDomainObject, &destroyObject);
        
        m_pCollection->push_back(pValue);

        FieldHandler fieldHandler(pValue);

        _databaseRow.getFields(fieldHandler);
    }

    virtual void end()
    {
    }

    CollectionRowHandler(ProjectDataMap::pProjectDataCollection_type _pCollection)
    : m_pCollection(_pCollection)
    {
    }

    virtual ~CollectionRowHandler()
    {
    }
    
private:
    ProjectDataMap::pProjectDataCollection_type     m_pCollection;
};

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class CollectionResultHandler
:   public Zen::Database::I_DatabaseTransaction::I_QueryResultHandler
{
public:
    virtual void handleResult(pDatabaseResult_type _pResult)
    {
        CollectionRowHandler rowHandler(m_pCollection);

        _pResult->getResults(rowHandler);

        m_pFutureCollection->setValue(m_pCollection);

        // Done, so commit the transaction.
        m_pTransaction->commit();
    }

    /// @param _pTransaction - We want to keep a reference to the transaction so it does 
    ///         not go out of scope until the results have been fully handled.
    CollectionResultHandler(Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type _pTransaction,
                 ProjectDataMap::pFutureProjectDataCollection_type _pFutureCollection,
                 ProjectDataMap::pProjectDataCollection_type _pCollection)
    :   m_pTransaction(_pTransaction)
    ,   m_pFutureCollection(_pFutureCollection)
    ,   m_pCollection(_pCollection)
    {
    }

    virtual ~CollectionResultHandler()
    {
    }

private:
    Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type  m_pTransaction;
    ProjectDataMap::pFutureProjectDataCollection_type     m_pFutureCollection;
    ProjectDataMap::pProjectDataCollection_type     m_pCollection;
};

} // namespace
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
static void
destroyObject(Zen::Memory::managed_weak_ptr<I_ProjectDomainObject> _wpObject)
{
    ProjectDomainObject* pObject = dynamic_cast<ProjectDomainObject*>(_wpObject.get());
    if (pObject != NULL)
    {
        delete pObject;
    }
    else
    {
        // TODO Error?
    }
}
 
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
static void
destroyCollection(Zen::Memory::managed_weak_ptr<I_ProjectDataCollection> _wpCollection)
{
    ProjectDataCollection* pCollection = dynamic_cast<ProjectDataCollection*>(_wpCollection.get());
    if (pCollection != NULL)
    {
        delete pCollection;
    }
    else
    {
        // TODO Error?
    }
}
 
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ProjectDataMap::pProjectDomainObject_type 
ProjectDataMap::createNew()
{
    return pProjectDomainObject_type(new ProjectDomainObject, &destroyObject);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ProjectDataMap::pFutureProjectDomainObject_type
ProjectDataMap::getByKey(boost::uint64_t _primaryKeyValue)
{
    // Start a transaction
    Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type 
        pTransaction = getDatabaseConnection()->beginTransaction();

    // Create a query
    Zen::Database::I_DatabaseTransaction::pStaticQuery_type 
        pQuery = pTransaction->createStaticQuery();

	const boost::uint64_t primaryKeyValue(_primaryKeyValue);

    // Get a record from the Project.
    std::stringstream query;
    query << "SELECT * FROM Project WHERE projectId = " << primaryKeyValue;

    pQuery->setQuery(query.str());
    
	pFutureProjectDomainObject_type pReturnValue(new FutureProjectDomainObject_type);
    pProjectDomainObject_type pValue(new ProjectDomainObject, &destroyObject);

    // Create a result handler to handle the execution results
    Zen::Database::I_DatabaseTransaction::pQueryResultHandler_type pResultHandler(new ResultHandler(pTransaction, pReturnValue, pValue));

    // Execute the query.  
    pTransaction->executeQuery(pQuery, pResultHandler);
    
    return pReturnValue;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
ProjectDataMap::deleteByKey(boost::uint64_t _primaryKeyValue)
{
    // Don't do anything if the key value is 0.  But should this be an error?
    if (_primaryKeyValue == 0)
    {
        // TODO Throw an exception or return an error?
        return;
    }

    // Start a transaction
    Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type 
        pTransaction = getDatabaseConnection()->beginTransaction();

    // Create a query
    Zen::Database::I_DatabaseTransaction::pStaticQuery_type 
        pQuery = pTransaction->createStaticQuery();

	const boost::uint64_t primaryKeyValue(_primaryKeyValue);

    // Delete a record in the Project.
    std::stringstream query;
    query << "DELETE FROM Project WHERE projectId = " << primaryKeyValue;

    pQuery->setQuery(query.str());

    // Execute the query.  
    pTransaction->executeQuery(pQuery);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Zen::Database::I_DatabaseTransaction::pFutureKey_type
ProjectDataMap::update(pProjectDomainObject_type _pProjectDomainObject)
{
    // Start a transaction
    Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type 
        pTransaction = getDatabaseConnection()->beginTransaction();

    // Create a query
    Zen::Database::I_DatabaseTransaction::pStaticQuery_type 
        pQuery = pTransaction->createStaticQuery();

    std::stringstream query;

    if (_pProjectDomainObject->getProjectId().isNull())
    {
        // Construct the query to insert a record into the Project table.

        query << "INSERT into Project ( "
            << getNonPKFieldNames() << " ) VALUES ( ";

        // Append all of the values
        std::string escapedStringValue;
        
        escapedStringValue = escapeString(_pProjectDomainObject->getExplorerNodeId().getStringValue());
        query << "\'" << escapedStringValue << "\'";
        escapedStringValue = escapeString(_pProjectDomainObject->getName().getStringValue());
        query << ", \'" << escapedStringValue << "\'";

        // Final closing parenthesis
        query << ")";

        pQuery->setQuery(query.str());

        // Execute the query.
        Zen::Database::I_DatabaseTransaction::pFutureKey_type 
            pKey(pTransaction->executeInsert(pQuery));

        _pProjectDomainObject->getProjectId() = pKey->getValue();
        
        // Done, so commit the transaction.
        pTransaction->commit();

        return pKey;
    }
    else
    {
        // Construct the query to update a record into the Project table.

        // Count the number of dirty fields.
        int dirtyFields = 0;

        query << "UPDATE Project SET ";

        std::string separator("");

        // Append all of the field names and values
        std::string escapedStringValue;

        if (_pProjectDomainObject->getExplorerNodeId().isDirty())
        {
            escapedStringValue = escapeString(_pProjectDomainObject->getExplorerNodeId().getStringValue());
            query << separator << "explorerNodeId = \'" 
                << escapedStringValue << "\'";
            separator = ", ";
            dirtyFields++;
        }
        if (_pProjectDomainObject->getName().isDirty())
        {
            escapedStringValue = escapeString(_pProjectDomainObject->getName().getStringValue());
            query << separator << "name = \'" 
                << escapedStringValue << "\'";
            separator = ", ";
            dirtyFields++;
        }

        // No need to proceed if none of the fields were dirty.
        if (dirtyFields > 0)
        {
            // WHERE clause to update the record
            query << " WHERE projectId = " << 
                _pProjectDomainObject->getProjectId().getInt64Value();

            pQuery->setQuery(query.str());

            // Execute the query.  
            pTransaction->executeQuery(pQuery);

            // Done, so commit the transaction.
            pTransaction->commit();
        }
        
        Zen::Database::I_DatabaseTransaction::pFutureKey_type 
            pKey(new Zen::Database::I_DatabaseTransaction::FutureKey_type);

        pKey->setValue(_pProjectDomainObject->getProjectId().getInt64Value());

        return pKey;
    }

}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ProjectDataMap::pFutureProjectDataCollection_type
ProjectDataMap::getByProjectName(const std::string& _projectName)
{
    pFutureProjectDataCollection_type pFutureCollection(new FutureProjectDataCollection_type);
    pProjectDataCollection_type pCollection(new ProjectDataCollection, &destroyCollection);

    // Start a transaction
    Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type 
        pTransaction = getDatabaseConnection()->beginTransaction();

    // Create a query
    Zen::Database::I_DatabaseTransaction::pStaticQuery_type 
        pQuery = pTransaction->createStaticQuery();

    // Get a collection of Projects by name.
    std::stringstream query;
    query << "SELECT * FROM Project WHERE " << "projectName == \'" << escapeString(_projectName) << "\'";

    pQuery->setQuery(query.str());
    
    // Create a result handler to handle the execution results
    Zen::Database::I_DatabaseTransaction::pQueryResultHandler_type pResultHandler(new CollectionResultHandler(pTransaction, pFutureCollection, pCollection));

    // Execute the query.  
    pTransaction->executeQuery(pQuery, pResultHandler);    
    
    return pFutureCollection;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ProjectDataMap::pFutureProjectDataCollection_type
ProjectDataMap::getByProjectType(const std::string& _projectType)
{
    pFutureProjectDataCollection_type pFutureCollection(new FutureProjectDataCollection_type);
    pProjectDataCollection_type pCollection(new ProjectDataCollection, &destroyCollection);

    // Start a transaction
    Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type 
        pTransaction = getDatabaseConnection()->beginTransaction();

    // Create a query
    Zen::Database::I_DatabaseTransaction::pStaticQuery_type 
        pQuery = pTransaction->createStaticQuery();

    // Get a collection of Projects by type.
    std::stringstream query;
    query << "SELECT * FROM Project WHERE " << "projectType == \'" << escapeString(_projectType) << "\'";

    pQuery->setQuery(query.str());
    
    // Create a result handler to handle the execution results
    Zen::Database::I_DatabaseTransaction::pQueryResultHandler_type pResultHandler(new CollectionResultHandler(pTransaction, pFutureCollection, pCollection));

    // Execute the query.  
    pTransaction->executeQuery(pQuery, pResultHandler);    
    
    return pFutureCollection;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ProjectDataMap::pFutureProjectDataCollection_type
ProjectDataMap::getAll()
{
    pFutureProjectDataCollection_type pFutureCollection(new FutureProjectDataCollection_type);
    pProjectDataCollection_type pCollection(new ProjectDataCollection, &destroyCollection);

    // Start a transaction
    Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type 
        pTransaction = getDatabaseConnection()->beginTransaction();

    // Create a query
    Zen::Database::I_DatabaseTransaction::pStaticQuery_type 
        pQuery = pTransaction->createStaticQuery();

    // Get all of the records from the Project.
    pQuery->setQuery("SELECT * FROM Project");

    // Create a result handler to handle the execution results
    Zen::Database::I_DatabaseTransaction::pQueryResultHandler_type pResultHandler(new CollectionResultHandler(pTransaction, pFutureCollection, pCollection));

    // Execute the query.  
    pTransaction->executeQuery(pQuery, pResultHandler);    
    
    return pFutureCollection;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
        
std::string
ProjectDataMap::escapeString(const std::string& _value) const
{
	return getDatabaseConnection()->escapeString(_value);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
static std::string sm_fieldNames = "projectId, explorerNodeId, name";
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
static std::string sm_nonPKFieldNames = "explorerNodeId, name";
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
const std::string&
ProjectDataMap::getFieldNames()
{
    return sm_fieldNames;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
const std::string&
ProjectDataMap::getNonPKFieldNames()
{
    return sm_nonPKFieldNames;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
static std::string sm_tableName = "Project";
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
const std::string&
ProjectDataMap::getTableName()
{
    return sm_tableName;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ProjectDataMap::pDatabaseConnection_type
ProjectDataMap::getDatabaseConnection() const
{
	return m_pDatabaseConnection;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Studio
}   // namespace Workbench
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

