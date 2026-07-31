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
	set_name("[1;33m杏花飞[2;37;0m", ({ "kunlun sword", "sword" }));
	set_weight(11114);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[1;36m	笑江湖浪迹十年游，空负少年头。
	对铜陀巷泊，吟情渺渺，心事悠悠！ 
	酒令诗残梦断，南国正清愁。 
	把剑凄然望，无处招归舟。 
 
	明月天涯路远，问谁留楚佩，弄影中洲？
	数英雄儿女，俯仰古今愁。
	难消受灯昏罗帐，伥昙花一现恨难休！
	飘零惯，金戈铁马，拼葬荒丘！ 
[2;37;0m这是一把由无比坚硬的[37m玄铁[2;37;0m制成，重二十二斤二两二钱的[1;36m昆仑之剑[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比锋利，具有[1;31m天下无双[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[31m精致[2;37;0m [36m木[2;37;0m:[1;32m魔王[2;37;0m [31m火[2;37;0m:[1;31m无双[2;37;0m [1;35m风[2;37;0m:[1;36m完美[2;37;0m 
[1;37m雷[2;37;0m:[1;31m开元[2;37;0m 
上面还刻了一些符字：
锋利:[1;31m毁天[2;37;0m 绝代:[34m细碎[2;37;0m 体灵:[1;36m完美[2;37;0m 白石:[32m粗糙[2;37;0m 紫石:[32m粗糙[2;37;0m 长生:[31m精致[2;37;0m 威力:[1;36m完美[2;37;0m 
以及一排古篆字【 [1;32m香里小[2;37;0m 】。和一些【 [1;32m轻功[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "qing");
		set("ownername", "香里小");
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",28);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 34);
    set("weapon_prop/parry", 37);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 71);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 61);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 73);

    set("wtypeA",6);
    set("wtypeB",9);
    set("wtypeC",0);
    set("wtypeD",12);
    set("wtypeE",0);
    set("wtypeF",7);
    set("wtypeG",13);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "dodge",
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
	
	init_sword(1045);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";