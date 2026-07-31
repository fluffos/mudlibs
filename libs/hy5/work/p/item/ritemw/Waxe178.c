// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit AXE;

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
	set_name("[34m戈壁之斧[2;37;0m", ({ "general axe", "axe" }));
	set_weight(3828);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", @LONG
戈壁之斧[2;37;0m这是一柄由极其坚硬的[33m生铁[2;37;0m制成，重七斤六两五钱的[34m戈壁之斧[2;37;0m。
综合评价[31m完美精致[2;37;0m 看起来极其锋利，具有[35m极其可怕[2;37;0m的威力！
上面刻了几个古符号：
[1;35m风[2;37;0m:[1;36m完美[2;37;0m 
[1;34m电[2;37;0m:[1;34m举世[2;37;0m [37m天[2;37;0m:[1;36m完美[2;37;0m 
上面还刻了一些符字：
锋利:[31m精致[2;37;0m 天宇:[32m极差[2;37;0m 不老:[32m极差[2;37;0m 

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
		set("weapon_prop/strength",4);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 5);
    set("weapon_prop/jingli", 5);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",7);
    set("wtypeG",0);
    set("wtypeH",8);
    set("wtypeI",7);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "finger",
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
	
	init_axe(310);
	setup();
}



#include "/obj/ritem/weaponzy.h";