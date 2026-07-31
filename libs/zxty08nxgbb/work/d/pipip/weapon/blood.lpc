// 铁血巨剑   by:pipip
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
    set_name(HIR"铁血巨剑"NOR, ({ "blood sword", "sword","blood" }));
    set_weight(50000);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "柄");
        set("long", HIR"千年玄铁所制，重达三百七十斤，据说可开天劈地，乃剑中之雄！\n"NOR);
        set("no_give", 1);
        set("flag",1);
        set("material", "steel");
        set("weapon_prop/strength", 30);
        set("wield_msg", HIR "$N力贯双臂，缓缓地举起一柄巨大的剑器，只见剑身闪出隐隐红光，天地间杀气顿盛。\n" NOR);
        set("unwield_msg", HIR "$N慢慢地将铁血巨剑收回鞘内，剑光顿收，杀意尽数化为无形。\n" NOR);
    }
    init_sword(800,1);
    setup();
}
int move(mixed dest)
{
        if(! userp(dest))       return ::move(dest);
        if( ::move(dest)==0)    return 0;
         message("channel:rumor",HIR"【神剑出世】"+ "江湖谣言四起："+
         dest->query("name")+"巧遇奇迹，成功夺得天下第一剑，铁血巨剑重入江湖！\n"NOR,users());
        return 1;
}

