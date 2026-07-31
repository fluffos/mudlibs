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
	      set_name("[1;37m勤劳的双手[2;37;0m", ({ "lanhong hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
		set("long", @LONG
[36m蓝虹之手套[2;37;0m这是一副由十分坚硬的[1;37m软银[2;37;0m加上[1;33m木棉花[2;37;0m制成，重三斤三两一钱的[36m蓝虹之手套[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来十分坚固，具有[36m不小[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;34m举世[2;37;0m [32m水[2;37;0m:[1;32m魔王[2;37;0m [1;35m风[2;37;0m:[1;31m无双[2;37;0m 
[1;37m雷[2;37;0m:[1;32m魔王[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m无双[2;37;0m 巧制:[35m标准[2;37;0m 
白石:[33m很高[2;37;0m 紫石:[32m粗糙[2;37;0m 闪电:[34m细碎[2;37;0m 
长生:[35m标准[2;37;0m 威力:[34m细碎[2;37;0m 
以及一排古篆字【 [1;32m慕容人[2;37;0m 】。和一些【 [1;32m掌法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ebebeb");
		set("ownername", "慕容人");
		set("value", 16000);
		set("armor_prop/intelligence",32);
		set("armor_prop/strength",16);
		set("armor_prop/karey",8);
		set("armor_prop/percao",8);
		set("armor_prop/dexerity",16);
		set("armor_prop/constitution",24);
    set("armor_prop/dodge", 44);
    set("armor_prop/parry", 33);
    set("armor_prop/attack", 23);


    set("armor_prop/armor", 252);
    set("armor_prop/defense", 16);
    
    set("armor_prop/neili", 8);
    set("armor_prop/qi", 50);
    set("armor_prop/jing", 16);
    set("armor_prop/jingli", 24);
    set("armor_prop/damage", 767);

    set("wtypeA",8);
    set("wtypeB",1);
    set("wtypeC",9);
    set("wtypeD",3);
    set("wtypeE",1);
    set("wtypeF",12);
    set("wtypeG",9);
    set("wtypeH",1);
    set("wtypeI",4);
    set("wtypeJ",2);
    set("wtypeK",2);
    set("wtypeL",4);
    
    
                set("skill", ([
                        "name": "strike",
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