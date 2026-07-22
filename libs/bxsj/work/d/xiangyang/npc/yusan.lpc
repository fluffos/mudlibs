// yusan.c 于三娘
// Lklv 2001.9.24

inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("于三娘", ({"yu sanniang", "yu", "sanniang" }) );
        set("gender", "女性" );
        set("age", 34+random(10));
        set("long", "她徐娘半老，风韵犹存。\n");
        set("attitude","heroism");
        set("combat_exp", 100000 + random(50000) );
        set("shen_type", 0);
        set("per", 21 + random(5));
        set("str", 19);
        set("dex", 24);
        set("con", 25);
        set("int", 12);
        set("env/wimpy", 30);

	set_skill("unarmed", 60);
        set_skill("dodge", 65);
        set_skill("parry", 60);

        set("vendor_goods", ({
                (["name":ARMOR_D("baihu-qiu"),"number": 2]),
                (["name":ARMOR_D("pifeng"),"number": 2]),
                (["name":ARMOR_D("green_silk"),"number": 2]),
                (["name":ARMOR_D("liyududou"),"number": 2]),
                (["name":ARMOR_D("changshan"),"number": 2]),
                (["name":ARMOR_D("changshan2"),"number": 2]),
                (["name":ARMOR_D("changshan3"),"number": 2]),
                (["name":ARMOR_D("changshan4"),"number": 2]),
                (["name":ARMOR_D("changshan5"),"number": 2]),
                (["name":ARMOR_D("qipao"),"number": 2]),
                (["name":ARMOR_D("xiupao"),"number": 2]),
                (["name":ARMOR_D("xiupao2"),"number": 2]),
                (["name":ARMOR_D("changqun"),"number": 2]),
                (["name":ARMOR_D("changqun2"),"number": 2]),
        }));

        set("chat_chance", 2);
        set("chat_msg", ({
                "于三娘看了你一眼，对你微微笑了笑。\n",
        }) );
        setup();
        carry_object(ARMOR_D("changqun2"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        add_money("silver", 20+random(10));
}
void init()
{
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
