/**
 * Print info - prints playerinfo database entries for a given player.
 * If the reason argument is given, print only entries referring to that
 * event.
 *
 * @author Fiona
 */
#include <creator.h>
#include <playerinfo.h>

inherit COMMAND_BASE;

// Command entry point
int do_report(string player, string event)
{
    string who = this_player()->expand_nickname(lower_case(player));

    if(!"/secure/login"->test_user(who)) {
        add_failed_mess("No such player: "+who+".  \n");
        return 0;
    }

    log_file("/secure/log/PLAYERINFO",
         "%s: %s read dossier of %s.\n",
         ctime(time()), this_player()->query_name(), who);
           
    if(event == 0) {
        PLAYERINFO_HANDLER->print_dossier(this_player(),who);
    } else {
        PLAYERINFO_HANDLER->print_event(this_player(),who,lower_case(event));
    }
    return 1;
}

// Yet Anothr Command Entry Point (YACEP)
int list_events()
{
    string *list = sort_array(PLAYERINFO_HANDLER->query_events(),1);
    string event, result = "";

    // See a remark in addevent.c
    foreach(event in list)
        result += (event == list[0]) ? event : (", "+event);
    write("The following events exist: "+result+". \n");
    return 1;
}

int do_acknowledge( string player, string event, int idx, string update ) {
   if( !(PLAYERINFO_HANDLER->is_alert( player, idx ) ) )
      return notify_fail( "That event is not an alert, so cannot be "
        "acknowledged.\n" );

   if( !PLAYERINFO_HANDLER->acknowledge_alert( this_player(), player,
     event, idx, update, 0 ) )
      write( "You do not have the permission to acknowledge that alert, "
        "or the event type is invalid.\n" );
   else
      write( "Event acknowledged.\n" );
   return 1;
}

int list_alerts( int foo ) {
   string * names;
   
   if( foo )
      names = PLAYERINFO_HANDLER->query_online_alerts();
   else
      names = keys( PLAYERINFO_HANDLER->query_alerts() );
   
   if( !sizeof( names ) )
      write( "There are no players with unacknowledged alerts.\n" );
   else
      write( "The following players have unacknowledged alerts: "
        + query_multiple_short( names ) + ".\n" );
        
   return 1;
}

// Return the command pattern list.
mixed *query_patterns()
{
    return ({
        "list",
        (: list_events() :),
        "<word'player-name'>",
        (: do_report($4[0],0) :),
        "<word'player-name'> <word'event'>",
        (: do_report($4[0],$4[1]) :),
        "<word'player-name'> acknowledge <number'event-number'> "
          "<string'update-string'>",
        (: do_acknowledge( $4[0], "misc", $4[1], $4[2] ) :),
        "<word'player-name'> acknowledge as <word:'event-type'> "
          "<number'event-number'> <string'update-string'>",
        (: do_acknowledge( $4[0], $4[1], $4[2], $4[3] ) :),
        "list alerts",
        (: list_alerts(0) :),
        "list alerts online",
        (: list_alerts(1) :)
    });
}
