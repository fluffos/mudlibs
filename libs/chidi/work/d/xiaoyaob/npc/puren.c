//puren.c
//keinxin 2003.2
inherit BHNPC;
#include <ansi.h>
string ask_food();
string ask_water();

void create()
{
       set_name("仆人", ({ "pu ren", "pu", "ren" }) );
       set("gender", "男性" );
       set("age", 50);
       set("long", "他是逍遥派的唯一的仆人，敦厚老实，跟了苏星河三十多年。\n");
       set("combat_exp", 2500);
       set("attitude", "friendly");

       set("inquiry", ([
             "食物" : (: ask_food :),
             "水" : (: ask_water :), 
       ]) );

       setup();
       carry_object("/d/city/obj/cloth")->wear();
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

string ask_food()
{                    
        object ob;
        object me;
        object room;
		object food;
        ob=this_object();
        me=this_player();
        say("仆人说道：谁知盘中餐，粒粒皆辛苦！别浪费了。”\n");
        if ((me->query("food")*10/me->max_water_capacity())>8)
                return "你怎么吃饱了还想要？";
        if ( present("rice", this_player()))
                return "先吃完了我给你的再说吧。";
        if ( present("rice",  environment(me)) )
                return "那不是有吗？先吃完了再说。";              
       food = new ("d/xiaoyao/obj/rice");
       food->move(me);
       return "这碗大米饭就给你了，慢点吃哟。";
}
 
string ask_water()
{
        object ob;
        object me;
        object room;
		object water;
	    ob=this_object();
        me=this_player();
        if ((me->query("water")*10/me->max_water_capacity())>8)
                return "你怎么喝饱了还想要？";
        if ( present("wan", this_player()))
                return "先喝完了我给你的再说吧。";
        if ( present("wan",  environment(me)) )
                return "那不是有吗？先喝完了再说。";
        water = new ("d/xiaoyao/obj/bowl");
        water->move(me);
        return "这杯大碗水就给你吧，请慢点喝哟。";
        
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
         
        if ( ob->query("combat_exp") < 100000000 )
       {
       command(":) "+ob->query("id"));
       command("say 这里是厨房，你可以先看看有什么吃的和喝的，如果没了你就向我
要食物 "HIY"ask pu ren about 食物"CYN" 和喝的 "HIY"ask pu ren about 水"CYN" 吧。"NOR);
          }
}
