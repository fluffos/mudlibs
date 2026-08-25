/* Do not remove the headers from this file! see /USAGE for more info. */

// limbs.c - Adversary module to control limb-based health. Body styles
//           are stored in /daemons/body_d.c.
//
// Tsath 2020: Extended with drunkenness

#include <limbs.h>

inherit CLASS_LIMB;
inherit __DIR__ "diagnose_msg";

void die();
varargs void simple_action(string, string);
varargs void filtered_simple_action(mixed msg, function filter, mixed extra, mixed *obs...);
void update_health();
void save_me();
int do_unwield(string);
int query_asleep();
int query_stunned();
int query_level();
int reflex_max();
varargs int xp_value(object);
int query_con();
varargs float query_capacity(string relation);
varargs int query_max_capacity(string relation);
int query_no_move_capacity();
int query_prone();
int message_filter(object who, mixed extra);
void set_reflex(int mp);
void set_max_health(int);
int karma_impact();
int should_cap_skill(string skillname);
varargs int test_skill(string skill, int opposing_skill, int no_learn);

private
nosave string body_style = "humanoid";
private
nosave mapping limb_sizes;
private
mapping health = BODY_D->get_body("humanoid");
private
nosave int health_time = time();
private
int heal_rate = 15;
private
int sober_rate = 30;
private
int dead = 0;
private
int drunk = 0; // 0: Sober
private
int abuse = 0; // 0: New born
private
int reflex = 0;
private
int reflex_rate = 30;

private
nosave int hp_cap;

//: FUNCTION query_drunk
// Returns the points of drunkeness currently held by this adversary.
// See also set_drunk(int).
int query_drunk()
{
   return drunk;
}

//: FUNCTION query_max_drunk()
// The maximum level of drunk points this adversary can hold. This increases
// with level and constitution stat score.
int query_max_drunk()
{
   return 20 + query_level() + query_con();
}

//: FUNCTION query_abuse
// Returns the abuse points held by this adversary.
int query_abuse()
{
   return abuse;
}

//: FUNCTION query_max_abuse
// Returns the maximum abuse points held by this adversary before they die
// permanently.
int query_max_abuse()
{
   return 1000 + (10 * query_level() + 5 * query_con());
}

//: FUNCTION query_abuse_percent
// Returns the abuse percentage.
int query_abuse_percent()
{
   return CLAMP((100 * abuse) / query_max_abuse(), 0, 100);
}

//: FUNCTION abuse_body
// Abuse this adversary for a number of points. These are hard to get
// rid of so use sparringly.
int abuse_body(int a)
{
   int cap_skill = should_cap_skill("misc/life/endocrines");
   if (test_skill("misc/life/endocrines", a, cap_skill))
   {
      abuse += to_int(a / 2);
   }
   else
      abuse += a;
   return 1;
}

int remove_abuse(int a)
{
   int cap_skill = should_cap_skill("misc/life/endocrines");
   if (test_skill("misc/life/endocrines", a, cap_skill))
      abuse += to_int(a * 2);
   else
      abuse -= a;

   if (abuse < 0)
      abuse = 0;
   return 1;
}

//: FUNCTION set_drunk
// Set a drunk level at a specific point. This is useful for adversaries
// you want to exhibit drunk behavior.
void set_drunk(int d)
{
   drunk = CLAMP(d, 0, query_max_drunk());
}

//: FUNCTION drink_alchohol
// Drink alchohol and add 'd' to the drunk level.
int drink_alchohol(int d)
{
   int cap_skill = should_cap_skill("misc/life/boozing");
   if (test_skill("misc/life/boozing", d, cap_skill))
   {
      drunk += to_int(d / 2);
   }
   else
      drunk += d;
}

//: FUNCTION query_drunk_percent
// Returns the drunk level in percent.
int query_drunk_percent()
{
   return (100 * drunk) / query_max_drunk();
}

