//tianjing 梅庄天井
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","梅庄天井");
	set("long",@LONG 这是一个大天井，天井左右各植一棵老梅，枝干如铁，极是苍劲。天井
西面是梅庄招待客人的客房，东面传来阵阵香气，原来是厨房。南面是庄门。
正面就是客厅了。
LONG
	);

	set("exits", ([
		"north" : __DIR__"keting",
		"west"	: __DIR__"guestroom",
		"east"	: __DIR__"chufang",
	]));
	set("outdoors","riyuejiao");
	setup();

}

void init()
{
	add_action("do_open","open");
}

int do_open(string arg)
{
	object me = this_player();
	if (!arg || (arg != "door" && arg != "gate"))
		return notify_fail("你要打开什么？\n");
	message_vision("$N抓住门上的把手，向后一拉，门「吱呀」一声开了。\n",me);
	set("exits/south" , __DIR__"meizhuang");
	return 1;
	
}

void do_close(object me)
{
	tell_room(__DIR__"tianjing","两个家丁走上前去，将庄门关上。\n");
	if (me)
	message_vision("两个家丁上前把庄门「咣当」一声关了个严严实实。\n",me);
	delete("exits/south");
}

int valid_leave(object me, string dir)
{
	object* inv;
	int i;
        inv = deep_inventory(me);


        if (dir == "south" && !query("exits/south"))
                return notify_fail("你「咣」的一声撞到了门上，脑袋上登时起了个大包。\n");
	if (dir == "south")
	{
/*	        for(i=sizeof(inv)-1; i>=0; i--)
        	    if((inv[i]->query("name") == "鹰爪功秘诀") || (inv[i]->query("name") == "开山掌法精要"))
			return notify_fail("不能带着梅庄的武功密笈离开这里！\n");
*/
		
		tell_room(__DIR__"meizhuang","庄门徐徐打开，" + me->query("name") + "走了出来。\n");
		call_out("do_close",1,me);
	}
        return ::valid_leave(me, dir);
}



