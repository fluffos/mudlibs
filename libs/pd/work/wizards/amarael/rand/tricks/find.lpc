#include <daemons.h>

void trick(string str) {
     object env, ob;
     string borg;
     mixed tmp;
     if(!ob = find_living(str))
       return notify_fail("Could not find "+capitalize(str)+".\n");
     if(!env = environment(ob))
       return notify_fail(capitalize(str)+" has no environment!\n");

     message("info", "%^GREEN%^*******************************************************************************%^RESET%^\n", this_player(), );
     env = environment(ob);
     borg = file_name(env)+"\n";
     borg += (string)MAPPER_D->mapper(ob);
     message("no_wrap", borg, this_player());
     if(stringp(tmp=(mixed)env->query_smell("default")))
         message("smell", tmp, this_player());
     else if(functionp(tmp))
         message("smell",(string)((*tmp)("default")), this_player());
     if(stringp(tmp=(mixed)env->query_listen("default")))
         message("listen", tmp, this_player());
     else if(functionp(tmp))
         message("listen", (string)((*tmp)("default")), this_player());
     if((tmp=(string)env->query_long_exits()) && tmp != "")
         message("info", sprintf("\n%s\n", tmp), this_player());
     if((tmp=(string)env->describe_living_contents(({this_player()})))!="")
         message("living_item", tmp, this_player());
     if((tmp=(string)env->describe_item_contents(({})))!="")
         message("inanimate_item", tmp, this_player());
         message("info", "\n%^GREEN%^*******************************************************************************%^RESET%^", this_player(), );
     return 1;
}
