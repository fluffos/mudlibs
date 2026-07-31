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
	set_name("[31m太阿之刀[2;37;0m", ({ "taie blade", "blade" }));
	set_weight(3474);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", @LONG
[31m太阿帝王之兵，持之能号令天下，莫有不从！
[2;37;0m这是一柄由无比坚硬的[1;37m软银[2;37;0m制成，重六斤九两四钱的[31m太阿之刀[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比锋利，具有[1;31m天下无双[2;37;0m的威力！
上面刻了几个古符号：
[31m火[2;37;0m:[1;31m毁天[2;37;0m [33m土[2;37;0m:[31m精致[2;37;0m [1;34m电[2;37;0m:[1;31m毁天[2;37;0m [37m天[2;37;0m:[1;33m天圣[2;37;0m [1;36m人[2;37;0m:[31m精致[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 天宇:[33m很高[2;37;0m 巧制:[1;32m魔王[2;37;0m 
长生:[35m标准[2;37;0m 

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
		set("weapon_prop/strength",46);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 90);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 50);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",15);
    set("wtypeE",6);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",15);
    set("wtypeI",10);
    set("wtypeJ",0);
    set("wtypeK",6);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "staff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 27);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_blade(1058);
	setup();
}



#include "/obj/ritem/weaponzy.h";