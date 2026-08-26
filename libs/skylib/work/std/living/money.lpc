/**
 * This file has all the functions to deal with living objects and
 * money.
 * @author Pinkfish
 * @see /obj/money.c
 * @see /handlers/money_handler.c
 */

#include <money.h>

/**
 * This method returns the money object for the player.  If the force
 * flag is set then the object will be created if it does not
 * exist.
 * @param force make the money object exist
 */
object query_money_object(int force) {
   object money;

   money = present( MONEY_ALIAS, this_object() );
   if (!money && force) {
      money = clone_object( MONEY_OBJECT );
      money->move( this_object() );
   }
   return money;
} /* query_money_object() */

/**
 * Adds an amount of money in the roundest amount of change to
 * the living.
 * @param amt the amount of money to add
 * @param location the area to use for the currency
 * @return integer success
 */
varargs int add_currency(int amt, string location) {
  if(!location) location = "default";
  if(amt < 1) return 0;
  return !MONEY_H->make_new_amount(amt, location)->move(TO);
} /* add_currency() */

/**
 * This method adjusts the amount of money the player has.
 * It redirects the call off the the money object and calls the
 * adjust_money() function on it.  The amount can be a money
 * array, in which case it will adjust the size by the members
 * of the money array.
 * <p>If the money object doesn't exist yet, this function
 * might create a new money object.  The exception is that if
 * the amount argument is 0, nothing happens.
 * @see /obj/money->adjust_money()
 * @param amount the amount to adjust the money by
 * @param type the type of coin to adjust
 */
varargs void adjust_money( mixed amount, string type ) {
   if (!amount) return;
   if (!intp(amount) && !arrayp(amount)) {
     error("Received a non-integer value in adjust_money()!\n");
     return 0;
   }
   if(!stringp(type)){
     error("No string type in adjust_money()!\n");
     return 0;
   }
   if(!MONEY_H->query_value_of(type)){
     error(sprintf("Bad type of coins in adjust_money():%s\n",type));
     return 0;
   }
   query_money_object( 1 )->adjust_money( amount, type );
} /* adjust_money() */

/**
 * This method returns the money array associated with the money on
 * the player object.
 * @return the money array on the player object
 * @see set_money_array()
 */
mixed *query_money_array() {
   return query_money_object(1)->query_money_array();
} /* query_money_array() */

/**
 * This method sets the money array associated with the player.   THis
 * will overwrite any current money on the player.
 * @param new_array the new money array for the player
 * @see query_money_array()
 */
void set_money_array( mixed *new_array ) {
   query_money_object(1)->set_money_array( new_array );
} /* set_money_array() */

/**
 * This method returns the value of the money as an integer.  This is
 * an absolute value of their worth.
 * @return an integer value of their money
 * @see query_value_in()
 */
int query_value() {
   object money;

   money = query_money_object(0);
   if ( ! money ) {
      return 0;
   }
   return money->query_value_in();
} /* query_value() */

/**
 * This method returns the value of the money as in integer in the specified
 * place.
 * @param where the place in which to determine the money from
 * @return the integer value of money
 * @see query_value()
 * @see query_money()
 */
int query_value_in( string where ) {
   object money;

   money = query_money_object(0);
   if ( ! money ) {
      return 0;
   }
   return (int)money->query_value_in( where );
} /* query_value_in() */

/**
 * This method returns all of the money of a certain type on the
 * money object.
 * @param type the type of money to return
 * @return the number of those money items
 * @see query_value()
 * @see query_value_in()
 */
int query_money( string type ) {
   object money;

   money = query_money_object(0);
   if ( ! money ) {
      return 0;
   }
   return (int)money->query_money( type );
} /* query_money() */

/**
 * This method makes the player make a payment.  This is used for
 * shops and things.
 * @param m_array the money to pay
 * @param where the money area to make the payment in
 * @see /handlers/money_handler->make_payment()
 */
varargs void pay_money( mixed m_array, string where ) {
   int i, j;
   object money;
   mixed *p_array;

   money = query_money_object(0);
   if ( !money ) {
      return;
   }
   for ( i = 0; i < sizeof( m_array ); i += 2 ) {
      p_array = (mixed *)MONEY_HAND->make_payment( m_array[ i ],
         m_array[ i + 1 ], money, where );
      if ( !pointerp( p_array ) ) {
         continue;
      }
      if ( sizeof( p_array[ 1 ] ) ) {
         money->adjust_money( p_array[ 1 ] );
      }
      for ( j = 0; j < sizeof( p_array[ 0 ] ); j += 2 ) {
         money->adjust_money( - p_array[ 0 ][ j + 1 ], p_array[ 0 ][ j ] );
      }
   }
} /* pay_money() */
