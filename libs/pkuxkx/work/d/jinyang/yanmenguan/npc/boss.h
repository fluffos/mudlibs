#include <ansi.h>



void init()
{
    add_action("do_none", "steal");
    add_action("do_none", "attack");
    add_action("do_none", "beg");
    set("random_npc",1);
    set("yanmen_enemy",1);
}

int kill_target()
{
	object ob=this_object();
    object env=environment(ob);
    object *all_target;
    int i;
    if (env)
    {
        all_target=all_inventory(env);
    }
    for (i=0;i<sizeof(all_target);i++)
    {
        if (all_target[i]->query_temp("yanmen/permit"))
        {
            kill_ob(all_target[i]);
        }
    }
	return 1;
}

void leave()
{
    object ob = this_object();
    message_vision("$N眼见无法占到便宜，干脆先撤离了。\n",ob);
    destruct(ob);
	return;
}

void do_copy(object me)
{
        object ob=this_object();
        mapping skills, hp_status, skill_status;
        int i,exp,count,tempskill;
        exp = (int)me->query("combat_exp");
        tempskill = to_int(pow(exp/100,0.333)*10);
        if ((int)ob->query("boss")==1)
        {
            tempskill=tempskill*12/10;
        }
        if ((int)ob->query("boss")==2)
        {
            tempskill=tempskill*13/10;
        }
        if ((int)ob->query("boss")==3)
        {
            tempskill=tempskill*3/2;
        }
        if (tempskill<300)
                 tempskill=300;
        skills = ob->query_skills();
        for (i=0;i<sizeof(skills);i++)
        {
            skills[keys(skills)[i]] = tempskill;
        }
        hp_status = me->query_entire_dbase();
        ob->set("str", hp_status["str"]+random(5));
        ob->set("int", hp_status["int"]+random(5));
        ob->set("con", hp_status["con"]+random(5));
        ob->set("dex", hp_status["dex"]+random(5));
        
        ob->set("combat_exp",exp);
}

int bonus(object me)
{
    tell_object(me,"你总过获得"+chinese_number(me->query_temp("yanmen/credit"))+"点积分。\n");
}

void die()
{
    object ob=this_object();
    object env=environment(ob);
    object *all=all_inventory(env);
    object obj;
    int i,count=5+random(15)+(2+random(4))*(int)ob->query("boss");
    if (ob->query("boss")==2&&!ob->query("yanmen/fullme"))
    {
        ob->add("yanmen/fullme",1);
        message_vision(HIR"$N大喝一声，将生命潜力全部逼出，准备背水一战了。\n"NOR,ob);
        ob->set("max_qi",(int)ob->query("max_qi")/2);
        ob->set("eff_qi",(int)ob->query("max_qi"));
        ob->set("qi",(int)ob->query("max_qi"));
        ob->set("max_jing",(int)ob->query("max_jing")/2);
        ob->set("eff_jing",(int)ob->query("max_jing"));
        ob->set("jing",(int)ob->query("max_jing"));
        ob->set("neili",(int)ob->query("max_neili")*3/2);
        ob->add_temp("apply/dodge",(int)ob->query_skill("dodge",1)/5);
        ob->add_temp("apply/parry",(int)ob->query_skill("parry",1)/5);
        return; 
    }
    if (ob->query("boss")==3&&ob->query("yanmen/fullme")<3)
    {
        ob->add("yanmen/fullme",1);
        message_vision(HIR"$N大喝一声，将生命潜力全部逼出，准备背水一战了。\n"NOR,ob);
        ob->set("max_qi",(int)ob->query("max_qi")/10*12);
        ob->set("eff_qi",(int)ob->query("max_qi"));
        ob->set("qi",(int)ob->query("max_qi"));
        ob->set("max_jing",(int)ob->query("max_jing")/10*11);
        ob->set("eff_jing",(int)ob->query("max_jing"));
        ob->set("jing",(int)ob->query("max_jing"));
        ob->set("neili",(int)ob->query("max_neili")*3/2);
        ob->add_temp("apply/dodge",(int)ob->query_skill("dodge",1)/15);
        ob->add_temp("apply/parry",(int)ob->query_skill("parry",1)/15);
        return;
    }
    for (i=0;i<count;i++)
    {
        switch(random(5))
        {
            case 0:
                obj=new("/d/jinyang/yanmenguan/obj/dan");
            break;
            case 1:
                obj=new("/d/jinyang/yanmenguan/obj/wan");
            break;
            case 2:
                obj=new("/d/jinyang/yanmenguan/obj/wan2");
            break;
            case 3:
                obj=new("obj/gem/armor");
            break;
            case 4:
                obj=new("obj/gem/weapon");
            break;
        }
        obj->set("yanmen_item",1);
        obj->move(env);
    }
    for (i=0;i<sizeof(all);i++)
    {
        if (userp(all[i]))
        {
            bonus(all[i]);
        }
    }
    message_vision("$N苦战多时，真力耗尽，气绝身亡。\n",ob);
    message_vision("$N身上掉下了一些药物和装备。\n",ob);
    ::die();
}

void unconcious() 
{
    object ob=this_object();
    object killer=ob->get_damage_origin_object();
    if(ob->query("qi") > (ob->query("max_qi")/100)*20 && ob->query("eff_qi") > (ob->query("max_qi")/100)*20 && ob->query("jing") > (ob->query("max_jing")/100)*20 && ob->query("eff_jing") > (ob->query("max_jing")/100)*20)
		{
            tell_object(killer,"想用一招晕解决"+ob->name()+"？别做梦了！\n");
			return;
		}
}

int do_none()
{
    return 1;
}

varargs int receive_damage(string type, int damage, mixed who)
{
	if(userp(who))
			{
				who->add_temp("yanmen/credit",damage);				
			}
	return ::receive_damage(type,damage,who);
}