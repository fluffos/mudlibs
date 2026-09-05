#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void gen_weapon(string type);

nosave string *all_ids=({"sword","blade","staff","whip","axe","spear","hammer","halberd","dagger"});
nosave int * weight=({10000,12000,30000,15000,18000,16000,31000,19000,7000});
nosave string *all_types =({"铁剑", "钢刀", "钢杖", "铁鞭", "钢斧", "钢枪", "铁锤", "铁戟", "铁匕"});
nosave mapping weapon_type = ([
        "sword"  : ({ "slash", "slice", "thrust", "pierce" }),
        "blade"  : ({ "slash", "slice", "hack", "chop" }),
        "staff"  : ({ "bash", "crush", "slam", "pierce", "impale" }),
        "whip"   : ({ "whip","wave" }),
        "axe"    : ({ "chop", "slice", "hack" }),
        "spear"  : ({ "thrust", "impale", "pierce" }),
        "hammer" : ({ "bash", "crush", "slam" }),
        "dagger" : ({ "pierce", "thrust" }),
        "fork"   : ({ "thrust", "pierce" }),
        "halberd"  : ({ "thrust", "impale", "pierce" }),    
        ]);

void create()
{
    gen_weapon(all_ids[random(9)]);
    setup();
}

void gen_weapon(string type) 
{
        int j,i;
        string name,id;
        object ob=this_object();
        set("skill_type",type);
        id=type;
        for (j=0;j<sizeof(all_ids);j++)
            {
                if (all_ids[j]==type)
                {
                    i=weight[j];
                    name=all_types[j];
                }
            }
        set("weapon_prop/damage", 100+random(50));
        set_name(name, ({id}) );  
        if( !ob->query("actions") )
        {
                ob->set("actions", (: call_other, WEAPON_D, "query_action" :) );
                ob->set("verbs", weapon_type[query("skill_type")]);	
        }
        set_weight(i);
        set("value",1);
        set("unit","柄");
        set("guozhan",1);
        set("no_store",1);
        set("no_sell",1);
        set("no_pawn",1);
        setup();	
}
