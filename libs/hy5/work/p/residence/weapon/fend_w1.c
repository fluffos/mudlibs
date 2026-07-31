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
	set_weight(4410);
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
[2;37;0m这是一把由无比坚硬的[31m万年神铁[2;37;0m制成，重八斤八两二钱的[1;36m昆仑之剑[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比锋利，具有[1;36m斩妖伏魔[2;37;0m的威力！
上面刻了几个古符号：
[37m天[2;37;0m:[1;31m创世[2;37;0m [1;33m金[2;37;0m:[1;36m完美[2;37;0m [32m水[2;37;0m:[1;33m天圣[2;37;0m [33m土[2;37;0m:[1;31m创世[2;37;0m [1;35m风[2;37;0m:[1;32m魔王[2;37;0m 

上面还刻了一些符字：
锋利:[1;31m毁天[2;37;0m 天灵:[34m细碎[2;37;0m 天渊:[34m细碎[2;37;0m 巧制:[1;36m完美[2;37;0m 
白石:[31m精致[2;37;0m 长生:[1;36m完美[2;37;0m 
以及一排古篆字【 [1;32m方方[2;37;0m 】。和一些【 [1;32m内功[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "fend");
		set("ownername", "方方");
		set("value", 25000);
		set("weapon_prop/intelligence",56);
		set("weapon_prop/strength",40);
		set("weapon_prop/karey",56);
		set("weapon_prop/percao",40);
		set("weapon_prop/dexerity",40);
		set("weapon_prop/constitution",56);
    set("weapon_prop/dodge", 66);
    set("weapon_prop/parry", 48);
    set("weapon_prop/attack", 56);
    set("weapon_prop/armor", 74);
    set("weapon_prop/defense", 56);
    
    set("weapon_prop/neili", 56);
    set("weapon_prop/qi", 74);
    set("weapon_prop/jing", 56);
    set("weapon_prop/jingli", 56);
    set("weapon_prop/damage", 0);

    set("wtypeA",7);
    set("wtypeB",7);
    set("wtypeC",10);
    set("wtypeD",6);
    set("wtypeE",14);
    set("wtypeF",9);
    set("wtypeG",6);
    set("wtypeH",6);
    set("wtypeI",14);
    set("wtypeJ",7);
    set("wtypeK",7);
    set("wtypeL",7);
    

                set("skill", ([
                        "name": "force",
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
	
	init_sword(1191);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";