//: FUNCTION drunk_diagnose
// Returns a string with a description of the drunkeness level.
string drunk_diagnose()
{
   string dd;
   switch (query_drunk_percent())
   {
   case 0..19:
      break;
   case 20..30:
      dd = "a little tipsy";
      break;
   case 31..40:
      dd = "a little drunk";
      break;
   case 41..50:
      dd = "very drunk";
      break;
   case 51..60:
      dd = "extremely drunk";
      break;
   case 61..70:
      dd = "in a drunken stupor";
      break;
   case 71..80:
      dd = "in a deep drunken stupor";
      break;
   case 81..90:
      dd = "barely awake";
      break;
   default:
      dd = "close to an alchohol coma";
      break;
   }
   return dd;
}

//: FUNCTION sober_up
// Removes a number of drunk points.
void sober_up(int s)
{
   drunk -= s;
   if (drunk < 0)
      drunk = 0;
}

//: FUNCTION query_abuse
// Can we drink at all? This function returns 1 if not above
// max drunk otherwise 0.
int can_drink()
{
   if (drunk < query_max_drunk())
      return 1;
   return 0;
}

//: FUNCTION hp_adjustment
// int hp_adjustment(int hp,int level)
// Returns the adjustment HP for a limb for an adversary.
int hp_adjustment(int hp, int level)
{
   float hpModifier = 1 + (level / 10.0) + (query_con() / 20.0) * (1.0 - (query_abuse_percent() / 125.0));
   return to_int(hp * hpModifier);
}

void update_max_health()
{
   mapping new_body = BODY_D->get_body(body_style);

   foreach (string name, class limb l in health)
   {
      class limb std_limb = (class limb)new_body[name];
      l.max_health = hp_adjustment(std_limb.max_health, query_level());
   }

   // TBUG("HP_cap: " + hp_cap);
   // If our HP are capped, respect that cap.
   if (hp_cap)
      set_max_health(hp_cap);
}

//: FUNCTION update_body_style
// int update_body_style(string body_style);
// Queries BODY_D for the number and type of limbs that will be used.
// e.g. update_body_style("humanoid") will give the body a torso, head,
// two arms, and two legs.
// Returns 0 if the body style doesn't exist or if it doesn't contain
// at least one vital or system limb.
int update_body_style(string bstyle)
{
   mapping new_body = BODY_D->get_body(bstyle);
   body_style = bstyle;
   limb_sizes = BODY_D->get_body_size(bstyle);
   // TBUG("Setting body style " + body_style + " for " + this_object() + " Level " + this_object()->query_level());

   if (!new_body)
      return 0;

   // Make sure we have at least one vital or system limb..

   if (!filter(keys(new_body), ( : ((class limb)$(new_body)[$1])->flags & (LIMB_VITAL | LIMB_SYSTEM) :)))
      return 0;

   health = new_body;

   foreach (string name, class limb l in health)
   {
      l.max_health = hp_adjustment(l.max_health, query_level());
      l.health = hp_adjustment(l.max_health, query_level());
   }

   update_health();
   return 1;
}

string query_body_style()
{
   return body_style;
}

int is_vital_limb(string limb)
{
   return ((class limb)health[limb])->flags & LIMB_VITAL;
}

int is_system_limb(string limb)
{
   return ((class limb)health[limb])->flags & LIMB_SYSTEM;
}

int is_wielding_limb(string limb)
{
   return ((class limb)health[limb])->flags & LIMB_WIELDING;
}

int is_mobile_limb(string limb)
{
   return ((class limb)health[limb])->flags & LIMB_MOBILE;
}

int is_attacking_limb(string limb)
{
   return ((class limb)health[limb])->flags & LIMB_ATTACKING;
}

//: FUNCTION query_limbs
// string *query_limbs();
// Returns a string *containing all limbs that health is applied to.
string *query_limbs()
{
   return keys(health);
}

//: FUNCTION query_wielding_limbs
// string *query_wielding_limbs();
// Returns a string *containing all the limbs that can wield weapons.
string *query_wielding_limbs()
{
   return filter(keys(health), ( : ((class limb)health[$1])->flags & LIMB_WIELDING:));
}

