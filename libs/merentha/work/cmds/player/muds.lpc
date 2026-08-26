// Petrarch
// Merentha Lib 1.0
// <muds>

#include <daemons.h>

string help() {
return "Syntax: muds\n\nThis command will display all the MUDs \
connected to the Merentha InterMUD System.  This system connects MUDs \
together on a network so communication between different worlds is \
possible.\n\n\
See also: users, finger, tell";
}

int command() {
  mapping Muds=NETWORK_D->query_mud_list();
  string *muds=keys(Muds), list;
  int i=sizeof(muds), x=this_player()->getenv("SCREEN");
  if(!x)x=75;
  if(!i) muds=({
"%^RED%^"+mud_name()+" knows of no other MUDS on the \
MIS.  This could be because of the low number of MUDs currently \
on the system.\n\n\
%^ORANGE%^To fix copy /save/daemons/network.old to /save/daemons/network.o \
and reboot your MUD.\n\n\
%^GREEN%^If that does not work you may need to download a new network.o \
from http://www.merentha.com and reboot your MUD."});
  while(i--) {
   muds[i]="%^RED%^"+arrange_string(muds[i],x/4-1)+
           "%^GREEN%^"+arrange_string(Muds[muds[i]]["address"],16)+
           arrange_string(Muds[muds[i]]["port"],6)+
           "%^ORANGE%^"+arrange_string(Muds[muds[i]]["mudlib"],x/4)+
           arrange_string(Muds[muds[i]]["driver"],x/5)+
           arrange_string(""+Muds[muds[i]]["pings"],x/5);
   muds[i]=arrange_string(muds[i],x-4);
  }
  list=implode(muds,"\n");
 this_player()->more(border(list,"MUDs on MIS",this_player()->getenv("SCREEN")),this_player()->getenv("SCREEN"));
 return 1;
}

