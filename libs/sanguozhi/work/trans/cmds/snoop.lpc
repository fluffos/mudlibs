// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// specification is: snoop [user] [str*]
// we will recieve: ({ user, ({ words }) })

#include <mudlib.h>
#include <log.h>

inherit CMD;

private void main(mixed *arg)
{
int rc;
    if ( !arg[0] )
        snoop();
    else
    {
        string msg;

        if ( arg[1] )
            msg = implode(arg[1], " ");
        else
            msg = //"no reason given";
                  "没来由";
        msg = sprintf(//"%s snooped %s because: %s\n",
                      "%s 监听 %s 原因：%s\n",
          this_user()->query_userid(),
          arg[0]->query_link()->query_userid(),
          msg);

rc = snoop(arg[0]->query_link());
if(rc)
          {
              LOG_D->log(LOG_SNOOP, msg);
          }
      }
    }
