#include <ansi.h>

inherit NPC;

void create()
{
        set_name("值勤兵", ({ "solider", "garrison" }) );
        set("long",
"这是个正在执行守城任务的值勤兵，虽然和许多武林人物比起来，值勤兵们的武功\n"
"实在平常，但他们是有组织、有纪律的战士，谁也不轻易地招惹他们。\n"
"[31m你最好也不要招惹他们。如果你来巡城,可问他findbaogao. [37m\n");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
        set("combat_exp", 50000+random(300000));
        set_skill("unarmed", 70+random(100));
        set_skill("dagger", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100));

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/longdagger")->wield();
}

void init()
{
	add_action("do_xunchen", "findbaogao");
}

int do_xunchen()
{
        object *ob_list;
  	  object obn;
        int i;
        object me = this_player();
        if (present("xunchen1", me))  
         {
               message_vision("$N对着$n说：你身上不是已经有这里的巡城报告了吗!!\n", this_object(), me);
               return 1;
         }
        else
        obn=new(__DIR__"xunchen1");
        obn->random(1);
        obn->move(me);
        command("say 巡城报告，你拿去给王大人吧!");
        return 1;
}
//}

