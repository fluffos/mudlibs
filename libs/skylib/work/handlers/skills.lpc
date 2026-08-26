/**
 * This is the skills handler.  It controls all the skills currently in
 * the game and keeps track of their various properties.
 * @author Pinkfish
 */

#include <language.h>
#include <skills.h>
#include <tune.h>

#define VERSION_1       "DSv1"
#define VERSION_2       "DSv2"
#define CURRENT_VERSION VERSION_2

private mixed _skills;
private mapping _stat_bonus;
private mapping _reg_skills;
private mapping _skill_tree;
private mapping _immediate_children;
private mapping _only_leaf;
private mapping _not_allowed_to_teach;
private mapping _only_show_if_non_zero;
private mapping _no_bonus;

private mapping flatten( mixed arr, string bit );
private int query_skill_cost_int( string str );

private void create() {
    int i;
    mixed rabbit;
    string lang, *languages, *lang_tree, skill_written, skill_spoken, *skill_bits;

    _skills = STD_SKILLS;
    _skill_tree = ([ ]);
    _immediate_children = ([ ]);
    _not_allowed_to_teach = ([ ]);
    _only_show_if_non_zero = ([ ]);
    _no_bonus = ([ ]);
    lang_tree = ({ });
    languages = LANGUAGE_H->query_languages();

    foreach( lang in languages ) {
        rabbit = ({ });
        if( LANGUAGE_H->query_language_spoken( lang ) )
            rabbit += ({ SPOKEN_SKILL, 0, 0, ({ }), });

        if( LANGUAGE_HAND->query_language_written( lang ) ||
            LANGUAGE_HAND->query_language_magic( lang ) )
            rabbit += ({ WRITTEN_SKILL, 0, 0, ({ }) });

        skill_written = LANGUAGE_H->query_language_written_skill( lang );
        skill_spoken = LANGUAGE_H->query_language_spoken_skill( lang );
        lang = replace( lang, " ", "_");
        lang_tree += ({ lang, 0, 0, rabbit });
        _not_allowed_to_teach[LANGUAGE_SKILL_START + lang] = 1;
        _not_allowed_to_teach[skill_spoken] = 1;
        _not_allowed_to_teach[skill_written] = 1;
        _only_show_if_non_zero[skill_spoken] = 1;
        _only_show_if_non_zero[skill_written] = 1;
        _no_bonus[skill_spoken] = 1;
        _no_bonus[skill_written] = 1;
    }

    // We make an assumption here that the skill is only two levels deep.
    skill_bits = explode( LANGUAGE_SKILL_START, ".");
    _not_allowed_to_teach["general.language"] = 1;

    if( ( i = member_array( skill_bits[0], _skills ) ) != -1 )
        _skills[i+SKILL_BIT] += ({ skill_bits[1], 0, 0, lang_tree });

    _only_leaf = ([ "general" : 1 ]);
    _reg_skills = flatten( _skills, "");

    _stat_bonus = ([
        "covert"                          : "DDDDD",
        "covert.hiding"                   : "DDDDI",
        "covert.lockpick"                 : "DDDII",
        "covert.casing"                   : "DDIII",
        "covert.items"                    : "DDDII",
        "crafts"                          : "DDIIW",
        "crafts.smithing.black"           : "DISSW",
        "crafts.smithing.sharpening"      : "DIIIS",
        "crafts.smithing.decorating"      : "DDISW",
        "crafts.smithing.examining"       : "IIWWW",
        "faith"                           : "WWWWW",
        "faith.items"                     : "IIWWW",
        "fighting"                        : "DDSSS",
        "fighting.combat.melee.pierce"    : "DDDSS",
        "fighting.combat.range"           : "DDDSS",
        "fighting.combat.range.thrown"    : "DDDSS",
        "fighting.combat.range.fired"     : "DDISS",
        "fighting.combat.dodging"         : "DDDDD",
        "fighting.combat.special.weapon"  : "SSDDI",
        "fighting.combat.special.unarmed" : "SSDDI",
        "fighting.combat.special.tactics" : "IIIWW",
        "magic"                           : "IIIII",
        "magic.methods.mental"            : "IIIWW",
        "magic.methods.physical"          : "IIIDD",
        "magic.items.held.broom"          : "DDIII",
        "general"                         : "DDISS",
        "general.tracking"                : "IIIWW",
        "general.swimming"                : "DCCSS",
        "general.climbing"                : "SSDIC",
        "general.valueing"                : "IIIIW",
        "general.evaluating"              : "IIIIW",
        "general.perception"              : "IIWWW",
        "general.direction"               : "DDIIW",
        "general.health"                  : "CCCCS",
        "general.points"                  : "CDISW",
        "general.language"                : "IIIWW",
    ]);

} /* create() */

