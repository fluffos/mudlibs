#include <ansi.h> 
#include <armor.h>

inherit HEAD;

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
	      set_name("[1;31m零丁[2;37;0m", ({ "shentong head", "head" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
		set("long", @LONG
[1;31m天兵神通，走势要平善，气要随行，两眼顾尖，气沉两足稳，
身法需自然，身行如飞燕，身落如停风，收如花絮，刺如钢钉！
[2;37;0m这是一顶由无比坚硬的[31m万年神铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重五斤五两九钱的[1;31m神通之头盔[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[1;31m魔[2;37;0m:[1;34m举世[2;37;0m [32m水[2;37;0m:[1;34m举世[2;37;0m [31m火[2;37;0m:[1;31m创世[2;37;0m [33m土[2;37;0m:[1;31m创世[2;37;0m [1;35m风[2;37;0m:[1;31m开元[2;37;0m 
[1;34m电[2;37;0m:[1;31m无双[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 福源:[32m粗糙[2;37;0m 
巧制:[31m精致[2;37;0m 
闪电:[31m精致[2;37;0m 
长生:[32m粗糙[2;37;0m 不老:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m两果[2;37;0m 】。和一些【 [1;32m掌法[2;37;0m 】的技巧。

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
		set("armor_prop/intelligence",40);
		set("armor_prop/strength",40);
		set("armor_prop/karey",30);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 62);


    set("armor_prop/armor", 321);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 39);
    set("armor_prop/jing", 38);
    set("armor_prop/jingli", 38);
    set("armor_prop/damage", 207);

    set("wtypeA",6);
    set("wtypeB",0);
    set("wtypeC",8);
    set("wtypeD",14);
    set("wtypeE",14);
    set("wtypeF",13);
    set("wtypeG",0);
    set("wtypeH",12);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",8);
    
    
                set("skill", ([
                        "name": "strike",
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