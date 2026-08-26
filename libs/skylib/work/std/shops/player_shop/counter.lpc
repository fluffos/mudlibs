/**
 * The standard inheritable object for player-run shop counters.
 * This object defines the section of the shop behind the counter,
 * containing the register and sales log.  The majority of player-shop
 * functionality is handled from within the main office.  See the
 * header file for a complete description of the shop's workings.
 * @see /include/player_shop.h
 * @see /std/shops/player_shop/office.c
 * @see /std/shops/player_shop/mgr_office.c
 * @see /std/shops/player_shop/storeroom.c
 * @see /std/shops/player_shop/shop_front.c
 * @see /std/shops/player_shop/shopkeeper.c
 * @author Ringo
 * @started 1st August 1999
 */
#include <player_shop.h>
#include <money.h>

inherit ROOM_OBJ;

int do_calc( float, string, float );
int do_log( mixed * );
int do_correction( mixed * );
int action( string );

private nosave mixed *_money;

private nosave object _register = 0;

private nosave string _save_file = "",
                      _place = "???",
                      _office = "",
                      _storeroom = "",
                      _mgr_office = "",
                      _shop_front = "",
                      _store_dir = "",
                      _office_dir = "",
                      _shop_dir = "";

/** @ignore yes */
void create()
{
   do_setup++;
   ::create();
   do_setup--;
   add_property( "no burial", 1 );
   add_property( "determinate", "" );
   if ( !do_setup )
   {
      this_object()->setup();
      this_object()->reset();
   }
   add_item( "calculator", "A standard shop's calculator used to total "
     "up all those difficult prices.  To use, see \"syntax calc\"." );
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
   this_player()->command_override( (: action :) );
   add_command( "calc", "<number> {+|-|*|/} <number>",
     (: do_calc($4[0],$4[1],$4[2]) :) );
   if ( _office->query_employee( this_player()->query_name() ) ||
        creatorp(this_player()) )
   {
      add_command( "log",
        "shop {bought|sold} <number> <string'item(s)'> for <word'amount'>",
        (: do_log($4) :) );
      add_command( "correction",
        "shop {bought|sold} <number> <string'item(s)'> for <word'amount'>",
        (: do_correction($4) :) );
   }
}
/* init() */


/**
 * Set the path of the main office.
 * @param path The full path & filename.
 */
void set_office( string path )
{
   object cash;

   _office = path;
   _storeroom = _office->query_storeroom();
   _mgr_office = _office->query_mgr_office();
   _shop_front = _office->query_shop_front();
   _place = _office->query_place();
   if ( _register )
   {
      return;
   }
   _register = clone_object( "/obj/misc/cash_register" );
   _register->set_name( "register" );
   _register->set_short( "cash register" );
   _register->add_adjective( "cash" );
   _register->set_long( "The cash register is really just an iron drawer "
     "mounted underneath the counter.  In a certain light, it almost "
     "seems tongue-shaped.\n" );
   _register->set_shop( this_object() );
   add_hidden_object( _register );
   _register->reset_get();
   _money = _office->restore_register();
   if ( !_money || sizeof( _money ) < 2 )
   {
      return;
   }
   cash = clone_object( MONEY_OBJECT );
   cash->set_money_array( _money );
   cash->move( _register );
}
/* set_office() */


/** @ignore yes */
void save_me( mixed *old, string word ) {
   int difference;
   string sign;
   object cash;

   if ( !_register )
   {
      return;
   }
   if ( member_array( _register, query_hidden_objects() ) == -1 )
   {
      tell_room( this_object(), "The register emerges from the counter "
        "again.\n" );
      add_hidden_object( _register );
   }
   cash = present( MONEY_ALIAS, _register );
   if ( !cash )
   {
      _money = ({ });
   }
   else
   {
      _money = cash->query_money_array();
   }
   _office->save_register( _money );
   difference =
     ((sizeof(_money) > 1) ?
           (MONEY_HAND->query_total_value( _money, _place )) : 0) -
     ((sizeof(old) > 1) ? (MONEY_HAND->query_total_value( old, _place )) : 0);
   if ( !difference )
   {
      return;
   }
   _office->adjust_takings( difference );
   if ( difference < 0 )
   {
      sign = "-";
      difference = -difference;
   }
   else
   {
      sign = "";
   }
   if ( !word || word == "" )
   {
      return;
   }
   if ( sign == "-" )
   {
      _office->shop_log( PURCHASE, word, "removed "+
        MONEY_HAND->money_value_string( difference, _place )+
        " from register" );
   }
   else
   {
      _office->shop_log( SALE, word, "added "+
        MONEY_HAND->money_value_string( difference, _place )+
        " to register" );
   }
}
/* save_me() */


