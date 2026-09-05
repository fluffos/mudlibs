#include "sequence.h"
#include <prop/player.h>

object owner;
string *commands;

void
set_owner (object player)
{
  owner = player;
}

object
query_owner ()
{
  return owner;
}

void
sustain_heart_beat ()
{
  set_heart_beat (1);
  while(remove_call_out("sustain_heart_beat") != -1);
  call_out ("sustain_heart_beat", 10);
}

void
add_sequence (string *sequence)
{
  if (object_name (previous_object ()) != SEQUENCE_SERVER) return;
  if (!commands) commands = sequence;
  else commands = sequence + commands;
  sustain_heart_beat ();
}

void
heart_beat (int counter)
{
  string actual_command;
  if (!owner || !sizeof (commands)) 
  {
    commands = 0;
    set_heart_beat (0);
    while (remove_call_out ("sustain_heart_beat") > -1);
    SEQUENCE_SERVER->comeback (this_object ());
    return;
  }
  actual_command = commands[0];
  commands = commands[1..];
  if (owner->query_property (P_VERBOSE_SEQUENCE))
    tell_object (owner, actual_command+"\n");
  command (actual_command, owner);
}