//: FUNCTION query_attacking_limbs
// string *query_attacking_limbs();
// Returns a string *containing all the limba that can attack.
string *query_attacking_limbs()
{
   return filter(keys(health), ( : ((class limb)health[$1])->flags & LIMB_ATTACKING:));
}

//: FUNCTION query_vital_limbs
// string *query_vital_limbs();
// Returns a string *containing all the limbs that are considered
// vital for survival. If any one of these limbs is disabled, the
// adversary dies.
string *query_vital_limbs()
{
   return filter(keys(health), ( : ((class limb)health[$1])->flags & LIMB_VITAL:));
}

//: FUNCTION query_mobile_limbs
// string *query_mobile_limbs();
// Lima doesn't do anything with mobile limbs, but they're provided for
// those who want health of mobile limbs to affect movement and such.
string *query_mobile_limbs()
{
   return filter(keys(health), ( : ((class limb)health[$1])->flags & LIMB_MOBILE:));
}

//: FUNCTION query_system_limbs
// string *query_system_limbs();
// Returns a string *of 'system' limbs. When ALL system limbs are
// disabled, the adversary dies.
string *query_system_limbs()
{
   return filter(keys(health), ( : ((class limb)health[$1])->flags & LIMB_SYSTEM:));
}

//: FUNCTION query_non_limbs
// string *query_non_limbs();
// Returns a list of body parts that are not worth tracking health for.
// Such body parts are defined by having a max_health of -1.
string *query_non_limbs()
{
   return filter(keys(health), ( : ((class limb)health[$1])->max_health == -1 :));
}

//: FUNCTION query_reflex
// int query_reflex()
// Returns the amount of reflex currently had by the adversary.
int query_reflex()
{
   return reflex;
}

//: FUNCTION max_reflex
// int max_reflex()
// Returns the max reflex based on the mana stat and a bonus for level of the
// adversary.
int max_reflex()
{
   return to_int((this_object()->query_int() || 1) * (1 + (query_level() / 10.0)));
}

//: FUNCTION set_reflex
// void set_reflex(int mp)
// Set the reflex to an integer, but never higher than max_reflex().
void set_reflex(int mp)
{
   if (mp > max_reflex())
      mp = max_reflex();
   reflex = mp;
}

//: FUNCTION spend_reflex
// void spend_reflex(int m)
// Spends reflex nomatter whether there is enough or too little. reflex is left at 0 no matter
// what. Returns 1 if we had enough, 0 if we didn't.
int spend_reflex(int m)
{
   reflex -= m;
   if (reflex < 0)
   {
      reflex = 0;
      return 0;
   }
   return 1;
}

//: FUNCTION use_reflex
// int use_reflex(int m)
// Uses reflex from the reflex pool only if it's available and returns 1. If there is not enough
// nothing is used, and 0 is returned.
int use_reflex(int m)
{
   if (reflex - m >= 0)
   {
      reflex -= m;
      return 1;
   }
   return 0;
}

//: FUNCTION restore_reflex
// protected void restore_reflex(int x);
// Restore us a specified amount, truncating at max_reflex().
protected
void restore_reflex(int x)
{
   // Dont get reflex while dead, sorry.
   if (dead)
      return;

   reflex += x;
   if (reflex > max_reflex())
      reflex = max_reflex();
}

void set_heal_rate(int x)
{
   if (x < 0)
      x = 0; /* a number of things depend on this */
   heal_rate = x;
}

int query_heal_rate()
{
   return heal_rate;
}

//: FUNCTION set_max_limb_health
// void set_max_limb_health(string limb, int x);
// Sets the maximum health for a given limb.
void set_max_limb_health(string limb, int x)
{
   class limb tmp = health[limb];

   if (!tmp)
      error("Bad limb.\n");
   if (tmp.max_health == -1 || x < 0)
      return;

   update_health();

   tmp.max_health = x;
   tmp.health = x;
}

