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
	set_name("[34m牛头之刀[2;37;0m", ({ "good blade", "blade" }));
	set_weight(5984);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", @LONG
牛头之刀[2;37;0m这是一柄由无比坚硬的[31m流花石[2;37;0m制成，重十一斤九两六钱的[34m牛头之刀[2;37;0m。
综合评价[1;34m举世罕见[2;37;0m 看起来无比锋利，具有[35m极其可怕[2;37;0m的威力！
上面刻了几个古符号：
[1;36m人[2;37;0m:[1;33m天圣[2;37;0m [1;33m金[2;37;0m:[35m标准[2;37;0m [36m木[2;37;0m:[1;33m天圣[2;37;0m [32m水[2;37;0m:[1;34m举世[2;37;0m [1;35m风[2;37;0m:[32m粗糙[2;37;0m 

上面还刻了一些符字：
锋利:[1;32m魔王[2;37;0m 天灵:[36m不错[2;37;0m 巧制:[34m细碎[2;37;0m 
体灵:[34m细碎[2;37;0m 紫石:[32m粗糙[2;37;0m 威力:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m仓库一[2;37;0m 】。和一些【 [1;32m斧法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "fena");
		set("ownername", "仓库一");
		set("value", 9000);
		set("weapon_prop/intelligence",18);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 35);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 21);
    set("weapon_prop/defense", 26);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 30);

    set("wtypeA",5);
    set("wtypeB",10);
    set("wtypeC",8);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",3);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",10);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "axe",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 9);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_blade(442);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";