// jianlun.c

inherit ITEM;

void create()
{
        set_name("剑论", ({ "sword book" ,"book"}));
        set_weight(600);
        set("unique", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "这是一卷明教前代弟子所著的书简，上面有一些模糊的图象，似乎\n"
                        "是画的一些击剑的小人形。\n");
                set("value", 5000);
                set("material", "paper");
                set("skill", ([
                        "name":               "sword",     
                       "exp_required":  100,                                                                                                          "jing_cost":   20,                             
                        "difficulty":   25,                                                                                                                "max_skill":   60,  ]));                                                                                
        }
}

