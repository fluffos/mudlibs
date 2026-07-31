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
	      set_name("[1;37m遮天[2;37;0m", ({ "xuanwu shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
		set("long", @LONG
[1;34m玄武之盾[2;37;0m这是一面由无比坚硬的[1;33m金铁[2;37;0m加上[32m玉蚕丝[2;37;0m制成，重十一斤四两三钱的[1;34m玄武之盾[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来无比坚固，具有[32m水准以上[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[35m标准[2;37;0m [36m木[2;37;0m:[1;35m绝世[2;37;0m [31m火[2;37;0m:[1;32m魔王[2;37;0m [1;35m风[2;37;0m:[31m精致[2;37;0m 

上面还刻了一些符字：
坚硬:[1;31m无双[2;37;0m 巧制:[32m粗糙[2;37;0m 
周天:[34m细碎[2;37;0m 长生:[34m细碎[2;37;0m 不老:[34m细碎[2;37;0m 威力:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m飞翔[2;37;0m 】。和一些【 [1;32m棍法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "wslxs");
		set("ownername", "飞翔");
		set("value", 16000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 184);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 23);
    set("armor_prop/qi", 28);
    set("armor_prop/jing", 28);
    set("armor_prop/jingli", 28);
    set("armor_prop/damage", 33);

    set("wtypeA",5);
    set("wtypeB",11);
    set("wtypeC",0);
    set("wtypeD",9);
    set("wtypeE",0);
    set("wtypeF",6);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "club",
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