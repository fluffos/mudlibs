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
	set_name("[37m生死之剑[2;37;0m", ({ "shengsi sword", "sword" }));
	set_weight(3764);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[37m生死之剑[2;37;0m这是一把由无比坚硬的[1;37m软银[2;37;0m制成，重七斤五两二钱的[37m生死之剑[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来无比锋利，具有[1;35m绝世罕见[2;37;0m的威力！
上面刻了几个古符号：
[1;36m人[2;37;0m:[31m精致[2;37;0m [36m木[2;37;0m:[1;35m绝世[2;37;0m [32m水[2;37;0m:[1;36m完美[2;37;0m [31m火[2;37;0m:[33m很高[2;37;0m [33m土[2;37;0m:[1;33m天圣[2;37;0m [1;37m雷[2;37;0m:[1;33m天圣[2;37;0m 
上面还刻了一些符字：
锋利:[1;31m无双[2;37;0m 体灵:[32m粗糙[2;37;0m 白石:[36m不错[2;37;0m 紫石:[36m不错[2;37;0m 闪电:[33m很高[2;37;0m 
长生:[35m标准[2;37;0m 
以及一排古篆字【 [1;32m科比[2;37;0m 】。和一些【 [1;32m拳法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "kobe");
		set("ownername", "科比");
		set("value", 16000);
		set("weapon_prop/intelligence",32);
		set("weapon_prop/strength",40);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",40);
		set("weapon_prop/constitution",40);
    set("weapon_prop/dodge", 17);
    set("weapon_prop/parry", 17);
    set("weapon_prop/attack", 42);
    set("weapon_prop/armor", 32);
    set("weapon_prop/defense", 35);
    
    set("weapon_prop/neili", 24);
    set("weapon_prop/qi", 54);
    set("weapon_prop/jing", 32);
    set("weapon_prop/jingli", 24);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",11);
    set("wtypeC",7);
    set("wtypeD",4);
    set("wtypeE",10);
    set("wtypeF",0);
    set("wtypeG",10);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",3);
    set("wtypeK",6);
    set("wtypeL",4);
    

                set("skill", ([
                        "name": "cuff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 15);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(1322);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";