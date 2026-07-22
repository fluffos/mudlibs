// jiudaoguai3.c


inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIW "九十九道拐" NOR);
	set("long", @LONG
这是著名的「九十九道拐」，道路纡曲陡竖，千折百回。据说过去曾有个
百余岁的疯僧至此，见一巨蟒挡路，便念咒驱蟒。但人们得知此处有巨蟒出没
后，便再也无人敢碰这里的草木，并以「龙居」名之。由此东可至千佛庵，西
达九老洞。
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"jiudaoguai2",
		"westup" : __DIR__"jiudaoguai4",
	]));

	set("outdoors", "峨嵋山");
	setup();
}

void init()
{
       object me, room;
       me = this_player();
/*	if( ! ( room = find_object(__DIR__"shushang")))
       room = load_object(__DIR__"shushang");
       if(! (present("ju mang", room)));
       return; */
    if(!objectp(me)||!userp(me)||!living(me)) return;
      if (random((int)me->query("kar")) < 9 ) {
       if( ! ( room = find_object(__DIR__"shushang")))
       room = load_object(__DIR__"shushang");
       if(! (present("ju mang", room))) 
       return;
       message_vision(HIR"忽然一阵腥风袭来，一条巨蟒从身旁大树上悬下，把$N卷走了。\n\n"NOR, me);              
       me->move(__DIR__"shushang");                                                            
       me->start_busy(3);	
    }      

}
