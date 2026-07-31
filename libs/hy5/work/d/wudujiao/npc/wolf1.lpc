// by victori
inherit NPC;
#include <ansi.h>

string *first_name = ({ "白眼", "饿", "公", "母"});
string *name_words = ({ "狼"});
void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        set_name(name,({"wolf"}));
	set("race", "野兽");
        set("long", "一只凶狠残暴的狼，正瞪着火红的狼眼盯着你。\n");
	set("age", 3);
	set("attitude", "peaceful");

	set("max_ging", 700);
	set("max_qi", 700);

	set("str", 20);
	set("con", 50);

	set("limbs", ({ "头部", "身体", "尾巴" ,"腿"}) );
	set("verbs", ({ "bite" }) );

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/attack", 50);
	set_temp("apply/damage", 50);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 50);

	set("combat_exp", 100000);
 
 //    set_weight(500000);
//	carry_object("/clone/misc/cloth")->wear();
	set("chat_chance", 15);
	set("chat_msg", ({
	(: random_move :)
	}) );

	setup();
}
void init()
{
        object me;
//       ::init();
//      add_action("do_train", "train");
//       object me,ob;
//        ::init();
        if (interactive(me = this_player()))
        {
        if( me->query("combat_exp") > 80000)
{
      	       remove_call_out("kill_ob");
              call_out("kill_ob", 1, me);
}
        }
        ::init();
}
