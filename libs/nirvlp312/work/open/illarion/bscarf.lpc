/* send a wiz a tell object */
inherit "obj/treasure";
#include "/players/illarion/dfns.h"

reset(arg) {
  if(arg) return;

  set_id("scarf");
  set_alias("itell");
  set_short("A dark black scarf");
  set_long("A black, but fuzzy scarf.  It can be used to speak with\n"+
           "Illarion even if he is invisible or bsy, or simply\n"+
           "to check if he is on, with the command: "+BLD("itell(e)")+".\n");
  set_value(0);
  set_weight(0);
}
drop() {
  write("That is not allowed.\n");
  return 1;
}
init() {
  ::init();
  add_action("cmd_itell","itell");
  add_action("cmd_itell","itelle");
}
cmd_itell(string str) {
  string out;
  object ob;
  ob=find_player("illarion");
  if(!str || !ob) {
    write("Illarion is "+(ob?"here.\n":"not here.....\n"));
    return 1;
  }
  else {
    if(query_verb() == "itell") {
      write(format("You itell Illarion: "+str+"\n"));
      out=format("(itell) "+TPN+": "+str);
      out=HIW+"(itell)"+NORM+extract(out,7);
      tell_object(ob,out);
      ob->add_tellhistory(out);
    } else {
      write(format("(itell) "+TPN+" "+str+"\n"));
      out=format("(itell) "+TPN+" "+str);
      out=HIW+"(itell)"+NORM+extract(out,7);
      tell_object(ob,out);
      ob->add_tellhistory(out);
    }
  return 1;
  }
}
