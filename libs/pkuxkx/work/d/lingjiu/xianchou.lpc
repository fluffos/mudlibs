#include <ansi.h>
inherit ROOM;
int do_zou(string);
void init();
void create()
{
  set("short","仙愁门");
  set("long",@LONG
这里就快到缥缈峰绝顶了，在你眼前出现一个石坊，上书『仙愁门』
三个大字，盖因上山之艰辛吧。越往上走，山势越高，缭绕在你身边
的白雾愈来愈浓。往南则是一条山涧，山涧之中云雾缭绕，你根本无
法看清对面。一条铁索(tiesuo)深入云中。
LONG );
  set("outdoors", "lingjiu");
  set("exits",([
      "northwest" : __DIR__"shanlu1",
  ]));
  set("item_desc",([
      "tiesuo" : "这是通往对面的“接天桥”，你也许可以走过(zou)去。\n" ,
  ]));
        set("objects",([
        CLASS_D("lingjiu")+"/shisao" : 1,
      __DIR__"npc/dizi" : random(5),    
                ]));
  set("no_clean_up", 0);
  setup();
}

void init()
{
	add_action("do_zou", "zou");
}

int do_zou(string arg)
{
	object me=this_player(), room,he;
        if (me->query_skill("dodge")<50 && !me->query_temp("lingjiu/ask下山"))
		return notify_fail("你的轻功太差,这铁索如何走的过去?\n");
	if(!arg || arg!="tiesuo")
		return notify_fail("你要走什么？\n");
        if(me->is_busy())
                return notify_fail("你正忙着呢。\n");
	if(!( room = find_object(__DIR__"jietianqiao")) )
		room = load_object(__DIR__"jietianqiao");
        if (me->query_temp("lingjiu/ask下山"))
                message_vision("两个灵鹫弟子走上前来，一边一个扶住你，微笑着把你送过铁索桥。\n",me);
        else
                message_vision("$N踩上铁索，向山涧的对面飘然而去。\n",me);
        me->delete_temp("lingjiu/ask下山");
	if (me->query_temp("lingjiu/leading") && present ("xu zhu",environment(me)))
	{
 	       	he = present ("xu zhu",environment(me));
 		he->do_zoutiesuo("tiesuo");
	}
	me->move(room);
	
        return 1;
}
