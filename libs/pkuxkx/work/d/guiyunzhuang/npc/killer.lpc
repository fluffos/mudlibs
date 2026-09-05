#include <ansi.h>
#include <title.h>
#include "/d/guiyunzhuang/bonus.h"
inherit NPC;

void create()
{
    string name,*tmp,*pinying;
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string color1=color[random(sizeof(color))];
    name=NAME_D->create_female_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
    set("title",color1+"女飞贼"+NOR);
    set("gender","女性");
    set("age",40);
    set("attitute", "peaceful");
    set("str",28);
    set("int",29);
    set("con",29);
    set("dex",28);
    set("shen_type",-1);
    set("score",300000);
    set("max_qi",1200);
    set("max_jing",1000);
    set("neili",1500);
    set("max_neili",1500);
    set("jiali",30);
    set("combat_exp",350000);
    set("random_npc",1);
    set_skill("force",100);
    set_skill("luoying-shenfa",110);
    set_skill("dodge",100);
    set_skill("claw",150);
    set_skill("parry",100);
    set_skill("bihai-shengong",110);
    set_skill("luoying-shenfa",100);
    set_skill("jiuyin-baiguzhao",150);
    map_skill("force","bihai-shengong");
    map_skill("dodge","luoying-shenfa");
    map_skill("claw","jiuyin-baiguzhao");
    map_skill("parry","jiuyin-baiguzhao");
    prepare_skill("claw","jiuyin-baiguzhao");
    
    setup();
    carry_object("/d/city/obj/cloth")->wear();
	call_out("check",1);
	call_out("dest",300);
}

int check()
{
	object ob=this_object();
	object me;
	if (!ob->query("owner"))
	{
		destruct(ob);
		return 1;
	}
	me=find_player(ob->query("owner"));
	if (!me||!me->query_temp("thnewbiejob/taolin/gua"))
	{
		destruct(ob);
		return 1;
	}
	call_out("check",10);
}

int dest()
{
	if (this_object()&&environment(this_object()))
	{
		tell_room(environment(this_object()),this_object()->name()+"转身离开了这里。\n");
	}
	
	destruct(this_object());
	return 1;
}

int killing(object me)
{
    if (me&&present(me->query("id"),environment(this_object())))
    {
        kill_ob(me);
    }
    call_out("killing",30,me);
    return 1;
}

void do_copy(object me)
{
        object ob;
        mapping skills, hp_status, skill_status;
        int exp,i,tempskill;
        ob = this_object();
        
        exp = me->query("combat_exp");
        tempskill = to_int(pow(exp/100,0.333)*10);
        tempskill = to_int(tempskill*3/5);
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
        
        ob->set("combat_exp",me->query("combat_exp")*4/5);
        ob->set("qi", hp_status["max_qi"]);
        ob->set("eff_qi",hp_status["max_qi"]);
        ob->set("max_qi",hp_status["max_qi"]);
        ob->set("max_neili", hp_status["max_neili"]);
        ob->set("neili", hp_status["max_neili"]);
        ob->set("max_jingli", hp_status["max_jingli"]);
        ob->set("jingli", hp_status["jingli"]);
        ob->set("owner",me->query("id"));
        ob->set("uni_target", me);
        ob->set_temp("seeme",me->query("id"));
        me->set_temp("thnewbiejob/taolin/killer",ob->query("id"));
        call_out("killing",30,me);
        
}
//死亡管理
void die()
{
    object killer;
    if(!objectp(killer = get_damage_origin_object()) || killer->query("id") != this_object()->query("owner"))
    {
        command("say 嘿嘿，老娘不奉陪了。");
        destruct(this_object());
        return;
    }
    killer=this_object()->get_damage_origin_object();
    if(killer->query_temp("thnewbiejob/taolin/gua"))
    {
        bonus(killer,"killer");
    }
    destruct(this_object());
	return ;
}
