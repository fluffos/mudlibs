// female-shoe.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
	set_name(HIM"绣花小鞋"NOR, ({ "flower shoes", "shoes"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "双");
		set("long", "一双女人穿的缝制得很精美的绣花鞋。\n");
		set("value", 500);
		set("armor_prop/armor", 30 );
		set("female_only", 1);
	}
	setup();
}

void init_boots(object ob)
{
	mapping boots_type=
	(["凉鞋":
		(["深色": 
			([MAG"木屐"NOR:({"mu ji", "一双女式的染着紫红色的木屐。\n" }),
				HIM"草鞋"NOR:({"cao xie", "一双深棕色的草鞋。\n"}),
				HIB"破鞋"NOR:({"po xie", "一只破鞋，鞋底还没了，鞋帮子也烂的不成样子！。\n"})]),
		  "浅色":
			([GRN"木屐"NOR:({"mu xie", "一双女式的染着湖绿色的木屐。\n" }),
				YEL"草鞋"NOR:({"cao xie", "一双土黄色的草鞋。\n"}),
				WHT"破鞋"NOR:({"po xie", "一只破鞋，鞋底还没了，鞋帮子也烂的不成样子！。\n"})])]),
	  "布鞋":
		(["深色": 
			([MAG"锦鞋"NOR:({"jin xie", "一双女式的紫红色丝织锦鞋。\n" }),
				HIR"绣花鞋"NOR:({"xiuhua xie", "一双女式的深红色绣花布鞋。\n"}),
				RED"凤鞋"NOR:({"feng xie", "一双女式的红色绣着凤凰图案的布鞋。\n"})]),
		  "浅色":
			([GRN"锦鞋"NOR:({"jin xie", "一双女式的湖绿色丝织锦鞋。\n" }),
				HIY"绣花鞋"NOR:({"xiuhua xie", "一双女式的米黄色绣花布鞋。\n"}),
				CYN"凤鞋"NOR:({"feng xie", "一双女式的青色绣着凤凰图案的布鞋。\n"})])]),
	  "靴子":
		(["深色": 
			([MAG"女式短靴"NOR:({"duan xue", "一双女式的紫红色牛皮短靴。\n" }),
				HIR"女式长靴"NOR:({"chang xue", "一双女式的深红色牛皮长靴。\n"}),
				HIM"薄底快靴"NOR:({"baodi kuaixue", "一双女式的红色布制快靴。\n"})]),
		  "浅色":
			([GRN"女式短靴"NOR:({"duan xue", "一双女式的湖绿色牛皮短靴。\n" }),
				HIY"女式长靴"NOR:({"chang xue", "一双女式的米黄色牛皮长靴。\n"}),
				CYN"薄底快靴"NOR:({"baodi kuaixue", "一双女式的青色布制快靴。\n"})])])]);
	mapping suboots;
	string *boots,cboots;
	
	suboots=boots_type[ob->query("special/boots_type")][ob->query("special/boots_color")];
	boots=keys(suboots);
	cboots=boots[random(sizeof(boots))];
	set_name(cboots, ({suboots[cboots][0],"shoes"}));
	set("long", suboots[cboots][1]);
}