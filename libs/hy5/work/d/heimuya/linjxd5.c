// ROOM : linjxd5.c
inherit ROOM;
void create()
{
  set("short","林间小道");
  set("long", @LONG
你走在一条阴暗的林间小道上，两旁是阴森森的树林。一阵
阵风吹过树梢，发出沙沙的响声，令你不寒而栗。忽然你发现树
丛中有两点绿芒，一闪即没！！
LONG );
  set("exits",([
      "southup" : __DIR__"dating1",
      "north" : __DIR__"linjxd4",     
      "east"  : __DIR__"linjxd3",
      "west"  : __DIR__"linjxd5",
  ]));
  set("objects",([
      __DIR__"npc/wolf" : 4 ,
   "quest/skills2/wunon/dalie/dalie" : 2,
  ]));
//  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
