/**
 * Module to handle the amount of magical charge (enchantment) of an
 * object has.  The maximum enchantment of an item is determined by
 * by its weight - the material of composition is not yet taken into
 * account.
 * <p>
 * Enchanting an object will add to its value, and, if the object
 * is an item of armour, will improve its armour class.
 *
 * @change 20th May 1994 Deutha
 *    added a function to calculate the maximum
 *                 enchantment based on weight.
 * @author Pinkfish
 */
/*
 * DS History:
 * 3/8/1 Shiannar, changed messages, changed max enchant limit.
 */

nosave private int _enchanted;
nosave private int _set_enchant_time;

#define ENCHANT_DEGRADE_TIME (8 * 7 * 24 * 60 * 60)

/**
 * This method returns the maximum possible enchantment for the
 * object.  This used to be based on its weight, though now
 * is 100 so that we have a percentage rating.
 * @return the maximum enchantment
 */
int query_max_enchant() {
    return 100;
} /* query_max_enchant() */

/**
 * This method returns the current enchantment string for the object.  The
 * string is created from the percentage of the max enchantment that it is
 * enchanted to.  If the object is also a talisman, an identifying string is
 * appended to the enchantment message.
 * <p>
 * These messages are only visible to creators and players who can see
 * octarine.
 * <p>
 * If the property "octarine_mess" is set, then this will be printed instead
 * of the automatically generated enchantment message.
 * <p>
 * If the property "talisman_mess" is set, then this will be printed instead
 * of the automatically generated talisman message if appropriate.
 * @return the enchantment string and talisman string
 * @see set_enchant()
 * @see add_enchant()
 * @see query_max_enchant()
 * @see query_enchant()
 */
string enchant_string() {
    string tal_msg, ench_msg, *pl;

    if( TO->query_property( "talisman" ) ) {
        tal_msg = (string)TO->query_property( "talisman_mess" );
        if( !tal_msg )
            tal_msg = "It has the hazy magical sparkle of a magical talisman.";
        tal_msg += "\n";
    } else {
        tal_msg = "";
    }

    if( query_group(TO) )
        pl = ({"They ", ""});
    else
        pl = ({"It ", "s"});

    if( ench_msg = TO->query_property("octarine_mess") ) {
        ench_msg += "\n";
    } else {
        switch( ( TO->query_enchant() * 100 ) / TO->query_max_enchant() ) {
          case 1..10:
            ench_msg = pl[0]+"occasionally pulse"+pl[1]+" with magical "
                       "energy.\n";
          break;
          case 11..20:
            ench_msg = pl[0]+"emit"+pl[1]+" a slow other-worldly glow.\n";
          break;
          case 21..30:
            ench_msg = pl[0]+"softly pulse"+pl[1]+" with a dim magical "
                       "glow.\n";
          break;
          case 31..40:
            ench_msg = pl[0]+"emit"+pl[1]+" dim magical light in a steady "
                       "glow.\n";
          break;
          case 41..50:
            ench_msg = pl[0]+"give"+pl[1]+" off magical energy in a steady "
                       "glow.\n";
          break;
          case 51..60:
            ench_msg = pl[0]+"glow"+pl[1]+" with intense magical energy.\n";
          break;
          case 61..70:
            ench_msg = pl[0]+"emit"+pl[1]+" magical energy in a steady, "
                       "bright haze.\n";
          break;
          case 71..80:
            ench_msg = pl[0]+({"is", "are"})[query_group(TO)]+" filled with "
                       "bright, pulsing magical energy.\n";
          break;
          case 81..90:
            ench_msg = pl[0]+"glow"+pl[1]+" with bright magical energy.\n";
          break;
          case 91..100:
            ench_msg = pl[0]+"radiate"+pl[1]+" pure, strong, magical "
                       "energy.\n";
          break;
          default :
            ench_msg = "";
       }
    }

    return ench_msg + tal_msg;

} /* enchant_string() */

/**
 * This method sets the current enchantment level.   If it is greator than
 * the max enchantment level then it will be set to the maximum
 * enchantment level.
 * @param number the new enchantment level
 * @see enchant_string()
 * @see query_enchant()
 * @see query_max_enchant()
 * @see add_enchant()
 */
void set_enchant( int number ) {
   if( number > TO->query_max_enchant() )
       number = TO->query_max_enchant();
   _set_enchant_time = time();
   _enchanted = number;
} /* set_enchant() */

/**
 * This method changes the current enchanment level.
 * @param numnber the amount to chant the enchantment level by
 * @see enchant_string()
 * @see query_enchant()
 * @see set_enchant()
 * @see query_max_enchant()
 */
int add_enchant( int number ) {
   set_enchant( TO->query_enchant() + number );
   return _enchanted;
} /* add_enchant() */

/**
 * This method queries the current enchantment level.
 * @param number the new enchantment level
 * @see enchant_string()
 * @see set_enchant()
 * @see query_max_enchant()
 * @see add_enchant()
 */
int query_enchant() {
   int max;
   int tmp;
   int tmp2;

   max = TO->query_max_enchant();
   if( _enchanted > max )
       _enchanted = max;
   if( _enchanted > max / 2 ) {
      if( !_set_enchant_time )
          _set_enchant_time = time();
      if( time() - _set_enchant_time >= ENCHANT_DEGRADE_TIME ) {
          _enchanted = max / 2;
      } else {
          tmp2 = tmp = (_enchanted - ( max / 2 ) ) * 100 + 99;
          tmp *= 100 - ( ( ( time() - _set_enchant_time ) * 100 ) /
                         ENCHANT_DEGRADE_TIME );
          return ( max / 2 ) + ( tmp / 10000 );
      }
   }
   return _enchanted;
} /* query_enchant() */

/**
 * This method returns the actual enchant of the object.
 * @return the actual enchant value
 */
int query_real_enchant() { return _enchanted; }

/**
 * This method returns the time the time the enchantment was set.
 * @return the time the enchantment was set
 */
int query_enchant_set_time() { return _set_enchant_time; }

/**
 * This method sets the time at which the enchant level was set.
 * @param tim the time to set it to
 */
protected void set_enchant_set_time(int tim) { _set_enchant_time = tim; }
