
#include <skills.h>

inherit COMMAND_BASE;

/** @ignore yes */
string rec_list( mixed *args, string path, int all, int lvl, int only_leaf ) {
    int i, sk, o_l, non_zero, no_bonus;
    string str, tp, tmp;

    str = "";

    for( i = 0 ; i < sizeof( args ) ; i += SKILL_ARR_SIZE ) {
        o_l = 0;
        tp = path +"."+ args[ i ];
        // Get the level of the skill at this point.
        if( tp[0] == '.')
            tp = tp[1..];

        sk = TP->query_skill( tp );
        non_zero = SKILL_H->query_only_show_if_non_zero( tp );
        no_bonus = SKILL_H->query_no_bonus( tp );
        reset_eval_cost();

        // Is this part of the tree only a leaf heirachy?
        if( lvl == 1 && SKILL_H->query_only_leaf(tp) )
            o_l = 1;

        // If it is not a leaf heirachy, we show the levels and bonuses.
        // Or, if it is a leaf the show the bonuses is the level is
        // above 0 and the we are not force showing all.
        if( !( only_leaf || o_l ) || ( !sizeof( args[i+SKILL_BIT]) &&
            ( sk > 0 || ( all && !non_zero ) ) ) )
            str += sprintf( "%*'| 's%*'.'-s %4d "+( no_bonus ? "   -\n" :
                "%4d\n"), ( lvl - 1 ) * 2, "", 20 - ( ( lvl - 1 ) * 2 ),
                args[ i ], sk, TP->query_skill_bonus( tp ) );

        // It is a leaf heirachy!  No bonuses, no level if this is not a leaf.
        if( sizeof( args[ i + SKILL_BIT ] ) && ( only_leaf || o_l || all ||
            ( sk > 5 * lvl ) ) ) {
            // Generate the lower bits.
            tmp = rec_list( args[ i + SKILL_BIT ], path +"."+ args[i],
                            all, lvl + 1, only_leaf || o_l );

            // Only put ourselves in if the list thingy generated something.
            // Don't generate the list if it is the language heirachy.
            if( ( only_leaf || o_l ) && ( tmp != "") )
                str += sprintf("%*'| 's%*'.'-s    -    -\n", ( lvl - 1 ) * 2,
                    "", 20 - ( ( lvl - 1 ) * 2 ), args[ i ]) + tmp;
            else
                str += tmp;
        }
    }

    return str;

} /* rec_list() */

/** @ignore yes */
int cmd( string word ) {
    string result, *bits, str;
    mixed *args;
    int i;

    result = "";
    str = "";

    add_succeeded_mess("");

    args = SKILL_H->query_skills();

    bits = ({ });

    if( word ) {
        word = TP->expand_nickname(word);

        if( ( i = member_array( word, args ) ) == -1 ) {
            add_failed_mess("There are no "+word+" skills.\n");
            return 0;
        }

        args = args[ i + SKILL_BIT ];

        result = sprintf( "%'='*-s\n", TP->query_cols(),
            "=======SKILLS=======Level/Bonus");
        result += sprintf("%#*-s\n", (int)TP->query_cols(),
            rec_list( args, word, 1, 1, 0 ) );
    } else {
        result += sprintf("%'='*-s\n", TP->query_cols(),
            "=======SKILLS====== Level/Bonus");
        result += sprintf("%#*-s\n", TP->query_cols(),
            rec_list( args, "", ( member_array("all", bits ) != -1 ), 1, 0 ) );
    }

    TP->more_string( result, "Skills");
    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({
        "", (: cmd(0) :),
        "<string'skill'>", (: cmd($4[0]) :),
    });
} /* query_patterns() */
