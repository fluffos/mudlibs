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
	set_name("[1;31m海洋之兵[2;37;0m", ({ "chungou sword", "sword" }));
	set_weight(16591);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[31m纯钩将帅之兵，持之能挥军百万，克敌制胜！
[2;37;0m这是一把由无比坚硬的[1;36m万年寒冰铁[2;37;0m制成，重三十三斤一两八钱的[31m纯钩之剑[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比锋利，具有[1;36m斩妖伏魔[2;37;0m的威力！
上面刻了几个古符号：
[37m天[2;37;0m:[1;35m绝世[2;37;0m [1;31m魔[2;37;0m:[1;31m开元[2;37;0m [1;33m金[2;37;0m:[1;34m举世[2;37;0m [32m水[2;37;0m:[1;33m天圣[2;37;0m [33m土[2;37;0m:[1;33m天圣[2;37;0m [1;34m电[2;37;0m:[1;31m无双[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 天渊:[32m粗糙[2;37;0m 巧制:[1;34m举世[2;37;0m 
体灵:[1;34m举世[2;37;0m 白石:[35m标准[2;37;0m 紫石:[32m粗糙[2;37;0m 不老:[1;36m完美[2;37;0m 
以及一排古篆字【 [1;32m渡渡[2;37;0m 】。和一些【 [1;32m内功[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "imemy");
		set("ownername", "渡渡");
		set("value", 36000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",40);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",48);
		set("weapon_prop/dexerity",39);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 58);
    set("weapon_prop/parry", 36);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 89);
    set("weapon_prop/defense", 82);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 77);
    set("weapon_prop/jingli", 77);
    set("weapon_prop/damage", 0);

    set("wtypeA",8);
    set("wtypeB",6);
    set("wtypeC",10);
    set("wtypeD",6);
    set("wtypeE",10);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",12);
    set("wtypeI",11);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",13);
    

                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 26);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(711);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";