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
	      set_name("[1;37m昆仑镜[2;37;0m", ({ "yuchang hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
		set("long", @LONG
[31m鱼肠轻巧无比，能开天辟地，荡妖除魔！
[2;37;0m这是一副由无比坚硬的[1;36m万年寒冰铁[2;37;0m加上[1;33m龙茧蚕丝[2;37;0m制成，重四斤八两二钱的[31m鱼肠之手套[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比坚固，具有[32m水准以上[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;34m举世[2;37;0m [31m火[2;37;0m:[1;35m绝世[2;37;0m [33m土[2;37;0m:[1;35m绝世[2;37;0m [1;35m风[2;37;0m:[1;35m绝世[2;37;0m 
[1;37m雷[2;37;0m:[1;35m绝世[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 天宇:[33m很高[2;37;0m 巧制:[1;34m举世[2;37;0m 
白石:[33m很高[2;37;0m 闪电:[32m粗糙[2;37;0m 
长生:[31m精致[2;37;0m 不老:[31m精致[2;37;0m 威力:[33m很高[2;37;0m 
以及一排古篆字【 [1;32m看看[2;37;0m 】。和一些【 [1;32m锤法[2;37;0m 】的技巧。

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
		set("value", 36000);
		set("armor_prop/intelligence",56);
		set("armor_prop/strength",45);
		set("armor_prop/karey",48);
		set("armor_prop/percao",40);
		set("armor_prop/dexerity",32);
		set("armor_prop/constitution",40);
    set("armor_prop/dodge", 49);
    set("armor_prop/parry", 40);
    set("armor_prop/attack", 40);


    set("armor_prop/armor", 407);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 62);
    set("armor_prop/jing", 65);
    set("armor_prop/jingli", 65);
    set("armor_prop/damage", 1276);

    set("wtypeA",8);
    set("wtypeB",6);
    set("wtypeC",6);
    set("wtypeD",11);
    set("wtypeE",11);
    set("wtypeF",11);
    set("wtypeG",11);
    set("wtypeH",0);
    set("wtypeI",5);
    set("wtypeJ",0);
    set("wtypeK",8);
    set("wtypeL",1);
    
    
                set("skill", ([
                        "name": "hammer",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 24);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";