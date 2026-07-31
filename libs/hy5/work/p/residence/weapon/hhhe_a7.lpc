#include <ansi.h> 
#include <armor.h>

inherit HEAD;

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
	      set_name("[36m天圣之头盔[2;37;0m", ({ "tiansheng head", "head" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
		set("long", @LONG
[36m天圣之头盔[2;37;0m这是一顶由绝对坚硬的[1;33m金铁[2;37;0m加上[1;33m木棉花[2;37;0m制成，重二斤五两八钱的[36m天圣之头盔[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来绝对坚固，具有[36m不小[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;35m绝世[2;37;0m [32m水[2;37;0m:[1;35m绝世[2;37;0m [31m火[2;37;0m:[35m标准[2;37;0m [1;37m雷[2;37;0m:[1;34m举世[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m开元[2;37;0m 天玄:[36m不错[2;37;0m 巧制:[32m粗糙[2;37;0m 
白石:[32m粗糙[2;37;0m 紫石:[32m粗糙[2;37;0m 闪电:[33m很高[2;37;0m 
威力:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m慕容米[2;37;0m 】。和一些【 [1;32m招架[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "hhhe");
		set("ownername", "慕容米");
		set("value", 16000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",16);
    set("armor_prop/dodge", 35);
    set("armor_prop/parry", 39);
    set("armor_prop/attack", 41);


    set("armor_prop/armor", 81);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 33);

    set("wtypeA",11);
    set("wtypeB",0);
    set("wtypeC",11);
    set("wtypeD",5);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",8);
    set("wtypeH",0);
    set("wtypeI",7);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "parry",
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