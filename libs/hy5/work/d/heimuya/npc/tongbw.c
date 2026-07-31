//tonbaixiong.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void greeting(object);
void init();
void create()
{
	set_name("童百熊", ({ "tongbai xiong","xiong"}) );
	set("gender", "男性" );
	set("age", 75);
	set("title", HIC"日月神教风雷堂长老"NOR);
	set("long", "他白发披散, 银髯戟张, 脸上的肌肉牵动, \n"
                    "圆睁双眼, 身上的鲜血已然凝结, 神情甚是可怖。\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 11000);
	set("max_jing",11000);
	set("neili", 12000);
	set("max_neili", 12000);
	set("jiali", 200);
	set("combat_exp", 950000);
	set("score", 30000);

          set_skill("sword", 100);
          set_skill("parry", 100);
        set_skill("literate",100);
          set_skill("dodge", 100);
          set_skill("unarmed", 100);
          set_skill("whip", 100);
          set_skill("force", 100);
        set_skill("staff", 100);
          set_skill("strike",100);
         set_skill("blade", 100);

         set_skill("tmjian", 150);
         set_skill("tmzhang", 250);
         set_skill("tmdao", 150);
         set_skill("pmshenfa", 150);
         set_skill("tmdafa", 350);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
set_skill("tmquan", 280);
        map_skill("strike", "tmzhang");
        map_skill("cuff", "tmquan");
  prepare_skill("cuff","tmquan");

prepare_skill("strike","tmzhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.diansha" :),
                (: perform_action, "sword.xuan" :),
                (: perform_action, "sword.tmbiao" :),
                	(: perform_action, "sword.jianshen" :),
                		(: perform_action, "sword.moshen" :),
                (: perform_action, "blade.moxiao" :),
                (: perform_action, "blade.tiandirenmo" :),
                (: perform_action, "blade.xuan" :),                	
                (: perform_action, "blade.yueshen" :),                	
                (: perform_action, "strike.huashen" :),                
                (: perform_action, "strike.zhen" :),                
                (: perform_action, "strike.tmduan" :),                
                (: perform_action, "cuff.tianmo" :),                
                (: perform_action, "cuff.dimo" :),                
                (: perform_action, "cuff.renmo" :),

        }) );

	create_family("日月神教",2,"弟子 风雷堂长老");

	set("chat_chance", 3);
	set("chat_msg", ({
		 "童百熊怒瞪双眼道: “我没错, 我没有叛教! 东方兄弟你不能冤枉我呀! ”\n",
	         "童百熊叹了一口气说：“我和东方兄弟出生入死, 共历患难的时候, 你们还没生下来哪!”\n"
        }) );
	setup();
        carry_object(__DIR__"obj/zijinchui");
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/card1")->wear();

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
