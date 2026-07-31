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
	set_name("[1;35m魔袱之刀[2;37;0m", ({ "general blade", "blade" }));
	set_weight(14744);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", @LONG
魔袱之刀[2;37;0m这是一柄由比较坚硬的[33m生铁[2;37;0m制成，重二十九斤四两八钱的[1;35m魔袱之刀[2;37;0m。
综合评价[31m完美精致[2;37;0m 看起来比较锋利，具有[34m不错[2;37;0m的威力！
上面刻了几个古符号：
[33m土[2;37;0m:[1;36m完美[2;37;0m [1;34m电[2;37;0m:[32m粗糙[2;37;0m [40m地[2;37;0m:[32m粗糙[2;37;0m [1;31m魔[2;37;0m:[33m很高[2;37;0m 
上面还刻了一些符字：
锋利:[32m粗糙[2;37;0m 绝代:[32m极差[2;37;0m 天渊:[33m一般[2;37;0m 闪电:[36m不错[2;37;0m 


LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 2000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",2);
		set("weapon_prop/dexerity",7);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 11);
    set("weapon_prop/armor", 0);
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
    set("wtypeE",7);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",3);
    set("wtypeI",0);
    set("wtypeJ",3);
    set("wtypeK",0);
    set("wtypeL",4);
    

                set("skill", ([
                        "name": "claw",
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
	
	init_blade(144);
	setup();
}



#include "/obj/ritem/weaponzy.h";