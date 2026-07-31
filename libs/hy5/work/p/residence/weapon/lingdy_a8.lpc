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
	      set_name("[1;32m无极之手套[2;37;0m", ({ "wuji hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
		set("long", @LONG
[1;32m此物已达出神入化，登峰造极，神乎其神之境界！俗说万物归宗，便是这“无极”！
[2;37;0m这是一副由无比坚硬的[37m玄铁[2;37;0m加上[37m天蚕丝[2;37;0m制成，重五斤六两九钱的[1;32m无极之手套[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[36m木[2;37;0m:[35m标准[2;37;0m [32m水[2;37;0m:[1;32m魔王[2;37;0m [31m火[2;37;0m:[1;31m开元[2;37;0m [1;35m风[2;37;0m:[1;32m魔王[2;37;0m 

上面还刻了一些符字：
坚硬:[1;31m毁天[2;37;0m 巧制:[33m很高[2;37;0m 
紫石:[33m很高[2;37;0m 闪电:[33m很高[2;37;0m 
周天:[35m标准[2;37;0m 长生:[35m标准[2;37;0m 威力:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m风风[2;37;0m 】。和一些【 [1;32m斧法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "lingdy");
		set("ownername", "风风");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",56);
		set("armor_prop/karey",48);
		set("armor_prop/percao",56);
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",56);
    set("armor_prop/dodge", 56);
    set("armor_prop/parry", 40);
    set("armor_prop/attack", 56);


    set("armor_prop/armor", 648);
    set("armor_prop/defense", 56);
    
    set("armor_prop/neili", 52);
    set("armor_prop/qi", 57);
    set("armor_prop/jing", 56);
    set("armor_prop/jingli", 56);
    set("armor_prop/damage", 1336);

    set("wtypeA",5);
    set("wtypeB",5);
    set("wtypeC",9);
    set("wtypeD",13);
    set("wtypeE",6);
    set("wtypeF",9);
    set("wtypeG",7);
    set("wtypeH",6);
    set("wtypeI",5);
    set("wtypeJ",6);
    set("wtypeK",7);
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