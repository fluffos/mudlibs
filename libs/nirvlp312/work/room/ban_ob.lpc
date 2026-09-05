int x;
init() {
   add_action("ban","ban");
}
ban(str){
if (this_player()->query_level() < 90000)
  return 0;
save_object("banish/"+str);
write(str + " has been banished.\n");
return 1;
}
