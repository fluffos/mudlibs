// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit DAGGER;

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
	set_name("[1;37m七宗罪[2;37;0m", ({ "taiji dagger", "dagger" }));
	set_weight(270);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", @LONG
[1;33m太极者，无极而生，阴阳之母也。动之则分，静之则合。无过不及，随曲就伸。
人刚我柔谓之走，我顺人背谓之粘。动急则急应，动缓则缓随。虽变化万端，而
理为一贯！
[2;37;0m这是一支由无比坚硬的[31m万年神铁[2;37;0m制成，重零斤五两四钱的[1;33m太极之暗器[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比锋利，具有[1;33m举世无匹[2;37;0m的威力！
上面刻了几个古符号：
[1;36m人[2;37;0m:[1;32m魔王[2;37;0m [1;33m金[2;37;0m:[1;31m创世[2;37;0m [36m木[2;37;0m:[1;31m开元[2;37;0m [32m水[2;37;0m:[1;35m绝世[2;37;0m [31m火[2;37;0m:[31m精致[2;37;0m 
上面还刻了一些符字：
锋利:[1;31m毁天[2;37;0m 体灵:[35m标准[2;37;0m 周天:[31m精致[2;37;0m 长生:[1;36m完美[2;37;0m 不老:[33m很高[2;37;0m 威力:[31m精致[2;37;0m 
以及一排古篆字【 [1;32m地图一号[2;37;0m 】。和一些【 [1;32m剑法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "maper");
		set("ownername", "地图一号");
		set("value", 25000);
		set("weapon_prop/intelligence",56);
		set("weapon_prop/strength",48);
		set("weapon_prop/karey",48);
		set("weapon_prop/percao",56);
		set("weapon_prop/dexerity",56);
		set("weapon_prop/constitution",48);
    set("weapon_prop/dodge", 48);
    set("weapon_prop/parry", 56);
    set("weapon_prop/attack", 56);
    set("weapon_prop/armor", 56);
    set("weapon_prop/defense", 55);
    
    set("weapon_prop/neili", 68);
    set("weapon_prop/qi", 74);
    set("weapon_prop/jing", 46);
    set("weapon_prop/jingli", 46);
    set("weapon_prop/damage", 64);

    set("wtypeA",14);
    set("wtypeB",13);
    set("wtypeC",11);
    set("wtypeD",6);
    set("wtypeE",6);
    set("wtypeF",6);
    set("wtypeG",6);
    set("wtypeH",6);
    set("wtypeI",6);
    set("wtypeJ",0);
    set("wtypeK",9);
    set("wtypeL",7);
    

                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 15);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	//set_amount(99);
	init_dagger(976);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";