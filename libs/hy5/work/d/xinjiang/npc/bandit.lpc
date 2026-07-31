 // bandit.c
inherit NPC; 
void create()
{
        set_name("土匪", ({ "bandit" }) );
        set("gender", "男性");
        set("age", 33);
        set("long",
                "这家伙满脸横肉，一付凶神恶煞的模样，令人望而生畏。\n");
        set("combat_exp", 600);
        set("score", 60);
        set("attitude", "friendly");
        set_skill("sword", 10);
        set_skill("parry", 10);
        set_skill("dodge", 10);
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
        carry_object(__DIR__"obj/short_sword")->wield();
        add_money("coin", 3);
}
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !ob || environment(ob) != environment() )
                return;
        if (ob->query("class") != "bandit")
        {
                message_vision("$N看着你大声呼喊到：“兄弟们，肥羊入口！”\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        else if(ob->query("class")=="bandit")
        {
                message_vision("$N对你阴笑道：兄弟今天又到哪里打家劫舍？\n", this_object() );
        }
        return;
}     