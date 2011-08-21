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
#include "SpreadSheetCellDataMap.hpp"

#include "SpreadSheetCellDomainObject.hpp"
#include "SpreadSheetCellDataCollection.hpp"

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

SpreadSheetCellDataMap::SpreadSheetCellDataMap(pDatabaseConnection_type _pDatabaseConnection)
:   m_pDatabaseConnection(_pDatabaseConnection)
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
SpreadSheetCellDataMap::~SpreadSheetCellDataMap()
{
}

static void 
destroyObject(Zen::Memory::managed_weak_ptr<I_SpreadSheetCellDomainObject> _wpObject);

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

    FieldHandler(SpreadSheetCellDataMap::pSpreadSheetCellDomainObject_type _pValue)
    : m_pValue(_pValue)
    {
    }

    virtual ~FieldHandler()
    {
    }

private:
    SpreadSheetCellDataMap::pSpreadSheetCellDomainObject_type       m_pValue;
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

    RowHandler(SpreadSheetCellDataMap::pSpreadSheetCellDomainObject_type _pValue)
    : m_pValue(_pValue)
    {
    }

    virtual ~RowHandler()
    {
    }
    
private:
    SpreadSheetCellDataMap::pSpreadSheetCellDomainObject_type           m_pValue;
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
                 SpreadSheetCellDataMap::pFutureSpreadSheetCellDomainObject_type _pFutureValue,
                 SpreadSheetCellDataMap::pSpreadSheetCellDomainObject_type _pValue)
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
    SpreadSheetCellDataMap::pFutureSpreadSheetCellDomainObject_type     m_pFutureValue;
    SpreadSheetCellDataMap::pSpreadSheetCellDomainObject_type           m_pValue;
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
        SpreadSheetCellDataMap::pSpreadSheetCellDomainObject_type pValue(new SpreadSheetCellDomainObject, &destroyObject);
        
        m_pCollection->push_back(pValue);

        FieldHandler fieldHandler(pValue);

        _databaseRow.getFields(fieldHandler);
    }

    virtual void end()
    {
    }

    CollectionRowHandler(SpreadSheetCellDataMap::pSpreadSheetCellDataCollection_type _pCollection)
    : m_pCollection(_pCollection)
    {
    }

    virtual ~CollectionRowHandler()
    {
    }
    
