/* verte was here! */

#include <security.h>

int
cmd_reply(string arg)
{
    string replyer;

     if(!(replyer = (string)this_player()->Replyer()))
      return(notify_fail("You aren't replying to anyone.\n"), 0);
    if(!arg) return (notify_fail("Reply what to " + capitalize(replyer) + "?\n"), 0);
    return command("tell " + replyer + " " + arg, this_player());
}
