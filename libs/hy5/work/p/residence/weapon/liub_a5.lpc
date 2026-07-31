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
	      set_name("[37m打造二[2;37;0m", ({ "good shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
		set("long", @LONG
神狼之盾[2;37;0m这是一面由十分坚硬的[31m流花石[2;37;0m加上[1;33m木棉花[2;37;0m制成，重五斤九两九钱的[37m神狼之盾[2;37;0m。
综合评价[1;34m举世罕见[2;37;0m 看起来十分坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[37m天[2;37;0m:[31m精致[2;37;0m [1;33m金[2;37;0m:[35m标准[2;37;0m [36m木[2;37;0m:[1;33m天圣[2;37;0m [1;35m风[2;37;0m:[35m标准[2;37;0m 

上面还刻了一些符字：
坚硬:[1;33m天圣[2;37;0m 天宇:[36m不错[2;37;0m 绝代:[36m不错[2;37;0m 巧制:[32m粗糙[2;37;0m 

以及一排古篆字【 [1;32m卜凤[2;37;0m 】。和一些【 [1;32m锤法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "liub");
		set("ownername", "卜凤");
		set("value", 9000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",11);
		set("armor_prop/karey",0);
		set("armor_prop/percao",11);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 157);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",5);
    set("wtypeB",10);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",5);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",6);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "hammer",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		


		set("material", "default");
    set("sharpness", 10);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";