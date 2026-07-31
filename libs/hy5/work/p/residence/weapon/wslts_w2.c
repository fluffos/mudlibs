// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit THROWING;

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
	set_name("[1;32m龙星[2;37;0m", ({ "zhendian throwing", "throwing" }));
	set_weight(386);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", @LONG
[37m震电之暗器[2;37;0m这是一支由极其坚硬的[1;33m金铁[2;37;0m制成，重零斤七两七钱的[37m震电之暗器[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来极其锋利，具有[31m无与伦比[2;37;0m的威力！
上面刻了几个古符号：
[1;36m人[2;37;0m:[33m很高[2;37;0m [32m水[2;37;0m:[1;35m绝世[2;37;0m [33m土[2;37;0m:[1;36m完美[2;37;0m [1;35m风[2;37;0m:[1;35m绝世[2;37;0m 

上面还刻了一些符字：
锋利:[1;31m无双[2;37;0m 巧制:[33m很高[2;37;0m 
白石:[33m很高[2;37;0m 周天:[35m标准[2;37;0m 长生:[34m细碎[2;37;0m 威力:[34m细碎[2;37;0m 
以及一排古篆字【 [1;32m莫等闲[2;37;0m 】。和一些【 [1;32m内功[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "wslts");
		set("ownername", "莫等闲");
		set("value", 16000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 46);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 45);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 55);
    set("weapon_prop/qi", 20);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 26);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",11);
    set("wtypeD",0);
    set("wtypeE",7);
    set("wtypeF",11);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",4);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 12);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	set_amount(99);
	init_throwing(557);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";