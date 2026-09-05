//D:\xkx\d\liuxiu-shanzhuang\npc\youkunyi.c游鲲翼
// labaz 2012/10/22

#include <ansi.h>
inherit NPC;
#include "../newbie_village.h"

string ask_me(string);
int do_give(string);

void create()
{
	set_name(RED"游鲲翼"NOR, ({ "you kunyi", "you" }));
	set("title", "柳秀山庄庄主");
	set("nickname", "英雄迟暮");
	set("shen_type", 0);

	set("inquiry", ([
		   "here" : (: ask_me, "here" :),
		   "name" : (: ask_me, "name" :),
		   "葫芦" : (: ask_me, "hulu" :),
		   "闯荡江湖" : (: ask_me, "jianghu" :),		   
	]));
	
	set("gender", "男性");
	set("age", 35);
	set("long",
		"他就是柳秀山庄的主人。\n");
	set("no_get_from", 1);
	
	set("dex", 80);
	set("str", 80);
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set("qi", 100000);
	set("max_qi", 100000);
	set("jing", 100000);
	set("max_jing", 100000);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	setup();
}

void dest_hulu()
{
	object hl;
	if(objectp(hl=present("hu lu")))
	{
		destruct(hl);
	}
}
void init()
{
	object who;
	who=this_player();
	
	set_nextquest(who, "再次敲门，去见山庄庄主", "快把你身上的葫芦给游鲲翼吧", 20, 100);
	add_action("do_give","give");

}

