// jinbi.c 新春金币

#include <ansi.h>

inherit MONEY;

void create()
{
	set_name(HIY+"兔年吉祥金币"+ NOR, ({ "jin bi","gold","bi","gold_money" }));
	set("long",HIY"这是北大侠客行为庆祝2011年春节特别发行的兔年吉祥金币，上面印着一只活泼可爱的小白兔，下面还印着一行小字『悠然特别版』\n
还有"HIR"恭贺新禧"HIY"的字样，下面刻着"HIR"北侠巫师恭祝大家新春快乐，庆贺冰冰喜得闺女！"NOR"\n");
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("base_value", 20000 );
                set("base_unit", "枚");
                set("base_weight", 37);
                set("unit", "些");
                set("money_id", "gold");
	}
        set_amount(random(100)+1);
}	

