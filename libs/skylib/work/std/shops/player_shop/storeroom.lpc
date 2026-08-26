/**
 * The standard inheritable object for player-run shop storerooms.
 * This object defines the section of the shop responsible for
 * holding the stock, and contains the stock cabinets.  The majority
 * of player-shop functionality is handled from within the main office.
 * See the header file for a complete description of the shop's workings.
 * @see /include/player_shop.h
 * @see /std/shops/player_shop/office.c
 * @see /std/shops/player_shop/mgr_office.c
 * @see /std/shops/player_shop/counter.c
 * @see /std/shops/player_shop/shop_front.c
 * @see /std/shops/player_shop/shopkeeper.c
 * @author Ringo
 * @started 1st August 1999
 */
#include <player_shop.h>
#include <move_failures.h>
#include <money.h>

#define ITEM_COST "player_shop_item_cost"

inherit ROOM_OBJ;

string get_list( mixed *, string );
int do_list( object *, object * );
int do_add( object *, object *, int );
int do_remove( string );

private nosave string _office = "",
                      _counter = "",
                      _mgr_office = "",
                      _shop_front = "",
                      _office_dir = "",
                      _counter_dir = "",
                      _shop_dir = "";

private nosave object *_cabinets = ({});

private nosave int _num_cabinets;

/** @ignore yes */
void create()
{
   do_setup++;
   ::create();
   do_setup--;
   add_property("no burial", 1);
   add_property( "determinate", "" );
//   add_item( "cabinet", "There are several cabinets in the room, holding "
//     "the entire stock of the shop.  If you are authorised to do so, you "
//     "may \"list\" the stock, as well as \"add\" and \"remove\" "
//     "items from the cabinets." );
   add_item( ({ "roll", "bags", "bag" }), ({ "long", "You could probably \"pull\""
     " a bag off the roll and give it to a customer with their purchase.\n"
     "Bags should only be handed out with purchases of 10 or more items.",
     "pull", ({ this_object(), "pull_roll" }) }) );
   if ( !do_setup )
   {
      this_object()->setup();
      this_object()->reset();
   }
   add_extra_look( this_object() );
}
/* create() */


/** @ignore yes */
void init()
{
   ::init();
   if ( !_office || _office == "" )
   {
      return;
   }
   if ( _office->query_employee( this_player()->query_name() ) ||
     creatorp(this_player()) )
   {
      add_command( "add", "<indirect:object:me'item(s)'>", (: do_add($1, ({}), 0) :) );
      add_command( "add", "<indirect:object:me'item(s)'> for <number'cost'>",
         (: do_add($1, ({}), $4[sizeof($4)-1]) :) );
      add_command( "add", "<indirect:object:me'item(s)'> to <indirect:object:here'cabinet(s)'>",
         (: do_add($1[0], $1[1], 0) :) );
      add_command( "add", "<indirect:object:me'item(s)'> to <indirect:object:here'cabinet(s)'> for <number'cost'>",
         (: do_add($1[0], $1[1], $4[0]) :) );
      add_command( "list", "", (: do_list($1, ({})) :) );
   }
   if ( _office->query_supervisor( TP->query_name() ) ||
        _office->query_manager( TP->query_name() ) ||
        creatorp( TP ) ) {
/*      add_command( "remove", ({
        "<number> <string'item(s)'> from stock",
        "<string'item'> <number> from stock",
        "<number> <string'item(s)'> from cabinet <number'cabinet'>",
        "<string'item'> <number> from cabinet <number'cabinet'>", }),
        (: do_remove($4,$5) :) );*/
      add_command("remove", "<string'object(s)'> from stock",
        (: do_remove($4[0]) :));
   }
   if ( _office->query_retired( this_player()->query_name() ) )
   {
            add_command( "list", ({ "", "cabinet <number'cabinet'>",
        "<string'item'>", "<string'item'> in cabinet <number'cabinet'>" }),
        (: do_list($4,$5) :) );
   }
} /* init() */


