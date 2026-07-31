#include <ansi.h> 
#include <armor.h>

inherit ARMOR;

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
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;32m新手之披风[2;37;0m★", ({ "newbie armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
[1;32m新手之披风[2;37;0m这是一件由无比坚硬的精钢加上[1;33m苎麻[2;37;0m制成，重一斤零两九钱的[1;32m新手之披风[2;37;0m。
综合评价[37m绝世无双[2;37;0m 看起来无比坚固，具有[36m不小[2;37;0m的防护力！
这是一件特殊的物品 属性如下:
天灵:[1;32m一般[2;37;0m 白石:[1;32m极差[2;37;0m 紫石:[1;32m极差[2;37;0m
闪电:[1;32m极差[2;37;0m 巧制:[1;32m灭世[2;37;0m 体灵:[1;32m极差[2;37;0m  长生:[1;32m极差[2;37;0m 不老:[1;32m极差[2;37;0m 不灭:[1;32m极差[2;37;0m 
这是一件打造的物品 符字如下:
水:[1;32m不错[2;37;0m 风:[1;32m不错[2;37;0m 地:[1;32m不错[2;37;0m 
上面刻着 可以学习的武功 读书写字 (literate)
LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_give",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 1800);
		set("armor_prop/intelligence",6);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 2);
    set("armor_prop/parry", 2);
    set("armor_prop/attack", 2);


    set("armor_prop/armor", 200);
    set("armor_prop/defense", 2);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 3);
    set("armor_prop/jing", 3);
    set("armor_prop/jingli", 3);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",1);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",1);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",1);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "literate",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 80,              
                ]) );		


		set("material", "default");
    set("sharpness", 12);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";