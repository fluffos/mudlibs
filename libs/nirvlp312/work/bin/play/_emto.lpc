/*
Originally written by Snow for his discreet emoter.
Modified by Feldegast for use in /bin
4-14-00
*/

int cmd_emto(string str) {
  object ob;
  string who;
  string msg;
  if (!str || sscanf(str, "%s %s", who, msg) != 2) {
    write("Usage: emto <who> <what>\n");
    return 1;
  }
  ob = present(who,environment(this_player()));
  if(!ob) {
    write("That player is not in the room.\n");
    return 1;
  }
  if((int)ob->query_invis() > 19) {
    write("That player is not in the room.\n");
    return 1;
  }
  if(in_editor(ob)) {
    write(capitalize(who)+" is in editing right now, try again later.\n");
    return 1;
  }
  if((int)ob->query_tellblock()) {
    write(capitalize(who)+" is blocking tells right now.\n");
    return 1; 
  }
  tell_object(ob,"(Discreet) "+(string)this_player()->query_name()+" "+msg+ "\n");
  write ("You secretly emote: '"+(string)this_player()->query_name()+" "+msg+"' to "+capitalize(who)+".\n");
  return 1;
}
