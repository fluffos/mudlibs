// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit SWORD;

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
	set_name("[33m风雨雷电[2;37;0m", ({ "wulong sword", "sword" }));
	set_weight(4316);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[35m五龙之剑[2;37;0m这是一把由极其坚硬的[1;37m软银[2;37;0m制成，重八斤六两三钱的[35m五龙之剑[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来极其锋利，具有[31m无与伦比[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;36m完美[2;37;0m [36m木[2;37;0m:[1;36m完美[2;37;0m [33m土[2;37;0m:[31m精致[2;37;0m [1;35m风[2;37;0m:[31m精致[2;37;0m 

上面还刻了一些符字：
锋利:[1;31m开元[2;37;0m 福源:[34m细碎[2;37;0m 
天渊:[34m细碎[2;37;0m 体灵:[33m很高[2;37;0m 白石:[34m细碎[2;37;0m 闪电:[36m不错[2;37;0m 

以及一排古篆字【 [1;32m地图一号[2;37;0m 】。和一些【 [1;32m棍法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "maper");
		set("ownername", "地图一号");
		set("value", 16000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",22);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",27);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 23);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 16);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 43);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",7);
    set("wtypeB",7);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",6);
    set("wtypeF",6);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "club",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 13);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(463);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";