// hanxiucao.c
//含羞草
//mady:pingpang
#include <ansi.h>
inherit ITEM;
void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name(GRN"含羞草"NOR,({"hanxiu cao","cao"}));
        set("unit", "根");
        set("long", "这是一根绿叶黄根的含羞草。\n");
        set("value", 5000);
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("你要吃什么？\n");
	if(this_player()->query_skill_mapped("force")!="bihai-shengong")
		{
			this_player()->add("max_neili",-random(10));
			message_vision("$N吃下一根"GRN"含羞草"NOR"只觉得头重脚轻,摇摇欲坠，好象是与你所练的内功相违背。\n",this_player());
			this_player()->unconcious();
			destruct(this_object());
			return 0;
		}
	else
	    {	if(this_player()->query("max_neili")>=1000)
			{
				this_player()->add("max_neili",-random(10));
message_vision("$N由于内力过高，含羞草似乎没有起什么作用",this_player());
				destruct(this_object());
				return 0;
			}
		if(this_player()->query("PKS")>=20)
			{
				this_player()->add("max_neili",-random(10));
message_vision("$N由于杀人太多，吃下的含羞草起作用了。",this_player());
				destruct(this_object());
				return 0;
			}		
		else
		  {
this_player()->add("max_neili",(random(3)-1));
			message_vision("$N吃下了一根含羞草，不知道是福还是祸.\n",this_player());
			destruct(this_object());
			return 1;
			}
	}
}


