// ren2.c 救出之后的任我行
//by bing

inherit NPC;
inherit F_MASTER;

#include "riyuenpc2.h"
#include <ansi.h>
void heal();
void consider();

void create()
{
        set_name("任我行", ({ "ren woxing", "ren" }));
        set("title",MAG "日月神教" NOR + HIR "教主" NOR);
        set("long","他长须垂至胸前，头发须眉都是深黑之色，全无斑白。身材魁梧,端的是个桀傲不驯的人物。
十多年前，他的教主位置为东方不败所篡，直到近几年才重新夺回此位。\n");
        set("gender", "男性");
        set("age", 65);
        set("attitude","heroism");
        set("shen_type", -1);
	set("shen",-50000);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 2000);
        set("max_jing", 2000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 200);
        set("combat_exp", 11000000);
	set("score",5000);
          set("chat_chance", 10);
        set("chat_msg", ({
		"任我行说道：「东方不败再厉害，也不是照样为我所擒？」\n",
                (: heal :),
		"任我行说道：「东方不败这厮奸诈之极，竟能骗得过我，真是让我佩服。」\n",
		"任我行自言自语道：「令狐冲那小子，竟敢不听我号令！不过他是盈盈的意中之人，这事倒也难办。」\n",
        }));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: consider :),
        }) );
        set("inquiry", ([
            "东方不败" : "哼！还提这厮作什么？莫非你想学他？！",
            "东方教主" : "你管这贼厮鸟叫教主？我才是日月神教的教主！",
	    "任我行" : "老夫就是任我行！你也知道我的名头？",
	    "任教主" : "老夫就是任我行！你也知道我的名头？",
	    "任盈盈" : "她是我的宝贝女儿。她有了情郎，就不顾老爸了，女生外向，呵呵呵......",
	    "圣药" : "那是我对有功之人的赏赐，吃了以后对我更加忠心。在风雷堂童堂主处领取。",
	    "三尸脑神丹" : "那是我对有功之人的赏赐，吃了以后对我更加忠心。在风雷堂童堂主处领取。",
	    "令狐冲" : "他是我女儿的意中人，不过这小子不听我号令，总会吃苦头的。嘿嘿......",
       ]) );

        set_skill("force", 300);
        set_skill("xixing-dafa", 300);
        set_skill("riyue-shengong",300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("kaishan-zhang", 300);
	set_skill("ryingzhua-gong",300);
	set_skill("claw",300);
	set_skill("sword",300);
	set_skill("riyue-jian",300);
	set_skill("blade",300);
	set_skill("riyue-dao",300);
        set_skill("feitian-shenfa", 300);
        set_skill("strike", 300);
        set_skill("literate",270);
        map_skill("force", "xixing-dafa");
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
	create_family("日月神教", 19, "弟子");
        setup();
        carry_object("/clone/armor/cloth")->wear();
	carry_object("/clone/weapon/gangdao");
	carry_object("/clone/weapon/changjian");
       }
void init()
{
	object ob;
	mapping fam;
        ::init();
	ob = this_player();
	if (interactive(ob) && !is_fighting()) {
		remove_call_out("greet");
		call_out("greet", 1, ob);
	}
	add_action("do_flatter","say");
}

int do_flatter(string arg)
{
        if(this_player()->query_temp("riyue/flatter") )
                return 0;
        if( !arg ) return notify_fail("你说我什么？\n");
        message_vision("$N大声说道：" + arg + "\n", this_player());
        if( strsrch(arg, "圣教主文成武德，仁义英明，中兴圣教，泽被苍生。") >=0)
	{
                command("smile");
                command("say 嗯。\n");
		this_player()->set_temp("riyue/flatter",1);
        }
        return 1;
}

void attempt_apprentice(object ob)
{
	if ( ((int)ob->query("riyue_drug") != 0) && (ob->query("family/family_name") != "日月神教" ))
	{
	   command("say 大胆叛逆，竟敢反出神教，我今天就为教除逆！\n");
	   command("kill "+ob->query("id"));
	   return;
	}

	if ( !ob->query("save_ren"))
	{
	   command("heng " + ob->query("id"));
	   command("say 救我出来你未立寸功，让我怎么收你？");
	   return;
	}

	if (ob->query("family/family_name") != "日月神教")
	{
	   command("say 我们日月神教拜师要从堂主拜起，" + RANK_D->query_respect(ob) + "先去拜堂主吧！\n");
	   return;
	}
	
	if ((string)ob->query("family/master_id") == "dongfang bubai")
	{
	   command("say 东方不败的徒弟？怎么跑到我这儿来了？");
	   command("say 想给你师傅报仇？好啊，受死吧！");
	   command("kill " + ob->query("id"));
	   return;
	}

	if (ob->query("riyue_drug") == 0)
	{
	   command("say " + RANK_D->query_respect(ob) + "吃了我教的圣药了吗？\n");
	   return;
	}
	
	if (ob->query("riyue_drug") == 999)
	{
	   command("say " + RANK_D->query_respect(ob) + "还没吃今年的圣药，我不能收你。\n");
	}

	if ((int)ob->query("score") < 1500)
	{
	   command("say " + RANK_D->query_respect(ob) + "对本教的贡献还不够，我不能收你。\n");
	   return;
	}

	if ((int)ob->query_skill("flatter",1) < 100)
	{
	   command("say " + RANK_D->query_respect(ob) + "还没学会应该怎么跟我说话，还是先回去好好学习一下吧！\n");
	   return;
	}

	if ((int)ob->query("shen") > -10000)
	{
	   command("say 我最痛恨那些所谓正教中的伪君子，" + RANK_D->query_respect(ob) + "若是能杀他几个，我一定收你。\n");
	   return;
	}

	if (!ob->query_temp("riyue/flatter"))
	{
	   command("say 你说我怎么样啊？\n");
	   return;
	}

        command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！");
        command("recruit "+ob->query("id"));
	command("chat 哼哼！我也收了徒弟了，你们正教大侠们给我小心一点！");
	ob->delete("save_ren");
	return;
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
		{ ob->set("title",MAG "日月神教" NOR + HIR "副教主" NOR); }

}


void greet(object me)
{
	if (me->query("save_ren"))
	{
		command("haha");
		command("say " + RANK_D->query_respect(me) + "救我脱出地牢，老夫自当重重酬谢！");
		return;
	}
         if (me->query("family/master_id") == "ren woxing")
        {
            command("say 啊哈！我的副教主回来了！");
            return;
        }
	command("say 你怎么进来的？");
	command("heng " + me->query("id"));
	command("say 又让巫师summon了。");
	return;
}
void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
         switch( random(3) )
        {
            case 0:
            command("wield jian");
            command("perform sword.xuanmu " + target->query("id"));
            command("unwield jian");
             break;
            case 1:
            command("exert maxsuck " +target->query("id"));
             break;
             case 2:
            command("wield blade");
            command("perform blade.lianhuan " + target->query("id"));
            command("unwield blade");
             }
}



