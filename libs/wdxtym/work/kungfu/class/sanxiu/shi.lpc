// shi.c 镇抚使
// By Lgg,1998.10

#include <ansi.h>;
#include "sanxiu.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name(HIC"逸仙风"NOR, ({"zhenfu shi", "shi"}));
	set("gender", "男性");
	set("class", "taoist");
	set("nickname", HIM"三阶散修"NOR);
	set("age", 30);
	set("long",
		HIW"此乃炸天帮名下记名弟子，由于修为被废，特隐居山林转修侠客。\n"NOR);
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 500);
	set("int", 500);
	set("con", 500);
	set("dex", 500);

	set("chat_chance_combat", 60);

	set("qi", 200000000);
	set("max_qi", 200000000);
	set("jing", 200000000);
	set("max_jing", 200000000);
	set("neili", 30000);
	set("max_neili", 30000);
	set("jiali", 600);

	set("combat_exp", 220000);

	set_skill("force", 90);
	//set_skill("aoqi-xiushenjue", 90);
	//set_skill("qiang", 90);
	//set_skill("bawang-qiang", 90);
	//set_skill("cunxin-quan", 120);
	set_skill("dodge", 90);
	//set_skill("bawang-qiang", 90);
	set_skill("parry", 90);
	//set_skill("bawang-qiang", 90);
	set_skill("literate",90);

	//map_skill("force", "aoqi-xiushenjue");
	//map_skill("qiang", "bawang-qiang");
	//map_skill("dodge", "bawang-qiang");
	//map_skill("parry", "bawang-qiang");

	create_family("散修", 4, "人仙");

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{

   ob=this_player();
       
      
   if ((int)ob->query("zhuanshi") < 3) 
        {
                command("say 我不收二阶弱者！");
                return;
        }
		
	 if ((int)ob->query_skill("aoqi-xiushenjue",1) < 60) 
        {
                command("say 多练练心法吧！");
                return;
        }
		
		if ((int)ob->query_skill("bawang-qiang",1) < 60) 
        {
                command("say 多练练武功吧！");
                return;
        }

	command("say 好吧，我就收下你这个徒弟了。");
	command("recruit " + ob->query("id"));
	command("say 很好！很好！我散修又多了一大助力。！");
	ob->set("title", HIY "散修至圣" NOR);
}
