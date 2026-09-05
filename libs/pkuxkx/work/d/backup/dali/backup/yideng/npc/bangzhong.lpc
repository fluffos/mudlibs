//铁掌帮众
//by icer
#include <ansi.h>


inherit NPC;


void create()
{
        set_name("铁掌帮众", ({ "bang zhong","zhong" }));
        set("long", "只见他一脸横肉，杀气腾腾，好象恨不得立刻把你煮来吃了一样。\n");
        set("gender", "男性");
        set("age", 34);
        set("str", 29);
        set("dex", 20);
        set("con", 14);
        set("int", 18);
        set("shen_type", -1);
	set("shen",5000);
	set("attitude","heroism");

        set_skill("strike", 70);
        set_skill("force", 50);
        set_skill("dodge", 50);

        set("combat_exp", 50000);

        set("max_qi", 150);
        set("max_jing", 80);
        set("neili", 300);
        set("max_neili", 300);

        setup();
        carry_object("/d/dali/yideng/obj/jinzhuang")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

