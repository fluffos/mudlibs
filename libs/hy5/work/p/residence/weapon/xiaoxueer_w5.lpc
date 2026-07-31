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
	set_name("[37m赤玉之剑[2;37;0m", ({ "chiyu sword", "sword" }));
	set_weight(3481);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[37m赤玉之剑[2;37;0m这是一把由无比坚硬的[1;33m金铁[2;37;0m制成，重六斤九两六钱的[37m赤玉之剑[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来无比锋利，具有[1;35m绝世罕见[2;37;0m的威力！
上面刻了几个古符号：
[40m地[2;37;0m:[1;32m魔王[2;37;0m [1;31m魔[2;37;0m:[1;33m天圣[2;37;0m [1;33m金[2;37;0m:[31m精致[2;37;0m [31m火[2;37;0m:[1;34m举世[2;37;0m 
上面还刻了一些符字：
锋利:[1;31m无双[2;37;0m 天灵:[36m不错[2;37;0m 体灵:[32m粗糙[2;37;0m 白石:[36m不错[2;37;0m 闪电:[34m细碎[2;37;0m 

以及一排古篆字【 [1;32m小雪儿[2;37;0m 】。和一些【 [1;32m锤法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "xiaoxueer");
		set("ownername", "小雪儿");
		set("value", 16000);
		set("weapon_prop/intelligence",17);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 18);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 20);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 39);
    
    set("weapon_prop/neili", 40);
    set("weapon_prop/qi", 48);
    set("weapon_prop/jing", 48);
    set("weapon_prop/jingli", 40);
    set("weapon_prop/damage", 0);

    set("wtypeA",6);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",8);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",9);
    set("wtypeK",0);
    set("wtypeL",10);
    

                set("skill", ([
                        "name": "hammer",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 15);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(1229);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";