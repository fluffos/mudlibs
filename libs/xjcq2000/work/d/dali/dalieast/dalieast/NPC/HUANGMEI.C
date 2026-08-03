// Modify By River 98/12

inherit NPC;

void create()
{
        set_name("黄眉和尚", ({ "huangmei heshang", "heshang", "huangmei" }) );
        set("title", "拈花寺主持");
        set("gender", "男性" );
        set("age", 65);
        set("str", 25);
        set("con", 23);
        set("dex", 23);
        set("int", 20);
        set("unique", 1);

        set("max_qi", 2500);
        set("max_jing", 2000);
        set("eff_jingli", 2000);
        set("max_neili", 2500);
        set("jiali", 100);       

       create_family("福建莆田少林寺", 10, "弟子");
        set("long", 
        "一个满脸皱纹、身形高大的老僧。这老僧两道焦黄长眉，眉尾下垂。\n");

        set("combat_exp", 1000000);
        set("score", 20000);       

        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("force", 120);
        set_skill("finger", 150);
        set_skill("buddhism", 120);
        set_skill("literate", 120);
        set_skill("yijin-jing", 120);
        set_skill("nianhua-zhi", 160);
        set_skill("shaolin-shenfa", 150);
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "nianhua-zhi");
        map_skill("finger", "nianhua-zhi");
        map_skill("force", "yijin-jing");
        prepare_skill("finger","nianhua-zhi");      

        setup();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}
