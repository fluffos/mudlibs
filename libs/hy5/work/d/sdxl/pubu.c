// xtj
// by dubei

#include <ansi.h>
#include <room.h>

inherit ROOM;
//      int do_jump(string arg);
string pubu(object);

void create()
{
    set("short", BLU "瀑布"NOR);
    set("long", @LONG
转过一个山峡，水声震耳欲聋，只见山峰间一条大白龙似的瀑布(pubu)
奔泻而下，冲入一条溪流，奔胜雷鸣，湍急异常，水中挟著树枝石块，转眼
便流得不知去向。四顾水气蒙蒙，蔚为奇观。
LONG
    );

    set("outdoors", "xiangyang");
    set("item_desc", ([
        "pubu" : (: pubu :),
    ]));
    set("objects",([
               __DIR__"npc/diao" : 1,
                ]));
    set("exits", ([
        "southeast" : __DIR__"xiaolu2",
        "west" : __DIR__"xiaolu3",
    ]));

    setup();
 
}
void init()
{
	add_action("do_tiao", "tiao");
 
}
string pubu(object me)
{
     return "一条白龙相仿的瀑布，水流激荡，让人感觉心惊胆战。\n";
    }
int do_tiao(string arg)
{
	object me = this_player();

	if (me->is_busy()) return notify_fail("你正忙着呢！\n");
        
      if( !arg || arg == "" || arg != "pubu" )
           return notify_fail("你要往哪里跳？\n");

	if (me->query_dex() < 27)
		return notify_fail("你试图跳进瀑布中，但隆隆的水声使你腿有点发软。\n");

	if (me->query_skill("dodge") < 100)
		return notify_fail("你试图跳进瀑布中，却发现自己目前的轻功难以实现。\n");

        if (me->query_skill("force") < 110)
                return notify_fail("你试图跳进瀑布中，却发现自己内功修为似乎还欠缺火候。\n");

        if (!me->query_temp("yg_pbask")){
        message_vision("$N纵身提气，跃进了瀑布之中。！\n", me);
        write("你忽然感觉水势甚急，自己无法运气和水流向抗，被激流挤压的左摇右幌。\n",me);
        message_vision(RED"只见$N如稻草一样又从瀑布中飞了出来。\n"NOR, me);
        me->set_temp("xth_hm",1);
        me->unconcious();
        return 1;
        }
	message_vision("$N纵身提气，跃进了瀑布之中，使了个「千斤坠」身法，气沉下盘，稳稳站住。\n", me);
	me->move(__DIR__"pubu1");
	return 1;
}
