//kaitian_book.c
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"开天剑谱"NOR, ({ "kaitian book", "book" }));
        set_weight(600);
                set("unit", "本");
                set("long",
"这是上古留传下来的神奇剑谱，可遇而不可求的.\n相传上面所载的开天剑法，是上古极强的武功之一。\n");
                set("value", 100);
                set("material", "paper");
                set("skill", ([
                        "name":  "kaitian-jianfa", 
                                      
                        "jing_cost":      50,                           
                        "difficulty":   50,                            
               
                "max_skill": 60, 
                                                                               
                ]) );
}
void init()
{
				remove_call_out("des");
				call_out("des",888,this_player(),this_object());
}
int des(object me,object book)
{
	tell_object(me,HIW"忽然间，剑谱就化为一阵幻影化为乌有了!\n"NOR);
	destruct(book);
	return 1;
}
