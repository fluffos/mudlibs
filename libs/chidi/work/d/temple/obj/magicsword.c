// sword.c
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIC "光之剑" NOR, ({ "sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",HIC"一把泛着天蓝色的魔法之剑\n"NOR);
                set("value", 1);
                set("material", "steel");
                set("wield_msg", "光线在$N的手上渐渐形成了一把$n。\n");
                set("unequip_msg", "$n渐渐分解。消失了。\n");
           set("no_drop",1);
           set("no_get",1);
        }

        init_sword(1);
        setup();

}

int do_dest(object me,int time)
{
	remove_call_out("dest");
	call_out("dest",time,me);
	return 1;
}

int dest(object me)
{
	string msg;
if(!me)
        destruct(this_object());
else    
	{
        msg=HIC"光之剑渐渐消失了\n"NOR;
	message_vision(msg,me);
	destruct(this_object());
	}
}

void break_weapon()
{
     
        tell_room(environment(),"光之剑消失了\n");
	call_out("dest_sword",1,this_object());
	return ;
}

int dest_sword(object sword)
{
	destruct(sword);	
}
