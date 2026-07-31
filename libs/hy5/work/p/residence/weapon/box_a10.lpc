#include <ansi.h> 
#include <armor.h>

inherit BOOTS;

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

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[32m玄机之靴[2;37;0m", ({ "xuanji boots", "boots" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
		set("long", @LONG
[32m玄机之靴[2;37;0m这是一双由无比坚硬的[1;33m金铁[2;37;0m加上[1;33m木棉花[2;37;0m制成，重一斤五两二钱的[32m玄机之靴[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来无比坚固，具有[36m不小[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;33m天圣[2;37;0m [32m水[2;37;0m:[1;35m绝世[2;37;0m [31m火[2;37;0m:[1;31m无双[2;37;0m [33m土[2;37;0m:[1;32m魔王[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m开元[2;37;0m 巧制:[33m很高[2;37;0m 
白石:[33m很高[2;37;0m 闪电:[35m标准[2;37;0m 
长生:[34m细碎[2;37;0m 不老:[34m细碎[2;37;0m 
以及一排古篆字【 [1;32m万剑穿心[2;37;0m 】。和一些【 [1;32m刀法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "box");
		set("ownername", "万剑穿心");
		set("value", 16000);
		set("armor_prop/intelligence",32);
		set("armor_prop/strength",32);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",32);
    set("armor_prop/dodge", 42);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 54);


    set("armor_prop/armor", 269);
    set("armor_prop/defense", 32);
    
    set("armor_prop/neili", 40);
    set("armor_prop/qi", 25);
    set("armor_prop/jing", 20);
    set("armor_prop/jingli", 20);
    set("armor_prop/damage", 117);

    set("wtypeA",10);
    set("wtypeB",0);
    set("wtypeC",11);
    set("wtypeD",12);
    set("wtypeE",9);
    set("wtypeF",0);
    set("wtypeG",4);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",4);
    
    
                set("skill", ([
                        "name": "blade",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 13);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";