/** @ignore yes */
void save_register( int no_player )
{
   string word;

   if ( !no_player )
   {
      word = this_player()->query_name();
   }
   else
   {
      word = "shop";
   }
   if ( find_call_out( "save_me" ) == -1 )
   {
      call_out( "save_me", 3, _money, word );
      tell_room( this_object(), "The register retracts into the counter.\n" );
      remove_hidden_object( _register );
   }
}
/* save_register() */


/** @ignore yes */
int action( string str ) {
   string st1;
   if ( _office->query_employee( this_player()->query_name() ) ||
        creatorp(this_player()) ) {
     return 0;
   }
   sscanf( str,"%s %s",str,st1 );
   if( str == "get" || str == "take" )  {
      if ( strsrch( st1, "register" ) != -1 )
      {
         tell_object( this_player(), "You are not an active employee here!\n" );
         return 1;
      }
   }
}
/* action() */


/** @ignore yes */
int query_register() {
   int value;
   object cash;

   value = 0;
   cash = present( MONEY_ALIAS, _register );
   if ( !cash )
   {
      return 0;
   }
   _money = cash->query_money_array() + ({ });
   return MONEY_HAND->query_total_value( _money, _place );
}
/* query_register() */


/** @ignore yes */
int adjust_register( string player, int amount ) {
   int value;
   object cash, change;

   if ( amount < 0 )
   {
      return 0;
   }
   cash = present( MONEY_ALIAS, _register );
   if ( !cash ) {
      return 0;
   }
   _money = cash->query_money_array() + ({ });
   value = MONEY_HAND->query_total_value( _money, _place );
   if ( value < amount ) {
      amount = value;
   }
   change = MONEY_HAND->pay_amount_from( amount, cash, _place );
   if ( change ) {
      change->move( _register );
   }
   _office->shop_log( ACCOUNTS, player, "adjusted the register by "+
     MONEY_HAND->money_value_string( amount, _place ) );
   call_out( "save_register", 1, 1 );
   return amount;
}
/* adjust_register() */


/** @ignore yes */
void add_money_ob( object money )
{
   if ( !money ) {
      return;
   }
   money->move( _register );
   call_out( "save_register", 1, 1 );
}
/* adjust_register() */


/** @ignore yes */
int do_calc( float a, string sign, float b ) {
   string result;

   result = a+ " "+ sign+ " "+ b+ " = ";
   switch ( sign ) {
     case "+" :
        result += sprintf( "%.2f", to_float(a + b) );
        break;
     case "-" :
        result += sprintf( "%.2f", to_float(a - b) );
        break;
     case "*" :
        result += sprintf( "%.2f", to_float(a * b) );
        break;
     case "/" :
        if ( !b ) {
           tell_object( this_player(),
             "That is an invalid equation.\n" );
           return 1;
      }
      result += sprintf( "%.2f", to_float(a / b) );
      break;
   }
   result += "\n";
   tell_object( this_player(), result );
   add_succeeded_mess( "$N use$s the calculator.\n" );
   return 1;
}
/* do_calc() */


/** @ignore yes */
int do_log( mixed *args ) {
   _office->shop_log( LOG_ENTRY, this_player()->query_name(),
     args[0]+ " "+ args[1]+ " "+ args[2]+ " for "+ args[3] );
   add_succeeded_mess( "$N make$s an entry in the transaction log book.\n" );
   return 1;
}
/* do_log() */


/** @ignore yes */
int do_correction( mixed *args ) {
   _office->shop_log( LOG_ENTRY, this_player()->query_name(),
     "ERROR IN LOG - correct entry follows:" );
   _office->shop_log( LOG_ENTRY, this_player()->query_name(),
     args[0]+ " "+ args[1]+ " "+ args[2]+ " for "+ args[3] );
   add_succeeded_mess( "$N make$s a correction in the transaction log book.\n" );
   return 1;
}
/* do_correction() */


/**
 * Set the directions to other parts of the shop.
 * This function is used by the npc shopkeeper to navigate
 * around the shop, using the exits at the given directions.
 * These directions should be the standard "north", "southeast" etc.
 * @param office The direction to the office.
 * @param storeroom The direction to the store room.
 * @param shop The direction to the shop front.
 */
void set_directions( string office, string storeroom, string shop  ) {
   _office_dir = office;
   _store_dir = storeroom;
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
string directions_to( string place ) {
   if ( place == _storeroom ) {
      return _store_dir;
   }
   if ( place == _office ) {
      return _office_dir;
   }
   if ( place == _shop_front ) {
      return _shop_dir;
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
void event_enter( object ob, string message, object from ) {
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
  string rmess, string kmess ) {
   _office->event_death( killed, others, killer );
}
/* event_death() */


/**
 * @ignore yes
 * Add standard stuff
 */
void set_long( string long_desc ) {
   long_desc += "Employees of the shop can \"log\" transactions or "
     "\"correction\"s here.  The shop's cash register is under the "
     "counter and there is a calculator next to that.\n";
   ::set_long( long_desc );
}
/* set_long() */
