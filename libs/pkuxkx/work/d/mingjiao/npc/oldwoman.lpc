// oldwoman.cage/npc/oldwoman.c
inherit NPC;
void create()
{
        set_name("老婆婆", ({ "old woman", "woman" }) );
        set("gender", "女性" );
        set("age", 63);
        set("long", "一个满脸风霜之色的老婆婆。\n");
//      set("shen", 1000);
        set("shen_type", 1);
        set("combat_exp", 150);
        set("env/wimpy", 60);
        set("chat_chance_combat", 50 );
//        set("chat_msg_combat", ({
//               "E)7r=P5@#:I1HKDD#!I1HKDD#!\n",
//              "E)7r=P5@#:SPMA7KDD#!9bLl;/HUOB4r=YDD#!\n",
//                (: command, "surrender" :),
//        }) );
        set("str", 13);
        set("dex", 12);
        set("con", 14);
        set("int", 13);
        set("attitude", "friendly");
        set("inquiry", ([
                "明教" : "明教就在山上，望北走就是，唉 ~ ~，那帮恶贼可真坏透了。",
             
        ]) );
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
                "老婆婆伤心的说道：也不知孩子他爸什么时候回来？\n",
                "老婆婆骂到：恶贼，不得好死，抢我们粮，还抢了孩子他爸去做苦工。\n",
                "老婆婆呆呆的望着两个孩子，发起愣来了。\n",
        }) );
        carry_object(__DIR__"obj/cloth")->wear();
        add_money("coin", 100);
}
