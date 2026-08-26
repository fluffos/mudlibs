/**
 * Entry for the training halls, can be adapted to suit other room.c
 * Based partly on the Vault Entry room
 * Shaydz
 * Started :4/30/01 11:19AM
 */

#include <money.h>

inherit ROOM_OBJ;

#define PTS proprietor->the_short()
#define TIME_LIMIT 500

string location,hall_room;
int visit_cost;
object proprietor;

/**
 * This function is used to set the location used for calculation of which
 * currency the vault proprietor will accept.
 * @param location The name of the location.
 */
void set_location(string str) { location = str; }

/**
 * This is used to set the cost of a visit to the vault (in monetary units)
 * @param cost The cost of a vist
 */
void set_visit_cost(int i) { visit_cost = i; }

/**
 * This is the object that is the proprietor of the vault. This should be an
 * NPC.
 * @param proprietor The proprietor NPC object.
 */
void set_proprietor(object ob) { proprietor = ob; }

/**
 * Used to set the exit from this entrance room into the training hall itself.
 * The parameters are just like those of add_exit.
 * @param direction The direction of the exit.
 * @param dest The destination object. Usually the filename of the destination.
 * @param type An exit type as in add_exit.
 * @return void
 * @see add_exit
 */
void set_hall_exit(string direc, mixed dest, string type) {
  hall_room = dest;
  add_exit(direc, dest, type);
  modify_exit( direc, ({ "function", "check_customer" }) );
  modify_exit( direc, ({ "closed", 1}));
}


/**
 * @ignore yes
 *
 * Internal function to check if this player is a customer
 */
int check_customer( string verb, object thing, string special ) {

  if(!proprietor || environment(proprietor) != TO)
    return notify_fail("This training hall is closed since the proprietor is "
                       "missing.\n");


  if ( (int)thing->query_value_in( location ) +
       (int)thing->query_value_in( "default" ) < visit_cost ) {
    tell_object( thing, PTS+" intercepts you.\n" );
    tell_room( TO, PTS+" intercepts "+
               (string)thing->the_short() +".\n",
               thing );

    proprietor->do_command("say It costs "+
                           (string)MONEY_HAND->money_value_string( visit_cost,
                                                                   location ) +
                           " to use the facility!\n" );
    return notify_fail( "" );
  }

  thing->pay_money((mixed *)MONEY_HAND->create_money_array(visit_cost,
                                                           location),
                   location);
  tell_object( thing, "You pay "+PTS+" who waves you through.\n" );
  tell_room( TO, (string)thing->the_short() +
             " pays "+PTS+" who waves "+ (string)thing->query_objective() +
             " through.\n", thing );

  return 1;
} /* check_customer() */
