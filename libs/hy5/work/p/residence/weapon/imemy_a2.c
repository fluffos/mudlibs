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
	      set_name("[34m海洋之护[2;37;0m", ({ "zhanlu shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
		set("long", @LONG
[31m湛卢威力、锋利、坚硬都冠绝当世，乃千古神兵！
[2;37;0m这是一面由无比坚硬的[1;36m万年寒冰铁[2;37;0m加上[1;33m龙茧蚕丝[2;37;0m制成，重九斤二两一钱的[31m湛卢之盾[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比坚固，具有[35m极其可怕[2;37;0m的防护力！
上面刻了几个古符号：
[40m地[2;37;0m:[1;32m魔王[2;37;0m [1;36m人[2;37;0m:[1;33m天圣[2;37;0m [36m木[2;37;0m:[31m精致[2;37;0m [1;35m风[2;37;0m:[1;33m天圣[2;37;0m 
[1;37m雷[2;37;0m:[1;31m开元[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 绝代:[32m粗糙[2;37;0m 巧制:[1;36m完美[2;37;0m 
紫石:[1;32m魔王[2;37;0m 闪电:[1;32m魔王[2;37;0m 
周天:[1;36m完美[2;37;0m 长生:[35m标准[2;37;0m 不老:[35m标准[2;37;0m 
以及一排古篆字【 [1;32m渡渡[2;37;0m 】。和一些【 [1;32m爪法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "imemy");
		set("ownername", "渡渡");
		set("value", 36000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",40);
		set("armor_prop/karey",0);
		set("armor_prop/percao",37);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 94);
    set("armor_prop/attack", 91);


    set("armor_prop/armor", 876);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 71);
    set("armor_prop/qi", 52);
    set("armor_prop/jing", 59);
    set("armor_prop/jingli", 59);
    set("armor_prop/damage", 93);

    set("wtypeA",0);
    set("wtypeB",6);
    set("wtypeC",0);
    set("wtypeD",5);
    set("wtypeE",0);
    set("wtypeF",10);
    set("wtypeG",13);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",9);
    set("wtypeK",10);
    set("wtypeL",8);
    
    
                set("skill", ([
                        "name": "claw",
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