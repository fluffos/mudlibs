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
	set_name("[1;32m潜龙[2;37;0m", ({ "bad sword", "sword" }));
	set_weight(5949);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
竹之剑[2;37;0m这是一把由非常坚硬的[32m青铜[2;37;0m制成，重十一斤八两九钱的[1;32m竹之剑[2;37;0m。
综合评价[32m精致细美[2;37;0m 看起来非常锋利，具有[32m水准以上[2;37;0m的威力！
上面刻了几个古符号：
[32m水[2;37;0m:[32m粗糙[2;37;0m [1;35m风[2;37;0m:[36m不错[2;37;0m 
[1;36m人[2;37;0m:[36m不错[2;37;0m 
上面还刻了一些符字：
锋利:[34m细碎[2;37;0m 天宇:[32m极差[2;37;0m 
以及一排古篆字【 [1;32m传真机三号[2;37;0m 】。和一些【 [1;32m内功[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "faxthree");
		set("ownername", "传真机三号");
		set("value", 2000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",2);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",3);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",1);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",1);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 2);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(261);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";