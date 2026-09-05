// zhangzhaozhong.c 张召重  by hubo

#include <ansi.h>

inherit NPC;
void heal();

void create()
{
	set_name("张召重", ({ "zhang zhaozhong", "zhang","zhaozhong" }));
	set("title", HIY "朝廷六扇门高手" NOR);
	set("nickname", HIR "火手判官" NOR);
	set("long", "武当派高手，但自甘堕落，趋身于朝廷，专与红花会作对。\n");
	set("gender", "男性");
	set("class", "fighter");
	set("age", 49);
	set("attitude", "aggressive");
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
                (: perform_action, "cuff.zhen" :),
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );

	
	set("max_qi", 8000);
	set("max_jing", 8000);
	set("neili", 12000);
	set("max_neili", 12000);
	set("jiali", 500);
	set("combat_exp", 10000000);

	set_skill("literate", 300);
	set_skill("taoism",350);
	set_skill("force", 500);
	set_skill("dodge", 500);
	set_skill("parry", 500);
	set_skill("cuff", 500);
	set_skill("sword", 500);
	set_skill("taiji-shengong", 500);
	set_skill("tiyunzong", 500);
	set_skill("taiji-quan", 500);
	set_skill("taiji-jian", 500);

	map_skill("dodge", "tiyunzong");
	map_skill("force", "taiji-shengong");
	map_skill("cuff", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	
	prepare_skill("cuff","taiji-quan");
	set("env/wimpy", 20);
	create_family("武当派", 10, "弟子");

 	setup();
	carry_object("/d/hangzhou/npc/obj/shiweifu")->wear();
	carry_object("/d/hangzhou/npc/obj/ningbisword")->wield();
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
        if(!wizardp(this_player()))
        {
        write(HIR"张召重冷笑道：文泰来这个鱼饵还真好使，拿命来吧！！\n"NOR);
        this_object()->kill_ob(this_player());
        return;
        }
}

