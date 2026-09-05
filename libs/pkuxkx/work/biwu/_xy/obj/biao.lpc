#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIB"伪劣唐门暗器"NOR, ({"biao", "anqi","tangmen anqi" }) );
        set_weight(100);
        if( clonep() )
			set_default_object(__FILE__);
        else 
			{
				set("unit", "个");
				set("long", @LONG 这个东西很像唐门暗器毒蒺藜，还用靛蓝在外面描了一圈，让人觉得仿佛涂
有剧毒。它似乎是纸叠的。你可以把它扔(ren)出去。
LONG
					);
				set("value", 1);        
			}
        setup();
}

void working(object me)
{	
	object* allob;
    object ob;
	allob = all_inventory(environment(me));
    message("vision",HIB"蓝色暗器突然炸开，更多小碎片以不规则的曲线飞行！\n"NOR,environment(this_player()));
    for(int i=0;i<sizeof(allob);i++)
		{    
			if(!objectp(allob[i])) continue;
            ob = allob[i];  
            if(!living(ob)) continue;
			if(ob==me) continue;
            tell_object(ob,HIR"这种古怪的暗器震慑了当场，瞬间你呆若木鸡。\n"NOR);
			ob->add_busy(5);
		}
	me->start_busy(1);
	destruct(this_object());
	return;
		
}

int do_throw(string arg)
{
    object me = this_player();
    
	if(stringp(arg) && (arg == "biao" || arg=="anqi" || arg=="tangmen anqi"))
		{
			
            message("vision",sprintf(HIW"%s大喝一声，看唐门暗器，一支蓝色的暗器不规则的在空中飞行。\n"NOR,me->query("name")),environment(this_player()));                     
            working(me);
			return 1;               
        }
	else
		{
			tell_object(me,"你要扔什么？\n");
			return 1;
		}
   
}

void init()
{
	add_action("do_throw", ({ "throw", "ren" }));
}
