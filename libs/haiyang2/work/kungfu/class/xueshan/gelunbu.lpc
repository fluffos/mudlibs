// /kungfu/class/xueshan/gelunbu.c  葛伦布
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_fashi();
string ask_fashi2();
void create()
{
        set_name("葛伦布", ({ "gelunbu", "ge" }));
        set("long",@LONG
葛伦布是雪山寺中护寺僧兵的头领。同时向本寺第子传授武功。
身穿一件黑色袈裟，头带僧帽。
LONG
        );
        set("title", HIY "喇嘛" NOR);
        set("nickname", HIG "僧兵头领" NOR);
        set("gender", "男性");
        set("age", 30);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 200);
        set("int", 20);
        set("con", 28);
        set("dex", 25);

        set("max_qi", 10000);
        set("max_jing", 5000);
        set("neili", 10000);
        set("max_neili", 1000);
        set("jiali", 20);
        set("combat_exp", 800000);
        set("score", 40000);

        set_skill("lamaism", 280);
        set_skill("literate", 130);
        set_skill("force", 180);
        set_skill("xiaowuxiang", 180);
        set_skill("dodge", 175);
        set_skill("shenkong-xing", 170);
        set_skill("parry", 160);
        set_skill("cuff", 100);
        set_skill("staff", 180);
        set_skill("xiangmo-chu", 370 );
        set_skill("unarmed", 160);
        set_skill("yujiamu-quan", 160);
        set_skill("sword", 160);
        set_skill("mingwang-jian", 160);

        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("parry", "xiangmo-chu");
        map_skill("staff", "xiangmo-chu");
        map_skill("sword","mingwang-jian");
        map_skill("unarmed","yujiamu-quan");
	set("inquiry", ([
		"准备法事" : (: ask_fashi :),
		"法事" : (: ask_fashi :),
		"开始法事" : (: ask_fashi2 :),	
	]));

        create_family("雪山寺", 5, "喇嘛");
        set("class", "bonze");

        setup();

        carry_object("/d/xueshan/obj/b-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        carry_object("/d/xueshan/obj/senggun")->wield();

        add_money("silver",100);
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	int bonus;
//	if( !ob || environment(ob) != environment() ) return;
//	if( environment(ob)->query("short") == "雪山祭坛" )
	if (!(int)ob->query_temp("作法事")) return;
	{
message_vision("葛伦布急急忙忙吩咐小喇嘛们往祭坛里填柴，倒酥油。\n\n", ob);
message_vision(HIR"$N点燃了祭坛中的木柴与酥油，熊熊烈火冲天而起。\n", ob);
message_vision(HIB"一丝魂魄升出祭坛，冉冉而起。魂魄受$N佛法感召，徘徊不去。\n", ob);
message_vision(RED"$N端起颅钵吸进一口水，「噗」的一声猛地朝那熊熊火焰喷将过去。\n", ob);
message_vision(HIC"$N盘腿打坐，神光内蕴，口中念念有辞，渐渐有一丝魂魄在$N面前凝聚成形。\n", ob);
message_vision(HIG"魂魄越聚越多，竟然呈出人形！$N手指人形，口念真言，指引往生之路。\n", ob);
message_vision(HIW"$N手持法铃，边走变摇，高声诵读密传经咒。突然大喝一声。声似雷霆。\n", ob);
message_vision(HIY"大院里光芒四起，一声巨响过后，又恢复了平静。超度完毕。\n"NOR, ob);
		if (ob->query_temp("作法事") > (int)ob->query("combat_exp"))
		{
			bonus= ob->query_skill("lamaism",1) / 2;
			if ((int)ob->set_temp("玩家法事"))
{
				ob->add("combat_exp", random(2000) + 300);
				ob->add("potential", random(400) + 200);
                                ob->start_busy(8);
}
	                	else 
{
				ob->add("combat_exp", random(300) + 200);
				ob->add("potential", random(230) + 80);
                                ob->start_busy(8);
}
		}
		else
message_vision(HIR"\n$N不知道哪里找了个菜鸟煞有介事地来超度，看来是白忙了。\n"NOR, ob);
				ob->add("jing", -(int)ob->query("jing")/8);
				ob->add("qi", -(int)ob->query("qi")/8);
                                ob->start_busy(8);
                                ob->delete_temp("作法事");
		command("say 法事已经做完。");
	        ob->apply_condition("gelunbu",5+random(8));
if (present("corpse",this_object()))
destruct(present("corpse",this_object()));
if (present("skeleton",this_object()))
destruct(present("skeleton",this_object()));
//		command("drop corpse");
//		command("drop skeleton");
		//command("go north");
		//command("go east");
		//command("go south");
                                	}
}

