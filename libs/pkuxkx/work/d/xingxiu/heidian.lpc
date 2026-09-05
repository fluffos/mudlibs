// Room: taihuge.c
// Made by:pingpang
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLK"黑店"NOR);
	set("long", "这里是"YEL"六盘山"NOR"一个貌似作生意的黑店。"
		"里面有一扇门(men)。墙上还挂了一幅画(drawing)。\n");

	set("exits", ([
                "eastup" : __DIR__"xxroad3",
                ]));
	set("item_desc",(["men":"你可以打开(open)它.\n",
			  "drawing" : "这是一幅古画，好象很值钱。\n",]));
	set("outdoors", "xingxiu");
        set("objects", ([
            __DIR__"npc/dashou" : 4,
	    __DIR__"npc/hboss" : 1,
	]));

	setup();
}
void init()
{
	object room;
	add_action("do_open","open");
	add_action("do_get","get");
	if(!(room=find_object("/d/xingxiu/heidian")))
		room=load_object("/d/xingxiu/heidian");
	room->delete("exits/eastup");
	tell_object(this_player(),BLK"打手们把门关了起来,黑老板嘿嘿笑了几声......\n"NOR);
}
int do_open(string arg)
{
	object room;
	if(!(room=find_object("/d/xingxiu/heidian")))
		room=load_object("/d/xingxiu/heidian");
        if(!arg||arg!="men")
	return 0;
	if(arg=="men")
		{message_vision("$N小心翼翼地打开一扇门.\n",this_player());
		 room->set("exits/eastup","/d/xingxiu/xxroad3");
		 return 1;
		}
}
int do_get(string arg)
{
	object me = this_player();
	object drawing;

    if(query_temp("mark/been_got")) return notify_fail("画已经被取走了!\n");
	if (!arg || arg != "drawing")
		return 0;
	drawing = new("/d/riyuejiao/npc/obj/xishantu");
	drawing->move(me);
    set_temp("mark/been_got",1);
	message_vision("$N从墙上取下一幅画。\n",me);
	return 1;
}

void reset()
{
    ::reset();
    delete_temp("mark/been_got");
}
