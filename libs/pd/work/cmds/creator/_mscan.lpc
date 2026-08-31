#include <std.h>

inherit DAEMON;

int cmd_mscan(string obj) {
 object ob;

 if (!obj) ob = environment( this_player() );
   else if (find_living(obj)) {
       ob = find_living(obj);
       if (!ob) return notify_fail("Failed: ERROR 1\n");
  } else {
      ob = find_object(obj);
      if (!ob) return notify_fail("Failed: ERROR 2\n");
  }
 write("going to search in ob: "+ob->query_name());
 return 1;
}
