// seeker 06/04/2000

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int abil();

int cmd_track(string str)
{
 mixed *tracks;
 mixed *track;
 int i;
 if (!abil())
   {
    write("What?\n");
    return 1;
   }
 if (!str || str=="")
   {
    notify_fail("Track what?\n");
    return 0;
   }
 say (this_player()->query_cap_name()+" searches for tracks on the ground.");
 this_player()->add_sp(-random(5));
 tracks = environment(this_player())->query_tracks();
 if (!tracks)
   {
    write("There are no tracks on the ground.");
    return 1;
   }

 i = sizeof(tracks);
 while(i--)
   {
    track = tracks[i];
    if (capitalize(str)==track[0])
      {
       write(capitalize(str)+"'s tracks lead "+track[1]+".");
       return 1;
      }
   }
 write("You failed to find "+capitalize(str)+"'s track.");
 return 1;
}

void help()
{
 write("Syntax: <track [person]>\n\n"
       "You can use this to check for tracks on the ground to find where "
       "a person was going. ");
}
int abil() {
 if (this_player()->query_level() >= 10 &&
     this_player()->query_subclass() == "ranger") return 1;
 if (this_player()->query_subclass() == "scout" &&
     this_player()->query_level() >= 10) return 1;
}