/**
 * Extra text for long description.
 * This function advises of the bag roll & cabinets in the room.
 * Mask this function to amend the extra_look.
 */
string extra_look( object thing )
{
   if ( thing == this_object() )
   {
       return "There are "+query_num(sizeof(_cabinets))+" cabinets in the "
         "room, holding the entire stock of the shop.\n";
   }
}
/* extra_look() */


/** @ignore yes */
private void init_cabinets()
{
   object cabinet;
   int i;
   string cab_name;

   for ( i = 0; i < _num_cabinets; i++ )
   {
      cab_name = "cabinet"+ i;
      cabinet = clone_object( CABINET );
//      cabinet->set_name( cab_name );
      cabinet->set_save_file( SAVE_DIR+ _office->shop_very_short()+
        "_"+ cab_name );
      _cabinets += ({ cabinet });
      add_hidden_object(cabinet);
   }
}
/* init_cabinets() */


/**
 * Set the path of the main office.
 * @param path The full path & filename.
 */
void set_office( string path )
{
   _office = path;
   _counter = _office->query_counter();
   _mgr_office = _office->query_mgr_office();
   _shop_front = _office->query_shop_front();
   _num_cabinets = _office->query_num_cabinets();
   init_cabinets();
}
/* set_office() */


/** @ignore yes */
int add_cabinet()
{
   object cabinet;
   string cab_name;

   if ( ( _num_cabinets ) == MAX_CABINETS )
   {
      return 0;
   }
   cab_name = "cabinet"+ _num_cabinets++;
   cabinet = clone_object( CABINET );
   cabinet->set_name( cab_name );
   cabinet->set_save_file( SAVE_DIR+ _office->shop_very_short()+
     "_"+ cab_name );
   _cabinets += ({ cabinet });
   return 1;
}
/* add_cabinet() */


/** @ignore yes */
string remove_cabinet()
{
   object cabinet;

   if ( ( _num_cabinets ) == MIN_CABINETS )
   {
      return "";
   }
   _num_cabinets--;
   cabinet = _cabinets[_num_cabinets];
   _cabinets -= ({ cabinet });
   cabinet->move( "/room/rubbish" );
   return cabinet->query_name();
}
/* remove_cabinet() */


/**
 * Query the current number of items in stock.
 * @param item The item to query.
 * @param cabinet The cabinet to look in (0 to look at all stock).
 * @return The number of that item in stock.
 */
int query_num_items( string item, int cabinet )
{
   int num_items = 0;

   if ( cabinet )
   {
      return sizeof( match_objects_for_existence( item, ({ _cabinets[cabinet-1] }) ) );
   }
   //for ( cabinet = 0; cabinet < _num_cabinets; cabinet++ )
   //{
      num_items += sizeof( match_objects_for_existence( item, _cabinets ) );
   //}
   return num_items;
}
/* query_num_items() */


/**
 * Query the current stock.
 * @param cabinet The cabinet to look in (0 to look at all stock).
 * @return The stock.
 */
object *query_stock( int cabinet )
{
   object *items = ({});
   int i;

   if ( cabinet )
   {
      return copy( all_inventory( _cabinets[cabinet-1] ) );
   }
   for ( i = 0; i < _num_cabinets; i++ )
   {
      items += all_inventory( _cabinets[i] );
   }
   return copy(items);
}
/* query_stock() */

