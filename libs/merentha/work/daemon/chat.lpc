// Petrarch
// Merentha Lib 1.0
// chat.c

#include <daemons.h>
#include <chat.h>
#include <std.h>

inherit DAEMON;

mapping __Channels=([]), __Blocked=([]);

void register_channels(string *channels, object player) {
int i;
  if(!channels || !player) return;
  i=sizeof(channels);
  while(i--) {
    if(!__Blocked[channels[i]]) __Blocked[channels[i]]=({});
    if(!__Channels[channels[i]]) __Channels[channels[i]]=({});
    __Channels[channels[i]]=__Channels[channels[i]]+({player});
  }
}

int send_message(string player, string channel, string message, int emote) {
object ob;
  if(!player || !channel) return 0;
  if(member_array(channel, keys(__Channels))==-1) return 0;
//tell_object(find_player("cratylus"),"hi!");
  if(!message) {
    if(!ob=this_player()) return 0;
    if(member_array(ob, __Blocked[channel])==-1) {
      __Blocked[channel]=__Blocked[channel]+({ob});
      message(channel, "Channel ["+channel+"] blocked.", ob);
    }
    else {
      __Blocked[channel]=__Blocked[channel]-({ob});
      message(channel, "Channel ["+channel+"] unblocked.", ob);
    }
    return 1;
  }
  if(member_array(channel, MIS_CHANNELS)!=-1 && this_player()) {
    NETWORK_D->send_rcre_request(player, message);
  }
  if(message[0]==':' && member_array(message[1..1], ({"P","p",")","(","-"}))==-1) {
    emote=1;
    message=message[1..<0];
  }
  if(emote) message(channel,"%^BLUE%^[%^RED%^"+channel+"%^BLUE%^]%^RESET%^ "+player+" "+message, __Channels[channel]-__Blocked[channel]);
  else message(channel, player+" %^BLUE%^[%^RED%^"+channel+"%^BLUE%^]%^RESET%^ "+message, __Channels[channel]-__Blocked[channel]);
if(member_array(channel,INTERMUD_D->GetChannels()) != -1){
//if(previous_object() != find_object("/daemon/services/channel"))
if(this_player())
SERVICES_D->eventSendChannel(capitalize(player),channel,message);
}
  return 1;
}

void create() {
string ns = INTERMUD_D->GetNameserver();
  if(sizeof(users())) call_out("remake",0);
foreach(string canal in ({"intermer","imud_code","dchat","dead_test4"}) ){
            INTERMUD_D->eventWrite(({ "channel-listen", 5, mud_name(), 0, ns,
                0, canal, 1 }));
}
}

void remake() {
  users()->add_channels();
}

mapping get_chans(){
return copy(__Channels);
}
