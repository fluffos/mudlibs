//flower Taohua Newbie JOB Zine

inherit ITEM;
#include <ansi.h>

void create()
{
    int n;
    string * name =({HIM"玫瑰"NOR,HIW"百合"NOR,MAG"郁金香"NOR,HIR"火鹤花"NOR,HIW"剑兰"NOR,WHT"满天星"NOR,HIY"向日葵"NOR,HIC"兰花"NOR,CYN"马蹄莲"NOR,MAG"薰衣草"NOR});
	string * id =({"mei gui","bai he","yujin xiang","huohe hua","jian lan","mantian xing","xiangri kui","lan hua","mati lian","xunyi cao"});
    n=random(sizeof(name));
    set_name(name[n], ({ id[n], }) );
    set_weight(100);
	set("long", "这是一朵娇艳的"+name[n]+"。\n");
	set("unit", "朵" );
    set("nian",0);
    set("value",0);
    set("no_get",1);
	set("gene_time",time());
	setup();
}

