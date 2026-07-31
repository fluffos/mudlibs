// shanyao.c  半山腰
// Modify By River@SJ 99.06
// Modify By Looklove@SJ 2000.10.24

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
    set("short", HIG"半山腰"NOR);
    set("long",@LONG
你已经来到这座山峰的半腰，由于此峰海拔极高，所以至此已遍地都是冰
雪了，阳光照在冰雪上面，反射过来，极为光亮刺目。山腰前面不远之处是悬
崖，阴森而深不见底。此处虽是终年积雪，但是有一处却好象经常有人用手拔
开，而隐隐露出一个小洞(dong)，恰能容入一身。向东方向是一条小路，直伸
入一片大森林之间。
LONG);
    	set("exits",([
        	"northdown" : __DIR__"sshanlu6",
        	"eastup"   :     __DIR__"ljroad1",
    	]));
    	set("item_desc", ([
		"dong" : "黑黑的一个山洞，什么也看不见。\n",
    	]));
    	set("coor/x",-320);
  	set("coor/y",110);
   	set("coor/z",80);
	setup();
    	set("outdoors", "明教光明顶");
}
void init()
{
       	object me = this_player();
        if(me->query_temp("mj/xunluo") && !me->query_temp("shanyao"))
           me->set_temp("shanyao",1);
        add_action("do_enter","enter");
	add_action("do_enter","zuan");	
}

int do_enter(string arg)
{
	mapping fam;
       	object me;
       	object *obj;
       	
	me = this_player();
       	if (arg != "dong") return 0;
       	
	if((fam = me->query("family")) && fam["family_name"] != "明教" )
       		return notify_fail("内面机关重重，你不是明教的，也想进去吗？！\n");

	obj = filter_array(deep_inventory(me),(: userp :));
	if(sizeof(obj)){
       		tell_object(me,"你负重过多，一不小心，头撞在山石上。\n");
       		obj[0]->move(environment(me));
       		me->unconcious();
		return 0;
    	}
       	message("vision",me->name() + "一弯腰往洞里钻了进去。\n",environment(me), ({me}) );
       	me->move(__DIR__"didao/bidao19");
       	message("vision",me->name() + "从洞里走了进来。\n",environment(me), ({me}) );
       	return 1;
}
