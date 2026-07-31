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
	      set_name("[1;37m信仰便鞋[2;37;0m", ({ "bad boots", "boots" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
		set("long", @LONG
铁之靴[2;37;0m这是一双由非常坚硬的[32m青铜[2;37;0m加上[1;37m棉花[2;37;0m制成，重零斤八两九钱的[1;37m铁之靴[2;37;0m。
综合评价[32m精致细美[2;37;0m 看起来非常坚固，具有[36m一般[2;37;0m的防护力！
上面刻了几个古符号：
[32m水[2;37;0m:[35m标准[2;37;0m [1;37m雷[2;37;0m:[35m标准[2;37;0m [1;34m电[2;37;0m:[36m不错[2;37;0m 
上面还刻了一些符字：
坚硬:[32m粗糙[2;37;0m 天宇:[32m极差[2;37;0m 绝代:[32m极差[2;37;0m 巧制:[32m极差[2;37;0m 
体灵:[33m一般[2;37;0m 紫石:[33m一般[2;37;0m 
以及一排古篆字【 [1;32m云月寒[2;37;0m 】。和一些【 [1;32m掌法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "zhma");
		set("ownername", "云月寒");
		set("value", 2000);
		set("armor_prop/intelligence",72);
		set("armor_prop/strength",72);
		set("armor_prop/karey",0);
		set("armor_prop/percao",2);
		set("armor_prop/dexerity",72);
		set("armor_prop/constitution",72);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 7);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 185);
    set("armor_prop/defense", 6);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",5);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",5);
    set("wtypeH",1);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",9);
    set("wtypeL",9);
    
    
                set("skill", ([
                        "name": "strike",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		


		set("material", "default");
    set("sharpness", 3);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";