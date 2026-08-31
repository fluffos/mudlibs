/* Do not remove the headers from this file! see /USAGE for more info. */
// Modified by Uae.  May 23rd 1997.
// Functionality added to deal with renewable drink
// sources like pools.  If the source has "<fluid>_source"
// in its id, it will be considered to be a source of
// that fluid.  Drink_it() here will call drink_from() in the
// fluid source.

private
int drinks_per_unit = 2;
private
int drinks_current_unit;
private
int num_drinks = 2;

private
mixed taste_action = "Your thirst is quenched.";
private
mixed drink_action = "$N $vdrink some $o.";
private
mixed last_drink_action = "$N $vfinish off the $o.";
private
int poison_strength;

object drink_source; //

string the_short();
string query_primary_id();
float query_mass();
void set_weight(float x);
void set_quantity(int x);
void remove();

//: FUNCTION set_taste_action
// set_taste_action( mixed x )
// Put this function in the drinkable
// fluid.  'x' is evaluated when the
// fluid is drunk.  By default it is
// a my_action, but it could be a
// function or an *of mixed.
// To have no taste action, pass a
// zero.
void set_taste_action(mixed x)
{
   taste_action = x;
}

mixed get_taste_action()
{
   return taste_action;
}

int query_drinks_current_unit()
{
   return drinks_current_unit;
}

//: FUNCTION set_poisonous
// void set_poisonous(int p)
// Sets the level of poison in this edible thing.
// 0 means non-poisonous, 100 means deadly.
void set_poisonous(int p)
{
   poison_strength = p;
}

int query_poisonous()
{
   return poison_strength;
}

//: FUNCTION set_drink_action
// set_drink_action( mixed x )
// Put this function in the drinkable
// fluid.  'x' is evaluated when the
// fluid is drunk.  By default it is
// a simple_action, but it could be a
// function or an *of mixed.
// To have no drink action, pass a
// zero.
void set_drink_action(mixed action)
{
   drink_action = action;
}

//: FUNCTION set_last_drink_action
// Just like set_drink_action, but only is used for the last drink.
void set_last_drink_action(mixed action)
{
   last_drink_action = action;
}

//: FUNCTION set_num_drinks
// set_num_drinks( int x )
// This sets the number of drinks per 1 size-unit.
// The default is 3;
void set_num_drinks(int x)
{
   drinks_per_unit = to_int(x);
}

// Not necessary, but kept for possible special effects.
// Actually, this doesn't appear to be used at all.
void set_drink_source(string source)
{
   drink_source = load_object(source);
}

int calculate_num_drinks()
{
   num_drinks = to_int((query_mass() < 1 ? 1 : query_mass()) * drinks_per_unit + drinks_current_unit);
   return num_drinks;
}

void reduce_drink_number()
{

   drinks_current_unit--;
   if (!drinks_current_unit)
   {
      drinks_current_unit = drinks_per_unit;
      set_weight(query_mass());
      set_quantity(query_mass());
   };
   calculate_num_drinks();
   if (!num_drinks)
      remove();
}

varargs void drink_it(object drinkee)
{ // This is called by the verb.

   mixed action;
   object source;

   if (!drinkee)
      drinkee = this_body();

   if (query_poisonous())
   {
      object p = new ("/std/transient/poison", query_poisonous(), query_poisonous(),
                      "$N $vbend over in pain. Must be something $n drank.")
                     ->move(drinkee);
   }

   // Are we in the presence of the source?
   source = present(query_primary_id() + "_source");

   if (source)
      if (source->id("drink_source"))
      {
         source->drink_from_it();
         return;
      }

   if (num_drinks == 1 && last_drink_action)
      action = last_drink_action;
   else
      action = drink_action;

   if (arrayp(action))
      action = choice(action);

   if (functionp(action))
      evaluate(action);
   else
      drinkee->simple_action(action, this_object());

   if (taste_action && num_drinks != 1)
   {
      action = taste_action;
      if (arrayp(action))
         action = choice(action);
      if (functionp(action))
         evaluate(action);
      else
         drinkee->my_action(action, this_object());
   };

   // These two are call_others to avoid a hard dependency between
   // M_DRINKABLE and M_HEALING.
   if (this_object()->query_heal_value())
   {
      this_object()->heal_from_drink();
   }

   reduce_drink_number();
}

//: FUNCTION query_num_drinks
// returns the number of drinks left in the drink.
int query_num_drinks()
{
   calculate_num_drinks();
   return num_drinks;
}

mixed direct_drink_obj()
{
   if (environment(this_object()) == environment(this_body()))
   {
      return 0;
   }

   // Must be inside something in our inventory or directly in our inventory.
   if (environment(environment(this_object())) != this_body() && environment(this_object()) != this_body())
   {
      return 0;
   }
   calculate_num_drinks();
   if (!num_drinks)
      return capitalize(the_short()) + " is gone.\n";

   return 1;
}

mixed direct_drink_obj_from_obj()
{
   return direct_drink_obj();
}
