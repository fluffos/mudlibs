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
	      set_name("[36m阖之盾[2;37;0m", ({ "bad shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
		set("long", @LONG
阖之盾[2;37;0m这是一面由极为坚硬的[33m生铁[2;37;0m加上[1;33m苎麻[2;37;0m制成，重二斤四两一钱的[36m阖之盾[2;37;0m。
综合评价[32m精致细美[2;37;0m 看起来极为坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[31m精致[2;37;0m [36m木[2;37;0m:[35m标准[2;37;0m [31m火[2;37;0m:[32m粗糙[2;37;0m [1;35m风[2;37;0m:[34m细碎[2;37;0m 

上面还刻了一些符字：
坚硬:[36m不错[2;37;0m 绝代:[32m极差[2;37;0m 巧制:[32m极差[2;37;0m 
周天:[32m极差[2;37;0m 长生:[32m极差[2;37;0m 不老:[32m极差[2;37;0m 威力:[32m极差[2;37;0m 
以及一排古篆字【 [1;32m独孤求圣[2;37;0m 】。和一些【 [1;32m暗器[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "mly");
		set("ownername", "独孤求圣");
		set("value", 2000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",4);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 127);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 4);
    set("armor_prop/qi", 3);
    set("armor_prop/jing", 4);
    set("armor_prop/jingli", 4);
    set("armor_prop/damage", 5);

    set("wtypeA",6);
    set("wtypeB",5);
    set("wtypeC",0);
    set("wtypeD",3);
    set("wtypeE",0);
    set("wtypeF",2);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",5);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "throwing",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		


		set("material", "default");
    set("sharpness", 1);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";