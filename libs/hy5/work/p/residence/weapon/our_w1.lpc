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
	set_name("[1;31m无双[2;37;0m", ({ "yuchang sword", "sword" }));
	set_weight(5804);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[31m鱼肠轻巧无比，能开天辟地，荡妖除魔！
[2;37;0m这是一把由无比坚硬的[1;36m万年寒冰铁[2;37;0m制成，重十一斤六两零钱的[31m鱼肠之剑[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比锋利，具有[1;31m天下无双[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;33m灭世[2;37;0m [36m木[2;37;0m:[1;33m天圣[2;37;0m [32m水[2;37;0m:[1;31m毁天[2;37;0m [31m火[2;37;0m:[1;36m完美[2;37;0m [33m土[2;37;0m:[1;33m天圣[2;37;0m [1;35m风[2;37;0m:[1;31m创世[2;37;0m 
[1;37m雷[2;37;0m:[1;32m魔王[2;37;0m [1;34m电[2;37;0m:[1;31m创世[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 天玄:[32m粗糙[2;37;0m 体灵:[35m标准[2;37;0m 白石:[1;36m完美[2;37;0m 紫石:[1;34m举世[2;37;0m 周天:[1;34m举世[2;37;0m 长生:[1;36m完美[2;37;0m 不老:[31m精致[2;37;0m 威力:[1;36m完美[2;37;0m 
以及一排古篆字【 [1;32m锦绣无双[2;37;0m 】。和一些【 [1;32m手法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "our");
		set("ownername", "锦绣无双");
		set("value", 36000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",72);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",38);
    set("weapon_prop/dodge", 70);
    set("weapon_prop/parry", 88);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 59);
    
    set("weapon_prop/neili", 88);
    set("weapon_prop/qi", 75);
    set("weapon_prop/jing", 64);
    set("weapon_prop/jingli", 64);
    set("weapon_prop/damage", 74);

    set("wtypeA",16);
    set("wtypeB",10);
    set("wtypeC",15);
    set("wtypeD",9);
    set("wtypeE",10);
    set("wtypeF",14);
    set("wtypeG",9);
    set("wtypeH",14);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "hand",
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
	
	init_sword(1293);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";