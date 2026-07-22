// /u/beyond/mr/houtang.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"后堂"NOR);
         set("long", @long
这里摆着一张小床，床头是一张女人用的梳妆台，上面放着许多胭脂粉盒。
靠窗是一张长长的红木书桌，只要抬眼望去，太湖的万顷碧波，尽收眼底。
long);

	set("exits",([
		"north" : __DIR__"xiaoting",
	]));
	setup();
}

void init()
{
	add_action("do_zuan", "zuan");        
}

int do_zuan(string arg)
{
	object me = this_player();
	mapping myfam;
	
	myfam = (mapping)me->query("family");
	
	if(!arg || arg != "didao")
		return notify_fail("你要往哪里钻？\n");       
     
        if ( myfam && myfam["family_name"] != "姑苏慕容")
            return notify_fail(" gg");
            
	message_vision("$N一转身，忽然一下子钻到地下不见了。\n",me);
	me->move(__DIR__"didao");
	message("vision",me->name() + "从水池边跃了上来。\n",environment(me), ({me}) );
        return 1;
}
