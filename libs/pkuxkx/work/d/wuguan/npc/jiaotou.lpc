//jiaotou.c
//by 诸葛不亮
//2009.8.16

#include <ansi.h>
#include <title.h>
inherit NPC;

string do_join();
void do_check();
int do_lg();
void greeting(object);
int do_decide();
int do_skill();
int do_rank();
int do_del_rank();
void init();

void create()
{
        set_name("武馆教头", ({ "wuguan jiaotou", "jiaotou" }) );
	set("title",HIC"太乙武馆教头"NOR);
        set("gender", "男性" );
        set("age", 60);
        set("long","这就是太乙武馆的教头，虽然他年纪已长，却依旧精神矍铄，\n道家太乙法门可谓名不虚传。\n");
        set("attitude", "peaceful");
        set("con", 25);
        set("str", 25);
        set("int", 20);
        set("dex", 10);
	set("per",500);
        set("max_qi", 2500);
        set("max_jing", 2500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 0);
        set("shen_type", 1);
		set("shen",50000);
        set("combat_exp", 250000);
		set("inquiry", ([
			"join" : (: do_join :),
			"加入" : (: do_join :),
			"加入武馆" : (: do_join :),
            "练功" : (: do_lg :),
            "练臂力" : (: do_lg :),
			"skill" : "武馆弟子输入skill可以查看教头技能。",
			"skills" : "武馆弟子输入skill可以查看教头技能。",
			"技能" : "武馆弟子输入skill可以查看教头技能。",
			"查看技能" : "武馆弟子输入skill可以查看教头技能。",
		    "称号" : (: do_rank :),
            "rank" : (: do_rank :),
            "title" : (: do_rank :),
            "去掉称号" : (:do_del_rank :),
		]));
        set_skill("force", 100);
        set_skill("strike", 100);
        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("literate", 150);
	set_skill("taiyi-shengong",100);
	set_skill("taiyi-zhang",100);
	set_skill("taiyi-jian",100);
	set_skill("taiyi-you",100);
	map_skill("force", "taiyi-shengong");
	map_skill("strike", "taiyi-zhang");
	map_skill("sword", "taiyi-jian");
	map_skill("dodge", "taiyi-you");
	map_skill("parry", "taiyi-jian");
	prepare_skill("strike", "taiyi-zhang");
	set("chat_chance", 10);
	set("chat_msg", ({
	name()+"手捋长须，说道：“身心意是谁分作两家？精气神由我抟为一处。”\n",
	name()+"说道：“太乙冲虚，江湖险恶，不求开宗立派，只求能平安隐退。”\n",
	name()+"对着弟子谆谆教导：“记住，道门冲虚，重厚积薄发，后发制人，先发而制于人也。”\n",
 	}));
setup();
carry_object("/d/city/obj/cloth")->wear();
carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
	object ob;

	::init();
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);
    if( interactive(ob = this_player()) && !is_fighting() ) {
            remove_call_out("greeting");
            call_out("greeting", 1, ob);
	}
	add_action("do_decide", "decide");
	add_action("do_skill", "skill");
//行动判定，decide加入，skill查看技能
}

int do_lg()
{
    object me=this_player();
    if (me->query("statistics/newbie_target/guo_finish"))
    {
        command("say 你已经练习有成，不必再费力了。");
        return 1;
    }
    if (me->query_temp("wg/permit"))
    {
        command("say 不要光说不练，快去吧。");
        return 1;
    }
    if (!me->query_temp("wg/start"))
    {
        command("say 无缘无故的，说这个干吗？");
        return 1;
    }
    me->delete_temp("wg");
    me->set_temp("wg/permit",1);
    command("say 那好吧，既然你要为国效力，那去练功房举举石锁，也可以练练臂力。");
    return 1;
}

string do_join()
{
	object me = this_object();
	object player = this_player();
	int leave_age;

	if (player->query("wuguan") == 1)
		return "你开什么玩笑？你已经是太乙中人了。";

		else
		{
		    player->set_temp("wuguan/join", 1);
			command( "say 很好，难得你对太乙之道有兴趣，不过，本武馆尚要维持生计，不能免费授艺" );
			return "你确认加入太乙武馆吗？(decide)";
		}
//加入武馆的ask
}

