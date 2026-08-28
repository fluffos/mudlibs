inherit "obj/skill/obj/skill";
#include <spell.h>

create_skill()
{
    set_skill_name("deformation");
    set_train_difficulty(7);
    set_base_percent(0);
    add_base_stat("pow",40);
    add_base_stat("wis",40);
    add_base_stat("int",20);
    set_parent_skill("primal evil");
    set_ep_cost(5);
    set_sp_cost(40);
    set_hp_cost(0);
    set_duration(6);
    set_skill_duration(0);
    set_restricted(1);
}

do_success(me, target, result)
{
    string slot,side;

    if(!present(target))
    {
        message("0","You are done with the chant, but then notice that "+target
        + " isn't here.\n",me);
        return 1;
    }
    message("0",me->query_cap_name()+" chants 'agarzz grahaz' and points a finger at "
    + present(target)->query_cap_name()+".\n",ENV(me),({me,present(target)}));
    message("0","You chant 'agarzz grahaz' and point a finger at "
    + present(target)->query_cap_name()+".\n",me);
    message("0",me->query_cap_name()+" chants 'agarzz grahaz' and points a finger at "
    + "you.\n",present(target));

    if(!present(target)->query("location_map"))
    {
        message("0",present(target)->query_name()+" is not a legal target.\n",me);
        return 1;
    }
    slot=keys(present(target)->query("location_map"))[random(sizeof(keys(present(target)->query("location_map"))))];
    if (random(1)==0)
        side="right";
    else
        side="left";

    present(target)->do_cripple(side,slot);
    message("0",present(target)->query_cap_name()+"'s "+side+" "+slot+" becomes deformed badly.\n",ENV(me));

}

do_failure(me, target, result)
{
    if(!present(target))
    {
        message("0","You are done with the chant, but then notice that "+target
        + " isn't here.\n",me);
        return 1;
    }
    message("0",me->query_cap_name()+" chants 'agarzz grahaz' and points a finger at "
    + present(target)->query_cap_name()+".\n",ENV(me),({me,present(target)}));
    message("0","You chant 'agarzz grahaz' and point a finger at "
    + present(target)->query_cap_name()+".\n",me);
    message("0",me->query_cap_name()+" chants 'agarzz grahaz' and points a finger at "
    + "you.\n",present(target));

    message("0",me->query_cap_name()+" fails miserably.\n",ENV(me),me);
    message("0","You fail miserably.\n",me);

    return 1;
}

do_message()
{
    message("0","You recite a prayer to the chaos gods and start chanting.\n",THIS);
    message("0",THIS->query_cap_name()+" recites a vile prayer to the chaos gods and starts chanting.\n",ENV(THIS),THIS);
    return 1;
}

