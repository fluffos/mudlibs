/*    /daemon/intermud.c
 *    from the Nightmare IV LPC Library
 *    daemon handling the InterMUD-3 Protocol
 *    created by Descartes of Borg 950506
 *    modified for the Discworld mudlib by Turrican 30-10-95
 */

#ifndef __PACKAGE_SOCKETS__
#error You should not try and load /daemon/intermud.c with no sockets package.
#else

#include <network.h>
#include "intermud.h"

inherit CLIENT;

private int Password;
private class list MudList, ChannelList;
private mapping Banned;
private mixed *Nameservers;
private nosave int Connected, Tries;

protected void create() {
    client::create();
    Connected = 0;
    Password = 0;
    Tries = 0;
    Banned = ([]);
    Nameservers = ({ ({ "*gjs", "198.174.169.120 9000" }) });
    MudList = new(class list);
    ChannelList = new(class list);
    MudList->ID = -1;
    MudList->List = ([]);
    ChannelList->ID = -1;
    ChannelList->List = ([]);
    if( file_size( SAVE_INTERMUD __SAVE_EXTENSION__ ) > 0 )
      restore_object( SAVE_INTERMUD, 1 );
    SetSocketType(MUD);
    SetDestructOnClose(1);
    call_out( (: Setup :), 2);
}

protected void Setup() {
    string ip;
    int port;

    if( !Nameservers || !sizeof(Nameservers) ) return;
    sscanf(Nameservers[0][1], "%s %d", ip, port);
    if( eventCreateSocket(ip, port) < 0 ) return;
    eventWrite( ({ "startup-req-2", 5, mud_name(), 0, Nameservers[0][0], 0,
		   Password, MudList->ID, ChannelList->ID, 4001,
		   0, 0, "Discworld 11.0a", 
		   "Discworld", __VERSION__, "LPMud",
		   "mudlib development", "ddt@iinet.com.au",
		   (mapping)SERVICES_D->GetServices(), 0 }) );
}

protected void eventRead(mixed *packet) {
    string *cles;
    mixed val;
    string ns, cle;
    int i, maxi;

    if( !packet || sizeof(packet) < 6 ) return; /* should send error */
    if( Banned[packet[1]] ) {
	/* build error packet, let them know why they are banned */
	return;
    }
    switch(packet[0]) {
	case "startup-reply":
	  if( sizeof(packet) != 8 ) return;  /* should send error */
	  if( !sizeof(packet[6]) ) return;
	  if( packet[6][0][0] == Nameservers[0][0] ) {
	      Nameservers = packet[6];
	      Connected = Nameservers[0][0];
	      Password = packet[7];
	      eventRequestMudList();
	      eventRequestChannelList();
	      save_object(SAVE_INTERMUD);
	  }
	  else {
	      Nameservers = packet[6];
	      Setup();
	  }
	  return;
        case "mudlist":
	  if( sizeof(packet) != 8 ) return;
	  if( packet[6] == MudList->ID ) return; 
	  if( packet[2] != Nameservers[0][0] ) return;
	  MudList->ID = packet[6];
	  foreach(cle, val in packet[7]) {
	      if( !val && MudList->List[cle] != 0 ) 
		map_delete(MudList->List, cle);
	      else if( val ) MudList->List[cle] = val;
	  }
	  save_object(SAVE_INTERMUD);
	  return;
	case "channel-e":
	  SERVICES_D->eventReceiveChannelEmote(packet);
	  break;
	case "channel-m":
	  SERVICES_D->eventReceiveChannelMessage(packet);
	  break;
	case "chan-who-reply":
	  SERVICES_D->eventReceiveChannelWhoReply(packet);
	  break;
	case "chan-who-req":
	  SERVICES_D->eventReceiveChannelWhoRequest(packet);
	  break;
        case "chan-user-req":
	  SERVICES_D->eventReceiveChannelUserRequest(packet);
	  break;
        case "chanlist-reply":
//	  if( packet[6] == ChannelList->ID ) return; 
	  if( packet[2] != Nameservers[0][0] ) return;
	  ChannelList->ID = packet[6];
	  foreach(cle, val in packet[7]) { 
	      if( !val && ChannelList->List != 0 ) 
		map_delete(ChannelList->List, cle);
	      else if( val ) ChannelList->List[cle] = val;
	  } 
	  save_object(SAVE_INTERMUD);
	  SERVICES_D->eventRegisterChannels(packet[7]);
	  return;
        case "emoteto":
	  SERVICES_D->eventReceiveEmote(packet);
	  break;
	case "finger-req":
	  SERVICES_D->eventReceiveFingerRequest(packet);
	  break;
	case "finger-reply":
	  SERVICES_D->eventReceiveFingerReply(packet);
	  break;
        case "locate-req":
	  SERVICES_D->eventReceiveLocateRequest(packet);
	  break;
        case "locate-reply":
	  SERVICES_D->eventReceiveLocateReply(packet);
	  break;
        case "tell":
	  SERVICES_D->eventReceiveTell(packet);
	  break;
        case "who-req":
	  SERVICES_D->eventReceiveWhoRequest(packet);
	  break;
        case "who-reply":
	  SERVICES_D->eventReceiveWhoReply(packet);
	  break;
        case "news":
	  SERVICES_D->eventReceiveNews(packet);
	  break;
        case "mail":
	  SERVICES_D->eventReceiveMail(packet);
	  break;
        case "mail-ok":
	  SERVICES_D->eventReceiveMailOk(packet);
	  break;
        case "file":
	  break;
        case "error":
	  SERVICES_D->eventReceiveError(packet);
	  break;
        default:
	  break;
    }
}

protected void eventRequestMudList() {
    eventWrite( ({ "mudlist-request", 5, mud_name(), 0, 
		   Nameservers[0][0], 0, MudList->ID }) );
}

protected void eventRequestChannelList() {
    eventWrite( ({ "chanlist-req", 5, mud_name(), 0, Nameservers[0][0], 0,
		   ChannelList->ID }) );
}

protected void eventSocketClose() {
    int extra_wait;

    extra_wait = (Tries++) * 20;
    if( extra_wait > 600 ) extra_wait = 600;
    Connected = 0;
    call_out( (: Setup :), 20 + extra_wait);
}

protected void eventConnectionFailure() {
    if( Connected ) return;
    error("Failed to find a useful name server.\n");
}

int SetSocketType(int x) { return client::SetSocketType(MUD); }

int SetDestructOnClose(int x) { return 0; }

string GetMudName(string mud) {
    string *lc, *uc;
    int x;

    if( MudList->List[mud] ) return mud;
    lc = map(uc = keys(MudList->List), function(string str) {
      if( !str ) return "";
      else return lower_case(str);
    });
    x = member_array(lower_case(mud), lc);
    if( x < 0 ) return 0;
    else return uc[x];
}

mapping GetMudList() { return copy(MudList->List); }

string *GetMuds() { return keys(MudList->List); }

mapping GetChannelList() { return copy(ChannelList->List); }

string *GetChannels() { return keys(ChannelList->List); }

string *GetMatch(string mud) {
    string *uc, *lc;

    mud = lower_case(mud);
    lc = map(uc = keys(MudList->List), (: lower_case :));
    return map(filter(regexp(lc, "^"+mud, 1), (: intp :)), (: $(uc)[$1] :));
}

string GetNameserver() { return Nameservers[0][0]; }

#endif /* __PACKAGE_SOCKETS__ */
