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
	      set_name("[1;34m乔依乌斯之服装[2;37;0m", ({ "joeywus cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
[1;34m在西方查理曼统治的时代，最简朴的剑也能值三头母牛的价钱。而查理大帝自己的那把传奇式
的神兵“乔依乌斯”据说是半人半神的“韦兰铁匠”所造，乃当世界神兵！
[2;37;0m这是一件由无比坚硬的[37m玄铁[2;37;0m加上[37m天蚕丝[2;37;0m制成，重九斤八两二钱的[1;34m乔依乌斯之服装[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比坚固，具有[1;36m斩妖伏魔[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;32m魔王[2;37;0m [36m木[2;37;0m:[31m精致[2;37;0m [31m火[2;37;0m:[1;34m举世[2;37;0m [1;37m雷[2;37;0m:[1;36m完美[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 巧制:[32m粗糙[2;37;0m 
白石:[31m精致[2;37;0m 闪电:[32m粗糙[2;37;0m 
长生:[1;36m完美[2;37;0m 不老:[31m精致[2;37;0m 
以及一排古篆字【 [1;32m雪儿[2;37;0m 】。和一些【 [1;32m掌法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "bmr");
		set("ownername", "雪儿");
		set("value", 25000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 62);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 32);


    set("armor_prop/armor", 570);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 71);
    set("armor_prop/jing", 69);
    set("armor_prop/jingli", 69);
    set("armor_prop/damage", 0);

    set("wtypeA",9);
    set("wtypeB",6);
    set("wtypeC",0);
    set("wtypeD",8);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",7);
    set("wtypeH",0);
    set("wtypeI",12);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "strike",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 16);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";