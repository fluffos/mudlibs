// daneibaobiao2.c 大内保镖  by hubo

#include <ansi.h>

inherit NPC;
void heal();

void create()
{
	set_name("大内保镖", ({ "danei baobiao", "baobiao" }));
	set("title", HIY "朝廷六扇门高手" NOR);
	set("long", "武功深不可测的大内高手，专门保护皇上的保镖，这次派到临安府看管犯人。\n");
	set("gender", "无性");
	set("class", "fighter");
	set("age", 50);
        set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 24);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("chat_chance", 100);
  set("chat_msg", ({
                (: heal :),
        }));
  set("chat_chance_combat", 100);
  set("chat_msg_combat", ({
                (: perform_action, "dodge.cixue" :),
                (: perform_action, "dodge.cimu" :),
                (: exert_function , "powerup" :)
        }) );

	
	set("max_qi", 80000);
	set("max_jing", 8000);
	set("neili", 52000);
	set("max_neili", 52000);
	set("jiali", 1000);
	set("combat_exp", 80000000);

	set_skill("literate", 800);
	set_skill("force", 800);
	set_skill("dodge", 800);
	set_skill("parry", 800);
	set_skill("cuff", 800);
	set_skill("sword", 800);
	set_skill("kuihua-shengong", 800);
	set_skill("pixie-jian", 800);
	set_skill("taiji-quan", 800);
	set_skill("taiji-jian", 800);

	map_skill("dodge", "pixie-jian");
	map_skill("force", "kuihua-shengong");
	map_skill("cuff", "taiji-quan");
	map_skill("parry", "pixie-jian");
	map_skill("sword", "pixie-jian");
	
	prepare_skill("cuff","taiji-quan");
	set("env/wimpy", 20);
	create_family("日月神教", 20, "弟子");

 	setup();
	carry_object("/d/city/obj/flower_shoe")->wear();
  carry_object("/d/city/obj/pink_cloth")->wear();
  carry_object("/d/city/obj/goldring")->wear();
  carry_object("/d/city/obj/necklace")->wear();
  carry_object("/d/quanzhou/obj/xiuhua")->wield();
  carry_object("/d/riyuejiao/obj/xiuhuajia")->carry();

}

void heal()
{
        object ob=this_object();
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("enforce 50");
                return;
        }
        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }
        if (ob->query("jing") < ob->query("eff_jing"))
                command("exert regenerate");
        return;
}

void init()
{
        if(this_player()->query_temp("hhh_wt1") == 7 && !this_player()->is_ghost())
        {
        write(HIR"大内保镖冷笑道：这么简单就想把人救走？我来送你一程吧！！\n"NOR);
        this_object()->kill_ob(this_player());
        return;
        }
}

