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
	set_name("[1;37m离别钩[2;37;0m", ({ "fengyun dagger", "dagger" }));
	set_weight(15550);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[1;35m所谓风云际会，天地变色！仗此行千里，老魔小丑，岂堪一击！
[2;37;0m这是一把由极为坚硬的[37m玄铁[2;37;0m制成，重三十一斤一两零钱的[1;35m风云之匕首[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来极为锋利，具有[1;35m绝世罕见[2;37;0m的威力！
上面刻了几个古符号：
[32m水[2;37;0m:[35m标准[2;37;0m [31m火[2;37;0m:[1;31m创世[2;37;0m [1;35m风[2;37;0m:[1;31m开元[2;37;0m 
[1;37m雷[2;37;0m:[1;34m举世[2;37;0m [1;34m电[2;37;0m:[1;33m天圣[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 天灵:[32m粗糙[2;37;0m 绝代:[32m粗糙[2;37;0m 体灵:[31m精致[2;37;0m 紫石:[35m标准[2;37;0m 闪电:[35m标准[2;37;0m 

以及一排古篆字【 [1;32m段药师[2;37;0m 】。和一些【 [1;32m掌法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "yellow");
		set("ownername", "段药师");
		set("value", 25000);
		set("weapon_prop/intelligence",56);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",30);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 58);
    set("weapon_prop/attack", 58);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 67);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",5);
    set("wtypeD",14);
    set("wtypeE",0);
    set("wtypeF",13);
    set("wtypeG",8);
    set("wtypeH",10);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "strike",
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
	
	init_dagger(931);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";