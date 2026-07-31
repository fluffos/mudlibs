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
	      set_name("[1;31m魅影[2;37;0m", ({ "kunlun armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
[1;36m	笑江湖浪迹十年游，空负少年头。
	对铜陀巷泊，吟情渺渺，心事悠悠！ 
	酒令诗残梦断，南国正清愁。 
	把剑凄然望，无处招归舟。 
 
	明月天涯路远，问谁留楚佩，弄影中洲？
	数英雄儿女，俯仰古今愁。
	难消受灯昏罗帐，伥昙花一现恨难休！
	飘零惯，金戈铁马，拼葬荒丘！ 
[2;37;0m这是一件由极为坚硬的[37m玄铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重五斤零两七钱的[1;36m昆仑之披风[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来极为坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[36m木[2;37;0m:[1;31m无双[2;37;0m [32m水[2;37;0m:[1;33m天圣[2;37;0m [1;35m风[2;37;0m:[1;31m无双[2;37;0m 
[1;37m雷[2;37;0m:[1;31m无双[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 巧制:[34m细碎[2;37;0m 
紫石:[31m精致[2;37;0m 周天:[1;36m完美[2;37;0m 长生:[35m标准[2;37;0m 不老:[35m标准[2;37;0m 
以及一排古篆字【 [1;32m两果[2;37;0m 】。和一些【 [1;32m手法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "here");
		set("ownername", "两果");
		set("value", 25000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",48);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 60);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 332);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 73);
    set("armor_prop/qi", 59);
    set("armor_prop/jing", 59);
    set("armor_prop/jingli", 59);
    set("armor_prop/damage", 246);

    set("wtypeA",0);
    set("wtypeB",12);
    set("wtypeC",10);
    set("wtypeD",6);
    set("wtypeE",0);
    set("wtypeF",12);
    set("wtypeG",12);
    set("wtypeH",6);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "hand",
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