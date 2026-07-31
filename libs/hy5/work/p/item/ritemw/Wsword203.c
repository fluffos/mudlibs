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
	set_name("[1;34m地竹之剑[2;37;0m", ({ "good sword", "sword" }));
	set_weight(12643);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
地竹之剑[2;37;0m这是一把由非常坚硬的[33m软铁[2;37;0m制成，重二十五斤二两八钱的[1;34m地竹之剑[2;37;0m。
综合评价[1;34m举世罕见[2;37;0m 看起来非常锋利，具有[35m极其可怕[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[33m很高[2;37;0m [1;35m风[2;37;0m:[32m粗糙[2;37;0m 
[1;37m雷[2;37;0m:[32m粗糙[2;37;0m [37m天[2;37;0m:[31m精致[2;37;0m [40m地[2;37;0m:[1;34m举世[2;37;0m 
上面还刻了一些符字：
锋利:[1;31m开元[2;37;0m 天玄:[36m不错[2;37;0m 白石:[36m不错[2;37;0m 不老:[36m不错[2;37;0m 

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
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",15);
    set("weapon_prop/dodge", 12);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 15);
    set("weapon_prop/jingli", 15);
    set("weapon_prop/damage", 0);

    set("wtypeA",4);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",3);
    set("wtypeG",3);
    set("wtypeH",0);
    set("wtypeI",6);
    set("wtypeJ",8);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 13);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(355);
	setup();
}



#include "/obj/ritem/weaponzy.h";