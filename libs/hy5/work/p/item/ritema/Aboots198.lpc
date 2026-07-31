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
	      set_name("[1;37m苍岩之靴[2;37;0m", ({ "general boots", "boots" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
		set("long", @LONG
苍岩之靴[2;37;0m这是一双由无比坚硬的精钢加上[33m亚麻[2;37;0m制成，重一斤二两二钱的[1;37m苍岩之靴[2;37;0m。
综合评价[31m完美精致[2;37;0m 看起来无比坚固，具有[36m一般[2;37;0m的防护力！
上面刻了几个古符号：
[40m地[2;37;0m:[1;34m举世[2;37;0m 
上面还刻了一些符字：
坚硬:[35m标准[2;37;0m 天灵:[32m极差[2;37;0m 天宇:[32m极差[2;37;0m 巧制:[36m不错[2;37;0m 
体灵:[36m不错[2;37;0m 紫石:[33m一般[2;37;0m 周天:[32m极差[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 2000);
		set("armor_prop/intelligence",2);
		set("armor_prop/strength",5);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 6);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 27);
    set("armor_prop/defense", 18);
    
    set("armor_prop/neili", 2);
    set("armor_prop/qi", 0);
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
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",8);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "hammer",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		


		set("material", "default");
    set("sharpness", 5);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";