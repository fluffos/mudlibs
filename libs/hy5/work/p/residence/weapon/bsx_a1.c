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
	      set_name("[36m绿虹之手套[2;37;0m", ({ "luhong hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
		set("long", @LONG
[36m绿虹之手套[2;37;0m这是一副由绝对坚硬的[1;33m金铁[2;37;0m加上[1;33m木棉花[2;37;0m制成，重五斤七两零钱的[36m绿虹之手套[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来绝对坚固，具有[36m不小[2;37;0m的防护力！
上面刻了几个古符号：
[37m天[2;37;0m:[1;33m天圣[2;37;0m [1;36m人[2;37;0m:[1;32m魔王[2;37;0m [1;31m魔[2;37;0m:[1;35m绝世[2;37;0m [36m木[2;37;0m:[33m很高[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m无双[2;37;0m 天灵:[34m细碎[2;37;0m 巧制:[35m标准[2;37;0m 
白石:[35m标准[2;37;0m 紫石:[35m标准[2;37;0m 周天:[34m细碎[2;37;0m 威力:[34m细碎[2;37;0m 
以及一排古篆字【 [1;32m代表[2;37;0m 】。和一些【 [1;32m锤法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "bsx");
		set("ownername", "代表");
		set("value", 16000);
		set("armor_prop/intelligence",26);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 55);
    set("armor_prop/parry", 51);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 505);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 26);
    set("armor_prop/qi", 48);
    set("armor_prop/jing", 56);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 891);

    set("wtypeA",0);
    set("wtypeB",4);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",10);
    set("wtypeJ",0);
    set("wtypeK",9);
    set("wtypeL",11);
    
    
                set("skill", ([
                        "name": "hammer",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 15);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";