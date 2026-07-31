#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

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
	      set_name("[1;33m东皇钟[2;37;0m", ({ "fengyun cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", @LONG
[1;35m所谓风云际会，天地变色！仗此行千里，老魔小丑，岂堪一击！
[2;37;0m这是一件由无比坚硬的[31m万年神铁[2;37;0m加上[1;37m冰蚕丝[2;37;0m制成，重九斤八两八钱的[1;35m风云之服装[2;37;0m。
综合评价[1;36m无双无对[2;37;0m 看起来无比坚固，具有[31m无与伦比[2;37;0m的防护力！
上面刻了几个古符号：
[37m天[2;37;0m:[1;31m创世[2;37;0m [1;31m魔[2;37;0m:[1;32m魔王[2;37;0m [36m木[2;37;0m:[1;31m创世[2;37;0m [33m土[2;37;0m:[1;31m无双[2;37;0m [1;35m风[2;37;0m:[1;31m创世[2;37;0m 
[1;37m雷[2;37;0m:[1;33m天圣[2;37;0m 
上面还刻了一些符字：
坚硬:[1;31m毁天[2;37;0m 绝代:[34m细碎[2;37;0m 巧制:[35m标准[2;37;0m 
白石:[1;36m完美[2;37;0m 紫石:[32m粗糙[2;37;0m 闪电:[33m很高[2;37;0m 
长生:[33m很高[2;37;0m 不老:[32m粗糙[2;37;0m 
以及一排古篆字【 [1;32m看看[2;37;0m 】。和一些【 [1;32m内功[2;37;0m 】的技巧。

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
		set("armor_prop/strength",32);
		set("armor_prop/karey",0);
		set("armor_prop/percao",26);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 74);
    set("armor_prop/parry", 31);
    set("armor_prop/attack", 40);


    set("armor_prop/armor", 881);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 42);
    set("armor_prop/jing", 35);
    set("armor_prop/jingli", 35);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",14);
    set("wtypeC",0);
    set("wtypeD",4);
    set("wtypeE",12);
    set("wtypeF",14);
    set("wtypeG",10);
    set("wtypeH",0);
    set("wtypeI",14);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",9);
    
    
                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 18);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";