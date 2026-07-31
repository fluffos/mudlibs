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
	set_name("[1;36m灵风之剑[2;37;0m", ({ "bad sword", "sword" }));
	set_weight(5760);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
小之剑[2;37;0m这是一把由相当坚硬的[32m青铜[2;37;0m制成，重十一斤五两二钱的[1;36m小之剑[2;37;0m。
综合评价[32m精致细美[2;37;0m 看起来相当锋利，具有[32m水准以上[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[31m精致[2;37;0m [1;37m雷[2;37;0m:[32m粗糙[2;37;0m [1;34m电[2;37;0m:[33m很高[2;37;0m [37m天[2;37;0m:[32m粗糙[2;37;0m 
上面还刻了一些符字：
锋利:[35m标准[2;37;0m 紫石:[33m一般[2;37;0m 
以及一排古篆字【 [1;32m云霜翎[2;37;0m 】。和一些【 [1;32m拳法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "mist");
		set("ownername", "云霜翎");
		set("value", 2000);
		set("weapon_prop/intelligence",72);
		set("weapon_prop/strength",72);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",72);
		set("weapon_prop/constitution",72);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 9);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 72);
    set("weapon_prop/qi", 72);
    set("weapon_prop/jing", 72);
    set("weapon_prop/jingli", 72);
    set("weapon_prop/damage", 0);

    set("wtypeA",6);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",9);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",3);
    set("wtypeH",4);
    set("wtypeI",3);
    set("wtypeJ",9);
    set("wtypeK",9);
    set("wtypeL",9);
    

                set("skill", ([
                        "name": "cuff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 5);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(621);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";