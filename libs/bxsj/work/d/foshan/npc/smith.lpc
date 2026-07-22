//smith.c  沈铁匠

inherit NPC;

inherit F_VENDOR;

void create()
{
         set_name("沈铁匠", ({ "shen tiejiang", "shen", "smith" }));
         set("long", "沈铁匠正满头大汗地挥舞着铁锤，不时地用铁钳夹住一块红热的铁块
放进炉中。\n");
	set("title", "铁匠铺老板");
        set("gender", "男性" );
        set("age", 43);
	set("shen", 1000);

	set("str", 35);
        set("int", 15);
        set("con", 15);
        set("dex", 20);

	set("max_qi", 400);
        set("max_jing", 400);
        set("neili", 400);
        set("max_neili", 400);

        set("jingli",400);
        set("eff_jingli",400);
        set("jiali", 1);   
	set("combat_exp", 5000);

	set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("strike", 30);
        set_skill("parry", 30);

        set("vendor_goods", ({
            (["name": BINGQI_D("baijielian"),"number" : 10]),
            (["name": BINGQI_D("danrenbi"),"number" : 10]),
            (["name": BINGQI_D("qingshichui"),"number" : 8]),
            (["name": BINGQI_D("siming"),"number" : 4]),
            (["name": BINGQI_D("yinzuifu"),"number" : 9]),
        }));

	setup();
	carry_object("/clone/misc/cloth")->wear();
        add_money("silver",5);

}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

