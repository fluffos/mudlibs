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
	set_name("[1;37m飞剑[2;37;0m", ({ "zhanlu sword", "sword" }));
	set_weight(23009);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[31m湛卢威力、锋利、坚硬都冠绝当世，乃千古神兵！
[2;37;0m这是一把由无比坚硬的[1;36m万年寒冰铁[2;37;0m制成，重四十六斤零两一钱的[31m湛卢之剑[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比锋利，具有[1;31m开元创世[2;37;0m的威力！
上面刻了几个古符号：
[40m地[2;37;0m:[1;31m毁天[2;37;0m [36m木[2;37;0m:[1;31m无双[2;37;0m [32m水[2;37;0m:[1;32m魔王[2;37;0m [31m火[2;37;0m:[31m精致[2;37;0m [1;35m风[2;37;0m:[1;32m魔王[2;37;0m 
[1;37m雷[2;37;0m:[1;33m灭世[2;37;0m [1;34m电[2;37;0m:[1;32m魔王[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 天灵:[33m很高[2;37;0m 绝代:[32m粗糙[2;37;0m 天玄:[33m很高[2;37;0m 白石:[35m标准[2;37;0m 周天:[1;36m完美[2;37;0m 威力:[1;34m举世[2;37;0m 
以及一排古篆字【 [1;32m云飞[2;37;0m 】。和一些【 [1;32m斧法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "yunfei");
		set("ownername", "云飞");
		set("value", 36000);
		set("weapon_prop/intelligence",43);
		set("weapon_prop/strength",72);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",37);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",49);
    set("weapon_prop/dodge", 56);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 79);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 87);

    set("wtypeA",0);
    set("wtypeB",12);
    set("wtypeC",9);
    set("wtypeD",9);
    set("wtypeE",0);
    set("wtypeF",9);
    set("wtypeG",16);
    set("wtypeH",9);
    set("wtypeI",0);
    set("wtypeJ",15);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "axe",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 22);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(1409);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";