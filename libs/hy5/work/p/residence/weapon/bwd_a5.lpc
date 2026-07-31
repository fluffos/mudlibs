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
	      set_name("[37m红玉之手套[2;37;0m", ({ "hongyu hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
		set("long", @LONG
[37m红玉之手套[2;37;0m这是一副由极其坚硬的[1;33m金铁[2;37;0m加上[32m玉蚕丝[2;37;0m制成，重六斤五两零钱的[37m红玉之手套[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来极其坚固，具有[36m不小[2;37;0m的防护力！
上面刻了几个古符号：
[1;31m魔[2;37;0m:[1;36m完美[2;37;0m [36m木[2;37;0m:[1;32m魔王[2;37;0m [33m土[2;37;0m:[31m精致[2;37;0m [1;35m风[2;37;0m:[1;32m魔王[2;37;0m 

上面还刻了一些符字：
坚硬:[1;31m开元[2;37;0m 巧制:[33m很高[2;37;0m 
紫石:[34m细碎[2;37;0m 闪电:[36m不错[2;37;0m 
周天:[33m很高[2;37;0m 长生:[35m标准[2;37;0m 威力:[34m细碎[2;37;0m 
以及一排古篆字【 [1;32m宋江[2;37;0m 】。和一些【 [1;32m锤法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "bwd");
		set("ownername", "宋江");
		set("value", 16000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 22);
    set("armor_prop/attack", 16);


    set("armor_prop/armor", 84);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 45);
    set("armor_prop/qi", 55);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 606);

    set("wtypeA",0);
    set("wtypeB",9);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",6);
    set("wtypeF",9);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",7);
    
    
                set("skill", ([
                        "name": "hammer",
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