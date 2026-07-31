// gammer.c
inherit NPC;
#include <ansi.h>
string *make_msg = ({
    HIB "瞎眼老太婆微笑的说道：嘿嘿，是不是喜欢我孙女啊!\n\n" NOR,
    HIB "瞎眼老太婆想了想，说道：谢谢您帮我找到阿宝.......\n\n" NOR,
    HIB "瞎眼老太婆点了点头道： 就把这个给您，作为谢礼吧! \n\n" NOR,
});
void create()
{
        set_name("瞎眼老太婆", ({ "blind gammer", "gammer" }) );
        set("con", 21);
        set("cor", 22);
        set("rank", "盗贼");
        set("gender", "女性" );
        set("combat_exp", 8000);
        set_skill("staff", 50);
        set_skill("stealing", 70);
        set_skill("dodge", 90);
        set_skill("blade", 30);
        set_skill("sword", 30);
        set_skill("unarmed", 50);
        set_skill("dagger", 70);
        set("age", 66);
        set("long",
                "一个瞎了眼睛的老太婆，满脸皱纹，但是却给人一种亲切的感觉。\n");
        set("inquiry", ([
              "here" : "嘿嘿，明眼人你不问，偏偏问我是不是有什么企图啊？\n",
              "阿宝" : "那是我的宝贝孙女。\n", 
               ]) );
        set("chat_chance", 8);
        set("chat_msg", ({
                "瞎眼老太婆喃喃地说道：阿宝？是你吗？\n",
                "瞎眼老太婆侧著耳朵似乎在倾听什麽。\n",
              //  (: random_move :)
        }) );
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                "瞎眼老太婆叫道：阿宝！有恶人在欺负婆婆哪！快出来啊！\n",
                (: random_move :),
        }) );
        setup();
       
        carry_object(__DIR__"obj/cane")->wield();
        carry_object("/clone/misc/cloth")->wear();
}
void relay_say(object ob, string arg)
{
        if( arg == "阿宝" ) 
        command("say 阿宝？你说阿宝在哪里，你是不是骗我呢？" );
}
int accept_fight(object me)
{
        if( (string)me->query("rank")=="盗贼" ) {
                command("nod");
                command("say 进招吧。");
                return 1;
        }
        command("say 我对你视若无睹，还想和我比试，哼 ...。");
        return 0;
}
int accept_object(object who, object ob)
{
     string objname;
     objname = (string)ob->name();
        if ( objname != "红木梳子")  {
           command("heng");
            say ( HIY "这个能证明什么？证明你见到了阿宝？\n" NOR);
           command("shake");
             return 1;
            }
        if( !who->query_temp("gammer/阿宝") )  {
          call_out( "make_stage", 2, who, 0 );
            who->set_temp("gammer/阿宝", 1);
         } else {
             say (HIB "怎么，难道你还想要谢礼，贪心啊! \n" NOR);
             return 1;
          }
          return 1;
}
void make_stage(object who, int stage)
{
     object obj;
     tell_object(who, make_msg[stage]);
     if( ++stage < sizeof(make_msg) ) {
         call_out( "make_stage", 2, who, stage );
         return;
     } else
       obj = new(__DIR__"obj/syndicator");
       obj->move(who);
    return;
}
