// Last edited by deforce on 09-28-2008
// Transient effects inheritable for diseases, intoxication, etc...
// Created by Midhir@Mutants and Machinery on 07-15-1997
inherit OBJ;
inherit M_GETTABLE;

int effect_duration = 1;
int effect_delay = 1;
int delay_count = 1;
int effect_type;
string effect_name;

int is_transient_effect() { return 1; }

//:FUNCTION another_effect_exists
// Passed the object of the existing effect, used to perform extra
// functionality if another effect with the same type/name exists.
void another_effect_exists(object ob)
{
   ob->add_effect_duration(effect_duration);
   destruct(this_object());
}

//:FUNCTION set_effect_duration
// Set the duration of the effect in number of heart_beats
void set_effect_duration(int duration)
{
   effect_duration = duration;
}

int query_effect_duration()
{
   return effect_duration;
}

void add_effect_duration(int duration)
{
   effect_duration += duration;

   if (!query_heart_beat())
   {
      set_heart_beat(1);
   }
}

//:FUNCTION set_effect_delay
// Set the delay of the effect in number of heart_beats
void set_effect_delay(int d)
{
   effect_delay = d;
}

int query_effect_delay()
{
   return effect_delay;
}

//:FUNCTION set_effect_type
// Set the string type of effect this is, used to make sure only
// one object of each type is in one inventory.
void set_effect_type(int t)
{
   effect_type = t;
}

int query_effect_type()
{
   return effect_type;
}

//:FUNCTION set_effect_name
// Sets the string name of the effect, this isn't currently used for
// anything, but could be used for more descriptive names than set_effect_type.
void set_effect_name(string n)
{
   effect_name = n;
}

string query_effect_name() { return effect_name; }

//:FUNCTION do_effect
// overload this function to create effects.
// The first argument is the object being afflicted.
void do_effect(object affected) {}

int check_for_existing()
{
   foreach (object ob in all_inventory(environment()))
   {
      if ((ob != this_object()) && ob->is_transient_effect() && (this_object()->query_unique_id() > ob->query_unique_id()) && (ob->query_effect_type() == effect_type) && (ob->query_effect_name() == effect_name))
      {
         ob->transfer_to_existing_effect(this_object());

//         tell(environment(), "Transferring new effect from " + file_name() + " to " + file_name(ob) + "\n");

         return 1;
      }
   }

   return 0;
}

void heart_beat()
{
   if (!environment() || !environment()->is_living() || check_for_existing())
   {
      destruct(this_object());
   }

   set_heart_beat(1);

   if (delay_count >= effect_delay)
   {
      do_effect(environment());
      delay_count = 0;
      effect_duration--;
   }

   if (effect_duration <= 0) 
   {
      set_heart_beat(0);
   }

   delay_count++;
}

void mudlib_setup()
{
   set_attached(1);
   add_save(({ "effect_duration", "effect_type", "effect_name", "effect_delay", "delay_count" }));
   set_heart_beat(1);
}

varargs mixed move(object dest, string where)
{
   set_heart_beat(1);
   return ::move(dest, where);
}