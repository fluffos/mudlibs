//醉汉
// Rewrote by iszt@pkuxkx, 2007-03-31

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name(HIR"醉汉"NOR, ({ "zui han", "han"}) );
        set("gender", "男性" );
        set("age", 30);
        set("long", "此人嗜酒如命，成天在醉仙楼饮酒度日。不过他对酒却是很有研究。\n");
        set("combat_exp", 50000);
        set("inquiry", ([
                "万年醉" : "好酒，好酒........" ,
        ]) );
        set("attitude", "friendly");
        set("seller",0);
        set("shen_type",1);set("score",200);setup();
}

void init()
{
        object me;

        ::init();
        if( interactive(me = this_player()) && !is_fighting() )
        {
                if(me->is_disable()) return;
                if( !this_object()->visible(me)) return;
                if( !me || environment(me) != environment() ) return;
                remove_call_out("greeting");
                call_out("greeting", 1, me);
                if(me->query_condition("drunk"))
                {
                        remove_call_out("selljiu");
                        call_out("selljiu", 2, me);
                        return ;
                }
                remove_call_out("nosell");
                call_out("nosell", 10, me);
        }
}

int selljiu(object me)
{
        if(query("seller")) return 1;
        if(!me || !present(me, environment())) return 1;
        set("seller",1);
        set("vendor_goods", ({
                "/d/yuewangmu/obj/wannianzui",
        }));
        message_vision(HIW"醉汉见到$N，如故友重逢一般，大笑：「看来你也是爱酒之人！\n"
                "我这里有上好的万年醉，一醉万年！你要不要买(buy)一瓶？」\n"
                "说完，醉汉拿出一瓶万年醉给$N看(list)。\n"NOR,me);

        add_action("do_list","list");
        add_action("do_buy","buy");

        call_out("nosell",10,me);
        return 1;
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if(ob->query("gender")=="女性")
        {
                command("haha "+ ob->query("id"));
                command("admire "+ob->query("id"));
                command("say 这位姑娘，来，陪大爷我喝喝酒！哈哈....");
        }
        else if (ob->query("gender")=="无性")
        {
                command("haha "+ ob->query("id"));
                command("nod");
                command("say 公公也来喝酒？好好，过来喝.......喝！");
        } 
        else
        {
                command("haha");
                command("hi " +ob->query("id"));
                command("say 哥们，来过来喝酒，酒可是好东西！高不高兴，有它就成！");
        }
}

int nosell(object me)
{
        if(me && present(me, environment()))
                message_vision(HIY"醉汉打了个嗝，又醉晕了过去。\n"NOR, me);
        delete ("vendor_goods");
        set("seller",0);
        unconcious();
        call_out("wakeup", 2);
}

int wakeup()
{
        this_object()->revive();
        delete_temp("last_damage_from");
        say(HIB"没过多久，醉汉打了个嗝，又醒过神来。\n"NOR);
        return 1;
}
