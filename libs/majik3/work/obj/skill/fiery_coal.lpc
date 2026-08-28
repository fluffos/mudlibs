
inherit "obj/skill/obj/skill";
#include <spell.h>

create_skill()
{
    set_skill_name("fiery_coal");
    set_base_percent(20); 
    add_base_stat("pow",30);  // Total of Base Stats is 100
    add_base_stat("int",30);
    add_base_stat("wis",10);
    add_base_stat("dex",30);
    set_parent_skill("elemental_fire");
    set_ep_cost(1);
    set_sp_cost(10);
    set_hp_cost(1);
    set_duration(2);
    set_skill_duration(0);
    set_restricted(1);
}

do_success(me,target,result)
{
    object trg, coal;
    int dmg;
    trg=present(target,environment(me));
    if(!trg)
    {
	write("Throw your coal at whom?\n");
	return 1;
    }
    coal=present("coal",me);
    if(coal)
	destruct(coal);
    tell_object(trg,"A fiery coal hits your chest!\n");
    tell_object(me,"You throw a hot coal at "+target+"!\n");
    tell_room(environment(me),
      me->query_cap_name()+" throws some flames at "+
      trg->query_cap_name()+"!\n",
      ({me,trg}));
    dmg=MASTER->query_power_effect("damage_fire");
    trg->damage_me(dmg,2,"chest");
    return 1;
}

do_failure(me,target,result)
{
    tell_object(me,"Nothing happens.\n");
    return 1;
}

do_critical_failure(me,target,result)
{
    tell_object(me,"The coal gets stuck to your hand! Aaarrggghhh!\n");
    me->damage_me(MASTER->query_power_effect("fire_damage",1),2,"right arm");
    tell_room(environment(me),
      me->query_cap_name()+" plays with fire and burns "+
      me->query_possessive()+" hand!\n",({me}));
    return 1;
}
query_can_use(me, target)
{
    if(!present("coal",me))
    {
	write("You don't have a coal to throw!\n");
	return 0;
    }
    if(!target||!present(target,environment(me)))
    {
	write("Throw coal at whom?\n");
	return 0;
    }
    return ::query_can_use(me, target);
}
