#ifndef _SQL_H
#define _SQL_H

#define SQL_ID_COLUMN           "id"
#define DEFAULT_DATABASE        "sqlite:" _EtcDir "/public.db"

#define SqlDir                  PlatformObjDir "/sql"
#define SQLiteClient            SqlDir "/sqlite_client"
#define MysqlClient             SqlDir "/mysql_client"
#define PostgresClient          SqlDir "/postgres_client"

#define SQL_COL_NAME            "name"
#define SQL_COL_TYPE            "type"
#define SQL_COL_FLAGS           "flags"
#define SQL_COL_DEFAULT         "default"

#define SQL_TYPE_INTEGER        "INTEGER"
#define SQL_TYPE_REAL           "REAL"
#define SQL_TYPE_TEXT           "TEXT"
#define SQL_TYPE_BLOB           "BLOB"
#define SQL_TYPE_NULL           "NULL"

#define SQL_FLAG_PRIMARY_KEY    0x01
#define SQL_FLAG_AUTOINCREMENT  0x02
#define SQL_FLAG_UNIQUE         0x04
#define SQL_FLAG_NOT_NULL       0x08

#endif  // _SQL_H
