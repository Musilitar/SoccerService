// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <ctype.h>
#include <stdio.h>
#include <tchar.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include "OKlantDAO.h"
#include "OMatchDAO.h"
#include "OVakDAO.h"
#include "OZitjeDAO.h"
#include "OTicketDAO.h"
#include "OAbbonementDAO.h"
#include "OAbbonementTypesDAO.h"
#include "OTegenstandersDAO.h"
#include "OStadionDAO.h"
#include "OBanDAO.h"
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <fstream>


using namespace std;

#include "cppconn\connection.h"
#include "cppconn\driver.h"
#include "Gegevens.h"

using namespace sql;

#include "DatabaseSingleton.h"
#include "cppconn\prepared_statement.h"
#include "cppconn\exception.h"
#include "KlantDAO.h"
#include "MatchDAO.h"
#include "TicketDAO.h"
#include "AbbonementDAO.h"
#include "AbbonementTypesDAO.h"
#include "StadionDAO.h"
#include "ZitjeDAO.h"
#include "VakDAO.h"
#include "TegenstandersDAO.h"
#include "BanDAO.h"

//win32 printer

#include <Windows.h>
#include <winspool.h>
#include <commdlg.h>
#include <math.h>
//#include "resource.h"