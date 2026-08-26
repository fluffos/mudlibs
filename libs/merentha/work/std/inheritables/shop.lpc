// Petrarch
// Merentha Lib 1.0
// shop.c

#include <std.h>
#include "shop.h"

inherit ROOM;

string __SupplyRoom;
string __Currency;

void set_supply_room(string str) { __SupplyRoom=str; }
void set_currency(string str) { __Currency=str; }

void init() {
    ::init();
    add_action("cmd_list", "list");
    add_action("cmd_show", "show");
    add_action("cmd_sell", "sell");
    add_action("cmd_buy", "buy");
    add_action("cmd_value", ({"appraise","value"}));
}

int filter_items(object item, string str) {
    if(!str) return 1;
    return item->id(str)+(str==item->query_type());
}

int sort_items(object item1, object item2) {
    if(item1->query_short() < item2->query_short()) return -1;
    if(item1->query_short() > item2->query_short()) return 1;
    return 0;
}

varargs int cmd_list(string str) {
    object *inv, *inv2;
    object supply;
    string ret="", tmp;
    int i, x, w;
    if(!supply=load_object(__SupplyRoom)) {
        message("shop", "The supply room is empty.", this_player());
        return 1;
    }
    if(!i=sizeof(inv=all_inventory(supply))) {
        message("shop", "The supply room is empty.", this_player());
        return 1;
    }
    inv=filter_array(inv, "filter_items", this_object(), str);
    inv=sort_array(inv, "sort_items", this_object());
    if(!i=sizeof(inv)) {
        message("shop", "The shop does not carry anything of that type.", this_player());
        return 1;
    }
    w=this_player()->getenv("SCREEN");
    if(!w) w=75;
    w-=14;
    x=w;
    while(i--) {
        w=x;
        tmp="%^RED%^"+inv[i]->query_short()+"%^GREEN%^ ";
        w-=strlen(strip_colours(tmp));
        if(w<0) w=0;
        while(w--) tmp+=".";
        tmp=arrange_string(tmp, x-1)+" %^ORANGE%^";  
        ret+=tmp+inv[i]->query_value()+" "+__Currency+"\n";
    }
    message("shop", border(ret,"Items for Sale",x+14), this_player());
    return 1;
}

int cmd_show(string str) {
    object supply, ob;
    if(!str) return notify_fail("Syntax: show <item>\n");
    if(!supply=load_object(__SupplyRoom)) {
        message("shop", "The supply room is empty.", this_player());
        return 1;
    }
    if(!ob=present(str,supply)) {
        message("shop", "That is not in stock.", this_player());
        return 1;
    }
    message("shop", "The shopkeeper takes "+ob->query_short()+" \
from the back shelf and shows it to you:\n"+ob->query_long(),
      this_player());
    return 1;  
}

int cmd_buy(string str) {
    object supply, ob;
    int val;
    if(!str) return notify_fail("Syntax: buy <item>\n");
    if(!supply=load_object(__SupplyRoom)) {
        message("shop", "The supply room is empty.", this_player());
        return 1;
    }
    if(!ob=present(str,supply)) {
        message("shop", "That is not in stock.", this_player());
        return 1;
    }
    if(this_player()->query_money(__Currency)<val=convert_money(ob->query_value(),__Currency)) {
        message("shop", "You do not have enough "+__Currency+".  It will cost you "+val+".", this_player());
        return 1;
    }
    if(ob->move(this_player())) return 1;
    message("shop", "The shopkeeper gives you "+ob->query_short()+" from the shelf.", this_player());
    this_player()->add_money(__Currency, -val);
    return 1;
}

int cmd_sell(string str) {
object ob;
int val;
 if(!str) return notify_fail("Syntax: sell <item>\n");
 if(!ob=present(str, this_player())) {
  message("shop", "You do not have that item to sell.", this_player());
  return 1;
 }
 if(!val=ob->query_value()) {
  message("shop", "That item is worthless and the shopkeeper will not buy it.\n", this_player());
  return 1;
 }
 if(ob->move(__SupplyRoom)) return 1;
 message("shop", "The shopkeeper gives you "+(val=convert_money(val,__Currency))+" "+__Currency+" for "+ob->query_short()+".", this_player());
 this_player()->add_money(__Currency, val);
 return 1;
}

int cmd_value(string str) {
object ob;
int val;
 if(!str) return notify_fail("Syntax: value <item>\n");
 if(!ob=present(str, this_player())) {
  message("shop", "You do not have that item to sell.", this_player());
  return 1;
 }
 if(!val=ob->query_value()) {
  message("shop", "That item is worthless and the shopkeeper will not buy it.\n", this_player());
  return 1;
 }
 message("shop", "The shopkeeper appraises "+ob->query_short()+" to be worth "+convert_money(val,__Currency)+" "+__Currency+".", this_player());
 return 1;
}


