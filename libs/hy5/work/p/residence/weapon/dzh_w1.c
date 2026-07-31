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
	set_name("[33m瑶池之剑[2;37;0m", ({ "yaochi sword", "sword" }));
	set_weight(2466);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[33m瑶池之剑[2;37;0m这是一把由绝对坚硬的[1;33m金铁[2;37;0m制成，重四斤九两三钱的[33m瑶池之剑[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来绝对锋利，具有[1;34m倚天屠龙[2;37;0m的威力！
上面刻了几个古符号：
[32m水[2;37;0m:[33m很高[2;37;0m [33m土[2;37;0m:[1;31m无双[2;37;0m [1;35m风[2;37;0m:[35m标准[2;37;0m 
[1;37m雷[2;37;0m:[1;31m无双[2;37;0m 
上面还刻了一些符字：
锋利:[1;31m无双[2;37;0m 天灵:[36m不错[2;37;0m 福源:[36m不错[2;37;0m 
绝代:[34m细碎[2;37;0m 体灵:[35m标准[2;37;0m 
以及一排古篆字【 [1;32m段子痕[2;37;0m 】。和一些【 [1;32m锤法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "dzh");
		set("ownername", "段子痕");
		set("value", 16000);
		set("weapon_prop/intelligence",16);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",16);
		set("weapon_prop/percao",23);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 51);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",4);
    set("wtypeD",0);
    set("wtypeE",12);
    set("wtypeF",5);
    set("wtypeG",12);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "hammer",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 12);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(778);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";