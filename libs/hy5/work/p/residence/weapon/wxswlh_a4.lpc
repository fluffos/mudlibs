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
	      set_name("[31m戈壁之披风[2;37;0m", ({ "general armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
戈壁之披风[2;37;0m这是一件由无比坚硬的[1;32m绿石[2;37;0m加上[33m大麻[2;37;0m制成，重二斤八两二钱的[31m戈壁之披风[2;37;0m。
综合评价[31m完美精致[2;37;0m 看起来无比坚固，具有[36m一般[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[34m细碎[2;37;0m [36m木[2;37;0m:[33m很高[2;37;0m [33m土[2;37;0m:[35m标准[2;37;0m [37m天[2;37;0m:[1;34m举世[2;37;0m [40m地[2;37;0m:[34m细碎[2;37;0m 
上面还刻了一些符字：
坚硬:[31m精致[2;37;0m 天灵:[33m一般[2;37;0m 天玄:[33m一般[2;37;0m 巧制:[32m极差[2;37;0m 
周天:[32m极差[2;37;0m 
以及一排古篆字【 [1;32m大先生[2;37;0m 】。和一些【 [1;32m指法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "wxswlh");
		set("ownername", "大先生");
		set("value", 2000);
		set("armor_prop/intelligence",9);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",6);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 63);
    set("armor_prop/defense", 8);
    
    set("armor_prop/neili", 3);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",2);
    set("wtypeB",4);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",5);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",8);
    set("wtypeJ",2);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "finger",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		


		set("material", "default");
    set("sharpness", 6);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";