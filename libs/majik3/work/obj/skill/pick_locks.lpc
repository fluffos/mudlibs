// namhas

inherit "obj/skill/obj/skill";

create_skill()
{
    set_skill_name("pick_locks");
    set_train_difficulty(2);
    set_base_percent(15);
    add_base_stat("dex",90);  // Total of Base Stats is 100
    add_base_stat("int",10);
    set_parent_skill("stealing");
    set_ep_cost(30);
    set_sp_cost(0);
    set_hp_cost(0);
    set_duration(3);
}

do_success(me,target,result)
{
    mapping m;

    m = ENV(me)->query_doors();

    if (!m)
	return 1;

    if (result >= m[target][4]) {
	tell_object (me, "You hear a soft click echoing from the lock.\n");
	m[target][5] = 1;
    }
    else {
	tell_object (me, "You hear a soft click echoing from the lock.\nOops! You fumbled and the door is again locked.\n");
    }
    return 1;
}

do_failure(me,target,result)
{
    tell_object (me, "You fail in picking the lock.\n");
    tell_room (ENV(me), THIS->query_cap_name() + " failed in picking lock in the door.\n", ({ me }));
    return 1;
}

query_can_use(me, target)
{
    if(ENV(THIS)->find_door(target))
    {
	write("Pick lock in which direction?\n");
	return 0;
    }
    return ::query_can_use(me, target);
}

int
do_message ()
{
    tell_object (THIS, "You begin to pick the lock.\n");
    tell_room (ENV(THIS), THIS->query_cap_name() + " begins to pick the lock.\n", ({ THIS }));
    return 1;
}
