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
	set_name("[31m巨阙之暗器[2;37;0m★", ({ "juque throwing", "throwing" }));
	set_weight(576);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", @LONG
[31m巨阙坚硬无比，能开天辟地，荡妖除魔！
[2;37;0m这是一支由无比坚硬的[1;37m软银[2;37;0m制成，重一斤一两五钱的[31m巨阙之暗器[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比锋利，具有[1;33m举世无匹[2;37;0m的威力！
上面刻了几个古符号：
[32m水[2;37;0m:[1;36m完美[2;37;0m [31m火[2;37;0m:[1;35m绝世[2;37;0m [1;37m雷[2;37;0m:[1;35m绝世[2;37;0m [37m天[2;37;0m:[31m精致[2;37;0m [40m地[2;37;0m:[1;31m毁天[2;37;0m [1;31m魔[2;37;0m:[1;31m无双[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 天宇:[32m粗糙[2;37;0m 绝代:[33m很高[2;37;0m 白石:[1;36m完美[2;37;0m 闪电:[35m标准[2;37;0m 


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
		set("weapon_prop/strength",36);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",46);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 76);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 53);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",7);
    set("wtypeD",11);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",11);
    set("wtypeH",0);
    set("wtypeI",6);
    set("wtypeJ",15);
    set("wtypeK",0);
    set("wtypeL",12);
    

                set("skill", ([
                        "name": "club",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 25);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	set_amount(1);
	init_throwing(876);
	setup();
}



#include "/obj/ritem/weaponzy.h";