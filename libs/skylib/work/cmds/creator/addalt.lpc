/**
 * Addalt - adds a record about a player's alt character.
 * @author Fiona
 */
#include <creator.h>
#include <playerinfo.h>

inherit COMMAND_BASE;

// Command entry point
int delete_alt(string s1, string s2)
{
    string  who = this_player()->expand_nickname(lower_case(s1));
    string  *alts = explode(lower_case(s2)," ") - ({ "" }) - ({ 0 });
    string result =
        PLAYERINFO_HANDLER->add_alts(this_player(),who,alts);

    write(result);
    return 1;
}

// Answer the command patterns
mixed *query_patterns()
{
    return ({
        "<word'player-name'> <string'alt-name alt-name ...'>",
        (: delete_alt($4[0],$4[1]) :)
    });
}
