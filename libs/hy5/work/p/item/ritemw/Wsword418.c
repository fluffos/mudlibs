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
	set_name("[1;31m神通之剑[2;37;0m", ({ "shentong sword", "sword" }));
	set_weight(5995);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[1;31m天兵神通，走势要平善，气要随行，两眼顾尖，气沉两足稳，
身法需自然，身行如飞燕，身落如停风，收如花絮，刺如钢钉！
[2;37;0m这是一把由绝对坚硬的[31m流花石[2;37;0m制成，重十一斤九两九钱的[1;31m神通之剑[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来绝对锋利，具有[1;33m举世无匹[2;37;0m的威力！
上面刻了几个古符号：
[40m地[2;37;0m:[1;36m完美[2;37;0m [1;36m人[2;37;0m:[1;31m创世[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 绝代:[34m细碎[2;37;0m 天渊:[34m细碎[2;37;0m 天玄:[34m细碎[2;37;0m 闪电:[35m标准[2;37;0m 
威力:[32m粗糙[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",29);
		set("weapon_prop/dexerity",29);
		set("weapon_prop/constitution",29);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 57);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 32);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",7);
    set("wtypeK",14);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "throwing",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 19);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(832);
	setup();
}



#include "/obj/ritem/weaponzy.h";