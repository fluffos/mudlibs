/* Do not remove the headers from this file! see /USAGE for more info. */

#include <behaviour.h>

// Associations towards other livings

void add_child(string node, string child);
varargs void create_node(int type, string name, mixed offspring);
void set_blackboard(string key, mixed value);
void del_blackboard(string key);
mixed blackboard(string key);
void do_game_command(string str);
int has_room_changed();
void room_checked();
void mod_emotion(mixed emotion, int mod);
void set_emotion(mixed emotion, int mod);
object *arrived();
object *left();

private
mapping assoc = ([]);

// The init function *must* create a node that is adds to the root sequence,
// e.g.
//    create_node(NODE_SEQUENCE, "my_seq", ({"step1", "step2"}));
//    add_child("root_sequence", "my_seq");
// The root of the tree contains the "root_sequence" that is run at the top of
// the tree.
void init_association_cluster()
{
   // Add nodes
   create_node(NODE_SEQUENCE, "association_seq", ({"look_around", "own_status", "study_beings"}));
   add_child("root_sequence", "association_seq");
   create_node(NODE_LEAF, "look_around");
   create_node(NODE_LEAF, "study_beings");
   create_node(NODE_LEAF, "own_status");
}

string attitude_to_string(int a)
{
   switch (a)
   {
   case 2:
      return "<190>Friendly<res";
   case 1:
      return "<190>Positive<res";
   case 0:
      return "<190>Indifferent<res";
   case -1:
      return "<190>Suspicious<res";
   case -2:
      return "<190>Hostile<res";
   }
}

mapping query_assoc()
{
   return assoc;
}

// Threat level <0 are threats, >0 = likely not threats
void recalc_threat_level(object ob)
{
   int level_diff = ob->query_level() - this_object()->query_level();

   // This handles if attitude is positive, we treat them as non-threats even
   // if higher levels. It's called trust.
   assoc[ob]["threat_level"] = assoc[ob]["attitude"] > 0 ? abs(level_diff) : level_diff * assoc[ob]["attitude"];
}

object *worst_threats()
{
   if (!sizeof(keys(assoc)))
      return ({});
   return sort_array(keys(assoc), ( : assoc[$1]["threat_level"] :));
}

object *worst_threats_present()
{
   return filter(worst_threats(), ( : present($1, environment()) :));
}

void register_beings(object *obs)
{
   foreach (object ob in obs)
   {
      // Things we only evaluate first time we meet.
      if (!assoc[ob])
      {
         assoc[ob] = ([]);
         assoc[ob]["attitude"] = this_object()->association_for(ob);
         assoc[ob]["level"] = ob->query_level();
         recalc_threat_level(ob);
      }

      // Things we evaluate every time.

      // Are we being attacked by this person?
      if (sizeof(this_object()->query_targets()) && this_object()->query_targets()[0] != 0 &&
          member_array(ob, this_object()->query_targets()) != -1)
      {
         // We were on good terms??
         if (assoc[ob]["attitude"] >= 0)
            mod_emotion(AMAZEMENT, assoc[ob]["attitude"]);
         // I knew he would attack...
         else if (assoc[ob]["attitude"] < 0)
         {
            mod_emotion(VIGILANCE, abs(assoc[ob]["attitude"]));
            mod_emotion(RAGE, 1);
         }

         if (abs(assoc[ob]["threat_level"]) < -20)
         {
            mod_emotion(TERROR, 3);
         }
         else if (abs(assoc[ob]["threat_level"]) < -10)
         {
            mod_emotion(TERROR, 2);
         }
         else if (abs(assoc[ob]["threat_level"]) < -5)
         {
            mod_emotion(TERROR, 1);
         }
         else if (abs(assoc[ob]["threat_level"]) > 10)
         {
            mod_emotion(VIGILANCE, 2);
         }
         else if (abs(assoc[ob]["threat_level"]) > 20)
         {
            mod_emotion(VIGILANCE, 3);
            mod_emotion(ECSTASY, 2);
         }

         // Reevaluate threat_level
         assoc[ob]["attitude"] = HOSTILE;
         recalc_threat_level(ob);
      }
   }
}

void i_met(object who)
{
   TBUG(who);
}

