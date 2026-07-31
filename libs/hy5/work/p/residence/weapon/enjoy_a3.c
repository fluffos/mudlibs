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
	      set_name("[1;31m碎步[2;37;0m", ({ "bagua boots", "boots" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
		set("long", @LONG
[1;37m八卦有“休”“生”“伤”“杜”“死”“景”“惊”“开”之别，创自诸葛武候，集天下万变于一身！
[2;37;0m这是一双由无比坚硬的[37m玄铁[2;37;0m加上[37m天蚕丝[2;37;0m制成，重二斤三两四钱的[1;37m八卦之靴[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;33m天圣[2;37;0m [32m水[2;37;0m:[1;31m无双[2;37;0m [33m土[2;37;0m:[1;33m天圣[2;37;0m [1;35m风[2;37;0m:[1;34m举世[2;37;0m 

上面还刻了一些符字：
坚硬:[1;31m毁天[2;37;0m 天宇:[32m粗糙[2;37;0m 巧制:[35m标准[2;37;0m 
白石:[31m精致[2;37;0m 长生:[35m标准[2;37;0m 不老:[31m精致[2;37;0m 
以及一排古篆字【 [1;32m花无棱[2;37;0m 】。和一些【 [1;32m拳脚[2;37;0m 】的技巧。

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
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 64);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 262);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 53);
    set("armor_prop/jing", 69);
    set("armor_prop/jingli", 69);
    set("armor_prop/damage", 113);

    set("wtypeA",10);
    set("wtypeB",6);
    set("wtypeC",12);
    set("wtypeD",6);
    set("wtypeE",10);
    set("wtypeF",8);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",6);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 15);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";