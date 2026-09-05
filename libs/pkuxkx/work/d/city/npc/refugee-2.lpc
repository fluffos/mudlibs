// 难民 Zine 3 Sep 2010

#include <ansi.h>
inherit NPC;


void create()
{
	string * surname=({"赵","钱","孙","李","周","吴","郑","王","东方", "独孤", "慕容", "欧阳", "司马","西门", "尉迟", "长孙", "诸葛"});
	string * givenname=({"一","二","三","四","五","六","七","八","九",});
	int i= random(2);
	set_name(surname[random(sizeof(surname))]+givenname[random(sizeof(givenname))], ({ "nan min", "refugee"}));
	set("title", "扬州城难民");
	set("gender", i?"男性":"女性");
	set("age", 20+random(30));
	set("long",(i?"他":"她")+"是一个扬州的难民"+this_object()->query("name")+"\n");
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
	set_skill("dodge",10);
	set_skill("parry",10);
	set_skill("force",10);
	set_skill("strike",10);
	set_skill("taiyi-you",10);
	set_skill("taiyi-shengong",10);
	set_skill("taiyi-zhang",10);
	map_skill("force", "taiyi-shengong");
	map_skill("dodge", "taiyi-you");
	map_skill("strike", "taiyi-zhang");
	map_skill("parry", "taiyi-zhang");
	prepare_skill("strike", "taiyi-zhang");
	set("cantkill",0);
    set("refugee",1);
	set("place",__DIR__"/xiaolu");
	set("no_get", 1);
	
	setup();		
	
	carry_object(__DIR__"items/cloth1")->wear();
	call_out("dest2",15);
    

	
}

int dest2()
{
	if(this_object());
	destruct(this_object());
}

int copy(object me)
{
    string *malename=({"张有忌","郭立青","杨很康","胡不菲","云狄","乔风风","韦多宝","令狐退","陈嘉城","杨果果","石顶天","袁志承"});
    string *femalename=({"周芷","黄绒绒","木年词","袁子怡","水升升","阿竹","爽儿","任意意","珑儿","丁玲玲","温雯"});
	object ob=this_object();
	int exp,qi,tempskill;
    mapping skills;
	qi=me->query("max_qi");
	if (me->query("max_qi")>=2000)
	qi=2000;
	exp = me->query("combat_exp");
	tempskill = to_int(pow(exp/100,0.333)*10);
    tempskill =tempskill/10;
    if (tempskill==0)
    tempskill=10;
    if (random(100)>96)
    {
        if (ob->query("gender")=="女性")
        ob->set("name",femalename[random(sizeof(femalename))]);
        else
        ob->set("name",malename[random(sizeof(malename))]);
        qi=me->query("max_qi")/4*5;
        tempskill/5*6;
        message_vision("$N大喝一声，臭贼敢尔，我候你多时了。\n",ob);
        remove_call_out("dest2");
        call_out("dest2",400);
    }
    skills = ob->query_skills();
    for (int i=0;i<sizeof(skills);i++)
    {
        skills[keys(skills)[i]] = tempskill;
    }
    ob->set("skfleader",me->query("id"));
	ob->set("combat_exp", exp/10);
	
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
	if (this_object())
    {
        message_vision("$N惨叫一声，倒在路边。\n",this_object());
        destruct(this_object());
        return;
    }
}
