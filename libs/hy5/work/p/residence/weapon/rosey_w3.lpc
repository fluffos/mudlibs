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
	set_name("[33m棒棒糖[2;37;0m", ({ "good dagger", "dagger" }));
	set_weight(5982);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
紫云之匕首[2;37;0m这是一把由非常坚硬的[31m流花石[2;37;0m制成，重十一斤九两六钱的[33m紫云之匕首[2;37;0m。
综合评价[1;34m举世罕见[2;37;0m 看起来非常锋利，具有[31m无与伦比[2;37;0m的威力！
上面刻了几个古符号：
[36m木[2;37;0m:[1;33m天圣[2;37;0m [32m水[2;37;0m:[33m很高[2;37;0m [1;35m风[2;37;0m:[33m很高[2;37;0m 
[1;37m雷[2;37;0m:[1;33m天圣[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m天圣[2;37;0m 天宇:[36m不错[2;37;0m 白石:[32m粗糙[2;37;0m 周天:[32m粗糙[2;37;0m 长生:[36m不错[2;37;0m 
以及一排古篆字【 [1;32m大花月季[2;37;0m 】。和一些【 [1;32m招架[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "rosey");
		set("ownername", "大花月季");
		set("value", 9000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",17);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 34);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 34);
    set("weapon_prop/qi", 15);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",10);
    set("wtypeC",4);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",4);
    set("wtypeG",10);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "parry",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 10);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_dagger(509);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";