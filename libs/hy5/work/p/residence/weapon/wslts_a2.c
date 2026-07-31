#include <ansi.h> 
#include <armor.h>

inherit SHIELD;

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
	      set_name("[1;32m龙护[2;37;0m", ({ "huangyu shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
		set("long", @LONG
[37m黄玉之盾[2;37;0m这是一面由极其坚硬的[1;33m金铁[2;37;0m加上[32m玉蚕丝[2;37;0m制成，重十一斤零两六钱的[37m黄玉之盾[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来极其坚固，具有[32m水准以上[2;37;0m的防护力！
上面刻了几个古符号：
[36m木[2;37;0m:[33m很高[2;37;0m [32m水[2;37;0m:[1;36m完美[2;37;0m [31m火[2;37;0m:[1;35m绝世[2;37;0m [33m土[2;37;0m:[33m很高[2;37;0m [1;35m风[2;37;0m:[31m精致[2;37;0m 

上面还刻了一些符字：
坚硬:[1;31m开元[2;37;0m 天灵:[32m粗糙[2;37;0m 巧制:[35m标准[2;37;0m 
白石:[34m细碎[2;37;0m 紫石:[33m很高[2;37;0m 闪电:[35m标准[2;37;0m 
周天:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m莫等闲[2;37;0m 】。和一些【 [1;32m剑法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "wslts");
		set("ownername", "莫等闲");
		set("value", 16000);
		set("armor_prop/intelligence",34);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 22);
    set("armor_prop/parry", 41);
    set("armor_prop/attack", 50);


    set("armor_prop/armor", 184);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 36);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",4);
    set("wtypeC",7);
    set("wtypeD",11);
    set("wtypeE",4);
    set("wtypeF",6);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "sword",
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