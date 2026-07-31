#include <ansi.h> 
#include <armor.h>

inherit BOOTS;

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
	      set_name("[1;37m琼鲸之履[2;37;0m", ({ "fengyun boots", "boots" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
		set("long", @LONG
[1;35m所谓风云际会，天地变色！仗此行千里，老魔小丑，岂堪一击！
[2;37;0m这是一双由无比坚硬的[37m玄铁[2;37;0m加上[32m玉蚕丝[2;37;0m制成，重五斤六两三钱的[1;35m风云之靴[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比坚固，具有[36m不小[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;31m创世[2;37;0m [36m木[2;37;0m:[1;31m创世[2;37;0m [31m火[2;37;0m:[1;34m举世[2;37;0m [33m土[2;37;0m:[35m标准[2;37;0m [1;34m电[2;37;0m:[1;31m无双[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m毁天[2;37;0m 巧制:[33m很高[2;37;0m 
白石:[33m很高[2;37;0m 长生:[34m细碎[2;37;0m 不老:[31m精致[2;37;0m 威力:[35m标准[2;37;0m 
以及一排古篆字【 [1;32m段药师[2;37;0m 】。和一些【 [1;32m拳法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "yellow");
		set("ownername", "段药师");
		set("value", 25000);
		set("armor_prop/intelligence",56);
		set("armor_prop/strength",56);
		set("armor_prop/karey",48);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",56);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 45);
    set("armor_prop/parry", 40);
    set("armor_prop/attack", 48);


    set("armor_prop/armor", 533);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 25);
    set("armor_prop/jing", 64);
    set("armor_prop/jingli", 64);
    set("armor_prop/damage", 470);

    set("wtypeA",14);
    set("wtypeB",14);
    set("wtypeC",0);
    set("wtypeD",8);
    set("wtypeE",5);
    set("wtypeF",0);
    set("wtypeG",5);
    set("wtypeH",12);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",7);
    
    
                set("skill", ([
                        "name": "cuff",
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