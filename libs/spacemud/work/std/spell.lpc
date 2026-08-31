/* Do not remove the headers from this file! see /USAGE for more info. */

// T: You need some variables to hold all these:
/*
    What are the things that all spells/abilities have in common
    - Name - string?
    - reflex Cost - cost how? int?
    - Damage Type - string that can be verified towards DAMAGE_D?  query_valid_damage_type(string str)
    - Casting type - int ? Perhaps spell.h to define different casting types?
    - Skills used - string?
    - Components - mapping perhaps? (["black powder":2,"piece of rope":1]) ? So you could specify how
                   much is used?
    - target - int ? perhaps also target types defined in spell.h? TARGET_LIVING TARGET_ITEM etc?
                     So let the spell specify what type of target it expects?
*/

// T: Materials: Could it be the ones also used for crafting? I think two different material sets
//    might be a bit much for  a MUD?
//  When on lima calls:
//  @CRAFTING_D->query_material_categories()
//  Then for each of those do:
//  @CRAFTING_D->query_materials("textile") e.g.
//
//  Further categories and materials could easily be added, like a magical category etc.
//  I'm just mindfil to keep LIMA somewhat generic so it can be spun into Rifts, DND and a sci-fi MUD.

#include <assert.h>
#include <spells.h>

private
nosave string spell_name;
private
nosave string spell_category;
private
nosave int reflex_cost = 1;
private
nosave int cast_time;
private
nosave int level = 1;
private
nosave string skill_used;
private
nosave string magic_skill_used;
private
nosave int channeling;
private
nosave int channeling_interval;
private
nosave int valid_targets;
private
nosave string description;

mapping spell_components = ([]);

void do_effects(object target, object sc);

void create()
{
   this_object()->setup();
}

//: FUNCTION set_category
// Sets the category of the spell.
// Parameters:
// - c: The category of the spell.
protected
void set_category(string c)
{
   spell_category = c;
}

//: FUNCTION query_category
// Returns the category of the spell.
string query_category()
{
   return spell_category;
}

//: FUNCTION set_level
// Sets the level of the spell.
// Parameters:
// - l: The level of the spell.
protected
void set_level(int l)
{
   level = l;
}

//: FUNCTION query_level
// Returns the level of the spell.
int query_level()
{
   return level;
}

//: FUNCTION set_name
// Sets the name of the spell.
// Parameters:
// - s: The name of the spell.
protected
void set_name(string s)
{
   spell_name = s;
}

//: FUNCTION query_name
// Returns the name of the spell.
string query_name()
{
   return spell_name;
}

//: FUNCTION extra_reflex_cost
// Sets the extra reflex cost of the spell. A spell
// always costs level + reflex_cost to cast.
// Parameters:
// - c: The reflex cost of the spell.
protected
void extra_reflex_cost(int c)
{
   ASSERT(c > 0);
   reflex_cost = c;
}

int is_channeled()
{
   return channeling_interval > 0;
}

//: FUNCTION query_reflex_cost
// Returns the reflex cost of the spell.
int query_reflex_cost()
{
   return reflex_cost + level;
}

//: FUNCTION check_reflex
// Checks if the caster has enough reflex to cast the spell.
// Parameters:
// - b: The caster object.
// Returns: 1 if the caster has enough reflex, 0 otherwise.
protected
int check_reflex(object b)
{
   return b->query_reflex() >= query_reflex_cost();
}

//: FUNCTION spend_reflex
// Spends the reflex cost for casting the spell.
// Parameters:
// - b: The caster object.
// Returns: 1 if the reflex cost was successfully spent, 0 otherwise.
protected
int spend_reflex(object b)
{
   return b->use_reflex(query_reflex_cost());
}

//: FUNCTION valid_target
// Checks if the target is valid for the spell.
// Parameters:
// - target: The target object.
// Returns: 1 if the target is valid, 0 otherwise.
protected
mixed valid_target(object target)
{
   // No rules defined, so any target is valid
   if (!valid_targets)
      return 1;

   // If rooms are valid targets, and we have no target
   // then we can cast the spell.
   if (valid_targets & TARGET_ROOM && !target)
      return 1;

   // If living targets are valid, and the target is a living
   // we can cast the spell.
   if (valid_targets & TARGET_LIVING && target->is_living())
      return 1;

   // If item targets are valid, and the target is an item
   // we can cast the spell.
   if (valid_targets & TARGET_ITEM && !target->is_living())
      return 1;

   // If self is a valid target, and the target is the caster
   // we can cast the spell.
   if (valid_targets & TARGET_SELF && target == this_body())
      return 1;

   return 0;
}

