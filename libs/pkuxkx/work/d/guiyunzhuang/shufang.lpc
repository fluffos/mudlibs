
// Made By:pingpang
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "书房");
        set("long", @LONG
这里是陆乘风的书房，里面有几排书架，靠墙的一张红木书桌(desk)
显得略有气派。书房门楣之上钉着八片铁片，排作八卦形状，却又不似寻
常的八卦那么排得整齐，疏疏落落，歪斜不称。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"zoulang4",
]));
	set("objects",([__DIR__"obj/shelf":1,]));
	set("no_fight",1);
        setup();
        set ("item_desc", ([
                "desk" :
"这是一张很结实的红木书桌，桌面上摆着只狼毫笔，磨了一半的墨，\n"
"还有一叠未用的白纸。\n"
"你可以抬起(lift)它.\n"
        ])  ) ;

        set("no_clean_up", 0);

        setup();
}
void init()
{
    add_action("do_lift", "lift");
	add_action("do_search","search");
    add_action("do_zhao","zhao");
}

int do_zhao()
{
    object me=this_player();
    int i,count=0;
    object * all;
    object qimen;
    if (me->query("family/family_name")!="桃花岛")
    {
        tell_object(me,"一个声音冷冷道：“阁下与我派素无渊源，不知这是何意？”\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"看你手忙脚乱的，等会再来吧。\n");
        return 1;
    }
    all=all_inventory(me);
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("is_qimenbook"))
        {
            count=count+1;
        }
    }
    if (count>0)
    {
        tell_object(me,"你身上不是就有一本吗？不要贪得无厌！\n");
        return 1;
    }
    if (random(1000)>350)
    {
        message_vision("你在这里找了半天，却什么都没有找到。\n",me);
        return 1;
    }
    qimen=new("/d/taohuadao/obj/qimen");
    qimen->move(me);
    message_vision("$N找到了一本"+qimen->name()+"，欣喜若狂。\n",me);
    tell_object(me,BLINK+HIY+"奇门遁甲的著作，你只有在这里才能集中精神阅读(du)。\n"NOR);
    return 1;
}

int do_lift(string arg)
{
        object paper;
	paper = new(__DIR__"obj/paper");

        if( !arg || arg=="" ) return 0;

        if( arg=="desk" ) {
                if (!query("hs_trigger")){
                message_vision(
"$N轻轻的抬了一下书桌，沉重的书桌被$N抬了起来...，突然从书桌和\n"
"墙壁之间飘落出一张纸。\n", this_player());
                paper->move(__FILE__);
                set("hs_trigger", 1);
                return 1;
                }
                message_vision(
"$N轻轻的抬了抬书桌，沉重的书桌并没有被$N抬起。\n", this_player());
                return 1;
        }
        return 0;
}
int do_search(string arg)
{
	object ob;
	if(!arg||arg!="book")
		return notify_fail("你想找什么?\n");
	if(arg=="shu"||arg=="book")
		{if(this_player()->query_temp("been_get"))
			return notify_fail("你找得满头大汗，可是什么也没有找到。\n");
		else
			{message_vision("$N找了老半天，终于从书架上模出一本内功心法的书来。\n",this_player());
			 ob=new(__DIR__"obj/force_book");
			 ob->move(this_player());
		         this_player()->set_temp("been_get",1);
			 return 1;
			}
		}
}

		