//: FUNCTION set_max_health
// void set_max_health(int x);
// Set the maximum number of hit points of a monster, and also set it's
// hit points to the new max. MUST be called *after* update_body_type()
// if that is called since that resets all limbs to neutral hitpoints
// i.e. sums to 100.
void set_max_health(int x)
{
   int max = 0;
   if (!x)
      x = hp_cap;
   else
      hp_cap = x;

   foreach (string l, class limb d in health)
      if (d.max_health > max)
         max = d.max_health;

   foreach (string l, class limb d in health)
   {
      d.max_health = d.max_health * x / max;
      d.health = d.max_health;
   }
}

//: FUNCTION can_move
// int can_move();
// Returns 1 if we can move, 0 if not.
int can_move()
{
   int can_move = 0;

   if (query_prone())
      return 0;

   // Are we over max capacity?
   if (query_capacity() > query_no_move_capacity())
      return 0;

   // Do we have limbs that can move us?
   foreach (string l, class limb lb in health)
   {
      if ((lb.flags & LIMB_MOBILE) && (lb.health > 0))
         can_move = 1;
   }

   return can_move;
}

//: FUNCTION kill_us
// void kill_us();
// Kills us. =)
void kill_us()
{
   object killer = previous_object();
   dead = 1;
   if (previous_object()->is_turret())
      killer = previous_object()->acts_for();

   if (killer)
   {
      string team = PARTY_D->locate_user(killer->short());
      object *viable = filter_array(all_inventory(environment(this_object())), ( : $1->is_body() :));
      this_object()->slain_by(killer);
      if (team && sizeof(viable) > 1)
      {
         // Player is in a team
         PARTY_D->award_experience(killer, team, viable, query_level());
#ifdef USE_KARMA
         PARTY_D->modify_karma(team, viable, karma_impact());
#endif
      }
      else
      {
#ifdef USE_KARMA
         previous_object()->modify_karma(karma_impact());
#endif
         // Add the XP to the player.
         killer->add_experience(xp_value(killer));
         // Add xp and object for stats purposes.
         killer->register_kill(this_object(), xp_value(killer));
      }
   }

   die();
}

/* OLD function where all is equal
string query_random_limb()
{
   string *limbs = filter_mapping(keys(health),
                          (
                              : ((class limb)health[$1])->health > 0
                              :));
   return sizeof(limbs) ? choice(limbs) : 0;
}
*/

//: FUNCTION query_random_limb
// Return a limb based on the size of the limb. The larger
// the limb the higher chance it's returned. Only limbs that
// have hitpoints are returned.
string query_random_limb()
{
   mapping limbs;
   if (!limb_sizes)
   {
      update_body_style(body_style);
   }
   limbs = filter_mapping(limb_sizes, ( : ((class limb)health[$1])->health > 0 :));

   return sizeof(limbs) ? element_of_weighted(limbs) : 0;
}

//: FUNCTION disable_limb
// void disable_limb(string limb);
// Disables a limb. For effects on vital and system limbs, see
// query_vital_limbs() and query_system_limbs().
void disable_limb(string limb)
{
   int dont_kill_me_now = 0;

   if (health[limb].health == -1)
      return;

   ((class limb)health[limb])->health = 0;
   if (((class limb)health[limb])->flags & LIMB_VITAL)
   {
      kill_us();
   }
   else if (((class limb)health[limb])->flags & LIMB_SYSTEM)
   {
      foreach (string l in query_system_limbs())
      {
         if (((class limb)health[l])->health != 0)
            dont_kill_me_now = 1;
      }
      if (dont_kill_me_now == 1)
      {
         filtered_simple_action("$N %^COMBAT_CONDITION%^cannot use%^RESET%^ $p $o anymore.",
                                (
                                    : message_filter:),
                                "disable_limb", limb);
      }
      else
         kill_us();
   }
   else if (((class limb)health[limb])->flags & LIMB_WIELDING)
   {
      filtered_simple_action("$N %^COMBAT_CONDITION%^cannot use%^RESET%^ $p $o anymore.",
                             (
                                 : message_filter:),
                             "disable_limb", limb);
      do_unwield(limb);
   }
   else
   {
      filtered_simple_action("$N %^COMBAT_CONDITION%^cannot use%^RESET%^ $p $o anymore.",
                             (
                                 : message_filter:),
                             "disable_limb", limb);
   }
}

