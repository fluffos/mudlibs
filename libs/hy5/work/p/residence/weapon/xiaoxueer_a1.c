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
	      set_name("[1;32m无影之手套[2;37;0m", ({ "wuying hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
		set("long", @LONG
[1;32m无影之手套[2;37;0m这是一副由无比坚硬的[1;33m金铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重三斤四两六钱的[1;32m无影之手套[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来无比坚固，具有[36m不小[2;37;0m的防护力！
上面刻了几个古符号：
[32m水[2;37;0m:[1;32m魔王[2;37;0m [1;35m风[2;37;0m:[1;31m无双[2;37;0m 
[1;37m雷[2;37;0m:[1;32m魔王[2;37;0m [1;34m电[2;37;0m:[1;31m无双[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m开元[2;37;0m 天宇:[34m细碎[2;37;0m 巧制:[35m标准[2;37;0m 
紫石:[34m细碎[2;37;0m 闪电:[35m标准[2;37;0m 
长生:[32m粗糙[2;37;0m 威力:[34m细碎[2;37;0m 
以及一排古篆字【 [1;32m小雪儿[2;37;0m 】。和一些【 [1;32m腿法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "xiaoxueer");
		set("ownername", "小雪儿");
		set("value", 16000);
		set("armor_prop/intelligence",40);
		set("armor_prop/strength",21);
		set("armor_prop/karey",40);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",40);
    set("armor_prop/dodge", 48);
    set("armor_prop/parry", 26);
    set("armor_prop/attack", 52);


    set("armor_prop/armor", 325);
    set("armor_prop/defense", 40);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 40);
    set("armor_prop/jing", 48);
    set("armor_prop/jingli", 48);
    set("armor_prop/damage", 887);

    set("wtypeA",6);
    set("wtypeB",5);
    set("wtypeC",9);
    set("wtypeD",6);
    set("wtypeE",5);
    set("wtypeF",12);
    set("wtypeG",9);
    set("wtypeH",12);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",1);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "leg",
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