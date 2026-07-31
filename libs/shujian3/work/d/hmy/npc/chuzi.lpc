// chuzi.c
// Modified by Numa 19991108

inherit NPC;
string ask_food();
string ask_water();

void create()
{
        set_name("厨师", ({ "chu zi", "chu" }));
        set("title", "日月神教");
        set("long", 
                "日月神教的一个厨子，笑眯眯地看着你，看来很和善的样子。\n");
        set("gender", "男性");
        set("age", 34);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);
        
        set("max_qi", 200);
        set("max_jing", 50);
        set("neili", 0);
        set("max_neili", 0);
        set("jiali", 0);
        set("combat_exp", 500);
        set("shen",0);
        set("score", 0);

        set_skill("force", 10);
        set_skill("dodge", 10);
        set_skill("cuff", 10);
        set_skill("parry", 10);

        create_family("日月神教", 3, "弟子");
        set("inquiry", ([
              "茶" : (: ask_water :),
              "水" : (: ask_water :),
              "棕子" : (:ask_food:),
              "食物" : (:ask_food:),
        ]));

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
}

string ask_food()
{                    
        object ob;
        object me;
                object food;
        ob=this_object();
        me=this_player();
        if ((me->query("food")*10/me->max_water_capacity())>8)
                return "你怎么吃饱了还想要？";
        if ( present("rice", this_player()))
                return "先吃完了我给你的再说吧。";
        if ( present("rice",  environment(me)) )
                return "那不是有吗？先吃完了再说。";              
        food = new (FOOD_D("zongzi"));
        food->move(environment(ob));
        return "这个又香又热的棕子给你吧，请慢点吃哟。";

}
 
string ask_water()
{
        object ob;
        object me;
        object water;
        ob = this_object();
        me = this_player();
        if ((me->query("water")*10/me->max_water_capacity())>8)
                return "你怎么喝饱了还想要？";
        if ( present("tea", this_player()))
                return "先喝完了我给你的再说吧。";
        if ( present("tea",  environment(me)) )
                return "那不是有吗？先喝完了再说。";
        water = new (FOOD_D("tang"));
        water->move(environment(ob));
        return "这杯大碗茶就给你吧，请慢点喝哟。";
        
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
         
        command(":) "+ob->query("id"));
        command("say 快进来，累了吧？我给您弄点吃的和喝的。");
}
