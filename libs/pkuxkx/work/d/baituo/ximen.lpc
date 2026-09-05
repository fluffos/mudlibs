inherit ROOM;
void create()
{
  set("short","西门");
  set("long",
       "这是个山庄的西门。拱月形的竹门分外雅致，门两边还种着几杆\n"
   "修竹，门上挂着一块竹牌(pai)。西门外面杂草丛生。很是荒凉。\n"
      );
  set("exits",([
      "west" : __DIR__"cao1",
      "east" : __DIR__"changlang",
     ]));
  set("item_desc",([
  "pai" : "西门外面有毒蛇出没，慎行。\n" ,
  ]));
  set("objects",([
    __DIR__"npc/menwei" : 1,
    ]));
 set("outdoors", "baituo");
 setup();
}
int valid_leave(object me, string dir)
{
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);  
    if ((dir == "east") && (me->query("shen") > 300)
    && objectp(present("men wei", environment(me)))
    && living(present("men wei", environment(me))))
         return notify_fail("门卫把手一拦：你这种所谓的正派人物不能进去！\n");
    return ::valid_leave(me, dir);
}
