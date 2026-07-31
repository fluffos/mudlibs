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
[2;37;0m这是一件由绝对坚硬的[37m玄铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重四斤八两四钱的[1;36m天地之服装[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来绝对坚固，具有[31m无与伦比[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;35m绝世[2;37;0m [36m木[2;37;0m:[1;35m绝世[2;37;0m [31m火[2;37;0m:[1;35m绝世[2;37;0m [33m土[2;37;0m:[1;31m创世[2;37;0m [1;37m雷[2;37;0m:[1;31m创世[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m毁天[2;37;0m 天宇:[32m粗糙[2;37;0m 巧制:[32m粗糙[2;37;0m 
白石:[31m精致[2;37;0m 紫石:[33m很高[2;37;0m 闪电:[35m标准[2;37;0m 
周天:[35m标准[2;37;0m 
以及一排古篆字【 [1;32m天正[2;37;0m 】。和一些【 [1;32m剑法[2;37;0m 】的技巧。

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
		set("armor_prop/intelligence",56);
		set("armor_prop/strength",48);
		set("armor_prop/karey",48);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",56);
		set("armor_prop/constitution",56);
    set("armor_prop/dodge", 60);
    set("armor_prop/parry", 49);
    set("armor_prop/attack", 58);


    set("armor_prop/armor", 1062);
    set("armor_prop/defense", 40);
    
    set("armor_prop/neili", 59);
    set("armor_prop/qi", 56);
    set("armor_prop/jing", 48);
    set("armor_prop/jingli", 40);
    set("armor_prop/damage", 376);

    set("wtypeA",11);
    set("wtypeB",11);
    set("wtypeC",5);
    set("wtypeD",11);
    set("wtypeE",14);
    set("wtypeF",5);
    set("wtypeG",14);
    set("wtypeH",6);
    set("wtypeI",8);
    set("wtypeJ",10);
    set("wtypeK",10);
    set("wtypeL",7);
    
    
                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 18);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";