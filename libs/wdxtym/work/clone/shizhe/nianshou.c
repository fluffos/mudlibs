
#include <ansi.h>

inherit NPC;

void clean_me()
{
	return;
}

mapping att_lv = ([
	"普通[1节爆竹]":1,
	"强力[5节爆竹]":5,
	"重击[25节爆竹]":25,
]);

string *ob_list = ({
		"/clone/gift/fudai",
	"/clone/vip/putao",
	"/clone/vip/jinsha",
	"/clone/vip/lingzhi",
	"/clone/vip/tianxiang",
	"/clone/vip/book_tianfu",
	"/clone/vip/book_wuliang",
	"/clone/vip/jinpiao",
	"/clone/gift/fudai",
	"/clone/vip/dan_chongmai1",
	"/clone/vip/dan_chongmai2",
	"/clone/vip/dan_chongmai1",
	"/clone/vip/dan_chongmai2",
	"/clone/vip/dan_chongmai3",
	"/clone/vip/putao",
	"/clone/vip/jinsha",
	"/clone/vip/lingzhi",
	"/clone/vip/tianxiang",
	"/clone/gift/fudai",
	"/clone/vip/book_tianfu",
	"/clone/vip/book_wuliang",
	"/clone/vip/putao",
	"/clone/vip/jinsha",
	"/clone/vip/dan_chongmai4",
	"/clone/vip/putao1",
	"/clone/gift/fudai",
	"/clone/gift/cagate",
	"/clone/gift/ccrystal",
	"/clone/gift/cdiamond",
	"/clone/gift/cjade",
	"/clone/vip2/xuanling",
});

string *ob_list1 = ({
		"/clone/vip/ling_wolong",
	"/clone/gift/fudai",
	"/clone/vip/dan_int",
	"/clone/vip/dan_str",
	"/clone/vip/dan_dex",
	"/clone/gift/fudai",
	"/clone/vip/ling_wolong",
	"/clone/vip/dan_con",
	"/clone/vip/putao1",
	"/clone/vip/dan_int",
	"/clone/vip/tiancs",
	"/clone/vip/dan_chongmai4",
	"/clone/vip/dan_str",
	"/clone/vip/dan_chongmai4",
	"/clone/vip/dan_dex",
	"/clone/vip/dan_chongmai4",
	"/clone/vip/dan_con",
	"/clone/vip/dan_chongmai4",
	"/clone/gift/agate",
	"/clone/gift/crystal",
	"/clone/gift/diamond",
	"/clone/gift/jade",
	"/clone/vip/jiuzhuan",
	"/clone/vip/tiancs",
	"/clone/vip/butian",
	"/clone/vip/ling_wolong",
	"/clone/gift/fudai",
	"/clone/vip/dan_int",
	"/clone/vip/dan_str",
	"/clone/vip/dan_dex",
	"/clone/gift/fudai",
	"/clone/vip/ling_wolong",
	"/clone/vip/dan_con",
	"/clone/vip/putao1",
	"/clone/vip/dan_int",
	"/clone/vip/tiancs",
	"/clone/vip/dan_chongmai4",
	"/clone/vip/dan_str",
	"/clone/vip/dan_chongmai4",
	"/clone/vip/dan_dex",
	"/clone/vip/dan_chongmai4",
	"/clone/vip/dan_con",
	"/clone/vip/dan_chongmai4",
	"/clone/gift/agate",
	"/clone/gift/crystal",
	"/clone/gift/diamond",
	"/clone/gift/jade",
	"/clone/vip/jiuzhuan",
	"/clone/vip/tiancs",
	"/clone/vip/butian",
	"/clone/tianji1/qilin",
	"/clone/tianji1/huanyutianjing",
});

void create()
{
	set_name(HIR"年兽"NOR, ({ "nian shou" }) );
	set_weight(99999999);
	set("long", "头长触角，尖牙利齿；目露凶光，凶猛异常。长年深居海底，每到除夕才爬上岸，吞食牲畜伤害人命。\n");
	set("unit", "只");
	set("no_get", 1);
	set("qi",10000);
	set("acts_list",([
		"驱赶":"duobao",
	]));
	set("max_qi",10000);
	setup();
}

void do_back()
{
	CHANNEL_D->do_channel(this_object(), "rumor","听说年兽年兽在人间肆虐一圈后不知所踪，请广大英雄豪杰留意年兽的下次侵袭。" NOR);
	destruct(this_object());
}

