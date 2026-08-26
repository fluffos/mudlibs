// THESE TITLES HAVE ALL BEEN STANDADISED, DO NOT CHANGE THE LEVELS THEY ARE GRANTED AT
// SHAYDZ

#define SKILLS ({ "covert", "crafts", "faith", "fighting", "general", "magic" })

void create() {
} /* create() */

/** @ignore yes */
void dest_me() {
    destruct(TO);
} /* dest_me() */

string query_main_skill( object player ) {
    string *a;
    mapping map;

    if( !player || !objectp(player) )
        return "general";

    map = unique_mapping( SKILLS,
      (: $2->query_skill_bonus( $1, 1 ) :), player );

    if( sizeof ( a = map[sort_array( keys(map), -1 )[0]] ) == 1 )
        return a[0];

    map = unique_mapping( a,
      (: $2->stat_modify( 100, $1, 1 ) :), player );

    return map[sort_array( keys(map), -1 )[0]][0];

} /* query_main_skill() */

string query_title_adjective( int level ) {
    switch( level ) {
    case 0..10:
        return "Novice";
    case 11..15:
        return "Not So Skilled";
    case 16..20:
        return "Inexperienced";
    case 21..25:
        return "Not So Keen";
    case 26..30:
        return "Keen";
    case 31..35:
        return "Practising";
    case 36..40:
        return "Practiced";
    case 41..45:
        return "Apprentice";
    case 46..50:
        return "Experienced";
    case 51..55:
        return "Tough";
    case 56..60:
        return "Good";
    case 61..65:
        return "Very Good";
    case 66..80:
        return "Expert";
    case 81..100:
        return "High";
    case 101..120:
        return "Highly Accomplished";
    case 121..140:
        return "Awesome";
    case 141..160:
        return "Incredible";
    case 161..180:
        return "Professional";
    case 181..200:
        return "Exalted High";
    case 201..225:
        return "Master";
    case 226..250:
        return "High Master";
    case 251..275:
        return "Grand Master";
    case 276..300:
        return "Supreme Master";
    case 301..325:
        return "Exalted High Master";
    case 326..350:
        return "Exalted Grand Master";
    case 351..375:
        return "Grand Master Exalted High";
    case 376..400:
        return "Exalted Supreme Master";
    case 401..425:
        return "Exalted Supreme High Master";
    case 426..450:
        return "Amazing Incredibly Exalted Master";
    case 451..475:
        return "Amazingly High Exalted Grand Master";
    default:
        return "Utterly Amazing Supreme High Master";
    }

} /* query_title_adjective */

string query_crafts_title( object player, int level ) {
    int female, good;
    female = (int)player->query_gender() == 2;
    good = player->query_al() < 0;

    switch( level ) {
    case 1..10: return "the Hopeless Artisan";
    case 11..20: return "the Pathetic Metal-worker";
    case 21..30: return "the Unskilled Crafts"+( female ? "wo" : "")+"man";
    case 31..40: return "the Experimenting Artist";
    case 41..50: return "the Inventive Metal-worker";
    case 51..60: return "the Clever Craftsperson";
    case 61..70: return "the Excellant Artisan";
    case 71..80: return "the Inventor";
    case 81..90: return "the Builder of "+( good ? "Armour" : "Weapons" );
    case 91..100: return "the Forger of Great Art";
    case 101..120: return "the Inspirational Artist";
    case 121..140: return "the Master Metal-worker";
    case 141..160: return "the Crazy Artist";
    case 161..180: return "the Renowned Crafts"+( female ? "wo" : "")+"man";
    case 201..225: return "the Expert Trades"+( female ? "wo" : "")+"man";
    case 226..250: return "the Professional Metalsmith";
    case 251..275: return "the Crafter of Glory";
    case 276..300: return "the Cunning Merchant";
    case 301..325: return "the Exceptional Artist";
    case 326..350: return "the "+( good ? "Holy" :
          "Unholy")+" Artisan of "+mud_name();
    default: return "the Legendary Metalsmith of "+mud_name();
    }
} /* query_crafts_title() */

