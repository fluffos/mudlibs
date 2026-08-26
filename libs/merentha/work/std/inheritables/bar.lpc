// Petrarch 
// Merentha Lib 1.0
// bar.c

#include <std.h>
#include "bar.h"

inherit ROOM;

mapping __Menu=([]);
string __Currency;

void set_currency(string str) { __Currency=str; }

void set_menu(mapping menu) { __Menu=menu; }
mapping query_menu() { return __Menu; }

void init() {
::init();
  add_action("cmd_read", ({"read","list"}));
  add_action("cmd_buy", "buy");
}

int buy_item(string type, mapping item) {
object food;
int cost=item["strength"]/2;
  if(this_player()->query_money(__Currency) < cost) return notify_fail("That will cost "+cost+" "+__Currency+" coins which you do not have.\n");
  food=new(type);
  food->set_name(item["name"]);
  food->set_short(item["short"]);
  food->set_long(item["long"]);
  food->set_id(item["id"]);
  food->set_strength(item["strength"]);
  food->set_mass(item["weight"]);
  if(food->move(this_player())) {
    food->remove();
    return 1;
  } 
  this_player()->add_money(__Currency, -cost);
  message("shop", "You purchase "+food->query_short()+".",this_player());
  return 1;
}

int cmd_buy(string str) {
mapping foods, drinks;
string *items;
int i; 
  if(!str) return notify_fail("Syntax: buy <item>\n");
  drinks=__Menu["drinks"];
  foods=__Menu["foods"];
  if(!drinks) drinks=([]);
  if(!foods) foods=([]);
  i=sizeof(items=keys(foods));
  while(i--) 
    if(member_array(str, foods[items[i]]["id"])!=-1) return buy_item(FOOD,foods[items[i]]);
  i=sizeof(items=keys(drinks));
  while(i--) 
    if(member_array(str, drinks[items[i]]["id"])!=-1) return buy_item(DRINK,drinks[items[i]]);
  return notify_fail("That is not for sale here.\n");
}

int cmd_read(string str) {
mapping foods, drinks;
string *items, *food=({}), *drink=({});
string tmp="............................";
int i,j,x,z,y;
  if(query_verb()!="list" && (!str || str!="menu")) return notify_fail("Read what?\n");
  x=this_player()->getenv("SCREEN");
  if(!x) x=75;
  x-=6;
  drinks=__Menu["drinks"];
  foods=__Menu["foods"];
  if(!drinks) drinks=([]);
  if(!foods) foods=([]);
  i=sizeof(items=keys(foods));
  while(i--) 
    food+=({"%^RED%^"+arrange_string(foods[items[i]]["short"]+"%^GREEN%^"+arrange_string(tmp,(x/2-9)-strlen(foods[items[i]]["short"]))+".%^ORANGE%^"+foods[items[i]]["strength"]/2+" coins",x/2-1)});
  i=sizeof(items=keys(drinks));
  while(i--) 
    drink+=({"%^RED%^"+arrange_string(drinks[items[i]]["short"]+"%^GREEN%^"+arrange_string(tmp,(x/2-9)-strlen(drinks[items[i]]["short"]))+".%^ORANGE%^"+drinks[items[i]]["strength"]/2+" coins",x/2-1)});
  i=sizeof(drink);
  j=sizeof(food);
  z=(j>i?j:i);
  y=0;
  tmp="";
  if(j) tmp+=arrange_string(center("%^ORANGE%^Food", x/2),x/2);
  if(i) tmp+=arrange_string(center("%^ORANGE%^Drinks", x/2),x/2);  
  tmp+="\n";
  while(y<z) {
    if(j) {  
      if(y<j) tmp+=food[y];
      else if(j) tmp+=arrange_string("",x/2-1);
      tmp+="  ";
    }
    if(y<i) tmp+=drink[y];
    tmp+="\n";
    y++;
  }  
  tmp+=center("%^ORANGE%^All prices are in "+__Currency+" coins.",x+2);
  message("read", border(tmp, "Menu", x+6), this_player());
 
  return 1;
}

void reset() { 
object menu;
::reset();
  if(!present("menu")) {
    menu=new(OBJECT);
    menu->set_short("a menu sitting on the counter");
    menu->set_name("menu");
    menu->set_long("The menu has today's specials on it.");
    menu->set_id(({"menu"}));
    menu->set_prevent_get("The menu is attached to the counter and can not be taken.");
    menu->move(this_object());
  }
}

