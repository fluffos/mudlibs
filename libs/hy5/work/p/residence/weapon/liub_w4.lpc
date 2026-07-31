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
	set_name("[33m朱唇之剑[2;37;0m", ({ "good sword", "sword" }));
	set_weight(4335);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
朱唇之剑[2;37;0m这是一把由无比坚硬的[31m流花石[2;37;0m制成，重八斤六两七钱的[33m朱唇之剑[2;37;0m。
综合评价[1;34m举世罕见[2;37;0m 看起来无比锋利，具有[1;34m倚天屠龙[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;34m举世[2;37;0m [36m木[2;37;0m:[1;33m天圣[2;37;0m [33m土[2;37;0m:[1;33m天圣[2;37;0m [1;35m风[2;37;0m:[1;33m天圣[2;37;0m 
[1;34m电[2;37;0m:[1;32m魔王[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m天圣[2;37;0m 天灵:[36m不错[2;37;0m 巧制:[34m细碎[2;37;0m 
紫石:[36m不错[2;37;0m 闪电:[36m不错[2;37;0m 

以及一排古篆字【 [1;32m卜凤[2;37;0m 】。和一些【 [1;32m掌法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "liub");
		set("ownername", "卜凤");
		set("value", 9000);
		set("weapon_prop/intelligence",19);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 19);
    set("weapon_prop/attack", 19);
    set("weapon_prop/armor", 22);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",8);
    set("wtypeB",10);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",10);
    set("wtypeF",10);
    set("wtypeG",0);
    set("wtypeH",9);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "strike",
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
	
	init_sword(671);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";