#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

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
	      set_name("[1;34m巧之服装[2;37;0m", ({ "bad cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
巧之服装[2;37;0m这是一件由非常坚硬的[32m青铜[2;37;0m加上[1;37m棉花[2;37;0m制成，重一斤九两二钱的[1;34m巧之服装[2;37;0m。
综合评价[32m精致细美[2;37;0m 看起来非常坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[35m标准[2;37;0m [32m水[2;37;0m:[31m精致[2;37;0m [33m土[2;37;0m:[33m很高[2;37;0m 
上面还刻了一些符字：
坚硬:[34m细碎[2;37;0m 福源:[32m极差[2;37;0m 
天渊:[33m一般[2;37;0m 巧制:[32m极差[2;37;0m 
白石:[32m极差[2;37;0m 
以及一排古篆字【 [1;32m褚禄霸[2;37;0m 】。和一些【 [1;32m鞭法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "pdckmxkdsss");
		set("ownername", "褚禄霸");
		set("value", 2000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",5);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",7);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 1);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 140);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",5);
    set("wtypeB",0);
    set("wtypeC",6);
    set("wtypeD",0);
    set("wtypeE",4);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "whip",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		


		set("material", "default");
    set("sharpness", 2);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";