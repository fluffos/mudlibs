// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit WHIP;

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
	set_name("[34m天竹之鞭[2;37;0m", ({ "good whip", "whip" }));
	set_weight(5771);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", @LONG
天竹之鞭[2;37;0m这是一根由无比坚硬的[31m流花石[2;37;0m制成，重十一斤五两四钱的[34m天竹之鞭[2;37;0m。
综合评价[1;34m举世罕见[2;37;0m 看起来无比锋利，具有[1;36m斩妖伏魔[2;37;0m的威力！
上面刻了几个古符号：
[32m水[2;37;0m:[1;32m魔王[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m天圣[2;37;0m 天宇:[36m不错[2;37;0m 巧制:[34m细碎[2;37;0m 
紫石:[34m细碎[2;37;0m 
以及一排古篆字【 [1;32m何金银[2;37;0m 】。和一些【 [1;32m刀法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "xianodb");
		set("ownername", "何金银");
		set("value", 9000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",17);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 25);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 23);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 16);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",9);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "blade",
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
	
	init_whip(644);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";