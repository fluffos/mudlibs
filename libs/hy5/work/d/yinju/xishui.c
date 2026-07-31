inherit ROOM;

void create()
{
  set("short","溪水");
  set("long",@LONG
这是一条溪水，前面一片湖水，原来这就是瀑布和
喷泉的源头
LONG);
  set("outdoors","yinju");
set("objects", ([
    __DIR__"npc/qiaofu": 1,
]));
set("exits",([
   "up"        : __DIR__"fengding",
   "westdown"  : __DIR__"pengquan",
        ]));
  setup();
}
int valid_leave(object me, string dir)
{
  
   if(dir=="up")
    {
       if(objectp(present("qiao fu", environment(me))) && 
(me->query("shen")<0))
            return notify_fail("樵夫拦住你说：家师不见外人！\n");
    }   
       return ::valid_leave(me, dir);
}