#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIY "皇太后" NOR, ({ "huang taihou", "taihou", "queen"}));
        set("title", "『母仪天下』");
        set("shen_type", -1);
        set("age",43);
        set("gender", "女性");
        set("per",24);
        set("long",
                "她生得矮矮胖胖，也许是终年不见阳光，所以她的脸色显得很苍白。\n");
        set("fake",1);
        set("max_qi", 4000);
        set("qi", 4000);
        set("max_jing", 3000);
        set("jing", 3000);
				set("neili", 4000);
				set("max_neili", 4000);
				set("jiali", 50);
        
				set("shenlong/meiren", 1);
        set("shenlong/yingxiong", 1);

        set_skill("force", 150 + random(100));
        set_skill("strike", 150 + random(100));
        set_skill("whip", 150 + random(100));
        set_skill("parry", 150 + random(100));
        set_skill("dodge", 150 + random(100));
        set_skill("dagger",150 + random(100));
        set_skill("dulong-bi",150 + random(100));
        set_skill("yixingbu", 150 + random(100));
        set_skill("shenlong-bian", 150 + random(100));
        set_skill("huagu-mianzhang", 150 + random(100));
        set_skill("shenlong-xinfa", 150 + random(100));
        set_skill("literate", 150 + random(100));
        map_skill("dodge", "yixingbu");
        map_skill("force", "shenlong-xinfa");
        map_skill("strike", "huagu-mianzhang");
        map_skill("parry", "shenlong-bian");
        map_skill("dodge", "yixingbu");
        map_skill("whip", "shenlong-bian");
        map_skill("dagger", "dulong-bi");
        
        prepare_skill("strike", "huagu-mianzhang");
				create_family("神龙教",3,"弟子");

        set("combat_exp", 800000);
        set("attitude", "friendly");
        set("inquiry", ([
                "陷害" : "你什么意思......。\n",
        ]));
				set("chat_chance_combat", 100);  
				set("chat_msg_combat", ({
                (: perform_action, "dagger.meiren" :),
                (: perform_action, "dagger.yingxiong" :),
                (: perform_action, "strike.hua" :),
                (: perform_action, "whip.chan" :),
        }) );
  			setup();
        carry_object("/clone/cloth/female4-cloth")->wear();
        carry_object(random(2)?"/clone/weapon/bishou":"/clone/weapon/changbian")->wield();
}