/**
 * This method returns the all of the skills with their children and the
 * number of children in a nice mapping.  The key of the mapping is the name
 * of the skill, the value is an array of two elements.  The first is an
 * array of all the children and the second is the number of children
 * of the skill.
 * @return the mapping as described above
 */
mapping query_reg_skills() { return _reg_skills; }

/**
 * This method returns the raw unfluffed skill array.  This is the same
 * as the skill array defined in /include/skills.h plus the language skills
 * and other dynamic skills added.
 * @return the skills array
 * @see /include/skills.h
 */
mixed query_skills() { return _skills; }

/**
 * This method returns the path to skill.  This is essentially the skill
 * name broken up on '.'s and returned as an array.
 * @return the skill path, or 0 if the skill does not exist
 */
string *query_skill_path( string skill ) {
    if( skill[0] == '.' )
        skill = skill[1..];

    if( !_reg_skills[skill] )
        return 0;

    return explode( skill, "." );

} /* query_skill_path() */

/**
 * This method returns the skill and all of its parents leading up to
 * it.
 * @example
 * query_skill_tree("magic.methods.physical.binding")
 * Returns: ({
 *  "magic.methods.physical.binding",
 *  "magic.methods.physical",
 *  "magic.methods",
 *  "magic"
 * })
 * @param skill the skill to get the tree of
 * @return the skill tree of the skill
 */
string *query_skill_tree( string skill ) {
    return _skill_tree[skill];
} /* query_skill_tree() */

/**
 * This method returns the stats that effect the skill.
 * @param skill the skill to check
 * @return the stats that effect the skill
 */
string query_skill_stat( string skill ) {
    int i;
    string *bit, s;

    bit = explode( skill, "." );
    i = sizeof(bit);

    while( i >= 0 ) {
       s = implode( bit[0..i], ".");
       if( _stat_bonus[s] )
           return _stat_bonus[s];
       else
           i--;
    }

    return "";

} /* query_skill_stat() */

/**
 * This method returns the children of the specified skill chunk.
 * You need to pass into this array a skill chunk as taken from the
 * skill array.  It is recursive and returns all the internal children
 * as well.
 * @param arr the skill chunk
 * @param path the skill bit leading up to this section
 * @return the children of the skill chunk
 */
string *query_children( mixed arr, string path ) {
    string *ret;
    int i;

    ret = ({ });

    for( i = 0; i < sizeof(arr); i += SKILL_ARR_SIZE )
       ret += ({ path+arr[i] }) + query_children( arr[i+SKILL_BIT],
                 path+arr[i]+".");

    return ret;

} /* query_children() */

/**
 * This method returns the immediate children of the specified skill.
 * @param skill the skill to get the children of
 * @return the immediate children of the skill
 */
string *query_immediate_children( string skill ) {
    return _immediate_children[skill];
} /* query_immediate_childen() */

/**
 * This method returns all the children of the specified skill.
 * This does a deep children finding exercise, returing all the children
 * as it goes lower and lower into the array.
 * @param skill the skill to get the children of
 * @return all the children
 * @see query_related_skills()
 */
string *query_all_children( string skill ) {
    if( _reg_skills[skill] )
        return _reg_skills[skill][0];
    return 0;
} /* query_all_children() */

private string *query_imm_children( mixed arr, string path ) {
    string *ret;
    int i;

    ret = ({ });
    for( i = 0; i < sizeof(arr); i+= SKILL_ARR_SIZE )
        ret += ({ path+arr[i] });

    return ret;

} /* query_imm_children() */

