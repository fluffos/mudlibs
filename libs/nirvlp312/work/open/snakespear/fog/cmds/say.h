do_say(str) {
  object ob;
  if(!fraternizing) return 0;
  write("You speak to your brothers, \""+str+"\"\n");
  ob=first_inventory(environment(TP));
  while(ob) {
    if(ob!=TP)
    if(present(GUILD_ID,ob))
      tell_object(ob,TPN+" says to his brothers, \""+str+"\"\n");
    else
      tell_object(ob,TPN+" says something to his brothers.\n");
    ob=next_inventory(ob);
  }
  return 1;
}
