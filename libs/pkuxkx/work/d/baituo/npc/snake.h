#include <ansi.h>
void init()
{
        object ob;
        ::init();
	add_action("convert","convert");
        if (interactive(ob = this_player()) && !(present("xiong huang", ob))
  	     && ob->query("family/family_name") != "白驼山")
      {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	F_POISON->poison_attack(me,victim,"snake_poison", 10 + me->query("snake_poison") +
		victim->query_condition("snake_poison"));
	if (me->query("bite_busy")) victim->start_busy(2);
}

int convert(string arg)
{
	object me = this_player();
	object ob;

	if (arg!="snake" && arg!="she") return 0;
	if (me->query("family/family_name") != "白驼山") 
		return notify_fail("你不能化蛇为杖。\n");
	if (random(me->query_skill("training",1)) <20) {
              tell_object(me,RED"你转化蛇杖失败，毒蛇反而向你进行攻击。\n"NOR);
		kill_ob(me);
		return 1;
	}
	message_vision("$N左手按住毒蛇的头，右手轻抚其七寸，口中念念有词，片刻间将蛇化为一根蛇杖。\n",
		me,);
	        ob = new("/d/baituo/obj/shezhang");
        ob->move(environment(this_object()));
        destruct(this_object());
	return 1;
}
