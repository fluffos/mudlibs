// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit CLUB;

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
	set_name("[1;32m千钧棒[2;37;0m", ({ "general club", "club" }));
	set_weight(5265);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", @LONG
紫陽之棍[2;37;0m这是一根由无比坚硬的[33m软铁[2;37;0m制成，重十斤五两三钱的[1;32m紫陽之棍[2;37;0m。
综合评价[31m完美精致[2;37;0m 看起来无比锋利，具有[32m水准以上[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;36m完美[2;37;0m [36m木[2;37;0m:[1;36m完美[2;37;0m [32m水[2;37;0m:[34m细碎[2;37;0m [1;35m风[2;37;0m:[35m标准[2;37;0m 
[1;34m电[2;37;0m:[35m标准[2;37;0m 
上面还刻了一些符字：
锋利:[32m粗糙[2;37;0m 周天:[36m不错[2;37;0m 长生:[36m不错[2;37;0m 不老:[36m不错[2;37;0m 威力:[33m一般[2;37;0m 
以及一排古篆字【 [1;32m破烂站[2;37;0m 】。和一些【 [1;32m招架[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "lyaxu");
		set("ownername", "破烂站");
		set("value", 2000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 15);
    set("weapon_prop/qi", 11);
    set("weapon_prop/jing", 11);
    set("weapon_prop/jingli", 11);
    set("weapon_prop/damage", 9);

    set("wtypeA",7);
    set("wtypeB",7);
    set("wtypeC",2);
    set("wtypeD",0);
    set("wtypeE",3);
    set("wtypeF",5);
    set("wtypeG",0);
    set("wtypeH",5);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "parry",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 3);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_club(260);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";