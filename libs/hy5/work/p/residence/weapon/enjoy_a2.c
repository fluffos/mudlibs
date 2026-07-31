#include <ansi.h> 
#include <armor.h>

inherit WRISTS;

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
	      set_name("[1;31m麒麟臂[2;37;0m", ({ "taiji wrists", "wrists" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
		set("long", @LONG
[1;33m太极者，无极而生，阴阳之母也。动之则分，静之则合。无过不及，随曲就伸。
人刚我柔谓之走，我顺人背谓之粘。动急则急应，动缓则缓随。虽变化万端，而
理为一贯！
[2;37;0m这是一双由无比坚硬的[37m玄铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重四斤七两三钱的[1;33m太极之护腕[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[36m木[2;37;0m:[1;32m魔王[2;37;0m [31m火[2;37;0m:[1;31m创世[2;37;0m [33m土[2;37;0m:[1;31m开元[2;37;0m [1;35m风[2;37;0m:[1;36m完美[2;37;0m 

上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 天灵:[32m粗糙[2;37;0m 天玄:[32m粗糙[2;37;0m 巧制:[33m很高[2;37;0m 
体灵:[34m细碎[2;37;0m 白石:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m花无棱[2;37;0m 】。和一些【 [1;32m拳法[2;37;0m 】的技巧。

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
		set("armor_prop/intelligence",56);
		set("armor_prop/strength",48);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",34);
    set("armor_prop/dodge", 34);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 266);
    set("armor_prop/defense", 56);
    
    set("armor_prop/neili", 40);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 164);

    set("wtypeA",0);
    set("wtypeB",9);
    set("wtypeC",6);
    set("wtypeD",14);
    set("wtypeE",13);
    set("wtypeF",7);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "cuff",
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