#include <ansi.h>
#include "/obj/lib/living/settings.h"

int cmd_topkill()
{
  mixed *top_kill;
    
  if (this_player()->query_ghost())
  {
    write("You are in an immaterial state with no scores.\n");
	  return 1;
  }
  
  top_kill = (mixed *) this_player()->query_top_kill();
  if( top_kill ) {
    write("Top Kill: " +comma_number(top_kill[0])+"\n");
    write("Name:     " +top_kill[1]+"\n" );
    write("Location: " +top_kill[2]+"\n" );
    write("Date:     " +ctime(top_kill[3])+"\n" );
  }
  else 
    write("No Kills Yet.\n");
  return 1;
}
