inherit ROOM;

void create()
{
  set("short","茅屋");
  set("long",@LONG
这是一个小茅屋,桌上点着蜡烛.屋中只有一桌一床,
陈设简单,却十分干净.床上铺着被褥.
LONG);
  set("outdoors","yinju");
set("objects", ([
    __DIR__"npc/yinggu": 1,
]));

set("exits",([
   "northwest"  : __DIR__"shitu",
   "southwest"  : __DIR__"chitang",
   "south" :__DIR__"neishi",
   ]));
  setup();
}
