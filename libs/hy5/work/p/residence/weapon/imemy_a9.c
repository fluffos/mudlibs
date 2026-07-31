#include <ansi.h> 
#include <armor.h>

inherit HANDS;

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
	      set_name("[1;34m海洋之触[2;37;0m", ({ "zhanlu hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
		set("long", @LONG
[31m湛卢威力、锋利、坚硬都冠绝当世，乃千古神兵！
[2;37;0m这是一副由无比坚硬的[1;36m万年寒冰铁[2;37;0m加上[1;33m龙茧蚕丝[2;37;0m制成，重三斤六两三钱的[31m湛卢之手套[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比坚固，具有[32m水准以上[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[31m精致[2;37;0m [36m木[2;37;0m:[1;31m毁天[2;37;0m [32m水[2;37;0m:[1;33m天圣[2;37;0m [1;35m风[2;37;0m:[1;33m灭世[2;37;0m 

上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 绝代:[32m粗糙[2;37;0m 巧制:[1;32m魔王[2;37;0m 
白石:[1;36m完美[2;37;0m 紫石:[35m标准[2;37;0m 周天:[32m粗糙[2;37;0m 长生:[35m标准[2;37;0m 威力:[33m很高[2;37;0m 
以及一排古篆字【 [1;32m渡渡[2;37;0m 】。和一些【 [1;32m轻功[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "imemy");
		set("ownername", "渡渡");
		set("value", 36000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",64);
		set("armor_prop/karey",0);
		set("armor_prop/percao",38);
		set("armor_prop/dexerity",64);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 73);
    set("armor_prop/parry", 53);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 303);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 39);
    set("armor_prop/qi", 59);
    set("armor_prop/jing", 64);
    set("armor_prop/jingli", 64);
    set("armor_prop/damage", 1172);

    set("wtypeA",6);
    set("wtypeB",15);
    set("wtypeC",10);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",16);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",14);
    set("wtypeL",8);
    
    
                set("skill", ([
                        "name": "dodge",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 24);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";