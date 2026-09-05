// bj

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("张崇威",({ "zhang chongwei", "zhang", "chongwei" }) );
        set("gender", "男性" );
        set("title",HIR"神威镖局 "+NOR+"总镖头"+NOR);
        set("age", 40+random(20));
        set("long", "这是个外家高手，一看就不好惹。\n");
		set("str", 10);
        set("dex", 1);
        set("con", 1);
        set("int", 1);
		set("shen_type", 1);
        set_temp("apply/defense", 10);
        set("combat_exp", 1);
        set("attitude", "peaceful");
        set_skill("sword", 250);
        set_skill("parry",250);
        set_skill("dodge", 250);
        set_skill("force",250);
        set_skill("literate",250);
        set_skill("taiyi-zhang",250);
        set_skill("strike",250);
        set_skill("taiyi-jian",250);
        set_skill("taiyi-shengong",250);
        set_skill("taiyi-you",250);
        

        map_skill("parry","taiyi-zhang");
        map_skill("sword","taiyi-jian");
        map_skill("force","taiyi-shengong");
        map_skill("dodge","taiyi-you");
        map_skill("strike","taiyi-zhang");

        
        prepare_skill("strike","taiyi-zhang");  
        setup();
        add_money("silver", 20+random(8)*10);
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
    add_action("do_taozhai", "taozhai");
    add_action("do_taozhai", "tao");
}

int do_taozhai()
{
    object ob=this_object();
    object me=this_player();
    if( me->is_busy() )
        return notify_fail("你正忙着呢。\n");
    if (me->query_temp("jn/step4c"))
    {
        if (random(100)>90)
        {
            tell_object(me,ob->query("name")+"很不情愿地说：怕了你了，帮我带个话给总管，他的赌债我三日内必上门奉还。\n");
            me->delete_temp("jn/step4c");
            me->set_temp("jn/step4d",1);
            return 1;
        }
        else
        {
            message_vision("$N假装没听懂$n在说什么，就是不理睬$n。\n",ob,me);
            me->add_busy(1);
            return 1;
        }
    }
    else
    {
        command("say 找死啊？敢来讹老子钱？");
		return 1;
    }
}
