//qianting.c

#include <ansi.h>
inherit ROOM;
/*
mapping check_lvl = ([
	"1" : "普通模式",
	"2" : "困难模式",
	"3" : "高手模式",
]);*/
//免费进入副本次数
int cs = 1;
void create()
{
        set("short", HIC"武馆前厅"NOR);
        set("long", @LONG
这是一间完全用花岗岩砌成的房子，两旁的墙壁上插着松油火把，把大厅
照的通亮，寂静的大厅中不时响起火把噼啪的燃烧声。大厅的正中摆放着一张
太师椅，两旁分列着十几把椅子，正面的墙上挂着一面缕金的横匾(bian)。再
往北去就是武馆的前院了。
LONG
        );
	set("no_fight",1);
	set("item_desc",([
            "bian" : HIY"				 
            ※※※※※※※※※※※※※※※※※※※※※※※※※
            ※※※※　　　　　　　　　  ※※※※
            ※※※※　                  ※※※※
            ※※※※   扬  州  武  馆   ※※※※
            ※※※※　                  ※※※※     
            ※※※※                    ※※※※※
            ※※※※※※※※※※※※※※※※※※※※※※※※※"NOR"\n",
		]));
	set("action_list", ([
		HIG"武馆训练"NOR:"ask_job 1",
	]));	 
        set("exits", ([
            "south" : __DIR__"menlang",
            "north" : __DIR__"dayuan",
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
		if (me->query("fuben/wuguan")) {
		ob_list = children("/adm/daemons/fuben_wuguan");
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
		if (to_int(local[4])+1 == 1 && local[3] >= 1 && local[3] <= 1) {
				ok = cs;
		}
		last = localtime(me->query("fuben/wuguan/times"));
		times = me->query("fuben/wuguan/mun");
		if(last[7]!=localtime(time())[7])
			me->set("fuben/wuguan/mun",0);
		else if(last[7]==localtime(time())[7]&&times>=2+ok && !wizardp(me))
		{
			tell_object(me, "今日已经任务你已经完成"+(2+ok)+"次了，明天再来吧。"NOR"\n");
			return 1;
		}
		/*
		str = ZJOBLONG"请选择：\n"ZJOBACTS2+ZJMENUF(2,3,9,30);
		str += "普通模式"+":ask_job 1"+ZJSEP;
		str += "困难模式"+":ask_job 2"+ZJSEP;
		str += "高手模式"+":ask_job 3";
*/
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

	if (!arg || (arg !="1" && arg !="2" && arg !="3")) {
		ask_quest();
		return 1;
	}
	if (to_int(arg) < 1 || to_int(arg)>3) {
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
	if (to_int(local[4])+1 == 1 && local[3] >= 1 && local[3] <= 1) {
			ok = cs;
	}
		last = localtime(me->query("fuben/wuguan/times"));
		times = me->query("fuben/wuguan/mun");
		if(last[7]!=localtime(time())[7])
			me->set("fuben/wuguan/mun",0);
			/*
		else if(last[7]==localtime(time())[7]&&times>=2+ok && !wizardp(me))
		{
			tell_object(me, "今日已经任务你已经完成"+(2+ok)+"次了，明天再来吧。"NOR"\n");
			return 1;
	}*/
	data = (to_int(local[4])+1)+"-"+local[3];
	if (me->query("fuben/wuguan/mun") <= cs)
	{
		me->set("fuben/wuguan/times",time());
		me->add("fuben/wuguan/mun", 1);
		me->add("fuben/wuguan/"+data, 1);
		me->move("/fuben/wuguan/enter");
		fb_room = new("/adm/daemons/fuben_wuguan");//改
		fb_room->init(me);
		fb_room->set("id", me->query("id"));
		tell_object(me, HIR"你正在进行武馆训练副本"NOR"\n");
	} else 
		tell_object(me, "你今天的任务次数已经没有了\n");
	return 1;
}