/*      Wocket did this!     */
inherit "/room/room";


string listens;
string smells;
int pk;
int pk_spar;
int remove_spar;

init() {
    int i;
    add_action("listen","listen");
    add_action("smell","smell");
    add_action("search","search");
    if (!dest_dir)
	return;
    i = 1;
    while(i < sizeof(dest_dir)) {
	add_action("move", dest_dir[i]);
	i += 2;
    }
    if(pk == 1){
      if(this_player()->is_player())
      this_player()->set_fight_area();
    }
}

exit(){
  if(this_player()){
    if(this_player()->is_player()) this_player()->clear_fight_area();
    if(pk_spar && remove_spar)
      this_player()->rm_spar();
  }
}

listen(str){
int i;
    if(!listens){
      notify_fail("You don't hear anything.\n");
   return 0;
}
  if(!str){
    str = "default"; }
    while(i < sizeof(listens)){
    if(listens[i] == str){
    write(listens[i+1] + ".\n");
    return 1;
}
    i+= 2;
}
write("You can't hear that.\n");
return 1;
}

smell(str){
int i;
    if(!smells){
      notify_fail("You dont smell anything.\n");
    return 0;
}
    if(!str){
    str = "default"; }
    while(i < sizeof(smells)){
    if(smells[i] == str){
    write(smells[i+1]+".\n");
    return 1;
}
    i+= 2;
}
write("You can't smell that.\n");
return 1;
}

search(){
  notify_fail("You find nothing of intrest.\n");
  return 0;
}

query_spar_area(){ return pk_spar; }
