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
	set_name("[31m龙泉之暗器[2;37;0m★", ({ "longquan throwing", "throwing" }));
	set_weight(644);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", @LONG
[31m龙泉人间极品，武林至宝！
[2;37;0m这是一支由无比坚硬的[1;37m软银[2;37;0m制成，重一斤二两八钱的[31m龙泉之暗器[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比锋利，具有[1;31m开元创世[2;37;0m的威力！
上面刻了几个古符号：
[32m水[2;37;0m:[1;34m举世[2;37;0m [31m火[2;37;0m:[1;31m开元[2;37;0m [1;34m电[2;37;0m:[1;31m创世[2;37;0m [37m天[2;37;0m:[1;31m开元[2;37;0m [40m地[2;37;0m:[31m精致[2;37;0m [1;36m人[2;37;0m:[1;36m完美[2;37;0m [1;31m魔[2;37;0m:[1;31m毁天[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 福源:[33m很高[2;37;0m 
绝代:[33m很高[2;37;0m 天渊:[33m很高[2;37;0m 体灵:[35m标准[2;37;0m 白石:[31m精致[2;37;0m 周天:[35m标准[2;37;0m 不老:[1;36m完美[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 36000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",45);
		set("weapon_prop/percao",44);
		set("weapon_prop/dexerity",42);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 66);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 57);
    
    set("weapon_prop/neili", 53);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 77);
    set("weapon_prop/jingli", 77);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",8);
    set("wtypeD",13);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",14);
    set("wtypeI",13);
    set("wtypeJ",6);
    set("wtypeK",7);
    set("wtypeL",15);
    

                set("skill", ([
                        "name": "strike",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 27);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	set_amount(1);
	init_throwing(1415);
	setup();
}



#include "/obj/ritem/weaponzy.h";