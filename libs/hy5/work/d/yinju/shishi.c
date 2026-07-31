inherit ROOM;

void create()
{
  set("short","石室");
  set("long",@LONG
这是一间干净的石室，陈设十分简陋。靠墙放了一张小木床，
地下几张蒲团，有两人坐在上面，眼睛微闭，好像睡去一般。
LONG);
 
set("objects", ([
    __DIR__"npc/yideng": 1,
  __DIR__"npc/sengren": 1,
]));
set("exits",([
   "west"  : __DIR__"zhulin",
  
        ]));
  setup();
replace_program(ROOM);
}