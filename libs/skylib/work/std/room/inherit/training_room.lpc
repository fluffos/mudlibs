/**
 * This is the training hall inherit.
 * @author Shaydz
 * @changed Moved some of the code to the skill handler.
 * - Sandoz, June 2003.
 */

#include <skills.h>

private string teaching_skill;

/** @ignore yes */
void create() {
    TO->add_help_file("training_hall");
} /* create() */

/** @ignore yes */
int do_advance_internal( string skill, int to, int by ) {
    string *bits, skill_name, outer_name;
    int lvl, max_lvl, tmp, total_xp, i;

    bits = explode( implode( explode( skill, " " ), "."), ".");

    if( strlen(bits[0]) == 2 ) {
        if( bits[0][0..1] != teaching_skill[0..1] ) {
            add_failed_mess("You cannot advance "+skill+" here.\n");
            return 0;
        }
    } else {
        if( bits[0] != teaching_skill ) {
            add_failed_mess("You cannot advance "+skill+" here.\n");
            return 0;
        }
    }

    if( !skill_name = SKILL_H->query_skill(bits) ) {
        add_failed_mess("The skill "+skill+" does not exist.\n");
        return 0;
    }

    if( !SKILL_H->query_allowed_to_teach(skill_name) ) {
        add_failed_mess("You cannot learn "+skill_name+" in here.\n");
        return 0;
    }

    lvl = TP->query_skill( skill_name );

    if( !by && to )
        by = to - lvl;

    if( by <= 0 ) {
        if( !by )
            add_failed_mess("You are already at level "+lvl+" in "+
                skill_name+".\n");
        else
            add_failed_mess("You cannot regress below your current "
                "skill level.\n");
        return 0;
    }

    if( SKILL_H->query_only_leaf(skill_name) ) {
        if( sizeof( SKILL_H->query_immediate_children(skill_name) ) ) {
            add_failed_mess("You can only advance the outer skills "
                "(eg: general.riding.horse), not the internal skills "
                "(eg: general.riding, or general).\n");
            return 0;
        }
    } else {
        bits = explode( skill_name, ".");

        if( sizeof( bits ) > 1 ) {
            outer_name = implode( bits[ 0 .. sizeof( bits ) - 2 ], "." );
            if( ( sizeof( bits ) - 1 ) * 5 > TP->query_skill( outer_name ) ) {
                 add_failed_mess("You are not at a high enough level in "+
                     outer_name+" to advance "+skill_name+" yet.\n");
                 return 0;
            }
        }
    }

    max_lvl = STD_GUILD_OBJ->query_skill_max_level( skill_name,TP );
    
    if( lvl >= max_lvl ) {
        add_failed_mess("You cannot advance any further in "+
            skill_name+" here.\n");
        return 0;
    }

    for( i = 0; i < by; i++ ) {
        tmp = SKILL_H->query_skill_cost( TP, skill_name, i );

        if( TP->query_xp() < tmp + total_xp ) {
            if( !i ) {
                add_failed_mess("Your lack of experience prevents you from "
                    "improving "+skill_name+".\n");
                return 0;
            } else {
                tell_object( TP, "Your lack of experience prevents you from "
                    "taking all the advancement you requested in "+
                    skill_name+".  You are only trained up to level "+
                    ( i + lvl )+".\n");
            }
            break;
        }

        if( ( lvl + i ) >= max_lvl ) {
            tell_object( TP, "This training hall hasn't the resources to "
                "train you as far as you requested in "+skill_name+".  You "
                "are trained to level "+max_lvl+" instead.\n");
            break;
        }

        total_xp += tmp;
    }

    if( !total_xp ) {
        add_failed_mess("Oh dear, something has gone wrong.\n");
        return 0;
    }

    TP->adjust_xp( -total_xp );
    TP->add_skill_level( skill_name, i, total_xp );

    event( TO, "guild_advance", bits, lvl, lvl+i );

    tell_object( TP, "You advance your skill in "+skill_name+" from level "+
        lvl+" to "+( lvl + i )+" for "+total_xp+" xp.\n");
    tell_room( TO, TP->the_short()+" $V$0=advances,advance$V$ $V$0="+
        TP->HIS+",their$V$ skills.\n", TP );
    
    return 1;

} /* do_advance_internal() */

