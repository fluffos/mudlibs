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
	set_name("[1;32m浩气之剑[2;37;0m", ({ "haoqi sword", "sword" }));
	set_weight(4685);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[1;32m天地浩气之神兵，扫魔除妖，为国为民，侠之大者！
[2;37;0m这是一把由无比坚硬的[37m玄铁[2;37;0m制成，重九斤三两七钱的[1;32m浩气之剑[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比锋利，具有[1;32m开天劈地[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;31m无双[2;37;0m [36m木[2;37;0m:[1;35m绝世[2;37;0m [1;35m风[2;37;0m:[1;31m开元[2;37;0m 
[1;37m雷[2;37;0m:[1;31m无双[2;37;0m 
上面还刻了一些符字：
锋利:[1;31m毁天[2;37;0m 天灵:[34m细碎[2;37;0m 福源:[34m细碎[2;37;0m 
巧制:[33m很高[2;37;0m 
体灵:[33m很高[2;37;0m 闪电:[1;36m完美[2;37;0m 
不老:[33m很高[2;37;0m 
以及一排古篆字【 [1;32m慕容米[2;37;0m 】。和一些【 [1;32m拳法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "hhhe");
		set("ownername", "慕容米");
		set("value", 25000);
		set("weapon_prop/intelligence",29);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",29);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 74);
    set("weapon_prop/armor", 43);
    set("weapon_prop/defense", 46);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 40);
    set("weapon_prop/jingli", 40);
    set("weapon_prop/damage", 0);

    set("wtypeA",12);
    set("wtypeB",11);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",13);
    set("wtypeG",12);
    set("wtypeH",0);
    set("wtypeI",6);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

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
    set("sharpness", 15);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(790);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";