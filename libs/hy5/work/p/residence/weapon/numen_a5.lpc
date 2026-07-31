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
	      set_name("[1;32m守护之靴[2;37;0m", ({ "general boots", "boots" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
		set("long", @LONG
圣母之靴[2;37;0m这是一双由相当坚硬的[33m软铁[2;37;0m加上[33m大麻[2;37;0m制成，重二斤一两五钱的[1;32m圣母之靴[2;37;0m。
综合评价[31m完美精致[2;37;0m 看起来相当坚固，具有[36m一般[2;37;0m的防护力！
上面刻了几个古符号：
[1;34m电[2;37;0m:[1;34m举世[2;37;0m 
上面还刻了一些符字：
坚硬:[32m粗糙[2;37;0m 天宇:[33m一般[2;37;0m 天渊:[33m一般[2;37;0m 巧制:[32m极差[2;37;0m 
长生:[34m细碎[2;37;0m 
以及一排古篆字【 [1;32m精灵[2;37;0m 】。和一些【 [1;32m杖法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "numen");
		set("ownername", "精灵");
		set("value", 2000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",9);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",6);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 34);
    set("armor_prop/defense", 24);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 21);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",8);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "staff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		


		set("material", "default");
    set("sharpness", 3);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";