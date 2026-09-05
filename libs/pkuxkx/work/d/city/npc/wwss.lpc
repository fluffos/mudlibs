#include <ansi.h>
inherit F_MASTER;
inherit F_UNIQUE;
inherit NPC;
void create()
{
        set_name(HIY"金身卫士"NOR, ({ "wei shi", "wei" }));
        set("nickname", HIC"忠心耿耿"NOR);
        set("long",
                "他就是这间房间的卫士。\n");
        set("gender", "男性");
        set("age", 25);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 15);
        set("con", 28);
        set("dex", 28);
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 15);
        set("combat_exp", 100000);
        set("score", 20000);
        set("immortal",1);
        setup();
        carry_object("/clone/weapon/xiangmochu")->wield();
}
init()
{
        object me;
       me=this_player();
        ::init();
        if ( me->query("id") != "chui" && me->query("id") !="caifei" && me->query("id") !="testbin"
&& me->query("id") != "kkttzz") {
                        remove_call_out("do_killing");
       call_out("do_killing",1,me);
           }
}
void do_killing(object me)
{
 command("kick "+me->query("id"));
 command("say 大胆狂徒，竟敢在此乱闯，快滚");
me->unconcious();
 me->move("/d/city/guangchang");
 message_vision(HIC"\n金身卫士举起降魔杵向$N当头砸下，只听「砰」的一声，$N已被砸出去\n"NOR);
}
   void unconcious()
{
object ob;
}
void die()

{
        object ob;
       
}
