#include <object.h>
#include <sql.h>

/** Connect to the MySQL database when the object is loaded.
 */
void create() {
   if(!sql_connect("forums"))
      debug("The saveload database is malfunctioning...","sql");
   ::create();
}

string restore_object(int oid) {
   string sql = "select data from saveload where oid="+oid;
   mixed res = request(sql);
   if( !res || !sizeof(res) ) {
      debug("restoring "+oid+" failed","sql");
      return "";
   }
   if( pointerp(res[0]) )
      return res[0][0];
   return res[0];
}

int save_object(int oid, string data) {
   string sql = "select oid from saveload where oid="+oid;
   mixed res = request(sql);
   if( !res ) {
      debug("saving "+oid+" failed - unable to select","sql");
      return 0;
   }
   if( !data ) {
      debug("attempt to save null data to "+oid,"sql");
      return 0;
   }
   data = safe_string( data );
   if( sizeof(res) )
      sql = "update saveload set data='"+data+"' where oid="+oid;
   else
      sql = "insert into saveload values("+oid+",'"+data+"')";
   res = request(sql);
   if( !res ) {
      debug("saving "+oid+" failed - unable to update","sql");
      debug("sql = "+sql,"sql");
      return 0;
   }
   return 1;
}
