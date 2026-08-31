//  Mailing List Generator
//  Whit
/*
 * This list will regenerate every hour, starting 5 seconds 
 * after the mud comes back online.  This will keep the mailing
 * list fresh.
 */
#include <daemons.h>
#include <system.h>

mapping list;

void create() {
   call_out("create_list", 5);
   list=([]);
}

void create_list() {
   mapping data=AUTH_D->get_data();
   string *k = keys(data), tmp;
   int i=sizeof(k), x;
   mixed er;
   if(!mysql_connect()) {
     CHAT_D->do_raw_chat("system", "Mail List <system> Could not connect to database.");
     call_out("create_list", 3600);
     return;
   }
   mysql_query("DELETE FROM Mail_List");
   while(i--) {
     if(!user_exists(k[i])) {
       map_delete(list, k[i]);
       CHAT_D->do_raw_chat("system", "Mail List <system> Cleaning out "+k[i]+". (No such user)");
       if(!AUTH_D->remove_user(k[i])) CHAT_D->do_raw_chat("system", "Mail List <system> Could not clean "+k[i]);
       continue;
     }
     if(sscanf(data[k[i]]["Email"], "%s@%s.%s", tmp, tmp, tmp) != 3) {
        CHAT_D->do_raw_chat("system", "Mail List <system> Invalid email address specified for "+k[i]);
        continue;
     }
     list[k[i]]=data[k[i]]["Email"];
     x=mysql_query("INSERT INTO Mail_List Values(\""+k[i]+"\", \""+data[k[i]]["Email"]+"\")");
     if(x<0) CHAT_D->do_raw_chat("system", "Mail List <system> System returned "+x+" on mysql_query()");
   }
   mysql_disconnect();
   if(DEBUG) CHAT_D->do_raw_chat("system", "Mail List <system> Mail List Generated.");
   call_out("create_list", 3600);
}
