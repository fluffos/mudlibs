//  Loadup Command
//    Command idea from Diku/Smaug style loadup
//  Will load a character into an unused user object.

#define SYNTAX "Syntax: <loadup [player]>\n"

int cmd_loadup(string who) {
   int i;
   object *u, ob;
   if(!who || who=="") return notify_fail(SYNTAX);
   if(find_player(who)) return notify_fail(who+" is online FP=1.\n");
   u=children("/std/user");
   for(i=0; i < sizeof(u); i++) {
     if(u[i]->query_name() == who) return notify_fail(who+" is online FP=0.\n");
   }
   ob=new("/std/user");
   seteuid("Root");
   if(geteuid() != "Root") return notify_fail("Unable to get root access to perform action.\n");
   ob->set_name(who);
   master()->load_player_from_file(who, ob);
   ob->set_invis();
   ob->setup();
   ob->net_dead();
   write(ob->query_name()+" has been loaded into "+identify(ob));
   return 1;
}

void help() {
   write(SYNTAX+"\n\n  This will loadup a player into a player object.");
}
