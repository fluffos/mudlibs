#include <ansi.h> 
#include <armor.h>

inherit WRISTS;

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
	      set_name("[37m绿玉之护腕[2;37;0m", ({ "luyu wrists", "wrists" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
		set("long", @LONG
[37m绿玉之护腕[2;37;0m这是一双由无比坚硬的[1;33m金铁[2;37;0m加上[32m玉蚕丝[2;37;0m制成，重四斤一两二钱的[37m绿玉之护腕[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来无比坚固，具有[36m不小[2;37;0m的防护力！
上面刻了几个古符号：
[37m天[2;37;0m:[31m精致[2;37;0m [33m土[2;37;0m:[31m精致[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m开元[2;37;0m 天灵:[34m细碎[2;37;0m 巧制:[35m标准[2;37;0m 

以及一排古篆字【 [1;32m史蒂芬周[2;37;0m 】。和一些【 [1;32m爪法[2;37;0m 】的技巧。

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
		set("armor_prop/intelligence",23);
		set("armor_prop/strength",8);
		set("armor_prop/karey",40);
		set("armor_prop/percao",16);
		set("armor_prop/dexerity",32);
		set("armor_prop/constitution",32);
    set("armor_prop/dodge", 16);
    set("armor_prop/parry", 40);
    set("armor_prop/attack", 40);


    set("armor_prop/armor", 411);
    set("armor_prop/defense", 8);
    
    set("armor_prop/neili", 24);
    set("armor_prop/qi", 48);
    set("armor_prop/jing", 48);
    set("armor_prop/jingli", 32);
    set("armor_prop/damage", 233);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",6);
    set("wtypeF",4);
    set("wtypeG",6);
    set("wtypeH",0);
    set("wtypeI",6);
    set("wtypeJ",6);
    set("wtypeK",5);
    set("wtypeL",2);
    
    
                set("skill", ([
                        "name": "claw",
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