#include <room.h>


inherit ROOM;

void create()
{
	set("short", "桃花山庄正门");
	set("long",@LONG
这里是桃花山庄的正门。门前疏落有致地种了几株桃花树，更显
得此地主人对桃花的偏爱。门口站着两个小童看守大门。看来由于地
处边远，人烟罕至，人们对山庄的防卫不是特别谨慎。门前有一对白
雕(diao)。
LONG);
	set("outdoors", "taohua");
	set("exits", ([
		"south" : __DIR__"qianyuan",
		"north" : __DIR__"tingzi",
		"east"  : __DIR__"road1" ,       
	]));
	set("item_desc", ([
		"白雕" : "一对白雕正展翅欲飞。如果是桃花岛的弟子，骑上(ride)就可以飞到中原。\n"
		ZJOBACTS2"骑上去:ride\n",
	]));
	set("objects", ([
		__DIR__"npc/shitong" : 2,
	]));
	set("outdoors", "taohua");
	setup();
}

void init()
{
    add_action("do_ride", "ride");
}

int do_ride()
{
    mapping myfam;
    object ob = this_player();

    if (objectp(query_temp("sb_ride")))
	 return notify_fail("现在白雕正忙着，请过一会再乘坐！\n" ) ;

    myfam = (mapping)ob->query("family");
    if (! myfam || myfam["family_name"] != "桃花岛")
    {
      	message_vision("$N一跃身跨上了白雕。只见白雕仰天长唳，突然猛然一颠...\n"
		       HIR "结果$N" HIR "摔了个鼻青脸肿！"NOR"\n"
		       "看来白雕对$N并不感兴趣，它只认识桃花岛的弟子。\n", ob);
      	ob->receive_damage("qi", 50);
      	ob->receive_wound("qi", 50);
      	return 1;
    }
    set_temp("sb_ride", ob);
    message_vision("$N一跃身跨上了白雕。只见白雕仰天长唳，突然展翅高飞。\n\n"
		   "但看一雕一人身形渐渐缩小，终至不见。\n", ob);
    ob->move(__DIR__"lantian");
    tell_object(ob, CYN "\n你不断地飞呀飞，万水千山身下飘过 ......"NOR"\n");
    call_out("taohua", 1, ob, environment(ob));
    return 1;
}

void taohua(object ob, object env)
{
	if (! objectp(ob))
		return;

	if (query_temp("sb_ride") == ob)
    		delete_temp("sb_ride");

	if (environment(ob) != env)
		return;

  	tell_object(ob, "你终于飞到了中原，白雕落了下来。\n\n");
  	ob->move("/d/guiyun/qianyuan");
}
