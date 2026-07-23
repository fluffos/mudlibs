#include <ansi.h>
#include <weapon.h>
inherit CLUB;
inherit F_UNIQUE;

void create()
{
 set_name("斑竹棍", ({ "banzhu gun", "gun", "banzhu","club" }));
        set_weight(4000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", GRN "\n这是根用南海斑竹制成的长棍，入手极为轻盈。棍两端竹干分枝，竹尖锐利如针。\n"NOR);
                set("value", 1);
                set("unique", 3);
                set("material", "bamboo");
		set("sharpness", 2);
                set("weapon_prop/parry", 2);
                set("weapon_prop/dodge", 5);
                set("wield_msg", "$N双手一晃，将$n抽出抖得笔直。\n"NOR);
                set("unwield_msg", "$N右手一抚，将$n别回背后。\n"NOR);
        }
        init_club(60);
        setup();
}
