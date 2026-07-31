// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit HAMMER;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

void create()
{
	set_name("[1;31m朱雀之锤[2;37;0m", ({ "zhuque hammer", "hammer" }));
	set_weight(7618);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", @LONG
[1;31m朱雀之锤[2;37;0m这是一柄由相当坚硬的[1;32m绿石[2;37;0m制成，重十五斤二两三钱的[1;31m朱雀之锤[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来相当锋利，具有[1;32m开天劈地[2;37;0m的威力！
上面刻了几个古符号：
[1;34m电[2;37;0m:[1;33m天圣[2;37;0m [37m天[2;37;0m:[1;32m魔王[2;37;0m 
上面还刻了一些符字：
锋利:[1;31m无双[2;37;0m 天宇:[36m不错[2;37;0m 周天:[34m细碎[2;37;0m 

LONG
);
	
		set("value", 16000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",19);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    set("no_put",1);
    set("no_give",1);
    set("no_pawn",1);
    set("weapon_prop/neili", 24);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",3);
    set("wtypeI",3);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "claw",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 12);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_hammer(787);
	setup();
}



#include "/obj/ritem/weaponzy.h";