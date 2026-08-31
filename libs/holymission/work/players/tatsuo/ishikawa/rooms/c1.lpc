 inherit "room/room";
#include "/players/tatsuo/def.h
#include "players/tatsuo/break_string.h

  reset(arg)
{
  if(arg) return;

     set_light(0);
     short_desc("Serpent Cave");
     long_desc("You are in a tunnel leading deeper into the cave, The walls are composed of"+
               "a smooth, dark, gray rock. The floor is rough and pitted with many littles "+
               "holes. You are careful not to trip in them. The tunnel proceeds south into "+
               "darkness. There is light coming from the north.\n",65);
     items=({"walls","The walls are a smooth, gray, rock. They appear to be granite";
             "floor","The floor is rough and covered with little holes";
             "holes","The holes are very shallow and only appear to threaten unwary ankles";})

     dest_dir=({"IPATH+"c2","south"});
  return 1;
}
