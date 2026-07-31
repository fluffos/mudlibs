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
	      set_name("[1;36m降魔之服装[2;37;0m", ({ "general cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
降魔之服装[2;37;0m这是一件由比较坚硬的[33m软铁[2;37;0m加上[33m亚麻[2;37;0m制成，重五斤九两八钱的[1;36m降魔之服装[2;37;0m。
综合评价[31m完美精致[2;37;0m 看起来比较坚固，具有[32m水准以上[2;37;0m的防护力！
上面刻了几个古符号：
[37m天[2;37;0m:[1;36m完美[2;37;0m [40m地[2;37;0m:[1;34m举世[2;37;0m [1;36m人[2;37;0m:[34m细碎[2;37;0m [1;31m魔[2;37;0m:[1;34m举世[2;37;0m 
上面还刻了一些符字：
坚硬:[31m精致[2;37;0m 天灵:[36m不错[2;37;0m 天渊:[32m极差[2;37;0m 天玄:[32m极差[2;37;0m 巧制:[32m极差[2;37;0m 
白石:[33m一般[2;37;0m 不老:[32m极差[2;37;0m 
以及一排古篆字【 [1;32m海大富[2;37;0m 】。和一些【 [1;32m锤法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "wxswlh");
		set("ownername", "海大富");
		set("value", 2000);
		set("armor_prop/intelligence",11);
		set("armor_prop/strength",24);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",3);
		set("armor_prop/constitution",5);
    set("armor_prop/dodge", 9);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 194);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 32);
    set("armor_prop/jing", 4);
    set("armor_prop/jingli", 4);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",3);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",7);
    set("wtypeJ",8);
    set("wtypeK",2);
    set("wtypeL",8);
    
    
                set("skill", ([
                        "name": "hammer",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		


		set("material", "default");
    set("sharpness", 6);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";