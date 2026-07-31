// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit DAGGER;

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
	set_name("[37m绿玉之匕首[2;37;0m", ({ "luyu dagger", "dagger" }));
	set_weight(10315);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[37m绿玉之匕首[2;37;0m这是一把由无比坚硬的[1;37m软银[2;37;0m制成，重二十斤六两三钱的[37m绿玉之匕首[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来无比锋利，具有[1;36m斩妖伏魔[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[35m标准[2;37;0m [32m水[2;37;0m:[31m精致[2;37;0m [31m火[2;37;0m:[35m标准[2;37;0m [33m土[2;37;0m:[1;31m无双[2;37;0m 
上面还刻了一些符字：
锋利:[1;31m开元[2;37;0m 天宇:[34m细碎[2;37;0m 紫石:[33m很高[2;37;0m 闪电:[32m粗糙[2;37;0m 
周天:[34m细碎[2;37;0m 
以及一排古篆字【 [1;32m小马[2;37;0m 】。和一些【 [1;32m手法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "xiaoma");
		set("ownername", "小马");
		set("value", 16000);
		set("weapon_prop/intelligence",48);
		set("weapon_prop/strength",48);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",48);
		set("weapon_prop/constitution",40);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 47);
    set("weapon_prop/attack", 39);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 23);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",5);
    set("wtypeB",0);
    set("wtypeC",6);
    set("wtypeD",5);
    set("wtypeE",12);
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
                        "max_skill": 320,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 13);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_dagger(676);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";