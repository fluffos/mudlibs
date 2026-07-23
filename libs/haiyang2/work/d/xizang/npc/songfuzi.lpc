inherit NPC;
inherit F_DEALER;
#include <ansi.h>
void create()
{
    set_name("宋老夫子", ({ "song fuzi","song" }) );
    set("gender", "男性" );
    set("age", 99 );
    set("title", HIG "悬壶济世"NOR);
        set("long",
        "一个白发苍苍，闭目养神，似乎随时都可能倒下的老者。但偶尔双目\n睁开，立刻就象换了一个年轻人般。\n");
        set("attitude", "friendly");
    set("combat_exp", 500000);
        set("chat_chance", 1);
        set("chat_msg", ({
  "宋老夫子懒懒地抬起头，打量了你一眼。\n",
                }) );
        set("per",30);

	set("vendor_goods", ({
               __DIR__"obj/xuezhi",
               __DIR__"obj/sanyecao",
               __DIR__"obj/qisehua",
	}));        
    set_skill("fall-steps",100);
    set_skill("unarmed",200);
    set_skill("dodge",100);
    set_skill("parry",100);
    map_skill("dodge","fall-steps");
        setup();
    carry_object("/clone/misc/cloth")->wear();
}
  
void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
        ::init();
}  