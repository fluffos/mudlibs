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
	      set_name("[1;31m魅影[2;37;0m", ({ "shentong armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
[1;31m天兵神通，走势要平善，气要随行，两眼顾尖，气沉两足稳，
身法需自然，身行如飞燕，身落如停风，收如花絮，刺如钢钉！
[2;37;0m这是一件由极为坚硬的[37m玄铁[2;37;0m加上[37m天蚕丝[2;37;0m制成，重三斤八两零钱的[1;31m神通之披风[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来极为坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[32m水[2;37;0m:[1;34m举世[2;37;0m [31m火[2;37;0m:[1;33m天圣[2;37;0m [33m土[2;37;0m:[1;33m天圣[2;37;0m [1;35m风[2;37;0m:[31m精致[2;37;0m 
[1;34m电[2;37;0m:[1;35m绝世[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m毁天[2;37;0m 巧制:[31m精致[2;37;0m 
白石:[33m很高[2;37;0m 紫石:[1;36m完美[2;37;0m 闪电:[32m粗糙[2;37;0m 
周天:[1;36m完美[2;37;0m 
以及一排古篆字【 [1;32m花无棱[2;37;0m 】。和一些【 [1;32m招架[2;37;0m 】的技巧。

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
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 47);
    set("armor_prop/parry", 73);
    set("armor_prop/attack", 32);


    set("armor_prop/armor", 330);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 73);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 191);

    set("wtypeA",6);
    set("wtypeB",7);
    set("wtypeC",8);
    set("wtypeD",10);
    set("wtypeE",10);
    set("wtypeF",6);
    set("wtypeG",0);
    set("wtypeH",11);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "parry",
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