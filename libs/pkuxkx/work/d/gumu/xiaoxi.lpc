//xiaoxi.c
inherit ROOM;

void create()
{
 set("short", "小溪");
set("outdoors","gumu");
 set("long", @LONG
    这是一终南山山洞中的一条小溪(river),小溪不是
很宽,但是你却不能看到底。也许可以游过去。
LONG
 );
 set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shandao3",
  "south": __DIR__"shandao4",
]));
setup();
}
void init()
{
  add_action("do_swim","swim");
  }
 
 int do_swim(string arg)
{
   object me;
   me=this_player();
    if (!arg||arg=="") return 0;
    if (arg=="river")
    {
     message("vision", me->name() + "扑通一声跳进小溪不见了\n", 
     environment(me), ({me}) );
                me->move(__DIR__"xidi");
                message("vision",
     me->name() + "从小溪里冒了出来 \n",
                environment(me),({me}) );
     return 1;
}
  }
