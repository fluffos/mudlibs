// xiaofan.c 小贩子
inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("小贩子", ({ "xiao fan", "xiao", "fan" }) );
        set("gender", "男性" );
        set("age", 34);
        set("long", "这位小贩子正笑咪咪地来回忙著，还不时招呼过往的客人进来。\n");
        set("combat_exp", 300);
        set("attitude", "peaceful");
        set("rank_info/respect", "小贩子");
        set("vendor_goods", ({
                "/d/mingjiao/obj/book",
        }));
        setup();
}

void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch(random(2)){
          case 0:
          say(CYN"小贩子笑咪咪地说道：这位"+RANK_D->query_respect(ob)+"，进来歇歇腿吧。\n"NOR);
          break;
          case 1: 
          say(CYN"小贩子用手指着竹壶说：这位"+RANK_D->query_respect(ob)+"快进来吧，喝几口泉水解解渴。\n"NOR);
          break;
        }
}
