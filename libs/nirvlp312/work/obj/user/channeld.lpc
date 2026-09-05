/* Generic Channel Daemon */
#pragma no_clone
#pragma strict_types

#include <ansi.h>
#include <security.h>
#include "/players/vital/closed/headers/channel.h"

mapping ChannelsMap;
mapping ChannelHistoryMap;

int   query_channel(string channel_name, object player);
void  remove_channel(string channel_name, object player);
void  add_channel(string channel_name, object player);
void  channel_message(string channel, string msg);
array on_channel(string channel);
void  add_channel_history(string channel_name, string message);
int   query_history(string channel_name);

int
query_channel(string channel_name, object player)
{
  object *players;
  int i;
  if(ChannelsMap == 0) { ChannelsMap = ([ ]); }
  if(ChannelsMap[channel_name])
  {
    players = ChannelsMap[channel_name];
    return (member_array(player, players) + 1);
  }
  return 0;
}

void
add_channel(string channel_name, object player)
{
  object *players;
  int i;
  if(ChannelsMap == 0) { ChannelsMap = ([ ]); }
  if(!(players = ChannelsMap[channel_name]))
  {
    ChannelsMap[channel_name] = ({ player });
  }
  else
  {
    if(member_array(player, players) == -1)
    {
      if((i = member_array(0, players)) == -1)
      {
        ChannelsMap[channel_name] += ({ player });
/*         player->add_channel_name(channel_name); */
        return;
      }
      else
        ChannelsMap[channel_name][i] + ({ player });
    }
/*   player->set_channel_name(player->query_channel_names() += ({ channel_name })); */
  }
}

void
remove_channel(string channel_name, object player)
{
  object *players;
  if(ChannelsMap == 0){ ChannelsMap = ([ ]); }
  if(players = ChannelsMap[channel_name])
  {
    ChannelsMap[channel_name] -= ({ player });
/*     player->set_channel_name(player->query_channel_names() -= ({channel_name})); */
  }
  else
  {
    return;
  }
}

void
channel_message(string channel, string msg)
{
  int i;
  object *targets;
  string ansi;
  if(ChannelsMap == 0) ChannelsMap = ([]);
  if(!ChannelsMap[channel]) ChannelsMap[channel] = ({ });
  targets = ChannelsMap[channel];
  for(i = 0; i < sizeof(targets); i++)
  {
    if(targets[i])
    {
      if(environment(targets[i]))
      {
        if(member_array(targets[i], on_channel(channel)) != -1)
        {
          if(environment(targets[i])->is_player())
          {
            if(!(ansi = (string) environment(targets[i])->get_ansi_pref(channel))) ansi = "";

            tell_object(environment(targets[i]), ansi + msg + NORM);
          }
          else
          {
            if(!(ansi = (string) targets[i]->get_ansi_pref(channel))) ansi = "";
            tell_object(targets[i], ansi + msg + NORM);
          }
        }
      }
      else
        ChannelsMap[channel] -= ({targets[i]});
    }
    else
      ChannelsMap[channel] -= ({targets[i]});
  }
  add_channel_history(channel,
    "\[" +(ctime()[11..18]) + "\] " + ansi + msg + NORM);
}

array
on_channel(string channel) { return ChannelsMap[channel]; }

void
add_channel_history(string channel_name, string message)
{
  string *messages;
  if(ChannelHistoryMap == 0){ ChannelHistoryMap = ([ ]); }
  if(!(messages = ChannelHistoryMap[channel_name]))
  {
    ChannelHistoryMap[channel_name] = ({ message });
  }
  messages = ChannelHistoryMap[channel_name];
  if(sizeof(messages) >= 19)
    messages -= ({ messages[0] });
  messages += ({ message });
  ChannelHistoryMap[channel_name] = messages;
}

int
query_history(string channel_name)
{
  string *messages;
  int i;
  if(ChannelHistoryMap == 0)
    ChannelHistoryMap = ([]);
  if(!ChannelHistoryMap[channel_name]) 
    ChannelHistoryMap[channel_name] = ({ });
  messages = ChannelHistoryMap[channel_name];
  tell_object(this_player(), "Channel History: "+channel_name+"\n");
  tell_object(this_player(), "----------------------------------------\n");
  for(i=0; i<sizeof(messages); i++){
     tell_object(this_player(), messages[i]);
  }
  tell_object(this_player(), "----------------------------------------\n");
  return 1;
}