/** @ignore yes */
string get_list( mixed *args, string pattern )
{
   string ret;
   object cabinet, ob;
   mixed *texts;
   int i, flag;
   object *items = ({ });
   switch(pattern) {
     case "" :
       //Searching for *everything*
       foreach(cabinet in _cabinets) {
         items += INV(cabinet);
       }
       ret = "Items listing for "+_office->query_shop_name();
       break;
     case "cabinet <number'cabinet'>" :
       //Searching in the one cabinet.
       items += INV(_cabinets[args[0]-1]);
       break;
       ret = "Items listing for "+_office->query_shop_name()+
             ", in cabinet "+query_num(args[0]);
     case "<string'item'>" :
       //All items matching specified string, in any cabinet.
       foreach(cabinet in _cabinets) {
         items += INV(cabinet);
       }
       filter(items, (: $1->id($2) :), args[0]);
       ret = "\""+args[0]+"\""+" listing for "+_office->query_shop_name();
       break;
     case "<string'item'> in cabinet <number'cabinet'>" :
       //Matching specified string in specified cabinet.
       items += INV(_cabinets[args[1]-1]);
       filter(items, (: $1->id($2) :), args[0]);
       ret = "\""+args[0]+"\""+" listing for "+_office->query_shop_name()+
             ", in cabinet "+query_num(args[1]);
       break;
   }
   ret += "\n";
   texts = ({ });
   foreach(ob in items) {
     flag = 0;
     for(i = 0; i < sizeof(texts); i++) {
       if(arrayp(texts[i]) && sizeof(texts[i])) {
         if(ob->query_short() == texts[i][0]->query_short() &&
            ob->query_property(ITEM_COST) ==
              texts[i][0]->query_property(ITEM_COST)) {
           texts[i] += ({ ob });
           flag = 1;
         }
       }
     }
     if(!flag) {
       texts += ({ ({ ob }) });
     }
   }
   for(i = 0; i < sizeof(texts); i++) {
     ret += "   "+query_multiple_short(texts[i])+" for "+
         MONEY_HAND->money_value_string(
            texts[i][0]->query_property(ITEM_COST), _office->query_place())+
         (sizeof(texts[i]) > 1 ? " each " : "") + "\n";
   }
   return ret;
}

/** @ignore yes */
int do_list( object *items, object *cabinets )
{
   string list;
   object thing;
   mapping things = ([]);
   if(!sizeof(cabinets)) cabinets = _cabinets;
   if(!sizeof(items)) {
     items = ({ });
     foreach(thing in cabinets) {
       items += INV(thing);
     }
   }
   foreach(thing in items) {
     if(member_array(thing->query_property(ITEM_COST), keys(things)) == -1) {
       things += ([ thing->query_property(ITEM_COST) : ({ thing }) ]);
     }
     else {
       things[thing->query_property(ITEM_COST)] += ({ thing });
     }
   }
   list = "Items on sale for " + _office->query_shop_name() + ":\n";
   if(!sizeof(things)) {
     tell_object(TP, list + "There is nothing on sale at the moment.\n");
     return 1;
   }  
   foreach(int key in keys(things)) {
     list += (query_multiple_short(things[key]) + " for " +
              MONEY_HAND->money_value_string(key, _office->query_place()) +
              (sizeof(things[key])>1?" each":"")+"\n");
   }           
   tell_object(TP, list);
   return 1;
}
/* do_list() */


/** @ignore yes */
int do_add( object *items, object *cabinets, int cost)
{
  object cabinet;
  object *succeed, *failed, *tmp_failed;
  if(!sizeof(cabinets)) cabinets = _cabinets;
  succeed = items;
  failed = items;
  tmp_failed = ({});
  foreach(cabinet in cabinets) {
    if(sizeof(items)) {
      tmp_failed = cabinet->add_items(items, TP, (cost?cost*sizeof(items):0));
      items -= tmp_failed;
      succeed -= tmp_failed;
    }
  }
  if(cost) {
    cost *= sizeof(succeed);
  }
  else {
    foreach(cabinet in succeed) { //Yeah, yeah, I know...
      cost += cabinet->query_value();
    }
  }
  failed -= succeed;
  if(sizeof(succeed)) {
    if(sizeof(failed)) {
      tell_object(TP, "You add "+query_multiple_short(succeed)+" to the "
        "inventory for the value of "+cost+
        ", but you cannot add "+
        query_multiple_short(failed)+" for some reason.\n");
    }
    else {
      tell_object(TP, "You add "+query_multiple_short(succeed)+" to the "
        "inventory for the value of "+cost+".\n");
    }
    TP->save();
  }
  else {
    tell_object(TP, "You fail to add "+query_multiple_short(failed)+" to "
      "the shop's inventory.\n");
  }
  return 1;
}
/* do_add() */

