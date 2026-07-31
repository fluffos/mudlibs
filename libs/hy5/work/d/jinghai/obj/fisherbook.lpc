inherit ITEM;

void create()
{
        set_name("渔民经验", ({ "fisherbook" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "本");
                set("long",
                        "这本书的纸张都已经泛黄了，只有一些字迹模糊的字句，上面\n"
                        "提到一些出海打鱼之类的方法什麽的。\n");
                set("value", 800);
                set("material", "paper");
                set("skill", ([
                        "name":         "unarmed", 
                        "exp_required": 5000,    
                        "sen_cost":     20,      
                        "difficulty":   25,      
                        "max_skill":    91,   
                ]) );
        }
}

