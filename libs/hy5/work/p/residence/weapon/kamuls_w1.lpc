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
	set_name("[31m巨阙之剑[2;37;0m", ({ "juque sword", "sword" }));
	set_weight(7953);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[31m巨阙坚硬无比，能开天辟地，荡妖除魔！
[2;37;0m这是一把由极为坚硬的[1;36m万年寒冰铁[2;37;0m制成，重十五斤九两零钱的[31m巨阙之剑[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来极为锋利，具有[1;31m开元创世[2;37;0m的威力！
上面刻了几个古符号：
[37m天[2;37;0m:[1;35m绝世[2;37;0m [1;31m魔[2;37;0m:[31m精致[2;37;0m [36m木[2;37;0m:[1;32m魔王[2;37;0m [32m水[2;37;0m:[1;33m灭世[2;37;0m [31m火[2;37;0m:[1;34m举世[2;37;0m [33m土[2;37;0m:[1;31m无双[2;37;0m [1;35m风[2;37;0m:[1;33m灭世[2;37;0m 
[1;34m电[2;37;0m:[1;31m无双[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 天灵:[32m粗糙[2;37;0m 天玄:[32m粗糙[2;37;0m 巧制:[33m很高[2;37;0m 
体灵:[33m很高[2;37;0m 紫石:[1;36m完美[2;37;0m 周天:[33m很高[2;37;0m 
以及一排古篆字【 [1;32m静文[2;37;0m 】。和一些【 [1;32m暗器[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "kamuls");
		set("ownername", "静文");
		set("value", 36000);
		set("weapon_prop/intelligence",38);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",36);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 72);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 46);
    set("weapon_prop/defense", 43);
    
    set("weapon_prop/neili", 49);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",9);
    set("wtypeC",16);
    set("wtypeD",8);
    set("wtypeE",12);
    set("wtypeF",16);
    set("wtypeG",0);
    set("wtypeH",12);
    set("wtypeI",11);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",6);
    

                set("skill", ([
                        "name": "throwing",
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
	
	init_sword(1347);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";