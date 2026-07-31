// hgweishi.c
 
inherit NPC;
#include "action.h"
#include "party.h"

void create()
{
        int rd;
 

	mapping npc,mp,j;
	mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
	string sex;
	object ob, weapon;
	int i,k,a,b,c,d,e,f,temp;

        int gd,sk;
	mp=menpai[random(sizeof(menpai))];
	j=ps[random(sizeof(ps))];
ob=this_object();
	k=random(17);
        gd=random(2);
        sk=random(10);        
                rd=random(4);
        set_name("护宫卫士", ({ "wei shi", "shi"}) );
        set("title", "天宫");
        set("gender", "男性" );
        set("long", 
                "一个威武的护宫卫士，膀阔腰圆，力大无穷。\n"
                "他手持兵刃，身穿宝甲，目光扫视着每个路过的人。\n"
        );
        set("age", 19+random(15));
        set("str", 25);
        set("int", 20);
        set("per", 15+random(10));
        
    
    set("combat_exp", 170000);
  set("daoxing", 70000);

  



	set("max_qi", 800);
	set("max_jing", 800);
        set("neili",800);
        set("max_neili",800);
	set("force_factor", 55);
	set("mana", 800);
	set("max_mana", 800);
	set("mana_factor", 40);
        set_skill("unarmed",109);
        set_skill("dodge",109);
        set_skill("parry",109);
 	set("combat_exp",19000000+random(20000000));
	set_temp("apply/attack",30);
	set_temp("apply/defense",30);
	set_temp("apply/armor",250);
	set_temp("apply/damage",250);
	set("max_force",2000);
	set_skill("unarmed",200);
	set_skill("sword",200);
	set_skill("club",200);
	set_skill("whip",200);
	set_skill("throwing",200);
	set_skill("parry",200);
	set_skill("dodge",200);
        set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
b=14000+random(4000);
a=16000+random(9000);
d=60+random(60);
set("str",d);
set("dex",d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
        set("jing",b);
        set("max_jing",b);
set("eff_jing",b);
        set("neili",a);
        set("max_neili",a);
	this_object()->set("party",ps[k]["party"]);
	this_object()->set_skills(ps[k]["skills"]);
	this_object()->set_skill_map(ps[k]["skill_map"]);
	this_object()->set_skill_prepare(ps[k]["skill_prepare"]);
        i=800+random(500);
        e=800+random(500);
	for (k = 0; k < sizeof(ns); k++)
		this_object()->set_skill(ns[k], i);

		this_object()->set_skill("literate",i);
        this_object()->set_skill("shenzhao-jing",e);
if (mapp(skill_status = this_object()->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
{
skill_status = this_object()->query_skills();
sname = keys(skill_status);//传回所有自己的功夫阵列

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
this_object()->set_skill(sname[i],e);//删除自己所有功夫
}
        this_object()->change_combat_mode();
set("chat_chance_combat", 100);
set("chat_msg_combat", get_auto_actions("perform"));
change_combat_mode(ob, 1);
        
f=1+random(8);        
	setup();

	if (ob->query("gender")=="女性")
	{
	carry_object("/clone/cloth/female"+f+"-cloth")->wear();
	carry_object("/clone/cloth/female-shoe")->wear();
	}
else {
	carry_object("/clone/cloth/male"+f+"-cloth")->wear();
	carry_object("/clone/cloth/male-shoe")->wear();
}        
        if (stringp(ob->query_skill_mapped("sword"))) 
	carry_object(__DIR__"weapon/sword")->wield();
	if (stringp(ob->query_skill_mapped("blade"))) 
	carry_object(__DIR__"weapon/dao")->wield();
	if (stringp(ob->query_skill_mapped("whip"))) 
	carry_object(__DIR__"weapon/bian")->wield();
	if (stringp(ob->query_skill_mapped("hammer"))) 
	carry_object(__DIR__"weapon/hammer")->wield();
	if (stringp(ob->query_skill_mapped("staff"))) 
	carry_object(__DIR__"weapon/ban")->wield();
	if (stringp(ob->query_skill_mapped("axe"))) 
	carry_object(__DIR__"weapon/axe")->wield();

	add_money("silver",50+random(50));
}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") )
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
if(wizardp(ob[i])) continue;
         if(!userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        call_out("check",0);
        }
}