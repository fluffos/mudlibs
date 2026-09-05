init() { 
add_action("eshout","eshout");
add_action("Eshout","Eshout");
add_action("etell","etell");
}

etell(str) {
  string tmp;
  string who;
  if(sscanf(str, "%s %s", who, tmp) != 2) return 0;
  tell_object(find_player(who),  tmp +"\n");
write("Ok.\n");
  return 1;
}

eshout(str) {
  object ob;
  int v;
  ob=users();
  for(v=0; v<sizeof(ob); v++) {
    if(ob[v]->query_level() < 21) tell_object(ob[v], str +"\n");
  }
  write(str + "\n");
  return 1;
}
Eshout(str) {
  object ob;

  int v;   
  ob=users();

   for(v=0; v<sizeof(ob); v++) {
    if(ob[v]->query_level() < 1001 && !in_editor(ob[v])) tell_object(ob[v], str +"\n");
}
  write(str + "\n");  
  return 1;
}