string query_faith_title( object player, int level ) {
    int female;
    string deity;
    female = (int)player->query_gender() == 2;
    deity = player->query_deity();

    if( !deity )
        return "the Unbeliever";

    switch( level ) {
    case 1..10:  return "the Clueless Worshipper of "+deity;
    case 11..20: return "the Hesitant Worshipper of "+deity;
    case 21..30: return "the Inquisitive Worshipper of "+deity;
    case 31..40: return "the Zealous Worshipper of "+deity;
    case 41..50: return "the Precarious Pilgrim of "+deity;
    case 51..60: return "the Wandering Pilgrim of "+deity;
    case 61..70: return "the Worthy Pilgrim of "+deity;
    case 71..80: return "the Ward of "+deity;
    case 81..90: return "the Preacher of "+deity;
    case 91..100: return "the Wise Preacher of "+deity;
    case 101..120: return "the Powerful Preacher of "+deity;
    case 121..140: return "the All-knowing Preacher of "+deity;
    case 141..160: return "the Fanatic Preacher of "+deity;
    case 161..180: return "the Enlightened One of "+deity;
    case 181..200: return "the Pure Mind of "+deity;
    case 201..225: return "the Precursor of "+deity+"'s Wisdom";
    case 226..250: return "the Keeper of "+deity+"'s Flock";
    case 251..275: return "the Protector of "+deity;
    case 276..300: return "the Grand Protector of "+deity;
    case 301..325: return "the Radiant Prophet of "+deity;
    case 326..350: return "the Wondrous Voice of "+deity;
    case 351..375: return "the Pawn of "+deity;
    default: return "the Embodied Power of "+deity;
    }
} /* query_faith_title() */

string query_fighting_title( object player, int level ) {
    int female, good;

    female = (int)player->query_gender() == 2;
    good = player->query_al() < 0;

    switch( level ) {
    case 0..5: return "the Fighter Fodder";
    case 6..10: return "the Warrior's Apprentice";
    case 11..20: return "the Novice Fighter";
    case 21..30: return "the Fighter Adept";
    case 31..40: return "the Cruel Combatant";
    case 41..50: return "the Squad Leader";
    case 51..60: return "the "+( female ? "Mistress" :
          "Master" )+" of Melee";
    case 61..70: return "the Executioner";
    case 71..80: return "the "+( good ? "Radiant" :
          "Malevolent" )+" Warrior";
    case 81..90: return "the Crusading General";
    case 91..100: return "the Harness of Fury";
    case 101..120: return "the Genocidal Maniac";
    case 121..140: return "the Dreadnought";
    case 141..160: return "the Destroyer of Dreams";
    case 161..180: return "the Brutal Oppressor";
    case 181..200: return "the Despoiler of Innocents";
    case 201..225: return "the Vicious Tyrant";
    case 226..250: return "the Infernal Aggressor";
    case 251..275: return "the Legendary "+( female ?
          "Warrior Princess" : "Warlord" );
    case 276..300: return "the Annihilator";
    case 301..325: return "the Depopulator of Continents";
    case 326..350: return "the "+( good ? "Radiant Protector" :
          "Scourge")+" of "+mud_name();
    case 351..375: return "the "+
        ( good ? "Holy" : "Unholy" ) +" Guardian of "+ mud_name();
    default: return "the "+mud_name()+" Legend";
    }
} /* query_fighting_title() */

string query_magic_title( object player, int level ) {
    switch( level ) {
    case 1..10: return "the Mage's Apprentice";
    case 11..20: return "the Youthful Mage";
    case 21..30: return "the Young Spellcaster";
    case 31..40: return "the Awakening Mage";
    case 41..50: return "the Smoke-scorched Learner";
    case 51..60: return "the Mage";
    case 61..70: return "the Learned Mage";
    case 71..80: return "the Experienced Mage";
    case 81..90: return "the Powerful Mage";
    case 91..100: return "the Wielder of Magics";
    case 101..120: return "the Holder of Power";
    case 121..140: return "the Manipulator of Magic";
    case 141..160: return "the Feared Mage";
    case 161..180: return "the Bender of Reality";
    case 181..200: return "the Forger of Reality";
    case 201..225: return "the Arbiter of Reality";
    case 226..250: return "the Adjunct of Matter";
    case 251..275: return "the Adjunct of Reality";
    case 276..300: return "the Holder of the Seven Keys";
    case 301..325: return "the Keeper of the Four Portals";
    case 326..350: return "the Wearer of Leather Boots";
    case 351..375: return "the Eye of the Storm";
    case 376..400: return "the Initiator of Armageddon";
    default: return "the Binder of Azargaroth";
    }
} /* query_magic_title() */

string query_title( object player ) {
    int lvl;

    if( !objectp(player) || ( ( lvl = player->query_level() ) < 5 ) )
        return "the Searcher";

    switch( query_main_skill( player ) ) {
    case "covert":
        return "the "+query_title_adjective( lvl )+" Sneak";
    case "magic":
        return query_magic_title( player, lvl );
    case "fighting":
        return query_fighting_title( player, lvl );
    case "crafts" :
        return query_crafts_title( player, lvl );
    case "faith" :
        return query_faith_title( player, lvl );
    default:
        return "the Searcher";
    }

} /* query_title() */
