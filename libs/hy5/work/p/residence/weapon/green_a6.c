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
	      set_name("[1;31m神通披风[2;37;0m", ({ "tiandi armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
[1;36m天地之初，女娲补天所留下的天地间至尊之物之一经千秋万载所制，功能开天劈地！
[2;37;0m这是一件由无比坚硬的[31m万年神铁[2;37;0m加上[32m玉蚕丝[2;37;0m制成，重三斤一两五钱的[1;36m天地之披风[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比坚固，具有[36m不小[2;37;0m的防护力！
上面刻了几个古符号：
[37m天[2;37;0m:[1;32m魔王[2;37;0m [32m水[2;37;0m:[35m标准[2;37;0m [1;35m风[2;37;0m:[1;31m创世[2;37;0m 
[1;37m雷[2;37;0m:[1;33m天圣[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m毁天[2;37;0m 福源:[34m细碎[2;37;0m 
天渊:[34m细碎[2;37;0m 巧制:[32m粗糙[2;37;0m 
长生:[32m粗糙[2;37;0m 不老:[33m很高[2;37;0m 
以及一排古篆字【 [1;32m欧阳不封[2;37;0m 】。和一些【 [1;32m腿法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "green");
		set("ownername", "欧阳不封");
		set("value", 25000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",28);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",27);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 138);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 30);
    set("armor_prop/jing", 49);
    set("armor_prop/jingli", 49);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",5);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",14);
    set("wtypeG",10);
    set("wtypeH",0);
    set("wtypeI",9);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "leg",
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