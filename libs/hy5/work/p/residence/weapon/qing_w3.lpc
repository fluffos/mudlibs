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
	set_name("[1;33m杏花飞[2;37;0m", ({ "fengyun sword", "sword" }));
	set_weight(6718);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[1;35m所谓风云际会，天地变色！仗此行千里，老魔小丑，岂堪一击！
[2;37;0m这是一把由无比坚硬的[37m玄铁[2;37;0m制成，重十三斤四两三钱的[1;35m风云之剑[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比锋利，具有[1;36m斩妖伏魔[2;37;0m的威力！
上面刻了几个古符号：
[1;36m人[2;37;0m:[1;31m创世[2;37;0m [1;31m魔[2;37;0m:[1;31m开元[2;37;0m [1;33m金[2;37;0m:[1;35m绝世[2;37;0m [36m木[2;37;0m:[1;32m魔王[2;37;0m [31m火[2;37;0m:[1;31m创世[2;37;0m [1;37m雷[2;37;0m:[1;32m魔王[2;37;0m 
上面还刻了一些符字：
锋利:[1;31m毁天[2;37;0m 闪电:[31m精致[2;37;0m 
周天:[32m粗糙[2;37;0m 长生:[31m精致[2;37;0m 不老:[32m粗糙[2;37;0m 威力:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m香里小[2;37;0m 】。和一些【 [1;32m拳法[2;37;0m 】的技巧。

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
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 62);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 39);
    set("weapon_prop/qi", 66);
    set("weapon_prop/jing", 31);
    set("weapon_prop/jingli", 31);
    set("weapon_prop/damage", 34);

    set("wtypeA",11);
    set("wtypeB",9);
    set("wtypeC",0);
    set("wtypeD",14);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",9);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",14);
    set("wtypeL",13);
    

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
    set("sharpness", 18);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(934);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";