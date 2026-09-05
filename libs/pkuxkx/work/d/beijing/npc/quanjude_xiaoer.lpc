//Cracked by Roath
// quanjude_xiaoer.c

inherit NPC;
inherit F_VENDOR;
#include "/d/beijing/killme.h"
#include <ansi.h>

int ask_kaoya();
void create()
{
        set_name("店小二", ({ "xiao er","waiter", "seller" }) );
        set("gender", "男性" );
        set("age", 32);
        set("long",
                "这是全聚德的店小二，想吃烤鸭赶紧向他买吧。\n");

	set_vendor_status(20);

        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/city/obj/jiudai",
        }) );
        set("inquiry", ([
                "烤鸭" : (: ask_kaoya :),
        ]));

        set("shen_type",1);set("score",200);setup();
        carry_object("/d/city/obj/cloth")->wear();
        add_money("silver", 10);
}

void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
int ask_kaoya()
{
        object me = this_player();
        object ob;
        if(!me->query_temp("kaoya_qjd"))
        {
                message_vision(CYN"店小二说道：「客官请先付"HIW"十四两银子"NOR+CYN"。」\n"NOR, me);
                return 1;
        }
        if(me->query("mud_age") - me->query_temp("kaoya_qjd") < 8+random(4))
        {
                message_vision(CYN"店小二说道：「客官稍安毋躁，烤鸭马上出炉。」\n"NOR, me);
                return 1;
        }
        ob = new(__DIR__"obj/kaoya");
        ob->move(me);
        me->delete_temp("kaoya_qjd");
        message_vision(CYN"店小二转身进入厨房，一会便将一只肥的流油的烤鸭交给了$N。\n"NOR, me);
        return 1;
}
int accept_object(object who, object ob)
{       
        if (ob->query("money_id") && ob->value() >= 1400) 
        {
                message_vision(CYN"店小二收下银两，对$N说道：「客官稍候，烤鸭马上出炉！」\n"NOR, this_player());
                this_player()->set_temp("kaoya_qjd",this_player()->query("mud_age"));
                return 1;
        }
        return notify_fail("店小二对你摆手道：小的可不敢收客官的东西。\n");
}


