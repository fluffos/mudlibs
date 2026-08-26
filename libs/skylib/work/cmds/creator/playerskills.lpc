
#include <skills.h>

inherit COMMAND_BASE;

/** @ignore yes */
private string rec_list( mixed *args, string path, int all, int lvl,
                         int only_leaf, object pl ) {
    int i, sk, o_l;
    string str, tp, tmp;

    str = "";

    for( i = 0 ; i < sizeof( args ) ; i += SKILL_ARR_SIZE ) {
        o_l = 0;
        tp = path +"."+ args[ i ];
        sk = pl->query_skill( tp );

        reset_eval_cost();

        if( lvl == 1 && SKILL_H->query_only_leaf(tp) )
            o_l = 1;

        if( !( only_leaf || o_l ) || ( !sizeof( args[i+SKILL_BIT] ) &&
            ( sk > 0 || all ) ) )
            str += sprintf("%*'| 's%*'.'-s %4d %4d\n", ( lvl-1 ) * 2, "",
                20 - ( ( lvl - 1 ) * 2 ), args[ i ], sk,
                pl->query_skill_bonus( tp ) );

        if( sizeof( args[ i + SKILL_BIT ] ) && ( only_leaf || o_l || all ||
            ( sk > 5 * lvl ) ) ) {
            tmp = rec_list( args[ i + SKILL_BIT ], path+"."+args[i],
                all, lvl + 1, only_leaf || o_l, pl );

            if( ( only_leaf || o_l) && ( tmp != "" || ( !all && lvl == 1 ) ) )
                str += sprintf("%*'| 's%*'.'-s    -    -\n", ( lvl-1 ) * 2,
                    "", 20 - ( ( lvl - 1 ) * 2 ), args[ i ] ) + tmp;
            else
                str += tmp;
        }
    }

    return str;

} /* rec_list() */

/** @ignore yes */
int cmd( object *players, string word ) {
    string result, *bits;
    mixed *args;
    object pl;
    int i;

    // Only do the first player.
    pl = players[0];

    args = SKILL_H->query_skills();

    bits = ({ });

    result = "";

    if( word ) {
        args = SKILL_H->query_skills();
        if( ( i = member_array( word, args ) ) == -1 )
            return notify_fail("Usage: "+query_verb()+" <skill>\n");

        args = args[ i + SKILL_BIT ];

        result = sprintf("%'='*-s\n", TP->query_cols(),
            "=======SKILLS=======Level/Bonus");
        result += sprintf("%#*-s\n", TP->query_cols(), rec_list( args, word,
            1, 1, 0, pl ) );
    } else {
        result += sprintf("%'='*-s\n", TP->query_cols(),
            "=======SKILLS=======Level/Bonus");
        result += sprintf("%#*-s\n", TP->query_cols(), rec_list( args, "",
            ( member_array( "all", bits ) != -1 ), 1, 0, pl ) );
    }

    TP->more_string( result, "Skills");

    add_succeeded( players[0] );
    add_succeeded_mess( ({"", "$N delve$s skillfully into the internals of "
        "$I.\n"}), players[0..0] );

    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({
        "<indirect:wiz-present> <string>", (: cmd( $1, $4[1] ) :),
        "<indirect:wiz-present>", (: cmd( $1, 0 ) :),
    });
} /* query_pattern() */
