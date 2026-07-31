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
	      set_name("[1;34m星云仙袍[2;37;0m", ({ "wuji cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
[1;32m此物已达出神入化，登峰造极，神乎其神之境界！俗说万物归宗，便是这“无极”！
[2;37;0m这是一件由无比坚硬的[37m玄铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重十二斤七两一钱的[1;32m无极之服装[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比坚固，具有[31m无与伦比[2;37;0m的防护力！
上面刻了几个古符号：
[1;31m魔[2;37;0m:[1;32m魔王[2;37;0m [36m木[2;37;0m:[1;31m开元[2;37;0m [32m水[2;37;0m:[1;34m举世[2;37;0m [33m土[2;37;0m:[35m标准[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 巧制:[35m标准[2;37;0m 
体灵:[32m粗糙[2;37;0m 白石:[35m标准[2;37;0m 闪电:[33m很高[2;37;0m 
长生:[1;36m完美[2;37;0m 
以及一排古篆字【 [1;32m星隐[2;37;0m 】。和一些【 [1;32m腿法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "bbm");
		set("ownername", "星隐");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",32);
		set("armor_prop/constitution",56);
    set("armor_prop/dodge", 52);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 43);


    set("armor_prop/armor", 590);
    set("armor_prop/defense", 37);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 74);
    set("armor_prop/jing", 40);
    set("armor_prop/jingli", 40);
    set("armor_prop/damage", 41);

    set("wtypeA",0);
    set("wtypeB",13);
    set("wtypeC",8);
    set("wtypeD",0);
    set("wtypeE",5);
    set("wtypeF",0);
    set("wtypeG",3);
    set("wtypeH",3);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",9);
    
    
                set("skill", ([
                        "name": "leg",
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