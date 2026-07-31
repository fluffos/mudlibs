// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit WHIP;

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
	set_name("[31m莫邪之鞭[2;37;0m★", ({ "moye whip", "whip" }));
	set_weight(10030);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", @LONG
[31m莫邪锋利无比，能开天辟地，荡妖除魔！
[2;37;0m这是一根由无比坚硬的[1;37m软银[2;37;0m制成，重二十斤零两六钱的[31m莫邪之鞭[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比锋利，具有[1;36m斩妖伏魔[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;33m灭世[2;37;0m [36m木[2;37;0m:[1;31m创世[2;37;0m [32m水[2;37;0m:[1;35m绝世[2;37;0m [31m火[2;37;0m:[1;33m灭世[2;37;0m [1;37m雷[2;37;0m:[1;31m无双[2;37;0m [37m天[2;37;0m:[1;36m完美[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 绝代:[33m很高[2;37;0m 天渊:[32m粗糙[2;37;0m 体灵:[1;36m完美[2;37;0m 白石:[32m粗糙[2;37;0m 周天:[31m精致[2;37;0m 长生:[1;36m完美[2;37;0m 不老:[31m精致[2;37;0m 

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
		set("weapon_prop/percao",42);
		set("weapon_prop/dexerity",38);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 38);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 77);
    
    set("weapon_prop/neili", 60);
    set("weapon_prop/qi", 73);
    set("weapon_prop/jing", 67);
    set("weapon_prop/jingli", 67);
    set("weapon_prop/damage", 0);

    set("wtypeA",16);
    set("wtypeB",14);
    set("wtypeC",11);
    set("wtypeD",16);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",12);
    set("wtypeH",0);
    set("wtypeI",7);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 25);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_whip(612);
	setup();
}



#include "/obj/ritem/weaponzy.h";