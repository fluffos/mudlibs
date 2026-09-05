// man-shoe.c
 
#include <armor.h>
#include <ansi.h>
 
inherit BOOTS;
 
void create()
{
	set_name("皮靴", ({ "pi xue", "xue" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "双");
		set("long", "这是一双用上好牛皮作的皮靴。\n");
		set("value", 0);
		set("armor_prop/dodge", 8);
	}
	setup();
}

void init_boots(object ob)
{
	mapping boots_type=
	(["凉鞋":
		(["深色": 
			([BLU"木屐"NOR:({"mu ji", "一双深蓝色的木屐。\n" }),
				HIM"草鞋"NOR:({"cao xie", "一双色的草鞋。\n"}),
				HIB"破鞋"NOR:({"po xie", "一只破鞋，鞋底还没了，鞋帮子也烂的不成样子！。\n"})]),
		  "浅色":
			([WHT"木屐"NOR:({"mu xie", "一双灰色的木屐。\n" }),
				YEL"草鞋"NOR:({"cao xie", "一双土黄色的草鞋。\n"}),
				WHT"破鞋"NOR:({"po xie", "一只破鞋，鞋底还没了，鞋帮子也烂的不成样子！。\n"})])]),
	  "布鞋":
		(["深色": 
			([HIB"千层底布鞋"NOR:({"bu xie", "一双非常结实的蓝色布鞋。\n" }),
				HIB"麻鞋"NOR:({"ma xie", "一双普通的蓝色麻鞋。\n"}),
				HIB"布鞋"NOR:({"bu xie", "一双普通的蓝色布鞋。\n"})]),
		  "浅色":
			([WHT"千层底布鞋"NOR:({"bu xie", "一双非常结实的灰色布鞋。\n" }),
				WHT"麻鞋"NOR:({"ma xie", "一双普通的灰色麻鞋。\n"}),
				WHT"布鞋"NOR:({"bu xie", "一双普通的灰色布鞋。\n"})])]),
	  "靴子":
		(["深色": 
			([HIB"牛皮短靴"NOR:({"duan xue", "一双熟牛皮精制的男式短靴。\n" }),
				HIB"马靴"NOR:({"ma xue", "一双骑马用的男式牛皮长靴。\n"}),
				HIB"七星剑靴"NOR:({"jian xue", "一双练武人士喜欢穿的便捷短靴。\n"})]),
		  "浅色":
			([WHT"牛皮短靴"NOR:({"duan xue", "一双熟牛皮精制的男式短靴。\n" }),
				WHT"马靴"NOR:({"ma xue", "一双骑马用的男式牛皮长靴。\n"}),
				WHT"七星剑靴"NOR:({"jian xue", "一双练武人士喜欢穿的便捷短靴。\n"})])])]);
	mapping suboots;
	string *boots,cboots;
	
	suboots=boots_type[ob->query("special/boots_type")][ob->query("special/boots_color")];
	boots=keys(suboots);
	cboots=boots[random(sizeof(boots))];
	set_name(cboots, ({suboots[cboots][0],"shoes"}));
	set("long", suboots[cboots][1]);
}