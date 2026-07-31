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
	set_name("[35m毒龙剑[2;37;0m", ({ "yuchang sword", "sword" }));
	set_weight(7032);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[31m鱼肠轻巧无比，能开天辟地，荡妖除魔！
[2;37;0m这是一根由无比坚硬的[1;36m万年寒冰铁[2;37;0m制成，重十四斤零两六钱的[31m鱼肠之剑[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比锋利，具有[1;35m绝世罕见[2;37;0m的威力！
上面刻了几个古符号：
[1;31m魔[2;37;0m:[1;31m毁天[2;37;0m [1;33m金[2;37;0m:[1;33m天圣[2;37;0m [36m木[2;37;0m:[1;31m无双[2;37;0m [32m水[2;37;0m:[1;31m创世[2;37;0m [33m土[2;37;0m:[1;31m无双[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 天灵:[33m很高[2;37;0m 天渊:[33m很高[2;37;0m 白石:[33m很高[2;37;0m 紫石:[1;34m举世[2;37;0m 周天:[35m标准[2;37;0m 长生:[33m很高[2;37;0m 不老:[1;34m举世[2;37;0m 
以及一排古篆字【 [1;32m珞珈混混[2;37;0m 】。和一些【 [1;32m内功[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "eddie");
		set("ownername", "珞珈混混");
		set("value", 36000);
		set("weapon_prop/intelligence",46);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",46);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 46);
    set("weapon_prop/parry", 86);
    set("weapon_prop/attack", 72);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 50);
    set("weapon_prop/qi", 72);
    set("weapon_prop/jing", 80);
    set("weapon_prop/jingli", 80);
    set("weapon_prop/damage", 0);

    set("wtypeA",10);
    set("wtypeB",12);
    set("wtypeC",14);
    set("wtypeD",9);
    set("wtypeE",12);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",15);
    

                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 26);

		set("wield_msg", "$N将$n拿在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(932);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";