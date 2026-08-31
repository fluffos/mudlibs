/* Changed Moonchild 010793 to make it take time to take effect */

#if 0
noattack() {
  object *ob,env;
  int i;
 
  write("You concentrate your Force.\n");
  say(TPN+" utters some strange words.\n");
 
  ob = all_inventory(env=environment(TP));
  for (i=0; i<sizeof(ob); i++)
    if (living(ob[i]) && ob[i]->query_attack()) 
      if(ob[i]->query_chr()<TP->query_chr()+NA_RANGE*TPL) {   
        ob[i]->stop_fight();
        ob[i]->stop_fight();
        ob[i]->stop_hunter(1);
      } 
      else
        write("You cannot affect "+ob[i]->query_name()+".\n");
  write("You're no longer attacked.\n");
}
#endif

noattack() {
  write("You concentrate your Force.\n");
  say(TPN+" utters some strange words.\n");
  call_out("perform_noattack", 1, environment(TP));
}

perform_noattack(oe) {
  object env, *ob;
  int i;
  env=environment(TP);
  if(env!=oe)
    return;
  ob = all_inventory(env=environment(TP));
  for (i=0; i<sizeof(ob); i++)
    if (living(ob[i]) && ob[i]->query_attack())
      if(ob[i]->query_chr()<TP->query_chr()+NA_RANGE*TPL) {
        ob[i]->stop_fight();
        ob[i]->stop_fight();
        ob[i]->stop_hunter(1);
      }
      else
        write("You cannot affect "+ob[i]->query_name()+".\n");
  write("You're no longer attacked.\n");
}
