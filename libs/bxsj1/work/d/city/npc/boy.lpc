// kid.c

inherit NPC;

void create()
{
        set_name("学童",({ "xue tong", "boy", "xuetong" }) );
        set("gender", "男性" );
        set("age", 13);
        set("long", "这是个扬州长大的男孩, 被父母逼着来书院读书。\n");

        set("str", 17);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
	set("shen_type", 1);
        set_temp("apply/defense", 10);
        set("combat_exp", 120);
        set("attitude", "peaceful");

        setup();

        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
	add_money("coin",20);
}