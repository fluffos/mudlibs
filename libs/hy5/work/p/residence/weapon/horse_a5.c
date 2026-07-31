#include <ansi.h> 
#include <armor.h>

inherit NECK;

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
	      set_name("[1;33m太极之项链[2;37;0m", ({ "taiji neck", "neck" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串");
		set("long", @LONG
[1;33m太极者，无极而生，阴阳之母也。动之则分，静之则合。无过不及，随曲就伸。
人刚我柔谓之走，我顺人背谓之粘。动急则急应，动缓则缓随。虽变化万端，而
理为一贯！
[2;37;0m这是一串由相当坚硬的[37m玄铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重二斤六两六钱的[1;33m太极之项链[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来相当坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[40m地[2;37;0m:[1;36m完美[2;37;0m [1;33m金[2;37;0m:[1;33m天圣[2;37;0m [36m木[2;37;0m:[1;33m天圣[2;37;0m [32m水[2;37;0m:[1;31m无双[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 巧制:[33m很高[2;37;0m 
白石:[31m精致[2;37;0m 紫石:[32m粗糙[2;37;0m 长生:[1;36m完美[2;37;0m 不老:[33m很高[2;37;0m 
以及一排古篆字【 [1;32m小马[2;37;0m 】。和一些【 [1;32m爪法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "horse");
		set("ownername", "小马");
		set("value", 25000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",32);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",40);
    set("armor_prop/dodge", 66);
    set("armor_prop/parry", 31);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 373);
    set("armor_prop/defense", 40);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 70);
    set("armor_prop/jing", 46);
    set("armor_prop/jingli", 46);
    set("armor_prop/damage", 287);

    set("wtypeA",10);
    set("wtypeB",10);
    set("wtypeC",12);
    set("wtypeD",0);
    set("wtypeE",7);
    set("wtypeF",0);
    set("wtypeG",5);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",7);
    set("wtypeK",0);
    set("wtypeL",3);
    
    
                set("skill", ([
                        "name": "claw",
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