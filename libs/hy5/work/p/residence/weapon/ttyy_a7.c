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
	      set_name("[32m松鹤之项链[2;37;0m", ({ "songhe neck", "neck" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串");
		set("long", @LONG
[32m松鹤之项链[2;37;0m这是一串由无比坚硬的[31m万年神铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重二斤零两零钱的[32m松鹤之项链[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来无比坚固，具有[36m不小[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[35m标准[2;37;0m [36m木[2;37;0m:[1;36m完美[2;37;0m [32m水[2;37;0m:[31m精致[2;37;0m [1;35m风[2;37;0m:[1;32m魔王[2;37;0m 
[1;37m雷[2;37;0m:[1;31m无双[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m无双[2;37;0m 巧制:[35m标准[2;37;0m 
白石:[35m标准[2;37;0m 闪电:[35m标准[2;37;0m 
长生:[33m很高[2;37;0m 不老:[35m标准[2;37;0m 威力:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m团团圆圆[2;37;0m 】。和一些【 [1;32m爪法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ttyy");
		set("ownername", "团团圆圆");
		set("value", 16000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 55);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 50);


    set("armor_prop/armor", 104);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 43);
    set("armor_prop/jing", 55);
    set("armor_prop/jingli", 55);
    set("armor_prop/damage", 34);

    set("wtypeA",5);
    set("wtypeB",7);
    set("wtypeC",6);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",9);
    set("wtypeG",12);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "claw",
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