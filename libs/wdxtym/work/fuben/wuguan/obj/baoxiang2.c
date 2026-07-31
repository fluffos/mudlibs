//baoxiang.c

#include <ansi.h>
inherit ITEM;
//随机爆出
string *random_item = ({
    "/clone/shizhe/jinsha",
});

void create()
{
	set_name("大宝箱", ({ "bao xiang" }));
	set("long", "一个大宝箱，可以"+ZJURL("cmds:open_1 bao xiang")+ZJSIZE(22)+"打开"NOR+"来看看。\n");
	set("unit", "个");
	set("value", 10);
	set("no_get", "箱子仿佛生了根一样，你使出吃奶的力气也搬不动。");
	set("action_list", ([
		"打开" : "open_1 bao xiang",
	]));
	set_weight(1000000);
	
	setup();
}
void init()
{
	add_action("do_open_1", "open_1");
}
int do_open_1(string arg)
{
	string id = random_item[random(sizeof(random_item))];//随机出物品列表
	object ob, obj;
	object me = this_player();
	object player;
	int i,num;
	object oba, obb, obc;
	int ok = 0;
	object *obs = all_inventory(environment(this_object()));
	
	if (!arg || arg != "bao xiang")
		return notify_fail("你想打开什么？！\n");
	
	oba = present("wuguan jiaotou", environment(me));
	oba = present("shouling", environment(me));	
	oba = present("gaoshou", environment(me));	
	oba = present("tongling", environment(me));
	oba = present("duizhang", environment(me));		
	
	foreach(player in obs) {
		if (userp(player))
		{
			if (oba) {
				oba->kill_ob(player);
				player->kill_ob(oba);
				tell_object(player, oba->name()+"要开宝箱得先打败我！\n");
				ok = 1;
			}
		}
	}
	if (ok > 0)
		return 1;
	message_vision( "$N打开了" + name() + "。"NOR"\n", me);
	
	if (!query("open_1")) {
	    num=10+random(me->query("kar"));
    if (me->query("kar")< 20 &&random(101) < 30||me->query("kar") > 20 &&random(101) > 30){	    	
		me->add("yuanbao_2",num);
		tell_object(me, "恭喜你获得"+num+"灵石票。\n");
		set("open_1", 1);		
	}else
		tell_object(me, "看来你的运气不是很好，箱子坏掉了。\n");		
        set("open_1", 1);		
	} else 
		tell_object(me, "这口箱子里的东西已经被人拿光了。"NOR"\n");
	
	return 1;
}
