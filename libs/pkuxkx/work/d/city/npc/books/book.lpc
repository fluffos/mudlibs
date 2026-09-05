//  传记配置文件
//  created by zine 19 Oct 2010

inherit ITEM;
#include <ansi.h>

int i=1;

void init()
	{
		add_action("do_zhuanji", "kan");
	}

void create()
	{
        set_name(WHT"人物传记"NOR, ({ this_object()->query("writer")+" zhuanji","zhuanji", "novel"}));
        if (clonep())
			set_default_object(__FILE__);
        else 
			{
				set("unit", "卷");
				set("long", "这是一卷人物传记，记载了"HIW+this_object()->query("name")+NOR"编写生平的故事，你可以看看(kan)。\n");
            }
        setup();
	}

int do_zhuanji(string arg)
	{
        object me,ob;
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
        me = this_player();
        ob = this_object();
        
        if (ob->query("read"))
        {
            tell_object(me,WHT"你已经开始读这本传记了，好好读完它吧。\n"NOR);
            return 1;
        }
        else
        {
            tell_object(me,color[random(sizeof(color))]+"你翻开了人物传记，并大声朗读。\n"NOR);
            call_out("zhuanji", 4, me);
            ob->set("read",1);
            return 1;
        }
	}

int zhuanji(object me)
{
    object ob=this_object();
    string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
    if (ob->query("context/i"))
    {
        tell_object(me,color[random(sizeof(color))]+ob->query("context/i")+"\n"NOR);
        i=i+1;
        remove_call_out("zhuanji");
        call_out("zhuanji",2,me);
        return 1;
    }
    else
    {
        ob->delete("read");
        return 1;
    }
    
}

