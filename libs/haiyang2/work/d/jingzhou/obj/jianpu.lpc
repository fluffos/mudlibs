// ITEM: /d/jingzhou/obj/jianpu.c
// Date: 99/05/31 by Byt


inherit ITEM;

void create()
{
        set_name("连城剑谱", ({ "liancheng jianpu", "jianpu" }));
        set_weight(600); 
        set("unique", 1); 
	if( clonep() )
		set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本薄薄的黄纸书，书页的左上角被撕去了小小的一角。\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name": "liancheng-jian",
                        "exp_required": 0,
                        "jing_cost":    30,
                        "difficulty":   20,
                 	"max_skill": 31,
                ]) );                
	     }
 
}

