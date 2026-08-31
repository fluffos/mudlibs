/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** chanlist.c -- print available channels
**
** Print out the available channels in the system/intermud.  Note that
** the system allows any number of channels, so this will only print
** out some "suggested" channels.  This command is most effective for
** printing out a list of available Intermud channels.
**
** 950629, Deathblade: Created.
*/


//: PLAYERCOMMAND
//$$see: gossip, newbie, chan
// USAGE
//    ``chanlist``
//
// Shows currently existing channels available to you.
//
// .. TAGS: RST

#include <channel.h>

inherit CMD;

private
nomask string fmt_imud_channel(string channel_name, mixed *channel_data)
{
   string owner = channel_data[0];
   string type;
   string *valid_types = ({"unrestricted", "restricted", "filtered"});

   if (!channel_name || strlen(trim(channel_name)) == 0)
      return "";

   if (!intp(channel_data[1]))
      type = save_variable(channel_data[1]);
   else
      type = valid_types[channel_data[1]];
   if (owner == "*")
      owner = "no owner";

   return sprintf("%-20s Intermud: %s, %s\n", channel_name, owner, type);
}

private
void main(string arg)
{
   string s;
   mapping chanlist;

   string *all_chan = CHANNEL_D->query_channels();
   string *restricted_chan = filter(all_chan, ( : CHANNEL_D->query_flags($1) & CHANNEL_RESTRICTED:));
   string *wiz_chan = filter(all_chan, ( : CHANNEL_D->query_flags($1) & CHANNEL_WIZ_ONLY:));
   string *admin_chan = filter(all_chan, ( : CHANNEL_D->query_flags($1) & CHANNEL_ADMIN_ONLY:));
   string *imud_chan = filter(all_chan, ( : $1[0..4] == "imud_" :));
   string *player_chan = all_chan - wiz_chan - admin_chan - imud_chan - restricted_chan;

   s = "Listing of public channels\n--------------------------\n";

   foreach (string chan in player_chan)
      s += sprintf("%-20s Local\n", chan);

   if (wizardp(this_user()))
   {
      foreach (string chan in wiz_chan)
         s += sprintf("%-20s Wizard\n", chan);
      foreach (string chan in restricted_chan)
         s += sprintf("%-20s Restricted\n", chan);
   }

   if (adminp(this_user()))
      foreach (string chan in admin_chan)
         s += sprintf("%-20s Admin\n", chan);

   //  if ( wizardp(this_user()) )
   //  {
   //    foreach(string chan in imud_chan)
   //      s+= sprintf("%-20s Intermud\n", chan[5..]);
   //  }

   if (wizardp(this_user()))
   {
      if (find_object(IMUD_D))
      {
         catch (chanlist = IMUD_D->query_chanlist());
         s += "\nOther subscribable intermud channels\n"
              "------------------------------------\n";
         s += implode(({""}) + sort_array(keys(chanlist) - imud_chan, 1),
                      (
                          : $1 + fmt_imud_channel($2, $(chanlist)[$2])
                          :));
      }
      else
      {
         s += "No intermud channels currently available\n";
      }
   }
   out(s);
}