/** @ignore yes */
int do_remove( string thing )
{
  object *items, cabinet, *cab_items, *failed;
  items = ({ });
  failed = ({ });
  items = match_objects_for_existence(thing, _cabinets);
  foreach(cabinet in _cabinets) {
    cab_items = filter(items, (: ENV($1) == $2 :), cabinet);
    failed += cabinet->remove_items(cab_items, TP);
  }
  items -= failed;
  if(sizeof(failed)) {
    tell_object(TP, sprintf("You remove %s from the shop's stock, but you cannot "
      "carry %s, so you leave %s here.\n", query_multiple_short(items),
      query_multiple_short(failed), (sizeof(failed)>1?"them":"it")));
  }
  else {
    tell_object(TP, sprintf("You remove %s from the shop's stock.\n",
      query_multiple_short(items)));
  }
  return 1;
}
/*  object *items, *failed, *test;
  object cabinet;
  int i;
  items = ({ });
  switch(pat) {
    case "<number> <string'item(s)'> from stock" :
      foreach(cabinet in _cabinets) {
        i -= 1;
        test = filter(INV(cabinet), (: $1->id($2) :), args[1]);
        if(i < sizeof(test) && i > -1) {
          test = test[0..i];
        }
        if(i > -1) {
          items += test;
          failed += cabinet->remove_items( items, TP );
        }
      }
      items -= failed;
      break;
/*        "<string'item'> <number> from stock",
        "<number> <string'item(s)'> from cabinet <number'cabinet'>",
        "<string'item'> <number> from cabinet <number'cabinet'>" */
/*
  }
  return 1;
*/
/*   int i, number, cab_no = 0;
   object *items, *stock, *failed, *test;
   string plural;

   return notify_fail("This sucks. Fix it. New syntax, etc, updated for "
     "the new behaviour. Do it!\n");

   failed = ({});
   add_succeeded_mess("");
   if ( sizeof( args ) > 2 )
   {
      cab_no = args[2];
   }
   if ( query_num_items( args[1], cab_no ) < args[0] )
   {
      tell_object( this_player(), "The stock does not contain "+
        args[0] + " "+ args[1]+ " to remove.\n" );
      return 1;
   }
   items = ({});
   if ( !cab_no )
   {
      number = args[0];
      for( i = sizeof( _cabinets ); i > 0; i-- )
      {
         stock = match_objects_for_existence( args[1], ({ _cabinets[i-1] }) );
         if ( sizeof(stock) > number )
         {
            stock = stock[ 0 .. (number-1) ];
         }
         items += stock;
         failed += _cabinets[i-1]->remove_items( stock, this_player() );
         number -= sizeof( stock );
         if ( !number )
         {
            break;
         }
      }
   }
   else
   {
      items = match_objects_for_existence( args[0]+ " "+ args[1], ({ _cabinets[cab_no-1] }) );
      failed = _cabinets[cab_no - 1]->remove_items( items, this_player() );
   }
   items -= failed;
   if ( sizeof( failed ) )
   {
      tell_room( environment( this_player() ), this_player()->query_short()+
         " accidentally drops "+ query_multiple_short( failed )+
         " on the floor.\n", ({ this_player() }) );
      tell_object( this_player() , "You accidentally drop "+
         query_multiple_short( failed )+ "on the floor.\n" );
   }
   if ( sizeof( items ) )
   {
      _office->shop_log( SALE, this_player()->query_name(),
         this_player()->convert_message( query_multiple_short( items ) )+
         " removed from stock" );
      foreach ( plural in _office->query_list_array() )
      {
         test = ({});
         parse_command( plural, items, "%i", test );
         if ( !test || !sizeof( test ) )
         {
             continue;
         }
         _office->adjust_sold( plural, sizeof( test ) - 1 );
      }
      add_succeeded_mess( "$N $V "+ query_multiple_short( items )+
         " from the stock.\n");
   }
   return 1;*/
