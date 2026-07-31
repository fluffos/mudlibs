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
	      set_name("[1;35m轩辕之服装[2;37;0m", ({ "xuanyuan cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
[1;35m昔日黄帝持此物立于指南车上，驱迷雾，扫阴霾，率应龙旱魃，御百兽而战蚩尤！
[2;37;0m这是一件由无比坚硬的[37m玄铁[2;37;0m加上[37m天蚕丝[2;37;0m制成，重九斤三两七钱的[1;35m轩辕之服装[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比坚固，具有[1;36m斩妖伏魔[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[31m精致[2;37;0m [36m木[2;37;0m:[31m精致[2;37;0m [31m火[2;37;0m:[1;34m举世[2;37;0m [1;35m风[2;37;0m:[1;31m开元[2;37;0m 

上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 天灵:[32m粗糙[2;37;0m 绝代:[32m粗糙[2;37;0m 巧制:[33m很高[2;37;0m 
体灵:[1;36m完美[2;37;0m 白石:[32m粗糙[2;37;0m 长生:[33m很高[2;37;0m 
以及一排古篆字【 [1;32m本无[2;37;0m 】。和一些【 [1;32m鞭法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "wuji");
		set("ownername", "本无");
		set("value", 25000);
		set("armor_prop/intelligence",37);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",32);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 39);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 570);
    set("armor_prop/defense", 71);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 43);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",6);
    set("wtypeB",6);
    set("wtypeC",0);
    set("wtypeD",8);
    set("wtypeE",0);
    set("wtypeF",13);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",8);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "whip",
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