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
	      set_name("[1;31m神通之服装[2;37;0m", ({ "shentong cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
[1;31m天兵神通，走势要平善，气要随行，两眼顾尖，气沉两足稳，
身法需自然，身行如飞燕，身落如停风，收如花絮，刺如钢钉！
[2;37;0m这是一件由无比坚硬的[37m玄铁[2;37;0m加上[37m天蚕丝[2;37;0m制成，重九斤零两二钱的[1;31m神通之服装[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比坚固，具有[1;36m斩妖伏魔[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;34m举世[2;37;0m [36m木[2;37;0m:[1;36m完美[2;37;0m [32m水[2;37;0m:[1;31m创世[2;37;0m [31m火[2;37;0m:[1;31m创世[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m毁天[2;37;0m 绝代:[34m细碎[2;37;0m 天渊:[32m粗糙[2;37;0m 巧制:[1;36m完美[2;37;0m 
白石:[31m精致[2;37;0m 紫石:[1;36m完美[2;37;0m 周天:[1;36m完美[2;37;0m 长生:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m科比[2;37;0m 】。和一些【 [1;32m暗器[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "kobe");
		set("ownername", "科比");
		set("value", 25000);
		set("armor_prop/intelligence",32);
		set("armor_prop/strength",0);
		set("armor_prop/karey",40);
		set("armor_prop/percao",25);
		set("armor_prop/dexerity",34);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 66);
    set("armor_prop/parry", 73);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 1039);
    set("armor_prop/defense", 32);
    
    set("armor_prop/neili", 73);
    set("armor_prop/qi", 37);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 251);

    set("wtypeA",8);
    set("wtypeB",7);
    set("wtypeC",14);
    set("wtypeD",14);
    set("wtypeE",5);
    set("wtypeF",4);
    set("wtypeG",5);
    set("wtypeH",0);
    set("wtypeI",5);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",4);
    
    
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