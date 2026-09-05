// Room:gu2
inherit ROOM;
#include <room.h>
void create()
{
        set("short", "山谷口");
        set("long", @LONG
一片辽阔的山谷，四山合抱，苍峰滴翠，一道清溪横流过，水波溶溶，游鱼
可数。沿溪一带，绿柳垂扬，如丝如缕，清溪对岸，半坡繁花间，隐隐现出一栋
精舍，四外花枝环绕，灿若云锦。放眼谷底(di)望去，对面却是一片茂密的树林。
LONG
        );

       set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"gu1",
 
]));
set("outdoors", "xingxiuhai");
set("item_desc", ([ 
        "di" : "谷底花团锦簇，入口(enter di)却极为隐秘。\n",  
   
   ])); 
set("objects",([__DIR__"npc/li":1,]));
     
      setup();

}

void init()
{
    add_action("do_enter","enter");
}

int do_enter(string arg)
{
    object gu,me=this_player();
    if (me->query("family/family_name")!="星宿派")
    {
        return notify_fail("看似花团锦簇，你却觉得暗藏杀机，还是不进为妙。\n");
    }
    if (me->is_busy()||me->is_fighting())
    {
        return notify_fail("你正忙着呢。\n");
    }
    if (!arg||arg!="di")
    {
        return notify_fail("你要“进”哪里？\n");
    }
    me->add_busy(1);
    gu=load_object(__DIR__"gu3");
    message("vision", me->name()+"向谷底方向离开。\n",environment(me), ({me}) );
    tell_room(gu,me->name()+"从山谷口走了过来。\n");
    me->move(gu);
    return 1;
}