void attempt_apprentice(object ob)
{

        if ((string)ob->query("gender") != "男性") {
                command("say 修习密宗内功需要纯阳之体。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
        }

        command("say 我就传你一些武功吧！");
        command("recruit " + ob->query("id"));

        if((string)ob->query("class") != "bonze")       {
                ob->set("title","雪山派俗家弟子");
        }
        else    {
                ob->set("title",HIY"小喇嘛"NOR);
        }
}
string ask_fashi()
{
	mapping fam; 
		object where,env,obj;
        string region;
	int sp, dp;
	int i, cost;
	int lvl, diff, busy_time;
	        int b1,b2;
int maxpot;	   
	object ob = this_player();
	object me = this_player();

	if( environment(this_object())->query("short") != "雪山祭坛" )
		return "这里正在做法事，你没看见麽？";
	if (!(fam = ob->query("family")) || fam["family_name"] != "雪山寺")
		return "你是那里跳出来的毛虫，也能做个屁法事？";
	if ( ob->query_skill("lamaism",1) < 30)
		return "你的密宗心法还早得很呢，没法让你开坛做法事。";

	if ( ob->query_skill("longxiang",1) < 30 && ob->query_skill("xiaowuxiang",1) < 30)
		return "你的本门内功还早得很呢，没法让你开坛做法事。";


         if(ob->query_condition("gelunbu")>0)
         return "你刚刚做过法事,还跑这里瞎嚷嚷什麽?";
        if (me->is_fighting()) 
        return "你正打的热闹着呢!";
                if (me->is_busy())
                return "你正热闹着呢!";

if( !environment(me)->query("no_fight"))
{
if (random(40)==1 && me->query("combat_exp") > 1000000)
{
obj=new("/quest/menpaijob/shenlong/menggu"); 
obj->move(environment(me));
obj->do_copy(me,maxpot,2);
obj->set("title",HIY"巡山官兵"NOR);
obj->set("usename",me->query("name"));
me->start_busy(1);
message_vision(HIC"附近走来一名很凶狠的巡逻官兵！\n"NOR, obj);
message_vision(RED"$N说道: 你这个妖僧竟敢私自处理尸体，我特来消灭你这等妖僧！\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
return "先把这恶官兵消灭再说吧？";
}
}

	ob->set_temp("法事",1);
	return "这位上人是要给哪位施主做法事呀？";
}

int accept_object(object who, object ob)
{
	object myenv ;
	if (!(int)who->query_temp("法事"))
	{
		message_vision("葛伦布笑着对$N说：这种臭东西给我有什么用，您还是自己留着吧！\n", who);
		return 0 ;
	}
	who->delete_temp("法事");
	if (ob->query("id") == "corpse")
	{
		message_vision("葛伦布笑着对$N说：那我们去祭坛吧！\n", who);
		who->set_temp("作法事", ob->query("combat_exp"));
		if ((int)ob->query("userp"))
			who->set_temp("玩家法事", 1);
//	who->set_leader(this_object());
//                destruct(ob);
		//command("go north");
		//command("go west");
		//command("go south");
 
		return 1;
	}
	else  
		message_vision("葛伦布对$N说：这种东西还能做法事？直接埋了省事。\n", who);
	return 0;
}
string ask_fashi2()
{
	int bonus;
//	if( !ob || environment(ob) != environment() ) return;
//	if( environment(ob)->query("short") == "雪山祭坛" )
object ob = this_player();
if (!ob->query_temp("作法事")) 
{
	command("say 这位上人是要给哪位施主做法事呀？");
return "没有尸体做什么法事啊？";
}
	if (!(int)ob->query_temp("作法事")) return "这位上人是要给哪位施主做法事呀？";
	{
message_vision("葛伦布急急忙忙吩咐小喇嘛们往祭坛里填柴，倒酥油。\n\n", ob);
message_vision(HIR"$N点燃了祭坛中的木柴与酥油，熊熊烈火冲天而起。\n", ob);
message_vision(HIB"一丝魂魄升出祭坛，冉冉而起。魂魄受$N佛法感召，徘徊不去。\n", ob);
message_vision(RED"$N端起颅钵吸进一口水，「噗」的一声猛地朝那熊熊火焰喷将过去。\n", ob);
message_vision(HIC"$N盘腿打坐，神光内蕴，口中念念有辞，渐渐有一丝魂魄在$N面前凝聚成形。\n", ob);
message_vision(HIG"魂魄越聚越多，竟然呈出人形！$N手指人形，口念真言，指引往生之路。\n", ob);
message_vision(HIW"$N手持法铃，边走变摇，高声诵读密传经咒。突然大喝一声。声似雷霆。\n", ob);
message_vision(HIY"大院里光芒四起，一声巨响过后，又恢复了平静。超度完毕。\n"NOR, ob);
		if (ob->query_temp("作法事") > (int)ob->query("combat_exp"))
		{
			bonus= ob->query_skill("lamaism",1) / 2;
			if ((int)ob->set_temp("玩家法事"))
{
				ob->add("combat_exp", random(2000) + 300);
				ob->add("potential", random(400) + 200);
                                ob->start_busy(8);
}
	                	else 
{
				ob->add("combat_exp", random(300) + 200);
				ob->add("potential", random(230) + 80);
                                ob->start_busy(8);
}
		}
		else
message_vision(HIR"\n$N不知道哪里找了个菜鸟煞有介事地来超度，看来是白忙了。\n"NOR, ob);
				ob->add("jing", -(int)ob->query("jing")/8);
				ob->add("qi", -(int)ob->query("qi")/8);
                                ob->start_busy(8);
                                ob->delete_temp("作法事");
		command("say 法事已经做完。");
	        ob->apply_condition("gelunbu",5+random(8));
if (present("corpse",this_object()))
destruct(present("corpse",this_object()));
if (present("skeleton",this_object()))
destruct(present("skeleton",this_object()));
}



}