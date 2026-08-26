/*  -*- LPC -*-  */

#define TABLE "/obj/handlers/top_ten_handler"
#include <top_ten_tables.h>
#include "/d/guilds/fighter/defs.h"

inherit STD_GUILD_OBJ;

void setup() {
    set_name("fighters");
    set_short("Fighters' Guild");
    set_long("The Fighters guild is the guild to join if you want to kill "
      "things with a sharp bit of metal or bludgeon them to death "
      "with a stick.  Not much intelligence is required when you are "
      "a fighter, as most things fall into the categories of prey or "
      "food.\n");
    set_gp_skill("fighting.points");
    set_start_pos("/d/calarien/slum/pub/pub"); //temp start location
    set_skills(({"fighting.combat.melee.sharp",
        "fighting.combat.melee.pierce",
        "fighting.combat.melee.blunt",
        "fighting.combat.melee.unarmed",
        "fighting.combat.range.thrown",
        "fighting.combat.range.fired",
        "fighting.combat.parry.melee",
        "fighting.combat.parry.range",
        "fighting.combat.dodging.melee",
        "fighting.combat.dodging.range",
        "fighting.combat.special.weapon",
        "fighting.combat.special.unarmed",
        "fighting.combat.special.tactics",
        "fighting.points"
      }));

    // add_command 's here
} /* setup() */

int query_skill_cost(string skill) {
    string *bits;
    if(member_array(skill, skills) != -1)
        return 3;
    bits = explode(skill, ".");
    switch(bits[0]) {
    case "faith" :
        return 15;
    case "fighting" :
        return 5;
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
        // Negatives? hmm, I suppose it could happen :)
    case -1000..5: return "the Fighter Fodder";
    case 6..9: return "the Fighter's Apprentice";
    case 10..19: return "the Novice Fighter";
    case 20..29: return "the Fighter Adept";
    case 30..39: return "the Accomplished Combatant";
    case 40..49: return "the Renowned Warrior";
    case 50..59: {
            if( female )
                return "the Mistress of Melee";
            return "the Master of Melee";
        }
    case 60..69: return "the Executioner";
    case 70..79: {
            if( good )
                return "the Radiant Warrior";
            return "the Malevolent Warrior";
        } break;
    case 80..89: return "the Forger of Fury";
    case 90..99: return "the Harness of Fury";
    case 100..119: return "the Genocidal Maniac";
    case 120..139: return "the Dreadnought";
    case 140..159: return "the Destroyer of Dreams";
    case 160..179: return "the Brutal Oppressor";
    case 180..199: return "the Despoiler of Innocents";
    case 200..224: return "the Vicious Tyrant";
    case 225..249: return "the Infernal Aggressor";
    case 250..274: {
            if( female )
                return "the Legendary Warrior Princess";
            return "the Legendary Warlord";
        } break;
    case 275..299: return "the Annihilator";
    case 300..329: return "the Depopulator of Continents";
    case 330..359: {
            if( good )
                return "the Radiant Protector of "+ mud_name();
            return "the Scourge of "+ mud_name();
        } break;
    case 360..399: return "the Sworn Protector of "+ mud_name();
    default: return "the "+ mud_name() +" Legend";
    }
    return "the fighter";
} /* query_title() */

void skills_advanced(object thing, string skill, int level) {
    ::skills_advanced(thing, skill, level);

    thing -> remove_known_command("berserk");
} /* skills_advanced() */

