/* Do not remove the headers from this file! see /USAGE for more info. */

#include <combat_modules.h>

#define STUN_FROM_PERCENT 40

inherit __DIR__ "class_" STRINGIZE(BLOW_MODULE);

private
nosave int natural_armour = 0;
nosave string *resistances = ({});
nosave string *vulnerabilities = ({});
varargs int hurt_us(int, string);
varargs void attacked_by(object, int);
string query_random_limb();
void handle_message(string, object, object, string);
string damage_message(int);
void add_experience(int);
object *query_targets();
object query_weapon();
varargs void unwield(string);
object *event_get_armours(class event_info);

void gmcp_send_vitals()
{
   // Do nothing in adversary. Real function for players is in body.
}

//: FUNCTION query_natural_armour
// int query_natural_armour()
// Returns the natural armour automatically reduces the amount of damage taken.
int query_natural_armour()
{
   return natural_armour;
}

//: FUNCTION set_natural_armour
// void set_natural_armour(int na)
// Natural armour automatically reduces the amount of damage taken.
void set_natural_armour(int na)
{
   if (na > 0)
      natural_armour = na;
}

//: FUNCTION query_resistances
// string *query_resistances()
// A string array of damage type this adversary is reistant to.
string *query_resistances()
{
   return resistances;
}

//: FUNCTION query_vulnerabilities
// string *query_vulnerabilities()
// A string array of damage type this adversary is vulnerable to.
string *query_vulnerabilities()
{
   return vulnerabilities;
}

//: FUNCTION add_resistance
// void add_resistance(string r)
// Add a resistance damage type for this adversary.
void add_resistance(string r)
{
   resistances += ({r});
}

void add_vulnerability(string v)
{
   vulnerabilities += ({v});
}

class event_info modify_resistances(class event_info evt)
{
   foreach (string r in resistances)
   {
      if (member_array(r, evt.data[0]) != -1)
      {
         evt->data[sizeof(evt.data) - 1] = evt->data[sizeof(evt.data) - 1] / 2;
         return evt;
      }
   }
   return evt;
}

class event_info modify_vulnerabilities(class event_info evt)
{
   foreach (string v in vulnerabilities)
   {
      if (member_array(v, evt.data[0]) != -1)
      {
         //      TBUG(this_object() + " vulnerable to " + v + ".");
         evt->data[sizeof(evt.data) - 1] = evt->data[sizeof(evt.data) - 1] * 2;
         return evt;
      }
   }
   return evt;
}

// Modify us (as attacker). Include things such as racial modifiers,
// resistances, etc.
class event_info modify_our_event(class event_info evt)
{
   if (!arrayp(evt.data))
      return evt;

   if (objectp(evt.target))
   {
      object t = evt.target;
      evt = t->modify_resistances(evt);
      evt = t->modify_vulnerabilities(evt);
   }
   return evt;
}

class event_info health_modify_event(class event_info evt)
{
   if (stringp(evt.data))
      return evt;

   if (natural_armour)
   {
      evt.data[1] -= random(natural_armour);
      if (evt.data[1] < 0)
         evt.data[1] = 0;
   }

   return evt;
}

class event_info armours_modify_event(class event_info evt)
{
   object *armours = event_get_armours(evt);

   // TBUG(armours);
   if (armours)
      foreach (object ob in armours)
         if (ob)
            evt = ob->sink_modify_event(evt);
   return evt;
}

// This is the method that gets called in the target object. Before
// the event does any damage to us, make modifications.
class event_info modify_event(class event_info evt)
{
   evt = health_modify_event(evt);
   evt = armours_modify_event(evt);

   return evt;
}

int do_damage_event(class event_info evt)
{
   int x;
   if (evt.data != "miss")
   {
      x = hurt_us(event_damage(evt), evt.target_extra);
   }
   if (member_array(previous_object(), query_targets()) == -1)
      attacked_by(previous_object(), 0);
   return x;
}

void disarm_weapon(object w, object target)
{
   w->do_remove();
   w->drop();
   w->move(environment());
   target->disarm(w);
}

void handle_result(class event_info evt)
{
   object w;

   // Debug combat events
   // TBUG(event_to_str(evt));
   if (evt.target && evt->target->query_ghost())
      return;

   if (stringp(evt.data))
   {
      handle_message("!" + evt.data, evt.target, evt.weapon, evt.target_extra);

      switch (evt.data)
      {
      case "fatal":
         evt->target->kill_us();
         break;
      case "disarm":
         w = evt->target->query_weapon();
         disarm_weapon(w, evt.target);
         break;
      case "miss":
         evt->target->do_damage_event(evt);
         break;
      }
   }
   else
   {
      int percent = event_damage(evt);

      // Do not message without a target or if the target is a ghost.
      if (evt.target && !evt->target->query_ghost())
      {
         // TBUG(event_to_str(evt));
         // TBUG("handle_message %" + percent + " Msg: " + damage_message(percent) + " Target: " + evt.target + "
         // Weapon: " + evt.weapon + " Extra: " + evt.target_extra);
         percent = to_int(percent / (1.0 * evt->target->query_max_health(evt.target_extra)) * 100);

         // Stun code
         if (percent >= STUN_FROM_PERCENT)
         {
            int stun_chance = percent - STUN_FROM_PERCENT;
            // TBUG("Chance of stun is " + stun_chance + " percent!");
            if (random(60) < stun_chance)
            {
               // TBUG("STUN happened!");
               evt->target->stun(evt.target_extra, stun_chance);
            }
         }

         handle_message(damage_message(percent), evt.target, evt.weapon, evt.target_extra);
         percent = evt->target->do_damage_event(evt);
      }
   }
}

void handle_events()
{
   int i = 0;

   /* walking over the queue is slightly more efficient than deleting the
    first element each time, causing them all to have to move */
   while (i < sizeof(queue))
   {
      queue[i] = modify_our_event(queue[i]);
      if (!queue[i])
      {
         i++;
         continue;
      }
      if (queue[i].weapon)
      {
         queue[i] = queue[i]->weapon->source_modify_event(queue[i]);
         if (!queue[i])
         {
            i++;
            continue;
         }
      }
      if (queue[i].target)
         queue[i] = queue[i]->target->modify_event(queue[i]);
      if (!queue[i])
      {
         i++;
         continue;
      }

      handle_result(queue[i]);
      i++;
   }

   queue = ({});
}