//: FUNCTION valid_spell_components
// Checks if the spell components are valid.
// Parameters:
// - sc: The spell components mapping.
// Returns: 1 if the spell components are valid, 0 otherwise.
protected
mixed valid_spell_components(mapping sc)
{
   /*DEFAULT: if there is a spell component, then it cant be used*/
   if (sc)
   {
      return 0;
   }
   return 1;
}

//: FUNCTION valid_circumstances
// Checks if the circumstances are valid for casting the spell.
// Parameters:
// - target: The target object.
// - sc: The spell components mapping.
// Returns: 1 if the circumstances are valid, 0 otherwise.
protected
mixed valid_circumstances(mixed target, mixed sc)
{
   return 1;
}

//: FUNCTION check_valid_spell
// Checks if the spell is valid to cast.
// Parameters:
// - has_target: 1 if the spell has a target, 0 otherwise.
// - has_sc: 1 if the spell has spell components, 0 otherwise.
// Returns: 1 if the spell is valid to cast, an error message otherwise.
nomask mixed check_valid_spell(int has_target, int has_sc)
{
   // Did we define only specific valid targets?
   // Do we not have a target? Then we need to have TARGET_ROOM
   // defined as a valid target.
   if (valid_targets && !has_target)
      return valid_targets & TARGET_ROOM ? 1 : "The spell requires a target.";

   return valid_circumstances(has_target, has_sc);
}

//: FUNCTION set_targets
// Sets the valid targets for the spell.
// Parameters:
// - targets: The valid targets for the spell.
nomask void set_targets(int targets)
{
   valid_targets = targets;
}

//: FUNCTION check_valid_target
// Checks if the target is valid for the spell.
// Parameters:
// - target: The target object.
// - has_sc: 1 if the spell has spell components, 0 otherwise.
// Returns: 1 if the target is valid, an error message otherwise.
nomask mixed check_valid_target(object target, mixed has_sc)
{
   mixed result;

   result = valid_circumstances(target, has_sc);
   if (!result)
      return result;

   return valid_target(target);
}

//: FUNCTION check_valid_spell_components
// Checks if the spell components are valid for the spell.
// Parameters:
// - sc: The spell components mapping.
// - has_target: 1 if the spell has a target, 0 otherwise.
// Returns: 1 if the spell components are valid, an error message otherwise.
nomask mixed check_valid_spell_components(mapping sc, mixed has_target)
{
   mixed result;

   result = valid_circumstances(has_target, sc);
   if (!result)
      return result;

   return valid_spell_components(sc);
}

//: FUNCTION set_skill_used
// Sets the skill used for casting the spell.
// Parameters:
// - val: The skill used for casting the spell.
void set_skill_used(string val)
{
   skill_used = val;
}

//: FUNCTION query_skill_used
// Returns the skill used for casting the spell.
string query_skill_used()
{
   return skill_used;
}

//: FUNCTION set_magic_skill_used
// Sets the magic skill used for casting the spell.
// Parameters:
// - val: The magic skill used for casting the spell.
void set_magic_skill_used(string val)
{
   magic_skill_used = val;
}

//: FUNCTION query_magic_skill_used
// Returns the magic skill used for casting the spell.
string query_magic_skill_used()
{
   return magic_skill_used;
}

//: FUNCTION set_channeling_time
// Sets the channeling time for the spell.
// Parameters:
// - t: The channeling time in seconds.
void set_channeling_time(int t)
{
   ASSERT(t > 0);
   channeling = t;
}

//: FUNCTION set_channeling_interval
// Sets the interval between channeling actions for the spell.
// Parameters:
// - t: The interval time in seconds.
void set_channeling_interval(int t)
{
   ASSERT(t > 0);
   channeling_interval = t;
}

//: FUNCTION set_cast_time
// Sets the cast time for the spell.
// Parameters:
// - t: The cast time in seconds.
void set_cast_time(int t)
{
   ASSERT(t >= 0);
   cast_time = t;
}

