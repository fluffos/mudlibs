 // XXDER@FY
inherit NPC;
void create()
{
        set_name("燕儿" , ({ "yaner", "yan er", "girl" }) );
        set("long", "一位十一二岁的小丫头，正在玩弄手上的一个草编蚂蚱。\n");
        set("attitude", "friendly");
/*      set("max_gin", 500);
        set("max_kee", 500);
        set("max_sen", 500); */
        set("age", 11);
        set("gender", "女性" );
        set("chat_chance", 20);
/*      set("str", 35);
        set("cor", 30);
        set("cps", 25); */
        set("combat_exp", 5000);
        set_skill("dodge", 50+random(50));
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/mazha");
}      
