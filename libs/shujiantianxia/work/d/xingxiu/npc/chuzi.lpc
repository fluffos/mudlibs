//wang1.c
inherit NPC;
#include <ansi.h>
string ask_food();
string ask_water();

void create()
{
        set_name("小厨子", ({ "xiao chuzi", "chuzi" }) );
        set("gender", "男性" );
        set("age", 28);
        set("long", 
             "小厨子是星宿派的食堂管事的。生性不爱练武功。"
             "只爱做饭，因老仙爱吃他做的菜，所以收他为徒。\n");
        set("str", 25);
        set("dex", 30);
        set("con", 17);
        set("int", 15);
        set("per", 20);
        set("shen", -300);
        set_skill("unarmed", 60);
        set_skill("force", 50);
        set_skill("dodge", 50);
        set_skill("zhaixingshu", 60);
        map_skill("dodge","zhaixingshu");
        set("combat_exp", 15000);

        set("max_qi", 500);
        set("max_jing", 500);

        create_family("星宿派", 2, "弟子");

        set("attitude", "peaceful");
       set("inquiry", ([
             "name" : "小生便是星宿派的厨子。",
             "手艺" : "我做菜的手艺可是西域一绝，连老仙他老人家也爱吃我做的菜！",
             "食物" : (: ask_food :),
             "水" : (: ask_water :), 
       ]) );

        setup();
        carry_object(ARMOR_D("pink_cloth"))->wear();
        add_money("silver", 10);
}

string ask_food()
{                    
        object ob,me,food;
        ob=this_object();
        me=this_player();
        say("小厨子说道：我做这点饭菜也不容易！别浪费了。”\n");
        if ((me->query("food")*10/me->max_water_capacity())>8)
                return "你怎么吃饱了还想要？";
        if ( present("cai yao", this_player()))
                return "先吃完了我给你的再说吧。";
        if ( present("cai yao",  environment(me)) )
                return "那不是有吗？先吃完了再说。";              
        food = new (FOOD_D("caiyao"));
        food->move(me);
        return "这盘菜就给你了，慢点吃哟。";
}
 
string ask_water()
{
        object ob,me,water;
        ob=this_object();
        me=this_player();
        if ((me->query("water")*10/me->max_water_capacity())>8)
                return "你怎么喝饱了还想要？";
        if ( present("qing hulu", this_player()))
                return "先喝完了我给你的再说吧。";
        if ( present("qing hulu",  environment(me)) )
                return "那不是有吗？先喝完了再说。";
        water = new(FOOD_D("hulu"));
        water->move(me);
        return "这个青葫芦就给你吧，请慢点喝哟。";        
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
         
        if ( ob->query("combat_exp") < 3000){
          command(":) "+ob->query("id"));
          command("say 这里是厨房，你可以先看看有什么吃的和喝的，如果没了你就向我\n"+
          "要食物 "HIY HBCYN"ask chuzi about 食物"CYN" 和\n喝的 "HIY HBCYN"ask chuzi about 水"CYN" 吧。"NOR);
        }
}
