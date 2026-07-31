#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIW "白衣" NOR, ({ "bai yi", "cloth","yi","baiyi" }) );
        set_weight(3500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件犹如轻纱般的雪白色长衫。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 35);
                set("wear_msg","$N轻轻披上一件轻纱般的$n，犹似身在烟中雾里。\n");
                set("remove_msg","$N把$n从身上脱了下来。\n");
        }
        setup();
}
