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
	set_name("[1;32m月形之刀[2;37;0m", ({ "general blade", "blade" }));
	set_weight(5098);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", @LONG
月形之刀[2;37;0m这是一柄由非常坚硬的[33m生铁[2;37;0m制成，重十斤一两九钱的[1;32m月形之刀[2;37;0m。
综合评价[31m完美精致[2;37;0m 看起来非常锋利，具有[32m水准以上[2;37;0m的威力！
上面刻了几个古符号：
[1;37m雷[2;37;0m:[35m标准[2;37;0m [40m地[2;37;0m:[31m精致[2;37;0m 
上面还刻了一些符字：
锋利:[31m精致[2;37;0m 天灵:[33m一般[2;37;0m 巧制:[36m不错[2;37;0m 
紫石:[36m不错[2;37;0m 闪电:[36m不错[2;37;0m 

以及一排古篆字【 [1;32m圣堂[2;37;0m 】。和一些【 [1;32m内功[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "archon");
		set("ownername", "圣堂");
		set("value", 2000);
		set("weapon_prop/intelligence",8);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 16);
    set("weapon_prop/attack", 14);
    set("weapon_prop/armor", 14);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",5);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",6);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 6);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_blade(188);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";