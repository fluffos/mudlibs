#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"震天雷"NOR, ({ "zhentian lei","bomb" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
		set("long", "威力巨大的火器，一旦爆炸，方圆数丈之内都难免波及。你可以点着它。(fire)\n"); 
		set("value", 500000);        
        }
        setup();
}

void firing()
{
    object* allob;
    object ob;
    if(query("firing") < 5)
    {
        add("firing",1);
        message("vision","震天雷嗤嗤的冒着青烟。。。\n",environment(this_object()));
        
        call_out("firing",1);        
    }
    else
    {
        allob = all_inventory(environment());
        message("vision","震天雷爆炸了！\n",environment(this_object()));
        for(int i=0;i<sizeof(allob);i++)
        {    
            if(!objectp(allob[i])) continue;
            ob = allob[i];  
            //昏迷的人没事，因为他们躺着
            if(!living(ob)) continue; 
            tell_object(ob,HIR"巨大的热浪向你扑来，瞬间将你变成一个火人！\n"NOR);
            if(ob->query("qi") < 500 || random(5) < 2)                            
            {
                //直接死掉
                ob->receive_damage("qi",1,"被震天雷炸");
                ob->die();
            }
            else
            {
                //掉一半气血,busy 5
                ob->receive_damage("qi", ob->query("qi")/2, "被震天雷炸");
                ob->receive_wound("qi", ob->query("eff_qi")/2, "被震天雷炸");
                COMBAT_D->report_status(ob);
                ob->add_busy(5);
            }
        }
        
        destruct(this_object());
    }
}

int do_fire(string arg)
{
    object me = this_player();
    object room = environment(me);

    if(stringp(arg) && arg == "zhentian lei")
    {
		if(room->istaskroom() != 1)
		{
			return notify_fail("震天雷十分危险，不能滥用！\n");
		}
        if(query("firing") != 1)
        {
            move(environment(me));
            message("vision",sprintf("%s点着了一颗震天雷，甩在地上！快跑！\n",me->query("name")),environment(this_object()));                     
            call_out("firing",1);
            me->add_busy(3);
            set("firing",1);            
        }
        return 1;
    }
    return 0;
}

void init()
{
    add_action("do_fire","fire");
}
