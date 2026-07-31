// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit AXE;

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
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

void create()
{
	set_name("[1;31m炼狱之斧[2;37;0m★", ({ "lianyu axe", "axe" }));
	set_weight(13804);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", @LONG
[1;31m三十三天下有地，地下有城，城名鬼城，大小妖魔，人神畜生都在此轮回往返，谓之“炼狱”！
[2;37;0m这是一柄由绝对坚硬的[31m流花石[2;37;0m制成，重二十七斤六两零钱的[1;31m炼狱之斧[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来绝对锋利，具有[1;31m天下无双[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;31m无双[2;37;0m [36m木[2;37;0m:[31m精致[2;37;0m [32m水[2;37;0m:[1;31m开元[2;37;0m [33m土[2;37;0m:[1;36m完美[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 绝代:[32m粗糙[2;37;0m 天渊:[34m细碎[2;37;0m 紫石:[31m精致[2;37;0m 不老:[32m粗糙[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",32);
		set("weapon_prop/dexerity",26);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 64);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 31);
    set("weapon_prop/jingli", 31);
    set("weapon_prop/damage", 0);

    set("wtypeA",12);
    set("wtypeB",6);
    set("wtypeC",13);
    set("wtypeD",0);
    set("wtypeE",7);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "cuff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 17);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_axe(1125);
	setup();
}



#include "/obj/ritem/weaponzy.h";