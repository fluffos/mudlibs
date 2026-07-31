#include <ansi.h> 
#include <armor.h>

inherit SHIELD;

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
	      set_name("[1;33m太极之盾[2;37;0m", ({ "taiji shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
		set("long", @LONG
[1;33m太极者，无极而生，阴阳之母也。动之则分，静之则合。无过不及，随曲就伸。
人刚我柔谓之走，我顺人背谓之粘。动急则急应，动缓则缓随。虽变化万端，而
理为一贯！
[2;37;0m这是一面由无比坚硬的[37m玄铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重四斤七两八钱的[1;33m太极之盾[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比坚固，具有[32m水准以上[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;34m举世[2;37;0m [32m水[2;37;0m:[1;34m举世[2;37;0m [1;35m风[2;37;0m:[35m标准[2;37;0m 
[1;37m雷[2;37;0m:[1;31m创世[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 巧制:[1;36m完美[2;37;0m 
紫石:[32m粗糙[2;37;0m 闪电:[33m很高[2;37;0m 
长生:[31m精致[2;37;0m 不老:[34m细碎[2;37;0m 
以及一排古篆字【 [1;32m文小[2;37;0m 】。和一些【 [1;32m鞭法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "name");
		set("ownername", "文小");
		set("value", 25000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 31);
    set("armor_prop/attack", 41);


    set("armor_prop/armor", 234);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 69);
    set("armor_prop/jing", 26);
    set("armor_prop/jingli", 26);
    set("armor_prop/damage", 0);

    set("wtypeA",8);
    set("wtypeB",0);
    set("wtypeC",8);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",5);
    set("wtypeG",14);
    set("wtypeH",0);
    set("wtypeI",0);
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