/** @ignore yes */
int do_advance( string skill ) {
    return do_advance_internal( skill, 0, 1 );
} /* do_advance() */

/** @ignore yes */
int do_advance_by( string skill, int num ) {
    return do_advance_internal( skill, 0, num );
} /* do_advance_by() */

/** @ignore yes */
int do_advance_to( string skill, int num ) {
    return do_advance_internal( skill, num, 0 );
} /* do_advance_to() */

/** @ignore yes */
private string rec_cost( mixed arr, string path, int depth, int only_leaf,
                         int brief ) {
    int i, depth_gap, ndots, o_l, tmp, lvl, max_lvl;
    string str, lpath;

    depth_gap = ( depth - 1 ) * 2;
    ndots = 19 - depth_gap;

    str = "";

    for( i = 0; i < sizeof(arr); i += SKILL_ARR_SIZE ) {
        lpath = path + arr[i];
        lvl = TP->query_skill(lpath);
        max_lvl = STD_GUILD_OBJ->query_skill_max_level( lpath, TP );
        o_l = only_leaf;

        if( depth == 1 )
            o_l = SKILL_H->query_only_leaf( lpath );

        if( lvl >= max_lvl ) {
            if( !brief ) {
                str += sprintf("%*'| 's%-*'.'s%4d/%3d  mastered\n", depth_gap,
                    "", ndots, arr[ i ], lvl, max_lvl );
            }
        } else {
            if( !o_l || !sizeof( arr[ i + SKILL_BIT] ) ) {
                if( ( o_l && sizeof( arr[ i + SKILL_BIT] ) ) ||
                    !SKILL_H->query_allowed_to_teach(lpath) ) {
                    str += sprintf("%*'| 's%-*'.'s\n", depth_gap,
                        "", ndots+18, arr[ i ] );
                } else {
                    tmp = SKILL_H->query_skill_cost( TP, lpath, 0 );
                    str += sprintf("%*'| 's%-*'.'s%4d/%3d %6d xp\n", depth_gap,
                        "", ndots, arr[ i ], lvl, max_lvl, tmp );
                }
            } else if( o_l ) {
                str += sprintf("%*'| 's%-*'.'s\n", depth_gap,
                    "", ndots+18, arr[ i ] );
            }
        }

        if( lvl >= depth * 5 || o_l ) {
            reset_eval_cost();
            str += rec_cost( arr[ i + SKILL_BIT ], lpath +".", depth + 1,
                o_l, brief );
        }
    }

    return str;

} /* rec_cost() */

