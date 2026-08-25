/* Do not remove the headers from this file! see /USAGE for more info. */

#include <drunk.h>

int query_ghost();
void simple_action(string msg, mixed *obs...);
varargs void filtered_simple_action(mixed msg, function filter, mixed extra, mixed *obs...);
varargs int test_skill(string skill, int opposing_skill, int no_learn);
string *query_vital_limbs();
string *query_mobile_limbs();
string *query_wielding_limbs();
int message_filter(object who, mixed extra);
int do_unwield(string);
int query_drunk_percent();
int query_level();
int cached_skill_rank(string s);
int should_cap_skill(string skillname);

private
nosave int stunned; // time to awake from stunned status
private
nosave int prone; // 1 if prone
private
int asleep; // flag for "asleep" status
private
nosave int chance; // counter for attempted "wake up"
private
nosave int attack_speed = 1;
private
nosave object *readied = ({}); // *of ready ammunition

void add_readied(object ob)
{
   readied -= ({ob});
   readied += ({ob});
   readied -= ({0});
}

void remove_readied(object ob)
{
   readied -= ({ob});
}

object *query_readied()
{
   return copy(readied);
}

int query_attack_speed()
{
   return attack_speed;
}

int lie_down()
{
   if (!prone)
   {
      prone = 1;
      return 1;
   }
   return 0;
}

int query_stunned()
{
   if (stunned > time())
      return 1;
   return 0;
}

int stand_up()
{
   if (prone && !query_stunned())
   {
      prone = 0;
      return 1;
   }
   return 0;
}

int query_prone()
{
   return prone;
}

int query_asleep()
{
   return asleep;
}

void stun(string limb, int period)
{
   int stance_impact = 1;
   string drunk_action;
   int train_limit = should_cap_skill("combat/defense/stance");
   period = CLAMP(period, 5, 30);

   switch (query_drunk_percent())
   {
   case 0..29:
      break;
   case 30..49:
      stance_impact = STANCE_IMPACT_AT_30;
      drunk_action = "$P $vare %^COMBAT_CONDITION%^tipsy%^RESET%^ so $p reflexes fail $n.";
      break;
   case 50..79:
      stance_impact = STANCE_IMPACT_AT_30;
      drunk_action = "$P $vare %^COMBAT_CONDITION%^drunk%^RESET%^ and $n can barely stand.";
      break;
   default:
      stance_impact = STANCE_IMPACT_AT_80;
      drunk_action = "$P $vare in a %^COMBAT_CONDITION%^drunken stupor%^RESET%^ fighting cross-eyed.";
      break;
   }

   // Vital limbs
   if (member_array(limb, query_vital_limbs()) != -1)
   {
      if (!test_skill("combat/defense/stance", period * 10 * stance_impact, train_limit))
      {
         if (drunk_action)
            simple_action(drunk_action, limb);
         simple_action("$N $vare %^COMBAT_CONDITION%^stunned%^RESET%^ by a hit to $p $o!", limb);

         stunned = time() + period;
         prone = 1;
      }
      else
      {
         simple_action("$N $vare %^COMBAT_CONDITION%^stunned%^RESET%^ and almost $vtopple over.");
         stunned = time() + (period / 2);
      }
   }
   // Wielding limbs
   else if (member_array(limb, query_wielding_limbs()) != -1)
   {
      if (!test_skill("combat/defense/disarm", period * 5, train_limit))
      {
         filtered_simple_action("$P $o $vare stunned.", ( : message_filter:), "simple_stun", limb);

         do_unwield(limb);
      }
      else
      {
         filtered_simple_action("$P $o is stunned but $n $vretain contol.", ( : message_filter:), "simple_stun", limb);
      }
   }
   // Mobile limbs
   else if (member_array(limb, query_mobile_limbs()) != -1)
   {
      if (!test_skill("combat/defense/stance", period * 10 * stance_impact, train_limit))
      {
         filtered_simple_action("$P $o $vare stunned and $n $vfall to the ground.",
                                (
                                    : message_filter:),
                                "simple_stun", limb);
         prone = 1;
      }
      else
      {
         filtered_simple_action("$P $o $vare stunned, $n $vstagger but $vremain standing.",
                                (
                                    : message_filter:),
                                "simple_stun", limb);
      }
   }
}

string conditionString()
{
   string *condi = ({});
   if (query_stunned())
      condi += ({"stunned"});
   if (query_asleep())
      condi += ({"asleep"});
   if (query_drunk_percent() > SHOW_IN_ROOM)
      condi += ({"drunk"});
   if (query_prone())
      condi += ({"prone"});

   if (sizeof(condi))
      return " [%^COMBAT_CONDITION%^" + format_list(condi) + "%^RESET%^]";
   return "";
}

void wake_up()
{
   if (asleep)
   {
      asleep = 0;
      stun("vital", 5);
   }
}

void knock_out()
{
   asleep = 1;
   chance = 0;
}

mixed check_condition(int urgent)
{
   if (query_ghost())
   {
      stunned = 0;
      asleep = 0;
      return 0;
   }

   if (urgent && prone)
      return "$N $vare %^COMBAT_CONDITION%^prone%^RESET%^, ";

   if (urgent && stunned > time())
      return "$N $vare %^COMBAT_CONDITION%^stunned%^RESET%^, ";

   if (asleep)
   {
      if (urgent)
      {
         if (random(5) <= chance++)
         {
            wake_up();
         }
         else
         {
            return "$N $vtry desperately to wake up, but $vfail.\n";
         }
      }
      else
      {
         return "But $n $vare asleep!\n";
      }
   }

   return 0;
}
