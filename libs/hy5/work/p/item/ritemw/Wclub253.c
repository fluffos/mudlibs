// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit CLUB;

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
	set_name("[31m飞武之棍[2;37;0m", ({ "good club", "club" }));
	set_weight(11644);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", @LONG
飞武之棍[2;37;0m这是一根由无比坚硬的[33m软铁[2;37;0m制成，重二十三斤二两八钱的[31m飞武之棍[2;37;0m。
综合评价[1;34m举世罕见[2;37;0m 看起来无比锋利，具有[35m极其可怕[2;37;0m的威力！
上面刻了几个古符号：
[36m木[2;37;0m:[1;34m举世[2;37;0m [1;34m电[2;37;0m:[1;33m天圣[2;37;0m [1;31m魔[2;37;0m:[33m很高[2;37;0m 
上面还刻了一些符字：
锋利:[1;35m绝世[2;37;0m 福源:[36m不错[2;37;0m 
巧制:[32m粗糙[2;37;0m 
体灵:[33m一般[2;37;0m 白石:[34m细碎[2;37;0m 周天:[34m细碎[2;37;0m 威力:[36m不错[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 9000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",11);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 22);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 38);
    set("weapon_prop/defense", 10);
    
    set("weapon_prop/neili", 23);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 14);

    set("wtypeA",0);
    set("wtypeB",8);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",10);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",4);
    

                set("skill", ([
                        "name": "whip",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 11);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_club(314);
	setup();
}



#include "/obj/ritem/weaponzy.h";