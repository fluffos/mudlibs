#include <daemons.h>
#include <objects.h>
#include <security.h>
#include <config.h>

inherit OB_USER;


void create()
{ 
 seteuid(geteuid());
}
int bleh(string str)
{
 string dte, *dir, tmp;
 int a, b;
 if (!str || str=="") return 1;
 
 dir = get_dir(str+"/");
 if (!dir) return 1;
 b = sizeof(dir);
 
/* seteuid( UID_USERSAVE );   */

 while(b--)
   {
    sscanf(dir[b], "%s.o", tmp);
    tmp = str + "/"+tmp;
    restore_object(tmp);
    if(member_array(query_position(), MORTAL_POSITIONS) == -1)
      { write(query_true_name()+" immortal skipped");
         continue;
      }
    sscanf(last_on, "%s:%s:%s %s", tmp,tmp,tmp, dte);
    a = to_int(dte);
    if (a < 1998) this_player()->force_me("rid "+query_true_name());
   }
 return 1;
}
