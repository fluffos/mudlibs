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
	      set_name("[34m玄冥神掌[2;37;0m", ({ "zhanlu hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
		set("long", @LONG
[31m湛卢威力、锋利、坚硬都冠绝当世，乃千古神兵！
[2;37;0m这是一副由无比坚硬的[1;36m万年寒冰铁[2;37;0m加上[1;33m龙茧蚕丝[2;37;0m制成，重五斤三两八钱的[31m湛卢之手套[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比坚固，具有[32m水准以上[2;37;0m的防护力！
上面刻了几个古符号：
[1;36m人[2;37;0m:[1;33m灭世[2;37;0m [33m土[2;37;0m:[1;31m无双[2;37;0m [1;35m风[2;37;0m:[1;31m毁天[2;37;0m 
[1;37m雷[2;37;0m:[1;31m毁天[2;37;0m [1;34m电[2;37;0m:[1;31m毁天[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 天玄:[33m很高[2;37;0m 巧制:[1;32m魔王[2;37;0m 
体灵:[31m精致[2;37;0m 白石:[31m精致[2;37;0m 周天:[35m标准[2;37;0m 长生:[1;34m举世[2;37;0m 威力:[33m很高[2;37;0m 
以及一排古篆字【 [1;32m静樱[2;37;0m 】。和一些【 [1;32m拳法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "kamuls");
		set("ownername", "静樱");
		set("value", 36000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",47);
    set("armor_prop/dodge", 61);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 252);
    set("armor_prop/defense", 66);
    
    set("armor_prop/neili", 58);
    set("armor_prop/qi", 89);
    set("armor_prop/jing", 40);
    set("armor_prop/jingli", 24);
    set("armor_prop/damage", 1121);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",2);
    set("wtypeE",12);
    set("wtypeF",15);
    set("wtypeG",15);
    set("wtypeH",15);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",16);
    set("wtypeL",3);
    
    
                set("skill", ([
                        "name": "cuff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 23);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";