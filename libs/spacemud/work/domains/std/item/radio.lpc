/* Do not remove the headers from this file! see /USAGE for more info. */

// This item a small demo of using restricted channels. It auto creates channels
// called "c10", "c80" etc. from c1 to cMAX_CHANNELS (see below).
//
// The channels are not permanent and will come and go as they are created,
// and disappear when nobody is listening.
//
// The radio can be tuned by doing "tune radio to channel X" and the channels
// will be created automatically. History of channels are cleared when all
// people leave.

#include <channel.h>

inherit OBJ;
inherit M_GETTABLE;
inherit M_GRAMMAR;

string *adverbs = ({"green", "military", "amateur", "dented", "dirty", "old", "rusty", "orange"});

#define MAX_CHANNELS 100

int channel = random(MAX_CHANNELS) + 1;
int prev_channel;

// Handle when the radio is dropped or transferred between people.
void hook_func()
{
   if (!channel)
      return;

   if (!environment()->is_body())
   {
      this_body()->simple_action("$N $vturn off the $o.", this_object());
      channel = 0;
      // Remove the channel since we're not being held.
      CHANNEL_D->cmd_channel("c" + channel, "/off", CHANNEL_RESTRICTED);
   }
}

// Verb interaction. This tells the parser that this object can
// be "tune OBJ to WRD WRD", i.e. "tune radio to channel 50".
mixed direct_tune_obj_to_wrd_wrd()
{
   // If we do not hold the radio, we cannot tune it, so refuse.
   if (environment() != this_body())
      return "#That is not your radio.";
   return 1;
}

void do_tune_to(string wrd1, string wrd2)
{
   int tmp_chan;
   wrd1 = lower_case(wrd1);
   if (wrd1 != "channel")
   {
      write("Which channel do you want to tune the radio to?");
      return;
   }
   tmp_chan = to_int(wrd2);
   if (tmp_chan < 1 || tmp_chan > MAX_CHANNELS)
   {
      write("The channels on the " + short() + " go from 1-" + MAX_CHANNELS + ".");
      return;
   }

   // Save old channel, record new channel
   prev_channel = channel;
   channel = tmp_chan;

   // Show message about channel in room just to be cheeky.
   this_body()->simple_action("$N $vtune $p $o to channel " + channel + ".", this_object());
   CHANNEL_D->cmd_channel("c" + prev_channel, "/off", CHANNEL_RESTRICTED);
   CHANNEL_D->cmd_channel("c" + channel, "/new on restricted", CHANNEL_RESTRICTED);
}

// Show some extra information to the players, is the radio on, off, which channel.
string get_extra_long()
{
   return "It seems to be " + (channel ? "tuned to channel <010>c" + channel + "<res> right now" : "off") +
          ". It can probably be tuned to different stations, as it goes from 1-" + MAX_CHANNELS + ".";
}

// Setup the radio object.
void setup()
{
   string adv = choice(adverbs);
   set_id("radio transceiver", "transceiver", "radio");
   add_adj(adv); // Pick a random adverb for our radio.
   set_weight(0.5);
   set_long("A hand-held, portable, two-way " + adv + " radio transceiver with a station selector.");
   // This adds a hook for if the radio is dropped or given (is moved)
   add_hook("move", ( : hook_func:));
}
