//guishoushe_book.c
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"鬼手暗器秘籍上册"NOR, ({ "guishou book", "book" }));
        set_weight(600);
                set("unit", "本");
                set("long",
"这是鬼手暗器手法的上册，是鬼手门的不传之秘.\n相传上面所载的鬼手暗器，是上古极强的武功之一。\n");
                set("value", 100000);
                set("no_store", 1);
                set("no_sell", 1);
                set("no_pawn", 1);
                set("material", "paper");
				set("no_sell",1);
                set("skill", ([
                        "name":  "guishoushe", 
                                      
                        "jing_cost":    100,                           
                        "difficulty":   100,                            
               
                "max_skill": 100,
				"exp_required": 100000,
                                                                               
                ]) );
}
void init()
{
				remove_call_out("des");
				call_out("des",30,this_player(),this_object());
}
int des(object me,object book)
{
	tell_object(me,HIW"忽然间，秘籍就化为一阵幻影化为乌有了!\n"NOR);
	destruct(book);
	return 1;
}
