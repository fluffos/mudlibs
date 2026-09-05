#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIY"麋鹿"NOR, ({ "xiao lu", "lu", "deer" }) );
	set("race", "野兽");
	set("age", 5);
	set("long", "一只好可爱的小鹿。\n");
	set("attitude", "peaceful");
	
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
        set("max_qi",400);
        set("qi",400);
	set("combat_exp", 1000);
	set_temp("apply/attack", 2);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 2);
	set_temp("apply/armor", 1);
	setup();  
        carry_object("/d/taishan/obj/shexiang");
		carry_object(__DIR__"obj/shexiang");
}

void die()
{
	object ob;
	message_vision("$N凄惨地鸣叫几声，临死之前把自己的身体狠狠往\n岩石上撞去,身上的香腺血肉模糊，令人心惊！\n", this_object());
	ob = new(__DIR__"obj/lurou");
	ob->move(environment(this_object()));
	destruct(this_object());
}
void init()
{
        object ob;  
        ob=this_object();
        ::init();       
        remove_call_out("do_dest");
        call_out("do_dest",15,ob);
}

void do_dest(object ob)
{
	if (!ob || environment(ob) != environment())
                return;
  message_vision("$N趁你不备，转身钻进了身后的灌木丛。\n", ob);
 	destruct(ob);
}
	
