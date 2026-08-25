// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <daemons.h>

inherit CMD;

private void main(string str) {
  string dest;
  if ( !adminp(this_user()) )
    {
      out("对不起，只对大神开放。\n");
      return;
    }
  
  if (!str) {
    out("用法: mvemote <target> <destination>\n");
    return;
  }
  sscanf(str, "%s %s", str, dest);
  if (SOUL_D->move_emote(str, dest))
    out("移动了。\n");
  else out("失败了。\n");
}

