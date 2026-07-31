#include <ansi.h> 
#include <armor.h>

inherit WAIST;

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
	      set_name("[36m蓝虹之腰带[2;37;0m", ({ "lanhong waist", "waist" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
		set("long", @LONG
[36m蓝虹之腰带[2;37;0m这是一条由无比坚硬的[1;37m软银[2;37;0m加上[1;33m木棉花[2;37;0m制成，重一斤四两五钱的[36m蓝虹之腰带[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来无比坚固，具有[36m不小[2;37;0m的防护力！
上面刻了几个古符号：
[37m天[2;37;0m:[1;35m绝世[2;37;0m [1;36m人[2;37;0m:[1;36m完美[2;37;0m [1;31m魔[2;37;0m:[1;34m举世[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m无双[2;37;0m 天宇:[34m细碎[2;37;0m 天渊:[34m细碎[2;37;0m 巧制:[36m不错[2;37;0m 

以及一排古篆字【 [1;32m史蒂芬周[2;37;0m 】。和一些【 [1;32m手法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "xianoda");
		set("ownername", "史蒂芬周");
		set("value", 16000);
		set("armor_prop/intelligence",24);
		set("armor_prop/strength",48);
		set("armor_prop/karey",16);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",20);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 32);
    set("armor_prop/parry", 48);
    set("armor_prop/attack", 24);


    set("armor_prop/armor", 420);
    set("armor_prop/defense", 40);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 40);
    set("armor_prop/jing", 40);
    set("armor_prop/jingli", 48);
    set("armor_prop/damage", 235);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",4);
    set("wtypeF",5);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",11);
    set("wtypeJ",0);
    set("wtypeK",7);
    set("wtypeL",8);
    
    
                set("skill", ([
                        "name": "hand",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 12);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";