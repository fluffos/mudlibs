//wang1.c
inherit NPC;
#include <ansi.h>
string ask_food();
string ask_water();

void create()
{
       set_name("王厨子", ({ "wang chuzi", "chuzi", "wang" }) );
       set("gender", "男性" );
       set("age", 46);
       set("long", "他是襄阳武馆的厨子，胖胖的，敦厚老实。\n");
       set("combat_exp", 2500);
       set("attitude", "friendly");

       set("inquiry", ([
             "手艺" : "我做饭的手艺可是襄阳一绝，整个襄阳城谁不夸我！嘿嘿！",
             "食物" : (: ask_food :),
             "水" : (: ask_water :), 
       ]) );

       setup();
       carry_object(ARMOR_D("cloth"))->wear();
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
        object ob,me,food;
        ob=this_object();
        me=this_player();
        say("王厨子说道：谁知盘中餐，粒粒皆辛苦！别浪费了。”\n");
        if ((me->query("food")*10/me->max_water_capacity())>8)
                return "你怎么吃饱了还想要？";
        if ( present("rice", this_player()))
                return "先吃完了我给你的再说吧。";
        if ( present("rice",  environment(me)) )
                return "那不是有吗？先吃完了再说。";              
        food = new (FOOD_D("rice"));
        food->move(me);
        return "这碗大米饭就给你了，慢点吃哟。";
}
 
string ask_water()
{
        object ob,me,water;
	ob=this_object();
        me=this_player();
        if ((me->query("water")*10/me->max_water_capacity())>8)
                return "你怎么喝饱了还想要？";
        if ( present("tea", this_player()))
                return "先喝完了我给你的再说吧。";
        if ( present("tea",  environment(me)) )
                return "那不是有吗？先喝完了再说。";
        water = new(FOOD_D("dawancha"));
        water->move(me);
        return "这杯大碗茶就给你吧，请慢点喝哟。";        
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
         
        if ( ob->query("combat_exp") < 1000){
          command(":) "+ob->query("id"));
          command("say 这里是厨房，你可以先看看有什么吃的和喝的，如果没了你就向我\n"+
          "要食物 "HIY HBCYN"ask wang about 食物"CYN" 和喝的 "HIY HBCYN"ask wang about 水"CYN" 吧。"NOR);
        }
}
