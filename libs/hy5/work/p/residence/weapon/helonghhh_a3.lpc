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
	      set_name("[35m三只手[2;37;0m", ({ "sanqing hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
		set("long", @LONG
[1;36m大道无名，聚气成形，功参造化，一是三清！这便是“老子一罡化三清。”
[2;37;0m这是一副由无比坚硬的[37m玄铁[2;37;0m加上[37m天蚕丝[2;37;0m制成，重六斤零两二钱的[1;36m三清之手套[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[31m火[2;37;0m:[1;34m举世[2;37;0m [33m土[2;37;0m:[1;33m天圣[2;37;0m [1;35m风[2;37;0m:[1;31m创世[2;37;0m 
[1;37m雷[2;37;0m:[1;31m创世[2;37;0m [1;34m电[2;37;0m:[1;31m无双[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m毁天[2;37;0m 天灵:[35m标准[2;37;0m 绝代:[34m细碎[2;37;0m 巧制:[33m很高[2;37;0m 
白石:[31m精致[2;37;0m 紫石:[33m很高[2;37;0m 长生:[35m标准[2;37;0m 威力:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m和白花[2;37;0m 】。和一些【 [1;32m棍法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "helonghhh");
		set("ownername", "和白花");
		set("value", 25000);
		set("armor_prop/intelligence",51);
		set("armor_prop/strength",40);
		set("armor_prop/karey",24);
		set("armor_prop/percao",26);
		set("armor_prop/dexerity",32);
		set("armor_prop/constitution",24);
    set("armor_prop/dodge", 60);
    set("armor_prop/parry", 40);
    set("armor_prop/attack", 24);


    set("armor_prop/armor", 797);
    set("armor_prop/defense", 24);
    
    set("armor_prop/neili", 24);
    set("armor_prop/qi", 51);
    set("armor_prop/jing", 56);
    set("armor_prop/jingli", 48);
    set("armor_prop/damage", 1326);

    set("wtypeA",4);
    set("wtypeB",2);
    set("wtypeC",2);
    set("wtypeD",8);
    set("wtypeE",10);
    set("wtypeF",14);
    set("wtypeG",14);
    set("wtypeH",12);
    set("wtypeI",1);
    set("wtypeJ",4);
    set("wtypeK",5);
    set("wtypeL",4);
    
    
                set("skill", ([
                        "name": "club",
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