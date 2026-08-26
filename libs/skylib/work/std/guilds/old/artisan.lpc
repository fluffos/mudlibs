/*  -*- LPC -*-  */
//Origion Artisan object (or what little there is of it)
//done by Liceas Shadowstealer 11/07/01
#define TABLE "/obj/handlers/top_ten_handler"
#include <top_ten_tables.h>

inherit STD_GUILD_OBJ;

void setup() {
    set_name("artisans");
    set_short("Artisans' Guild");
    set_long("The Artisans guild is the guild to join if you believe "
    "there should be more to life than just hitting things with a big "
    "clun, or stealing other peoples wealth.  In the Artisans guild "
    "you can make your own wealth by making great weapons, swindling "
    "people out of money, selling and making poisons, maybe even "
    "exploiting the knowlege that can be discovered from clients "
    "for your own gain in the form of spying, you can amuse people by "
    "painting great portraits or playing excellent music, "
    "the possibilitys are almost endless.\n");
    set_gp_skill("crafts.points");
    set_start_pos("/d/calarien/slum/pub/pub"); //temp start location
    set_skills(({"crafts.smithing.gold",
        "crafts.smithing.silver",
        "crafts.smithing.black.tools",
        "crafts.smithing.black.weapons",
        "crafts.smithing.black.armour",
        "crafts.carpentry.furniture",
        "crafts.carpentry.coopering",
        "crafts.carpentry.turning",
        "crafts.carpentry.whittling",
        //These need to be added to the game first
        "crafts.brewing.alcohol",
        "crafts.brewing.poison",
        "crafts.mining.gold",
        "crafts.mining.silver",
        "crafts.mining.bronze",
        "crafts.mining.iron",
        "crafts.mining.jewels",
        //back to skills already here :o)
        "crafts.pottery.forming.throwing",
        "crafts.pottery.forming.shaping",
        "crafts.pottery.glazing",
        "crafts.pottery.firing",
        "crafts.points"
      }));

    // add_command 's here *shudder*
} /* setup() */

int query_skill_cost(string skill) {
    string *bits;
    if(member_array(skill, skills) != -1)
        return 3;
    bits = explode(skill, ".");
    switch(bits[0]) {
    case "craft" :
        return 5;
    case "faith" :
        return 25;
    case "fighting" :
        return 40;
    case "magic" :
        return 50;
    default :
        return 10;
    }
} /* query_skill_cost() */

int query_skill_max_level( string skill ) {
    if(member_array(skill, skills) != -1)
        return 400;
    return 40;
} /* query_skill_max_level() */

string query_title(object player) {
    int level, female, good;
    female = (int)player->query_gender() == 2;
    level = query_level(player);
    if( player -> query_al() > 0 )
        good = 1;
    else
        good = 0;

    switch( level )
    {
    case 1..5: return "the Hopeless Artisan";
    case 6..9: return "the Pathetic Metal-worker";
    case 10..19: {
           if( female )
               return "the Unskilled Craftswoman";
               return "the Unskilled Craftsman";
        }
    case 20..29: return "the Experimenting Artist";
    case 30..39: return "the Inventive Metal-worker";
    case 40..49: return "the Clever Craftsperson";
    case 50..59: return "the Excellant Artisan";
    case 60..69: return "the Inventor";
    case 70..79: {
            if( good )
                return "the Builder of Armour";
                return "the Builder of Weapons";
        } break;
    case 80..89: return "the Forger of Great Art";
    case 90..99: return "the Inspirational Artist";
    case 100..119: return "the Master Metal-worker";
    case 120..139: return "the Crazy Artist";
    case 140..159: {
            if( female )
                return "the Renowned Craftswoman";
                return "the Renowned Craftsman";
    }
    case 160..179: {
            if( female )
            return "the Expert Tradeswoman";
            return "the Expert Tradesman";
    }
    case 180..199: return "the Proffessional Metalsmith";
    case 200..224: return "the Crafter of Glory";
    case 225..249: return "the Cunning Merchant";
    case 250..274: return "the Exceptional Artist";
//care to help fill these in?
    case 275..299: return "the ";
    case 300..329: return "the ";
    case 330..359: {
            if( good )
                return "the Holy Artisan of "+ mud_name();
            return "the Satanic Artisan of "+ mud_name();
        } break;
    case 360..399: return "the Legendary metalsmith of "+ mud_name();
    default: return "the "+ mud_name() +" Legend";
    }
    return "the artisan";
} /* query_title() */

void skills_advanced(object thing, string skill, int level) {
    ::skills_advanced(thing, skill, level);

} /* skills_advanced() */