int do_decide()
{
	string name;
	object player = this_player();
	name = player->query("name");
	if (!player->query_temp("wuguan/join")) return 0;
	if (player->query("family"))
	{
		command( "say 往矣！非曳尾涂中之士，如何领悟太乙正道？" );
		return 1;
	}
	if (player->query("betrayer") > 0)
	{
		command( "say 往矣！非曳尾涂中之士，如何领悟太乙正道？" );
		return 1;
	}
	if (player->query("reborn/chushi")>=1)
	{
		command( "say 往矣！非曳尾涂中之士，如何领悟太乙正道？" );
		return 1;
	}
	if (player->query_skill("hunyuan-yiqi",1) > 0)
	{
		command( "say 往矣！非曳尾涂中之士，如何领悟太乙正道？" );
		return 1;
	}
	message_vision("$N决定加入太乙武馆\n", player);
	player->set("wuguan", 1);
	message_vision("$N站起身来，对$n作揖道：欢迎你给加入太乙武馆。\n\n", this_object(), player);
	message_vision("输入skill可以查看教头技能\n", this_object(), player);
	player->save();
	return 1;
//decide指令
}

int do_skill()
{
	object player = this_player();
	if (!player->query("wuguan")) return 0;
	tell_object(player, "武馆教头目前所学过的技能：（共十项技能）\n");
	tell_object(player, "\n");
	tell_object(player, "┌──一项基本知识────────────────────────┐\n");
	tell_object(player, "│  读书识字 (literate)                      - 心领神会 150/     0│\n");
	tell_object(player, "└────────────────────────────────┘\n");
	tell_object(player, "┌──五项基本功夫────────────────────────┐\n");
	tell_object(player, "│  基本轻功 (dodge)                         - 普普通通 100/     0│\n");
	tell_object(player, "│  基本内功 (force)                         - 普普通通 100/     0│\n");
	tell_object(player, "│  基本招架 (parry)                         - 普普通通 100/     0│\n");
	tell_object(player, "│  基本掌法 (strike)                        - 普普通通 100/     0│\n");
	tell_object(player, "│  基本剑法 (sword)                         - 普普通通 100/     0│\n");
	tell_object(player, "└────────────────────────────────┘\n");
	tell_object(player, "┌──四项特殊功夫────────────────────────┐\n");
	tell_object(player, "│□太乙神剑 (taiyi-jian)                    - 普普通通 100/     0│\n");
	tell_object(player, "│□太乙神功 (taiyi-shengong)                - 第四重楼 100/     0│\n");
	tell_object(player, "│□太乙神游 (taiyi-you)                     - 普普通通 100/     0│\n");
	tell_object(player, "│□太乙神掌 (taiyi-zhang)                   - 普普通通 100/     0│\n");
	tell_object(player, "└────────────────────────────────┘\n");
	return 1;
//skill指令
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/武馆"))
		return 0; 
	ob->add_temp("mark/武馆", -1);
	return 1;
//学习次数计算
}
int accept_object(object who, object ob)
{
	int money=1000;
	if (ob->query("money_id")) {
		if (ob->value() >= money) {
			if ((int)who->query_temp("mark/武馆") < 1)
				who->set_temp("mark/武馆", 1);
			message_vision("教头同意指点$N一些功夫。\n", who);
			who->add_temp("mark/武馆", ob->value()/10);
			return 1;
		}
		return notify_fail("你现在的学费是每次" + MONEY_D->money_str(money) + "。\n");
	}
	return 0;
//最低学费10两，每两silver可学习10次，若新人投入10wpot，则需100gold
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if( !this_object()->visible(ob)) return;
        say( "武馆教头长身立起，对你一抱拳：这位" + RANK_D->query_respect(ob) + "，不知来到太乙武馆，有何贵干？\n");
}

int do_rank()
{
	object me=this_player();
	if (me->query("wuguan") == 1)
	{
		command( "say 孔德之容，为道是从，太乙中人，当以散人为号" );
		me->set("title",HIC"太乙散人"NOR);
//title系统记录玩家title by seagate@pkuxkx
	  me->set_title(TITLE_RANK, HIC"太乙散人"NOR);
		return 1;
	}
	else
	{
		command( "say 阁下并非太乙中人，何出此问？" );
		return 1;
	}
}

int do_del_rank()
{
	object me=this_player();
	
	if (me->query("title") == HIC"太乙散人"NOR)
	{
		me->delete("title");
		command("say 你的头衔已经去掉了。");
	}
	else command("say 阁下何出此言？");
	return 1;
}