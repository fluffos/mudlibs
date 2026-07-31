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
	set_name("[1;31m诛仙[2;37;0m", ({ "shentong sword", "sword" }));
	set_weight(16129);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[1;31m天兵神通，走势要平善，气要随行，两眼顾尖，气沉两足稳，
身法需自然，身行如飞燕，身落如停风，收如花絮，刺如钢钉！
[2;37;0m这是一把由相当坚硬的[37m玄铁[2;37;0m制成，重三十二斤二两五钱的[1;31m神通之剑[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来相当锋利，具有[1;34m倚天屠龙[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;31m无双[2;37;0m [36m木[2;37;0m:[1;36m完美[2;37;0m [31m火[2;37;0m:[1;35m绝世[2;37;0m [1;35m风[2;37;0m:[1;35m绝世[2;37;0m 

上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 天宇:[32m粗糙[2;37;0m 白石:[34m细碎[2;37;0m 闪电:[31m精致[2;37;0m 
周天:[35m标准[2;37;0m 
以及一排古篆字【 [1;32m欧阳不封[2;37;0m 】。和一些【 [1;32m爪法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "green");
		set("ownername", "欧阳不封");
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",35);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 27);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 66);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 59);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",12);
    set("wtypeB",7);
    set("wtypeC",0);
    set("wtypeD",11);
    set("wtypeE",0);
    set("wtypeF",11);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "claw",
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
	
	init_sword(731);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";