int do_give(string arg)
{
	object me,who,ob;
	string target, item;
	
	me=this_player();

	if(!arg) return notify_fail("你要给谁什么东西？\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("你要给谁什么东西？\n");

        if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		return notify_fail("你正忙着打架呢。\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("这里没有这个人。\n");

	if( who == me) return notify_fail("自己给自己？！\n");

	if( who->query("env/no_accept") ) return notify_fail(who->name() + "不想接受任何物品。\n");

	if (("hulu"==item || "all"==item ) && objectp(present("hulu", me)))
	{
		if (1==check_questindex(me,"give hulu to you kunyi，把葫芦交给游鲲翼"))
		{
			present("hulu", me)->set("no_drop",0);
		}
	}
	return 0;
}

string ask_me(string arg)
{
	object who;
	who=this_player();
	
	switch(arg)
	{
		case "here" :
			if (0==who->query_temp("newbie/askyou") && 1==check_questindex(who, "向游鲲翼依次打听，here、name、葫芦、闯荡江湖"))
			{
				who->set_temp("newbie/askyou",1);
			}
			else
			{
				who->set_temp("newbie/askyou",0);
			}
			return "这里……现在是柳秀山庄。";
			
		case "name" :
			if (1==who->query_temp("newbie/askyou") && 1==check_questindex(who, "向游鲲翼依次打听，here、name、葫芦、闯荡江湖"))
			{
				who->set_temp("newbie/askyou",2);
			}
			else
			{
				who->set_temp("newbie/askyou",0);
			}
			return "在下不才，正是柳秀山庄庄主游鲲翼，山庄附近百里皆由在下打点。";
			
		case "hulu" :
			if (2==who->query_temp("newbie/askyou") && 1==check_questindex(who, "向游鲲翼依次打听，here、name、葫芦、闯荡江湖"))
			{
				who->set_temp("newbie/askyou",3);
			}
			else
			{
				who->set_temp("newbie/askyou",0);
			}
			return "让"+RANK_D->query_respect(who)+"劳心了，这葫芦只是庄内仆人的用具。";
		
		case "jianghu" :
			if (3==who->query_temp("newbie/askyou") && 1==check_questindex(who, "向游鲲翼依次打听，here、name、葫芦、闯荡江湖"))
			{
				who->set_temp("newbie/askyou",0);
				call_out("set_nextquest", 1, who, "向游鲲翼依次打听，here、name、葫芦、闯荡江湖", "你见他如此盛情，便也不好推辞，跟着丫鬟阿姝，让她带你熟悉一下山庄吧。", 50, 250);
				return RANK_D->query_respect(who)+"能有这份心思，实属不易。不过还是容在下招呼阁下几天，如若有不周之处，还望恕罪则个。\n既是有缘人，那请多盘桓几日。阿姝，带这位"+RANK_D->query_respect(who)+"好好休息休息，先在庄里做些事吧。\n";
			}
			else
			{
				who->set_temp("newbie/askyou",0);
                if (1==check_questindex(who,"洗完穿上衣服，向游鲲翼打听闯荡江湖"))
                {
					who->set_temp("newbie/fight",0);
                    call_out("set_nextquest",1, who, "洗完穿上衣服，向游鲲翼打听闯荡江湖", "你跃跃欲试，已经迫不及待了！快去尚武堂找武师试试身手吧。", 20, 100);
                    return RANK_D->query_respect(who)+"，敝庄尚武堂有几名武师，懂点三脚猫功夫，要不去跟他切磋一下试试。";
                }
                if (1==check_questindex(who,"向游鲲翼打听闯荡江湖！"))
                {
                    call_out("set_nextquest",1, who, "向游鲲翼打听闯荡江湖！", "你按照他的吩咐去做,出发之前先用(localmaps)查下柳秀票号在哪里。", 20, 100);
					who->set("balance",10000);
                    return "这位"+RANK_D->query_respect(who)+"切莫心急，庄里的武师甚是野蛮，得罪了阁下，把伤养好再说吧。\n我在柳秀票号为"+RANK_D->query_respect(who)+"存了些银两，我这里有事脱不开身，麻烦"+RANK_D->query_respect(who)+"自行取了，再去药铺买些药服下吧。";
                }
                if (1==check_questindex(who,"向游鲲翼打听闯荡江湖！！"))
                {
                    call_out("set_nextquest",1, who, "向游鲲翼打听闯荡江湖！！", "快去尚武堂，找武师拜师学艺去吧。(bai wushi)", 20, 100);
                    return RANK_D->query_respect(who)+"的伤势好转，让游某好生宽慰。"+RANK_D->query_respect(who)+"还是先熟悉熟悉武功，那几个武师我已训斥，他们答应传授些武功给你。";
                }
                if (1==check_questindex(who,"向游鲲翼打听闯荡江湖！！！"))
                {
                    call_out("set_nextquest",1, who, "向游鲲翼打听闯荡江湖！！！", "为民除害，哪能推辞？终于要正式上阵了，去树林手刃幼虎，以示武勇。", 20, 100);
                    tell_object(who,GRN"游鲲翼的脸上再次泛起了你熟悉的微笑。\n游鲲翼对你点了点头，似乎是赞许的模样。\n阿姝水汪汪的眼睛望着你，充满期待！\n");
                    return RANK_D->query_respect(who)+"，未明谷附近的树林有幼虎时常伤人，还望慷慨仗剑。畜生无情，下手要狠。\n你练的太乙剑法绝招当用则用。(perform sword.bafang)";
                }
                if (1==check_questindex(who,"向游鲲翼打听闯荡江湖！！！！"))
                {
                    call_out("set_nextquest",1, who, "向游鲲翼打听闯荡江湖！！！！", "不知游鲲翼让你看那本《江湖掌故》有何用意，还是去藏书阁读一读看看吧", 20, 100);
                    tell_object(who,GRN"游鲲翼对你竖起了大拇指，道：“好俊的身手！”\n");
                    return RANK_D->query_respect(who)+"看来热衷风尘世故，藏书阁有本《江湖掌故》，你先去看一下。";
                }
                if (1==check_questindex(who,"向游鲲翼打听闯荡江湖！！！！！"))
                {
                    call_out("set_nextquest",1, who, "向游鲲翼打听闯荡江湖！！！！！", "既然英雄要送你，却之不恭。在杏子林和游庄主道别。", 20, 100);
                    tell_object(who,GRN"游鲲翼对你竖起了大拇指，道：“好俊的身手！”\n");
                    return RANK_D->query_respect(who)+"真的要走了吗？那么……好吧，且让我在杏子林送你一程。";
                }

				// 1==check_questindex(who, "向游鲲翼依次打听，here、name、hulu、jianghu")
				// 1==check_questindex(who, "向游鲲翼依次打听，here、name、hulu、jianghu")
				// 1==check_questindex(who, "向游鲲翼依次打听，here、name、hulu、jianghu")
				// 1==check_questindex(who, "向游鲲翼依次打听，here、name、hulu、jianghu")
				// 1==check_questindex(who, "向游鲲翼依次打听，here、name、hulu、jianghu")
				// 1==check_questindex(who, "向游鲲翼依次打听，here、name、hulu、jianghu")
				
			}
			
	}
	return RANK_D->query_respect(who)+"能有这份心思，实属不易。";
}

int accept_object(object who, object ob)
{
	// if (ob->query("id")=="hulu" && ob->qurery("name")=="[33m"+"葫芦")
	if (ob->query("id")=="hu lu")
	{
		message_vision(GRN"游鲲翼起身恭敬接过葫芦，低头看了看，喃喃道：“剧饮千杯男儿事，杏子林中，商略平生义……“\n\n"NOR, who);
		if (1==check_questindex(who,"give hulu to you kunyi，把葫芦交给游鲲翼"))
		{
			call_out("dest_hulu",1);
            call_out("set_nextquest", 1, who, "give hulu to you kunyi，把葫芦交给游鲲翼", "游鲲翼似乎对你言而不尽，看看能不能问个明白。\n向游鲲翼依次打听：here、name、葫芦、闯荡江湖。", 20, 100);
			return 1;
		}
	}
	return 0;
}

