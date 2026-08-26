// Petrarch
// Merentha Lib 1.0
// <rid>

int command(string str) {
object ob;
  if(!str) return notify_fail("Syntax: rid <person>\n");
  str=player_name(str);
  if(!player_exists(str)) return notify_fail("That person does not exist.\n");
  rename("/save/users/"+str[0..0]+"/"+str+".o","/save/rid/rid_"+str+".o");
  if(ob=find_player(str)) ob->remove();
  message("command", "Player "+str+" removed.", this_player());
  return 1;
}

string help() {
return "Syntax: rid <person>\n\nThis command removes someone from the game.  As you grow your lib you should continue to update this command.  By default it only moves the person's character file to /save/rid/ but you may also want it to empty bank accounts, remove pets, things like that.";
}
