
inherit COMMAND_BASE;

/** @ignore yes */
int cmd( object *obs, string words ) {
    object other;
    object *ok;
    object *ignoring;
    object *net_dead;
    object *fail;
    object *earmuffed;
    object *multiple_earmuffed;
    string me_name;
    string pad = " ";

    // Do not allow players with remotes ear muffed to use the command.
    if( TP->check_earmuffs("remote") )
        return notify_fail("You have remote ear muffed.\n");

    ok = ({ });
    ignoring = ({ });
    net_dead = ({ });
    earmuffed = ({ });
    multiple_earmuffed = ({ });

    if( sizeof( fail = TP->query_ignoring(obs) ) )  {
        write("You are currently ignoring "+query_multiple_short(fail)+", so "
            "you ought to leave "+( sizeof(fail) > 1 ? "them" :
            fail[0]->HIM )+" alone.\n");
        obs -= fail;
    }

    foreach( other in obs ) {
        if( other && other->query_property("ignoring") ) {
            if( member_array( TP->query_name(),
                other->query_property("ignoring") ) != -1 &&
                !TP->query_creator() ) {
                ignoring += ({ other });
                other = 0;
            }
        }

        if( other ) {
            if( userp(other) && !interactive( other ) ) {
                net_dead += ({ other });
            } else if( other->check_earmuffs("remote") ) {
                earmuffed += ({ other });
            } else if( other->check_earmuffs("multiple-remote") &&
                sizeof(obs) > 1 ) {
                multiple_earmuffed += ({ other });
            } else {
                ok += ({ other });
            }
        }
    }

    if( sizeof( ignoring ) ) {
        write( query_multiple_short(ignoring)+
            ( sizeof( ignoring ) > 1 ? " are" : " is")+
            " ignoring you and will not have seen your message.\n");
    }

    if( sizeof( earmuffed ) ) {
        write( query_multiple_short( earmuffed )+
            ( sizeof( earmuffed ) > 1 ? " have" : " has")+
            " remotes earmuffed and will not have seen your message.\n");
    }

    if( sizeof( multiple_earmuffed) ) {
        write( query_multiple_short( multiple_earmuffed )+
            ( sizeof( multiple_earmuffed ) > 1 ? " have" : " has")+
            " multiple-remotes earmuffed and will not have seen your"
            " message.\n");
    }

    words = strip_colours(words);

    if( words[0..0] == "'")
        pad = "";

    me_name = TP->short(0);

    if( words[0..0] == "'")
        pad = "";

    if( sizeof(net_dead) || sizeof(ok) ) {
        if( sizeof( ok + net_dead ) > 1 ) {
            foreach( other in ok )
                other->event_emote( TP,
                    other->colour_event("remote", "%^MAGENTA%^")+
                    "$C$Remotes to "+query_multiple_short( net_dead + ok )+
                    ": " + me_name + pad + words + "%^RESET%^\n");

        } else {
            other->event_emote( TP,
                other->colour_event("remote", "%^MAGENTA%^")+
                "$C$" + me_name + pad + words + "%^RESET%^\n");
        }

        write("You remote to "+query_multiple_short( net_dead + ok )+
            ": $C$" + me_name + pad + words +"%^RESET%^\n");
    }

    if( sizeof( net_dead ) ) {
        write( query_multiple_short( net_dead )+
            ( sizeof( net_dead ) > 1 ? " are" : " is")+
            " netdead (or an npc) and may not have seen your message.\n");
    }

    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({"<indirect:distant-living> <string>", (: cmd($1, $4[1]) :) });
} /* query_patterns() */
