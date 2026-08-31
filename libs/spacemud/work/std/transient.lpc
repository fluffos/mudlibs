/* Do not remove the headers from this file! see /USAGE for more info. */

/*
 *
 *  Transient effects inheritable for diseases, intoxication, etc...
 *  Midhir@Mutants and Machinery <July 15 1997>
 *  Tsath@LIMA Rebean extended and enhanced, July 2023.
 */

#include <hooks.h>

inherit OBJ;
inherit M_GETTABLE;
inherit M_STATEFUL;
inherit CLASS_EVENT_INFO;

private
int effect_duration;
private
string effect_type;
private
string effect_name;
private
int can_extend = 1;

int is_transient_effect()
{
   return 1;
}

int query_can_extend()
{
   return can_extend;
}

void cannot_extend()
{
   can_extend = 0;
}

//: HOOK another_effect_exists
// Passed the object of the existing effect, used to perform extra
// functionality if another effect with the same type/name exists.
void another_effect_exists(object ob)
{
   ob->add_effect_duration(effect_duration);
   this_object()->remove();
}

//: FUNCTION set_effect_duration
// Set the duration of the effect in number of heart_beats
void set_effect_duration(int d)
{
   effect_duration = d;
}
int query_effect_duration()
{
   return effect_duration;
}
void add_effect_duration(int d)
{
   effect_duration += d;
}

//: FUNCTION set_effect_type
// Set the string type of effect this is, used to make sure only
// one object of each type is in one inventory.
void set_effect_type(string t)
{
   effect_type = t;
}
string query_effect_type()
{
   return effect_type;
}

//: FUNCTION set_effect_name
// Sets the string name of the effect, this isn't currently used for
// anything, but could be used for more descriptive names than set_effect_type.
void set_effect_name(string n)
{
   effect_name = n;
}
string query_effect_name()
{
   return effect_name;
}

//: FUNCTION do_effect
// overload this function to create effects.
// The first argument is the object being afflicted.
void do_effect(object affected)
{
}

int state_update()
{
   do_effect(environment());
   if (effect_duration <= 0)
   {
      this_object()->remove();
   }
   effect_duration--;
   return 1;
}

void mudlib_setup()
{
   m_stateful::mudlib_setup();
   set_attached(1);
   add_save(({"effect_duration"}));
}

void extend_effect(object t)
{
   if (t)
   {
      add_effect_duration(t->query_effect_duration());
      t->remove();
   }
}

class event_info effect_modify_event(class event_info evt)
{
   // Override in effects to impact combat event.
   return evt;
}

varargs mixed move(object dest, string where)
{
   //No magic things, the objects cannot be collapsed into one.
   if (!can_extend)
      return ::move(dest, where);
   
   //Collapse more effects into a stronger effect
   foreach (object ob in all_inventory(dest))
   {
      if (!ob->is_transient_effect())
         continue;

      if (ob->query_effect_type() == effect_type && ob->query_effect_name() == effect_name)
      {
         ob->extend_effect(this_object());
         return;
      }
      continue;
   }
   return ::move(dest, where);
}
