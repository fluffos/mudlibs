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
	      set_name("[35m降神护腕[2;37;0m", ({ "general wrists", "wrists" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
		set("long", @LONG
黑云之护腕[2;37;0m这是一双由极其坚硬的[33m软铁[2;37;0m加上[33m大麻[2;37;0m制成，重二斤八两九钱的[35m黑云之护腕[2;37;0m。
综合评价[31m完美精致[2;37;0m 看起来极其坚固，具有[36m一般[2;37;0m的防护力！
上面刻了几个古符号：
[32m水[2;37;0m:[1;36m完美[2;37;0m [31m火[2;37;0m:[1;34m举世[2;37;0m 
上面还刻了一些符字：
坚硬:[33m很高[2;37;0m 天渊:[32m极差[2;37;0m 巧制:[36m不错[2;37;0m 
闪电:[34m细碎[2;37;0m 
不老:[36m不错[2;37;0m 威力:[36m不错[2;37;0m 
以及一排古篆字【 [1;32m方舟[2;37;0m 】。和一些【 [1;32m轻功[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "boat");
		set("ownername", "方舟");
		set("value", 2000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",5);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 20);


    set("armor_prop/armor", 31);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 16);
    set("armor_prop/jingli", 16);
    set("armor_prop/damage", 19);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",7);
    set("wtypeD",8);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "dodge",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		


		set("material", "default");
    set("sharpness", 4);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";