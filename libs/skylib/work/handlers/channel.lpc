/**
 * Chat daemon from the Nightmare mudlib ... "borrowed" by Sibbis 12/10/1994
 * Modified extensively for the Cyningdom of Suvangi by Sibbis 12/10/1994
 * Cleaned up and modified for new intermud(3) client;  Galileo, 2/4/99
 * Modified for the Skylib Mudlib: Shaydz 2001
 */

#define MAX_HISTORY   50

#include <drinks.h>
#include <network.h>

int show_channel(string);
int show_ichannel(string);
string query_channel_name(string);

private mapping channels, chan_history;

void create() {
    object *obs;

    channels = ([ ]);
    chan_history = ([ ]);
    seteuid( master()->creator_file( file_name(TO) ) );

    obs = users();

    foreach( object ob in obs ) {
        string *chans;

        if( !pointerp( chans = ob->query_channels() ) )
            continue;

        if( !adminp(ob) )
            chans -= ({"admin"});

        if( !lordp(ob) )
            chans -= ({"lord"});

        if( !seniorp(ob) )
            chans -= ({"senior"});

        foreach( string chan in chans ) {
            if( pointerp( channels[chan] ) ) {
                if( member_array( ob, channels[chan] ) == -1 )
                    channels[chan] += ({ ob });
            } else {
                channels[chan] = ({ ob });
            }
        }
    }

} /* create() */

/** @ignore yes */
varargs string channel_syntax( string verb, int flag ) {
    string ret, pad;

    if( verb == "cwho") {
        printf("cwho <channel> - List all players on the channel.\n");
        return 0;
    }

    pad = repeat_string(" ", sizeof(verb) );

    ret = "Syntax: "+verb+" <message>  - Normal\n"
          "        "+verb+" @<message> - Emoted\n"
          "        "+verb+" :<message> - Emoted\n";

    if( lordp(TP) )
        ret += "        "+verb+" !<message> - Forced\n";

    ret += "        "+verb+" off        - Channel Off\n"
           "        "+verb+" on         - Channel On\n\n"
           "        history "+verb+"    - Show last "+MAX_HISTORY+" messages.\n"
           "        channels"+pad+"    - Show all available channels.\n"
           "        cwho "+verb+"       - List all players on the channel.\n";

//    if( INTERMUD_H->available_channel( query_channel_name(verb) ) )
//        ret += "        ishow "+verb+"      - List all players on the "
//            "intermud channel.\n";

    if( flag )
        return ret;

    tell_object( TP, ret );
    return 0;

} /* channel_syntax */

/**
 * This method returns the list of users for the specified channel.
 * @param channel the channel to get the users list for
 */
string *query_users( string channel ) {
    string *tmp;

    if( !sizeof( tmp = channels[channel] ) )
        return ({ });

    return filter( tmp, (: !$1->query_property( $2+"_off") &&
                   reference_allowed( $1, $3 ) :), channel, TP );

} /* query_users() */

/** @ignore yes */
int update_users( string channel ) {
    if( pointerp( channels[channel] ) ) {
        channels[channel] -= ({ 0 });
        return 1;
    }

    return 0;

} /* update_users() */

/** @ignore yes */
mixed query_history( string channel ) {
    int i, cols;
    mixed hist;


    if( base_name(PO) != "/cmds/player/hi_story")
        return 0;

    hist = HISTORY_H->query_chat_history(channel);

    if( !pointerp(hist) || !sizeof(hist) )
        return notify_fail("Nobody has said anything on the "+
            channel+" channel.\n");

    write("The "+channel+" channel history is:\n");

    cols = TP->query_cols();

    for( i = 0; i < sizeof(hist); i++ ) {
        if( sizeof( hist[i]) > 2 )
            tell_object( TP, TP->fix_string( sprintf("*%s* %s%-=*s\n",
                ctime(hist[i][2])[11..18], hist[i][0],
                cols - strlen( hist[i][0] ) - 11, hist[i][1] ) ) );
        else
            tell_object( TP, TP->fix_string( sprintf("%s%-=*s\n",
                hist[i][0], cols - strlen( hist[i][0] ), hist[i][1] ) ) );
    }

    return 1;

} /* query_history() */

/** @ignore yes */
int add_user( string *chans ) {
    if( !pointerp(chans) )
        return 0;

    if( !adminp(TP) )
        chans -= ({"admin"});

    if( !lordp(TP) )
        chans -= ({"lord"});

    if( !seniorp(TP) )
        chans -= ({"senior"});

    foreach( string chan in chans ) {
        if( pointerp( channels[chan] ) ) {
            if( member_array( TP, channels[chan] ) == -1 )
                channels[chan] += ({ TP });
        } else {
            channels[chan] = ({ TP });
        }
    }

    return 1;

} /* add_user() */

/** @ignore yes */
void remove_user() {
    object ob;

    ob = PO;

    foreach( string key in keys(channels) )
        if( !sizeof( channels[key] -= ({ 0, ob }) ) )
            map_delete( channels, key );

} /* remove_user() */

