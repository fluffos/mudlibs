// sword_book.cc
inherit ITEM;
void create()
{
        set_name("飞沙走石十三式", ({ "blade book", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
"这是田伯光的刀法秘籍，封面上写著「飞沙走石十三式刀法」.\n");
                set("value", 100);
                set("material", "paper");
                set("skill", ([
                        "name":  "blade",  
   "exp_required": 1000,  
                                      
                        "jing_cost":      20,                           
                        "difficulty":   20,                            
               
                "max_skill": 100, 
                                                                               
                ]) );
               }
}
