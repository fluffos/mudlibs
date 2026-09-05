#include <ansi.h>
inherit NPC;

void create()
{
	set_name("桑坤", ({"sang kun","sang","kun"}));
	set("long", 
            HIG"他就是和林的大汗——桑坤。\n"NOR);
	set("gender", "男性");
	set("age", 55);
    set("combat_exp", 25000);
    set_skill("unarmed", 300);
    set_skill("force", 300);
    set_skill("dodge", 400);
    set_temp("apply/attack", 50);
    set_temp("apply/defense", 50);
	set_temp("shediaoquest/jdfm/kouling","finish");
	set("shen_type", -1);
	setup();
    
}

void die()
{
    object rm,killer,ob=this_object();
    if(!objectp(killer = get_damage_origin_object()))
    {
        ::die();
        return;
    }
    else if (killer->query_temp("shediaoquest/jdfm/kouling")=="finish")
    {
        rm=load_object("/d/menggu/d_menggubao00");
        killer->set_temp("shediaoquest/jdfm/jdfm",1);
        killer->set_temp("shediaoquest/jdfm/kill_sangkun",time());
        rm->trap(killer);
        ::die();
        return;
    }
    else
    {
        ::die();
        return;
    }
}