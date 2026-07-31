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
	set_name("[31m太阿之剑[2;37;0m", ({ "taie sword", "sword" }));
	set_weight(18807);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[31m太阿帝王之兵，持之能号令天下，莫有不从！
[2;37;0m这是一把由无比坚硬的[1;36m万年寒冰铁[2;37;0m制成，重三十七斤六两一钱的[31m太阿之剑[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比锋利，具有[1;35m绝世罕见[2;37;0m的威力！
上面刻了几个古符号：
[1;31m魔[2;37;0m:[1;34m举世[2;37;0m [1;33m金[2;37;0m:[1;31m开元[2;37;0m [36m木[2;37;0m:[1;31m开元[2;37;0m [31m火[2;37;0m:[1;33m灭世[2;37;0m [33m土[2;37;0m:[1;31m毁天[2;37;0m [1;35m风[2;37;0m:[1;31m毁天[2;37;0m 
[1;34m电[2;37;0m:[1;32m魔王[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 天灵:[32m粗糙[2;37;0m 绝代:[33m很高[2;37;0m 巧制:[1;32m魔王[2;37;0m 
白石:[35m标准[2;37;0m 周天:[32m粗糙[2;37;0m 长生:[31m精致[2;37;0m 不老:[31m精致[2;37;0m 
以及一排古篆字【 [1;32m某人[2;37;0m 】。和一些【 [1;32m爪法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "hxsd");
		set("ownername", "某人");
		set("value", 36000);
		set("weapon_prop/intelligence",38);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",40);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 59);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 92);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 38);
    set("weapon_prop/qi", 69);
    set("weapon_prop/jing", 60);
    set("weapon_prop/jingli", 60);
    set("weapon_prop/damage", 0);

    set("wtypeA",13);
    set("wtypeB",13);
    set("wtypeC",0);
    set("wtypeD",16);
    set("wtypeE",15);
    set("wtypeF",15);
    set("wtypeG",0);
    set("wtypeH",9);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",8);
    

                set("skill", ([
                        "name": "claw",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 24);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(4828);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";