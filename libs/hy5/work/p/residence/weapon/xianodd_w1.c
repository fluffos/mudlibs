// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit STAFF;

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
	set_name("[1;35m望月之杖[2;37;0m", ({ "good staff", "staff" }));
	set_weight(8868);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", @LONG
望月之杖[2;37;0m这是一根由相当坚硬的[1;37m软银[2;37;0m制成，重十七斤七两三钱的[1;35m望月之杖[2;37;0m。
综合评价[1;34m举世罕见[2;37;0m 看起来相当锋利，具有[35m极其可怕[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[32m粗糙[2;37;0m [1;34m电[2;37;0m:[31m精致[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m天圣[2;37;0m 天灵:[36m不错[2;37;0m 天渊:[36m不错[2;37;0m 天玄:[36m不错[2;37;0m 体灵:[34m细碎[2;37;0m 
以及一排古篆字【 [1;32m慕容天[2;37;0m 】。和一些【 [1;32m鞭法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "xianodd");
		set("ownername", "慕容天");
		set("value", 9000);
		set("weapon_prop/intelligence",18);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",19);
		set("weapon_prop/constitution",16);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 23);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",3);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",6);
    set("wtypeI",7);
    set("wtypeJ",0);
    set("wtypeK",7);
    set("wtypeL",3);
    

                set("skill", ([
                        "name": "whip",
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
	
	init_staff(409);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";