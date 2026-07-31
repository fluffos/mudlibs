#include <ansi.h>
inherit NPC;

void create()
{
        set_name("李诗诗", ({ "li shishi","li","shishi" }) );
        set("title", HIR "天下第一名妓" NOR);
        set("gender", "女性" );
        set("age", 22);
        set("str", 10);
        set("per", 30);
        set("long", @LONG
两弯似戚非戚笼烟眉，一双似喜非喜含情目．
行动如弱柳扶风，闲静似娇花照水．
LONG
);
        set("combat_exp", 100000);
        set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
"李诗诗又意无意地撩起长裙，向你露出她那双白如羊脂的细足．\n",
"李诗诗似乎怕热，拎起领口扇了扇，半边雪白坚挺的胸膛尽收眼底．\n",
"李诗诗向你笑了笑，又继续看天上满天的星辰．\n",
        }) );

        setup();
        carry_object(__DIR__"obj/sskirt")->wear();
}

int accept_fight(object me)
{
        command("say 小女子哪里是您的对手？");
        return 0;
}

int accept_object(object me, object ob)
{
        if ((string)me->query("gender")=="男性"){
          if ( ob->query("money_id") && ob->value() >= 30000000 ) {
             command("blush");
             message_vision( HIM "$N吃吃地笑着，瞟了$n几眼，这位" + RANK_D->query_respect(me) +"，可是看中了贱妾？\n" NOR, this_object(), me);
             me->set_temp("tmark/love2",1);
             command("follow "+(string)me->query("id"));
             return 1;
             }
        }
        if ( ob->query("money_id") ) {
             command("smile");
             command("say 多谢这位" + RANK_D->query_respect(me) +"，您一定会在这儿玩的开心的！");
        return 1;
        } else { 
             command("say 这位" + RANK_D->query_respect(me) +"，你给些什么东西给我啊！");
        return 0;
        }
}

void init()
{
        ::init();
/*
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
*/
        add_action("do_enjoy","enjoy");
}

/*
int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}

*/
int do_enjoy(object ob)
{
        ob=this_player();
        if ( ob->query_temp("tmark/love2") ) {
           if( !ob || environment(ob) != environment() ) return 0;
           if ((string)ob->query("gender")=="男性")
              command("makelove "+(string)ob->query("id"));
              command("follow none");
        return 1;
        } else return notify_fail( HIW "李诗诗轻轻地打了个哈欠。笑道：这位" + RANK_D->query_respect(ob) +"，请你还是早些回家歇息吧！\n" NOR );
}

