/** \note Average nutritional values for food will be:
 * 1 - piece of candy
 * 8 - tiny piece of fruit (2 grapes, 1 cherry, or half of a plum)
 * 25 - normal piece of fruit (apple or orange)
 * 50 - small meal-type item (sandwich, potato)
 * 150 - large meal-type item (steak, loaf of bread)
 * \note For food with special effects (diku based muds call them pills)
 * such as stat bonuses, spells, poison, or anything other than simply
 * increasing food/drink levels on the player... you will need to write an
 * on_consume function on the individual food object, as the eat and
 * drink verbs will attempt to call it. Note that the default_consume
 * function is provided to allow you to easily incorporate default
 * consumption behavior when writing your own on_consume.
 *
 * Update:
 *     Food items now can have buffing effects that are applied to the
 *     consumer for a given number of hunger ticks. The variables buff
 *     and buff_time are used to define these features.
 *
 *     Example: buff = ([ "str": +2, "int": -1 ])
 *              buff_time = 3
 *
 *              This will produce an item of food that increases the user's
 *              strength at the cost of intelligence for roughly 3 food ticks
 *
 *     - Al [ Oct 7, 05 ]
 */

/// Can this item be eaten? 1 - yes, 0 - no
int edible;
/// Can this item be drunk? 1 - yes, 0 - no
int drinkable;
/// How much hunger does this item heal when consumed?
int food_value;
/// How much thirst does this item heal when consumed?
int drink_value;
/// Message displayed when the item is consumed.
string use_msg;

/// (De)buffing effects that this food has when consumed
mapping buff;
/// How long does the buff last? (in hunger ticks)
int buff_time;

/// This function is for keeping objedit happy
string edible_info() {
  return "edible\ndrinkable\nfood_value\ndrink_value\nuse_msg";
}

/// \return True if this item is edible.
int query_is_edible()       { return edible; }
/// \return True if this item is drinkable.
int query_is_drinkable()    { return drinkable; }
/// \return Amount of hunger healed by consuming this item.
int query_food_value()   {
	if( !food_value )
		return this_object()->query_default_food_value();
	return food_value;
}
/// \return Amount of thirst healed by consuming this item.
int query_drink_value()  {
	if( !drink_value )
		return this_object()->query_default_drink_value();
	return drink_value;
}
/// \return The message displayed when this item is consumed.
string query_use_msg()   { return use_msg; }

/// Set whether or not this item may be eaten.
void set_edible(int x)        { edible = x; }
/// Set whether or not this item may be drunk.
void set_drinkable(int x)     { drinkable = x; }
/// Set how much hunger this item heals.
void set_food_value(int x)    { food_value = x; }
/// Set how much thirst this item heals.
void set_drink_value(int x)   { drink_value = x; }
/// Set the message displayed when this item is consumed.
void set_use_msg(string x)    { use_msg = x; }

/// \return The buffing effects of this item of food
mapping query_buff() {
	if( !buff )
		return this_object()->query_default_buff();
	return buff;
}
/// \return The duration of this buff
int query_buff_time() {
	if( !buff_time )
		return this_object()->query_default_buff_time();
	return buff_time;
}
/// Set the buffing effects
void set_buff(mapping m) { buff = m; }
/// Set the buff duration
void set_buff_time(int x) { buff_time = x; }

/** This function sets up some generic defaults for an item of food, might want to
 * get rid of it later on, but it is convenient for now.
 */
int defaults() {
  this_object()->set_name("food");
  this_object()->set_look("This is a piece of food.");
  this_object()->set_distant("some food");
  this_object()->set_plural("foods");
  this_object()->set_gettable(1);
  set_edible(1);
  set_food_value(10);
  set_use_msg("~Name ~verbeat ~targ.");
  return 1;
}

int take_damage(mixed x) {
  // Eventually make food take damage when abused... :P But for now, I
  // will just destroy the object... :)

  call_out("decay",1,this_object()->query_cap_name()+" is destroyed!");
  return 1;

//  int total;
//  if (mappingp(x))
//  else if (intp(x)
}

void decay(string message) {
  object where = environment(this_object());
  if (where->query_is_living())
    where = environment(where);
  tell_room(where,message+"\n");
  destruct(this_object());
}

/** This will make building a custom on_consume easier; just call
 * this function, and add any extra behavior you want. Pass the flag
 * 0x1, and no messages will be printed. You can also pass 0x2 to have
 * the object not destruct. Example usage:
 *
 * int on_consume(int max) { default_consume(max); return 1; }
 *
 * int on_consume(int max) { if(default_consume(max,2)) destruct(this_object()); return 1; }
 *
 * Note that default_consume returns 1 if something was eaten,
 * 0 on failure. The only failure condition is being too full
 * to eat anything.
 */
varargs int default_consume( int max, int flag ) {
   string m;
   int quant;

   quant = this_object()->query_quantity();
   if( !quant ) quant = 1;
   if( quant * max(this_object()->query_food_value(),
      this_object()->query_drink_value()) > max ) {
      if( this_object()->query_food_value() )
         quant = max / this_object()->query_food_value();
      if( this_object()->query_drink_value() )
         quant = min( quant, max / this_object()->query_drink_value() );
      if( quant == 0 ) {
         if( !(flag&0x1) )
            msg("You are too full!");
         return 0;
      }
   }
   if( quant < this_object()->query_quantity() )
      this_object()->split_quantity(quant);
   this_player()->add_food( this_object()->query_food_value() * quant );
   this_player()->add_drink( this_object()->query_drink_value() * quant );
   if( !(flag&0x1) ) {
      m = this_object()->query_use_msg();
      if( !m ) m = "~CACT~Name ~verbeat ~targ.~CDEF";
      else m = "~CACT" + m + "~CDEF";
      set_target(this_object());
      this_player()->msg_local( m );
   }

   // apply buffage
   if( this_object()->query_buff() ) {
      object buff_ob = present_clone("/obj/foodbuff", this_player());
      mapping map = this_object()->query_buff();
      string stat;
	  if( !buff_ob ) {
         buff_ob = clone_object("/obj/foodbuff");
         buff_ob->move(this_player());
      }
      foreach( stat : m_indices(map) ) {
         buff_ob->add_affect( this_object()->query_specific(), stat, map[stat] );
      }
      buff_ob->add_time( this_object()->query_specific(), this_object()->query_buff_time() );
	  // apply stat bonuses
	  this_player()->recalc();
   }

   if( !(flag&0x2) ) {
      destruct( this_object() );
   }
   return 1;
}
