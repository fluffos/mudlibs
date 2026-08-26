/**
 * This class contains information relating to the value and the weight
 * of the object.
 * @author Pinkfish
 */

#include <money.h>
#include <move_failures.h>

#define WATCH_DEFINE "fluff'n'stuff"
#define PRICE_INDEX "/handlers/cpi_handler"

inherit "/std/basic/light";
inherit "/std/basic/move";

nosave int weight;
nosave int value;
nosave mapping value_info;

void check_log_status( object *parray );

void create() {
    weight = 1;
    light::create();
    call_out( "check_log_status", 1, previous_object(-1) );
    value_info = ([ ]);
} /* create() */

/**
 * This method adjusts the weight by the given amount.
 * @param w the amount to change the weight by
 * @see set_weight()
 * @see query_weight()
 */
void adjust_weight(int w) {
    if( environment() )
        environment()->add_weight(w);
    weight += w;
} /* adjust_weight() */

/**
 * This method sets the weight of the object.  One weight unit
 * is 50 grams.
 * <p>
 * When setting the weights of weapons use the following guide:
 * <p>
 * o===================o=====================o================o<br>
 * | Weapon            | Approx. Weight (kg) |  Weight Units  |<br>
 * o===================o=====================o================o<br>
 * | Dagger            |        0.5          |       10       |<br>
 * | War Hammer        |        1.1          |       22       |<br>
 * | Mace              |        1.3          |       26       |<br>
 * | Flail             |        1.5          |       30       |<br>
 * | Pole Axe          |        2.3          |       46       |<br>
 * | Short Sword       |        0.8          |       16       |<br>
 * | Broad Sword       |        1.1          |       22       |<br>
 * | Long Sword        |        1.4          |       28       |<br>
 * | Bastard Sword     |        1.9          |       38       |<br>
 * | Two-handed Sword  |        2.7          |       42       |<br>
 * o===================o=====================o================o<br>
 * @param w the amount to change the weight by
 * @see adjust_weight()
 * @see query_weight()
 */
void set_weight(int w) {
    if( environment() )
        environment()->add_weight( w - weight );
    weight = w;
} /* set_weight() */

/**
 * This method returns the current weight of the object.
 * @return the current weight of the object
 * @see set_weight()
 * @see adjust_weight()
 */
int query_weight() { return weight; }
/**
 * This method returns the current weight of the object. It does basicly
 * the same thing as the previous call.  NB: TO->query_weight()
 * is pretty much the same as query_weight(), except it takes shadows into
 * account.
 * @return the current weight of the object
 * @see set_weight()
 * @see adjust_weight()
 * @see query_weight()
 */
int query_complete_weight() { return (int)TO->query_weight(); }

/**
 * This method changes the value of the object by a certain number of
 * coins.  The coins can be any type.
 * @see /handlers/money_handler->query_total_value()
 * @see adjust_value()
 * @see query_money_array()
 * @see set_value()
 * @return the new value
 */
varargs int adjust_money(mixed amt, string coin) {
    if( pointerp(amt) ) {
        value += (int)MONEY_HAND->query_total_value(amt);
        if( value < 0 )
            value = 0;
        return value;
    }
    amt = (int)MONEY_HAND->query_total_value( ({ coin, amt }) );
    value += amt;
    if( value < 0 )
        value = 0;
    return value;
} /* adjust_money() */

/**
 * This method changes the current value of the object.
 * @param i the amount to change the value by
 * @return the new value of the object
 */
int adjust_value(int i) {
    value += i;
    return value;
} /* adjust_value() */

/**
 * This method returns the value of the object as a money array.  The
 * money array is a list oif coinages followed by a number of coins.
 * Eg: <code>({ "copper", 10, "silver", 12 }).</code>
 * @see /handlers/money_handlers->create_money_array()
 * @see set_value()
 * @see adjust_value()
 * @see adjust_money()
 * @see query_value()
 */
mixed query_money_array() {
    return (mixed)MONEY_HAND->create_money_array(value);
} /* query_money_array() */

/**
 * This method returns the number of coins of a certain
 * type that are in the value of the object.  This is not
 * a good estimate of value or anything, no idea why it is
 * here really.  I am sure I had a good reason
 * at the time :)
 * @param type the type of coin to look for
 * @return the number of coins of that type
 * @see /handlers/money_handlers->create_money_array()
 * @see set_value()
 * @see adjust_value()
 * @see adjust money()
 * @see query_money_array()
 * @see query_value()
 */
int query_money( string type ) {
    int i;
    mixed m_a;

    m_a = (mixed *)MONEY_HAND->create_money_array(value);
    if( ( i = member_array( type, m_a ) ) == -1 )
        return 0;
    return m_a[i+1];
} /* query_money() */

/**
 * This method sets the value of the object.  The actual value in
 * coins and so forth is worked out by the money handler based on the
 * value.
 * @param number the new value of the object
 * @see query_value()
 * @see adjust_value()
 * @see query_money_array()
 */
void set_value( int number ) { value = number; }

/**
 * This method sets the value information for a type of
 * special object.  This is the extra value information associated
 * with the "artifact", "enchantment" or "material" of the object.
 * @param word the type of value information
 * @param number the amount to set it to
 * @see query_value_at()
 * @see remove_value_info()
 * @see set_value()
 */
void set_value_info( string word, int number ) {
    value_info[ word ] = number;
} /* set_value_info */

