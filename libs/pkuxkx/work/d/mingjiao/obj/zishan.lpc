// zishan.c 紫色长衫
// By yuer
#include <armor.h>
inherit CLOTH;
void create()
{
    set_name("紫色长衫", ({"shan", "cloth", "chang shan"}) );
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
        set("long", "这是件质地精细的紫色长衫，用上好丝绸制成，薄如蝉翼。\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}
