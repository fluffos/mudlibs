// liumang.c 流氓

inherit BHNPC;

void create()
{
        set_name("清洁工", ({ "qingjie gong", "qingjiegong" }));
        set("gender", "男性");
        set("age", 19);
        set("long", "他是一个清洁工，负责打扫卫生的。\n");
        
        set("combat_exp", 1000);
        set("shen_type", -1);

        set("attitude", "peaceful");
        
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :)
        }) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver",2);
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
                call_out("des", 100, ob);}
}

void greeting(object ob)
{
    command("get all");
    command("get corpse");
}
void des(object ob)
{
  message_vision("$N一阵风似的跑不见了.\n",this_object());
  destruct(this_object());
}