/** @ignore yes */
private string *create_skill_tree( string skill ) {
    string *ret, *bits;
    int i;

    ret = ({ });
    bits = explode(skill, ".");

    // For the only leaf heirachy, only count the upper level.
    if( _only_leaf[bits[0]] )
         return ({ skill });

    for( i = sizeof(bits) - 1; i >= 0; i-- )
        ret += ({ implode(bits[0..i], ".") });

    return ret;

} /* create_skill_tree() */

/** @ignore yes */
private mapping flatten( mixed arr, string bit ) {
    int i;
    mapping ret;

    if( !bit )
        bit = "";

    ret = ([ ]);
    for( i = 0; i < sizeof(arr); i += SKILL_ARR_SIZE ) {
        reset_eval_cost();
        if( !sizeof( arr[i+SKILL_BIT] ) ) {
            ret[bit + arr[i]] = ({ ({ bit+arr[i] }), 1 });
        } else {
            ret[bit + arr[i]] = ({ query_children( arr[i+SKILL_BIT],
                bit + arr[i]+".")+({ bit + arr[i] }),
                query_skill_cost_int(bit + arr[i]) });
            ret += flatten( arr[i+SKILL_BIT], bit+arr[i]+".");
        }
        _skill_tree[bit + arr[i]] = create_skill_tree( bit + arr[i] );
        _immediate_children[bit + arr[i]] = query_imm_children(
            arr[i+SKILL_BIT], bit+arr[i]+".");
     }

     return ret;

} /* flatten() */

/** @ignore yes */
private int query_skill_cost_rec( mixed arr ) {
    int i, tmp;

    if( !sizeof(arr) )
        return 1;

    for( i = 0; i < sizeof(arr); i += SKILL_ARR_SIZE )
        tmp += query_skill_cost_rec( arr[i+SKILL_BIT] );

    return tmp;

} /* query_skill_cost_rec() */

/** @ignore yes */
private int query_skill_cost_int( string str ) {
    int i;
    mixed arr;
    string *path;

    path = explode( str, "." );
    arr = _skills;

    while( sizeof(path) ) {
        i = member_array( path[0], arr );
        if( i == -1 ) {
            return -1;
        } else {
            path = path[1..sizeof(path)];
            arr = arr[i+SKILL_BIT];
        }
    }

    return query_skill_cost_rec(arr);

} /* query_skill_cost_int() */

/**
 * This method also returns all the children of a skill.  It preforms
 * exactly the same action as query_all_children()
 * @param skill the skill to get the children of
 * @return the children of the skill
 */
string *query_related_skills( string skill ) {
    if( _reg_skills[skill] )
        return _reg_skills[skill][0];
    return 0;
} /* query_related_skills() */

/**
 * This method attempts to figure out the path of a skill from an array
 * of bits.  It verifies that the skill actually exists on the way.
 * @param bits the skill to check
 * @return the path of the skill
 */
string query_skill( string *bits ) {
    string path, s1;
    mixed arr;
    int i;

    path = "";
    arr = _skills;

    for( i = 0; i < sizeof(arr); i += SKILL_ARR_SIZE ) {
        if( sscanf( arr[i], bits[0]+"%s", s1 ) == 1 ) {
            path += "."+arr[i];
            arr = arr[i+SKILL_BIT];
            i = -SKILL_ARR_SIZE;
            bits = bits[1..sizeof(bits)];
            if( !sizeof(bits) )
                return path[1..strlen(path)];
        }
    }

    if( i < sizeof(arr) )
        return path[1..strlen(path)];

    return 0;

} /* query_skill() */

/**
 * This method determines if only leaf skills can be increased in this
 * skill tree.  This is used for the other skill tree, to avoid increasing
 * all the other skills at the same time.
 * @param str the skill tree to check
 * @return 1 if the tree is only leaf, 0 if not
 */
int query_only_leaf( string str ) {
    return _only_leaf[explode( str, "." )[0]];
} /* query_only_leaf() */

/**
 * This method checks to see if this particular skill is allowed to be
 * taught to people.
 * @param str the skill to check
 * @return 1 if they are not allowed to teach it, 0 if they are
 */
