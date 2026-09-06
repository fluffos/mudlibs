#include <object.h>
#include <sql.h>

// Constant(s)
#define ANONYMOUS_UID 1

#define MAIL_CLIENT	"/obj/mailclient"

/** Connect to the MySQL database when the object is loaded.
 */
void create() {
   if(!sql_connect("forums"))
      debug("The forums/mail interface doesn't work -- this would be a bad thing.");
   ::create();
}

////// Querries ///////

mixed query_messages(int uid) {
   string sql = "select * from message where uid="+uid;
   mixed res = request(sql);
   if (!res) {
     debug("query_messages("+uid+") failed: "+sql,"mail");
     return -1;
   } else
     return res;
}

mixed query_lists() {
   string sql = "select * from list";
   mixed res = request(sql);
   if (!res) {
     debug("query_lists() failed: "+sql,"mail");
     return -1;
   } else
     return res;
}

int *query_list_members(int lid) {
   string sql = "select uid from subscription where lid="+lid;
   mixed res = request(sql);
   if (!res) {
     debug("query_list_members("+lid+") failed: "+sql,"mail");
     return ({ -1 });
   } else
     return res[0];
}

int *query_subscriptions(int uid) {
   string sql = "select lid from subscription where uid="+uid;
   mixed res = request(sql);
   if (!res) {
     debug("query_subscriptions("+uid+") failed: "+sql,"mail");
     return ({ -1 });
   } else
     return res[0];
}

string query_username(int uid) {
   string sql = "select name from user where uid="+uid;
   mixed res = request(sql);
   if (!res) {
     debug("query_username("+uid+") failed: "+sql,"mail");
     return "-1";
   } else
     return res[0][0];
}

string query_listname(int lid) {
   string sql = "select name from list where lid="+lid;
   mixed res = request(sql);
   if (!res) {
     debug("query_listname("+lid+") failed: "+sql,"mail");
     return "-1";
   } else
     return res[0][0];
}

int query_uid(string name) {
   string sql = "select uid from user where name='"+name+"'";
   mixed res = request(sql);
   if (!res) {
     debug("query_name("+name+") failed: "+sql,"mail");
     return -1;
   } else
     return res[0][0];
}

int query_lid(string name) {
   string sql = "select lid from list where name='"+name+"'";
   mixed res = request(sql);
   if (!res) {
     debug("query_lid("+name+") failed: "+sql,"mail");
     return -1;
   } else
     return res[0][0];
}

int query_valid_address(string str) {
   return (query_uid(str) || query_lid(str) ? 1 : 0);
}

////// Changing the database //////

void send_message(string from, string to, string subject, string text) {
   string sql;
   mixed res;
   int sid, uid;

   // first query, find uid of sender
   sid = query_uid(from);
   if (!sid) {
     debug("invalid sender in send_message: "+from,"mail");
     return;
   }

   // second query, find uid of recipient
   uid = query_uid(to);
   if (!uid) {
     msg("~CWRNUnable to send mail to ~CBRT"+to+"~CWRN, no such user.~CDEF");
     return;
   }

   // third query, actually send the message
   sql = "insert into message values(null,"+uid+",'inbox','new',"+sid+",now(),"+
         "'"+safe_string(subject)+"','"+safe_string(text)+"')";
   res = request(sql);
   if (!res)
     debug("send_message() failed: "+sql,"mail");
   else {
     object ob = find_player(to);
     msg("~CBRTMessage sucessfully sent from ~CCOM"+from+"~CBRT to ~CCOM"+to+"~CBRT.~CDEF");
     if (ob) {
        msg_object(ob, "~CBRTYou have new mail from ~CCOM"+from+"~CBRT about ~CCOM"+subject+"~CBRT.~CDEF");
        ob = present_clone(MAIL_CLIENT, ob);
        if (ob)
           ob->reload();
     }
   }
}
