// /d/gift/becool/longlin.c by becool 2008-11
#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
        int bonus = random(100)+1;
        set_name(HIY"龙 心"NOR, ({ "long xin", "xin"}) );
        set_weight(20);
        set("unique", 1);
        set("unit", "条");
        set("long", "一条沉甸甸的项链，坠子呈心形，像是纯金打造而成。\n吊坠的背面有几个蝇头小字：虫心第"+bonus+"号，莫名其妙。\n");
        set("value", 100000);
        set("armor_type","neck");
        set("material", "gold");
        set("wear_msg","$N把"HIY"龙 心"NOR"套在脖子上，四处炫耀，活像个暴发户。\n");
        set("remove_msg","$N把"HIY"龙 心"NOR"摘了下来，偷偷藏在怀中。\n");
        set("armor_prop/armor", 100+bonus);
        set("armor_prop/dodge", bonus/2);
        set("armor_prop/force", bonus/2);
        set("armor/magic", bonus);
        set("armor_prop/magic", bonus);
        setup();
}