private int send_chat( object *obs, string verb, string color, string str,
                       int emote, int force, string who ) {
    string header;

    if( !obs && !( obs = channels[verb] ) )
        return 0;

    update_users(verb);
    header = CAP(who);

    if( emote ) {
        str = ( str[0..1] == "$N" ? str[3..] : str );

        if( emote == 2 )
            who = 0;

        header += " ";
    } else {
        header += ": ";
    }

    if( !channel_silenced(TP) )
        HISTORY_H->add_chat_history( verb, header, str );

    foreach( object ob in obs )
        if( objectp(ob) )
            ob->event_chat( ob, who, verb, str, emote, force );

} /* send_chat() */

/** @ignore yes */
int do_chat( string verb, string str ) {
    string s1;
    int emote, force;

    if( !TP || member_array( TP, previous_object(-1) ) == -1 )
        return 0;

    if( verb == "channels")
        return show_channel("");

    if( verb == "cwho") {
        if( !str || str == "") {
            channel_syntax(verb);
            return 1;
        }
        return show_channel(str);
    }

//    if( verb == "ishow")
//        return show_ichannel(str);

    if( member_array( verb, ( sizeof( TP->query_channels() ) ?
        TP->query_channels() : ({ }) ) ) == -1 )
        return 0;

    if( !channels[verb] )
        return 0;

    if( !str || str == "") {
        channel_syntax(verb);
        return 1;
    }

    if( member_array( TP, channels[verb] ) == -1 )
        return 0;

    if( TP->query_in_jail() ) {
        tell_object( TP, "You are in jail, channels are out of your reach.\n");
        return 1;
    }

    switch( str[0] ) {
      case '@':
      case ':':
        emote = 1;
        str = str[1..];
      break;
      case '!':
        if( lordp(TP) )
            force = 1;
        str = str[1..];
        break;
    }

    if( !str || str == "") {
        channel_syntax(verb);
        return 1;
    }

    if( str == "on") {
        TP->remove_property( verb+"_off");
        tell_object( TP, "You turn on the "+verb+" channel.\n");
        return 1;
    }

    if( str == "off") {
        TP->add_property( verb+"_off", 1 );
        tell_object( TP, "You turn off the "+verb+" channel.\n");
        return 1;
    }

    if( TP->check_earmuffs("chat-channels") ||
        TP->query_property("allchat_off") ||
        TP->query_property(verb + "_off") ) {
        tell_object( TP, "You currently have that channel turned off.\n");
        return 1;
    }

    if( TP->query_gagged() )
        return notify_fail("You have been gagged, channels are out of your "
            "reach.\n");

    if( INTERMUD_H->available_channel( query_channel_name(verb) ) ) {
        INTERMUD_H->channel( query_channel_name(verb), TP->query_name(),
            ( emote ? "@" : "") + str );
        return 1;
    }

    update_users(verb);

    if( !emote ) {
        s1 = TP->mangle_speech(str);
        if( stringp(s1) )
            str = s1;
    }

    if( channel_silenced(TP) )
        send_chat( ({ TP }), verb, TP->query_colour("main"),
            str, emote, force, TP->query_cap_name() );
    else
        send_chat( channels[verb], verb, TP->query_colour("main"),
            str, emote, force, TP->query_cap_name() );

    return 1;

} /* do_chat() */

/** @ignore yes */
int send_intermud_chat( object *obs, string verb, string color, string str,
                        int emote, int force, string who ) {
    if( file_name(PO) == INTERMUD_H )
        send_chat( obs, verb, color, str, emote, force, who );
} /* send_intermud_chat() */

/** @ignore yes */
int show_channel( string str ) {
    object *online, *offline, *vis;
    string *ret;

    if( !str || str == "") {
        tell_object( TP, create_table( ({"Channels", "channel"}),
            map( TP->query_channels(),
                (: $1 + ( TP->query_property( $1+"_off") ?
                " (off)" : " (on)") :) ), 1 ) );
        return 1;
    }

    if( member_array( str, TP->query_channels() ) == -1 ) {
        tell_object( TP, "There is no '"+str+"' channel.\n");
        return 1;
    }

    channels[str] -= ({ 0 });
    vis = filter( channels[str], (: reference_allowed( $1, $(TP) ) :) );
    online = filter( vis, (: !$1->query_property( $2+"_off") :), str );
    offline = vis - online;

    ret = ( map( online,  (: $1->query_cap_name()+" (on)" :) ) +
            map( offline, (: $1->query_cap_name()+" (off)" :) ) );

    tell_object( TP, create_table( ({ CAP(str), "user" }), ret, 1 ) );
    return 1;

} /* show_channel() */

/** @ignore yes */
int show_ichannel( string str ) {
    if( !str || str == "") {
        tell_object( TP, "Syntax: ishow <channel name>\n");
        return 1;
    }

    INTERMUD_H->chan_who( query_channel_name(str) );
    return 1;

} /* show_ichannel() */

/** @ignore yes */
string query_channel_name( string channel ) {
    switch( channel ) {
      default:                 return channel;
      case "intercre":         return "imud_code";
      case "intergossip":      return "imud_gossip";
      case "imud_code":        return "intercre";
      case "imud_gossip":      return "intergossip";
    }

    return 0;

} /* query_channel_name() */

/**
 * This method returns the names of all registered channels.
 * @return the names of registered channels
 */
string *query_registered_channels() { return keys(channels); }
