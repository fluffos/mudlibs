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
	      set_name("[1;36m天地之披风[2;37;0m", ({ "tiandi armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
[1;36m天地之初，女娲补天所留下的天地间至尊之物之一经千秋万载所制，功能开天劈地！
[2;37;0m这是一件由无比坚硬的[37m玄铁[2;37;0m加上[1;33m龙茧蚕丝[2;37;0m制成，重四斤五两三钱的[1;36m天地之披风[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比坚固，具有[32m水准以上[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;31m创世[2;37;0m [32m水[2;37;0m:[1;34m举世[2;37;0m [33m土[2;37;0m:[1;35m绝世[2;37;0m [1;35m风[2;37;0m:[1;31m开元[2;37;0m 
[1;37m雷[2;37;0m:[31m精致[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 巧制:[31m精致[2;37;0m 
体灵:[1;36m完美[2;37;0m 紫石:[1;36m完美[2;37;0m 周天:[31m精致[2;37;0m 长生:[33m很高[2;37;0m 不老:[35m标准[2;37;0m 
以及一排古篆字【 [1;32m天正[2;37;0m 】。和一些【 [1;32m爪法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "archon");
		set("ownername", "天正");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",40);
		set("armor_prop/karey",40);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 56);
    set("armor_prop/parry", 72);
    set("armor_prop/attack", 48);


    set("armor_prop/armor", 412);
    set("armor_prop/defense", 71);
    
    set("armor_prop/neili", 69);
    set("armor_prop/qi", 47);
    set("armor_prop/jing", 52);
    set("armor_prop/jingli", 52);
    set("armor_prop/damage", 82);

    set("wtypeA",14);
    set("wtypeB",6);
    set("wtypeC",8);
    set("wtypeD",5);
    set("wtypeE",11);
    set("wtypeF",13);
    set("wtypeG",6);
    set("wtypeH",3);
    set("wtypeI",4);
    set("wtypeJ",5);
    set("wtypeK",4);
    set("wtypeL",1);
    
    
                set("skill", ([
                        "name": "claw",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 16);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";