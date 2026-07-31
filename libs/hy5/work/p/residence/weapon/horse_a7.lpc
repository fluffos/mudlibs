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
	      set_name("[1;37m八卦之盾[2;37;0m", ({ "bagua shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
		set("long", @LONG
[1;37m八卦有“休”“生”“伤”“杜”“死”“景”“惊”“开”之别，创自诸葛武候，集天下万变于一身！
[2;37;0m这是一面由绝对坚硬的[37m玄铁[2;37;0m加上[37m天蚕丝[2;37;0m制成，重三斤九两五钱的[1;37m八卦之盾[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来绝对坚固，具有[32m水准以上[2;37;0m的防护力！
上面刻了几个古符号：
[1;36m人[2;37;0m:[1;33m天圣[2;37;0m [1;33m金[2;37;0m:[1;31m开元[2;37;0m [36m木[2;37;0m:[35m标准[2;37;0m [32m水[2;37;0m:[31m精致[2;37;0m [1;34m电[2;37;0m:[1;36m完美[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 巧制:[33m很高[2;37;0m 
周天:[35m标准[2;37;0m 长生:[35m标准[2;37;0m 不老:[1;36m完美[2;37;0m 威力:[35m标准[2;37;0m 
以及一排古篆字【 [1;32m小马[2;37;0m 】。和一些【 [1;32m暗器[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "horse");
		set("ownername", "小马");
		set("value", 25000);
		set("armor_prop/intelligence",40);
		set("armor_prop/strength",40);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",32);
		set("armor_prop/constitution",32);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 429);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 57);
    set("armor_prop/qi", 50);
    set("armor_prop/jing", 70);
    set("armor_prop/jingli", 70);
    set("armor_prop/damage", 229);

    set("wtypeA",13);
    set("wtypeB",5);
    set("wtypeC",6);
    set("wtypeD",4);
    set("wtypeE",3);
    set("wtypeF",5);
    set("wtypeG",5);
    set("wtypeH",7);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",10);
    set("wtypeL",1);
    
    
                set("skill", ([
                        "name": "throwing",
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