//yanyu 燕语古琴
inherit ITEM;
void create()
{
        set_name("燕语古琴", ({ "yanyu qin", "qin" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "具");
                set("long","这是一具短琴，琴身陈旧，显是古物，琴尾刻着两个篆字“燕语”，你可以弹(play)它。\n");
                set("value", 70000);
               	set("material", "wood");
               	set("music", "qin");
               }
}
void init()
{
        add_action("do_play", "play");
}

int do_play(string arg)
{
        if (!id(arg))
                return notify_fail("你要演奏什么？\n");
        if (this_player()->query_skill("music",1)<30)
        	{
      say(this_player()->name() + "一挽袖子，故作风雅地弹起琴来，但却不成调子，只听得四周的麻雀乌鸦都随着琴声一唱一和，甚是嘈杂。\n");
      write(this_player()->name() + "一挽袖子，故作风雅地弹起琴来，但却不成调子，只听得四周的麻雀乌鸦都随着琴声一唱一和，甚是嘈杂。\n");
      return 1;
        	}
        switch( random(2) ) 
        {
                case 1:
      say(this_player()->name() + "盘膝坐下，拿出古琴调了调弦，便如行云流水一般地演奏开来，忽如空山鸟语，忽如百鸟朝凤，忽而安祥平和，忽而剑拔弩张，令人为之倾倒。\n");
			write(this_player()->name() + "盘膝坐下，拿出古琴调了调弦，便如行云流水一般地演奏开来，忽如空山鸟语，忽如百鸟朝凤，忽而安祥平和，忽而剑拔弩张，令人为之倾倒。\n");
                break;
                case 0:
      say(this_player()->name() + "拿出一张古琴，悠然地弹了起来。那幽怨琴声似乎在诉说一个久远的故事，让人黯然神伤。\n");
			write(this_player()->name() + "拿出一张古琴，悠然地弹了起来。那幽怨琴声似乎在诉说一个久远的故事，让人黯然神伤。\n");
                break;
        }
        return 1;
}

