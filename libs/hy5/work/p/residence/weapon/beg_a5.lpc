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
	      set_name("[1;33m炼妖壶[2;37;0m", ({ "haoqi wrists", "wrists" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
		set("long", @LONG
[1;32m天地浩气之神兵，扫魔除妖，为国为民，侠之大者！
[2;37;0m这是一双由无比坚硬的[37m玄铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重六斤六两三钱的[1;32m浩气之护腕[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[36m木[2;37;0m:[1;32m魔王[2;37;0m [32m水[2;37;0m:[1;31m无双[2;37;0m [31m火[2;37;0m:[1;31m无双[2;37;0m [1;35m风[2;37;0m:[1;36m完美[2;37;0m 
[1;34m电[2;37;0m:[35m标准[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m毁天[2;37;0m 天宇:[32m粗糙[2;37;0m 天渊:[32m粗糙[2;37;0m 巧制:[31m精致[2;37;0m 
白石:[33m很高[2;37;0m 紫石:[35m标准[2;37;0m 威力:[34m细碎[2;37;0m 
以及一排古篆字【 [1;32m看看[2;37;0m 】。和一些【 [1;32m斧法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "beg");
		set("ownername", "看看");
		set("value", 25000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",35);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",33);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 49);
    set("armor_prop/parry", 57);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 134);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 27);

    set("wtypeA",0);
    set("wtypeB",9);
    set("wtypeC",12);
    set("wtypeD",12);
    set("wtypeE",0);
    set("wtypeF",7);
    set("wtypeG",0);
    set("wtypeH",5);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "axe",
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