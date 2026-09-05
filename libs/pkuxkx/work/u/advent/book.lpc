//book.c
#include <ansi.h>
inherit ITEM;
void create()
{       

        set_name(MAG"发呆大法"NOR, ({ "fadai dafa", "dafa" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", HIC"这是一本无聊的小说，\n大侠们闲暇的时候总喜欢翻翻。\n比较适合大米们阅读。"NOR);
		set("value", 10);
		set("material", "paper");
                		
	}
}
void init()
{
        add_action("do_read","read");
        

}
int do_read(string arg)
{
        if( !arg || arg != "dafa" )
        {
                write("你想读什么? \n");
                return 1;
        }
        message_vision(HIG"$N从破布袋里掏出本《发呆大法》，看了起来。\n"NOR, this_player());
        if ( (int)this_player()->query("combat_exp") > 2500000)
        {
         message_vision(HIW"$N的发呆大法进步了！\n"NOR, this_player());
        }
        else
        {
         message_vision(HIR"$N手舞足蹈，看起来是练习发呆大法走火入魔啦！\n"NOR, this_player());
         
         }
        return 1;
}

