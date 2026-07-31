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
[2;37;0m这是一副由相当坚硬的[37m玄铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重六斤七两五钱的[1;32m无极之手套[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来相当坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;31m无双[2;37;0m [32m水[2;37;0m:[1;33m天圣[2;37;0m [31m火[2;37;0m:[1;31m创世[2;37;0m [33m土[2;37;0m:[1;36m完美[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 天渊:[32m粗糙[2;37;0m 巧制:[33m很高[2;37;0m 
长生:[33m很高[2;37;0m 不老:[31m精致[2;37;0m 威力:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m天正[2;37;0m 】。和一些【 [1;32m内功[2;37;0m 】的技巧。

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
		set("armor_prop/intelligence",40);
		set("armor_prop/strength",48);
		set("armor_prop/karey",48);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 48);
    set("armor_prop/parry", 48);
    set("armor_prop/attack", 48);


    set("armor_prop/armor", 405);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 45);
    set("armor_prop/jing", 64);
    set("armor_prop/jingli", 64);
    set("armor_prop/damage", 1046);

    set("wtypeA",12);
    set("wtypeB",6);
    set("wtypeC",10);
    set("wtypeD",14);
    set("wtypeE",7);
    set("wtypeF",6);
    set("wtypeG",6);
    set("wtypeH",6);
    set("wtypeI",6);
    set("wtypeJ",4);
    set("wtypeK",7);
    set("wtypeL",5);
    
    
                set("skill", ([
                        "name": "force",
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