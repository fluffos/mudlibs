// male5-cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIM"紫蟒袍"NOR, ({ "cloth" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		            set("long", "一件很重的紫蟒袍。\n");
                set("material", "cloth");
		            set("value", 500);
                set("armor_prop/armor", 30);
        }
        setup();
}

void init_cloth(object ob)
{
	mapping cloth_type=
	(["绸衫":
		(["深色": 
			([HIB"丝织儒衫"NOR:({"ru shan", "一件天蓝色的丝织儒衫。\n" }),
				HIB"丝织长衫"NOR:({"chang pao", "一件天蓝色的丝织长衫。\n"}),
				HIB"绸袍"NOR:({"chou pao", "一件天蓝色的丝织长袍。\n"})]),
		  "浅色":
			([HIW"丝织儒衫"NOR:({"ru shan", "一件白色的丝织儒衫。\n" }),
				HIW"丝织长衫"NOR:({"chang pao", "一件白色的丝织长衫。\n"}),
				HIW"绸袍"NOR:({"chou pao", "一件白色的丝织长袍。\n"})])]),
	  "布衣":
		(["深色": 
			([HIB"短打劲装"NOR:({"jin zhuang", "一件习武人士喜欢穿的短打劲装。\n" }),
				HIB"蓝马褂"NOR:({"ma gua", "一件蓝色的马褂。\n"}),
				HIB"天蓝锦袍"NOR:({"jing pao", "一件蓝色底纹的织锦长袍。\n"})]),
		  "浅色":
			([WHT"短打劲装"NOR:({"jin zhuang", "一件习武人士喜欢穿的短打劲装。\n" }),
				WHT"灰马褂"NOR:({"ma gua", "一件灰色的马褂。\n"}),
				WHT"灰布衫"NOR:({"bu shan", "一件普通的布衫。\n"})])]),
	  "棉袄":
		(["深色": 
			([HIB"狼皮袄"NOR:({"pi ao", "一件狼皮制的皮袄。\n" }),
				HIB"鹤氅"NOR:({"he chang", "一件狐狸皮制成的鹤氅。\n"}),
				HIB"棉袄"NOR:({"mian ao", "一件普通的棉袄。\n"})]),
		  "浅色":
			([WHT"狼皮袄"NOR:({"pi ao", "一件狼皮制的皮袄。\n" }),
				WHT"鹤氅"NOR:({"he chang", "一件狐狸皮制成的鹤氅。\n"}),
				WHT"棉袄"NOR:({"mian ao", "一件普通的棉袄。\n"})])])]);
	mapping subcloth;
	string *cloth,ccloth;
	
	subcloth=cloth_type[ob->query("special/cloth_type")][ob->query("special/cloth_color")];
	cloth=keys(subcloth);
	ccloth=cloth[random(sizeof(cloth))];
	set_name(ccloth, ({subcloth[ccloth][0], "cloth"}));
	set("long", subcloth[ccloth][1]);
}