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
	      set_name("[1;31m神通战衣[2;37;0m", ({ "zhendian cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
[37m震电之服装[2;37;0m这是一件由无比坚硬的[31m万年神铁[2;37;0m加上[32m玉蚕丝[2;37;0m制成，重三斤二两八钱的[37m震电之服装[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来无比坚固，具有[35m极其可怕[2;37;0m的防护力！
上面刻了几个古符号：
[40m地[2;37;0m:[1;32m魔王[2;37;0m [1;31m魔[2;37;0m:[1;31m无双[2;37;0m [33m土[2;37;0m:[1;33m天圣[2;37;0m [1;35m风[2;37;0m:[1;36m完美[2;37;0m 

上面还刻了一些符字：
坚硬:[1;31m开元[2;37;0m 福源:[36m不错[2;37;0m 
天渊:[36m不错[2;37;0m 巧制:[32m粗糙[2;37;0m 
体灵:[34m细碎[2;37;0m 白石:[34m细碎[2;37;0m 紫石:[34m细碎[2;37;0m 威力:[33m很高[2;37;0m 
以及一排古篆字【 [1;32m欧阳不封[2;37;0m 】。和一些【 [1;32m掌法[2;37;0m 】的技巧。

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
		set("value", 16000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",18);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",18);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 28);
    set("armor_prop/parry", 26);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 370);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 65);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",6);
    set("wtypeE",10);
    set("wtypeF",7);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",9);
    set("wtypeK",0);
    set("wtypeL",12);
    
    
                set("skill", ([
                        "name": "strike",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 13);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";