
//tea_vendor.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("卖茶水的大娘", ({ "tea vendor", "vendor" }) );
        set("gender", "女性" );
        set("age", 47);
        set("per", 18);
//        set("where","south");
        set("long", "这个卖茶的大娘对你微微一笑，说道：自家种的茶，来一壶吧？\n");
        set("combat_exp", 3000);
        set("attitude", "friendly");

//        set("chat_chance", );
        set("chat_msg", ({
                "卖茶水的大娘吆喝道：茶水！来喝碗茶吧！\n",
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();

}



