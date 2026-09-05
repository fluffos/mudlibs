
#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void create()
{
        set_name("渡昆", ({ "du kun", "kun" }) );
        set("title", HIR "少林" NOR + CYN "长老" NOR);
        set("gender", "男性");
        set("age", 90);
        set("long",
    "这是一个面颊深陷，瘦骨零丁的老僧，他脸色枯黄，但双眼炯炯有神。\n"
);

        set("attitude", "peaceful");
        set("combat_exp", 2000000);
        set("score", 200000);

        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);

        set("qi", 5000);
        set("max_qi", 5000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 90);
        set("max_jing",2500);
        set("jing",2500);

        create_family("少林派", 35, "弟子");
        assign_apprentice("弟子", 0);

        set_skill("force", 200);
        set_skill("claw", 190);
        set_skill("hand", 190);
        set_skill("sword",190);
        set_skill("club", 190);
        set_skill("strike", 190);
        set_skill("parry", 190);
        set_skill("dodge", 190);

        set_skill("hunyuan-yiqi", 200);
        set_skill("buddhism", 200);
        set_skill("longzhua-gong", 190);
        set_skill("shaolin-shenfa", 160);
        set_skill("fumo-jian",170);
        set_skill("qianye-shou",180);
        set_skill("sanhua-zhang",180);


        map_skill("force", "hunyuan-yiqi");
        map_skill("strike",  "sanhua-zhang");
        map_skill("parry", "sanhua-zhang");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("hand", "qianye-shou");
        map_skill("sword" ,"fumo-jian");
      
        prepare_skill("hand","qianye-shou");
        prepare_skill("claw","longzhua-gong");
 
        setup();

        carry_object("/d/shaolin/obj/changjian")->wield();
}


#include "/kungfu/class/shaolin/du2.h"
