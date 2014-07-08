#include "stdafx.h"
#include "DatabaseSingleton.h"

DatabaseSingleton* DatabaseSingleton::databaseSingleton=NULL;

DatabaseSingleton::DatabaseSingleton()
{
	connection = NULL;
	try{
		driver = get_driver_instance();
		connection = driver -> connect(URL, USER, PASSWORD);
		connection -> setAutoCommit(0);
		connection -> setSchema(DATABASE);
			} catch (SQLException &e) {
		cout<<"PROBLEM: "<<e.what()<<endl;
	}
}


DatabaseSingleton::~DatabaseSingleton()
{
	delete connection;
}


DatabaseSingleton* DatabaseSingleton::getInstance()
{
	if(databaseSingleton==NULL)
		databaseSingleton = new DatabaseSingleton();
	return databaseSingleton;
}

Connection* DatabaseSingleton::getConnection()
{
	if (connection == NULL || connection->isClosed())
	{

		if(connection!=NULL)
			delete connection;

		try
		{
		connection = driver -> connect(URL, USER, PASSWORD);
		connection -> setAutoCommit(0);
		connection -> setSchema(DATABASE);
			} catch (SQLException &e) {
		cout<<"PROBLEM: "<<e.what()<<endl;
		return NULL;
	}
	}
	return connection;
}