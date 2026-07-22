//writed by xingyun
#include <ansi.h>
#include <armor.h>
inherit ARMOR;
inherit F_UNIQUE1;
void create()
{
        set_name(HIB"乌蚕衣"NOR, ({ "wucan yi", "yi" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
HIB"这是一件轻柔的乌蚕衣，乃取自大雪山乌蚕丝所制，质地极为坚韧。\n");
                set("material", "cloth");
                set("unit", "件");
                set("unique", 1);
                set("no_steal", 1);
                set("no_drop",1);
                set("no_get",1);
                set("no_put", 1);
                set("replica_ob","/clone/misc/cloth");
                set("value", 700000);  
                set("wear_msg",HIB"$N将乌蚕衣贴身穿在体内，周身顿感一阵温暖。\n"NOR);
                set("unequip_msg", HIY"$N将乌蚕衣从身上脱了下来，叠了起来。\n"NOR);
                set("armor_prop/armor", 400);
        }
        setup();
}

