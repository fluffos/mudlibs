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
	      set_name("[1;31m山缺[2;37;0m", ({ "fengyun cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
[1;35m所谓风云际会，天地变色！仗此行千里，老魔小丑，岂堪一击！
[2;37;0m这是一件由绝对坚硬的[37m玄铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重八斤四两六钱的[1;35m风云之服装[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来绝对坚固，具有[31m无与伦比[2;37;0m的防护力！
上面刻了几个古符号：
[40m地[2;37;0m:[1;31m创世[2;37;0m [31m火[2;37;0m:[1;33m天圣[2;37;0m [33m土[2;37;0m:[1;35m绝世[2;37;0m [1;35m风[2;37;0m:[1;32m魔王[2;37;0m 

上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 天宇:[34m细碎[2;37;0m 天渊:[32m粗糙[2;37;0m 巧制:[35m标准[2;37;0m 
白石:[31m精致[2;37;0m 闪电:[35m标准[2;37;0m 
长生:[33m很高[2;37;0m 威力:[35m标准[2;37;0m 
以及一排古篆字【 [1;32m花无棱[2;37;0m 】。和一些【 [1;32m杖法[2;37;0m 】的技巧。

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
		set("armor_prop/strength",48);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",33);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 66);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 53);


    set("armor_prop/armor", 609);
    set("armor_prop/defense", 56);
    
    set("armor_prop/neili", 40);
    set("armor_prop/qi", 49);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 56);
    set("armor_prop/damage", 159);

    set("wtypeA",6);
    set("wtypeB",6);
    set("wtypeC",6);
    set("wtypeD",10);
    set("wtypeE",11);
    set("wtypeF",9);
    set("wtypeG",6);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",14);
    set("wtypeK",0);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "staff",
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