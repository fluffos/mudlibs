#define REP "/obj/user/reports/reporter"

int cmd_typo(string str) {
  object obj;
  string typ;
  
  typ = "typo";
  
  if(str && find_player(str)) {
    return 0;
  }
  
  if(!str || str == "help") {
    write("        To report "+a_or_an(typ)+" "+typ+" in a room:\n");
    write("\t\t");
    write("'"+typ+" <your "+typ+">'\n");
    write("                 -or-\n");
    write("   To report "+a_or_an(typ)+" "+typ+" in a specific item:\n"); 
    write("\t\t");
    write("'"+typ+" [item] <your "+typ+">'\n");
    write("  NOTE: YOU MUST USE THE []'S IF YOU ARE REPORTING A "+
          upper_case(typ)+"\n"+
          "        FOR A SPECIFIC ITEM. THE ITEM MUST ALSO BE IN\n"+
          "        YOUR INVENTORY.  thank you :)\n");
    return 1;
  } 
  
  if(str[0] == '[' && text_contains(str,"]")) {
    int x, y, l;
    y = strlen(str);
    for(x = 0; x < y && !l; x ++) {
      if(str[x] == ']') {
        l = x;
      }
    }
    if(l) {
      if(!(obj = present(str[1..l-1], this_player()))) {
        write("You don't have \""+str[1..l-1]+"\".\n");
        return 1;
      }
        str = str[l+2..strlen(str)-1];
    }
  }
  
  if(strlen(str) < 2) {
    write("...uh, you forgot to type your \""+typ+"\" there buddy.\n");
    return 1;
  }
  if(!obj) {
    obj = environment(this_player());
  }
  
  write("Okay, recording "+typ+" for "+(string)obj->short()+".\n");
  
  call_other(REP, "add_"+typ, basename(obj), (string)this_player()->query_real_name(), str);
  
  write("Thousands of cheering newbies chant your name!\n");
  write("Game driver tells you: "+
  "You are soooooooo cool for reporting that "+typ+"!\n");
  write("Armageddon tells you: Rock on!\n");
  return 1;
}
