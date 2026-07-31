// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit BLADE;

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
	set_name("[31m工布之刀[2;37;0m", ({ "gongbu blade", "blade" }));
	set_weight(4716);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", @LONG
[31m工布天生怪异，功能参商！
[2;37;0m这是一柄由无比坚硬的[1;37m软银[2;37;0m制成，重九斤四两三钱的[31m工布之刀[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比锋利，具有[1;33m举世无匹[2;37;0m的威力！
上面刻了几个古符号：
[32m水[2;37;0m:[1;33m灭世[2;37;0m [1;37m雷[2;37;0m:[31m精致[2;37;0m [1;34m电[2;37;0m:[1;31m开元[2;37;0m [40m地[2;37;0m:[1;31m毁天[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 天灵:[33m很高[2;37;0m 天宇:[33m很高[2;37;0m 绝代:[33m很高[2;37;0m 天渊:[32m粗糙[2;37;0m 周天:[1;32m魔王[2;37;0m 不老:[35m标准[2;37;0m 威力:[35m标准[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 36000);
		set("weapon_prop/intelligence",46);
		set("weapon_prop/strength",45);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",45);
		set("weapon_prop/dexerity",36);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 91);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 58);
    set("weapon_prop/jingli", 58);
    set("weapon_prop/damage", 53);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",16);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",6);
    set("wtypeH",13);
    set("wtypeI",0);
    set("wtypeJ",15);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 19);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_blade(832);
	setup();
}



#include "/obj/ritem/weaponzy.h";