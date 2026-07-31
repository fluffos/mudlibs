// Room: /lingzhou/wangling.c

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "王陵通道");
	set("long", @LONG
这里是西夏陵墓的通道，陵墓造的异常宏大，然而一个石人武士拦着了你的去路。
LONG );
	set("exits", ([
		"south":__DIR__"qingxinquan",
	]));
	set("out_room",__DIR__"qingxinquan");
	set("objects", ([
	]));
	setup();
}

void heart_beat()
{
	object *inv;
	inv = all_inventory(this_object());
	if(!sizeof(inv)||(sizeof(inv)==1&&!playerp(inv[0])))
	{
		set_heart_beat(0);
		destruct(this_object());
	}
}

void no_die(object me)
{
	object ob;
	int num;

	if ( objectp(ob = present("wu shi",this_object())) )
	{
		num = time() - query("start_time");
		if(num>900) num = 900;
		num += 1000*(ob->query("max_qi")-ob->query("qi"))/ob->query("max_qi");
		if(num>0&&mapp(me->query("banghui")))
		{
			WARS_D->set_data("wangling/"+me->query("banghui/name")+"/pot",WARS_D->query_data("wangling/"+me->query("banghui/name")+"/pot")+num);
			tell_object(me,"你以生命为代价，在今天的王陵争霸赛中为本帮做出了"+num+"点贡献！\n");
		}
	}
}