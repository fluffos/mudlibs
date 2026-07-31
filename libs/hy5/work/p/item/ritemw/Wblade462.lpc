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
	set_name("[31m鱼肠之刀[2;37;0m", ({ "yuchang blade", "blade" }));
	set_weight(12328);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", @LONG
[31m鱼肠轻巧无比，能开天辟地，荡妖除魔！
[2;37;0m这是一柄由无比坚硬的[1;37m软银[2;37;0m制成，重二十四斤六两五钱的[31m鱼肠之刀[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比锋利，具有[1;31m天下无双[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;36m完美[2;37;0m [36m木[2;37;0m:[1;33m天圣[2;37;0m [32m水[2;37;0m:[1;34m举世[2;37;0m [40m地[2;37;0m:[1;32m魔王[2;37;0m [1;36m人[2;37;0m:[1;31m创世[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 绝代:[33m很高[2;37;0m 天渊:[33m很高[2;37;0m 天玄:[33m很高[2;37;0m 紫石:[1;36m完美[2;37;0m 周天:[33m很高[2;37;0m 长生:[33m很高[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 36000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",40);
		set("weapon_prop/dexerity",40);
		set("weapon_prop/constitution",47);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 76);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 48);
    set("weapon_prop/qi", 41);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",7);
    set("wtypeB",10);
    set("wtypeC",8);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",9);
    set("wtypeK",14);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "leg",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 21);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_blade(1170);
	setup();
}



#include "/obj/ritem/weaponzy.h";