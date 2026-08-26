
#define TABLE "/handlers/top_ten_handler"
#include <top_ten_tables.h>

inherit STD_GUILD_OBJ;

void setup() {
  set_name("thieves");
  set_short("Thieves Guild");
  set_long("The thieves guild. They steal, filch and shoplift. All in all "
           "very likable people.\n");
  set_gp_skill("covert.points");
  set_start_pos("/d/calarien/slum/pub/pub");
  set_skills( ({
      "covert.stealth.inside",
      "covert.stealth.outside",
      "covert.hiding.person",
      "covert.hiding.object",
      "covert.lockpick.doors",
      "covert.lockpick.traps",
      "covert.manipulation.sleight-of-hand",
      "covert.manipulation.stealing",
      "covert.casing.person",
      "covert.casing.place",
      "covert.points",
      "fighting.combat.range.thrown",
      "general.valueing.gems",
      "general.valueing.jewellery"
  }) );
} /* setup() */

int query_skill_cost(string skill) {
  string *bits;
  if(member_array(skill, skills) != -1)
    return 3;
  bits = explode(skill, ".");
  switch(bits[0]) {
    case "covert" :
      return 5;
    case "faith" :
      return 20;
    case "magic" :
      return 50;
    default :
      return 10;;
  }
} /* query_skill_cost() */

int query_skill_max_level( string skill ) {
  string *bits;
  if ( member_array( skill, skills ) != -1 )
    return 400;
  bits = explode( skill, "." );
  switch( bits[ 0 ] ) {
    case "covert" :
      return 50;
    case "faith" :
      return 40;
   case "fighting" :
      return 40;
    case "magic" :
      return 40;
    case "general" :
      return 40;
    default:
      return 40;
  }
} /* query_skill_max_level() */

string query_title_adjective( object player ) {
  int level;

  level = query_level( player );
  if (level > 500)
    return "utterly amazing supreme high master ";
  if (level > 450)
    return "amazingly high exalted grand master ";
  if (level > 425)
    return "amazing incredibly exalted master ";
  if (level > 400)
    return "exalted supreme high master ";
  if (level > 350)
    return "exalted supreme master ";
  if (level > 325)
    return "grand master exalted high ";
  if (level > 300)
    return "exalted grand master ";
  if (level > 275)
    return "exalted high master ";
  if (level > 250)
    return "supreme master ";
  if (level > 200)
    return "grand master ";
  if (level > 175)
    return "high master ";
  if (level > 150)
    return "master ";
  if (level > 120)
    return "exalted high ";
  if (level > 110)
    return "professional ";
  if (level > 100)
    return "incredible ";
  if (level >  90)
    return "awesome ";
  if (level >  80)
    return "highly accomplished ";
  if (level >  70)
    return "high ";
  if (level >  60)
    return "expert ";
  if (level >  55)
    return "very good ";
  if (level >  50)
    return "good ";
  if (level >  45)
    return "tough ";
  if (level >  40)
    return "experienced ";
  if (level >  35)
    return "apprentice ";
  if (level >  30)
    return "practiced ";
  if (level >  25)
    return "practising ";
  if (level >  20)
    return "keen ";
  if (level >  15)
    return "not so silent ";
  if (level >  10)
    return "inexperienced ";
  if (level >  5)
    return "not so skilled ";
  return "novice ";
} /* query_title_adjective */

