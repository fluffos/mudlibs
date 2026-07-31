#include <ansi.h> 
#include <armor.h>

inherit SURCOAT;

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
	      set_name("[1;31m未央[2;37;0m", ({ "xuanyuan surcoat", "surcoat" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
		set("long", @LONG
[1;35m昔日黄帝持此物立于指南车上，驱迷雾，扫阴霾，率应龙旱魃，御百兽而战蚩尤！
[2;37;0m这是一条由相当坚硬的[37m玄铁[2;37;0m加上[37m天蚕丝[2;37;0m制成，重一斤九两八钱的[1;35m轩辕之肚带[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来相当坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;31m开元[2;37;0m [32m水[2;37;0m:[1;31m开元[2;37;0m [33m土[2;37;0m:[35m标准[2;37;0m [1;35m风[2;37;0m:[1;32m魔王[2;37;0m 

上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 巧制:[32m粗糙[2;37;0m 
长生:[1;36m完美[2;37;0m 不老:[35m标准[2;37;0m 威力:[35m标准[2;37;0m 
以及一排古篆字【 [1;32m花无棱[2;37;0m 】。和一些【 [1;32m招架[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "enjoy");
		set("ownername", "花无棱");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",40);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 56);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 284);
    set("armor_prop/defense", 32);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 70);
    set("armor_prop/jing", 58);
    set("armor_prop/jingli", 58);
    set("armor_prop/damage", 186);

    set("wtypeA",13);
    set("wtypeB",6);
    set("wtypeC",13);
    set("wtypeD",6);
    set("wtypeE",5);
    set("wtypeF",9);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",6);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "parry",
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