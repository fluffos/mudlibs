// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** chan.c
**
** General channel command.
**
** 06-Nov-94. Created. Deathblade.
*/

#include <mudlib.h>
#include <daemons.h>

inherit CMD;


void create()
{
  ::create();
  no_redirection();
}

private void main(string arg)
{
    string channel_name;
    int chan_type;

    if(this_body()->chan_disabled()) {
            out("你的频道交流特权被取消了，请在线WIZ帮你恢复。\n");
            return;

    }
    if ( !arg || arg == "" || (wizardp(this_user()) && arg == "-d") )
    {
        string * channel_list;

        channel_list = this_body()->query_channel_list();
        if ( sizeof(channel_list) == 0 )
            out("你目前没有收听任何频道。\n");
        else
        {
            if ( arg != "-d" )
                channel_list = map(channel_list,
                                   (: CHANNEL_D->user_channel_name($1) :));

            out("你目前在收听的频道有：" +
                  implode(channel_list, ", ") + ".\n");
        }
                                     
        return;
    }

    if ( sscanf(arg, "%s %s", channel_name, arg) != 2 )
    {
        channel_name = arg;
        arg = "";
    }

    /* COMPATIBILITY: if there is no '_' in the name, prepend plyr_ */
//    if ( member_array('_', channel_name) == -1 )
//      channel_name = "plyr_" + channel_name;

    chan_type = channel_name[0..4] == "imud_";

    CHANNEL_D->cmd_channel(channel_name, arg, chan_type);
}
