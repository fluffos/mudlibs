#include <move_failures.h>

#define MAX_DROP_NUMBER 20

inherit COMMAND_BASE;

mixed cmd(object *obs, string str) {
   int num, max;
   object bing;
   string env_sh;
   object ob;
   object *fail;
   object *too_many;
   mapping ret;
   object env;
   string drop_mess;
   //string sh;
   
   ret = ([ ]);
   fail = ({ });
   too_many = ({ });
   if (sizeof(obs) > MAX_DROP_NUMBER) {
      too_many = obs[MAX_DROP_NUMBER..];
      obs = obs[0..MAX_DROP_NUMBER-1];
   }
   foreach(ob in obs) {
      if (!ob->short()) {
         continue;
      }
      env = environment(ob);
      if (function_exists("do_drop", ob) ||
            function_exists("command_control", ob)) {
         if (function_exists("do_drop", ob)) {
            max = (int)call_other(ob, "do_drop", ({ }), str, 0, ({ str }),
                                             "<direct:object:me>");
         } else {
            max = ob->command_control("drop", ({ }), str, 0, ({ str }),
                                                   "<direct:object:me>");
         }
         if (max == 0)  {
            fail += ({ ob });
            continue;
         }
      }
      if (ob->move(environment(TP)) == MOVE_OK) {
         if (ret[env]) {
            ret[env] += ({ ob });
         } else {
            ret[env] = ({ ob });
         }
         if(interactive(TP))
           ob->add_property("dropped", ({TP->query_name(), query_ip_number(TP),
                                           time()}), 1800);
      } else {
         fail += ({ ob });
      }
   }
   if (sizeof(ret)) {
      foreach (env, bing in ret) {
         //sh = query_multiple_short(bing);
         if (env != this_player()) {
            env_sh = " from inside " + inside_the_short(env);
         } else {
            env_sh = "";
         }
         
         /* If you want to define your own message for when you
          * drop an item... return the string here.
          */
         if ( drop_mess = this_player()->query_drop_mess() ) {
            add_succeeded_mess( drop_mess, bing );
         }
         else {
            add_succeeded_mess("$N $V $I" + env_sh + ".\n", bing);
         }
      }
      if (sizeof(too_many)) {
         add_succeeded_mess(({ "You can only drop " +
                         query_num(MAX_DROP_NUMBER) + " objects at one time; "
                         "discarding.\n", "" }));
      }
   } else {
      if (sizeof(fail)) {
         add_failed_mess("You cannot drop $I.\n", fail);
         return 0;
      }
      if (sizeof(too_many)) {
         add_failed_mess("You can only drop " +
                         query_num(MAX_DROP_NUMBER) + " objects at one time; "
                         "discarding $I.\n", too_many);
         return 0;
      }
   }


   num = sizeof(fail)+sizeof(ret);

   if (!num) {
//      return notify_fail("Cannot drop "+str+".\n");
        return 0;
   }

   return 1;
}

mixed *query_patterns() {
   return ({ "<indirect:object:me>", (: cmd($1, $3) :) });
}
