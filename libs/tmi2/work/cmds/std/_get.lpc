/*
// This file is part of the TMI distribution mudlib.

// Please include this header if you use the code here.
// Originally written by Brian Leet.
// Adapted by Sulam (12-13-91)
// Help added by Brian (1/28/92)  *smirk*
// Better messages added by Brian (2/5/92)
// Money functions and comments added by Mobydick@TMI-II  (8-24-92)
// Prevent_get added by Watcher@TMI (3/5/93)
*/

#include <mudlib.h>
#include <money.h>
#include <move.h>

inherit DAEMON ;

#define SYNTAX	"Syntax: get [object | all] <from [container]>\n"

int cmd_get( string str ) {
  object ob, *inv, ob2, *all;
  int res, i, number, is_money;
  string short, tmp, type;
  string word;
  int ammount;
  
  notify_fail("Get what?\n");
  if(!str || str == "")  return 0;
 
  this_player()-> block_attack( 2 );
 
   if(!this_player()->query("vision")) {
   notify_fail("Get what?  You can't see a thing!\n");
   return 0; }
 
  /* Check for form "get 30 gold coins"  */
  if( sscanf( str, "%d %s %s", ammount, type, tmp ) != 3 )
    /* Check for form "get 30 gold" */
  if( sscanf( str, "%d %s", ammount, type ) != 2 ) {
 
    /* Check for command "get all" */
    if( str == "all" ) {
      if (environment(this_player())) {
        inv = all_inventory( environment( this_player() ) );
        inv = filter_array(inv, "filter_short", this_object());
        all = filter_array(inv, "filter_get", this_object());
      }
 
      if(sizeof(inv) <= 1 || sizeof(all) == 1) {
      notify_fail("There is nothing here for you to get.\n");
      return 0; }
 
      for( i = 0; i <sizeof( inv ); i++ ) {
        if( ( int ) inv[i]-> query( "money" ) == 1 ) {
          type = inv[i]-> query_type();
          number = inv[i]-> query_number();
        }
	 
	if((int)inv[i]->query("prevent_get")) {
	write("You can't get the " + (string)inv[i]->query("short") + ".\n");
	continue; }
 
        res = ( int ) inv[i]-> move( this_player() );
        if( res == MOVE_OK ) {
          if( number> 0 ) {
            if( number == 1 ) word = "coin"; else word = "coins";
            write( "You take " + number + " " + type + " " + word + ".\n" );
            say( this_player()-> query( "cap_name" ) + " takes some " + type + " " + word + ".\n" );
            number = 0;
          } else {
	   short = inv[i]->query("short");
	   if(!short)  short = "something";
	    write ("You take "+short+".\n") ;
	    say( this_player()-> query("cap_name") + " takes " +
		 short+".\n") ;
          }
        }
      }
      return 1;
    }
    /* Assume he's trying to pick up a single object. */
    ob = environment( this_player() );
    if (!ob) {
      notify_fail("You can't take anything in the void!\n");
      return 0;
    }
    ob = present( str, ob );
    if( !ob ) {
      if( ( int ) environment( this_player() )-> id( str ) ) {
        notify_fail( "You can't take that!\n" );
        return 0;
      }
      notify_fail("There is no such object here to get.\n");
      return 0;
    }
    is_money = ob-> query( "money" );
    if( is_money == 1 ) {
      number = ob-> query_number();
      type = ob-> query_type();
    }
 
    if((int)ob->query("prevent_get")) {
    write("You can't get that object.\n");
    return 1; }
 
    res = ( int ) ob-> move( this_player() );
    if( res == MOVE_OK ) {
      if( is_money == 1 ) {
        if( number == 1 ) word = "coin"; else word = "coins";
        write( "You take " + number + " " + type + " " + word + ".\n" );
        say( this_player()-> query( "cap_name" ) + " takes some " + type + ".\n" );
      } else {
	short = (string) ob->query("short");
  	if(!short)  short = "something";
	write("You take " + short + ".\n") ;
	say( this_player()->query("cap_name") + " takes " +
	     short+"\n") ;
      }
      return 1;
    }
    if( res == MOVE_NOT_ALLOWED )
      notify_fail( "You can't do that.\n" );
    else if( res == MOVE_NO_ROOM )
      notify_fail( "You don't have enough room to carry that.\n" );
    else if( res == MOVE_TOO_HEAVY )
      notify_fail( "It is so heavy you cannot pick it up!\n" );
    return 0;
  }
  /* If we get here, it means we tried to "get 20 gold coins" or "get 20 gold" */
  type = lower_case( type );
  tmp = type + " coins";
  if( ammount < 1 ) {
    notify_fail( "You can only take positive amounts of coins.\n" );
    return 0;
  }
  i = this_player()-> query( "wealth/" + type );
  if( i < 0 ) return 0;
  ob = present( tmp, environment( this_player() ) );
  if( !ob || ob-> query_number() <ammount ) {
    notify_fail( "I don't see that many " + type + " here.\n" );
    return 0;
  }
  /* Split the pile of coins into two, the part taken and the part left behind.*/
  ob2 = clone_object( COINS );
  type = ob-> query_type();
  number = ob-> query_number();
  ob2-> set_type( type );
  ob2-> set_number( ammount );
  res = ( int ) ob2-> move( this_player() );
  if( res == MOVE_OK ) {
    ob-> set_number( number - ammount );
    if( ammount == 1 ) word = "coin"; else word = "coins";
    write( "You put " + ammount + " " + type + " " + word + " into your purse.\n" );
    say( this_player()-> query( "cap_name" ) + " takes some " + type + ".\n" );
    return 1;
  }
  notify_fail( "You can't carry that many more coins.\n" );
  ob2-> remove();
  return 0;
}

protected int filter_short(object obj) {  return (obj->query("short") != 0); }
 
protected int filter_get(object obj) {  return !(obj->query("prevent_get"));  }
 
string help() {
 
   return( SYNTAX + "\n" +
    "This command will have your character try to pick up the\n" +
    "item specified, or if all is typed, it will make your\n" +
    "character try to pick up everything in the room.\n"+
    "\nSee also: put, drop\n") ;
}
/* EOF */
