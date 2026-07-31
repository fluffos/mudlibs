#include <ansi.h> 
#include <armor.h>

inherit NECK;

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
	      set_name("[1;31m神通项链[2;37;0m", ({ "sanqing neck", "neck" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串");
		set("long", @LONG
[1;36m大道无名，聚气成形，功参造化，一是三清！这便是“老子一罡化三清。”
[2;37;0m这是一串由无比坚硬的[31m万年神铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重二斤六两四钱的[1;36m三清之项链[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[31m精致[2;37;0m [31m火[2;37;0m:[1;33m天圣[2;37;0m [33m土[2;37;0m:[1;31m创世[2;37;0m [1;35m风[2;37;0m:[1;33m天圣[2;37;0m 
[1;37m雷[2;37;0m:[31m精致[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 绝代:[34m细碎[2;37;0m 巧制:[34m细碎[2;37;0m 
体灵:[1;36m完美[2;37;0m 长生:[32m粗糙[2;37;0m 不老:[1;36m完美[2;37;0m 
以及一排古篆字【 [1;32m欧阳不封[2;37;0m 】。和一些【 [1;32m轻功[2;37;0m 】的技巧。

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
		set("armor_prop/percao",29);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 145);
    set("armor_prop/defense", 70);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 34);
    set("armor_prop/jing", 73);
    set("armor_prop/jingli", 73);
    set("armor_prop/damage", 0);

    set("wtypeA",6);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",10);
    set("wtypeE",14);
    set("wtypeF",10);
    set("wtypeG",6);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "dodge",
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