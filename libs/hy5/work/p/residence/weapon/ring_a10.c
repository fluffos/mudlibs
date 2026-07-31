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
	      set_name("[1;37m夜月清辉[2;37;0m", ({ "gongbu hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
		set("long", @LONG
[31m工布天生怪异，功能参商！
[2;37;0m这是一副由极其坚硬的[1;36m万年寒冰铁[2;37;0m加上[1;33m龙茧蚕丝[2;37;0m制成，重五斤四两七钱的[31m工布之手套[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来极其坚固，具有[32m水准以上[2;37;0m的防护力！
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 天灵:[32m粗糙[2;37;0m 巧制:[35m标准[2;37;0m 
白石:[33m很高[2;37;0m 威力:[33m很高[2;37;0m 
以及一排古篆字【 [1;32m風鈴[2;37;0m 】。和一些【 [1;32m锤法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ring");
		set("ownername", "風鈴");
		set("value", 36000);
		set("armor_prop/intelligence",72);
		set("armor_prop/strength",72);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",72);
		set("armor_prop/constitution",72);
    set("armor_prop/dodge", 49);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 72);


    set("armor_prop/armor", 434);
    set("armor_prop/defense", 72);
    
    set("armor_prop/neili", 72);
    set("armor_prop/qi", 72);
    set("armor_prop/jing", 72);
    set("armor_prop/jingli", 72);
    set("armor_prop/damage", 1303);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",9);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "hammer",
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