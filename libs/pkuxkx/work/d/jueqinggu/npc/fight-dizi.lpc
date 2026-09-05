
#include <ansi.h>
inherit NPC;
int ask_quest();

void create()
{
    string name,*tmp,*pinying;
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string color1=color[random(sizeof(color))];
    name=NAME_D->create_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("title",HIG+"绝情谷 "+color1+"护法弟子"+NOR);
	set("shen_type", 1);
    set("花圃",1);
	set("str", 30);
	set("gender", "男性");
    set("fight_dizi",1);
	set("age", 20+random(10));
	set("combat_exp", 500000);
    set_skill("unarmed", 200);
    set_skill("dodge", 200);
    set_skill("parry", 200);
    set_skill("force", 200);
    set("eff_qi",1000000);
    set("max_qi",1000000);
    set("qi",1000000);
    set_temp("apply/attack",  100);
    set_temp("apply/defense", 100);
    set_temp("apply/damage",  100);
	set("attitude", "friendly");
	set("random_npc",1);
/*	set("inquiry", ([
			"离谷" : (: ask_quest :),
            "out" : (: ask_quest :),
            "leave" : (: ask_quest :),
            "离开" : (: ask_quest :),
       	]) );
*/
	setup();
    carry_object(__DIR__"obj/cloth-2")->wear();

}

int stopping(object me)
{
    command("halt");
}

void init()
{
    int i;
    object *all=all_inventory(environment(this_object()));
    object user,target;
    object me=this_object();
    for (i=0;i<sizeof(all) ;i++ )
    {
        if (userp(all[i]))
        {
            user=all[i];
        }
        if (!userp(all[i])&&all[i]->query("fight_dizi")&&all[i]!=me)
        {
            target=all[i];
        }
    }
    if (user&&target)
    {
        fight_ob(target);
    }
    call_out("stopping",120,me);
}