string query_title_name( object player ) {
  int level, melee, value, sleight, locks, stealth;

  level = query_level( player );
  melee = ( (int)player->query_skill( "fighting.combat.melee.sharp" ) +
      (int)player->query_skill( "fighting.combat.range.thrown" ) ) / 2;
  value = ( (int)player->query_skill( "general.valueing.gems" ) +
      (int)player->query_skill( "general.valueing.jewellery" ) +
      (int)player->query_skill( "covert.hiding.object" ) ) / 3;
  sleight = ( (int)player->query_skill( "covert.sleight-of-hand" ) +
      (int)player->query_skill( "covert.casing.person" ) +
      (int)player->query_skill( "covert.casing.place" ) ) / 3;
  locks = ( (int)player->query_skill( "covert.lockpick.doors" ) +
      (int)player->query_skill( "covert.lockpick.safes" ) +
      (int)player->query_skill( "covert.lockpick.traps" ) ) / 3;
  stealth = ( (int)player->query_skill( "covert.stealth.inside" ) +
      (int)player->query_skill( "covert.stealth.outside" ) +
      (int)player->query_skill( "covert.hiding.person" ) ) / 3;

  if ( melee > level )
    melee -= level;
  else
    melee = 0;
  if ( value > level )
    value -= level;
  else
    value = 0;
  if ( sleight > level )
    sleight -= level;
  else
    sleight = 0;
  if ( locks > level )
    locks -= level;
  else
    locks = 0;
  if ( stealth > level )
    stealth -= level;
  else
    stealth = 0;
  if ( ( melee < 3 ) && ( value < 3 ) && ( sleight < 3 ) && ( locks < 3 ) &&
      ( stealth < 3 ) )
    return "thief";
  melee /= 2;
  value /= 2;
  sleight /= 2;
  locks /= 2;
  stealth /= 2;
  if ( ( melee > value ) && ( melee > sleight ) && ( melee > locks ) &&
      ( melee > stealth ) )
    switch ( melee ) {
      case 0 .. 4 :
        return "robber";
      case 5 .. 9 :
        return "thuggee";
      case 10 .. 14 :
         return "mugger";
      case 15 .. 19 :
        return "thug";
      case 20 .. 24 :
        return "waylayer";
      case 25 .. 29 :
        return "brigand";
      case 30 .. 34 :
        return "hijacker";
      case 35 .. 39 :
        return "footpad";
      case 40 .. 44 :
        return "bandit";
      case 45 .. 49 :
        return "rogue";
      case 50 .. 54 :
        return "highway"+ ( (int)player->query_gender() == 1 ?
            "man" : "woman" );
      default :
        return "cut-throat";
    }
  if ( ( value > sleight ) && ( value > locks ) && ( value > stealth ) )
    switch ( value ) {
      case 0 .. 4 :
        return "plunderer";
      case 5 .. 9 :
        return "pillager";
      case 10 .. 14 :
        return "smuggler";
      case 15 .. 19 :
        return "larcenist";
      case 20 .. 24 :
        return "marauder";
      case 25 .. 29 :
        return "looter";
      default :
        return "fence";
    }
  if ( ( sleight > locks ) && ( sleight > stealth ) ) 
    switch ( sleight ) {
      case 0 .. 4 :
        return "bag snatcher";
      case 5 .. 9 :
        return "pickpocket";
      case 10 .. 14 :
        return "shoplifter";
      case 15 .. 19 :
        return "cutpurse";
      case 20 .. 24 :
        return "filcher";
      case 25 .. 29 :
        return "pilferer";
      case 30 .. 34 :
        return "trickster";
      case 35 .. 39 :
        return "fingersmith";
      case 40 .. 44 :
        return "light-finger";
      case 45 .. 49 :
        return "rustler";
      case 50 .. 54 :
        return "second storey "+ ( (int)player->query_gender() == 1 ?
            "man" : "woman" );
      default :
        return "kleptomaniac";
    }
  if ( locks > stealth )
    switch ( locks ) {
      case 0 .. 4 :
        return "lock picker";
      case 5 .. 9 :
        return "safe cracker";
      case 10 .. 14 :
        return "safe breaker";
      case 15 .. 19 :
        return "house breaker";
      case 20 .. 24 :
        return "acquirer";
      default :
        return "locksmith";
    }
  switch ( stealth ) {
    case 0 .. 4 :
      return "sneak thief";
    case 5 .. 9 :
      return "bravo";
    case 10 .. 14 :
      return "prowler";
    case 15 .. 19 :
      return "burglar";
    case 20 .. 24 :
      return "cat burglar";
    default :
      return "shadowstealer";
  }
} /* query_title_name() */

string query_title(object player) {
   string title;
   
   title = "the "+query_title_adjective(player) + query_title_name(player);

   if (player->query_property("guildmaster"))
      title = "the Guildmaster of the Thieves' Guild";
   return title;
} /* query_title() */

void skills_advanced(object thing, string skill, int level) {
  ::skills_advanced(thing, skill, level);
} /* skills_advanced() */