//: FUNCTION query_cast_time
// Returns the cast time of the spell.
int query_cast_time()
{
   return cast_time;
}

//: FUNCTION delayed_cast_spell
// Initiates a delayed cast for the spell.
// Parameters:
// - target: The target object.
// - sc: The spell components object.
// - success: The success level of the spell casting.
nomask void delayed_cast_spell(object target, object sc, int success)
{
   this_body()->other_action("$N $vbegin casting a spell.");
   this_body()->busy_with(this_object(), (channeling_interval > 0 ? "channeling " : "casting ") + query_name(),
                          "cast_action", ({target, sc, success}), cast_time);
}

//: FUNCTION continue_channeling
// Continues the channeling of the spell.
// Parameters:
// - target: The target object.
// - sc: The spell components object.
void continue_channeling(object target, object sc)
{
   object caster = this_body();
   int channeling_level = clamp(level - 1, 0, 100);
   int success;

   if (!check_reflex(caster))
   {
      write("You cannot focus on casting spells right now.");
      return;
   }

   spend_reflex(caster);

   // We check for channeling_level which is one level lower than spell level, to make it easier
   // to channel the spell.
   if (!caster->test_skill("magic/technique/channeling", SKILL_D->pts_for_rank(channeling_level)))
   {
      write("You fail to continue channeling " + query_name() + ".");
      return;
   }

   // Safe to test this one, we already tested for it existing when loading the spell via SPELL_D.
   success = caster->test_skill("magic/" + spell_category + "/" + spell_name, SKILL_D->pts_for_rank(level));

   caster->busy_with(this_object(), (channeling_interval > 0 ? "channeling " : "casting ") + query_name(),
                     "cast_action", ({target, sc, success}), channeling_interval);
}

//: FUNCTION channel_failure
// Handles the failure of channeling the spell.
// Parameters:
// - message: The failure message.
void channel_failure(string message)
{
   write(message);
   channeling = 0;
}

//: FUNCTION cast_action
// Executes the casting action for the spell.
// Parameters:
// - args: An array containing the target, spell components, and success level.
int cast_action(mixed *args)
{
   int success;
   object target, sc;
   if (channeling_interval)
      channeling = 1;
   if (sizeof(args) != 3)
      return 0;
   target = args[0];
   sc = args[1];
   success = args[2];

   if (!target)
   {
      channel_failure("Your target has disappeared.");
      return;
   }

   // If we have a target, but it's not present in inventory or room, we can't cast the spell.
   if (!present(target, environment(this_body())) && !present(target, this_body()))
   {
      channel_failure("Your target has disappeared.");
      return;
   }

   this_object()->cast_spell(target, sc, success);
   if (channeling && channeling_interval)
      continue_channeling(target, sc);
   return 1;
}

//: FUNCTION transient
// Creates a transient spell object.
// Parameters:
// - name: The name of the transient spell.
// - args: Additional arguments for the transient spell.
// Returns: The created transient spell object.
object transient(string name, mixed *args...)
{
   object t = new ("/domains/std/spell/transient/" + replace_string(name, " ", "_"), args...);
   if (!t)
      error("Failed to load transient spell object.");
   return t;
}

//: FUNCTION test_spell
// Tests if the spell is fully defined and valid.
// Returns: 1 if the spell is valid, 0 otherwise.
int test_spell()
{
   if (!spell_name || !spell_category)
   {
      write("Spell not fully defined with name (" + spell_name + ") and category (" + spell_category + ").\n");
      return 0;
   }
   if (!SKILL_D->valid_skill("magic/" + spell_category + "/" + spell_name))
   {
      write("Undefined skill used for spell. Add 'magic/" + spell_category + "/" + spell_name + "' to SKILL_D.\n");
      return 0;
   }
   return 1;
}

//: FUNCTION internal_cast_spell
// Internally handles the casting of the spell.
// Parameters:
// - target: The target object.
// - sc: The spell components object.
void internal_cast_spell(object target, object sc)
{
   object caster = this_body();
   int success;

   if (!check_reflex(caster))
   {
      write("You cannot focus on casting spells right now.");
      return;
   }

   spend_reflex(caster);
   if (!caster->test_skill("magic/technique/casting", SKILL_D->pts_for_rank(level)))
   {
      write("You fail to cast the spell.");
      return;
   }

   // Safe to test this one, we already tested for it existing when loading the spell via SPELL_D.
   // Do not make skill checks against target here, as target may change on cast_spell() call.
   success = caster->test_skill("magic/" + spell_category + "/" + spell_name, SKILL_D->pts_for_rank(level));

   if (cast_time > 0)
      delayed_cast_spell(target, sc, success);
   else
      this_object()->cast_spell(target, sc, success);
}

