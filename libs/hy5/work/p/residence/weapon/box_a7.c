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
	      set_name("[1;31m炼狱之手套[2;37;0m", ({ "lianyu hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
		set("long", @LONG
[1;31m三十三天下有地，地下有城，城名鬼城，大小妖魔，人神畜生都在此轮回往返，谓之“炼狱”！
[2;37;0m这是一副由无比坚硬的[31m万年神铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重四斤五两五钱的[1;31m炼狱之手套[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;33m天圣[2;37;0m [36m木[2;37;0m:[1;32m魔王[2;37;0m [32m水[2;37;0m:[1;34m举世[2;37;0m [33m土[2;37;0m:[1;34m举世[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m毁天[2;37;0m 绝代:[34m细碎[2;37;0m 巧制:[35m标准[2;37;0m 
紫石:[35m标准[2;37;0m 闪电:[33m很高[2;37;0m 
长生:[35m标准[2;37;0m 威力:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m万剑穿心[2;37;0m 】。和一些【 [1;32m暗器[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "box");
		set("ownername", "万剑穿心");
		set("value", 25000);
		set("armor_prop/intelligence",32);
		set("armor_prop/strength",32);
		set("armor_prop/karey",0);
		set("armor_prop/percao",25);
		set("armor_prop/dexerity",32);
		set("armor_prop/constitution",32);
    set("armor_prop/dodge", 48);
    set("armor_prop/parry", 52);
    set("armor_prop/attack", 49);


    set("armor_prop/armor", 750);
    set("armor_prop/defense", 32);
    
    set("armor_prop/neili", 32);
    set("armor_prop/qi", 53);
    set("armor_prop/jing", 40);
    set("armor_prop/jingli", 48);
    set("armor_prop/damage", 1232);

    set("wtypeA",10);
    set("wtypeB",9);
    set("wtypeC",8);
    set("wtypeD",5);
    set("wtypeE",8);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",4);
    set("wtypeJ",4);
    set("wtypeK",4);
    set("wtypeL",5);
    
    
                set("skill", ([
                        "name": "throwing",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 18);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";