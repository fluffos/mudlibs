#define TP this_player()
 cmd_kill(string str) {
  object obj;
  
  if(this_player()->query_ghost()) {
    write("You're dead!\n");
  }
  
  else if(!str) {
    write("You must specify a target.\n\"kill <name>\"\n");
  }
  else if(!(obj = present(str, environment(this_player())))) {
    write("You don't see \""+str+"\" here.\n");
  }
  
  else if(!living(obj)) {
    write((string)obj->short()+" is not alive.\n");
  }
  
  else if(obj == TP->query_attack()) {
    write("Yes, yes.\n");
  }
  else if(!TP->valid_attack(obj)) {
    return 1;
  }
  else
    this_player()->attack_object(obj);
  
  return 1;
}
