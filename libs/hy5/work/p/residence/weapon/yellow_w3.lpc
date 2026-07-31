// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit BLADE;

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
	set_name("[1;37m蝉翼刀[2;37;0m", ({ "tiandi blade", "blade" }));
	set_weight(4118);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", @LONG
[1;36m天地之初，女娲补天所留下的天地间至尊之物之一经千秋万载所制，功能开天劈地！
[2;37;0m这是一柄由无比坚硬的[31m万年神铁[2;37;0m制成，重八斤二两三钱的[1;36m天地之刀[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比锋利，具有[31m无与伦比[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;31m创世[2;37;0m [36m木[2;37;0m:[1;36m完美[2;37;0m [32m水[2;37;0m:[1;31m无双[2;37;0m [31m火[2;37;0m:[1;33m天圣[2;37;0m [1;34m电[2;37;0m:[1;31m开元[2;37;0m 
上面还刻了一些符字：
锋利:[1;31m毁天[2;37;0m 巧制:[34m细碎[2;37;0m 
白石:[35m标准[2;37;0m 紫石:[31m精致[2;37;0m 周天:[33m很高[2;37;0m 威力:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m段药师[2;37;0m 】。和一些【 [1;32m轻功[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "yellow");
		set("ownername", "段药师");
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 51);
    set("weapon_prop/parry", 62);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 29);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 47);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 35);

    set("wtypeA",14);
    set("wtypeB",7);
    set("wtypeC",12);
    set("wtypeD",10);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",13);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "dodge",
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
	
	init_blade(556);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";