void get_damage(object me, int damage, int type)
{
	object ob,obj;

	ob = this_object();

	me->add("potential",damage*60);
	tell_object(me,"只听噼里啪啦一阵声响，你对年兽造成"+damage+"点伤害，获得"+damage*60+"点潜能。\n");
	if((damage > random(1600)) || (random(90)==50))
	{
		obj = new("/clone/vip/jiuzhuan");
		CHANNEL_D->do_channel(ob,"rumor", me->query("name")+"重创年兽获得"+obj->short()+"。");
		log_ufile(me,"qilin","重创("+damage+")年兽获得"+obj->short()+"。\n");
		tell_object(me,"你重创年兽获得"+obj->short()+"。\n");
		obj->move(me);
	}
	if((damage > random(300)) || (random(20)==10))
	{
		obj = new(ob_list1[random(sizeof(ob_list1))]);
		CHANNEL_D->do_channel(ob,"rumor", me->query("name")+"重创年兽获得"+obj->short()+"。");
		log_ufile(me,"qilin","重创("+damage+")年兽获得"+obj->short()+"。\n");
		tell_object(me,"你重创年兽获得"+obj->short()+"。\n");
		obj->move(me);
	}
	if((damage > random(100)) || (random(6)==1))
	{
		obj = new(ob_list[random(sizeof(ob_list))]);
		CHANNEL_D->do_channel(ob,"rumor", me->query("name")+"重创年兽获得"+obj->short()+"。");
		log_ufile(me,"qilin","重创("+damage+")年兽获得"+obj->short()+"。\n");
		tell_object(me,"你重创年兽获得"+obj->short()+"。\n");
		obj->move(me);
	}
	ob->add("qi",-damage);
	message("vision", ZJCHARHP+"look "+file_name(ob)+ZJSEP+ob->query("qi")+":"+ob->query("max_qi")+":"+ob->query("max_qi")+"\n", 
				filter_array(all_inventory(environment(ob)), (: interactive($1) :)) );
	if(ob->query("qi")<=0)
	{
		obj = new(ob_list[random(sizeof(ob_list))]);
		CHANNEL_D->do_channel(ob,"rumor", me->query("name")+"对年兽造成致命一击获得"+obj->short()+"。");
		log_ufile(me,"qilin","对年兽造成致命一击("+damage+")获得"+obj->short()+"。\n");
		tell_object(me,"你对年兽造成致命一击获得"+obj->short()+"。\n");
		obj = new("/clone/gift/fudai");
		obj->move(me);
		tell_object(me,"你对年兽造成致命一击获得"+obj->short()+"。\n");
		obj->move(me);
		if(damage > random(500) || random(5)==1)
		{
			obj = new(ob_list1[random(sizeof(ob_list1))]);
			CHANNEL_D->do_channel(ob,"rumor", me->query("name")+"对年兽造成致命一击获得"+obj->short()+"。");
			log_ufile(me,"qilin","对年兽造成致命一击获得"+obj->short()+"。\n");
			tell_object(me,"你对年兽造成致命一击获得"+obj->short()+"。\n");
			obj->move(me);
		}
		if(damage > random(220) || random(5)==2)
		{
			obj = new("/clone/vip/vip2/dan_jiuzhuan");
			CHANNEL_D->do_channel(ob,"rumor", me->query("name")+"对年兽造成致命一击获得"+obj->short()+"。");
			log_ufile(me,"qilin","对年兽造成致命一击获得"+obj->short()+"。\n");
			tell_object(me,"你对年兽造成致命一击获得"+obj->short()+"。\n");
			obj->move(me);
		}
		destruct(ob);
	}
}

void init()
{
	object ob,me;

	me = this_player();
	ob = this_object();
	if(playerp(me))
	{
		tell_object(me,ZJCHARHP+"look "+file_name(ob)+ZJSEP+ob->query("qi")+":"+ob->query("max_qi")+":"+ob->query("max_qi")+"\n");
		tell_object(me,ZJCHARHP+"look "+file_name(ob)+ZJSEP+ob->query("qi")+":"+ob->query("max_qi")+":"+ob->query("max_qi")+"\n");
		add_action("do_duobao","duobao");
	}
}

int do_duobao(string arg)
{
	object me,ob;
	string *lvs,str;
	int lv;

	me = this_player();

	if(me->is_busy())
		return notify_fail("你正在忙着呢！\n");

	if(!objectp(ob=present("bao zhu",me)))
		return notify_fail("你身上没有爆竹，无法对年兽造成有效伤害！\n");

	if(!arg)
	{
		str = ZJOBLONG"年兽乃传说之物，只有用爆竹才能对其造成一定的伤害，寻常难以靠近半步"ZJBR"请选择攻击强度：\n";
		str += ZJOBACTS2+ZJMENUF(3,3,10,30);
		str += "普通[1节爆竹]:duobao 普通[1节爆竹]"ZJSEP;
		str += "强力[5节爆竹]:duobao 强力[5节爆竹]"ZJSEP;
		str += "重击[25节爆竹]:duobao 重击[25节爆竹]";
		tell_object(me,str + "\n");
		return 1;
	}

	if(!att_lv[arg])
		return notify_fail("选择错误，请重新选择！\n");

	if(ob->query_amount() < att_lv[arg])
		return notify_fail("你身上没有那么多爆竹！\n");
	ob->add_amount(-att_lv[arg]);
	tell_object(me,HIG"你点燃一些爆竹向年兽掷去！"NOR"\n");
	me->start_busy(1);
	get_damage(me,att_lv[arg]*10,2);
	return 1;
}
