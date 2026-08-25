/* Do not remove the headers from this file! see /USAGE for more info. */

inherit WEAPON;


private
nosave int counter;
private
nosave int time_to_load = 2;
private
nosave object ammo_ob;
private
nosave string *fire_type;
private
nosave string fire_mode = "single";
private
nosave int exertion_rating = 5;

private
string ammo_type = "";

int query_exertion_rating()
{
   return exertion_rating;
}

void set_exertion_rating(int er)
{
   exertion_rating = er;
}

string query_ammo_type()
{
   return ammo_type;
}

string *query_fire_type()
{
   return fire_type;
}

void set_fire_type(string ft...)
{
   // single, pump, semi, fully
   fire_type = flatten_array(ft);
   fire_mode = fire_type[0];
}

int set_fire_mode(string fm)
{
   if (member_array(fm, fire_type) == -1)
      return 0;
   fire_mode = fm;
   return 1;
}

string query_fire_mode()
{
   return fire_mode;
}

void set_ammo_type(string at)
{
   ammo_type = at;
}

int query_charges()
{
   if (ammo_ob && environment(ammo_ob) == environment(this_object()))
      return ammo_ob ? ammo_ob->query_charges() : 0;
   return 0;
}

// Treat as a loadable weapon for combat
// ie use the loaded ammunition for messaging etc
int query_loadable()
{
   return 1;
}

int query_loaded()
{
   return query_charges() > 0;
}

// Is it loaded ?
int query_time_to_load()
{
   return time_to_load;
}
void set_time_to_load(int t)
{
   time_to_load = t;
}

// Called when it is fired - ammunition is moved to firer's environment
// and ammunition records of weapon are updated
void discharge()
{
   counter = time_to_load;
}

mixed direct_fire_obj_at_liv(object ob, object liv)
{
   if (!query_loaded())
      return "Need to load it before you can fire it.";
   if (!sizeof(this_object()->query_wielding()))
      return "You need to wield it to fire it.";
   return 1;
}

void do_fire_at(object liv)
{
   if (sizeof(this_object()->query_wielding()))
      this_body()->start_fight(liv);
   else
   {
      write("You need to wield " + this_object()->the_short() + " to fire it.\n");
   }
}

int direct_load_obj_with_obj(object ob1, object ob2)
{
   return 1;
}

string evaluate_ammo(object ammo_ob)
{
   int left = ammo_ob->query_charges() * 100 / ammo_ob->query_max_charges();

   switch (left)
   {
   case 0:
      return "empty";
   case 1..10:
      return "almost empty";
   case 11..30:
      return "nearly empty";
   case 31..45:
      return "less than half full";
   case 46..55:
      return "about half full";
   case 56..65:
      return "more than half full";
   case 66..90:
      return "nearly full";
   case 91..99:
      return "almost fully loaded";
   case 100:
      return "fully loaded";
   }
}

string long_fire_mode(string fm)
{
   switch (fm)
   {
   case "semi":
      return "set to semi-automatic fire";
   case "fully":
      return "set to fully automatic fire";
   case "pump":
      return "pump action loaded";
   case "single":
      return "set to single round fire";
   }
}

void do_switch(string fm)
{
   fire_mode = fm;
   this_body()->simple_action("$N $vswitch $p $o to '$o1'.", this_object(), fm);
}

mixed direct_switch_obj_to_str(object ob, string str)
{
   if (fire_mode == lower_case(str))
      return "#The " + short() + " is already switched to '" + str + "'.";
   if (member_array(str, fire_type) == -1)
      return "#That " + short() + " can only switch to " + format_list(query_fire_type(), "or") + ".";
   return 1;
}

string get_extra_long()
{
   return ammo_ob
              ? "Ammo-wise the weapon is " + evaluate_ammo(ammo_ob) + " with " + query_ammo_type() + " rounds, "
              : "The weapon requires " + query_ammo_type() + " rounds, " + "and is " + long_fire_mode(fire_mode) + ".";
}

object loaded_with()
{
   return ammo_ob;
}

void do_load(object ammo)
{
   int ammo_charges = ammo->query_charges();
   if (!ammo_ob)
   {
      this_body()->simple_action("$N $vload the $o1 with $o2.", this_body(), this_object(), ammo);
      ammo_ob = ammo;
      ammo->do_ready();
      ammo->ammo_for(this_object());
   }
   else
   {
      this_body()->simple_action("$N $vcheck $p $o1 is loaded.", this_body(), this_object());
   }
}

void load(object ammo)
{
   counter--;
   if (counter < 1)
   {
      do_load(ammo);
   }
   else
   {
      this_body()->simple_action("$N $vcontinue to load the $o.", this_object());
   }
}
