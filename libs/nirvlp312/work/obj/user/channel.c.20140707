/*
// channel.c
//
// This object is central to the channel system being set up
// on Nirvana.
// The system is developed to look like the channel system on TMI,
// though the code (being non-native mode) will be different.
// Developed by Shadowhawk the NUISANCE
*/

#include <security.h>

#pragma strict_types
#pragma save_types
#define FREE_CHANNELS ({ "gossip", "equip", "shout", "risque", "junk", "msg", "babble", "newbie", "pk", "jukebox" })
#define WIZ_CHANNELS ({ "wiz", "lpc", "announce" })

int list_users(string channel);
int valid_channel(string channel);

string *channel_names;

int
add_channel(string new_chan) {
  if (!valid_channel(new_chan)) {
    write("The channel " + new_chan + " is invalid.\n");
    return 1;
  }
  if (member_array(new_chan, channel_names) != -1) {
    write("You are already on that channel.\n");
    return 1;
  }
  channel_names += ({ new_chan });
     if(this_object()->query_level() > 20 || (new_chan != "msg" && new_chan != "jukebox"))
  add_action("broadcast", new_chan);
  return 1;
}

int
remove_channel(string channel) {
  int index;

  if ((index = member_array(channel, channel_names)) == -1) {
    write("You are not on that channel.\n");
    return 1;
  }
  channel_names -= ({ channel_names[index] });
  remove_action(channel);
  return 1;
}

int
broadcast(string msg) {
  string channel;
  object *people;
  int index;

  channel = query_verb();
/* Edited by OMEGA; Reason: If no arg provided should return 0; */
  if (!msg) return 0;
/* End Segment by OMEGA */
  if( msg == "list" || msg == "who" )
    return list_users(channel);
/* Segment inserted by Feldegast for history changes */
  if(msg == "history"){
    write((string)"/obj/user/chistory.c"->query_history(channel));
    /* need CR and return -Bp */
    write("\n");
    return 1;
  }
/* End of Feldegast's change */
/*
 if(this_object()->query_channelcount() > 15) {
   write("Spaming limit reached. Message Not sent.\n");
   return 1;
 }
*/
  if (!this_player()->setup_broadcast(channel))
    return 1;
  if(channel != "wiz" && channel != "admin" && channel != "risque" &&
      channel != "jukebox" && channel != "lpc" &&
      channel != "announce" && channel != "pk")
       msg = (string)"/obj/verte/text_sanitizer"->sanitize_text(msg);
  if (msg[0] == ':') /* Emoting broadcast */
     { 
       string feeling, targ;
       feeling = msg[1..strlen(msg)-1];
       sscanf(feeling, "%s %s", feeling, targ);
       if(feeling)
      {
       string a, b;
       while(sscanf(feeling,"%s.%s",a,b))
       {
         if(!a) a = "";
         if(!b) b = "";
         feeling = (a+b);
      }
      }
       if(file_size("/bin/soul/_"+feeling+".c") > 1)
       {
       if(call_other("/bin/soul/_"+feeling, "broadcast", query_verb(), targ))
         return 1;
       }
       if((channel != "wiz"  && channel != "admin" && channel != "cwiz") || !this_object()->query_invis())
    msg = "(" + channel + ") " + this_object()->query_name() + " " + 
      msg[1..strlen(msg)] + "\n";
       else
    msg = "(" + channel + ") " + "(invis) "+capitalize((string)this_object()->query_real_name()) + " " + 
      msg[1..strlen(msg)] + "\n";
     }
  else
       if((channel != "wiz" && channel != "admin" && channel != "cwiz") || !this_object()->query_invis())
    msg = this_player()->query_name() + " " + channel + "s: " + msg + "\n";
    else
    msg = "(Invis) "+capitalize((string)this_player()->query_real_name()) + " " + channel + "s: " + msg + "\n";
  people = users();
  msg = format(msg,75);
/*
  for (index = 0; index < sizeof(people); index++)
    if (people[index]->on_channel(channel) || channel == "announce")
      tell_object(people[index], msg);
*/
/* REplace with emit_channel  -Bp */
  this_object()->add_channelcount();
  emit_channel(channel,msg);
  return 1;
}

int
list_users(string channel) {
  int index;
  object *people;
  string str;

  str = "On channel " + channel + ": ";
  people = users();
  for (index = sizeof(people) - 1; index >= 0; index--) 
    if (people[index]->on_channel(channel) || channel == "announce")
      if (!people[index]->query_invis() || this_player() && this_player()->query_level() > 999)
      if(!people[index]->query_muffled())
	str += people[index]->query_name() + (index ? ", " : " ");
  write(format(str));
  return 1;
}

int
valid_channel(string channel) {
  if (member_array(channel, FREE_CHANNELS) != -1)
    return 1;
  if (member_array(channel, WIZ_CHANNELS) != -1)
    /* Only wizards have access to these channels. */
    return (this_object()->query_level() > 20);
  if(channel == "admin") return (this_object()->query_level() > 99);
  return 0;
}

int
on_channel(string channel) {
   if(present("mailread",this_object()))
       if(present("mailread",this_object())->query_block())
         return 0;
  return (member_array(channel, channel_names) != -1);
}

int
list_channels() {
  int index;
  
#if 0
  index = sizeof(channel_names);
  if (index == 0)
    write("You aren't on any channels.\n");
  else if (index == 1)
    write("You are on channel: " + channel_names[0] + "\n");
  else if (index == 2)
    write("You are on channels: " + channel_names[0] +
	  " and " + channel_names[1] + "\n");
  else {
    write("You are on channels: ");
    for (index = sizeof(channel_names) - 1; index > 0; index--)
      write(channel_names[index] + ", ");
    write("and " + channel_names[0] + "\n");
  }
#endif
  for (index = 0; index < sizeof(FREE_CHANNELS); index++) {
    write("    ");
    if (member_array(FREE_CHANNELS[index], channel_names) != -1)
      write("ON ");
    else
      write("OFF");
    write(" -- " + FREE_CHANNELS[index] + "\n");
  }
  if (this_object()->query_level() < EXPLORE)
    return 1;
  for (index = 0; index < sizeof(WIZ_CHANNELS); index++) {
    write("    ");
    if (member_array(WIZ_CHANNELS[index], channel_names) != -1)
      write("ON ");
    else
      write("OFF");
    write(" -- " + WIZ_CHANNELS[index] + "\n");
  }
  if(this_object()->query_level() < SENIOR) return 1;
    if(on_channel("admin")) write("    ON  -- admin\n");
    else write("    OFF -- admin\n");
  return 1;
}

void
init_channels() {
  int index;

  for (index = 0; index < sizeof(channel_names); index++)
     if(this_object()->query_level() > 20 || channel_names[index] != "msg" || channel_names[index] != "jukebox")
    add_action("broadcast", channel_names[index]);
}
