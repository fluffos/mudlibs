 // fat_bandit.c
inherit NPC;
void call_for_help();
void create()
{
        set_name("矮胖子土匪", ({ "bandit" }) );
        set("gender", "男性");
        set("age", 36);
        set("long",
                "这家伙又矮又胖，圆滚滚的眼珠子在满脸肥肉中骨碌碌地转来转去。\n");
        set("combat_exp", 500);
        set("score", 80);
        set("attitude", "friendly");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                "\n矮胖子土匪大叫：把你身上的钱通通留下来！\n",
                "\n矮胖子土匪嘴里不乾不净地咒骂著。\n",
                (: call_for_help :),
        }) );
 set("combat_exp", 400000+random(900000));
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );

	set("max_qi", 3000);
	set("max_jing", 3000);
	set("neili", 3000);
	set("max_neili", 3000);

        set_skill("unarmed", 80+random(180));
        set_skill("sword", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-jian", 80+random(380));
        
        map_skill("sword", "kuang-jian");
        map_skill("parry", "kuang-jian");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);
        setup();
        carry_object(__DIR__"obj/short_sword")->wield();
        carry_object(__DIR__"obj/leather")->wear();
        add_money("coin", 50);
} 
void call_for_help()
{
        object ob; 
        if( query("called_help") || present("bandit chief", environment()) ) return;
        set("called_help", 1);
        command("say 他妈的，点子爪子太硬....");
        say("矮胖子土匪大叫：老大！老大！兄弟撑不住啦！\n");
        ob = new(__DIR__"bandit_chief");
        ob->move(environment());
        ob->start_help();
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