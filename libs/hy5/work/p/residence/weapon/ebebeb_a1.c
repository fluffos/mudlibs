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
	      set_name("[1;37m无影甲[2;37;0m", ({ "good cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
花纹之服装[2;37;0m这是一件由无比坚硬的[1;37m软银[2;37;0m加上[1;33m木棉花[2;37;0m制成，重八斤五两九钱的[1;37m花纹之服装[2;37;0m。
综合评价[1;34m举世罕见[2;37;0m 看起来无比坚固，具有[32m水准以上[2;37;0m的防护力！
上面刻了几个古符号：
[1;31m魔[2;37;0m:[1;34m举世[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m天圣[2;37;0m 福源:[33m一般[2;37;0m 
天玄:[36m不错[2;37;0m 巧制:[36m不错[2;37;0m 
紫石:[36m不错[2;37;0m 
以及一排古篆字【 [1;32m慕容人[2;37;0m 】。和一些【 [1;32m拳法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ebebeb");
		set("ownername", "慕容人");
		set("value", 9000);
		set("armor_prop/intelligence",8);
		set("armor_prop/strength",24);
		set("armor_prop/karey",9);
		set("armor_prop/percao",8);
		set("armor_prop/dexerity",8);
		set("armor_prop/constitution",17);
    set("armor_prop/dodge", 24);
    set("armor_prop/parry", 17);
    set("armor_prop/attack", 32);


    set("armor_prop/armor", 626);
    set("armor_prop/defense", 40);
    
    set("armor_prop/neili", 16);
    set("armor_prop/qi", 40);
    set("armor_prop/jing", 32);
    set("armor_prop/jingli", 16);
    set("armor_prop/damage", 104);

    set("wtypeA",1);
    set("wtypeB",2);
    set("wtypeC",2);
    set("wtypeD",1);
    set("wtypeE",1);
    set("wtypeF",2);
    set("wtypeG",3);
    set("wtypeH",5);
    set("wtypeI",3);
    set("wtypeJ",3);
    set("wtypeK",0);
    set("wtypeL",8);
    
    
                set("skill", ([
                        "name": "cuff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		


		set("material", "default");
    set("sharpness", 10);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";