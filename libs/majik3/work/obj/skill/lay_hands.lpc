//madrid

inherit "obj/skill/obj/skill";

create_skill()
{
    set_skill_name("lay_hands");
    set_train_difficulty(2);
    set_base_percent(10);
    add_base_stat("wis",40);
    add_base_stat("pow",20);
    add_base_stat("int",10);
    add_base_stat("cha",30);
    set_parent_skill("clerical_healing");
    set_ep_cost(5);
    set_sp_cost(30);
    set_hp_cost(0);
    set_duration(5);
    set_help("This skill is used to raise dead and revive the unconscious.\n");
}
do_success(me,target,result)
{
    object ob;
    int heal;
    string how;
    heal = random(100);
    switch(heal)
    {
    case 0..20:
	how = "a tiny bit";
	break; 
    case 21..50:
	how = "some";
	break;
    case 51..80:
	how = "quite a bit";
	break; 
    case 81..100:
	how = "a great deal";
	break; 
    default:
	how = "didn't work";
	break; 
    }
    ob = present (target, ENV(me));
    if(!ob)
    {
	write("Lay hands upon whom?\n");
	return 1;
    }
    if(ob->query_is_dead()||ob->query_is_unconscious())
	ob->revive();
    write("You call upon a blessing from Madrid and lay your hands "+
      "upon "+ob->query_cap_name()+".\n");
    ob->add_hp(heal);
    tell_object(ob,me->query_cap_name()+" laid his hands upon you "+
      "and heals you "+how+".\n");
    message("standard",me->query_cap_name()+" calls upon a blessing "+
      "from Madrid and lays his hands upon "+ob->query_cap_name()+
      ".\n",ENV(THIS),({THIS,target}));

    return 1;
}
do_failure(me,target,result)
{
    object ob;
    ob = present(target, ENV(me));
    if (!ob)
    {
	write("Lay hands on whom?\n");
	return 1;
    }
    write("You failed to recieve a blessin from Madrid.\n");
    return 1;
}
