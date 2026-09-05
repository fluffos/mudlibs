//bingqipu.c
#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
void create()
{
        set_name(HIC"江湖兵器谱"NOR, ({ "bingqi pu", "book","pu" }));
        set_weight(600);
                set("unit", "本");
                set("unique",1);                
                set("long",
"这是一本记录了江湖中所有特殊兵器特性及鉴定方式的奇书，乃是当年百晓生集平生之所学吐血编纂而成，可谓一书在手，尽识天下之兵器！\n
也可以从上面学习鉴定之术，学会后可以自己对物品进行粗鉴(identify)。\n");
                set("value", 1000000);
                set("material", "paper");
                set("skill", ([
                        "name":  "identification", 
                                                "exp_required": 300000,  
                        "jing_cost":      20,                           
                        "difficulty":   20,                            
                "max_skill": 50, 
                                                                               
                ]) );
        setup();
                
}
void init()
{
        ::init();
				remove_call_out("des");
				call_out("des",3600,this_object());
}
int des(object book)
{
	message_vision(HIW"忽然间一阵风吹来，$N变成了碎纸片，洒落了一地!\n"NOR,book);
	destruct(book);
	return 1;
}
