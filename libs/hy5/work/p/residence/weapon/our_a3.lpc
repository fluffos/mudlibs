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
	      set_name("[35m万紫千红[2;37;0m", ({ "juque boots", "boots" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
		set("long", @LONG
[31m巨阙坚硬无比，能开天辟地，荡妖除魔！
[2;37;0m这是一双由无比坚硬的[1;36m万年寒冰铁[2;37;0m加上[1;33m龙茧蚕丝[2;37;0m制成，重三斤九两五钱的[31m巨阙之靴[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比坚固，具有[32m水准以上[2;37;0m的防护力！
上面刻了几个古符号：
[36m木[2;37;0m:[1;36m完美[2;37;0m [32m水[2;37;0m:[1;35m绝世[2;37;0m [31m火[2;37;0m:[1;35m绝世[2;37;0m [33m土[2;37;0m:[1;34m举世[2;37;0m [1;35m风[2;37;0m:[1;31m创世[2;37;0m 

上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 绝代:[32m粗糙[2;37;0m 天玄:[33m很高[2;37;0m 巧制:[1;36m完美[2;37;0m 
白石:[35m标准[2;37;0m 紫石:[33m很高[2;37;0m 闪电:[1;36m完美[2;37;0m 
不老:[1;32m魔王[2;37;0m 
以及一排古篆字【 [1;32m锦绣无双[2;37;0m 】。和一些【 [1;32m鞭法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "our");
		set("ownername", "锦绣无双");
		set("value", 36000);
		set("armor_prop/intelligence",72);
		set("armor_prop/strength",72);
		set("armor_prop/karey",0);
		set("armor_prop/percao",37);
		set("armor_prop/dexerity",72);
		set("armor_prop/constitution",72);
    set("armor_prop/dodge", 52);
    set("armor_prop/parry", 45);
    set("armor_prop/attack", 72);


    set("armor_prop/armor", 638);
    set("armor_prop/defense", 72);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 94);
    set("armor_prop/jingli", 94);
    set("armor_prop/damage", 123);

    set("wtypeA",0);
    set("wtypeB",7);
    set("wtypeC",11);
    set("wtypeD",11);
    set("wtypeE",8);
    set("wtypeF",14);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",9);
    set("wtypeL",9);
    
    
                set("skill", ([
                        "name": "whip",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 25);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";