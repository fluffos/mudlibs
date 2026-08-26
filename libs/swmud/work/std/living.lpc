#include <flags.h>
#include <log.h>

inherit CONTAINER;
inherit __DIR__ "living/alignment";
inherit __DIR__ "living/grammar";
inherit __DIR__ "living/handedness";
inherit __DIR__ "living/levels";
inherit __DIR__ "living/messages";
inherit __DIR__ "living/misc";

// This is a pure 'living' object, not what is traditionally meant by a living object
// on LPmuds.  Note that find_living() won't necessarily find it b/c the driver may not
// even know it's alive.  (Why the driver keeps track of livings is beyond me ...)
// [ed note: it doesn't any more; find_living() doesn't exist]
// This is an object than can hold things and do actions.  If you want it to be able
// to fight, inherit MONSTER instead.

int assign_flag(int, int);
int test_flag(int);

private string name;
private nosave string race = "human";

void mudlib_setup()
{
   ::mudlib_setup();
   // We always should have an 'in' relation in living objects.
   // This takes care of capacity too
   add_relation("on", 100);
   set_default_relation("on");
   set_def_msgs("living-default");
   assign_flag(F_FORCE_SENSITIVE, 1);
}

string query_name()
{
   if (strlen(name))
   {
      return name;
   }

   return this_object()->query_primary_id();
}

void set_name(string new_name)
{
   if (name) { remove_id(lower_case(new_name)); }

   name = new_name;

   if (wizardp(this_user()) && this_object()->is_body()
      && (this_user()->query_userid() != lower_case(query_name())))
   {
      LOG_D->log(LOG_SETNAME, sprintf("%O used set_name() on %O (%s)\n", this_user(),
         this_object(), query_name()));
   }

   add_id_no_plural(lower_case(new_name));
}

void set_race(string value)
{
   if (!this_object()->is_body() && strlen(value))
   {
      race = value;
   }

   if (race == "yuuzhan vong")
   {
      assign_flag(F_FORCE_SENSITIVE, 0);
   }
}

string query_race()
{
   return race;
}

string in_room_desc()
{
   return query_in_room_desc();
}

string inventory_header()
{
   foreach (object thing in all_inventory(this_object()))
   {
      if (thing->is_visible())
      {
         return "\n" + capitalize(query_subjective()) + " is carrying:";
      }
   }

   return "";
}

string introduce_contents()
{
   return inventory_header();
}

string invis_name()
{
   return "someone";
}

int is_living()
{
   if (this_object()->is_droid())
   {
      return 0;
   }

   return 1;
}

int can_feel_force()
{
   if (test_flag(F_FORCE_SENSITIVE) && !this_object()->is_droid()
      && !this_object()->has_buff("/d/buffs/sever_force"))
   {
      return !environment()->is_force_blocked();
   }

   return 0;
}

object has_effect(string type)
{
   foreach (object thing in all_inventory(this_object()))
   {
      if (thing->query_effect_name() == type)
      {
         return thing;
      }
   }

   return 0;
}

// This returns an action, so that spells can modify the perspective. i.e:
// You sense: Beek is dead.  Other than that, things are going well for him.
string diagnose()
{
   return "$N $vare in perfect health.\n";
}

// verb interaction
mixed direct_cross_obj(object ob)
{
   return "I don't think " + ob->the_short() + " would appreciate that.\n";
}

// Default behavior.  Livings that want to behave differently should override this.
mixed indirect_give_obj_to_liv(object ob, object liv)
{
   return capitalize(liv->the_short()) + " politely refuses.\n";
}

mixed direct_get_obj(object ob)
{
   if (ob == this_body()) { return "#You find your presence uplifting.\n"; }

   return "#If you want to pick up another person, try using your social skills.\n";
}

mixed direct_whisper_liv_str() { return 1; }
mixed direct_whisper_str_to_liv() { return 1; }
mixed direct_whisper_to_liv_str() { return 1; }

// m_conversation will override
void begin_conversation()
{
   tell(this_user(), "%^TELL%^" + capitalize(query_name()) + " tells you:%^RESET%^ I don't have anything to say to you.\n");
}

string look_in(string relation)
{
   // only trap "in", since you may want something to be behind/on/under a living

   if (relation == "in") { return "With your X-Ray vision?"; }
   else { return ::look_in(relation); }
}

string query_possessive() { return grammar::query_possessive(); }

int query_encumbrance()
{
   this_object()->refresh_stats();

   return to_int(floor((this_body()->query_capacity() * 100) / this_body()->query_max_capacity()));
}