/* Do not remove the headers from this file! see /USAGE for more info. */

private
int num_eats = 1;
private
int original_eats;
private
mixed eat_action = "$N $veat $o.";
private
mixed last_eat_action;
private
int poison_strength;

string the_short();
void add_save(string *);

void mudlib_setup()
{
   add_save(({"num_eats"}));
}

//: FUNCTION set_eat_action
// set_eat_action(string) causes 'string' to be printed when someone
// eats this object.  set_eat_action(function) causes the function
// to be called instead.
void set_eat_action(mixed action)
{
   eat_action = action;
}

//: FUNCTION set_last_eat_action
// Just like set_eat_action, but only is used for the last eat
void set_last_eat_action(mixed action)
{
   last_eat_action = action;
}

//: FUNCTION set_num_eats
// num_eats is the number of eats left before the object is empty.
void set_num_eats(int num)
{
   original_eats = num;
   num_eats = num;
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

int get_num_eats()
{
   return num_eats;
}

int query_num_eats()
{
   return get_num_eats();
}

int get_original_eats()
{
   return original_eats;
}

mixed direct_eat_obj()
{
   if (!num_eats)
      return capitalize(the_short()) + " is gone.\n";

   return 1;
}

varargs private eat_action(string action, object eater)
{
   if (stringp(action))
      eater->simple_action(action, this_object());
   else
      evaluate(action);

   // Hook into M_HEALING.
   if (query_heal_value())
   {
      heal_from_food();
   }
}

varargs void do_eat(object eater)
{
   mixed action;

   if (!eater)
      eater = this_body();

   if (query_poisonous())
   {
      object p = new ("/std/transient/poison", query_poisonous(), query_poisonous(),
                      "$N $vbend over in pain. Must be something $n ate.")
                     ->move(eater);
   }

   if (num_eats == 1)
   {
      if (last_eat_action)
         action = last_eat_action;
      else
         action = eat_action;
      if (stringp(action))
         eater->simple_action(action, this_object());
      else
         evaluate(action);

      this_object()->remove();
   }
   else
   {

      if (stringp(eat_action))
         eater->simple_action(eat_action, this_object());
      else
         evaluate(eat_action);
      eat_action(action, eater);

      num_eats--;
   }
}
