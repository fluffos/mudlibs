// Last modified by deforce on 07-03-2008
#include <mudlib.h>
inherit CMD;
inherit M_EXIT;

private mapping translations = ([ "n" : "north", "s" : "south", "e" : "east", "w" : "west", "ne" : "northeast", "nw" : "northwest", "se" : "southeast", "sw" : "southwest", "u" : "up", "d" : "down" ]);

private void main(string direction)
{
   if (direction)
   {
      object dir_room;

      if (translations[direction]) { direction = translations[direction]; }

      dir_room = environment(this_body())->query_exit_destination(direction);

      if (dir_room && (member_array(direction, environment(this_body())->query_exit_directions(wizardp(this_body()))) > -1))
      {
         if (dir_room->query_light() < 1)
         {
            out("It is too dark to see anything.\n");
         }
         else if (dir_room->query_light() > 9)
         {
            out("It is too bright to see anything.\n");
         }
         else
         {
            out(dir_room->long());
         }
      }
      else { out("You don't see anything in that direction.\n"); }
   }
   else { out("Usage: peer <exit>\n"); }
}