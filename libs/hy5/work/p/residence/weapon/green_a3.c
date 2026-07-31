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
	      set_name("[1;31m神通手套[2;37;0m", ({ "haoqi hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
		set("long", @LONG
[1;32m天地浩气之神兵，扫魔除妖，为国为民，侠之大者！
[2;37;0m这是一副由无比坚硬的[37m玄铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重二斤五两三钱的[1;32m浩气之手套[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[36m木[2;37;0m:[1;34m举世[2;37;0m [32m水[2;37;0m:[1;31m开元[2;37;0m [31m火[2;37;0m:[1;31m开元[2;37;0m [1;35m风[2;37;0m:[1;35m绝世[2;37;0m 
[1;37m雷[2;37;0m:[31m精致[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m毁天[2;37;0m 天渊:[32m粗糙[2;37;0m 巧制:[1;36m完美[2;37;0m 
紫石:[35m标准[2;37;0m 闪电:[32m粗糙[2;37;0m 
长生:[33m很高[2;37;0m 不老:[31m精致[2;37;0m 威力:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m欧阳不封[2;37;0m 】。和一些【 [1;32m腿法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "green");
		set("ownername", "欧阳不封");
		set("value", 25000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",31);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 57);
    set("armor_prop/attack", 33);


    set("armor_prop/armor", 134);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 48);
    set("armor_prop/jing", 69);
    set("armor_prop/jingli", 69);
    set("armor_prop/damage", 775);

    set("wtypeA",0);
    set("wtypeB",8);
    set("wtypeC",13);
    set("wtypeD",13);
    set("wtypeE",0);
    set("wtypeF",11);
    set("wtypeG",6);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "leg",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 15);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";