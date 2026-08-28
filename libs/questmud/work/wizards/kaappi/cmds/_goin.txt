cmd_goin(string str) {
object plr;
  if(!str) {
    write("## Usage : Goin [name]\n");
  return 1;
}

plr = find_player(str);
if(!plr) {
  write("Can't find " + str + ".\n");
return 1;
}
if(this_player() -> query_wiz_level() < plr -> query_wiz_level()) {
  write("Can't goin to higher level wizards.\n");
  return 1;
}

 move_object(this_player(), plr);
write("Moving to " + str + "'s inventory.\n");
return 1;
}