/** @ignore yes */
int do_cost_internal( string skill, int to, int by ) {
    string *bits, skill_name, outer_name;
    int lvl, max_lvl, i, tmp;

    bits = explode( implode( explode( skill, " "), "."), ".");

    if( strlen(bits[0]) == 2 ){
        if( bits[0][0..1] != teaching_skill[0..1] ) {
            add_failed_mess("You cannot advance "+skill+" here, so we can't "
                "tell you how much it would cost.\n");
            return 0;
        }
    } else {
        if( bits[0] != teaching_skill ) {
            add_failed_mess("You cannot advance "+skill+" here.\n");
            return 0;
        }
    }

    if( !skill_name = SKILL_H->query_skill( bits ) ) {
        add_failed_mess("There is no such skill as "+skill+".\n");
        return 0;
    }

    if( !SKILL_H->query_allowed_to_teach(skill_name) ) {
        add_failed_mess("You cannot learn "+skill_name+" in here.\n");
        return 0;
    }

    lvl = TP->query_skill( skill_name );

    if( !by && to )
        by = to - lvl;

    if( !by ) {
        add_failed_mess("It won't cost you anything to stay at the same "
            "level.\n");
        return 0;
    }

    if( by < 0 ) {
        add_failed_mess("We don't give refund xp for regressing skills.\n");
        return 0;
    }

    bits = explode( skill_name, ".");

    if( sizeof( bits ) > 1 ) {
        if( SKILL_H->query_only_leaf(skill_name) ) {
            if( sizeof( SKILL_H->query_immediate_children(skill_name) ) ) {
                add_failed_mess("You can only advance the outer skills "
                    "(eg: general.riding.horse), not the internal skills "
                    "(eg: general.riding, or general).\n");
                return 0;
            }
        } else {
            outer_name = implode( bits[ 0 .. sizeof( bits ) - 2 ], ".");
            if( ( sizeof(bits) - 1 ) * 5 > TP->query_skill( outer_name ) ) {
                add_failed_mess("You are not at a high enough level in "+
                    outer_name+" to advance "+skill_name+" yet.\n");
                return 0;
            }
        }
    }

    max_lvl = STD_GUILD_OBJ->query_skill_max_level( skill_name, TP );
   
    if( lvl >= max_lvl ) {
        add_failed_mess("Sorry, our teachers are not capable of instructing "
            "you above level "+max_lvl+" in "+skill_name+".\n");
        return 0;
    }

    for( i = 0;i < by; i++ ) {
        if( ( lvl + i ) >= max_lvl ) {
            tell_object( TP, "Sorry, our teachers are only able to instruct "
                "you up to level "+max_lvl+" in "+skill_name+".\n");
            break;
        }

        tmp += SKILL_H->query_skill_cost( TP, skill_name, i );

    }

    printf("It would cost you %d xp to raise %s from level %d to %d.\n",
        tmp, skill_name, lvl, ( lvl + i ) );

    return 1;

} /* do_cost_internal() */

/** @ignore yes */
int do_cost( string skill ) {
    string *bits, list;
    mixed arr;
    int i;

    bits = explode( implode( explode( skill, " "), "."), ".");
   
    if( strlen(bits[0]) == 2 ) {
        if( bits[0][0..1] != teaching_skill[0..1] ) {
            add_failed_mess("You cannot advance "+skill+" here.\n");
            return 0;
        }
    } else {
        if( bits[0] != teaching_skill ) {
            add_failed_mess("You cannot advance "+skill+" here.\n");
            return 0;
        }

    }

    arr = SKILL_H->query_skills();

    if( !arr ) {
        add_failed_mess("Oops, something seems to have broken.\n");
        return 0;
    }

    i = member_array( skill, arr );
   
    if( i != -1 ) {
        list = sprintf( "%-*'='s\n", TP->query_cols() - 1,
            "======SKILLS=======Cur/Max==For Next");
        list += sprintf("%#*-s\n", TP->query_cols(),
            rec_cost( arr[ i + 3 ], skill+".", 2, 0, 0 ) );
        list += sprintf("%*'='|s\n", TP->query_cols() - 1,
            "> You have "+TP->query_xp()+" points to spend. <");
        TP->more_string( list, CAP( skill ), 1 );
        return 1;
    }

    return do_cost_internal( skill, 0, 1 );

} /* do_cost() */

/** @ignore yes */
int do_cost_to( string skill, int num ) {
    return do_cost_internal( skill, num, 0 );
} /* do_cost_to() */

/** @ignore yes */
int do_cost_by( string skill, int num ) {
    return do_cost_internal( skill, 0, num );
} /* do_cost_to() */

/** @ignore yes */
varargs void set_teaching_skill( string skill ) { teaching_skill = skill; }

/** @ignore yes */
string query_teaching_skill() { return teaching_skill; }

/** @ignore yes */
void init() {
    add_command("advance", "<string>", (: do_advance($4[0]) :) );
    add_command("advance", "<string> to <number>",
        (: do_advance_to( $4[0], $4[1] ) :) );
    add_command("advance", "<string> by <number>",
        (: do_advance_by( $4[0], $4[1] ) :) );
    add_command("cost", "<string>", (: do_cost($4[0]) :) );
    add_command("cost", "<string> to <number>",
        (: do_cost_to($4[0], $4[1]) :) );
    add_command("cost", "<string> by <number>",
        (: do_cost_by($4[0], $4[1]) :) );
} /* init() */
