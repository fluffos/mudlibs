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
	      set_name("[34m乌蚕衣[2;37;0m", ({ "zhanlu cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
[31m湛卢威力、锋利、坚硬都冠绝当世，乃千古神兵！
[2;37;0m这是一件由无比坚硬的[1;36m万年寒冰铁[2;37;0m加上[1;33m龙茧蚕丝[2;37;0m制成，重七斤八两一钱的[31m湛卢之服装[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比坚固，具有[1;33m举世无匹[2;37;0m的防护力！
上面刻了几个古符号：
[37m天[2;37;0m:[1;34m举世[2;37;0m [1;33m金[2;37;0m:[31m精致[2;37;0m [36m木[2;37;0m:[1;33m天圣[2;37;0m [32m水[2;37;0m:[1;31m创世[2;37;0m [1;35m风[2;37;0m:[1;33m天圣[2;37;0m 

上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 天宇:[33m很高[2;37;0m 福源:[33m很高[2;37;0m 
天玄:[33m很高[2;37;0m 巧制:[33m很高[2;37;0m 
体灵:[1;36m完美[2;37;0m 紫石:[31m精致[2;37;0m 周天:[31m精致[2;37;0m 
以及一排古篆字【 [1;32m珞珈混混[2;37;0m 】。和一些【 [1;32m棍法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "eddie");
		set("ownername", "珞珈混混");
		set("value", 36000);
		set("armor_prop/intelligence",72);
		set("armor_prop/strength",47);
		set("armor_prop/karey",43);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",46);
    set("armor_prop/dodge", 72);
    set("armor_prop/parry", 61);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 840);
    set("armor_prop/defense", 77);
    
    set("armor_prop/neili", 64);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 72);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 64);

    set("wtypeA",6);
    set("wtypeB",10);
    set("wtypeC",14);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",10);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",8);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "club",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 18);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";