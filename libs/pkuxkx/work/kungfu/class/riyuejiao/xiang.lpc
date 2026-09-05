// xiang.c 向问天
//by bing
#include "riyuenpc.h"
#include "riyuenpc2.h"

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include "/new_quest/qxiepai.h"
#include "/new_quest/quest.h"
string ask();
string ask_jiu();

void create()
{
        set_name("向问天", ({ "xiang wentian", "xiang" }));
        set("title",MAG "日月神教" NOR + HIY "左使" NOR);
	set("nickname",HIR "天王老子" NOR);
        set("long","他容貌清癯，颏下疏疏朗朗一丛花白长须，垂在胸前。眼中尽是傲然之色，
身型魁梧，你不禁赞叹：真是一条好汉子！\n");
        set("gender", "男性");
        set("age", 51);
        set("attitude","heroism");
        set("shen_type", -1);
	set("shen",-30000);
        set("str", 30);
        set("int", 30);
        set("con", 27);
        set("dex", 28);
        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 150);
        set("combat_exp", 800000);
	set("score",2000);
        set("chat_chance", 10);
        set("count",1);
        set("chat_msg", ({
                (: heal :),
		"向问天说道：「几年以前任教主突然失踪，东方不败这才坐上教主的位子......」\n",
		"向问天说道：「任教主的吸星大法天下少有对手，正教人物都为之丧胆。」\n",
		"向问天挠挠头，自言自语道：「让谁去救好呢？」\n",
        }));
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword.xuanmu" :),
		(: perform_action, "blade.lianhuan" :),
        }) );
        set("inquiry", ([
            "东方不败" : (: ask_df :),
            "东方教主" : (: ask_df :),
        "quest":   (: ask_quest() :),
        "cancelquest":   (: ask_cancel() :),
        "取消任务":   (: ask_cancel() :),
	    "任我行" : (: ask :),
	    "任教主" : (: ask :),
	    "救人" : (: ask_jiu :),
	    "令狐冲" : "他是我的结拜兄弟，也是圣姑盈盈的情郎，哈哈哈......",
	    "任盈盈" : "她是任教主的女儿，一般不住在黑木崖上，圣教主对她很尊重。",
	    "圣药" : "那是圣教主对有功之人的赏赐，吃了以后对教主更加忠心。在风雷堂童堂主处领取。",
	    "三尸脑神丹" : "那是圣教主对有功之人的赏赐，吃了以后对教主更加忠心。在风雷堂童堂主处领取。",
       ]) );

        set_skill("force", 150);
        set_skill("riyue-shengong", 180);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("kaishan-zhang", 150);
	set_skill("ryingzhua-gong",150);
	set_skill("claw",150);
	set_skill("sword",150);
	set_skill("riyue-jian",150);
	set_skill("blade",150);
	set_skill("riyue-dao",150);
        set_skill("feitian-shenfa", 150);
        set_skill("strike", 150);
        set_skill("literate",150);
        map_skill("force", "riyue-shengong");
        map_skill("parry", "riyue-jian");
        map_skill("dodge", "feitian-shenfa");
        map_skill("strike", "kaishan-zhang");
	map_skill("claw","ryingzhua-gong");
	map_skill("blade","riyue-dao");
        map_skill("sword","riyue-jian");
	prepare_skill("strike", "kaishan-zhang");
	prepare_skill("claw","ryingzhua-gong");
	prepare_wskill("blade","riyue-dao");
	prepare_wskill("sword","riyue-jian");
	reset_action();
	create_family("日月神教", 20, "弟子");
        setup();
        carry_object("/d/riyuejiao/obj/heiyi")->wear();
	carry_object("/d/riyuejiao/obj/yaodai")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/weapon/changjian")->wield();
       }

void attempt_apprentice(object ob)
{
	command("say 老夫我不收徒弟。");
}

string ask()
{
	object me;
	me = this_player();
	
	if (me->query("save_ren"))
	{
		return "任教主已经诛除了叛贼东方不败，现在成德殿主持教务。\n";
	}
	
	if (me->query("family/master_id") == "ren woxing")
	{
		return "哈哈哈哈..." + "任教主真是知人善任，人尽其才啊！\n";
	}

	if (me->query("family/master_id") == "dongfang bubai")
	{
		return "杨总管吩咐了，谁也不许提这个名字。\n";
	}

//	if (random(me->query("kar"))>12 && (string)me->query("family/family_name") == "日月神教")
	if ((string)me->query("family/family_name") == "日月神教")
	{	
		message_vision("向问天对着$N看了许久，说到：「我打听到任教主被东方不败这厮囚在梅庄地牢里。」\n",me);
		me->set_temp("riyue/ask_ren",1);
		message_vision( "向问天意味深长地叹了一口气。\n",me);
		return "怎么办好呢？\n";
	}
	return "杨总管吩咐了，谁也不许提这个名字。\n";
}

string ask_jiu()
{
	object me,ju;
	me = this_player();

    if (me->query("family/family_name") != "日月神教" )
    	return "你们外派的怎么跑到这里来了？\n";
    if (me->query("betrayer") > 0)
    {
        return "你是判到本教的，让我怎么能相信你呢？\n";
    }
    
    if (this_object()->query("count") == 0)
    	return "刚才已经有人来问过这个了，你们是串通好的么？\n";
    	
	if (me->query_temp("riyue/save_ren"))
	{
		return "快去呀!\n";
	}

	if (me->query_temp("riyue/ask_ren"))
	{
		message_vision("向问天想了一会儿，说到：「既然你有这忠心，这事就交给你办吧！这把钢丝锯你拿着，也许到时用得上。」\n",me);
		ju = new("/d/riyuejiao/obj/gangju");
		ju->move(me);
		message_vision("向问天给$N一把钢丝锯。\n",me);
		me->delete_temp("riyue/ask_ren");
		me->set_temp("riyue/save_ren",1);
		this_object()->set("count", 0);
		return "去吧！\n";
	}
	
	return "救什么人？\n";
}

		

	
