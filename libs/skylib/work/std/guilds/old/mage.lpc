
#include <top_ten_tables.h>
inherit STD_GUILD_OBJ;

#define TABLE "/obj/handlers/top_ten_handler"

void setup() {
  set_name("mages");
  set_short("Mages' Guild");
  set_long("The mages guild is for those that want to use magic.\n");

  // guild required skills
  set_gp_skill( "magic.points");
  set_skills(({ "magic.spells.offensive",
                "magic.spells.defensive",
                "magic.spells.misc",
                "magic.spells.special",
                "magic.methods.elemental.air",
                "magic.methods.elemental.fire",
                "magic.methods.elemental.water",
                "magic.methods.elemental.earth",
                "magic.methods.mental.animating",
                "magic.methods.mental.channeling",
                "magic.methods.mental.charming",
                "magic.methods.mental.convoking",
                "magic.methods.mental.cursing",
                "magic.methods.physical.binding",
                "magic.methods.physical.brewing",
                "magic.methods.physical.chanting",
                "magic.methods.physical.dancing",
                "magic.methods.physical.enchanting",
                "magic.methods.physical.evoking",
                "magic.methods.physical.healing",
                "magic.methods.physical.scrying",
                "magic.methods.spiritual.abjuring",
                "magic.methods.spiritual.banishing",
                "magic.methods.spiritual.conjuring",
                "magic.methods.spiritual.divining",
                "magic.methods.spiritual.summoning",
                "magic.items.held.wand",
                "magic.items.held.rod",
                "magic.items.held.staff",
                "magic.items.held.broom",
                "magic.items.worn.amulet",
                "magic.items.worn.ring",
                "magic.items.scroll",
                "magic.items.talisman",
                "magic.points"
                        }));

   // add_command 's here
   add_command("remember", 0);
   add_command("forget", 0);
} /* setup() */

int query_skill_cost( string skill ) {
   string *bits;
   if ( member_array( skill, skills ) != -1 )
      return 3;
   bits = explode( skill, "." );
   switch ( bits[ 0 ] ) {
      case "faith" :
         return 50;
      case "fighting" :
         return 20;
      case "magic" :
         return 5;
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
         return 40;
      case "magic" :
         return 100;
      case "general" :
         return 40;
      default :
         return 40;
   }
} /* query_skill_max_level() */

string query_title(object player) {
  int level;
  level = query_level(player);
  switch(level) {
    case -1000..0: return "the Dishonourable Mage";
    case 1..5: return "the Mage's Apprentice";
    case 6..10: return "the Youthful Mage";
    case 11..20: return "the Young Spellcaster";
    case 21..30: return "the Awakening Mage";
    case 31..40: return "the Smoke-scorched Learner";
    case 41..50: return "the Mage";
    case 51..60: return "the Learned Mage";
    case 61..70: return "the Experienced Mage";
    case 71..90: return "the Powerful Mage";
    case 91..110: return "the Wielder of Magics";
    case 111..130: return "the Holder of Power";
    case 131..150: return "the Manipulator of Magic";
    case 151..170: return "the Feared Mage";
    case 171..190: return "the Bender of Reality";
    case 191..210: return "the Forger of Reality";
    case 211..230: return "the Arbiter of Reality";
    case 231..250: return "the Adjunct of Matter";
    case 251..280: return "the Adjunct of Reality";
    case 281..310: return "the Holder of the Seven Keys";
    case 311..340: return "the Keeper of the Four Portals";
    case 341..370: return "the Wearer of Leather Boots";
    case 371..400: return "the Eye of the Storm";
    case 401..440: return "the Initiator of Armageddon";
    case 441..480: return "the Binder of Azargaroth";
    default: return "the Puissant Mage";
  }
} /* query_title() */

void skills_advanced(object thing, string skill, int level) {
  ::skills_advanced(thing, skill, level);
} /* skills_advanced() */

