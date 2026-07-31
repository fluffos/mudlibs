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
	      set_name("[33m瑶池之盾[2;37;0m", ({ "yaochi shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
		set("long", @LONG
[33m瑶池之盾[2;37;0m这是一面由无比坚硬的[1;33m金铁[2;37;0m加上[32m玉蚕丝[2;37;0m制成，重十二斤一两九钱的[33m瑶池之盾[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来无比坚固，具有[32m水准以上[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[31m精致[2;37;0m [36m木[2;37;0m:[1;35m绝世[2;37;0m [31m火[2;37;0m:[1;33m天圣[2;37;0m [33m土[2;37;0m:[1;32m魔王[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m开元[2;37;0m 巧制:[34m细碎[2;37;0m 
白石:[33m很高[2;37;0m 紫石:[35m标准[2;37;0m 闪电:[33m很高[2;37;0m 
周天:[36m不错[2;37;0m 
以及一排古篆字【 [1;32m团团圆圆[2;37;0m 】。和一些【 [1;32m内功[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ttyy");
		set("ownername", "团团圆圆");
		set("value", 16000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",48);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 44);
    set("armor_prop/parry", 51);
    set("armor_prop/attack", 42);


    set("armor_prop/armor", 393);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 17);
    set("armor_prop/qi", 48);
    set("armor_prop/jing", 48);
    set("armor_prop/jingli", 48);
    set("armor_prop/damage", 0);

    set("wtypeA",6);
    set("wtypeB",11);
    set("wtypeC",6);
    set("wtypeD",10);
    set("wtypeE",9);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",6);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "force",
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