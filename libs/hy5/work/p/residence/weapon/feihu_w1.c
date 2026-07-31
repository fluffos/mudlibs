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
	set_name("[1;34m叹息[2;37;0m", ({ "shengxie sword", "sword" }));
	set_weight(9908);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[31m胜邪威力巨大而无任何要求！
[2;37;0m这是一把由无比坚硬的[1;36m万年寒冰铁[2;37;0m制成，重十九斤八两一钱的[31m胜邪之剑[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比锋利，具有[1;35m绝世罕见[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;31m创世[2;37;0m [36m木[2;37;0m:[1;35m绝世[2;37;0m [32m水[2;37;0m:[1;33m灭世[2;37;0m [31m火[2;37;0m:[1;35m绝世[2;37;0m [33m土[2;37;0m:[1;33m灭世[2;37;0m [1;37m雷[2;37;0m:[1;31m开元[2;37;0m [1;34m电[2;37;0m:[1;36m完美[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 天灵:[32m粗糙[2;37;0m 福源:[33m很高[2;37;0m 
巧制:[1;36m完美[2;37;0m 
体灵:[1;34m举世[2;37;0m 紫石:[33m很高[2;37;0m 不老:[31m精致[2;37;0m 威力:[1;34m举世[2;37;0m 
以及一排古篆字【 [1;32m飞狐[2;37;0m 】。和一些【 [1;32m刀法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "feihu");
		set("ownername", "飞狐");
		set("value", 36000);
		set("weapon_prop/intelligence",36);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",47);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 42);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 72);
    set("weapon_prop/defense", 83);
    
    set("weapon_prop/neili", 72);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 62);
    set("weapon_prop/jingli", 62);
    set("weapon_prop/damage", 88);

    set("wtypeA",14);
    set("wtypeB",11);
    set("wtypeC",16);
    set("wtypeD",11);
    set("wtypeE",16);
    set("wtypeF",0);
    set("wtypeG",13);
    set("wtypeH",7);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "blade",
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
	
	init_sword(1057);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";