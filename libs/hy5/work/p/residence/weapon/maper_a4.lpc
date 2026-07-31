#include <ansi.h> 
#include <armor.h>

inherit WRISTS;

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
	      set_name("[31m飞焰麒麟[2;37;0m", ({ "tiandi wrists", "wrists" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
		set("long", @LONG
[1;36m天地之初，女娲补天所留下的天地间至尊之物之一经千秋万载所制，功能开天劈地！
[2;37;0m这是一双由极其坚硬的[37m玄铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重六斤零两四钱的[1;36m天地之护腕[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来极其坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[37m天[2;37;0m:[1;33m天圣[2;37;0m [33m土[2;37;0m:[1;32m魔王[2;37;0m [1;35m风[2;37;0m:[1;31m开元[2;37;0m 
[1;37m雷[2;37;0m:[1;35m绝世[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m毁天[2;37;0m 巧制:[1;36m完美[2;37;0m 
紫石:[1;36m完美[2;37;0m 闪电:[31m精致[2;37;0m 
周天:[35m标准[2;37;0m 长生:[33m很高[2;37;0m 
以及一排古篆字【 [1;32m地图一号[2;37;0m 】。和一些【 [1;32m内功[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "maper");
		set("ownername", "地图一号");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",48);
		set("armor_prop/karey",48);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 72);
    set("armor_prop/attack", 65);


    set("armor_prop/armor", 377);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 51);
    set("armor_prop/qi", 46);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 48);
    set("armor_prop/damage", 235);

    set("wtypeA",5);
    set("wtypeB",5);
    set("wtypeC",5);
    set("wtypeD",5);
    set("wtypeE",9);
    set("wtypeF",13);
    set("wtypeG",11);
    set("wtypeH",0);
    set("wtypeI",10);
    set("wtypeJ",0);
    set("wtypeK",6);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "force",
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