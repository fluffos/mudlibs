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
	set_name("[1;35m轩辕之剑[2;37;0m", ({ "xuanyuan sword", "sword" }));
	set_weight(16042);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[1;35m昔日黄帝持此物立于指南车上，驱迷雾，扫阴霾，率应龙旱魃，御百兽而战蚩尤！
[2;37;0m这是一把由无比坚硬的[37m玄铁[2;37;0m制成，重三十二斤零两八钱的[1;35m轩辕之剑[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比锋利，具有[1;31m天下无双[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;33m天圣[2;37;0m [36m木[2;37;0m:[1;31m无双[2;37;0m [32m水[2;37;0m:[1;31m创世[2;37;0m [31m火[2;37;0m:[31m精致[2;37;0m [1;35m风[2;37;0m:[1;35m绝世[2;37;0m 
[1;37m雷[2;37;0m:[1;33m天圣[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 福源:[32m粗糙[2;37;0m 
天渊:[34m细碎[2;37;0m 天玄:[32m粗糙[2;37;0m 体灵:[34m细碎[2;37;0m 闪电:[33m很高[2;37;0m 

以及一排古篆字【 [1;32m科比[2;37;0m 】。和一些【 [1;32m斧法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "kobe");
		set("ownername", "科比");
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",33);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",26);
		set("weapon_prop/constitution",35);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 45);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 26);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",10);
    set("wtypeB",12);
    set("wtypeC",14);
    set("wtypeD",6);
    set("wtypeE",0);
    set("wtypeF",11);
    set("wtypeG",10);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "axe",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 16);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(1126);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";