// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit THROWING;

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
	set_name("[31m火鶴之暗器[2;37;0m", ({ "general throwing", "throwing" }));
	set_weight(796);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", @LONG
火鶴之暗器[2;37;0m这是一支由无比坚硬的[33m生铁[2;37;0m制成，重一斤五两九钱的[31m火鶴之暗器[2;37;0m。
综合评价[31m完美精致[2;37;0m 看起来无比锋利，具有[35m极其可怕[2;37;0m的威力！
上面刻了几个古符号：
[33m土[2;37;0m:[1;36m完美[2;37;0m [1;31m魔[2;37;0m:[33m很高[2;37;0m 
上面还刻了一些符字：
锋利:[35m标准[2;37;0m 天宇:[33m一般[2;37;0m 福源:[33m一般[2;37;0m 
天玄:[36m不错[2;37;0m 长生:[36m不错[2;37;0m 

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
		set("weapon_prop/strength",9);
		set("weapon_prop/karey",9);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",11);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 18);
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
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",4);
    

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
    set("sharpness", 5);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	set_amount(1);
	init_throwing(415);
	setup();
}



#include "/obj/ritem/weaponzy.h";