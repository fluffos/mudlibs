// jinbi.c 新春金币

#include <ansi.h>

inherit MONEY;

void create()
{
	set_name(HIY+"生日纪念金币"+ NOR, ({ "jin bi","gold","bi","gold_money" }));
	set("long",HIY"这是北大侠客行专为庆祝玩家生日发行的纪念金币，只有女玩家才能获得。上面印着一只活泼可爱的Hello Kitty，\n还有"HIR"生日快乐"HIY"的字样，下面刻着"HIR"北侠巫师恭祝MM生日快乐！"NOR"\n");
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("base_value", 10000000 );
                set("base_unit", "枚");
                set("base_weight", 1);
                set("unit", "些");
                set("money_id", "gold");
	}
        set_amount(1);
}	

