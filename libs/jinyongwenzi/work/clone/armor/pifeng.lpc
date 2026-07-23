// pifeng.c
 
#include <ansi.h> 
#include <armor.h> 
 
inherit NECK; 
 
void create() 
{ 
        set_name( HIR "锦虎披风" NOR, ({ "jinhu pifeng", "pifeng" }) ); 
        set_weight(300); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "件"); 
                set("long", "这是一件猩红色的披风，上面用金线绣了一头斑斓猛虎，银线走边，非常华丽。\n"); 
                set("value", 300); 
                set("material", "cloth"); 
                set("wield_msg", "$N“哗”地展开锦虎披风披在身上，披风在身后随风飘扬，平添了几分威风。\n");
                set("unwield_msg"," $N锦虎披风解下来叠好塞在了怀里。\n");
                set("armor_prop/armor", 10); 
                set("armor_prop/dodge", 2); 
              } 
        setup(); 
} 