//: FUNCTION enable_limb
// void enable_limb(string limb);
// Re-enables a disabled limb.
void enable_limb(string limb)
{
   class limb tmp = health[limb];

   if (tmp.health == 0)
      tmp.health = 1;
   health[limb] = tmp;
}

//: FUNCTION set_health
// Set hitpoints for a limb to a certain amount.
varargs void set_health(string limb, int x)
{
   class limb tmp = health[limb];

   if (!tmp)
      error("Bad limb.\n");
   update_health();

   if (x > tmp.max_health)
      error("Attempt to set health > max_health.\n");
   if (tmp.health < 1 || dead)
      return;

   tmp.health = x;
   if (tmp.health <= 0)
      disable_limb(limb);
}

//: FUNCTION hurt_us
// varargs int hurt_us(int x, string limb);
// Hurt us a specified amount.
varargs int hurt_us(int x, string limb)
{
   class limb tmp;

   if (!limb)
      limb = query_random_limb();
   tmp = health[limb];
   if (!tmp)
      error("Bad limb '" + limb + "'.\n");
   update_health();

   if (tmp.health < 1 || dead)
      return 0;

   tmp.health -= x;
   if (tmp.health <= 0)
   {
      x += tmp.health; /* negative */
      tmp.health = 0;
      disable_limb(limb);
   }

   return x;
}

//: FUNCTION heal_limb
// protected void heal_limb(string limb, int x);
// Heal us a specified amount, truncating at max_health.
protected
void heal_limb(string limb, int x)
{
   class limb tmp = health[limb];

   if (!tmp)
      error("Bad limb.\n");

   if (tmp.health == -1)
      return;

   if (tmp.health == 0 || dead)
      x = fuzzy_divide(x, 10);

   tmp.health += x;
   if (tmp.health > tmp.max_health)
      tmp.health = tmp.max_health;
}

//: FUNCTION is_limb
// int is_limb(string s);
// Returns 1 if 's' is a valid limb.
int is_limb(string s)
{
   return !undefinedp(health[s]);
}

//: FUNCTION query_max_health
// varargs int query_max_health(string limb);
// Tells us the maximum health of a given limb.
varargs int query_max_health(string limb)
{
   int x = 1;

   if (limb)
      return is_limb(limb) ? ((class limb)health[limb])->max_health : 0;

   foreach (string l in keys(health))
      if (health[l].max_health > x)
         x = health[l].max_health;
   return x;
}

//: FUNCTION heal_us
// varargs void heal_us(int x, string limb);
// Heals all limbs by 'x' amount.
varargs void heal_us(int x, string limb)
{
   if (!limb || undefinedp(limb))
   {
      foreach (limb in keys(health))
         heal_limb(limb, x);
      return;
   }
   else
      heal_limb(limb, x);
}

//: FUNCTION heal_all
// void heal_all();
// Heal us entirely.
void heal_all()
{
   foreach (string l in keys(health))
      if (!health[l].health)
         enable_limb(l);
   heal_us(query_max_health());
   set_drunk(0);
   set_reflex(max_reflex());
}

//: FUNCTION reincarnate
// void reincarnate();
// Makes us alive again!
void reincarnate()
{
   if (dead)
   {
      foreach (string limb, class limb l in health)
         enable_limb(limb);
      dead = 0;
      health_time = time();
   }
}