/**
 * This method removes the value information for a type of
 * special object.  This is the extra value information associated
 * with the "artifact", "enchantment" or "material" of the object.
 * @param word the type of value information to remove
 * @see query_value_at()
 * @see set_value_info()
 * @see set_value()
 */
void remove_value_info( string word ) {
    map_delete( value_info, word );
} /* remove_value_info() */

/**
 * This method returns the current value of the object.
 * @return the current value of the object
 */
int query_value() { return value; }

/**
 * This method returns the vase value of the object.  This is before
 * any scaling from things like condition occurs.
 * @return the base value
 */
int query_base_value() {
   return value;
} /* query_base_value() */

/**
 * This method returns the information associated for all the special
 * bits of the object.  The value infor maping ihas keys which are
 * the type of value info and the value is the value of it.
 * @return the value info mapping
 * @see set_value_info()
 * @see query_value_at()
 * @see remove_value_info()
 */
mapping query_value_info() { return value_info; }

/**
 * This method figures out how much an object will cost in a certain
 * place.  For instance at a shop that does not handle artifcacts an
 * artifact will be bought and sold cheaply.  The current types
 * of "artifact", "enchantment" and "material" are recognised.
 * A property in the shop of the type "artifact valued" will
 * cause the values of that type to be taken into account.
 * @param place the object to find the value at
 * @return the value in the shop
 * @see query_value()
 * @see set_value_info()
 * @see adjust_value()
 */
int query_value_at( object place ) {
    int total;
    string _key;
    mixed how, _value;

    if( !value_info )
        value_info = ([ ]);

    total = (int)TO->query_value();

    foreach( _key, _value in value_info ) {
      how = (mixed)place->query_property( _key +" valued" );
      if( how ) {
          switch( _key ) {
            case "artifact" :
              total += ( _value * ( how[ 0 ] + how[ 1 ] *
                       (int)TO->query_charges() ) ) / how[ 2 ];
            break;
            case "enchantment" :
              if( TO->query_max_enchant() )
                  total += ( _value * how * (int)TO->query_enchant() ) /
                           (int)TO->query_max_enchant();
            break;
            case "material" :
              total += (int)TO->query_weight() *
                       (int)PRICE_INDEX->query_price(
                       (string)TO->query_material(), how );
            break;
            default :
              total += _value;
          }
      }
    }

    return total;

} /* query_value_at() */

/**
 * This method always returns the most expensive value of an item.
 * This should be used for things like theif quotas and anything which
 * requires the real actual value of an item.
 * @param place the place to find the values in
 */
int query_value_real(string place) {
   int total;
   string _key;
   mixed _value;

   if( !value_info )
       value_info = ([ ]);

   total = (int)TO->query_value();

   foreach( _key, _value in value_info ) {
      switch( _key ) {
        case "artifact" :
          total += ( _value * ( 3 + 1 * (int)TO->query_charges() ) ) / 1;
        break;
        case "enchantment" :
          if( TO->query_max_enchant() )
              total += ( _value * 10 * (int)TO->query_enchant() ) /
                       (int)TO->query_max_enchant();
        break;
        case "material" :
          total += (int)TO->query_weight() *
                   (int)PRICE_INDEX->query_price(
                   (string)TO->query_material(), place );
        break;
        default :
          total += _value;
      }
   }
   return total;
} /* query_value_real() */

/** @ignore yes */
varargs int move( mixed dest, string messin, string messout ) {
  int i, w;
  object from;

  if( stringp(dest) )
      dest = load_object(dest);

  if( !dest )
      return MOVE_INVALID_DEST;

  w = (int)TO->query_complete_weight();

  if( !( dest->add_weight(w) ) )
      return MOVE_TOO_HEAVY;

  from = environment();

  if( ( i = ::move( dest, messin, messout ) ) != MOVE_OK ) {
      dest->add_weight(-w);
      return i;
  }

  if( from )
      from->add_weight(-w);

  if( query_light_needs_inform() ) {
      if( from )
          inform_of_light_level_change( from );
      inform_of_light_level_change( dest );
  }

  return i;

} /* move() */

/** @ignore yes */
void dest_me() {
    if( environment() ) {
        environment()->add_weight( -(int)TO->query_complete_weight() );
        if( query_my_light() )
            adjust_light( -query_my_light() );
    }
    ::dest_me();
} /* dest_me() */

/** @ignore yes */
mixed *stats() {
    string _key;
    mixed tmp, _value;

    tmp = ({ ({ "value", value }) });

    if( !value_info )
        value_info = ([ ]);

    foreach( _key, _value in value_info )
        tmp += ({ ({ "(info) "+ _key, _value }) });

    return light::stats() + tmp;

} /* stats() */

/** @ignore yes */
void check_log_status( object *parray ) {
  if( TO->query_property( WATCH_DEFINE ) && clonep( TO ) &&
      arrayp( parray ) && member_array(
      load_object( "/secure/cmds/creator/cl_one" ), parray ) != -1 ) {
      log_file( "WATCH", "DS: %d TO: %s. TP: %s.\n", time(),
      base_name( TO ), parray[2]->query_name() );
      TO->add_property( "CT", time() );
      user_event( "inform", sprintf( "[Restricted] %s cloned %s.",
                  parray[2]->query_cap_name(),
      base_name( TO ) ), "cheat" );
  }
} /* check_log_status() */
