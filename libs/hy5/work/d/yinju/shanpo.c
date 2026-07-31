inherit ROOM;

void create()
{
  set("short","山坡");
  set("long",@LONG
这里是陡峭的山坡。此处山势陡峭，登山的人一个不
小心很容易便会跌堕到崖谷之中。
LONG);
  set("outdoors","yinju");
set("objects", ([
    __DIR__"npc/nongfu": 1,
__DIR__"npc/niu": 1,
]));
set("exits",([
   "west"  : __DIR__"shanlu",
   "east"  : __DIR__"pingdi",
        ]));
  setup();
}
int valid_leave(object me, string dir)
{
  
   if(dir=="west")
    {
       if(objectp(present("wu santong", environment(me))) && 
(me->query_temp("help_nongfu")!=1))
            return notify_fail("农夫拦住你说：家师不见外人！\n");
    }   
       return ::valid_leave(me, dir);
}