int query_allowed_to_teach( string str ) {
    return !_not_allowed_to_teach[str];
} /* query_allowed_to_teach() */

/**
 * This method checks to see if the skill should only be shown on the
 * skill list if it is non-zero.
 * @param str the skill to check
 * @return 1 if should only show non-zero skills, 0 if show any skill
 */
int query_only_show_if_non_zero( string str ) {
    return _only_show_if_non_zero[str];
} /* query_only_show_if_non_zero() */

/**
 * This method checks to see if the specified skill has no bonus associated
 * with it.
 * @param str the skill to check
 * @return 1 if there is no bonus, 0 if there is a bonus
 */
int query_no_bonus( string str ) {
    return _no_bonus[str];
} /* query_no_bonus() */

/**
 * This method is called by the player object when logging in, and
 * checks whether or not an upgrade is needed to the player's skills.
 */
void player_logon() {
    object player;
    mapping skills;

    if( !userp( player = PO ) )
        return;

    switch( player->query_property("skills version") ) {
      case CURRENT_VERSION :
        return;
      case 0 :
      case VERSION_1 : {
        int co_po, fi_po, ma_po, fa_po, cr_po, ge_po;
        int *points;
        
        skills = player->query_skills();


        if( !undefinedp( skills["fighting.points"] ) ) {
            fi_po = skills["fighting.points"];
            map_delete( skills, "fighting.points");
        }
        if( !undefinedp( skills["covert.points"] ) ) {
            co_po = skills["covert.points"];
            map_delete( skills, "covert.points");
        }
        if( !undefinedp( skills["faith.points"] ) ) {
            fa_po = skills["faith.points"];
            map_delete( skills, "faith.points");
        }
        if( !undefinedp( skills["magic.points"] ) ) {
            ma_po = skills["magic.points"];
            map_delete( skills, "magic.points");
        }
        if( !undefinedp( skills["crafts.points"] ) ) {
            cr_po = skills["crafts.points"];
            map_delete( skills, "crafts.points");
        }
        if( !undefinedp( skills["general.points"] ) ) {
            ge_po = skills["general.points"];
        }
        points = sort_array(({co_po, fi_po, ma_po, fa_po, cr_po, ge_po}),-1);
        
        if(points){
            skills["general.points"] = points[0];
            
            tell_object( player, "\nMerging your gp into general.points.\n\n");
        }


        player->set_skills( skills );

        log_file("SKILL_CHANGE",sprintf("%s: Co:%d, Fi:%d, Ma:%d, Fa:%d, Cr:%d, Ge:%d, Points:%d\n",
            player->query_name(),co_po, fi_po, ma_po, fa_po, cr_po, ge_po, points[0]));
      }
      default :
        player->add_property("skills version", CURRENT_VERSION );
    
      }
} /* player_logon() */

/**
 * The current version of the skill tree.
 * @return the version of the skill system
 */
string query_version() { return CURRENT_VERSION; }

/**
 * This method returns the experience cost for advancing to a certain
 * level in a skill for the specified player.
 * If no offset is specified, the return value will be the cost of a
 * single skill level from the player's current level.
 * @param player the player to get the cost for
 * @param skill the skill to get the cost for
 * @param offset the offset
 * @return the cost of advancing a level of the skill
 */
int query_skill_cost( object player, string skill, int offset ) {
    float base, total;
    string *next;

    next = SKILL_H->query_immediate_children( skill );

    if( !sizeof( next ) ) {
        base = STD_GUILD_OBJ->query_skill_cost( skill, player );
        total = base;
        total *= ( STD_COST * 100 ) / 500;
        total *= ( player->query_skill(skill) + offset ) / LEVEL_DIV + 1;
        total += 30 * base;
        return to_int( total * exp( ( player->query_skill(skill) +
                       offset ) / 150.0 ) );
    }

    foreach( skill in next )
        total += query_skill_cost( player, skill, offset );

    return total;

} /* query_skill_cost() */

/** @ignore yes */
mixed stats() { return ({ ({"skills version", CURRENT_VERSION }) }); }
