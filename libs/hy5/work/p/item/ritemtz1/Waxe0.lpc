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
	set_name("[31m巨阙之斧[2;37;0m★", ({ "juque axe", "axe" }));
	set_weight(1748);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", @LONG
[31m巨阙坚硬无比，能开天辟地，荡妖除魔！
[2;37;0m这是一柄由无比坚硬的[1;37m软银[2;37;0m制成，重三斤四两九钱的[31m巨阙之斧[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比锋利，具有[1;34m倚天屠龙[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;31m毁天[2;37;0m [33m土[2;37;0m:[1;31m开元[2;37;0m [40m地[2;37;0m:[1;31m毁天[2;37;0m [1;31m魔[2;37;0m:[1;31m毁天[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 天玄:[33m很高[2;37;0m 巧制:[32m粗糙[2;37;0m 
紫石:[35m标准[2;37;0m 闪电:[1;34m举世[2;37;0m 
周天:[1;36m完美[2;37;0m 不老:[33m很高[2;37;0m 

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
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",47);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 58);
    set("weapon_prop/attack", 82);
    set("weapon_prop/armor", 37);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 71);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 41);
    set("weapon_prop/jingli", 41);
    set("weapon_prop/damage", 0);

    set("wtypeA",15);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",13);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",15);
    set("wtypeK",0);
    set("wtypeL",15);
    

                set("skill", ([
                        "name": "blade",
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
	
	init_axe(756);
	setup();
}



#include "/obj/ritem/weaponzy.h";