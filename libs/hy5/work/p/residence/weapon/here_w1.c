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
	set_name("[1;33m芒月[2;37;0m", ({ "qiankun sword", "sword" }));
	set_weight(4278);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[1;33m此物左右两边分别以黑白两种奇铁溶铸而成，一黑一白，切合乾坤，包含阴阳之气，好一柄宝物！
[2;37;0m这是一把由无比坚硬的[37m玄铁[2;37;0m制成，重八斤五两五钱的[1;33m乾坤之剑[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比锋利，具有[31m无与伦比[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;34m举世[2;37;0m [32m水[2;37;0m:[1;36m完美[2;37;0m [31m火[2;37;0m:[1;32m魔王[2;37;0m [1;35m风[2;37;0m:[1;33m天圣[2;37;0m 
[1;37m雷[2;37;0m:[1;32m魔王[2;37;0m 
上面还刻了一些符字：
锋利:[1;31m毁天[2;37;0m 巧制:[31m精致[2;37;0m 
周天:[34m细碎[2;37;0m 长生:[35m标准[2;37;0m 不老:[1;36m完美[2;37;0m 威力:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m两果[2;37;0m 】。和一些【 [1;32m棍法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "here");
		set("ownername", "两果");
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",32);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",48);
		set("weapon_prop/dexerity",48);
		set("weapon_prop/constitution",56);
    set("weapon_prop/dodge", 56);
    set("weapon_prop/parry", 40);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 66);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 56);
    set("weapon_prop/qi", 59);
    set("weapon_prop/jing", 71);
    set("weapon_prop/jingli", 71);
    set("weapon_prop/damage", 35);

    set("wtypeA",8);
    set("wtypeB",0);
    set("wtypeC",7);
    set("wtypeD",9);
    set("wtypeE",6);
    set("wtypeF",10);
    set("wtypeG",9);
    set("wtypeH",6);
    set("wtypeI",6);
    set("wtypeJ",6);
    set("wtypeK",7);
    set("wtypeL",7);
    

                set("skill", ([
                        "name": "club",
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
	
	init_sword(1064);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";