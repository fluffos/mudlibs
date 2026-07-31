#include <ansi.h>
inherit NPC;
int doing(object me);
void create()
{
        set_name("翠彤", ({ "girl" }) );
        set("title", HIM "鸣玉之花" NOR);
        set("gender", "女性" );
        set("age", 22);
        set("str", 10);
        set("per", 30);
        set("long", @LONG
翠彤是鸣玉坊的名妓，如果你感兴趣的话，请（ｅｎｊｏｙ）．
LONG
);
        set("combat_exp", 10);
        set("attitude", "friendly");

        setup();
        carry_object(__DIR__"obj/pink_cloth")->wear();
}

int accept_fight(object me)
{
        command("say 小女子哪里是您的对手？");
        return 0;
}
int accept_object(object me, object ob)
{
        if ((string)me->query("gender")=="男性"){
          if ( ob->query("money_id") && ob->value() >= 10000000 ) {
             command("blush");
             message_vision( HIM "$N缓缓地低下头，瞟了$n几眼，这位" + RANK_D->query_respect(me) +"，想在此渡夜吗？\n" NOR, this_object(), me);
             me->set_temp("tmark/love1",1);
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
        if ( ob->query_temp("tmark/love1") ) {
           if( !ob || environment(ob) != environment() ) return 0;
           if ((string)ob->query("gender")=="男性")
              command("makelove "+(string)ob->query("id"));
        return 1;
        } else return notify_fail( HIW "翠彤轻轻地打了个哈欠。笑道：这位" + RANK_D->query_respect(ob) +"，请你还是早点回家歇息吧！\n" NOR );
}
