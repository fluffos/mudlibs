// huangboliu.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
#include <ansi.h>;
void create()
{
	set_name("黄伯流", ({ "huang boliu","huang","boliu"}) );
	set("gender", "男性" );
	set("title", HIB"日月神教风雷堂香主"NOR);
	set("nickname", HIW"银髯蛟"NOR);
	set("age", 85);
	set("long", "一部白须，直垂至胸，身材魁梧之极。\n");
	set("attitude", "friendly");
	set("shen_type", 1);

	set("per", 21);
	set("str", 53);
	set("int", 53);
	set("con", 52);
	set("dex", 50);

	set("max_qi", 11000);
	set("max_jing",11000);
	set("neili", 21000);
	set("max_neili", 21000);
	set("combat_exp", 1950000);
	set("jiali", 100);
	set("score", 30000);

          set_skill("sword", 150);
          set_skill("parry", 150);
        set_skill("literate",150);
          set_skill("dodge", 150);
          set_skill("unarmed", 150);
          set_skill("whip", 150);
          set_skill("force", 150);
        set_skill("staff", 150);
          set_skill("strike",150);
         set_skill("blade", 150);
set_skill("changquan", 150);
         set_skill("tmjian", 150);
         set_skill("tmzhang", 150);
         set_skill("tmdao", 250);
         set_skill("pmshenfa", 150);
         set_skill("tmdafa", 150);
set_skill("changquan", 150);
        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");

	create_family("日月神教",2,"弟子 风雷堂香主");

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object ob)
{
         if (ob->query_int() < 20) {
              command("say " + RANK_D->query_respect(ob) +
                        "走开走开，我不想和傻瓜说话。");
                return;
        }
         if (ob->query_dex() < 20) {
                command("say " + RANK_D->query_respect(ob) +
                        "身手不捷，还是另求高师吧。");
                return;
        }
        if ((int)ob->query("shen") > -10000) {
                command("say " + RANK_D->query_respect(ob) +
                        "你还不够心狠手辣，我还不能收你。");
                return;
        }
        command("say 哈哈！ 那我就收下你吧。");
        command("recruit " + ob->query("id"));
}
