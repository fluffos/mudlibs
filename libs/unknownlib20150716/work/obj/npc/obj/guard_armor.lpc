//guard专用
#include <armor.h>
inherit ARMOR;

void self_destroy()
{
object env=environment();
if(env) 
        {
        this_object()->unequip();       
        if(env->is_character()) 
                { 
                tell_object(env,"天上忽然传来一声断喝：还我"+this_object()->query("name")+"来！\n");
                tell_object(env,"只见"+this_object()->query("name")+"凌空而去，霎时间不见了踪影。\n");  
                } 
        else    tell_object(env,this_object()->query("name")+"钻进地里，霎时间不见了踪影。\n");
        }
destruct(this_object());
}

void create()
{
set_name("护法铠甲", ({ "hufa armor", "armor" }) );
set_weight(70000);
if( clonep() )
        set_default_object(__FILE__);
else    {
        set("unit", "件");
        set("material", "steel");
        set("value", 9000);
        set("armor_prop/armor", 70);
        set("armor_prop/dodge", -30);
        }
setup();
}

void init()
{
if ( !environment()
  || userp(environment()) )
        {
        remove_call_out("self_destroy");
        call_out("self_destroy",2+random(3));
        }
}                       
