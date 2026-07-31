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
	      set_name("[1;33m灭世[2;37;0m", ({ "mowang cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
[34m魔王之服装[2;37;0m这是一件由十分坚硬的[31m万年神铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重六斤八两九钱的[34m魔王之服装[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来十分坚固，具有[35m极其可怕[2;37;0m的防护力！
上面刻了几个古符号：
[37m天[2;37;0m:[1;33m天圣[2;37;0m [1;31m魔[2;37;0m:[33m很高[2;37;0m [1;33m金[2;37;0m:[1;31m无双[2;37;0m [36m木[2;37;0m:[33m很高[2;37;0m [33m土[2;37;0m:[1;36m完美[2;37;0m [1;37m雷[2;37;0m:[1;31m无双[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m无双[2;37;0m 巧制:[34m细碎[2;37;0m 
白石:[33m很高[2;37;0m 紫石:[32m粗糙[2;37;0m 闪电:[34m细碎[2;37;0m 
周天:[35m标准[2;37;0m 
以及一排古篆字【 [1;32m再续前缘[2;37;0m 】。和一些【 [1;32m拳法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "yunlongzi");
		set("ownername", "再续前缘");
		set("value", 16000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 49);
    set("armor_prop/parry", 39);
    set("armor_prop/attack", 29);


    set("armor_prop/armor", 441);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 54);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",12);
    set("wtypeB",4);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",7);
    set("wtypeF",0);
    set("wtypeG",12);
    set("wtypeH",0);
    set("wtypeI",10);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",4);
    
    
                set("skill", ([
                        "name": "cuff",
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