// namhas

inherit "obj/skill/obj/skill";

create_skill()
{
    set_skill_name("pick_pockets");
    set_train_difficulty(2);
    set_base_percent(11);
    add_base_stat("agi",10);  // Total of Base Stats is 100
    add_base_stat("int",20);
    add_base_stat("dex",70);
    set_parent_skill("stealing");
    set_ep_cost(25);
    set_sp_cost(0);
    set_hp_cost(0);
    set_duration(3);
    set_not_in_battle();
}

do_success(me,target,result)
{
    int i;
    object ob;

    ob = find_player(target);

    if (!ob)
    {
	write ("Steal money from who?\n");
	return 0;
    }

    i = random (ob->query_money());

    if (!i || i == 1)
    {
	tell_object(me, "You didn't quite steal anything.\n");
	return 0;
    }

    tell_object(me, "You stole "+i+" gold pieces.\n");
    ob->add_money (-i);
    me->add_money (i);
    me->add_aligny (-5);
    call_out ("do_notify", 25 + random(50), ob);
    return 1;
}

do_failure(me,target,result)
{
    object ob;
    int notice;

    ob = find_player(target);

    if (ob && ENV(ob) == ENV(me)) {
	if (random(201) < THIS->query_skill_chance("sneak"))
	{
	    notice = 1;
	    me->add_crimes (0);
	}
	else
	{
	    tell_object(ob, "You notice "+capitalize(me->query_name())+"'s hand at your pocket!\n");
	    tell_room(environment(ob), capitalize(me->query_name())+" tried to steal money from "+capitalize(ob->query_name())+"!\n", ({ me, ob }));
	    me->add_aligny (-1);
	    me->add_crimes (1);
	}
    }
    else {
	tell_object(me, "Steal money from who?\n");
	return 0;
    }

    if (notice)
	tell_object(me, "You failed but luckily "+ob->query_pronoun()+" didn't notice!\n");
    else
	tell_object(me, "You failed and "+capitalize(ob->query_name())+" notices your attempt.\n");
    return 1;
}

do_notify (object ob)
{
    remove_call_out ("do_notify");
    tell_object (ob, "Your purse feels lighter.\n");
    return 1;
}

query_can_use(me, target)
{
    if(!target||!present(target,environment(me))||present(target)==me)
    {
	write("Steal from whom?\n");
	return 0;
    }
    return ::query_can_use(me, target);
}

int
do_message ()
{
    if (random(101) < THIS->query_skill_chance("sneak")) {
	tell_object (THIS, "You begin to do the skill.\n");
    }
    else {
	tell_object (THIS, "You begin to do the skill.\n");
	tell_room (ENV(THIS), THIS->query_cap_name() + " begins to do something.\n", ({THIS}));
    }

    return 1;
}
