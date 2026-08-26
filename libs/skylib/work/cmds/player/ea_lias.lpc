
#include <alias.h>

inherit COMMAND_BASE;

mapping editing_alias;

/** @ignore yes */
void create() {
    editing_alias = ([ ]);
} /* create() */

/**
 * The method used by the 'ealias' command.
 * @param str the alias name to edit
 * @return 1 on success, 0 on failure
 * @see cmd::ealias
 * @see finish_alias_edit()
 */
protected int edit_alias( string str ) {
    string al;

    if( editing_alias[TP] ) {
        add_failed_mess("You are already editing the '"+
            editing_alias[TP]+"' alias.\n");
        return 0;
    }

    if( !TP->is_alias(str) ) {
        add_failed_mess("No alias '"+str+"' defined.\n");
        return 0;
    }

    editing_alias[TP] = str;
    al = replace( ALIAS_CMD->alias_string( TP->query_player_alias(str) ),
        ";", "\n");

    TP->do_edit( al, "finish_alias_edit", 0 );
    return 1;

} /* edit_alias() */

/**
 * This method used to copy an alias to another one and then edit the
 * result.
 * @param alias the alias to copy
 * @param new_alias the alias to copy to
 * @return 1 on success, 0 on failure
 * @see cmd::ealias
 * @see finish_alias_edit()
 */
protected int edit_alias_copy( string alias, string new_alias ) {
    string al;

    if( !TP->is_alias(alias) ) {
        add_failed_mess("No alias '"+alias+"' defined.\n");
        return 0;
    }

    if( TP->is_alias(new_alias) ) {
        add_failed_mess("The alias '"+alias+"' already exists.\n");
        return 0;
    }

    editing_alias[TP] = new_alias;
    al = replace( ALIAS_CMD->alias_string( TP->query_player_alias(alias)),
        ";", "\n");

    TP->do_edit( al, "finish_alias_edit", 0 );
    return 1;

} /* edit_alias_copy() */

/**
 * The method called when the editing of the alias has been completed.
 * @param str the new alias value
 * @return 1 on success, 0 on failure
 */
void finish_alias_edit( string str ) {
    string alias;

    if( !editing_alias[TP] ) {
        write("Oh dear.  We got terribly confused and forgot "
              "what you were trying to do.  Terribly sorry.\n");
        return;
    }

    if( !str ) {
        map_delete( editing_alias, TP );
        return;
    }

    alias = editing_alias[TP];

    if( alias == ".plan" || alias == ".project" || alias == ".signature") {
        if( sizeof(str) > MAX_PLAN_LENGTH ) {
            write("Sorry, the maximum length of .plan, .project and "
                ".signature aliases is "+MAX_PLAN_LENGTH+" characters.\n");
            return;
        }
    }

    if( sizeof(str) > MAX_ALIAS_LENGTH ) {
        write("Sorry, the maximum alias length is "+
            MAX_ALIAS_LENGTH+" characters.\n");
        return;
    }

    str = replace( str, "\n", ";");
    TP->add_player_alias( alias, ALIAS_CMD->compile_alias(str) );
    write("Changed alias '"+alias+"'\n");

    map_delete( editing_alias, TP );
    return;

} /* finish_alias_edit() */

/** @ignore yes */
mixed query_patterns() {
    return ({
        "<word'alias'>", (: edit_alias($4[0]) :),
        "copy <word'alias'> to <word'new alias'>",
        (: edit_alias_copy($4[0], $4[1]) :),
        });
} /* query_patterns() */
