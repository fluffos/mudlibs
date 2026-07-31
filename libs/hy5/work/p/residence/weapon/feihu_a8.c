#include <ansi.h> 
#include <armor.h>

inherit SURCOAT;

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
	      set_name("[1;33m飞天肚带[2;37;0m", ({ "moye surcoat", "surcoat" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
		set("long", @LONG
[31m莫邪锋利无比，能开天辟地，荡妖除魔！
[2;37;0m这是一条由无比坚硬的[1;36m万年寒冰铁[2;37;0m加上[1;33m龙茧蚕丝[2;37;0m制成，重四斤七两二钱的[31m莫邪之肚带[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比坚固，具有[32m水准以上[2;37;0m的防护力！
上面刻了几个古符号：
[40m地[2;37;0m:[1;33m天圣[2;37;0m [1;36m人[2;37;0m:[1;35m绝世[2;37;0m [32m水[2;37;0m:[1;31m开元[2;37;0m [31m火[2;37;0m:[31m精致[2;37;0m [1;35m风[2;37;0m:[1;31m毁天[2;37;0m 

上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 天渊:[33m很高[2;37;0m 巧制:[1;36m完美[2;37;0m 
闪电:[1;36m完美[2;37;0m 
周天:[1;36m完美[2;37;0m 长生:[1;36m完美[2;37;0m 不老:[33m很高[2;37;0m 
以及一排古篆字【 [1;32m飞狐[2;37;0m 】。和一些【 [1;32m内功[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "feihu");
		set("ownername", "飞狐");
		set("value", 36000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",72);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",72);
		set("armor_prop/constitution",72);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 75);


    set("armor_prop/armor", 451);
    set("armor_prop/defense", 72);
    
    set("armor_prop/neili", 78);
    set("armor_prop/qi", 74);
    set("armor_prop/jing", 41);
    set("armor_prop/jingli", 41);
    set("armor_prop/damage", 89);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",13);
    set("wtypeD",6);
    set("wtypeE",0);
    set("wtypeF",15);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",10);
    set("wtypeK",11);
    set("wtypeL",9);
    
    
                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 20);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";