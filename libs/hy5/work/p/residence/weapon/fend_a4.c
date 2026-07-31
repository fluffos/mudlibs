#include <ansi.h> 
#include <armor.h>

inherit ARMOR;

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
	      set_name("[1;32m无极之披风[2;37;0m", ({ "wuji armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
[1;32m此物已达出神入化，登峰造极，神乎其神之境界！俗说万物归宗，便是这“无极”！
[2;37;0m这是一件由相当坚硬的[31m万年神铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重五斤七两八钱的[1;32m无极之披风[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来相当坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;31m创世[2;37;0m [36m木[2;37;0m:[31m精致[2;37;0m [32m水[2;37;0m:[35m标准[2;37;0m [31m火[2;37;0m:[35m标准[2;37;0m [1;35m风[2;37;0m:[1;31m开元[2;37;0m 

上面还刻了一些符字：
坚硬:[1;31m毁天[2;37;0m 巧制:[34m细碎[2;37;0m 
长生:[33m很高[2;37;0m 不老:[35m标准[2;37;0m 威力:[31m精致[2;37;0m 
以及一排古篆字【 [1;32m方方[2;37;0m 】。和一些【 [1;32m轻功[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "fend");
		set("ownername", "方方");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",56);
		set("armor_prop/karey",48);
		set("armor_prop/percao",56);
		set("armor_prop/dexerity",56);
		set("armor_prop/constitution",56);
    set("armor_prop/dodge", 56);
    set("armor_prop/parry", 56);
    set("armor_prop/attack", 48);


    set("armor_prop/armor", 472);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 46);
    set("armor_prop/jing", 50);
    set("armor_prop/jingli", 50);
    set("armor_prop/damage", 400);

    set("wtypeA",14);
    set("wtypeB",6);
    set("wtypeC",5);
    set("wtypeD",5);
    set("wtypeE",5);
    set("wtypeF",13);
    set("wtypeG",5);
    set("wtypeH",6);
    set("wtypeI",4);
    set("wtypeJ",6);
    set("wtypeK",6);
    set("wtypeL",13);
    
    
                set("skill", ([
                        "name": "dodge",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 15);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";