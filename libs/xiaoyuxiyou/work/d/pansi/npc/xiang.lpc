//niang.c/2001 by lestat
inherit SUPER_NPC;
inherit F_MASTER;
#include <ansi.h>


void create()
{
       set_name("香香", ({"xiang xiang", "xiang","master"}));
       set("long",
"牛魔王的妹妹,五岳山一战之后与其兄大力牛魔王决裂,跟随桃花娘子春十三娘来到
这花果山,隐居在桃林之后的盘丝洞内,经常在这里采桃。\n");
       set("gender", "女性");
       set("age", 20);
       set("class", "yaomo");
       set_level(69);
       set("attitude", "friendly");
	set("force_factor", 20);
       set("mana_factor", 40);
       set("eff_dx", 800000);
       set("nkgain", 350);
       set_skill("literate",690);
       set_skill("unarmed",690);
       set_skill("dodge",690);
       set_skill("force",690);
       set_skill("parry",690);
       set_skill("sword",690);
       set_skill("spells",690);
       set_skill("whip", 690);
       set_skill("pansi-dafa",690);
       set_skill("lanhua-shou",690);
       set_skill("jiuyin-xinjing",690);
       set_skill("chixin-jian",690);
       set_skill("yueying-wubu",690);
       set_skill("yinsuo-jinling",690);
       map_skill("spells", "pansi-dafa");
       map_skill("unarmed", "lanhua-shou");
       map_skill("force", "jiuyin-xinjing");
       map_skill("sword", "chixin-jian");
       map_skill("parry", "chixin-jian");
       map_skill("dodge", "yueying-wubu");
       map_skill("whip", "yinsuo-jinling");
       
	create_family("盘丝洞", 3, "弟子");
	setup();
        carry_object("/d/moon/obj/luoyi")->wear();
    	carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{
	if( ob->query("class") && ob->query("class")!="yaomo" )
        {
       		EMOTE_D->do_emote(this_object(), "?",geteuid(ob),CYN,0,0,0);
		return ;
        }
        if( ob->query_level()<40 )
        {
        	tell_object(ob,CYN+name()+CYN"说道：这位" + RANK_D->query_respect(ob) + "还是先去打打基础再来。\n"NOR);
        	return;
        }
	tell_object(ob,CYN+name()+CYN"说道：好！" + RANK_D->query_respect(ob) + "投入我的门下，他日必有所成！\n"NOR);
	command("recruit " + ob->query("id") );
}

int recruit_apprentice(object ob)
{
	 if( ::recruit_apprentice(ob) )
	 	ob->set("class","yaomo");
}