private:
    SpreadSheetCellDataMap::pSpreadSheetCellDataCollection_type     m_pCollection;
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
                 SpreadSheetCellDataMap::pFutureSpreadSheetCellDataCollection_type _pFutureCollection,
                 SpreadSheetCellDataMap::pSpreadSheetCellDataCollection_type _pCollection)
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
    SpreadSheetCellDataMap::pFutureSpreadSheetCellDataCollection_type     m_pFutureCollection;
    SpreadSheetCellDataMap::pSpreadSheetCellDataCollection_type     m_pCollection;
};

} // namespace
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
static void
destroyObject(Zen::Memory::managed_weak_ptr<I_SpreadSheetCellDomainObject> _wpObject)
{
    SpreadSheetCellDomainObject* pObject = dynamic_cast<SpreadSheetCellDomainObject*>(_wpObject.get());
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
destroyCollection(Zen::Memory::managed_weak_ptr<I_SpreadSheetCellDataCollection> _wpCollection)
{
    SpreadSheetCellDataCollection* pCollection = dynamic_cast<SpreadSheetCellDataCollection*>(_wpCollection.get());
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
SpreadSheetCellDataMap::pSpreadSheetCellDomainObject_type 
SpreadSheetCellDataMap::createNew()
{
    return pSpreadSheetCellDomainObject_type(new SpreadSheetCellDomainObject, &destroyObject);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
SpreadSheetCellDataMap::pFutureSpreadSheetCellDomainObject_type
SpreadSheetCellDataMap::getByKey(boost::uint64_t _primaryKeyValue)
{
    // Start a transaction
    Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type 
        pTransaction = getDatabaseConnection()->beginTransaction();

    // Create a query
    Zen::Database::I_DatabaseTransaction::pStaticQuery_type 
        pQuery = pTransaction->createStaticQuery();

	const boost::uint64_t primaryKeyValue(_primaryKeyValue);

    // Get a record from the SpreadSheetCell.
    std::stringstream query;
    query << "SELECT * FROM SpreadSheetCell WHERE spreadSheetCellId = " << primaryKeyValue;

    pQuery->setQuery(query.str());
    
	pFutureSpreadSheetCellDomainObject_type pReturnValue(new FutureSpreadSheetCellDomainObject_type);
    pSpreadSheetCellDomainObject_type pValue(new SpreadSheetCellDomainObject, &destroyObject);

    // Create a result handler to handle the execution results
    Zen::Database::I_DatabaseTransaction::pQueryResultHandler_type pResultHandler(new ResultHandler(pTransaction, pReturnValue, pValue));

    // Execute the query.  
    pTransaction->executeQuery(pQuery, pResultHandler);
    
    return pReturnValue;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
SpreadSheetCellDataMap::deleteByKey(boost::uint64_t _primaryKeyValue)
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

    // Delete a record in the SpreadSheetCell.
    std::stringstream query;
    query << "DELETE FROM SpreadSheetCell WHERE spreadSheetCellId = " << primaryKeyValue;

    pQuery->setQuery(query.str());

    // Execute the query.  
    pTransaction->executeQuery(pQuery);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Zen::Database::I_DatabaseTransaction::pFutureKey_type
SpreadSheetCellDataMap::update(pSpreadSheetCellDomainObject_type _pSpreadSheetCellDomainObject)
{
    // Start a transaction
    Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type 
        pTransaction = getDatabaseConnection()->beginTransaction();

    // Create a query
    Zen::Database::I_DatabaseTransaction::pStaticQuery_type 
        pQuery = pTransaction->createStaticQuery();

    std::stringstream query;

    if (_pSpreadSheetCellDomainObject->getSpreadSheetCellId().isNull())
    {
        // Construct the query to insert a record into the SpreadSheetCell table.

        query << "INSERT into SpreadSheetCell ( "
            << getNonPKFieldNames() << " ) VALUES ( ";

        // Append all of the values
        std::string escapedStringValue;
        
        escapedStringValue = escapeString(_pSpreadSheetCellDomainObject->getSpreadSheetDocumentId().getStringValue());
        query << "\'" << escapedStringValue << "\'";
        escapedStringValue = escapeString(_pSpreadSheetCellDomainObject->getSpreadSheetRowId().getStringValue());
        query << ", \'" << escapedStringValue << "\'";
        escapedStringValue = escapeString(_pSpreadSheetCellDomainObject->getSpreadSheetColumnId().getStringValue());
        query << ", \'" << escapedStringValue << "\'";
        escapedStringValue = escapeString(_pSpreadSheetCellDomainObject->getValueType().getStringValue());
        query << ", \'" << escapedStringValue << "\'";
        escapedStringValue = escapeString(_pSpreadSheetCellDomainObject->getValue().getStringValue());
        query << ", \'" << escapedStringValue << "\'";

        // Final closing parenthesis
        query << ")";

        pQuery->setQuery(query.str());

        // Execute the query.
        Zen::Database::I_DatabaseTransaction::pFutureKey_type 
            pKey(pTransaction->executeInsert(pQuery));

        _pSpreadSheetCellDomainObject->getSpreadSheetCellId() = pKey->getValue();
        
        // Done, so commit the transaction.
        pTransaction->commit();

        return pKey;
    }
    else
    {
        // Construct the query to update a record into the SpreadSheetCell table.

        // Count the number of dirty fields.
        int dirtyFields = 0;

        query << "UPDATE SpreadSheetCell SET ";

        std::string separator("");

        // Append all of the field names and values
        std::string escapedStringValue;

        if (_pSpreadSheetCellDomainObject->getSpreadSheetDocumentId().isDirty())
        {
            escapedStringValue = escapeString(_pSpreadSheetCellDomainObject->getSpreadSheetDocumentId().getStringValue());
            query << separator << "spreadSheetDocumentId = \'" 
                << escapedStringValue << "\'";
            separator = ", ";
            dirtyFields++;
        }
        if (_pSpreadSheetCellDomainObject->getSpreadSheetRowId().isDirty())
        {
            escapedStringValue = escapeString(_pSpreadSheetCellDomainObject->getSpreadSheetRowId().getStringValue());
            query << separator << "spreadSheetRowId = \'" 
                << escapedStringValue << "\'";
            separator = ", ";
            dirtyFields++;
        }
        if (_pSpreadSheetCellDomainObject->getSpreadSheetColumnId().isDirty())
        {
            escapedStringValue = escapeString(_pSpreadSheetCellDomainObject->getSpreadSheetColumnId().getStringValue());
            query << separator << "spreadSheetColumnId = \'" 
                << escapedStringValue << "\'";
            separator = ", ";
            dirtyFields++;
        }
        if (_pSpreadSheetCellDomainObject->getValueType().isDirty())
        {
            escapedStringValue = escapeString(_pSpreadSheetCellDomainObject->getValueType().getStringValue());
            query << separator << "valueType = \'" 
                << escapedStringValue << "\'";
            separator = ", ";
            dirtyFields++;
        }
        if (_pSpreadSheetCellDomainObject->getValue().isDirty())
        {
            escapedStringValue = escapeString(_pSpreadSheetCellDomainObject->getValue().getStringValue());
            query << separator << "value = \'" 
                << escapedStringValue << "\'";
            separator = ", ";
            dirtyFields++;
        }

        // No need to proceed if none of the fields were dirty.
        if (dirtyFields > 0)
        {
            // WHERE clause to update the record
            query << " WHERE spreadSheetCellId = " << 
                _pSpreadSheetCellDomainObject->getSpreadSheetCellId().getInt64Value();

            pQuery->setQuery(query.str());

            // Execute the query.  
            pTransaction->executeQuery(pQuery);

            // Done, so commit the transaction.
            pTransaction->commit();
        }
        
        Zen::Database::I_DatabaseTransaction::pFutureKey_type 
            pKey(new Zen::Database::I_DatabaseTransaction::FutureKey_type);

        pKey->setValue(_pSpreadSheetCellDomainObject->getSpreadSheetCellId().getInt64Value());

        return pKey;
    }

}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
SpreadSheetCellDataMap::pFutureSpreadSheetCellDataCollection_type
SpreadSheetCellDataMap::getByDocumentId(const boost::uint64_t _spreadSheetDocumentId)
{
    pFutureSpreadSheetCellDataCollection_type pFutureCollection(new FutureSpreadSheetCellDataCollection_type);
    pSpreadSheetCellDataCollection_type pCollection(new SpreadSheetCellDataCollection, &destroyCollection);

    // Start a transaction
    Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type 
        pTransaction = getDatabaseConnection()->beginTransaction();

    // Create a query
    Zen::Database::I_DatabaseTransaction::pStaticQuery_type 
        pQuery = pTransaction->createStaticQuery();

    // Get SpreadSheet cells by spreadSheetDocumentId.
    std::stringstream query;
    query << "SELECT * FROM SpreadSheetCell WHERE " << "spreadSheetDocumentId == " << _spreadSheetDocumentId ;

    pQuery->setQuery(query.str());
    
    // Create a result handler to handle the execution results
    Zen::Database::I_DatabaseTransaction::pQueryResultHandler_type pResultHandler(new CollectionResultHandler(pTransaction, pFutureCollection, pCollection));

    // Execute the query.  
    pTransaction->executeQuery(pQuery, pResultHandler);    
    
    return pFutureCollection;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
SpreadSheetCellDataMap::pFutureSpreadSheetCellDataCollection_type
SpreadSheetCellDataMap::getAll()
{
    pFutureSpreadSheetCellDataCollection_type pFutureCollection(new FutureSpreadSheetCellDataCollection_type);
    pSpreadSheetCellDataCollection_type pCollection(new SpreadSheetCellDataCollection, &destroyCollection);

    // Start a transaction
    Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type 
        pTransaction = getDatabaseConnection()->beginTransaction();

    // Create a query
    Zen::Database::I_DatabaseTransaction::pStaticQuery_type 
        pQuery = pTransaction->createStaticQuery();

    // Get all of the records from the SpreadSheetCell.
    pQuery->setQuery("SELECT * FROM SpreadSheetCell");

    // Create a result handler to handle the execution results
    Zen::Database::I_DatabaseTransaction::pQueryResultHandler_type pResultHandler(new CollectionResultHandler(pTransaction, pFutureCollection, pCollection));

    // Execute the query.  
    pTransaction->executeQuery(pQuery, pResultHandler);    
    
    return pFutureCollection;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
        
std::string
SpreadSheetCellDataMap::escapeString(const std::string& _value) const
{
	return getDatabaseConnection()->escapeString(_value);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
static std::string sm_fieldNames = "spreadSheetCellId, spreadSheetDocumentId, spreadSheetRowId, spreadSheetColumnId, valueType, value";
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
static std::string sm_nonPKFieldNames = "spreadSheetDocumentId, spreadSheetRowId, spreadSheetColumnId, valueType, value";
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
const std::string&
SpreadSheetCellDataMap::getFieldNames()
{
    return sm_fieldNames;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
const std::string&
SpreadSheetCellDataMap::getNonPKFieldNames()
{
    return sm_nonPKFieldNames;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
static std::string sm_tableName = "SpreadSheetCell";
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
const std::string&
SpreadSheetCellDataMap::getTableName()
{
    return sm_tableName;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
SpreadSheetCellDataMap::pDatabaseConnection_type
SpreadSheetCellDataMap::getDatabaseConnection() const
{
	return m_pDatabaseConnection;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Studio
}   // namespace Workbench
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
