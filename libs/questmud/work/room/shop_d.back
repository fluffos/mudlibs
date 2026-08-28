#include "/sys/ansi.h"

static mapping objects;
int balance;

reset(arg) {
  if(arg) {
    return;
  }
  objects = ([ ]);
  move_object(clone_object("/world/objects/trashcan"), this_object());
}

restore_shop() {
  if(!get_savefile()) return 0;
  restore_object("/data/shops/"+get_savefile());
}

save_shop() {
  if(!get_savefile()) return 0;
  save_object("/data/shops/"+get_savefile());
}

get_savefile() {
  string file, temp;
  int tmp;
  file = file_name(this_object());
  if(sscanf(file, "%s#%d", file, tmp) == 2) {
    log_file("SHOP_SAVE", ctime(time())+" "+file+" not saved. (is a clone).\n");
    return 0;
  }
  file = file[1..strlen(file)-1];
  while(file && sscanf(file, "%s/%s", temp, file) == 2) { }
  return file;
}

query_balance() {
  return balance;
}

add_balance(int value) {
  balance += value;
  save_shop();
}

shop_commands() {
  add_action("sell_item", "sell");
  add_action("buy_item", "buy");
  add_action("list_inventory","list");
}

load_item(str,min,max) {
  int i;
  i = random(max+1)+min;
  objects += ([ str:i ]);
}

reduce_item(file) {
  if(objects[file] > 1) {
    objects[file] -= 1;
    return 1;
  }
  objects -= ([ file ]);
  return 1;
}

add_item(file) {
  if(objects[file]) {
    objects[file] += 1;
    return 1;
  }
  objects += ([ file : 1 ]);
  return 1;
}

sell_item(string arg) {
  object ob, item_o;
  string file,tmp, sold;
  int i, total_value, value;
  if(!arg) {
    write("Sell what?\n");
    return 1;
  }

  /* multiloop */
  item_o = call_other("/daemons/filter", "EQ_FILTER", arg, this_player());

  /* loop. */
  for(i=0; i < sizeof(item_o); i++) {
    /* sscanffi. add_item mapping loop. query_keep mapping loop  */
    value = query_item_value(item_o[i]);
    if(value > 0) {
      total_value += value;
      if(!sold) sold = "";
      else sold += ", ";
      sold += item_o[i]->short();
      destruct(item_o[i]);
    }
  }
  if(total_value) "/room/bank"->add_bank_money(total_value, 3, this_player()->query_name());
  if(!total_value) {
    write("You sold nothing.\n");
    return 1;
  }
  write("You sell "+sold+" for "+total_value+" bronze coins. (coins transferred to your account)\n");
  say(this_player()->query_name()+" sells "+sold+".\n");
  add_balance(-total_value);
  this_player()->fix_weight();
  return 1; 
}

/* return 0 if cannot sell. stores the item if returns a value */
static query_item_value(object ob) {
  string file,tmp;
  int value, divider;
  if(!this_object()->can_sell(ob) || this_player()->query_keep(ob) ||
        ob->id("money")) {
    if (ob && this_player()->query_tester()) write("Cannot sell '"+ob->short()+"'.\n");
    return 0;
  } 
  sscanf(file_name(ob), "%s#%s",file,tmp);
  value = ob->query_value() / 2;
  divider = objects[file] / 20 + 1;
  value = value / divider;
  if(value <0) value = 0; 
  if (value == 0) {
    if(this_player()->query_tester()) write(ob->short() + " has no value.\n");
    return 0;
  }
  if (value > 1000) {   
    write("The shopkeeper says '"+ 
        "Hmm.. I don't have enough money to buy this item.'\n");
    return 0;
  }   
  add_item(file);
  return value;
}

buy_item(string arg) {
  object ob;
  string str,file,tmp;
  int i, value;
  str = m_indices(objects);
  if(!arg || sscanf(arg,"%d",i) != 1) {
    write("Usage: buy <number>\n");
    return 1;
  }
  i -= 1;
  if(i<0 || i>= sizeof(str)) {
    write("No such an item for sale.\n");
    return 1;
  }
  if(this_player()->query_wiz()) {
	write(str[i]+"\n");
  }
    
  if(!str[i]) { /* || file_size(str[i]+".c") == -1) { */
    write("That item is not for sale anymore, sorry.\n");
    return 1;
  }

  ob = clone_object(str[i]);
  value = ob->query_value();
  if(value > this_player()->query_money(3)) {
    write("You don't have enough bronze coins.\n");
    destruct(ob);
    return 1;
  }
  if(!this_player()->add_weight(ob->query_weight())) {
    write("You cannot carry it.\n");
    destruct(ob);
    return 1;
  }
  sscanf(file_name(ob), "%s#%s",file,tmp);
  reduce_item(file);
  this_player()->reduce_money(value,3, 1); /* 1 for selling */
  move_object(ob,this_player());
  write("You buy "+ob->short()+" for "+value+" bronzes.\n");
  say(this_player()->query_name()+" buys "+ob->short()+".\n");
  add_balance(value);
  return 1;
}

list_inventory() {
  object ob;
  int i,num;
  string str,tmp,tmp2,tmp3,tmp4,space;
  str = m_indices(objects);
  num = m_values(objects);
  space = "                                                                  ";
  write("+----+--------------------------------------------------------+----+------+\n");
  write("|  # | Item:                                                  |Left| Cost |\n");
  write("+----+--------------------------------------------------------+----+------+\n");
  while(i<sizeof(num)) {
    tmp = "| "+(i+1)+".| ";
    if(i<9) tmp = "|  "+(i+1)+".| ";
    if(str[i] && clone_object(str[i])) {
     ob = clone_object(str[i]);
     tmp2 = ob->short();
     if(strlen(tmp2) < 53)
       tmp2 += extract(space,0,53-strlen(tmp2));
     tmp3 = " | "+num[i]+" |";
     if(num[i]<10) tmp3 = " |  "+num[i]+" |";
     tmp4 = ob->query_value()+"|";
     tmp4 = extract(space,0,6-strlen(tmp4))+tmp4;
     write(tmp+tmp2+tmp3+tmp4+"\n");
    }
    i+= 1;
  }
  write("+----+--------------------------------------------------------+----+------+\n");
  if (ob) destruct(ob);
  return 1;
}
