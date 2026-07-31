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
	set_name("[1;36m昆仑之剑[2;37;0m", ({ "kunlun sword", "sword" }));
	set_weight(12618);
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
[2;37;0m这是一把由无比坚硬的[37m玄铁[2;37;0m制成，重二十五斤二两三钱的[1;36m昆仑之剑[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比锋利，具有[1;31m天下无双[2;37;0m的威力！
上面刻了几个古符号：
[37m天[2;37;0m:[1;34m举世[2;37;0m [40m地[2;37;0m:[1;35m绝世[2;37;0m [1;31m魔[2;37;0m:[1;34m举世[2;37;0m [36m木[2;37;0m:[1;33m天圣[2;37;0m [33m土[2;37;0m:[1;33m天圣[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 绝代:[34m细碎[2;37;0m 巧制:[32m粗糙[2;37;0m 
白石:[32m粗糙[2;37;0m 紫石:[35m标准[2;37;0m 闪电:[32m粗糙[2;37;0m 
周天:[32m粗糙[2;37;0m 不老:[35m标准[2;37;0m 威力:[33m很高[2;37;0m 
以及一排古篆字【 [1;32m团团圆圆[2;37;0m 】。和一些【 [1;32m鞭法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ttyy");
		set("ownername", "团团圆圆");
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",25);
		set("weapon_prop/dexerity",48);
		set("weapon_prop/constitution",48);
    set("weapon_prop/dodge", 32);
    set("weapon_prop/parry", 54);
    set("weapon_prop/attack", 31);
    set("weapon_prop/armor", 34);
    set("weapon_prop/defense", 56);
    
    set("weapon_prop/neili", 36);
    set("weapon_prop/qi", 48);
    set("weapon_prop/jing", 52);
    set("weapon_prop/jingli", 52);
    set("weapon_prop/damage", 43);

    set("wtypeA",0);
    set("wtypeB",10);
    set("wtypeC",0);
    set("wtypeD",6);
    set("wtypeE",10);
    set("wtypeF",6);
    set("wtypeG",0);
    set("wtypeH",6);
    set("wtypeI",8);
    set("wtypeJ",11);
    set("wtypeK",4);
    set("wtypeL",8);
    

                set("skill", ([
                        "name": "whip",
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
	
	init_sword(1287);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";