// throwing_book.cc.c
inherit ITEM;
void create()
{
        set_name("天山器法", ({ "tianshan qifa", "book","throwing book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
"这是天山派的秘籍，封面上写著「天山器法」.\n");
                set("value", 100);
                set("material", "paper");
                set("skill", ([
                        "name":  "throwing",
                "exp_required": 1000,
                        "jing_cost":      20,
                        "difficulty":   20,
                "max_skill": 100,
                ]) );
               }
}
