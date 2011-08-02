#ifndef __GTKQQ_DAO_H
#define __GTKQQ_DAO_H
#include <glib.h>
#include <sqlite3.h>
#include <qq.h>

//
// The DAO
// Manage the connection to the database.
//

//
// Open a connection to the databases.
//
// If databases not exist, create it.
// The tables will also be created too.
//
sqlite3* db_open();

//
// Close the connection to the databases.
//
void db_close(sqlite3 *db);

//
// Delete all the data in all tables.
// NOT delete the tables.
//
gint db_clear_db(sqlite3 *db);
//
// Delete all the data in table where key = value
//
gint db_clear_table(sqlite3 *db, const gchar *table
                            , const gchar *key, const gchar *value);

//
// Store qq user into db
//
gint db_qquser_save(sqlite3 *db, const gchar *qqnum, const gchar *passwd
                                , const gchar *status, gint last);

//
// Store key:value into db
// Use g_free to free the value after using it.
//
gint db_config_save(sqlite3 *db, const gchar *owner
                            , const gchar *key, const gchar *value);
//
// Store buddy, group, category into db
//
gint db_buddy_save(sqlite3 *db, const gchar *owner, QQBuddy *bdy);
gint db_group_save(sqlite3 *db, const gchar *owner, QQGroup *grp);
gint db_category_save(sqlite3 *db, const gchar *owner, QQCategory *cate);

//
// Get key:value
//
gint db_config_get(sqlite3 *db, const gchar *owner
                            , const gchar *key, gchar **value);
//
// Get all the buddies, groups and categories.
// The result is stored in a array and returned from the third parmeter.
// The array must be free.
//
gint db_buddy_get(sqlite3 *db, const gchar *owner, GPtrArray **buddies);
gint db_group_get(sqlite3 *db, const gchar *owner, GPtrArray **groups);
gint db_category_get(sqlite3 *db, const gchar *owner, GPtrArray **cates);

#endif
