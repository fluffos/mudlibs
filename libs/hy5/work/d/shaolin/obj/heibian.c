// longsword.c 长鞭
#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
set_name(BLU"黑索"NOR,({ "hei suo", "whip","bian","suo" }) );
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 100);
                set("weapon_prop/dodge", 3);
                set("weapon_prop/parry", 1);
                set("treasure",1);
                set("wield_neili", 200);
                set("wield_maxneili", 800);
                set("wield_str", 20);
		set("material", "leather");
                set("long", BLU"这是条通体黝黑无光的长索，便如一条张牙舞爪的墨龙，夜晚舞动之时瞧不见半点影子。\n"NOR);                
                set("unwield_msg", "$N随手一抖，将$n盘回腰间。\n");
                set("wield_msg", "$N随手一抖，抽出一条$n握在手中。\n");
	}
	init_whip(280);
	setup();
}
