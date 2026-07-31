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
	      set_name("[37m震电之项链[2;37;0m", ({ "zhendian neck", "neck" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串");
		set("long", @LONG
[37m震电之项链[2;37;0m这是一串由无比坚硬的[1;33m金铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重四斤二两四钱的[37m震电之项链[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来无比坚固，具有[36m不小[2;37;0m的防护力！
上面刻了几个古符号：
[32m水[2;37;0m:[1;35m绝世[2;37;0m [33m土[2;37;0m:[35m标准[2;37;0m [1;35m风[2;37;0m:[1;33m天圣[2;37;0m 
[1;37m雷[2;37;0m:[1;32m魔王[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m无双[2;37;0m 福源:[34m细碎[2;37;0m 
天玄:[36m不错[2;37;0m 巧制:[36m不错[2;37;0m 
白石:[36m不错[2;37;0m 紫石:[34m细碎[2;37;0m 
以及一排古篆字【 [1;32m天正[2;37;0m 】。和一些【 [1;32m棍法[2;37;0m 】的技巧。

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
		set("value", 16000);
		set("armor_prop/intelligence",24);
		set("armor_prop/strength",48);
		set("armor_prop/karey",23);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",24);
		set("armor_prop/constitution",16);
    set("armor_prop/dodge", 17);
    set("armor_prop/parry", 24);
    set("armor_prop/attack", 48);


    set("armor_prop/armor", 425);
    set("armor_prop/defense", 40);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 48);
    set("armor_prop/jing", 48);
    set("armor_prop/jingli", 48);
    set("armor_prop/damage", 164);

    set("wtypeA",6);
    set("wtypeB",6);
    set("wtypeC",11);
    set("wtypeD",6);
    set("wtypeE",5);
    set("wtypeF",10);
    set("wtypeG",9);
    set("wtypeH",5);
    set("wtypeI",4);
    set("wtypeJ",4);
    set("wtypeK",0);
    set("wtypeL",4);
    
    
                set("skill", ([
                        "name": "club",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 12);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";