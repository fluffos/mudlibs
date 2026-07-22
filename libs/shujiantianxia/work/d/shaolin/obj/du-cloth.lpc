// xuan-cloth.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIM "锦" HIY "斓" HIG "袈裟" NOR, ({ "jia sha", "cloth" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "千般巧妙明珠坠，万样稀奇佛宝攒\n
上下龙须铺彩绮，兜罗四面锦沿边\n
体挂魍魉从此灭，身披魑魅入黄泉\n
托化天仙亲手制，不是真僧不敢穿\n");
                set("unit", "件");
                set("material", "silk");
                set("armor_prop/armor", 40);
                set("wear_msg","$N拿出一件$n披在身上。\n");
                set("remove_msg","$N把$n从身上脱了下来。\n");
        }
        setup();
}
