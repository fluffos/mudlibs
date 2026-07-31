#include <ansi.h> 
#include <armor.h>

inherit HEAD;

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
	      set_name("[34m七星之头盔[2;37;0m", ({ "qixing head", "head" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
		set("long", @LONG
[34m七星之头盔[2;37;0m这是一顶由无比坚硬的[1;33m金铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重三斤零两九钱的[34m七星之头盔[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来无比坚固，具有[36m不小[2;37;0m的防护力！
上面刻了几个古符号：
[36m木[2;37;0m:[1;31m无双[2;37;0m [33m土[2;37;0m:[1;34m举世[2;37;0m [1;35m风[2;37;0m:[1;36m完美[2;37;0m 
[1;37m雷[2;37;0m:[1;31m无双[2;37;0m [1;34m电[2;37;0m:[1;35m绝世[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m无双[2;37;0m 福源:[34m细碎[2;37;0m 
巧制:[34m细碎[2;37;0m 
紫石:[34m细碎[2;37;0m 闪电:[32m粗糙[2;37;0m 
长生:[32m粗糙[2;37;0m 不老:[33m很高[2;37;0m 
以及一排古篆字【 [1;32m史蒂芬周[2;37;0m 】。和一些【 [1;32m鞭法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "xianoda");
		set("ownername", "史蒂芬周");
		set("value", 16000);
		set("armor_prop/intelligence",32);
		set("armor_prop/strength",40);
		set("armor_prop/karey",21);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",16);
		set("armor_prop/constitution",8);
    set("armor_prop/dodge", 24);
    set("armor_prop/parry", 26);
    set("armor_prop/attack", 32);


    set("armor_prop/armor", 250);
    set("armor_prop/defense", 16);
    
    set("armor_prop/neili", 24);
    set("armor_prop/qi", 36);
    set("armor_prop/jing", 46);
    set("armor_prop/jingli", 46);
    set("armor_prop/damage", 106);

    set("wtypeA",0);
    set("wtypeB",12);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",8);
    set("wtypeF",7);
    set("wtypeG",12);
    set("wtypeH",11);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "whip",
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