// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit BLADE;

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
	set_name("[1;31m龙牙[2;37;0m", ({ "shentong blade", "blade" }));
	set_weight(16535);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", @LONG
[1;31m天兵神通，走势要平善，气要随行，两眼顾尖，气沉两足稳，
身法需自然，身行如飞燕，身落如停风，收如花絮，刺如钢钉！
[2;37;0m这是一柄由极为坚硬的[37m玄铁[2;37;0m制成，重三十三斤零两七钱的[1;31m神通之刀[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来极为锋利，具有[1;31m天下无双[2;37;0m的威力！
上面刻了几个古符号：
[37m天[2;37;0m:[1;32m魔王[2;37;0m [1;36m人[2;37;0m:[1;31m无双[2;37;0m [1;31m魔[2;37;0m:[31m精致[2;37;0m [1;33m金[2;37;0m:[35m标准[2;37;0m [36m木[2;37;0m:[31m精致[2;37;0m [31m火[2;37;0m:[1;34m举世[2;37;0m [1;35m风[2;37;0m:[35m标准[2;37;0m 
[1;37m雷[2;37;0m:[1;34m举世[2;37;0m 
上面还刻了一些符字：
锋利:[1;31m毁天[2;37;0m 天渊:[34m细碎[2;37;0m 巧制:[33m很高[2;37;0m 
体灵:[31m精致[2;37;0m 白石:[1;36m完美[2;37;0m 长生:[1;36m完美[2;37;0m 
以及一排古篆字【 [1;32m地图一号[2;37;0m 】。和一些【 [1;32m内功[2;37;0m 】的技巧。

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
		set("weapon_prop/intelligence",48);
		set("weapon_prop/strength",48);
		set("weapon_prop/karey",48);
		set("weapon_prop/percao",48);
		set("weapon_prop/dexerity",48);
		set("weapon_prop/constitution",48);
    set("weapon_prop/dodge", 70);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 48);
    set("weapon_prop/armor", 42);
    set("weapon_prop/defense", 69);
    
    set("weapon_prop/neili", 48);
    set("weapon_prop/qi", 72);
    set("weapon_prop/jing", 48);
    set("weapon_prop/jingli", 48);
    set("weapon_prop/damage", 0);

    set("wtypeA",6);
    set("wtypeB",6);
    set("wtypeC",6);
    set("wtypeD",8);
    set("wtypeE",0);
    set("wtypeF",6);
    set("wtypeG",8);
    set("wtypeH",0);
    set("wtypeI",9);
    set("wtypeJ",0);
    set("wtypeK",12);
    set("wtypeL",6);
    

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
	
	init_blade(1302);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";