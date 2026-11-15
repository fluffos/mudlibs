#include <room.h>

inherit ROOM;

string *jieti_msg = ({
	HIM "你盘膝坐在地上，平心净气，试着将内息在体内循环十二周天，发现"
	HIM "完全畅通无阻，便运起无上心法"NOR"\n"	    
	HIR "	    转     世      重      修     大     法"NOR"\n",
	
	HIW "顿时只听得一阵阵巨雷滚滚而起，天空乌云密布，道道紫色闪电划破" 
	HIW "长空！你丝毫不感分心，按照转世重修大法所述将自身内力分成两部" 
	HIW "分，分别归入丹田与百汇中，只感觉丹田和百汇好像绝了堤的水坝一" 
	HIW "般，内力如滚滚洪水似的向前冲去，而内力所经过的经脉瞬间被摧毁。\n",

	HIC "经脉瞬间被毁的巨痛险些使你昏过去，身体传来撕心裂肺的痛苦，更" 
	HIC "是让你的脸完全扭曲了。一秒锺的时间都不到，但在你感觉好像经过" 
	HIC "一个世纪那麽长一般。"NOR"\n" ,

	HIM "两穴里冲出来的内力遍会集到龙回穴所处的地方，两股内力互相融合，" 
	HIM "慢慢形成太极形状，各分阴阳的流淌著，当所有内力集中在太极上後，" 
	HIM "整个太极图案突然一跳，而你的神经也跟著猛地跳动一下，你知道这"
	HIM "是龙回穴成功产生出来後的效果。"NOR"\n",

	HIY "就在这时，四周的灵气仿佛被什么牵引着疯狂的开始向你体内涌入，" 
	HIY "以惊人的速度飞快的从龙回穴往回开始修复损坏的经脉，瞬间在精神" 
	HIY "恍惚间你仿佛感觉回到了母亲的怀里般，终忍不住袭来的倦意，缓缓" 
	HIY "的睡过了去。。。。"NOR"\n",

	HIG "清晨醒来，乌云四散，清空万里，唯有大地一片寂静。。。。。\n",
	HIR "你发现体内的情况让你震惊，虽然内力已经减了近三成，但是却是生"
	HIR "生不息，取之不尽，用之不完，经脉也被拓宽了几倍。而在眉心已留" 
	HIR "下一小道红色胎记，仔细观察的话，会发现这块胎记如同一把倒立的" 
	HIR "宝剑一般，散发著阵阵煞灵之气，你摸了摸身子，发现身体外层好像" 
	HIR "脱皮一般，稀里哗啦的掉下不少老化的皮肤，而那些脱落旧皮後的新" 
	HIR "肌肤比以前更加的白嫩。"NOR"\n",
});

int do_jieti(string arg);
int do_decide(string arg); 

void create()
{
	set("short", "华山之巅");
	set("long", "这里是华山之巅，是天下群雄向往之地，据说许多前辈高人在此评武论剑，不断突破到更高境界，甚至有人曾在此破碎虚空乘风而去！");
	set("exits", ([
		"south" : __DIR__"jzroad7",
	]));
	set("no_fight",1);
	set("no_fly",1);
	set("objects",([
	]));
	set("action_list",([
		"转世重修":"jieti",
	]));
	setup();
}

void init()
{
	add_action("do_jieti","jieti");
}

int do_jieti(string arg)
{
	object me;
	string msg;
	me = this_player();

	msg = ZJOBLONG + HIY "转世重修是一种耗费大量的经验、武技来体悟中华武学精髓的方式，通过转世" +
		  "重修，可以大大的提升你的体质，无论是先天资质、精力上限、内力上限、还" +
		  "是你的自身潜力都会得到很大的提高，你战斗中的杀伤力也会大大的加强，你" +
		  "是否确定自己将进行转世重修？"NOR"\n";
	msg += ZJOBACTS2+ZJMENUF(3,3,10,30)+"确定:decide\n";

	me->set_temp("attempt_jieti",1);
	tell_object(me, msg);
	add_action("do_decide","decide");
	return 1;
}

int do_decide(string arg)
{
	object me = this_player();

	if (!me->query_temp("attempt_jieti"))
		return notify_fail("你想决定什么？\n");

    if(!wizardp(me))
	    return notify_fail("测试中，稍后开放！\n");

      if(me->query("combat_exp") < 50000000)
	       return notify_fail("经验不够还想转世？？\n");

	if(	me->query_skill("jiuyin-shengong")< 650
		&& me->query_skill("bluesea-force")< 650
		&& me->query_skill("never-defeated")< 650
		&& me->query_skill("kuihua-mogong")< 650
	)
		return notify_fail("你至少要有一门宗师机能达到650级以上才能转世重修！\n");

	if((int)me->query("max_neili")< 15000)
		return notify_fail("你的内力没有达到转世重修的条件！\n");
      if(me->query("magic_points") < 150000)
	       return notify_fail("你的灵慧没有达到转世重修的条件！\n");
      if(me->query_skill("martial-cognize",1) < 300 && me->query_skill("sword-cognize",1) < 300)
	       return notify_fail("你的武学修为没有达到转世重修的条件！\n");


	tell_object(me, HIW "你闭目沉思，良久，终于下定决心，进行转世重修！"NOR"\n""\n");

	me->delete_temp("attempt_jieti");
	call_out("jieti_msg", 0, me, 0);
	return 1;
}

void jieti_msg(object me, int stage, string place)
{
	string msg;

	if (stage == 5) me->revive();

	msg = HIR + jieti_msg[stage];
	tell_object(me, HIY + msg);
	if (stage < sizeof(jieti_msg) - 1)
	{
		if (stage == 4) me->unconcious();

		stage++;
		call_out("jieti_msg", 1, me, stage, place);
	} else
	{
		me->set("relife/martial_lvl",me->query_skill("martial-cognize",1));
		me->set("combat_exp",2000000);
		me->set("mud_age",1036800);//86400*3*4=18岁
		CHANNEL_D->do_channel(this_object(), "rumor", HIC"听说" + me->name(1) + "成功转世了！"NOR"\n");
		me->add("relife/zhuanshi",1);
		me->add("gain/max_qi",3000);
		me->add("gain/damage",150);//换成apply/damage吧
		me->add("gain/attack",150);
		me->add("gain/defense",150);
		me->add("max_neili",1000);
		me->add("max_jingli",1000);
		me->add("magic_points",10000);
		me->add("str",1);
		me->add("int",1);
		me->add("dex",1);
		me->add("con",1);
		UPDATE_D->check_user(me);
		me->save();
		log_file("zhuanshi", sprintf("%s：%s(%s) 在华山之颠成功转世重修。\n", ctime(time()),me->name(1),me->query("id")) );
	}      
	return;
}
