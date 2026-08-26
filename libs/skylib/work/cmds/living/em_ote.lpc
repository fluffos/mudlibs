
#include <player.h>

inherit COMMAND_BASE;

/** @ignore yes */
int cmd( string words ) {
    string pad = " ";

    if( !ENV(TP) )
        return notify_fail("You are in limbo, you cannot emote.\n");

    if( userp(TP) && !creatorp(TP) ) {
        // So we can remove the permission to do emotes.
        if( TP->query_property("no emote") )
            return notify_fail(NOT_ALLOWED);

        if( TP->adjust_sp( -EMOTE_COST ) < 0 )
            return notify_fail( NO_POWER );
    }

    words = strip_colours(words);

    if( words[0..0] == "'")
        pad = "";

    ENV(TP)->event_emote( TP, "$C$"+TP->one_short()+pad+words+"\n");
    INV(ENV(TP))->event_emote( TP, "$C$"+TP->one_short()+pad+words+
        "%^RESET%^\n");

    write("You emote: $C$"+TP->pretty_short(TP)+pad+words+"%^RESET%^\n");
    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() { return ({"<string>", (: cmd($4[0]) :) }); }
