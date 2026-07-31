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
	set_name("[1;37m屠龙剑[2;37;0m", ({ "general sword", "sword" }));
	set_weight(2930);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
双星之剑[2;37;0m这是一把由极为坚硬的[33m软铁[2;37;0m制成，重五斤八两六钱的[1;37m双星之剑[2;37;0m。
综合评价[31m完美精致[2;37;0m 看起来极为锋利，具有[32m水准以上[2;37;0m的威力！
上面刻了几个古符号：
[31m火[2;37;0m:[1;36m完美[2;37;0m [1;34m电[2;37;0m:[35m标准[2;37;0m 
上面还刻了一些符字：
锋利:[33m很高[2;37;0m 白石:[36m不错[2;37;0m 紫石:[36m不错[2;37;0m 
以及一排古篆字【 [1;32m半粒米[2;37;0m 】。和一些【 [1;32m斧法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ebeba");
		set("ownername", "半粒米");
		set("value", 2000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 17);
    set("weapon_prop/parry", 19);
    set("weapon_prop/attack", 0);
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
    set("wtypeD",7);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",5);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "axe",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 4);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(267);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";