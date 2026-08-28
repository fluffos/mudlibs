inherit ROOM;

create_room ()
{
  set_short ("obsolete room");
  set_long ("obsolete room, please move out!\n");
  add_exit ("out", "/world/hilltop/rooms/room1");
}

init ()
{
  add_action ("do_teleport", "");
}

do_teleport ()
{
  THIS->move_player("/world/hilltop/rooms/room1");
  return 1;
}
