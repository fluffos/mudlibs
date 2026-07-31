// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit BLADE;

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
	set_name("[1;31m杀猪刀[2;37;0m", ({ "moye blade", "blade" }));
	set_weight(5489);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", @LONG
[31m莫邪锋利无比，能开天辟地，荡妖除魔！
[2;37;0m这是一柄由绝对坚硬的[1;36m万年寒冰铁[2;37;0m制成，重十斤九两七钱的[31m莫邪之刀[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来绝对锋利，具有[1;35m绝世罕见[2;37;0m的威力！
上面刻了几个古符号：
[40m地[2;37;0m:[1;31m创世[2;37;0m [36m木[2;37;0m:[1;31m创世[2;37;0m [1;35m风[2;37;0m:[1;35m绝世[2;37;0m 
[1;37m雷[2;37;0m:[31m精致[2;37;0m [1;34m电[2;37;0m:[1;33m天圣[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 天灵:[32m粗糙[2;37;0m 体灵:[35m标准[2;37;0m 白石:[1;34m举世[2;37;0m 紫石:[35m标准[2;37;0m 长生:[35m标准[2;37;0m 威力:[35m标准[2;37;0m 
以及一排古篆字【 [1;32m阿宝[2;37;0m 】。和一些【 [1;32m剑法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "apo");
		set("ownername", "阿宝");
		set("value", 36000);
		set("weapon_prop/intelligence",36);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 82);
    set("weapon_prop/parry", 51);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 55);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 52);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 59);

    set("wtypeA",0);
    set("wtypeB",14);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",11);
    set("wtypeG",6);
    set("wtypeH",10);
    set("wtypeI",0);
    set("wtypeJ",14);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 23);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_blade(944);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";