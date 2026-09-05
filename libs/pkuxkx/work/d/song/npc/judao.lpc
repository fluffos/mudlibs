#include <ansi.h>
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
    set("title",color1+"巨盗"+NOR);
    set("gender","男性");
    set("age",40);
    set("attitute", "peaceful");
    set("str",20);
    set("int",20);
    set("con",20);
    set("dex",20);
    set("shen_type",-1);
    set("score",3000);
    set("max_qi",120);
    set("max_jing",100);
    set("neili",150);
    set("max_neili",150);
    set("jiali",3);
    set("combat_exp",50000);
    set("random_npc",1);
    set_skill("force",40);
    set_skill("luoying-shenfa",30);
    set_skill("dodge",40);
    set_skill("claw",40);
    set_skill("parry",30);
    set_skill("bihai-shengong",30);
    set_skill("luoying-shenfa",40);
    set_skill("jiuyin-baiguzhao",50);
    map_skill("force","bihai-shengong");
    map_skill("dodge","luoying-shenfa");
    map_skill("claw","jiuyin-baiguzhao");
    map_skill("parry","jiuyin-baiguzhao");
    prepare_skill("claw","jiuyin-baiguzhao");
    
    setup();
    carry_object("/d/city/obj/cloth")->wear();
	call_out("dest",300);
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

void die()
{
    object killer;
    killer=this_object()->query("owner");
    if (killer->query_temp("songtasks/xingbu/task")==3)
    {
        killer->set_temp("songtasks/xingbu/3/finish",1);
		tell_object(killer,HIR+this_object()->name()+"拘捕，已被就地格毙。\n"+NOR);
		tell_object(killer,HIG+"你可以划船回去(hua back)，到刑部复命了。\n"+NOR);
    }
	dest();
	return ;
}
