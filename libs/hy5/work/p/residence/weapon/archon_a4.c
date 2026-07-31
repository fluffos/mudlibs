#include <ansi.h> 
#include <armor.h>

inherit WRISTS;

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
	      set_name("[1;31m火龙之护腕[2;37;0m", ({ "huolong wrists", "wrists" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
		set("long", @LONG
[1;31m火龙之护腕[2;37;0m这是一双由无比坚硬的[31m万年神铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重五斤三两八钱的[1;31m火龙之护腕[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来无比坚固，具有[36m不小[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;33m天圣[2;37;0m [36m木[2;37;0m:[1;32m魔王[2;37;0m [32m水[2;37;0m:[35m标准[2;37;0m [31m火[2;37;0m:[1;36m完美[2;37;0m [1;34m电[2;37;0m:[1;35m绝世[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m开元[2;37;0m 天灵:[32m粗糙[2;37;0m 巧制:[35m标准[2;37;0m 
闪电:[33m很高[2;37;0m 
周天:[35m标准[2;37;0m 长生:[33m很高[2;37;0m 
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
		set("value", 16000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",40);
		set("armor_prop/karey",48);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",40);
    set("armor_prop/dodge", 40);
    set("armor_prop/parry", 48);
    set("armor_prop/attack", 43);


    set("armor_prop/armor", 464);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 51);
    set("armor_prop/qi", 44);
    set("armor_prop/jing", 48);
    set("armor_prop/jingli", 40);
    set("armor_prop/damage", 320);

    set("wtypeA",10);
    set("wtypeB",9);
    set("wtypeC",5);
    set("wtypeD",7);
    set("wtypeE",6);
    set("wtypeF",5);
    set("wtypeG",4);
    set("wtypeH",11);
    set("wtypeI",4);
    set("wtypeJ",5);
    set("wtypeK",5);
    set("wtypeL",5);
    
    
                set("skill", ([
                        "name": "force",
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