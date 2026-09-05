// xiaoer.c 酒店小二
//by steel
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
int ask_chuangwang();
void create()
{
        set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long",
                "这位店小二满脸和气,正在高高兴兴的招呼客人。\n");
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/riyuejiao/obj/niurou",
                "/d/city/npc/obj/sdz",
        }));
        set("boot", 1);
        set("chat_chance", 10);
        set("chat_msg",
        ({
        "唉,母亲的心病需要熊心才能治好, 可我上哪里弄呢，那位大侠帮帮我呀？\n",
        (:command("sigh"):),
        (:command("cry1"):),
        (:command("sob"):),
        (:command("shout"):),
        (:command("shout xiao"):),
        }) );
         set("inquiry",([
        "闯王" :(:ask_chuangwang:),
        "宝藏" :(:ask_chuangwang:),
        "闯王宝藏" :(:ask_chuangwang:),
         ]) );
        set("shen_type",1);set("score",200);setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;
        ob=this_player();
        ::init();
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
int ask_chuangwang()
{
    object ob;
    object boots;

    ob=this_player();

   if(!ob->query_temp("given"))
    {
    command("tell "+ob->query("id")+" 嘘...,你问这些干什么,我不知道。");
    say(YEL"店小二颇不信任的看着你\n"NOR);
    return 1;
    }
    else if(query("boot") <= 0 )
    {
       command("tell " + ob->query("id")+" "+"这位"+RANK_D->query_respect(ob)+"\n"+
      "你救了家母的命，在下本应重谢，无奈小人家贫如洗，实在没有东西可以给你啊。\n");
      command("cry " + ob->query("id"));
      return 1;
    }
    else
    {
     command("tell "+ob->query("id")+" "+"这位"+RANK_D->query_respect(ob)+"\n"+
      "你救了家母的命，这双冰山靴你拿去吧，去闯王宝藏用得着。\n");
     boots=new("/d/changbai/obj/snow_boots");
     boots->set_amount(1);
     boots->move(ob);
     write("店小二给你一双冰山靴！\n");
     ob->set_temp("given",0);
     add("boot", -1);
     return 1;
    }
}
/*
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return 0;
        this_player()->set_temp("given",0);
        switch( random(2) ) {
                case 0:
                        say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯烧酒，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "店小二搓了搓手，说道：天冷,这位" + RANK_D->query_respect(ob)
                                + "，快请进。\n");
                        break;
        }
}

*/
int accept_object(object ob, object obj)
{
       if(!ob||environment(ob)!=environment() ) return 0;

       if(!objectp(ob) ) return 0;

       if( !present(obj,ob) )
        {
         say("你有吗？？\n");
         return 1;
        }
        if(obj->query("id")== "bear heart")
        ob->set_temp("given",1);
         call_out("destroy",1,obj);
        say( "店小二感激涕零，声泪俱下说道：多谢这位" + RANK_D->query_respect(ob)
                                + "，小人愿意告知闯王宝藏的秘密来作为答谢。\n");
        return 1;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}
