 inherit NPC;
int tell_him();
void create()
{
        set_name("王镖师", ({ "wang", "biaoshi wang"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "老王的个子不高但一副大胡子，相当地精明能干。\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set_skill("hammer", 90);
        set_skill("dodge", 100);
        set("iron-cloth", 200);
        set("chat_chance", 1);
        set("chat_msg", ({
                "王镖师道：什么？你肯出十倍的价钱？\n",
                "王镖师气得直跺脚：我被骗了！\n",
        }) );
    set("inquiry", ([
        "sword" : (: tell_him :),
        "宝剑" : (: tell_him:),
        "尚方宝剑" : (: tell_him:),
        ]));
        
        setup();
        add_money("coin", 50);
        carry_object(__DIR__"obj/jinzhuang")->wear();
        carry_object(__DIR__"obj/stonehammer")->wield();
} 
int tell_him()
{
    object me;
    me =this_player();
        if(me->query_temp("marks/sword_laowang")) {
                tell_object(me,"老王道：这事你都知道了？我已经把它卖了！卖给那个该死的矮胖子了！\n");
                me->set_temp("marks/sword_asked",1);
        }else{
                message_vision("$N道：你别瞎猜，没有的事！\n",this_object());           
        }
    return 1;
}     
