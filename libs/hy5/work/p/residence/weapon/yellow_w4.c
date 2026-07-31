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
	set_name("[1;37m长生剑[2;37;0m", ({ "fengyun sword", "sword" }));
	set_weight(15892);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[1;35m所谓风云际会，天地变色！仗此行千里，老魔小丑，岂堪一击！
[2;37;0m这是一把由无比坚硬的[37m玄铁[2;37;0m制成，重三十一斤七两八钱的[1;35m风云之剑[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比锋利，具有[1;31m开元创世[2;37;0m的威力！
上面刻了几个古符号：
[1;31m魔[2;37;0m:[1;31m开元[2;37;0m [31m火[2;37;0m:[1;31m创世[2;37;0m [1;35m风[2;37;0m:[1;35m绝世[2;37;0m 
[1;37m雷[2;37;0m:[31m精致[2;37;0m [1;34m电[2;37;0m:[1;36m完美[2;37;0m 
上面还刻了一些符字：
锋利:[1;31m毁天[2;37;0m 天宇:[34m细碎[2;37;0m 福源:[32m粗糙[2;37;0m 
天玄:[34m细碎[2;37;0m 体灵:[32m粗糙[2;37;0m 长生:[33m很高[2;37;0m 
以及一排古篆字【 [1;32m段药师[2;37;0m 】。和一些【 [1;32m斧法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "yellow");
		set("ownername", "段药师");
		set("value", 25000);
		set("weapon_prop/intelligence",56);
		set("weapon_prop/strength",56);
		set("weapon_prop/karey",56);
		set("weapon_prop/percao",56);
		set("weapon_prop/dexerity",48);
		set("weapon_prop/constitution",40);
    set("weapon_prop/dodge", 24);
    set("weapon_prop/parry", 56);
    set("weapon_prop/attack", 56);
    set("weapon_prop/armor", 56);
    set("weapon_prop/defense", 56);
    
    set("weapon_prop/neili", 56);
    set("weapon_prop/qi", 56);
    set("weapon_prop/jing", 56);
    set("weapon_prop/jingli", 56);
    set("weapon_prop/damage", 48);

    set("wtypeA",5);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",14);
    set("wtypeE",0);
    set("wtypeF",11);
    set("wtypeG",6);
    set("wtypeH",7);
    set("wtypeI",6);
    set("wtypeJ",0);
    set("wtypeK",6);
    set("wtypeL",13);
    

                set("skill", ([
                        "name": "axe",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 15);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(3810);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";