//LUCAS 2000-6-18
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("燕万鹏",({"yan wanpeng","yan"}));
        set("gender", "男性");
        set("age", 20);
        set("long", 
               "他是凌霄城第六代弟子燕万鹏,第六代弟子中,为人数他最\n"
                "为梗直,素有铁面之称,所以在此镇狱。\n");
        set("attitude", "peaceful");

        set("str", 25);
        set("con", 30);
        set("int", 24);
        set("dex", 30);
        set("neili", 20000);
        set("max_neili", 20000);
        set("jing", 15000);
        set("max_jing", 10500);
        set("qi", 25000);
        set("max_qi", 25000);
        set("jiali", 80);

        set("combat_exp", 500000);
        set("shen_type", 1);
        set("score", 50000);

   set_skill("sword", 280);
        set_skill("force", 230);
        set_skill("parry", 230);
        set_skill("dodge", 230);
        set_skill("literate", 180);

        set_skill("xueshan-sword", 320);
        set_skill("bingxue-xinfa", 320);
        set_skill("snow-zhang", 300);
        set_skill("snowstep", 300);
        set_skill("doom-hand", 300);
        set_skill("hanshan-strike", 300);
        set_skill("snowwhip", 300);
        set_skill("hand", 250);
        set_skill("whip", 250);
         set_skill("strike", 280);
        map_skill("sword", "xueshan-sword");
        map_skill("parry", "xueshan-sword");
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");

        map_skill("strike", "hanshan-strike");
        map_skill("hand", "doom-hand");
	prepare_skill("strike", "hanshan-strike");
	prepare_skill("hand", "doom-hand");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fengxue" :),
                (: perform_action, "sword.wanmei" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "dodge.snowfly" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "unarmed.yanxue" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.zhe" :),
                (: perform_action, "unarmed.lang" :),
                (: perform_action, "strike.zhangjian" :),
                (: perform_action, "strike.siji" :),
	               (: perform_action, "hand.hantian" :),                		
                (: exert_function, "powerup" :),
        }) );

        create_family("凌霄城", 6, "弟子");
        setup();

        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int accept_object(object me, object ob)
{
   object nowords;

     if ((string)ob->query("name")!=HIW"寒玉牌"NOR) {
            command("say 你给我这个干什么！你想贿赂我吗？");
            return 1;
        }
        else {
            command("say 师弟请下去吧，老爷子在下面。\n");
                me->move("/d/lingxiao/laolang");
            return 1;
        }
}

