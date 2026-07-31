#include <ansi.h> 
#include <armor.h>

inherit SHIELD;

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
	      set_name("[1;37m月之护盾[2;37;0m", ({ "general shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
		set("long", @LONG
登龙之盾[2;37;0m这是一面由无比坚硬的[33m软铁[2;37;0m加上[33m大麻[2;37;0m制成，重六斤九两五钱的[1;37m登龙之盾[2;37;0m。
综合评价[31m完美精致[2;37;0m 看起来无比坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[40m地[2;37;0m:[1;34m举世[2;37;0m [36m木[2;37;0m:[31m精致[2;37;0m [1;34m电[2;37;0m:[33m很高[2;37;0m 
上面还刻了一些符字：
坚硬:[33m很高[2;37;0m 福源:[32m极差[2;37;0m 
天玄:[33m一般[2;37;0m 巧制:[32m极差[2;37;0m 
白石:[33m一般[2;37;0m 不老:[36m不错[2;37;0m 
以及一排古篆字【 [1;32m小辫子[2;37;0m 】。和一些【 [1;32m鞭法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "change");
		set("ownername", "小辫子");
		set("value", 2000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",4);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",8);
    set("armor_prop/dodge", 8);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 137);
    set("armor_prop/defense", 16);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 14);
    set("armor_prop/jingli", 14);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",6);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",4);
    set("wtypeI",0);
    set("wtypeJ",8);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "whip",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		


		set("material", "default");
    set("sharpness", 4);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";