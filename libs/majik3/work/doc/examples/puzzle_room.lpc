// puzzle_room.c
//   - example of coding simple puzzle, by Namhas (29.07.97)

inherit ROOM;

create_room ()
{
  set_light (1);
  set_area ("example");
  set_short ("puzzle room");
  set_long (
    "You are standing in a strange puzzle room. There is a blue panel "
  + "in the northern wall. Light blue mist is creeping on the floor " 
  + "and slowly moving to the north. You also notice there is no exits "
  + "and this does not exists!\n");

  add_item ( ({ "panel", "blue panel", "wall", "nothern wall" }),
             "You see a very strange panel, coded inside the northern wall. "
           + "It has strange numbers placed on it, maybe you could turn them?\n");
}

init ()
{
  ::init();

  add_action ("do_puzzle", "turn");
}

do_puzzle (string numbers)
{
  int i, x, y, z;
  string number;

  if (numbers && sscanf (numbers, "%d %d %d", x, y, z) == 3)
    {
      write ("You slowly turn numbers in the panel to: "+x+" "+y+" "+z+"\n");

      if (x == 4)
        i++;
      if (y == 8)
        i++;
      if (z == 3)
        i++;

      if (!i) {
        write ("Nothing happens.\n");
        return 1;
      }

      if (i == 2)
        number = "two";
      if (i == 3)
        number = "three";

      if (i == 1)
        write ("You hear strange 'click' sound echoing from the panel.\n");
      else
        write ("You hear strange 'click' sound echoing from the panel " +
          number + " times.\n");

      if (i == 3) {
        write ("*THUD* A trapdoor opens under your feet and you fall down!\n");
        THIS->move("/world/city/start");
      }
      return 1;
    }
  else
    {
      notify_fail ("usage: turn <n> <n> <n>, where <n> is number between 0 and 9.\n");
      return 0;
    }
}

