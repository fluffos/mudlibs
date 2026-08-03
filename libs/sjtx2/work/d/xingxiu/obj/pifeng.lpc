// pifeng.c
// caiji@SJ 8/27/2000 根据锦虎披风修改，如感觉雷同的话，请帮忙CUT。 
#include <ansi.h> 
#include <armor.h> 
 
inherit SURCOAT;
 
void create() 
{
	object me=this_object(); 
        set_name( HIB "魑魅披风" NOR, ({ "chimei pifeng", "pifeng" }) ); 
        set_weight(300); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "件"); 
                set("long", "这是一件传说可以散发鬼气，使人产生幻影的披风。\n"); 
                set("value", 300);
                set("material", "cloth"); 
                set("wield_msg", "$N“哗”地展开"+me->name()+"披在身上，披风在身后随风飘扬。\n");
                set("unwield_msg"," $N将"+me->name()+"解下来叠好塞在了怀里。\n");
                set("armor_prop/armor", 4); 
                set("armor_prop/dodge", 1); 
              } 
        setup(); 
} 