//: FUNCTION set_description
// Sets the description of the spell.
// Parameters:
// - d: The description of the spell.
string set_description(string d)
{
   description = d;
}

//: FUNCTION target_to_str
// Converts the valid targets to a string representation.
// Returns: A comma separated string representation of the valid targets.
string target_to_str()
{
   string *targs = ({});

   if (!valid_targets)
      return "Flexible";

   if (valid_targets & TARGET_ROOM)
      targs += ({"Room"});
   if (valid_targets & TARGET_LIVING)
      targs += ({"Living"});
   if (valid_targets & TARGET_ITEM)
      targs += ({"Item"});
   if (valid_targets & TARGET_SELF)
      targs += ({"Self"});
   return format_list(targs);
}

int query_channeling_interval()
{
   return channeling_interval;
}

//: FUNCTION cast_time_string
// Converts the cast time to a string representation.
// Returns: A string representation of the cast time.
string cast_time_string()
{
   switch (query_cast_time())
   {
   case 0:
      return "Instant";
   case 1:
      return "Very fast";
   case 2..3:
      return "Fast";
   case 4..6:
      return "Moderate";
   case 7..9:
      return "Slow";
   default:
      return "Very slow";
   }
}

//: FUNCTION reflex_string
// Converts the reflex cost to a string representation.
// Returns: A string representation of the reflex cost.
string reflex_string()
{
   switch (reflex_cost)
   {
   case 0:
      return "Very low";
   case 1:
      return "Low";
   case 2:
      return "Moderate";
   case 3:
      return "High";
   default:
      return "Very high";
   }
}

//: FUNCTION spell_skill_rank
// Returns the skill rank for the spell.
// Parameters:
// - target: (optional) The target object to check the skill rank for. If not provided, defaults to this_body()
// (caster). Returns: The skill rank for the spell.
varargs int spell_skill_rank(object target)
{
   return SKILL_D->skill_rank(target || this_body(), "magic/" + spell_category + "/" + spell_name);
}

//: FUNCTION query_description
// Returns the description of the spell.
string query_description()
{
   int width = this_user()->query_screen_width();
   string desc = "<bld>Description<res>\n";
   desc += wrap(description || "(This spell is missing a description)", width - 20);
   desc += "\n\n";
   desc += sprintf("<bld>%10.10s:<res> %-10.10s<bld>%10.10s:<res> %-15.15s<bld>%10.10s:<res> %-10.10s\n", //
                   "Level", (query_level() ? query_level() + "" : "Cantrip"),                             //
                   "Category", capitalize(query_category()),                                              //
                   "Targets", target_to_str());
   desc += sprintf("<bld>%10.10s:<res> %-10.10s<bld>%10.10s:<res> %-15.15s\n", //
                   "Reflex", "" + reflex_string(),                             //
                   "Cast time", cast_time_string());                           //
   if (channeling_interval)
      desc += sprintf("<bld>%10.10s:<res> %-10.10s<bld>%10.10s:<res> %-15.15s\n", //
                      "Channeling", channeling_interval ? "Yes" : "No",           //
                      "Interval", channeling_interval + "s");                     //
   desc += "\n";
   desc += "<228>Example of use:<res>\n";
   if (valid_targets & TARGET_ROOM || !valid_targets)
      desc += "   cast " + query_name() + "\n";
   if (valid_targets & TARGET_LIVING || !valid_targets)
      desc += "   cast " + query_name() + " on <living>\n";
   if (valid_targets & TARGET_ITEM || !valid_targets)
      desc += "   cast " + query_name() + " on <item>\n";
   if (valid_targets & TARGET_SELF || !valid_targets)
      desc += "   cast " + query_name() + " on self\n";
   if (!query_level())
      desc += "\nTip: Cantrips are easy to cast, and a great way of training.";

   return desc;
}