void update_health()
{
   int sobering;

   if (dead)
   {
      drunk = 0;
      return;
   }

   sobering = fuzzy_divide((time() - health_time) * sober_rate, 3000);
   sober_up(sobering);

   if (time() != health_time)
   {
      foreach (string limb in keys(health))
         heal_limb(limb, fuzzy_divide((time() - health_time) * heal_rate, 3000));
      restore_reflex(fuzzy_divide((time() - health_time) * (reflex_rate + this_object()->query_int()), 2000));
      health_time = time();
   }
}

//: FUNCTION query_health
// int query_health(string limb);
// Find the current number of hitpoints of a monster
int query_health(string limb)
{
   update_health();
   if (!limb)
      limb = "head";
   return ((class limb)health[limb])->health;
}

//: FUNCTION get_health
// mapping get_health();
// Return the health mapping for adversary.
mapping get_health()
{
   update_health();
   return health;
}

int query_ghost()
{
   return dead;
}

// : FUNCTION banner_wounded
// void banner_wounded(string limb, int hp);
// Tell this_object() that they're badly wounded.
void banner_wounded(string limb, int hp)
{
   tell(this_object(), "\n[%^RED%^WOUNDED!%^RESET%^] Your " + limb + " has " + hp + " hp!\n");
}

//: FUNCTION query_worst_limb
// Returns an array of a limb and a percentage of health that is
// the worst hurt vital limb if vital=1, otherwise from all limbs.
varargs mixed *query_worst_limb(int vital)
{
   int hp_percent, min = 100;
   string l = "none";

   foreach (string limb in keys(health))
   {
      class limb lb = health[limb];
      if (vital && !(lb.flags & LIMB_VITAL) || !lb.max_health)
         continue;

      hp_percent = (100 * lb.health) / lb.max_health;
      if (hp_percent < min)
      {
         min = hp_percent;
         l = limb;
      }
   }
   return ({l, min});
}

//: FUNCTION badly_wounded
// Returns 1 if we're near death.
string badly_wounded()
{
   int wimpy_at = 20;

   if (this_object()->is_body())
   {
      object link = this_object()->query_link();
      if (link)
      {
         wimpy_at = this_user()->query_shell_ob()->get_variable("wimpy_percent") || 20;
      }
   }

   foreach (string limb in keys(health))
   {
      class limb lb = health[limb];

      if ((lb.flags & LIMB_VITAL) && (lb->health < ((lb.max_health * wimpy_at) / 100)))
      {
         banner_wounded(limb, lb.health);
         return limb;
      }
   }
}

//: FUNCTION very_wounded
// Returns 1 if we're very wounded (50% hp on vital limbs). Mobs will start drinking and
// eating when they hit this level of damage.
string very_wounded()
{
   foreach (string limb in keys(health))
   {
      class limb lb = health[limb];

      if ((lb.flags & LIMB_VITAL) && (lb->health < ((lb.max_health * 50) / 100)))
      {
         banner_wounded(limb, lb.health);
         return limb;
      }
   }
}

//: FUNCTION diagnose
// Returns a string diagnosing the adversary. The string lists limbs in bad health,
//  drunkenness level and other conditions that affect the adversary.
string diagnose()
{
   string ret;
   string *damaged_limbs;

   if (query_ghost())
      return "$N $vare dead. Other than that, things are going pretty well.\n";

   if (query_asleep())
      ret = "$N $vare asleep.\n";
   else if (query_stunned())
      ret = "$N $vare stunned.\n";
   else
      ret = "";

   damaged_limbs = filter(query_limbs(), ( : query_health($1) < health[$1].max_health:));
   foreach (string limb in damaged_limbs)
      ret += diagnose_limb_msg(health[limb].health * 100 / health[limb].max_health, limb);

   if (drunk_diagnose())
   {
      if (ret == "")
         ret = "$N $vare in excellent health, but $n $vare also " + drunk_diagnose() + ".";
   }
   else
   {
      if (ret == "")
         ret = "$N $vare in excellent health.";
   }

   return ret;
}
