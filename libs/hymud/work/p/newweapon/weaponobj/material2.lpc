// buliao.c

#include <ansi.h>
inherit ITEM;

void initlvl();
#include "material.h"

void create()
{
        set_name("玉石", ({ "yushi" }));
        set_weight(3000+random(5000));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一块普通的玉石。\n");
                set("value", 3000);
                
                set("no_sell",1);// add by LinuX@SJ
        }
        setup();
        initlvl();
}

int set_level(int level,int hehe)
{
	string type;
	mapping get;
	set("name","测试");
	set("id","hxsd");

		if(hehe==1)
{		
		 type="weapon";
set("wyushi",1);
}
	else if(hehe==2)
{
type="armor";
set("ayushi",1);
}
	if(hehe==1) type="weapon";
	else if(hehe==2) type="armor";
	else type=random(2)?"weapon":"armor";
	if(level<1 || level>6) return 0;
	get = essence[type][level-1];

	
	set("level",level);	
	set_weight(get["weight"]);
	set("long",get["long"]);	
	//set("long2",get["long"]);
	set("unit",get["unit"]);
	set("material_level",get["level"]);
	set("material_attrib",1);
	set("material_status",get["status"][0]+random(get["status"][1]));
	set("value",get["value"][0]+random(get["value"][1]));
	if(arrayp(get["damage"])) set("material_prop/damage",get["damage"][0]+random(get["damage"][1]));
	if(arrayp(get["armor"])) set("material_prop/armor",get["armor"][0]+random(get["armor"][1]));
		
	if(random(20)==1){
		set_name(get["name"],get["id"]);
		//WORKER_D->get_status(this_object(),3,query("material_status"),1,type);
		}
	else {
	set_name(get["name"]+NOR,get["id"]);
		//WORKER_D->get_status(this_object(),3,query("material_status"),0,type);
	}
	if(type=="weapon"){
		delete("material_prop/armor");
		delete("material_prop/defense");
	}
	if(type=="armor"){
		delete("material_prop/damage");
		delete("material_prop/attack");
	}	
	//msg = WORKER_D->get_msg(query("material_prop"));
	//if(stringp(msg) && msg!="") set_temp("apply/long",({short()+"\n"+query("long")+msg }));	
	return 1;
}

void initlvl() { set_level(2,1); }

