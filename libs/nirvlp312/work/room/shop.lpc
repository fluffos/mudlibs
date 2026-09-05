inherit "room/room";

#include <ansi.h>

#define SHOP "/obj/daemons/shop_daemon"

/** Shop variables **/
int value;
int item_short;

reset(arg) {
	if(arg) return;
  
  short_desc = "The shop";
  long_desc=
"You are in a shop. You can buy or sell things here.\n" +
"There is a sign on the wall that you could look at to get commands.\n"+
"There is an opening to the north, and some shimmering\n" +
HIB+"blue light"+NORM+" in the doorway.\n",
  set_light(1);
  items=({
    "sign","You can buy, list, sell, and value things here.\n\
list                       List all items\n\
list armors                List armors\n\
list weap                  List weapons\n\
list heals                 List heal items\n\
list misc                  List misc items\n\
list <item>                List items with id of <item>\n\
buy <item>                 Buy item\n\
buy #                      Buy item\n\
sell <item>                Sell a paticular item.\n\
sell all <item>            Sell all items of that type.\n\
sell ALL <item>            Sell all items of that type even if kept or equipped.\n\
sell all                   Sell everything, except kept or equipped items.\n\
sell ALL                   Sell everything, even if kept or equipped.\n\
sell <item> in bagname     Sell an item from a bag.\n\
sell all <item> in bagname Sell all items of that type from a bag\n\
sell all in bagname        Sell all items from your bag.\n\
value <item>               Value of item\n\
\n\tContents from bags will always be sold when selling",
  });
  dest_dir=({
    "room/store","north",
    "room/ptroom","east",
    "room/vill_road2","south",
  });
  if( !find_object( "/room/store" ) )
    call_other( "/room/store", "???" );
  
}

init() {
	::init();
  add_action("Sell","sell");
  add_action("Value","value");
  add_action("North","north");
  add_action("List","list");
  add_action("Buy","buy");
}

query_drop_castle() {
    return 1;
}

North() {
  if ( this_player()->query_level() < 30) {
    write("A strong magic force stops you.\n");
    say(call_other(this_player(), "query_name", 0) +
      " tries to go through the field, but fails.\n");
    return 1;
  }
  write("You wriggle through the force field...\n");
  return 0;
}

Sell( str ) { 
  return SHOP->sell( str );
}

Value( str ) {
  return SHOP->value( str );
}

List( string str ) {
  return SHOP->list( str );
}

Buy( string str ) {
  return SHOP->buy( str );
}

exit() {
  if (this_player()) /* Added this check - Rumplemintz */
  this_player()->set_shop_inventory( 0 );
}

object
query_backshop() { 
  object store;
  store = find_object("/room/store"); 
  if( !store ) {
    call_other( "/room/store", "???");
    store = find_object( "/room/store" );
  }
  return store;
}

query_shop() { return 1; }
query_annoy() { return "Not sure what you want from me."; }
query_sold() { return "You get "+value+" gold coins"; }
query_sold2() { return "The shop is low on money...\nYou get "+value+" gold coins." ; }
query_is_eq() { return item_short+" is equipped."; }
query_is_kept() { return item_short+" is kept."; }
query_no_item() { return "No such item ("+item_short+") here."; }
query_no_item2() { return "No such item ("+item_short+") here\nor in the store."; }
query_no_drop() { return "I can't seem to take that from you."; }
query_no_bag() { return "You don't seem to have "+item_short+"."; }
query_error() { return "Uhhh something went wrong."; }
query_no_value() { return item_short+" has no value."; }
query_no_move() { return item_short+" can't be moved."; }
query_empty() { return item_short+" is empty."; }
query_empty_shop() { return "Store is empty."; }
query_dest_msg() { return "The valuable item is hidden away."; }
query_value_msg() { return "You would get "+value+" gold coins."; }
query_value_msg2() { return "The "+item_short+" would cost you "+value+" gold coins."; }
query_no_money() { return "It would cost you "+value+" coins, which you don't have."; }
query_no_carry() { return "You are unable to carry "+item_short+"."; }
query_buy() { return "You buy "+item_short+" for "+value+" gold coins."; }
query_dump_worthless_bag_items() { return "Worthless items from the "+item_short+" are dumped onto the ground."; }
query_total(int nbr_items, int total ) { return "You sold "+nbr_items+" items for "+total+" gold coins."; }
query_buy_msg() { return capitalize(this_player()->query_name())+" buys "+item_short+"."; }
query_sold_msg() { return capitalize(this_player()->query_name())+" sells "+item_short+"."; }

set_obj_value( int val ) {
  if( intp( val ) )
    value = val;
}

set_obj_short( string str ) {
  if( stringp( str ) )
    item_short = str;
}
