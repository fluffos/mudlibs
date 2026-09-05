// fangtianji.c 方天画戟

#include <weapon.h>
#include <ansi.h>
inherit HALBERD;

void create()
{
        set_name(HIY "明月寒星戟" NOR, ({ "mingyue ji", "ji" }));
	set_weight(30000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", "此戟为三角形长援，戟刺反卷成钩状，援两面的中部均带有宽血槽，内中有一圆穿，犹如明月，戟身修长，寒铁所铸，尖端缀以宝石，折射日光月光，犹如寒星闪烁，惊人心魂。\n");
                set("value", 80000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声拎起$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_halberd(80);
        setup();
}
