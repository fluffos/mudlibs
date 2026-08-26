// Petrarch
// Merentha Lib 1.0
// <events>

#include <daemons.h>

int command() {
mapping __Events;
string *events;
int i;

    i=sizeof(events=keys(__Events=EVENT_D->query_events()));
    if(!i) message("command", "No events pending.", this_player());
    else message("command", "Event    Time      Object               Args", this_player());
    while(i--)
      message("command", 
arrange_string(events[i],9)+
arrange_string(""+((__Events[events[i]][0]-time())/60)+" min",10)+
arrange_string(__Events[events[i]][1],20)+
arrange_string(identify(__Events[events[i]][2]),35), this_player());

    return 1;
}


string help() {
    return "Syntax: events\n\nLists all future events in the event daemon.";
}
