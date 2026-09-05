// qinweibang.c	秦伟邦	chatter
//by bing
#include "riyuenpc.h"
#include "riyuenpc2.h"

inherit NPC;
#include <ansi.h>
void suck();
void create()
{
        set_name("秦伟邦", ({ "qin weibang", "qin","weibang" }));
        set("title",GRN "日月神教" NOR + HIY "长老" NOR);
        set("long","他长手长脚，双目精光烂然，甚有威势，他在教中资历也不甚深，
只是近数年教中变迁甚大，他在教中已是极有权势、极有头脸的第一流人物。\n");
        set("gender", "男性");
        set("age", 43);
        set("attitude","heroism");
        set("shen_type", -1);
	set("shen",-30000);
        set("str", 30);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        set("max_qi", 1200);
        set("max_jing", 1000);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 100);
        set("combat_exp", 600000);
	set("score",2000);
        set("chat_chance",10);
        set("chat_msg", ({
                (: heal :),
		"本教相传有三样镇教之宝：日月神刀，日月神剑和葵花宝典。\n",
                "本教教众如果贡献出色，可问贾长老领取神丹解药。\n",
                "本教教众可以问贾长老领取本门神兵，也就是日月神刀和日月神剑。\n",
		"可惜我教日月神刀和日月神剑早已遗失，久已不现江湖。\n",
		"日月神刀和日月神剑据说可以大大提高我教高手的攻击力。\n",
		"前几天听华山村的李铁嘴说他知道了什么四宝的下落，不知道是不是真的，也不知道是哪四宝？\n",
		"承蒙任教主看得起我，传了我吸星大法，这功夫虽然名声不好，可是威力可也不能小瞧了。\n",
		"葵花宝典现在东方教主手中。据说研习葵花宝典非常容易走火入魔，但东方教主已经写了一篇心法，可以防止走火。\n",
		"听说我教曲长老和衡山派刘正风交好，结果被那些所谓的正派侠士追杀，身负重伤，也不知现在在哪里......唉！\n",
		"哼！什么正教白道也不是什么好东西了。黑木崖下经常发现有正教的探子，鬼鬼祟祟，没有一个正经家伙！\n",

	        }));
          set("chat_chance_combat", 0);
        set("chat_msg_combat", ({
                (: perform_action, "blade.lianhuan" :),
		(: perform_action, "sword.xuanmu" :),
		(: suck :),
        }) );
        set("inquiry", ([
            "东方不败" : (: ask_df :),
            "东方教主" : (: ask_df :),
	    "任我行" : (: ask_ren :),
	    "任教主" : (: ask_ren :),
	    "任盈盈" : "她是任教主的女儿，一般不住在黑木崖上，圣教主对她很尊重。",
	    "圣药" : "那是圣教主对有功之人的赏赐，吃了以后对教主更加忠心。在风雷堂童堂主处领取。",
	    "三尸脑神丹" : "那是圣教主对有功之人的赏赐，吃了以后对教主更加忠心。在风雷堂童堂主处领取。",
       ]) );

        set_skill("force", 150);
        set_skill("xixing-dafa", 150);
        set_skill("dodge", 180);
        set_skill("parry", 150);
        set_skill("ryingzhua-gong", 120);
	set_skill("blade",150);
	set_skill("riyue-dao",150);
	set_skill("sword",150);
	set_skill("riyue-jian",150);
        set_skill("feitian-shenfa", 120);
        set_skill("claw", 150);
        set_skill("literate",100);
	set_skill("flatter",120);
        map_skill("force", "xixing-dafa");
        map_skill("parry", "riyue-dao");
        map_skill("dodge", "feitian-shenfa");
	map_skill("sword", "riyue-jian");
        map_skill("claw", "ryingzhua-gong");
        map_skill("blade","riyue-dao");
	prepare_skill("claw", "ryingzhua-gong");
	prepare_wskill("riyue-dao", "riyue-jian");
	create_family("日月神教", 20, "弟子");
        setup();
        carry_object("/d/riyuejiao/obj/heiyi")->wear();
	carry_object("/d/riyuejiao/obj/yaodai")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/weapon/gangdao")->wield();
       }
void init()
{
	object ob;
	mapping fam;
        ::init();
	ob = this_player();
	if (interactive(ob) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

}

void attempt_apprentice(object ob)
{
	command("say 老夫不收徒弟，你要拜师去黑木崖吧！");
}


void suck()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        command("exert neilisuck " + target->query("id"));

}
