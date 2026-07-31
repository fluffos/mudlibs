inherit ROOM;

void create()
{
  set("short","石梁");
  set("long",@LONG
山道从此断开，有几个突出的石梁，但是有个书生
坐在其中石梁之上，如果有人要经过，就必须书生
的同意！
LONG);
  set("outdoors","yinju");
set("objects", ([
    __DIR__"npc/shusheng": 1,
]));
set("exits",([
   "west"  : __DIR__"shimiao",
  "east"  : __DIR__"shanlu",
        ]));
  setup();
}
int valid_leave(object me, string dir)
{
  
   if(dir=="west")
    {
       if(objectp(present("zhu ziliu", environment(me))) && 
(me->query_temp("answer_shusheng")!=1))
            return notify_fail("书生拦住你说：家师不见外人！\n");
    }   
       return ::valid_leave(me, dir);
}
