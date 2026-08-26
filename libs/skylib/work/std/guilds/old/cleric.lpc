#define TABLE "/obj/handlers/top_ten_handler"
#include <top_ten_tables.h>

inherit STD_GUILD_OBJ;

void setup() {
  set_name("clerics");
  set_short("Clerics' Guild");
  set_long("The clerics guild is all about worshipping a god (or goddess).\n");

  set_gp_skill( "faith.points" );
  set_skills(({ "faith.rituals.offensive.area",
                "faith.rituals.offensive.target",
                "faith.rituals.defensive.area",
                "faith.rituals.defensive.self",
                "faith.rituals.defensive.target",
                "faith.rituals.curing.self",
                "faith.rituals.curing.target",
                "faith.rituals.misc.area",
                "faith.rituals.misc.self",
                "faith.rituals.misc.target",
                "faith.rituals.special",
                "faith.items.rod",
                "faith.items.scroll",
                "faith.points"
                }));

} /* setup() */

int query_skill_cost( string skill ) {
  string *bits;
  if ( member_array( skill, skills ) != -1 )
    return 3;
  bits = explode( skill, "." );
  switch ( bits[ 0 ] ) {
    case "faith" :
      return 5;
    case "fighting" :
      return 15;
    case "covert" :
      return 20;
    case "magic" :
      return 50;
    default :
      return 10;
  }
} /* query_skill_cost() */

int query_skill_max_level( string skill ) {
  string *bits;
  if ( member_array( skill, skills ) != -1 )
    return 400;
  bits = explode( skill, "." );
  switch ( bits[ 0 ] ) {
    case "faith" :
      return 50;
    default :
      return 40;
  }
} /* query_skill_max_level() */

string query_title(object player) {
    int level, female;
    string deity;
    female = (int)player->query_gender() == 2;
    level = query_level(player);
    deity = player->query_deity();

    if (!deity) return "the Unbeliever";

    switch(level) {
      case -400..-1: return "the Unbeliever";
      case 0..5:     return "the Clueless Worshipper of "+deity;
      case 6..10:    return "the Hesitant Worshipper of "+deity;
      case 11..20:   return "the Curious Worshipper of "+deity;
      case 21..30:   return "the Zealous Worshipper of "+deity;
      case 31..40:   return "the Precarious Pilgrim of "+deity;
      case 41..50:   return "the Wandering Pilgrim of "+deity;
      case 51..60:   return "the Worthy Pilgrim of "+deity;
      case 61..70:   return "the Ward of "+deity;
      case 71..90:   return "the Preacher of "+deity;
      case 91..110:  return "the Wise Preacher of "+deity;
      case 111..130: return "the Powerful Preacher of "+deity;
      case 131..150: return "the All-knowing Preacher of "+deity;
      case 151..170: return "the Fanatic Preacher of "+deity;
      case 171..190: return "the Enlightened One of "+deity;
      case 191..210: return "the Pure Mind of "+deity;
      case 211..230: return "the Precursor of "+deity+"'s Wisdom";
      case 231..250: return "the Keeper of "+deity+"'s Flock";
      case 251..280: return "the Protector of "+deity;
      case 281..310: return "the Grand Protector of "+deity;
      case 311..340: return "the Radiant Prophet of "+deity;
      case 341..370: return "the Wondrous Voice of "+deity;
      case 371..400: return "the Pawn of "+deity;
      default: return "the Embodied Power of "+deity;
    }
} /* query_title() */

void skills_advanced(object thing, string skill, int level) {
  ::skills_advanced(thing, skill, level);
} /* skills_advanced() */
