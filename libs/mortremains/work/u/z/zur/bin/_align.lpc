int cmd_align(string str){
  object ob;
  int x;
  if(!str) return 1;
  ob = present(str, environment(this_player()));
  if(!ob){ write("Uhhh\n"); return 1; }
  x = keys(ob->query_true_alignment())[0];
  printf("%s is %s [%d / %d ]",
      ob->query("cap_name"), ob->query_alignment(),
     x,ob->query_true_alignment()[x]);
  return 1;
  }
