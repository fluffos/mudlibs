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
	      set_name("[1;35m愈心披风[2;37;0m", ({ "bad armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
巨之披风[2;37;0m这是一件由比较坚硬的[32m青铜[2;37;0m加上[1;37m棉花[2;37;0m制成，重一斤三两四钱的[1;35m巨之披风[2;37;0m。
综合评价[32m精致细美[2;37;0m 看起来比较坚固，具有[36m一般[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[33m很高[2;37;0m [31m火[2;37;0m:[31m精致[2;37;0m [1;35m风[2;37;0m:[31m精致[2;37;0m 
[1;37m雷[2;37;0m:[33m很高[2;37;0m [37m天[2;37;0m:[31m精致[2;37;0m [1;36m人[2;37;0m:[34m细碎[2;37;0m 
上面还刻了一些符字：
坚硬:[34m细碎[2;37;0m 绝代:[32m极差[2;37;0m 巧制:[32m极差[2;37;0m 
周天:[32m极差[2;37;0m 不老:[32m极差[2;37;0m 
以及一排古篆字【 [1;32m云冰翎[2;37;0m 】。和一些【 [1;32m剑法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "spray");
		set("ownername", "云冰翎");
		set("value", 2000);
		set("armor_prop/intelligence",72);
		set("armor_prop/strength",72);
		set("armor_prop/karey",0);
		set("armor_prop/percao",3);
		set("armor_prop/dexerity",72);
		set("armor_prop/constitution",72);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 166);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 5);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 3);
    set("armor_prop/jingli", 3);
    set("armor_prop/damage", 0);

    set("wtypeA",4);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",6);
    set("wtypeE",0);
    set("wtypeF",6);
    set("wtypeG",4);
    set("wtypeH",0);
    set("wtypeI",6);
    set("wtypeJ",0);
    set("wtypeK",9);
    set("wtypeL",9);
    
    
                set("skill", ([
                        "name": "sword",
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