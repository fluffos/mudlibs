inherit ROOM;

#include "../path.h"

create_room ()
{
  set_short ("Linguistics guild");
  set_long (
    "You are standing in linguistics guild. You can get some "
  + "'info', and 'train' some languages, 'advance' guild level and do "
  + "something "
  + "else too. This place is under construction and is available only "
  + "temporarily - unless new language training system is available.\n");

  add_exit ("west", ROOM_PATH + "cave3");
 



  add_object (MONSTER_PATH + "linguist");
}

init_guild ()
{
  add_action ("do_info", "info");
  add_action ("do_join","join");
  add_action ("do_advance","advance");
  add_action ("do_train","train");
}
