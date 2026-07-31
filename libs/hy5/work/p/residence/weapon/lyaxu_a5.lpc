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
	      set_name("[1;32m六道轮回[2;37;0m", ({ "moye cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
[31m莫邪锋利无比，能开天辟地，荡妖除魔！
[2;37;0m这是一件由绝对坚硬的[1;36m万年寒冰铁[2;37;0m加上[1;33m龙茧蚕丝[2;37;0m制成，重四斤零两四钱的[31m莫邪之服装[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来绝对坚固，具有[1;33m举世无匹[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;33m灭世[2;37;0m [36m木[2;37;0m:[1;31m开元[2;37;0m [33m土[2;37;0m:[1;35m绝世[2;37;0m [1;35m风[2;37;0m:[1;36m完美[2;37;0m 
[1;37m雷[2;37;0m:[31m精致[2;37;0m [1;34m电[2;37;0m:[1;36m完美[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 福源:[33m很高[2;37;0m 
巧制:[33m很高[2;37;0m 
紫石:[31m精致[2;37;0m 周天:[1;34m举世[2;37;0m 长生:[31m精致[2;37;0m 不老:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m破烂站[2;37;0m 】。和一些【 [1;32m手法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "lyaxu");
		set("ownername", "破烂站");
		set("value", 36000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",24);
		set("armor_prop/karey",46);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 68);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 840);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 80);
    set("armor_prop/qi", 63);
    set("armor_prop/jing", 36);
    set("armor_prop/jingli", 36);
    set("armor_prop/damage", 24);

    set("wtypeA",16);
    set("wtypeB",13);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",11);
    set("wtypeF",7);
    set("wtypeG",6);
    set("wtypeH",7);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "hand",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 26);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";