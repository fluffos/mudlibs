#define MARK sprintf("%c",34)
#define HOUSE_SHOP_D "/room/house_shop_d"

inherit "/room/room";

reset(arg) {
  if (arg) { return; }
  short_desc = "Town hall of Duranghom";
  long_desc = 
"This large hall is the town hall of Duranghom. There is a desc infront of\n"+
"you. There is an officer behind the desk renting houses in the city.\n"+
"Available commands are:\n\tlist\n\tbuy [number]\n\tmap\n\tinfo [number]\n\tduplicate [key]\n";
 
  add_exit("east", "/world/city/gold5");
  set_not_out(1);
  set_light(3);
}

init() {
  ::init();
  add_action("list","list");
  add_action("buy", "buy");
  add_action("map", "map");
  add_action("info", "info");
  add_action("codes", "codes");
  add_action("duplicate", "duplicate");
}

duplicate(str) {
  object ob, ob2;
  int cost;
  string file, tmp;
  cost = 1000;
  if (!str) { write("Syntax: duplicate key [number]\n"); return 1; }
  ob = present(str, this_player());
  if (!ob) {
    write("You don't have a '"+str+"'.\n"); 
    return 1;
  }
   if (!ob->query_key_code() || !sscanf(file_name(ob), "/room/houses/keys/key%s", tmp) ) {
    write(capitalize(str)+" is not a key.\n");
    return 1;
  }
  if (this_player()->query_money(3) < cost) {
    write("Sorry, but the cost for duplicating a key is "+cost+" bronze coins.\n");
    return 1;
  }
  this_player()->reduce_money(cost,3);
  write(
"You give your key to the officer and after a while he hands you\n"+
"back the original and a duplicate of it.\n");

  file = file_name(ob);
  sscanf(file, "%s#%s", file,tmp);
  ob2 = clone_object(file);
  move_object(ob2, this_player());
  return 1;
}

buy(num) {
  int costs, code;
  string file;
  if (!num || !sscanf(num, "%d", num)) {
    write("Usage: buy [number of house]\n");
    return 1;
  }
  num -= 1;
  if (num < 0 || num > 9) {
    write("No such a house available.\n");
    return;
  }
  if (call_other(HOUSE_SHOP_D, "query_sold", num)) {
    write("That house is already sold.\n");
    return 1;
  }
  costs = call_other(HOUSE_SHOP_D, "query_house_costs");
  if (this_player()->query_money(5) < costs[num]) {
     write("That house costs "+costs[num]+" gold coins "+
	"and you only have money worth "+this_player()->query_money(5)+" gold.\n");
     return 1;
  }
  this_player()->reduce_money(costs[num], 5);
  write("You pay "+costs[num]+" gold coins for the house.\n");
  write("The officer hands you the key to the house.\n");
  write("See 'map' to see where your house is located.\n");
  say(this_player()->query_name()+" buys a house.\n");

  code = HOUSE_SHOP_D->query_code(num);
  HOUSE_SHOP_D->set_sold(num, 1);

  file = write_new_key(code);

  move_object(clone_object(file), this_player());

  log_file("HOUSE_LOG", ctime(time())+" "+this_player()->query_name()+
" bought house "+num+" for "+costs[num]+"\n");
  return 1;
}

random_code(num) {
  string str;
  int i, quality;
  quality = num / 4 + 4;
  str = "";
  while(i < quality) {
    str = str + random(10);
    i += 1;
  }
  return str;
}

list() {
 int i, costs;
 costs = call_other(HOUSE_SHOP_D, "query_house_costs");
 write("List of houses available:\n");
 while (i < 10) {
   if (!call_other(HOUSE_SHOP_D, "query_sold", i)) {
     write("House "+(i+1)+" is available for "+costs[i]+" gold coins.\n");
   }
   i += 1;
 }
 return 1;
}

codes() {
 int i;
 while (i < 10) {
   write("Code for "+i+":"+call_other(HOUSE_SHOP_D, "query_code", i)+"\n");
   i += 1;
 }
 return 1;
}

info(i) {
  if (!i || !sscanf(i, "%d", i)) {
    write("Usage: info [number of house]\n");
    return 1;
  }
  if (i > 0 && i < 4) {
    write("A small house near the slums.\n");
    return 1;
  }
  if (i > 3 && i < 9) {
    write("A small house in central town.\n");
    return 1;
  }
  if (i > 8 && i < 11) {
    write("A large house in the rich part of the city.\n");
    return 1;
  }
  write("No such a house.\n");
  return 1;
}


map() {
 cat("/data/housemap");
 return 1;
}

write_new_key(code) {
  string file;
  int i;

  file = "/room/houses/keys/key";
  i = 1;
  while(file_size((file+i+".c")) != -1) {
    i += 1;
  }
  file = file+i+".c";
  if (this_player()->query_wiz() || this_player()->query_tester()) {
    write("File: "+file+" code: "+code+"\n");
  }
write_file(file, "inherit "+MARK+"room/key"+MARK+";\n");
write_file(file, "inherit "+MARK+"room/houses/keys/key_base"+MARK+";\n");
write_file(file, "reset() { set_key_code("+MARK+code+MARK+"); }\n");
write_file(file, "query_auto_load() { return "+MARK+file+":"+MARK+"; }\n");

  return file;
}

