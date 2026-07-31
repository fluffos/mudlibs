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
	set_name("[1;33m杏花飞[2;37;0m", ({ "taibai sword", "sword" }));
	set_weight(4424);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", @LONG
[1;37m
		赵客缦胡缨  吴钩霜雪明		银鞍照白马  飒沓如流星
		十步杀一人  千里不留行		事了拂衣去  深藏身与名
		闲过信陵饮  脱剑膝前横		将炙□朱亥  持觞劝侯嬴
		三杯吐然诺  五狱倒为轻		眼花耳热後  意气素霓生
		救赵挥金槌  邯郸先震惊		千秋二壮士  喧赫大梁城
		纵死侠骨香  不惭世上英		谁能书阁下  白首太玄经
[2;37;0m这是一把由无比坚硬的[37m玄铁[2;37;0m制成，重八斤八两四钱的[1;37m太白之剑[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比锋利，具有[1;34m倚天屠龙[2;37;0m的威力！
上面刻了几个古符号：
[36m木[2;37;0m:[1;31m无双[2;37;0m [32m水[2;37;0m:[1;36m完美[2;37;0m [31m火[2;37;0m:[1;31m开元[2;37;0m [33m土[2;37;0m:[1;31m开元[2;37;0m [1;35m风[2;37;0m:[1;35m绝世[2;37;0m 

上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 福源:[34m细碎[2;37;0m 
白石:[35m标准[2;37;0m 紫石:[31m精致[2;37;0m 长生:[31m精致[2;37;0m 不老:[32m粗糙[2;37;0m 
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
		set("weapon_prop/karey",28);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 51);
    set("weapon_prop/parry", 63);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 60);
    set("weapon_prop/jing", 38);
    set("weapon_prop/jingli", 38);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",12);
    set("wtypeC",7);
    set("wtypeD",13);
    set("wtypeE",13);
    set("wtypeF",11);
    set("wtypeG",0);
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
    set("sharpness", 16);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(666);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";