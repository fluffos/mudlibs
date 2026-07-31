// Npc: /d/tianshan/npc/chenzhende.c
// By Linux

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("陈正德", ({ "chen zhengde", "chen", "zhengde"}));
		set("long",
                "他就是回疆一带武林前辈秃鹫陈正德。\n"
                "和妻子雪雕关明梅和称天山双鹰。\n"
                "长得身材高大，秃头，满脸红光，须眉皆白。\n");
        set("title",HIY"天山双鹰"NOR);
        set("nickname", WHT"秃鹫"NOR);
        set("gender", "男性");

        set("age", 66);
        set("attitude", "peaceful");
        set("shen_type", -1);
	set("per", 10);
        set("str", 27);
        set("int", 27);
        set("con", 27);
        set("dex", 30);

        set("max_qi", 3000);
        set("max_jing", 2200);
        set("eff_jingli", 2200);
        set("max_neili", 4000);
        set("jiali", 50);
        set("combat_exp", 1700000);

        set_skill("force", 250);
        set_skill("unarmed", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("hand",250);
        set_skill("strike", 250);
        set_skill("sword",250);

        set_skill("zhemei-shou",250);          //逍遥折梅手(hand)
        set_skill("liuyang-zhang",250);        //天山六阳掌(strike)(unarmed)
        set_skill("pinxu-lingfeng",250);       //凭虚临风(dodge)
        set_skill("bahuang-gong", 250);        //八荒六合唯我独尊功(force)
	set_skill("tianshan-jianfa", 260);     //天山剑法(sword)


        map_skill("force", "bahuang-gong");
        map_skill("strike","liuyang-zhang");
        map_skill("dodge", "pinxu-lingfeng");
        map_skill("unarmed", "liuyang-zhang");
        map_skill("hand", "zhemei-shou");
        map_skill("parry", "tianshan-jianfa");
	map_skill("sword", "tianshan-jianfa");
        prepare_skill("hand","zhemei-shou");
        prepare_skill("strike","liuyang-zhang");

        setup();
        carry_object(BINGQI_D("changjian"))->wield();
        carry_object(MISC_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
