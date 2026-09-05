inherit ITEM;
void create()
{
        set_name("燕青拳谱", ({ "yanqing quanpu", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
"这是记载着燕青生平所学拳法的秘籍，封面上写著「燕青拳谱」.\n留赠有缘人，读完后请放回(huan)原处。\n");
                set("value", 0);
                set("no_drop",1);
                set("no_put",1);
                set("material", "paper");
                set("skill", ([
                        "name":  "yanqing-quan",  
                        "exp_required": 100000,  
                        "jing_cost":      25,                           
                        "difficulty":   25,                            
                        "max_skill": 100, 
                                                                               

                ]) );
               }
}
