//chuzi.c 厨子
inherit NPC;
#include <ansi.h>
string ask_water();
string ask_food();
void create()
{
        set_name("厨子",({"chu zi", "chuzi"}));
        set("long","他以前是皇家的御厨，皇上将他送到嵩山掌管嵩山派弟子的饮食。\n");
        set("gender", "男性");
        set("age", 36);
        set("attitude", "friendly");
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 100);
        set("max_neili", 100);
        set("jiali", 1);
        set("combat_exp", 3500);
        set_skill("unarmed",20);
        set_skill("parry",20);
        set_skill("dodge",20);
        set_skill("force", 20);
        set_skill("sword", 20);
        set("inquiry", ([
              "水" : (: ask_water :),
              "食物" : (:ask_food:),
        ]));
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

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say(CYN"厨子笑着说道：这位" + RANK_D->query_respect(ob)
             + "，您来尝尝我的手艺。\n"NOR);
}

string ask_water()
{
        object ob;
        object me;
        ob=this_object();
        me=this_player();
        if ((me->query("water")*10/me->max_water_capacity())>8)
                return "你怎么喝饱了还想要？";
        if ( present("suanmei tang", this_player()))
                return "先喝完了我给你的再说吧。";
        if ( present("suanmei tang",  environment(me)) )
                return "那不是有吗？先喝完了再说。";
        ob=new(FOOD_D("tang"));
        ob->move(environment(this_object()));
        return "这杯又甜又热的酸梅汤给你吧，请慢点喝哟。";
}

string ask_food()
{
        object ob;
        object me;
        ob=this_object();
        me=this_player();
        if ((me->query("food")*10/me->max_water_capacity())>8)
                return "你怎么吃饱了还想要？";
        if ( present("zongzi", this_player()))
                return "先吃完了我给你的再说吧。";
        if ( present("zongzi",  environment(me)) )
                return "那不是有吗？先吃完了再说。";
        ob=new(random(2)==1?FOOD_D("liji"):FOOD_D("mantou"));
        ob->move(environment(this_object()));
        return "来，尝尝吧，看我的手艺如何！";
}
