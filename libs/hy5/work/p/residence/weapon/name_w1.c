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
	set_name("[1;33m冰释之剑[2;37;0m", ({ "good sword", "sword" }));
	set_weight(6582);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
冰释之剑[2;37;0m这是一把由无比坚硬的[31m流花石[2;37;0m制成，重十三斤一两六钱的[1;33m冰释之剑[2;37;0m。
综合评价[1;34m举世罕见[2;37;0m 看起来无比锋利，具有[1;34m倚天屠龙[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[32m粗糙[2;37;0m [36m木[2;37;0m:[1;36m完美[2;37;0m [32m水[2;37;0m:[1;36m完美[2;37;0m [31m火[2;37;0m:[32m粗糙[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m天圣[2;37;0m 白石:[32m粗糙[2;37;0m 紫石:[32m粗糙[2;37;0m 闪电:[34m细碎[2;37;0m 
周天:[36m不错[2;37;0m 
以及一排古篆字【 [1;32m小璇风[2;37;0m 】。和一些【 [1;32m手法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "name");
		set("ownername", "小璇风");
		set("value", 9000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 36);
    set("weapon_prop/parry", 30);
    set("weapon_prop/attack", 27);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 17);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 40);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",3);
    set("wtypeB",7);
    set("wtypeC",7);
    set("wtypeD",3);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "hand",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 10);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(771);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";