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
	      set_name("[34m弦月之靴[2;37;0m", ({ "good boots", "boots" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
		set("long", @LONG
弦月之靴[2;37;0m这是一双由极其坚硬的精钢加上[33m大麻[2;37;0m制成，重一斤三两八钱的[34m弦月之靴[2;37;0m。
综合评价[1;34m举世罕见[2;37;0m 看起来极其坚固，具有[36m一般[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;34m举世[2;37;0m [33m土[2;37;0m:[31m精致[2;37;0m [1;34m电[2;37;0m:[31m精致[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m天圣[2;37;0m 巧制:[34m细碎[2;37;0m 
体灵:[32m粗糙[2;37;0m 不老:[36m不错[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 9000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 47);
    set("armor_prop/defense", 35);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 13);
    set("armor_prop/jingli", 13);
    set("armor_prop/damage", 0);

    set("wtypeA",8);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",6);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",6);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "blade",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		


		set("material", "default");
    set("sharpness", 10);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";