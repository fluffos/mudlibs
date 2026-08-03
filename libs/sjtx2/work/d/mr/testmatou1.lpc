// /d/mr/testmatou1.c
inherit ROOM;
#include <ansi.h>  
mapping *sign=({
([ 
	"name":"琴韵小筑",
	"id":"mr",
	"file":__DIR__"duchuan",
	"value":500
]),
([
	"name":"燕子坞",
	"id":"yanziwu",
	"file" :__DIR__"zhou",
	"value":1000
]),
});
string look_sign();
int do_go(string);

void create()
{
	set("short", "码头");
	set("long",@LONG
这里是慕容家的家仆和丫鬟出入太湖的水上码头，只见人们来来往往，一
个个风尘仆仆，码头边的老船夫见到你走过来，马上笑呵呵的迎了上去。码头
边张贴着一张价格表(sign)。
LONG 
);
	set("outdoors","慕容");
	set("exits",([
		"north" : __DIR__"shiqiao",
	]));
	set("item_desc", ([
		"sign" : (: look_sign :)
	]));

	setup();
}

void init()
{
	add_action("do_go", "qu");
//	add_action("do_yue", "yue");
}

string look_sign()
{
	string str="";
	int i=sizeof(sign);

	while (i--) {
		str += sign[i]["name"];
		str += "(" + sign[i]["id"] + ") ";
		str += MONEY_D->price_str(sign[i]["value"]) + "\n";
	}
	str += "慕容弟子免费。\n";
	return str;
}

void do_move(object ob, int i)
{
	if (ob->query("family/family_name") == "姑苏慕容") {
		message_vision(YEL"\n$N把和船家打了声招呼，船家领$N上了一条小舟。\n\n"NOR,ob);
	}
	else {
		message_vision(YEL"\n$N把钱交给船家，船家领$N上了一条小舟。\n\n"NOR,ob); 
	}
	ob->move(sign[i]["file"]);
}

int do_go(string arg)
{
	object ob=this_player();
	int i=sizeof(sign);

	if (!arg) return 0;
	if(ob->query_temp("ride_horse"))
		return notify_fail("对不起，这里只负责渡人！\n");
	if (ob->is_busy() || ob->is_fighting())
		return notify_fail("你正忙着呢！\n");
	while(i--) {
		if (arg == sign[i]["id"]) {
			if (ob->query("family/family_name") != "姑苏慕容") {
				switch (MONEY_D->player_pay(ob, sign[i]["value"])) {
					case 0: 
						return notify_fail("穷光蛋，一边呆着去！\n");
					case 2:
						return notify_fail("有零钱吗？\n");
				}
				message_vision("$N在口袋里翻来覆去地找船钱。\n", ob);
			}
			else {
				message_vision("船家上下打量着$N。\n", ob);
			}
			ob->start_busy(3);
			call_out("do_move", 3, ob, i);
			return 1;
		}
	}
	return notify_fail("你要去哪里？\n");
}

int do_yue(string arg)
{
	object me;
	me = this_player(); 

	if(!arg) return notify_fail("你要干什么？\n");
	if(arg != "hu") return notify_fail("你要干什么？\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");
	if (me->query_skill("dodge") < 400) 
		return notify_fail("你的修为不够！\n");
	if (me->query("max_neili") < 4000)
		return notify_fail("你的内力修为不够，怎能支持！？\n");
	if (me->query("neili") < 2000)
		return notify_fail("你的真气不够了！\n");
	if (me->query("jingli") < 1500)
		return notify_fail("你的精力不够了！\n");
	me->receive_damage("neili", 300);
	me->receive_damage("jingli", 150);
	tell_room(environment(me), HIY+me->name()+"向手心吐了两口吐沫，紧了紧腰带，施展「一苇渡江」绝技纵身跃过湖面！\n" NOR, ({me}));
	write("你向手心吐了两口吐沫，紧了紧腰带，施展「一苇渡江」绝技纵身跃过湖面！\n");
	me->move(__DIR__"anbian4");
	me->start_busy(3);
	tell_room(environment(me), HIY+me->name()+"飞身从湖对面跃起，在湖心当中芦苇上一点，从湖对面串了过来！\n" NOR, ({me}));
	return 1;
}
