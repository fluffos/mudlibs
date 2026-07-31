// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit STAFF;

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
	set_name("[1;33m芍药之杖[2;37;0m", ({ "general staff", "staff" }));
	set_weight(2691);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", @LONG
芍药之杖[2;37;0m这是一根由无比坚硬的[33m生铁[2;37;0m制成，重五斤三两八钱的[1;33m芍药之杖[2;37;0m。
综合评价[31m完美精致[2;37;0m 看起来无比锋利，具有[33m很高[2;37;0m的威力！
上面刻了几个古符号：
[37m天[2;37;0m:[34m细碎[2;37;0m [1;31m魔[2;37;0m:[34m细碎[2;37;0m 
上面还刻了一些符字：
锋利:[31m精致[2;37;0m 福源:[33m一般[2;37;0m 
天玄:[33m一般[2;37;0m 体灵:[33m一般[2;37;0m 闪电:[34m细碎[2;37;0m 
长生:[32m极差[2;37;0m 威力:[36m不错[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 2000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",8);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",10);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 20);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 8);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 4);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 16);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",2);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",2);
    

                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 6);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_staff(287);
	setup();
}



#include "/obj/ritem/weaponzy.h";