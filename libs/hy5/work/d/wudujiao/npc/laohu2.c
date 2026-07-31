// by victori
inherit NPC;
#include <ansi.h>

string *first_name = ({"小"});
string *name_words = ({ "虎崽"});
void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        set_name(name,({"hu zai"}));
	set("race", "野兽");
        set("long", "一只刚出生几个月的小老虎，正和同伴们扑打游戏。\n");
	set("age", 1);
	set("attitude", "peaceful");

	set("max_ging", 400);
	set("max_qi", 400);

	set("str", 20);
	set("con", 50);

	set("limbs", ({ "头部", "身体", "尾巴" ,"腿"}) );
	set("verbs", ({ "bite" }) );

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/damage", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/armor", 20);

	set("combat_exp", 50000);
 
        set_weight(20000);
//	carry_object("/clone/misc/cloth")->wear();
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
