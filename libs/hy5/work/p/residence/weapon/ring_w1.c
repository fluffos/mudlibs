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
	set_name("[1;36m风之咏叹[2;37;0m", ({ "shengxie sword", "sword" }));
	set_weight(18916);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[31m胜邪威力巨大而无任何要求！
[2;37;0m这是一把由无比坚硬的[1;36m万年寒冰铁[2;37;0m制成，重三十七斤八两三钱的[31m胜邪之剑[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比锋利，具有[1;31m毁天灭地[2;37;0m的威力！
上面刻了几个古符号：
[36m木[2;37;0m:[1;31m无双[2;37;0m [32m水[2;37;0m:[1;33m灭世[2;37;0m [31m火[2;37;0m:[1;31m毁天[2;37;0m [1;35m风[2;37;0m:[1;33m天圣[2;37;0m 
[1;37m雷[2;37;0m:[1;36m完美[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 天灵:[33m很高[2;37;0m 天玄:[32m粗糙[2;37;0m 体灵:[33m很高[2;37;0m 紫石:[1;36m完美[2;37;0m 闪电:[1;36m完美[2;37;0m 
周天:[35m标准[2;37;0m 
以及一排古篆字【 [1;32m風鈴[2;37;0m 】。和一些【 [1;32m指法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ring");
		set("ownername", "風鈴");
		set("value", 36000);
		set("weapon_prop/intelligence",41);
		set("weapon_prop/strength",72);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",36);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 73);
    set("weapon_prop/attack", 71);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 40);
    
    set("weapon_prop/neili", 50);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 72);
    set("weapon_prop/jingli", 72);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",12);
    set("wtypeC",16);
    set("wtypeD",15);
    set("wtypeE",0);
    set("wtypeF",10);
    set("wtypeG",7);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",9);
    set("wtypeL",9);
    

                set("skill", ([
                        "name": "finger",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 19);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(1705);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";