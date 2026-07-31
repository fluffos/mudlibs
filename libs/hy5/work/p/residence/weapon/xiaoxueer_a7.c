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
	      set_name("[37m红玉之靴[2;37;0m", ({ "hongyu boots", "boots" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
		set("long", @LONG
[37m红玉之靴[2;37;0m这是一双由极其坚硬的[1;33m金铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重五斤六两零钱的[37m红玉之靴[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来极其坚固，具有[36m不小[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;32m魔王[2;37;0m [31m火[2;37;0m:[1;34m举世[2;37;0m [1;35m风[2;37;0m:[33m很高[2;37;0m 
[1;37m雷[2;37;0m:[31m精致[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m开元[2;37;0m 天宇:[34m细碎[2;37;0m 巧制:[32m粗糙[2;37;0m 
紫石:[34m细碎[2;37;0m 周天:[33m很高[2;37;0m 长生:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m小雪儿[2;37;0m 】。和一些【 [1;32m杖法[2;37;0m 】的技巧。

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
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",22);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 23);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 161);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 47);
    set("armor_prop/qi", 30);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",9);
    set("wtypeB",3);
    set("wtypeC",2);
    set("wtypeD",8);
    set("wtypeE",0);
    set("wtypeF",4);
    set("wtypeG",6);
    set("wtypeH",3);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",1);
    
    
                set("skill", ([
                        "name": "staff",
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