int attitude(object ob)
{
   // We don't know this person.
   if (!assoc[ob])
      return INDIFFERENT;
   return assoc[ob]["attitude"];
}

// Default behavior.  Livings that want to behave differently should
// override this.
mixed indirect_give_obj_to_liv(object ob, object liv)
{
   if (attitude(ob) == HOSTILE)
      return capitalize(liv->the_short()) + " refuses.\n";
   return 1;
}

void clean_assoc()
{
   assoc = filter_mapping(assoc, ( : $1:));
}

varargs void threat_emotions(object *people, int left)
{
   int total_threat = 0;
   foreach (object p in people)
   {
      if (assoc[p])
         total_threat += assoc[p]["threat_level"];
   }
   total_threat = clamp(total_threat, -1000, 1000);
   if (left)
      total_threat = total_threat * -1;

   switch (total_threat)
   {
   case -1000.. - 20:
      mod_emotion(TERROR, 3);
      break;
   case -19.. - 10:
      mod_emotion(TERROR, 2);
      break;
   case -9.. - 1:
      mod_emotion(TERROR, 1);
      break;
   case 0..10:
      mod_emotion(TERROR, -1);
      break;
   case 11..50:
      mod_emotion(TERROR, -2);
      mod_emotion(ADMIRATION, 1);
      break;
   case 51..1000:
      mod_emotion(TERROR, -3);
      mod_emotion(ADMIRATION, 2);
      break;
   }
}

int own_status()
{
#ifdef HEALTH_USES_LIMBS
   // Limbs code
   mixed *worst_vital = this_object()->query_worst_limb(1);
   mixed *worst_limb = this_object()->query_worst_limb();
   if (worst_vital[0] != "none")
      set_blackboard("worst_vital_limb", worst_vital);
   else
      del_blackboard("worst_vital_limb");
   if (worst_limb[0] != "none")
      set_blackboard("worst_limb", worst_limb);
   else
      del_blackboard("worst_limb");
#else
   // Non limbs
   int hp, max_hp;
   hp = this_object()->query_health();
   max_hp = this_object()->query_max_health();
   set_blackboard("health", (100 * hp) / max_hp);
#endif
   return EVAL_SUCCESS;
}

int study_beings()
{
   object *things = all_inventory(environment()) - ({this_object()});
   object *beings, *new_people, *leavers;

   if (!environment())
      return EVAL_FAILURE;

   clean_assoc();

   // If room is the same and we're not in combat, exit here.
   if (!has_room_changed() && !this_object()->is_attacking())
      return EVAL_SUCCESS;

   beings = filter_array(things, ( : $1->is_living() && environment($1) == environment() :));
   new_people = arrived();
   leavers = left();

   // Do we have new people?
   if (sizeof(new_people))
   {
      threat_emotions(new_people);
   }
   // Someone left?
   if (sizeof(leavers))
   {
      threat_emotions(leavers, 1);
   }
   // Are we alone? :(
   if (!sizeof(beings))
   {
      this_object()->alone();
      mod_emotion(LOATHING, 1);
   }
   else
   {
      mod_emotion(LOATHING, 0);
   }

   // Tell them that we noticed that they arrived.
   if (sizeof(new_people) == 1)
      do_game_command("look at " + new_people[0]->query_id()[0]);

   register_beings(beings);
   set_blackboard("environment", things - blackboard("exits") - blackboard("gettable") - beings);
   room_checked();

   return EVAL_SUCCESS;
}

int look_around()
{
   object *things = all_inventory(environment()) - ({this_object()});
   if (!environment())
      return EVAL_FAILURE;
   if (!has_room_changed())
      return EVAL_SUCCESS;
   if (!blackboard("beings"))
      set_blackboard("beings", ({}));

   set_blackboard("gettable", filter_array(things, ( : $1->is_gettable() :)));
   set_blackboard("exits", filter_array(things, ( : $1->id("door") :)));
   set_blackboard("environment", things - blackboard("exits") - blackboard("gettable") - blackboard("beings"));
   return EVAL_SUCCESS;
}

string association_features()
{
   return "<045>Association:\n<res>" + "\t- Relations to other beings\n" + "\t- Basic emotion settings\n" +
          "\t- Assessing threats\n" + "\t- Assess own status\n\n";
}