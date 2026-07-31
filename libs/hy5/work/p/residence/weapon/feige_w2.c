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
	set_name("[1;32m无影之刀[2;37;0m", ({ "wuying blade", "blade" }));
	set_weight(5941);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", @LONG
[1;32m无影之刀[2;37;0m这是一柄由无比坚硬的[1;33m金铁[2;37;0m制成，重十一斤八两八钱的[1;32m无影之刀[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来无比锋利，具有[31m无与伦比[2;37;0m的威力！
上面刻了几个古符号：
[36m木[2;37;0m:[35m标准[2;37;0m [31m火[2;37;0m:[1;31m无双[2;37;0m [33m土[2;37;0m:[1;32m魔王[2;37;0m [1;35m风[2;37;0m:[1;34m举世[2;37;0m 
[1;34m电[2;37;0m:[1;34m举世[2;37;0m 
上面还刻了一些符字：
锋利:[1;31m无双[2;37;0m 绝代:[36m不错[2;37;0m 天玄:[34m细碎[2;37;0m 巧制:[35m标准[2;37;0m 
白石:[36m不错[2;37;0m 
以及一排古篆字【 [1;32m天天向上[2;37;0m 】。和一些【 [1;32m指法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "feige");
		set("ownername", "天天向上");
		set("value", 16000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",18);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",26);
    set("weapon_prop/dodge", 18);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 51);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 48);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",5);
    set("wtypeC",0);
    set("wtypeD",12);
    set("wtypeE",9);
    set("wtypeF",8);
    set("wtypeG",0);
    set("wtypeH",8);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "finger",
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
	
	init_blade(592);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";