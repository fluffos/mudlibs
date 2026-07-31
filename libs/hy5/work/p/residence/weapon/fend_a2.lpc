#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

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
	      set_name("[1;36m天地之服装[2;37;0m", ({ "tiandi cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
[1;36m天地之初，女娲补天所留下的天地间至尊之物之一经千秋万载所制，功能开天劈地！
[2;37;0m这是一件由无比坚硬的[37m玄铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重五斤九两二钱的[1;36m天地之服装[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比坚固，具有[31m无与伦比[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[35m标准[2;37;0m [32m水[2;37;0m:[1;32m魔王[2;37;0m [31m火[2;37;0m:[1;31m创世[2;37;0m [1;35m风[2;37;0m:[1;31m创世[2;37;0m 
[1;37m雷[2;37;0m:[1;34m举世[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m毁天[2;37;0m 巧制:[32m粗糙[2;37;0m 
白石:[32m粗糙[2;37;0m 长生:[1;36m完美[2;37;0m 不老:[34m细碎[2;37;0m 威力:[31m精致[2;37;0m 
以及一排古篆字【 [1;32m方方[2;37;0m 】。和一些【 [1;32m斧法[2;37;0m 】的技巧。

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
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",56);
    set("armor_prop/dodge", 30);
    set("armor_prop/parry", 56);
    set("armor_prop/attack", 48);


    set("armor_prop/armor", 1030);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 73);
    set("armor_prop/jing", 26);
    set("armor_prop/jingli", 26);
    set("armor_prop/damage", 596);

    set("wtypeA",7);
    set("wtypeB",6);
    set("wtypeC",9);
    set("wtypeD",14);
    set("wtypeE",5);
    set("wtypeF",14);
    set("wtypeG",8);
    set("wtypeH",6);
    set("wtypeI",6);
    set("wtypeJ",6);
    set("wtypeK",6);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "axe",
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