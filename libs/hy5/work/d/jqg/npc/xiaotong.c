// /NPC shinu.c

#include <ansi.h>
string ask_tea(object ob);
inherit NPC;
void create()
{
       set_name("绿衣小僮", ({ "luyi xiaotong", "xiaotong", "luyi"}));
       set("long","他长得眉清目秀，是个专门侍茶的小僮。\n");
       set("title","绝情谷侍童");
       set("gender", "男性");
       set("age", 15);
       set("shen_type",1);
       set("attitude", "peaceful");
  
       set("str", 14);
       set("int", 20);
       set("con", 25);
       set("dex", 20);
       set("per", 20);

       set("qi", 300);
       set("max_qi", 300);
       set("jing", 200);
       set("max_jing", 200);
       set("eff_jingli",200);

       set("combat_exp",10000);
       set("inquiry", ([
		   "茶" : (: ask_tea :),
       ]));

       setup();
       carry_object("/clone/misc/cloth")->wear();
}
void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say("绿衣小僮笑吟吟地说道：这位" + RANK_D->query_respect(ob)
             + "请了，" + "我这就给您泡茶。\n");
}

string ask_tea(object ob)
{ 
       object obj;
       if ((this_player()->query("water")*10/this_player()->max_water_capacity())>8)
            return "你怎么喝饱了还想要？";
       if ( present("longjin cha", this_player()))
            return "你先喝完了我给你的再说吧。";
       if ( present("longjin cha",  environment(ob)) )
            return "那不是有吗？先喝完了再说。";
       obj=new("/d/jqg/obj/longjin");
       obj->move(this_player());
            return "这杯龙井茶给您，请慢点喝哟。";
}
