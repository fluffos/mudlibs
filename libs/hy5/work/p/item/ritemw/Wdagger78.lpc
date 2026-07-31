// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit DAGGER;

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
	set_name("[33m叠之匕首[2;37;0m", ({ "bad dagger", "dagger" }));
	set_weight(11323);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
叠之匕首[2;37;0m这是一把由十分坚硬的[32m青铜[2;37;0m制成，重二十二斤六两四钱的[33m叠之匕首[2;37;0m。
综合评价[32m精致细美[2;37;0m 看起来十分锋利，具有[32m水准以上[2;37;0m的威力！
上面刻了几个古符号：
[31m火[2;37;0m:[31m精致[2;37;0m [40m地[2;37;0m:[36m不错[2;37;0m 
上面还刻了一些符字：
锋利:[34m细碎[2;37;0m 天渊:[32m极差[2;37;0m 体灵:[33m一般[2;37;0m 闪电:[33m一般[2;37;0m 
周天:[33m一般[2;37;0m 不老:[33m一般[2;37;0m 

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
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",1);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 6);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 7);
    
    set("weapon_prop/neili", 8);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 7);
    set("weapon_prop/jingli", 7);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",6);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",1);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "club",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 2);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_dagger(177);
	setup();
}



#include "/obj/ritem/weaponzy.h";