/* do_remove() */


/** @ignore yes */
void dest_me()
{
   object cabinet;

   foreach( cabinet in _cabinets )
   {
      cabinet->dest_me();
   }
   ::dest_me();
}
/* dest_me() */


/**
 * Set the directions to other parts of the shop.
 * This function is used by the npc shopkeeper to navigate
 * around the shop, using the exits at the given directions.
 * These directions should be the standard "north", "southeast" etc.
 * @param office The direction to the office.
 * @param counter The direction to the counter.
 * @param shop The direction to the shop front.
 */
void set_directions( string office, string counter, string shop  )
{
   _office_dir = office;
   _counter_dir = counter;
   _shop_dir = shop;
}
/* set_directions() */


/**
 * Query the direction to another part of the shop.
 * This function is used by the npc shopkeeper to navigate
 * around the shop.
 * @param place The full path to the destination.
 * @return The direction, or "here" if already there.
 */
string directions_to( string place )
{
   if ( place == _counter )
   {
      return copy(_counter_dir);
   }
   if ( place == _office )
   {
      return copy(_office_dir);
   }
   if ( place == _shop_front )
   {
      return copy(_shop_dir);
   }
   return "here";
}
/* directions_to() */


/**
 * Someone has entered the room.
 * This function will automatically fire an employee if they have
 * teleported to this room.  To avoid this happening, or to modify,
 * mask this function.
 */
void event_enter( object ob, string message, object from )
{
   _office->event_enter( ob, message, from );
}
/* event_enter() */


/**
 * Someone has died.
 * This function will automatically fire an employee if they have
 * killed someone whilst on duty.  It will also make a note of anyone
 * who has killed an on-duty employee (including the npc shopkeeper).  To
 * avoid this happening, or to modify, mask this function.
 */
void event_death( object killed, object *others, object killer,
  string rmess, string kmess )
{
   _office->event_death( killed, others, killer );
}
/* event_death() */


/**
 * Query the path to the office.
 * @return The path to the office.
 */
string query_office() { return copy( _office ); }


/**
 * @ignore yes
 * Get a shopping bag
 */
int pull_roll()
{
   object bag;
   string message, day, day2, month;

   bag = clone_object( SHOP_BAG );
   sscanf( mudtime(time()), "%*s %s %s %s", day, day2, month );
   if ( member_array( month, ({ "Offle", "February", "March",
     "April", "May", "June", "Grune", "August", "Spune", "Sektober",
     "Ember", "December", "Ick" }) ) == -1 )
   {
      message = sprintf( "A very happy %s %s %s\n\nfrom everyone at\n\n%s, %s",
        day, day2, month, _office->query_shop_name(), _office->query_place() );
   }
   else
   {
      message = sprintf( "With the compliments of\n\n%s, %s.",
        _office->query_shop_name(), _office->query_place() );
   }
   bag->set_read_mess( message );
   if ( (int)bag->move( this_player() ) != MOVE_OK )
   {
      bag->move( this_object() );
      tell_object( this_player(),
        "You drop the bag as you're carrying too much.\n" );
   }
   this_player()->add_succeeded_mess( this_object(),
     "$N $V the roll and $I comes off.\n", ({ bag }) );
   return 1;
}
/* pull_roll() */


/**
 * @ignore yes
 * Add standard stuff
 */
void set_long( string long_desc )
{
   long_desc += "Employees can \"add\" something to, \"remove\" "
     "something from and \"list\" the stock.\nThere is a roll of "
     "shopping bags conveniently located on one wall.\n";
   ::set_long( long_desc );
}
/* set_long() */

/** @ignore yes */
object *query_cabinets() {
  return _cabinets;
}
