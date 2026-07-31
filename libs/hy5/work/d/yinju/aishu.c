inherit ROOM;

void create()
{
  set("short","矮树林");
  set("long",@LONG
这是一片茂密的矮树林。地上长满了长草，走在其间不见人烟
矮树林中还不时可以听到大自然发出的声响
LONG);
  set("outdoors","yinju");
   set("exits",([
   "east"    : __DIR__"nitang1",
   "eastup"  : __DIR__"yangchang",
   "southdown"  : "d/dali/road4",
        ]));
  setup();
}