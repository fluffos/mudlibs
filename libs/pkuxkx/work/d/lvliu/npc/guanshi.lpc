#include <ansi.h>
inherit NPC;
string ask_biwu();
string ask_reward();
int do_decide(string arg);

void create()
{
        set_name("管事", ({ "guan shi", "guan" }));
		set("title",HIM "比" HIW "武" HIC "场"NOR);
        set("long","他大约20多岁年纪，是比武场的管事，负责安排比武场的事务。\n");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 26);
		set("combat_exp", 5000000);
		set("str", 50);
        set("int", 50);
        set("con", 50);
        set("dex", 50);
        set("max_qi", 10000);
        set("max_jing", 10000);
        set("neili", 30000);
        set("max_neili", 20000);
        set("jiali", 100);
        set("score", 500000);
		set_skill("force", 500);
        set_skill("jiuyin-zhengong", 500);
        set_skill("xuanming-zhangfa", 500);
        set_skill("dodge", 500);
        set_skill("jiuyin-shenfa", 500);
        set_skill("strike", 500);  
        set_skill("parry", 500);
        map_skill("force","jiuyin-zhengong");
        map_skill("dodge","jiuyin-shenfa");
        map_skill("strike","xuanming-zhangfa");
        map_skill("parry","xuanming-zhangfa");
		set_temp("apply/armor", 300);
		set_temp("apply/damage", 100);
        prepare_skill("strike", "xuanming-zhangfa");
		set("inquiry",([
			"赵敏": "那是我们郡主，她现在就在庄内招待各路英雄。",
			"比武": (: ask_biwu :),
			"test": (: ask_biwu :),
			"奖励": (: ask_reward :),
			"间隔时间": "你可以用 decide <秒数> 来决定比武间隔，秒数在2～10之间。",
			]));
        setup();
}

void init()
{
	add_action("do_decide", "decide");
}

int do_decide(string arg)
{
	int x;
	object me = this_player();
	if (!arg || sscanf(arg, "%d", x) !=1)
		return notify_fail("你可以用 decide <秒数> 来决定比赛间隔，秒数在2～10之间。\n");
	if (x<2 || x>10)
		return notify_fail("秒数只能在2～10之间。\n");
	message_vision("$N对$n点了点头：好的，你下一场比武的时间间隔设置为 "+x+" 秒！\n", this_object(), me);
	me->set("lvliu/biwuchang/set_interval", x);
	return 1;
}

int bwc_in_use(string bwc)
{
	object room;
    room = load_object("/d/lvliu/"+bwc);
	if (objectp(room))
		return room->in_use();
	return 1;
}

string ask_reward()
{
	object me=this_player();
	int exp,qn,re;
	string msg;
	
	exp = me->query_temp("lvliu/biwuchang/reward_exp");
	if (exp<=0)
		return "尊客别闹了，没有战胜我庄武士，何来奖励一说？";
	re = me->query_temp("lvliu/biwuchang/reward_re");
	qn = me->query_temp("lvliu/biwuchang/reward_qn");
	me->delete_temp("lvliu/biwuchang");
	
	msg = "你被奖励了：\n";
	exp = REWARD_D->add_exp(me, exp);
	msg += "\t"+chinese_number(exp)+"点经验；\n";
	qn = REWARD_D->add_pot(me, qn);
	msg += "\t"+chinese_number(qn)+"点潜能；\n";
	re = REWARD_D->add_rep(me, re);
	msg += "\t"+chinese_number(re)+"点声望。\n\n";
	me->add("exp/lvliu_biwuchang", exp);
	tell_object( me, HIW + msg + NOR);	
	CHANNEL_D->do_channel(this_object(), "rw",
		sprintf("%s在「绿柳山庄·比武场」中获得经验%s点、潜能%s点、声望%s点。", 
			me->query("name"), chinese_number(exp), chinese_number(qn), chinese_number(re)));
	me->set("lvliu/biwuchang/start", time()+ 600); // 任务CD 10分钟？
	COMBAT_D->add("task_stat/lvliu_biwuchang/reputy",re);
	COMBAT_D->add("task_stat/lvliu_biwuchang/potential",qn);
	COMBAT_D->add("task_stat/lvliu_biwuchang/exp",exp);
	COMBAT_D->add("task_stat/lvliu_biwuchang/expratio", to_float(exp)/me->query("combat_exp"));
	if (exp>10000)
		return "尊客武艺高超，敝庄佩服之致！";
	else if (exp>3000)
		return "尊客身手不错，敝庄佩服！";
	return "尊客身手不错！";
}

string ask_biwu()
{
	string *bwc = ({ });
	object room, bw;
	object me=this_player();
	if (me->query("combat_exp")<5000000) //5m
		return "以阁下的身手……还是上楼观赏罢，下场比试我怕害了阁下的性命。";
	if ((int)me->query("lvliu/biwuchang/start")>time())
		return "阁下才刚参加过比试，还是多休息片刻再来吧。";
	if ( ! bwc_in_use("biwuchang1") ) bwc += ({"biwuchang1"});
	if ( ! bwc_in_use("biwuchang2") ) bwc += ({"biwuchang2"});
	if ( ! bwc_in_use("biwuchang3") ) bwc += ({"biwuchang3"});
	if ( ! bwc_in_use("biwuchang4") ) bwc += ({"biwuchang4"});
	if (sizeof(bwc)<=0)
		return "现在四座比武场中都有人正在比试，还请阁下稍带片刻。";
	command("ok");
	tell_object(me, HIY"管事上下打量了你一番，点了点头，说道：「刀剑无眼，请多加小心！」\n"NOR);
    room = load_object("/d/lvliu/biwukantai");
	bw = load_object("/d/lvliu/"+bwc[random(sizeof(bwc))]);
	if (objectp(bw))
	{
		if (objectp(room))
			tell_room(room, HIC"只听楼下一阵喧哗，有人高声道：\n\n    " HIW + "「" + me->query("name")
				+ HIW " 下『" + bw->query("short") + HIW "』比武挑战，有请尊客观赏(sight)！」\n\n"NOR);
		me->move(bw);
	}
	COMBAT_D->add("task_stat/lvliu_biwuchang/times", 1);
	return "好的，小的马上为您安排。";
}


