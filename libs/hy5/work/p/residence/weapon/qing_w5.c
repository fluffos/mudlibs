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
	set_name("[1;33m杏花飞[2;37;0m", ({ "wuji sword", "sword" }));
	set_weight(11762);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[1;32m此物已达出神入化，登峰造极，神乎其神之境界！俗说万物归宗，便是这“无极”！
[2;37;0m这是一把由无比坚硬的[37m玄铁[2;37;0m制成，重二十三斤五两二钱的[1;32m无极之剑[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比锋利，具有[1;35m绝世罕见[2;37;0m的威力！
上面刻了几个古符号：
[1;31m魔[2;37;0m:[1;34m举世[2;37;0m [1;33m金[2;37;0m:[31m精致[2;37;0m [31m火[2;37;0m:[1;31m创世[2;37;0m [33m土[2;37;0m:[1;33m天圣[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 福源:[34m细碎[2;37;0m 
天玄:[34m细碎[2;37;0m 巧制:[33m很高[2;37;0m 
紫石:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m香里小[2;37;0m 】。和一些【 [1;32m剑法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "qing");
		set("ownername", "香里小");
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",27);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",28);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 36);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 49);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",6);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",14);
    set("wtypeE",10);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",8);
    

                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 16);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(985);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";