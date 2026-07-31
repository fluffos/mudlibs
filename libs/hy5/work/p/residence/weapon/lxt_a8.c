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
	      set_name("[34m暗之肚带[2;37;0m", ({ "ganjiang surcoat", "surcoat" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
		set("long", @LONG
[31m干将威力无比，能开天辟地，荡妖除魔！
[2;37;0m这是一条由无比坚硬的[1;36m万年寒冰铁[2;37;0m加上[1;33m龙茧蚕丝[2;37;0m制成，重四斤二两四钱的[31m干将之肚带[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比坚固，具有[32m水准以上[2;37;0m的防护力！
上面刻了几个古符号：
[1;36m人[2;37;0m:[1;33m天圣[2;37;0m [36m木[2;37;0m:[1;31m无双[2;37;0m [32m水[2;37;0m:[1;32m魔王[2;37;0m [1;35m风[2;37;0m:[1;33m天圣[2;37;0m 
[1;37m雷[2;37;0m:[1;31m开元[2;37;0m [1;34m电[2;37;0m:[1;31m毁天[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 天渊:[33m很高[2;37;0m 巧制:[1;32m魔王[2;37;0m 
体灵:[1;32m魔王[2;37;0m 紫石:[31m精致[2;37;0m 周天:[1;34m举世[2;37;0m 长生:[1;34m举世[2;37;0m 
以及一排古篆字【 [1;32m传鹰[2;37;0m 】。和一些【 [1;32m招架[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "lxt");
		set("ownername", "传鹰");
		set("value", 36000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",72);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",72);
		set("armor_prop/constitution",72);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 63);
    set("armor_prop/attack", 72);


    set("armor_prop/armor", 655);
    set("armor_prop/defense", 95);
    
    set("armor_prop/neili", 83);
    set("armor_prop/qi", 89);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 174);

    set("wtypeA",0);
    set("wtypeB",12);
    set("wtypeC",9);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",10);
    set("wtypeG",13);
    set("wtypeH",15);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",10);
    set("wtypeL",9);
    
    
                set("skill", ([
                        "name": "parry",
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