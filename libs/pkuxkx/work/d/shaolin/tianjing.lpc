// Room: /d/shaolin/tianjing
// Date: YZC 96/01/19
inherit ROOM;
#include <ansi.h>
string look_stone();
void create()
{
        set("short", "天井");
        set("long", @LONG
这是戒律院前的天井。这里有一口古井，好多年前，这口井就被
一块大石头(stone)盖住。
LONG
        );

        set("exits", ([
                "west" : __DIR__"guangchang3",
        ]));
        set("outdoors", "shaolin");
          set("item_desc", ([ /* sizeof() == 2 */
        "stone" :        (: look_stone : ),
          ]));
        setup();
}
string look_stone()
{
    object me;
    me = this_player();
    return HIB"这是一块巨石，扣在了古井口上，好像可以移动它，(move)。\n"NOR;
}
void init()
{
        add_action("do_move", "move");
}
int do_move(string arg)
{
        object me;
        object* inv;
        int i;
        me = this_player();
        if( !arg || arg == "" ) 
        return notify_fail("你要移动什么?\n");
         if( ((int)me->query("max_neili")<1500) || ((int)me->query("neili") < 1500) )
        return notify_fail("你这点内力不要尝试了吧。\n");
        if( arg == "stone")
        {
	        if( (me->query("family"))&& me->query("family/family_name") == "少林派" && me->query("family/master_id")=="wuming laoseng")
	{
        message_vision("$N双脚扎马步，一弯腰把石头移开了，并且伸头往井里看，突然一股吸力将$N吸入井中\n"+
        "那块巨石自动合上了。\n",me);    
        inv = deep_inventory(me);
        for (i=sizeof(inv)-1;i>=0;i--)
        {
        	if (userp(inv[i]))
        	{
                        tell_object(me,"无名老僧突然出现在你面前，声色俱厉道：你怎敢不听我的教诲擅自带人进入这里！\n");
        		tell_object(me,"你被无名老僧赶了出去。\n");
        		me->move("/d/shaolin/tianjing");
        		return 1;
        	}
        }
        me->move("/d/shaolin/hantan4");
	 return 1;
	 }
	 else
                  {
                 me->start_busy(3);
                me->add("neili",-500);
                message_vision("$N双脚扎马步，一弯腰把石头移开了，并且伸头往井里看，发现这原来就是普通的一口古井。\n",me);
        }
        return 1;
        }
        else
        return notify_fail("你要干什么？\n");
}
