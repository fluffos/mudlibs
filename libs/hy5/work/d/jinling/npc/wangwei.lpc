// gao.c

inherit NPC;
void create()
{
       set_name("王维", ({"wang wei", "wan"}));

set("long","王维是金陵著名的诗人，据说是个隐居江湖的高人。\n");
       set("gender", "男性");
       set("age", 52);
       set("title", "诗人");
       set("attitude", "peaceful");
       set("shen_type", 1);
	set("combat_exp", 85000);
        set_skill("unarmed", 25);
	set_skill("dodge", 15);
	set_skill("dagger", 35);
	set_skill("parry", 45);
set("inquiry", ([
"name": "老夫姓王,你有什么事吗？\n",
"here": "这里是燕堂.\n",
]) );

	setup();
       add_money("silver", 5+random(5));
       // carry_object("/u/baiwt/xueshan/npc/obj/yandou")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

