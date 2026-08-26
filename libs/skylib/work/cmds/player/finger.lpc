/* finger command, trial out by Turrican for a commands daemon. */

#include <clubs.h>

inherit COMMAND_BASE;

private int bc, vc;

/** @ignore yes */
int cmd() {
  string ret;
  object ob, *obs;
  string type;
  string str;

    obs = users();
    obs = sort_array( obs, (: strcmp( $1->query_cap_name(),
                                      $2->query_cap_name() ) :) );

    str = sprintf("%-12.12s    %-20.20s %-20.20s %-20.20s\n",
                  "Name", "Real name", "Where", "Birthday");

    foreach( ob in obs ) {
        string euid;
        euid = geteuid(ob);

        type = ob->query_object_type();
        str += sprintf("%-12.12s %2.2s %-20.20s %-20.20s %-20.20s\n",
             ( ob->query_invis() ? "("+ob->query_cap_name()+")" :
             (string)ob->query_cap_name() ), type,
             ( ( ret = (string)ob->query_real_name() ) ? ret : "-" ),
             ( ( ret = (string)ob->query_where() ) ? ret : "-" ),
             ( ( ret = (string)ob->query_birthday() ) ? ret : "-" ) );
    }

    TP->more_string( str, "Finger" );
    return 1;

} /* cmd() */

/** @ignore yes */
int finger_player( string str, int brief ) {
    string ret, who, where;

    if( brief )
        bc++;
    else
        vc++;

    if( str ) {
        str = lower_case(str);
        str = (string)TP->expand_nickname(str);
    }

    ret = (string)FINGER_H->finger_info( str, 0, brief );
    if( ret ) {
        // Don't do a fit_message() here, because it breaks tables.
        TP->more_string( ret, "finger: "+str );
        return 1;
    } else if( creatorp(TP) && sscanf( str,"%s@%s", who, where ) == 2 ) {
        INTERMUD_H->finger( who, where );
        write("Intermud finger on its way.\n");
        return 1;
    } else {
        add_failed_mess( str+" doesn't have a character on "+mud_name()+".\n");
        return 0;
    }

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({ "", (: cmd() :),
              "<string'name|domain|club'>",
              (: finger_player( $4[0], !TP->query_verbose("finger") ) :),
              "verbose <string'name|domain|club'>",
              (: finger_player( $4[0], 0 ) :),
              "brief <string'name|domain|club'>",
              (: finger_player( $4[0], 1 ) :) });
} /* query_patterns() */

/** @ignore yes */
mixed stats() {
    return ({ ({ "Verbose", vc }), ({"Brief", bc }) });
} /* stats() */
