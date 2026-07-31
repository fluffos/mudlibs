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
	      set_name("[1;32m风雷之头盔[2;37;0m", ({ "wulong head", "head" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
		set("long", @LONG
[35m五龙之头盔[2;37;0m这是一顶由无比坚硬的[1;33m金铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重五斤三两一钱的[35m五龙之头盔[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来无比坚固，具有[36m不小[2;37;0m的防护力！
上面刻了几个古符号：
[31m火[2;37;0m:[1;31m无双[2;37;0m [33m土[2;37;0m:[1;32m魔王[2;37;0m [1;35m风[2;37;0m:[1;32m魔王[2;37;0m 
[1;37m雷[2;37;0m:[1;36m完美[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m开元[2;37;0m 巧制:[34m细碎[2;37;0m 
白石:[34m细碎[2;37;0m 紫石:[34m细碎[2;37;0m 长生:[34m细碎[2;37;0m 不老:[34m细碎[2;37;0m 
以及一排古篆字【 [1;32m红无风[2;37;0m 】。和一些【 [1;32m拳脚[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "red");
		set("ownername", "红无风");
		set("value", 16000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 24);
    set("armor_prop/parry", 26);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 104);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 23);
    set("armor_prop/jing", 27);
    set("armor_prop/jingli", 27);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",12);
    set("wtypeE",9);
    set("wtypeF",9);
    set("wtypeG",7);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "unarmed",
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