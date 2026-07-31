
// seller.c

inherit NPC;

void create()
{
        set_name("李老黑", ({ "seller" }) );
        set("title", "烟贩子");
        set("gender", "男性" );
        set("age", 28);
        set("str", 26);
        set("int", 14);
        set("long",
                
"李老黑是个见钱眼开的大奸商，他正在向别人出售鸦片!\n");
        set("combat_exp", 3000);
        set("attitude", "heroism");

        set("force", 120);
        set("max_force", 120);
        set("force_factor", 1);

        set_skill("unarmed", 30);
        set_skill("dodge", 30);

        setup();
}

