#include <ansi.h> 
#include <armor.h>

inherit WAIST;

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
	      set_name("[1;33m霸王之证[2;37;0m", ({ "taibai waist", "waist" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
		set("long", @LONG
[1;37m
		赵客缦胡缨  吴钩霜雪明		银鞍照白马  飒沓如流星
		十步杀一人  千里不留行		事了拂衣去  深藏身与名
		闲过信陵饮  脱剑膝前横		将炙□朱亥  持觞劝侯嬴
		三杯吐然诺  五狱倒为轻		眼花耳热後  意气素霓生
		救赵挥金槌  邯郸先震惊		千秋二壮士  喧赫大梁城
		纵死侠骨香  不惭世上英		谁能书阁下  白首太玄经
[2;37;0m这是一条由绝对坚硬的[37m玄铁[2;37;0m加上[37m天蚕丝[2;37;0m制成，重六斤三两九钱的[1;37m太白之腰带[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来绝对坚固，具有[34m不错[2;37;0m的防护力！
上面刻了几个古符号：
[32m水[2;37;0m:[1;33m天圣[2;37;0m [31m火[2;37;0m:[1;31m开元[2;37;0m [33m土[2;37;0m:[1;31m创世[2;37;0m [1;35m风[2;37;0m:[35m标准[2;37;0m 
[1;37m雷[2;37;0m:[1;31m无双[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 巧制:[33m很高[2;37;0m 
白石:[35m标准[2;37;0m 周天:[1;36m完美[2;37;0m 长生:[31m精致[2;37;0m 不老:[35m标准[2;37;0m 威力:[35m标准[2;37;0m 
以及一排古篆字【 [1;32m地图一号[2;37;0m 】。和一些【 [1;32m爪法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "maper");
		set("ownername", "地图一号");
		set("value", 25000);
		set("armor_prop/intelligence",56);
		set("armor_prop/strength",56);
		set("armor_prop/karey",48);
		set("armor_prop/percao",56);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 59);
    set("armor_prop/parry", 56);
    set("armor_prop/attack", 56);


    set("armor_prop/armor", 400);
    set("armor_prop/defense", 56);
    
    set("armor_prop/neili", 74);
    set("armor_prop/qi", 65);
    set("armor_prop/jing", 50);
    set("armor_prop/jingli", 50);
    set("armor_prop/damage", 301);

    set("wtypeA",7);
    set("wtypeB",6);
    set("wtypeC",10);
    set("wtypeD",13);
    set("wtypeE",14);
    set("wtypeF",5);
    set("wtypeG",12);
    set("wtypeH",6);
    set("wtypeI",0);
    set("wtypeJ",6);
    set("wtypeK",5);
    set("wtypeL",7);
    
    
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