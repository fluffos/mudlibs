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
	      set_name("[33m狮子座黄金圣衣[2;37;0m", ({ "taie cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
[31m太阿帝王之兵，持之能号令天下，莫有不从！
[2;37;0m这是一件由无比坚硬的[1;36m万年寒冰铁[2;37;0m加上[1;33m龙茧蚕丝[2;37;0m制成，重十一斤七两一钱的[31m太阿之服装[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比坚固，具有[1;33m举世无匹[2;37;0m的防护力！
上面刻了几个古符号：
[1;36m人[2;37;0m:[31m精致[2;37;0m [1;31m魔[2;37;0m:[1;32m魔王[2;37;0m [36m木[2;37;0m:[1;31m开元[2;37;0m [1;35m风[2;37;0m:[1;31m创世[2;37;0m 
[1;37m雷[2;37;0m:[31m精致[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 巧制:[31m精致[2;37;0m 
紫石:[33m很高[2;37;0m 周天:[1;36m完美[2;37;0m 长生:[1;36m完美[2;37;0m 不老:[33m很高[2;37;0m 威力:[33m很高[2;37;0m 
以及一排古篆字【 [1;32m静樱[2;37;0m 】。和一些【 [1;32m杖法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "kamuls");
		set("ownername", "静樱");
		set("value", 36000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 44);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 840);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 75);
    set("armor_prop/qi", 72);
    set("armor_prop/jing", 44);
    set("armor_prop/jingli", 44);
    set("armor_prop/damage", 43);

    set("wtypeA",0);
    set("wtypeB",13);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",14);
    set("wtypeG",6);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",6);
    set("wtypeL",9);
    
    
                set("skill", ([
                        "name": "staff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 23);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";