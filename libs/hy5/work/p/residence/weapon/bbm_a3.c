#include <ansi.h> 
#include <armor.h>

inherit NECK;

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
	      set_name("[34m幻风之项链[2;37;0m", ({ "good neck", "neck" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串");
		set("long", @LONG
幻风之项链[2;37;0m这是一串由无比坚硬的[31m流花石[2;37;0m加上[1;33m木棉花[2;37;0m制成，重三斤三两五钱的[34m幻风之项链[2;37;0m。
综合评价[1;34m举世罕见[2;37;0m 看起来无比坚固，具有[36m一般[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;32m魔王[2;37;0m [36m木[2;37;0m:[35m标准[2;37;0m [32m水[2;37;0m:[1;33m天圣[2;37;0m [31m火[2;37;0m:[1;32m魔王[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m天圣[2;37;0m 福源:[36m不错[2;37;0m 
巧制:[32m粗糙[2;37;0m 
周天:[32m粗糙[2;37;0m 长生:[36m不错[2;37;0m 不老:[36m不错[2;37;0m 
以及一排古篆字【 [1;32m星隐[2;37;0m 】。和一些【 [1;32m刀法[2;37;0m 】的技巧。

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
		set("value", 9000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",24);
		set("armor_prop/karey",12);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",32);
    set("armor_prop/dodge", 24);
    set("armor_prop/parry", 40);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 96);
    set("armor_prop/defense", 24);
    
    set("armor_prop/neili", 37);
    set("armor_prop/qi", 12);
    set("armor_prop/jing", 16);
    set("armor_prop/jingli", 16);
    set("armor_prop/damage", 79);

    set("wtypeA",9);
    set("wtypeB",5);
    set("wtypeC",10);
    set("wtypeD",9);
    set("wtypeE",3);
    set("wtypeF",0);
    set("wtypeG",4);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",1);
    
    
                set("skill", ([
                        "name": "blade",
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