#include <colour.h>
#include <clubs.h>

inherit COMMAND_BASE;

private string* _colours;

void create() {
  ::create();
  _colours = ({
   "BOLD",
   "BLACK",
   "RED",
   "BLUE",
   "CYAN",
   "MAGENTA",
   "ORANGE",
   "YELLOW",
   "GREEN",
   "WHITE",
   "B_RED",
   "B_ORANGE",
   "B_YELLOW",
   "B_BLACK",
   "B_CYAN",
   "B_WHITE",
   "B_GREEN",
   "B_MAGENTA" });
} /* create() */

/** @ignore yes */
int is_valid_colour( string name ) {
    return member_array( name, _colours) != -1;
} /* is_valid_colour() */

/** @ignore yes */
string* query_colour_list( int inform ) {
    string* colour_list;

    switch( inform ) {
      case 0:
        colour_list = USER_COLOUR_LIST;
      break;
      case 1 :
        colour_list = TP->query_inform_types();
      break;
      case 2 :
        colour_list = map( TP->query_player_clubs(), (: "club_" + $1 :) );
      break;
      case 3 :
        colour_list = TP->query_channels();
      break;
    }

    return asort( colour_list );

} /* query_colour_list() */

/** @ignore yes */
mixed set_colours( int inform, string event_type, string colour, int force ) {
    mapping my_colours;
    string *colour_list, *bad, tmp, name;

    colour_list = query_colour_list(inform);

    if( inform == 2 ) {
        name = CLUB_HANDLER->query_club_name(event_type);
        event_type = "club_" + event_type;
    } else {
        name = event_type;
    }

    if( member_array( event_type, colour_list ) == -1 ) {
        add_failed_mess("No such type.\n");
        return 0;
    }

    my_colours = TP->query_my_colours();

    if( colour == "default" ) {
        TP->set_my_colours( event_type, colour );
        write( name + " colour set to default.\n");
    } else if( colour == "none" ) {
        TP->set_my_colours( event_type, colour );
        write( name + " colour set to none.\n");
    } else {
        colour_list = map( explode( colour, " "), (: upper_case($1) :) );
        bad = filter( colour_list, (: !is_valid_colour($1) :) );
        if( sizeof(bad) && !force ) {
            if( sizeof(bad) > 1 ) {
                add_failed_mess("The colours "+
                    query_multiple_short(bad)+" are not valid, valid colours "
                    "are: "+query_multiple_short(_colours)+".\n");
            } else {
                add_failed_mess("The colour "+
                    query_multiple_short(bad)+" is not valid, valid colours "
                    "are: "+query_multiple_short(_colours) + ".\n");
            }
            return 0;
        }

        tmp = "%^"+implode( colour_list, (: $1 + "%^ %^" + $2 :) ) + "%^";
        TP->set_my_colours( event_type, tmp );
        write( name+" colour set to "+tmp+"["+colour+"]%^RESET%^.\n");
    }

    return 1;

} /* set_colours() */

/** @ignore yes */
private int show_colours( int inform ) {
    string *colour_list, event, name;
    mapping my_colours;

    colour_list = query_colour_list(inform);
    my_colours = TP->query_my_colours();

    if( !inform ) {
        write( sprintf("%-20s %s\n", "Clubs", "<list>") );
        write( sprintf("%-20s %s\n", "Informs", "<list>") );
        write( sprintf("%-20s %s\n", "Channels", "<list>") );
    }

    foreach( event in colour_list ) {
        if( inform == 2 )
            name = CLUB_HANDLER->query_club_name(event[5..]);
        else
            name = event;

        if( my_colours[event] ) {
            if( my_colours[event] != "" )
                write(sprintf("%-20s %s\n", name, my_colours[event]+"["+
                    replace( my_colours[event], "%^", "")+"]%^RESET%^") );
            else
                write( sprintf("%-20s %s\n", name, "[none]") );
        } else {
            write( sprintf("%-20s %s\n", name, "[default]") );
        }
    }

    return 1;

} /* show_colours() */

/** @ignore yes */
mixed query_patterns() {
  return ({ "<word'event type'> <string'colour'>",
              (: set_colours(0, $4[0], $4[1], 0) :),
            "force <word'event type'> <string'colour'>",
              (: set_colours(0, $4[0], $4[1], 1) :),
            "", (: show_colours(0) :),
            "inform <word'inform type'> <string'colour'>",
              (: set_colours(1, $4[0], $4[1], 0) :),
            "inform force <word'inform type'> <string'colour'>",
              (: set_colours(1, $4[0], $4[1], 1) :),
            "club <string:quoted'club name'> <string'colour'>",
              (: set_colours(2, $4[0], $4[1], 0) :),
            "club force <string:quoted'club name'> <string'colour'>",
              (: set_colours(2, $4[0], $4[1], 1) :),
            "channel <word'channel name'> <string'colour'>",
              (: set_colours(3, $4[0], $4[1], 0) :),
            "channel force <word'channel name'> <string'colour'>",
              (: set_colours(3, $4[0], $4[1], 1) :),
            "inform", (: show_colours(1) :),
            "clubs", (: show_colours(2) :),
            "channels", (: show_colours(3) :) });
} /* query_patterns() */
