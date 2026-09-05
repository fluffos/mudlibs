// female2-cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name("女式短衫", ({ "cloth" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		            set("long", "一件轻盈漂动的白绸轻衫。\n");
                set("material", "cloth");
                set("value", 500);
                set("armor_prop/armor", 30);
             		set("female_only", 1);
        }
        setup();
}

void init_cloth(object ob)
{
	mapping cloth_type=
	(["绸衫":
		(["深色": 
			([MAG"丝绸短襦"NOR:({"chou ru", "一件女式的紫红色齐腰绣花对襟襦衫。\n" }),
				HIR"旗袍"NOR:({"qi pao", "一件女式的无袖深红色旗袍。\n"}),
				RED"轻罗纱"NOR:({"luo sha", "一件女式的红色轻罗纱。\n"})]),
		  "浅色":
			([GRN"丝绸短襦"NOR:({"chou ru", "一件女式的湖绿色齐腰绣花对襟襦衫。\n" }),
				HIY"旗袍"NOR:({"qi pao", "一件女式的无袖米黄色旗袍。\n"}),
				HIG"轻罗纱"NOR:({"luo sha", "一件女式的浅绿色轻罗纱。\n"})])]),
	  "布衣":
		(["深色": 
			([MAG"圆领衫"NOR:({"yuanling shan", "一件女式的紫红色棉织圆领布衫。\n" }),
				HIR"百褶裙"NOR:({"baizhe qun", "一件女式的深红色绣花百褶裙。\n"}),
				RED"坎肩"NOR:({"kan jian", "一件女式的红色棉织坎肩。\n"})]),
		  "浅色":
			([GRN"圆领衫"NOR:({"yuanling shan", "一件女式的湖绿色棉织圆领布衫。\n" }),
				HIY"百褶裙"NOR:({"baizhe qun", "一件女式的米黄色绣花百褶裙。\n"}),
				HIG"坎肩"NOR:({"kan jian", "一件女式的浅绿色棉织坎肩。\n"})])]),
	  "棉袄":
		(["深色": 
			([MAG"比甲"NOR:({"bi jia", "一件女式的紫红色棉比甲。\n" }),
				HIR"短袄"NOR:({"duan ao", "一件女式的深红色齐腰短棉袄。\n"}),
				RED"长袄"NOR:({"chang ao", "一件女式的红色齐膝长棉袄。\n"})]),
		  "浅色":
			([GRN"比甲"NOR:({"bi jia", "一件女式的湖绿色棉比甲。\n" }),
				HIY"短袄"NOR:({"duan ao", "一件女式的米黄色齐腰短棉袄。\n"}),
				HIG"长袄"NOR:({"chang ao", "一件女式的浅绿色齐膝长棉袄。\n"})])])]);
	mapping subcloth;
	string *cloth,ccloth;
	
	subcloth=cloth_type[ob->query("special/cloth_type")][ob->query("special/cloth_color")];
	cloth=keys(subcloth);
	ccloth=cloth[random(sizeof(cloth))];
	set_name(ccloth, ({subcloth[ccloth][0], "cloth"}));
	set("long", subcloth[ccloth][1]);
}