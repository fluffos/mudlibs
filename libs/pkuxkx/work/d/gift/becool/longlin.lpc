// /d/gift/becool/longlin.c by becool 2008-11
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        int bonus = random(100)+1;
        set_name(HIY"龙 鳞"NOR, ({ "long lin", "lin"}) );
        set_weight(100);
        set("unique", 1);
        set("unit", "件");
        set("long", "一件很轻极具质感的的贴身防具，由无数泛着微光的鳞片织成，显然来历不凡。\n右下角不起眼的地方刻有一行小字：虫皮第"+bonus+"号，不知道是什么意思。\n");
        set("value", 100000);
        set("armor_type","cloth");
        set("material", "cloth");
        set("wear_msg","$N脱了个精光，把"HIY"龙 鳞"NOR"贴身穿上，四周隐隐现出一圈光环。\n");
        set("remove_msg","$N找了个没人的角落把"HIY"龙 鳞"NOR"脱了下来，不胜怜惜的看了又看。\n");
        set("armor_prop/armor", 500+bonus);
        set("armor_prop/parry", bonus/2);
        set("armor/magic", bonus);
        set("armor_prop/magic", bonus);
        setup();
}