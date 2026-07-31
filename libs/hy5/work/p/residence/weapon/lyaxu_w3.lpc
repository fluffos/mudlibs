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
	set_name("[1;32m神人鬼[2;37;0m", ({ "good whip", "whip" }));
	set_weight(7615);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", @LONG
桃花之鞭[2;37;0m这是一根由无比坚硬的[31m流花石[2;37;0m制成，重十五斤二两三钱的[1;32m桃花之鞭[2;37;0m。
综合评价[1;34m举世罕见[2;37;0m 看起来无比锋利，具有[35m极其可怕[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;34m举世[2;37;0m [32m水[2;37;0m:[1;34m举世[2;37;0m [33m土[2;37;0m:[33m很高[2;37;0m [1;35m风[2;37;0m:[1;33m天圣[2;37;0m 
[1;34m电[2;37;0m:[33m很高[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m天圣[2;37;0m 体灵:[36m不错[2;37;0m 闪电:[36m不错[2;37;0m 
周天:[36m不错[2;37;0m 长生:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m破烂站[2;37;0m 】。和一些【 [1;32m指法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "lyaxu");
		set("ownername", "破烂站");
		set("value", 9000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 11);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 11);
    
    set("weapon_prop/neili", 16);
    set("weapon_prop/qi", 31);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",8);
    set("wtypeB",0);
    set("wtypeC",8);
    set("wtypeD",0);
    set("wtypeE",4);
    set("wtypeF",10);
    set("wtypeG",0);
    set("wtypeH",4);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "finger",
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
	
	init_whip(410);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";