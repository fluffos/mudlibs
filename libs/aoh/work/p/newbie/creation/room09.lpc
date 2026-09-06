
#include <properties.h>
#include <ansi.h>

#define AB(x)   ANSI_BOLD + x + ANSI_NORMAL

inherit "/std/room";

varargs void create()
{
  ::create();
  SetIntShort("Channels");
  SetIntLong(

   "We provide channels as a way for all players to communicate with "
   "eath other easily. Anyone who has a channel on receives all the "
   "messages which are sent using this channel. It's like a MUD-wide "
   "radio broadcast. All channels are prefixed with a '='.\n"
   " \n"
   "To send a message on the newbie channel, type " +
    AB("=newbie <text you want to send>") +
   ". When you leave the newbie area, your player channel "
   "will be turned on and you can send messages with " +AB("=")+".\n"
   "\n"
   "You can look at the available channels by typing "+AB("channels")+
   ". You can turn all your channels off temporarily with the command " +
    AB("choff") +", and "
   "turn them back on with "+AB("chon")+
   ". You can also turn selected channels on/off with " +
    AB("choff <channel name>") +" and " + AB("chon <channel name>") +
   ". To see who is listening to a channel, type "+
    AB("chwho <channel name>")+ ".\n"
   "Try typing 'chwho newbie'.\n\n");

  AddExit("north","./room10");
  AddExit("south","./room08");

  SetIndoors(1);

}
