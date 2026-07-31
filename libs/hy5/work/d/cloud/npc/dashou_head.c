
//dashou_head.c
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("铁豹", ({ "head" }) );
        set("title", "管家");
        set("gender", "男性" );
        set("age", 35);
        set("long", "你看到一个剽悍的大块头。\n");
        set("str", 29);
        set("int", 14);
        set("combat_exp", 2500);
        set("attitude", "heroism");
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);

        set("inquiry", ([
                "碧玉刀" : "这刀可是个宝物, 
据说是当年张家老祖宗退隐时皇上赐的。",
                "香茗坊" : "您也知道'碧海银针'？茶楼就在街对面，我常去的。", 
        ]) );


        setup();
        add_money("silver", 12);
        add_money("coin", 500);
        carry_object("/clone/misc/cloth")->wear();
}

