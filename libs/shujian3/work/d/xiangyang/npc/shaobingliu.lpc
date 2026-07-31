// shaobingliu.c 烧饼刘
// Lklv 2001.9.26

inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("烧饼刘", ({"shaobing liu", "liu"}) );
        set("gender", "男性" );
        set("age", 44+random(10));
        set("long", "他身上的衣服沾的一块块的油腻。\n");
        set("attitude","heroism");
        set("combat_exp", 120000 + random(50000) );
        set("shen_type", 0);
        set("str", 19);
        set("dex", 24);
        set("con", 25);
        set("int", 12);

	set_skill("unarmed", 60);
        set_skill("dodge", 65);
        set_skill("parry", 60);

        set("vendor_goods", ({
                (["name":FOOD_D("shaobing"),"number": 20]),
        }));

        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
void init()
{
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
