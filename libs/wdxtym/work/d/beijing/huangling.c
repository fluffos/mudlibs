#include <ansi.h>
inherit ROOM;
//免费进入副本次数
int cs = 1;
void create()
{
	set("short", "十三皇陵");
	set("long", @LONG
这里就是著名的明十三皇陵，相当的宏伟壮观。十三皇陵坐落于紫禁城的
西郊，在这里游玩观赏的游人甚多。
LONG NOR);
	set("exits", ([
		"south" : __DIR__"guandao_2",
	]));
	set("action_list", ([
		HIM"十三皇陵"NOR:"ask_job 1",
	]));	 
        setup();
}
void init()
{
    add_action("ask_job","ask_job");
}

int ask_quest()
{
	object me = this_player();
	string str;
	mixed *local,*last;
	int times;
	int ok =0,i;
	object *ob_list,room;
	int k;
	
	if (userp(me)) {
		if (me->query("fuben/huangling")) {
		ob_list = children("/adm/daemons/fuben_huangling");
		for(i=0; i<sizeof(ob_list); i++)  {
		if (ob_list[i]->query("id") == me->query("id")) {
		if (room = find_object(ob_list[i]->query("enter")))
		if (me->move(room))
			tell_object(me, HIR"系统检测到你上次的副本还未结束\n"NOR);
			return 1;
			}
		}
	}
		local = localtime(time());
		if (to_int(local[4])+1 == 1 && local[5] >= 1 && local[5] <= 1) {
				ok = cs;
		}
		last = localtime(me->query("fuben/huangling/times"));
		times = me->query("fuben/huangling/mun");
		if(last[7]!=localtime(time())[7])
			me->set("fuben/huangling/mun",0);
		else if(last[7]==localtime(time())[7]&&times>=5+ok && !wizardp(me))
		{
			tell_object(me, "今日已经任务你已经完成"+(5+ok)+"次了，明天再来吧。"NOR"\n");
			return 1;
		}

		tell_object(me, str+"\n");
	}
	return 1;
}

int ask_job(string arg)
{
	object obj, me=this_player();
	object fb_room, *ob;
	int i, ok=0;
	int times;
	mixed *local,*last;
	string data;

	if (!arg || (arg !="1" && arg !="2" && arg !="5")) {
		ask_quest();
		return 1;
	}
	if (to_int(arg) < 1 || to_int(arg)>5) {
		tell_object(me, "你想干什么！"NOR"\n");
		return 1;
	}
	if (me->query_condition("killer")){
		tell_object(me, "你是杀人犯?！"NOR"\n");
		return 1;
	}
        if( me->query("eff_qi")<me->query("max_qi") )
               return notify_fail("你好像受伤了，不适合副本。\n");

        if( me->query("eff_jing")<me->query("max_jing") )
               return notify_fail("你好像受伤了，不适合副本。\n");
               	
	ob=deep_inventory(me);
	for (i=0;i<sizeof(ob);i++) {
		if (userp(ob[i])) {
			tell_object(me, "不支持组队！\n");
			return 1;
		}
	}

	me->delete_temp("ask_no");

	local = localtime(time());

	//免费提供一次进入机会
	if (to_int(local[4])+1 == 1 && local[5] >= 1 && local[5] <= 1) {
			ok = cs;
	}
		last = localtime(me->query("fuben/huangling/times"));
		times = me->query("fuben/huangling/mun");
		if(last[7]!=localtime(time())[7])
			me->set("fuben/huangling/mun",0);

	data = (to_int(local[4])+1)+"-"+local[5];
	if (me->query("fuben/huangling/mun") <= cs)
	{
		me->set("fuben/huangling/times",time());
		me->add("fuben/huangling/mun", 1);
		me->add("fuben/huangling/"+data, 1);
		fb_room = new("/adm/daemons/fuben_huangling");//改
		fb_room->init(me);
		fb_room->set("id", me->query("id"));
		tell_object(me, HIR"你正在进行十三皇陵副本"NOR"\n");
	} else 
		tell_object(me, "你今天的任务次数已经没有了\n");
	return 1;
}