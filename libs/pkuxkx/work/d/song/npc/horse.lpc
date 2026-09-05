#include <ansi.h>
inherit NPC_TRAINEE;

void create()
{
        set_name("未驯服的战马", ({"horse", "ma"}));
        set_weight(35000);
	    set("race", "马类");
        set_max_encumbrance(80000);
        set("long", "一匹良种的战马，可以骑(ride)，也可以驮东西。\n");
        set("msg_fail", "$n冲着$N怒嘶一声，一摆头向旁边走去！");
        set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
        set("msg_trained","$n低鸣一声，走到$N身边挨挨擦擦，显得十分高兴！");
        set("ride_msg","一跃身骑");
        set("wildness", 1);
        set("combat_exp", 1000);
        set("horse",1);
        set("max_qi", 10000);
        set("qi", 10000);
		set("untrained",1);
        setup();
}

int train_it(object ob, object me, int pts)
{
	string msg_trained;

	if(!living(me)) return 1;

	if(me->query_lord())
		pts = 10 * pts / (me->query("loyalty") + 10);

	if(query_temp("trainer") != ob->name()) {
		set_temp("trainer", ob->name());
		set_temp("training_pts",pts);
	}
	else
		add_temp("training_pts",pts);

	if(query_temp("training_pts") > 40+random(40)) {
		delete_temp("trainer");
		delete_temp("training_pts");
		me->set("is_trainee",1);
        if(me->is_fighting())
			me->remove_all_enemy();
		me->set_lord(ob);
		if(!(msg_trained = me->query("msg_trained")))
			msg_trained = "$N驯服了$n";
        delete("untrained");
		message_vision(msg_trained + "。\n", ob, me);
		me->set_name("战马",({"horse","zhan ma","ma"}));
		if(me->query("auto_follow")) {
			me->set_leader(ob);
			message_vision("$n朝$N走了过来。\n", ob, me);
		}
	}
	return 1;
}
int dest(object ob)
{
	if (ob)
	destruct(ob);
}
void init()
{
	object me=this_object();
	object env=environment(me),pl;
	if (me->query("potential_owner"))
	if (userp(me->query("potential_owner")))
	set("long", "一匹良种的战马，可以骑(ride)，也可以驮东西。\n"+HBWHT+MAG+me->query("potential_owner")->query("name")+HBWHT+MAG+"奉命来驯服它。\n"+NOR);
	::init();
	if (!me->query_lord()||!env)
	return;
	pl=me->query_lord();
	if (pl->query_temp("songtasks/majun/task")!=4)
	return;
	if (base_name(env)!="/d/song/majun3")
	return;
	if (environment(pl)!=env)
	return;
	if (me->query("dest"))
	return;
	me->set("dest",1);
	pl->set_temp("songtasks/majun/4/finish",1);
	message_vision("$N把$n送入了马厩。\n",pl,me);
	call_out("dest",1,me);
	return;
}