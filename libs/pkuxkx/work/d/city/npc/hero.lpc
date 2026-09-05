// 英雄 Zine

#include <ansi.h>
inherit NPC;


void create()
{
	string * surname=({"赵","钱","孙","李","周","吴","郑","王","东方", "独孤", "慕容", "欧阳", "司马","西门", "尉迟", "长孙", "诸葛"});
	string * givenname=({"一","二","三","四","五","六","七","八","九",});
	int i= random(2);
	set_name(surname[random(sizeof(surname))]+givenname[random(sizeof(givenname))], ({ "da xia", "hero"}));
	set("title", "侠义无双");
	set("gender", i?"男性":"女性");
	set("age", 20+random(30));
	set("long",(i?"他":"她")+"是一位侠义无双的大侠，准备护送难民过江。\n");
	set("attitude", "peaceful");
	set("combat_exp", 5000000);
	set("str", 20+random(5));
	set("int", 20+random(5));
	set("con", 20+random(5));
	set("dex", 20+random(5));
	set("skf_leader", "");
	set("max_qi", 20000);
	set("max_jing", 20000);
	set("qi",20000);
	set("max_neili", 20000);
	set("neili", 20000);
	set_temp("apply/armor", 100);
	set_temp("skf/huaquanpass",1);
	set_temp("skf/refugeeasked",1);
	set("eff_jing", 20000);
	set("eff_jingli", 20000);
	set("max_jingli", 20000);
	set_skill("dodge",300);
    set_skill("parry",300);
	set_skill("force",300);
	set_skill("strike",300);
	set_skill("taiyi-you",300);
	set_skill("taiyi-shengong",300);
	set_skill("taiyi-zhang",300);
	map_skill("force", "taiyi-shengong");
	map_skill("dodge", "taiyi-you");
	map_skill("strike", "taiyi-zhang");
	map_skill("parry", "taiyi-zhang");
	prepare_skill("strike", "taiyi-zhang");
	set("xj",0);
    set("jz",0);
    set("superhero",1);
	set("place",__DIR__"/xiaolu");
	set("no_get", 1);
	
	setup();		
	
	carry_object(__DIR__"items/cloth1")->wear();
	call_out("dest2",600);
    call_out("start",1);

	
}

int dest2()
{
	if(this_object());
	destruct(this_object());
}

int copy(object me)
{
	object ob=this_object();
	int i,tempskill;
    mapping skills;
	int exp,qi;
	qi=me->query("max_qi");
	exp = me->query("combat_exp");
	tempskill = to_int(pow(exp/100,0.333)*10);
    tempskill =tempskill/2*3;
    if (tempskill==0)
                 tempskill=10;
    skills = ob->query_skills();
    for (i=0;i<sizeof(skills);i++)
    {
        skills[keys(skills)[i]] = tempskill;
    }
    ob->set("skfleader",me->query("id"));
	ob->set("combat_exp", exp/2*3);
	
	ob->set("max_qi",qi);
	ob->set("qi", qi);
	ob->set("max_jing", qi);
	ob->set("jing", qi);
	ob->set("max_neili", me->query("max_neili"));
	ob->set("neili", ob->query("neili"));
	ob->set("max_jingli", me->query("max_jingli"));
	ob->set("jingli", ob->query("jingli"));
}


	
void die()
{
	object pl=find_player(this_object()->query("skfleader"));
	if (pl)
	{
		pl->add_temp("skf/killnumber",1);
	}
	::die();
}

int start()
{
    object ob=this_object();
    int i;
    object *all;
    if (ob && environment(ob))
    {
        all=all_inventory(environment(ob));
    }
    
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query_temp("skf/ct"))
        {
            ob->kill_ob(all[i]);
            message_vision("$N大喝一声：女真狗鞑子，我和你们拼了。\n",ob);
        }
        if (all[i]->query("qingqi"))
        {
            ob->kill_ob(all[i]);
            message_vision("$N大喝一声：女真狗鞑子，我和你们拼了。\n",ob);
        }
        else
        {
            continue;
        }
    }
    remove_call_out("start");
    call_out("start",15);
}

void init()
{
    object ob=this_object();
    object room;
    if (environment(ob))
    {
        room=environment(ob);
        if (room->query("xianjing")&&!ob->query("xj"))
        {
            message_vision("$N仰天长叹：中陷阱了！啊～～\n",ob);
            ob->add_busy(10);
            ob->set("xj",1);
        }
        if (room->query("jianzhu")&&!ob->query("jz"))
        {
            message_vision(RED"$N惨叫一声：陷阱还有家伙！我再啊～～\n"NOR,ob);
            ob->receive_damage("qi",ob->query("max_qi")/10*(int)room->query("jianzhu"));
            ob->receive_wound("qi",ob->query("max_qi")/10*(int)room->query("jianzhu"));
            ob->set("jz",1);
        }
        return;
    }
    else
    {
        return;
    }
}