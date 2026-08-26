inherit COMMAND_BASE;

string *properties = ({ "no score", "no delete", "test character" });

int cmd( object player, string status ) {
    foreach( string property in properties ) {
        if ( status == "on" ) {
            player->add_property( property, 1 );
        }
        else {
            player->remove_property( property );
        }
    }
   
    if ( status == "on" ) {
        add_succeeded_mess( ({ "$I is now a test character.\n", "" }), 
            ({ player }) );
    }
    else {
        add_succeeded_mess( ({ "$I is no longer a test character.\n", "" }), 
            ({ player }) );
    }

    return 1;
} /* cmd() */

mixed *query_patterns() {
    return ({ "<indirect:player> {on|off}", (: cmd($1[0], $4[1]) :) });
} /* query_patterns() */

