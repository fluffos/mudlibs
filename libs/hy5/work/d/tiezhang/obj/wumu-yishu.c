// wumu-yishu.c
// zqb

#include <ansi.h>

inherit ITEM;
void init()
{
        add_action("do_du", "dushu");
}

void create()
{
	set_name( "「武穆遗书」", ({ "wumu yishu", "yishu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			GRN
			"\n这就是岳武穆临死前留下的“破金要诀”。\n"
			"只见第一页上写了十八个大字：\n"
                        "“重搜选，谨训习”\n"
                        "“公赏罚，明号令”\n"
                        "“严纪  ，同甘苦”\n"
                        "“你可以(dushu)”\n"
               NOR
		);
		set("value", 10000);
		set("material", "paper");
//		set("no_get", 1);
//		set("no_drop", 1);
		set("treasure", 1);
	}
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        
if (!id(arg))
	return 0;

//if( me->query("wumu+int")) 
if ((int)this_player()->query("mark/+int")) 
        {
        write("这可真是一部兵法奇书呀！你已经看过了，但为了不让金人获得其中的兵法，你就把书给毁掉了。\n");
        destruct(this_object());
        }
        else
        {
        me->add("int", 1);
        write(HIY"你随手翻阅，但见一字一句之间，无不阐明临阵对敌的妙法，不禁大声赞叹！\n"NOR);
        write(HIR"你的悟性提高了！\n"NOR);
        write(HIY"你看过了,为了不让金人获得其中的兵法，就把书给毁掉了。\n"NOR);
        this_player()->set("mark/+int", 1); 
        destruct(this_object());
        }
        return 1;
}
