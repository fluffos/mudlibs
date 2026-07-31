#include <ansi.h> 
#include <armor.h>

inherit HANDS;

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
	      set_name("[1;37m狂狼之手套[2;37;0m", ({ "good hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
		set("long", @LONG
狂狼之手套[2;37;0m这是一副由非常坚硬的[31m流花石[2;37;0m加上[33m亚麻[2;37;0m制成，重五斤九两三钱的[1;37m狂狼之手套[2;37;0m。
综合评价[1;34m举世罕见[2;37;0m 看起来非常坚固，具有[36m一般[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;33m天圣[2;37;0m [33m土[2;37;0m:[35m标准[2;37;0m [1;37m雷[2;37;0m:[1;34m举世[2;37;0m [1;34m电[2;37;0m:[1;34m举世[2;37;0m 
上面还刻了一些符字：
坚硬:[1;32m魔王[2;37;0m 天灵:[36m不错[2;37;0m 福源:[36m不错[2;37;0m 
巧制:[32m粗糙[2;37;0m 
体灵:[36m不错[2;37;0m 长生:[36m不错[2;37;0m 威力:[36m不错[2;37;0m 
以及一排古篆字【 [1;32m大先生[2;37;0m 】。和一些【 [1;32m斧法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "wxswlh");
		set("ownername", "大先生");
		set("value", 9000);
		set("armor_prop/intelligence",18);
		set("armor_prop/strength",32);
		set("armor_prop/karey",13);
		set("armor_prop/percao",40);
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",40);
    set("armor_prop/dodge", 32);
    set("armor_prop/parry", 8);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 941);
    set("armor_prop/defense", 18);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 17);
    set("armor_prop/jing", 16);
    set("armor_prop/jingli", 24);
    set("armor_prop/damage", 688);

    set("wtypeA",10);
    set("wtypeB",3);
    set("wtypeC",2);
    set("wtypeD",1);
    set("wtypeE",5);
    set("wtypeF",0);
    set("wtypeG",8);
    set("wtypeH",8);
    set("wtypeI",5);
    set("wtypeJ",0);
    set("wtypeK",2);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "axe",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		


		set("material", "default");
    set("sharpness", 18);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";