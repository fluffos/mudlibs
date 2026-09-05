// /d/xinfang/bieshuqu.c
//
// Created by ... (Maybe bibi)
// Modified by pretty (09/18/98)

#include <ansi.h>

inherit ROOM;

int touch_xinfang();

void create()
{
	set("short",GRN"花园别墅区"NOR);
	set("long","这里就是著名的"GRN"花园别墅区"NOR"，很多人都在这里买了自己的房子！\n"
		"附近新建成了礼品店、驿站、浴室等公共设施，并不断地建设其他娱乐场所。\n"
		"看着一幢幢的新房，真是让人心动，自己也想买一套新房住！路旁的树下有一个\n"
		"盖着茅草的小洞，似乎可以钻进去。\n"
	);

	set("exits", ([
		"north":__DIR__"giftshop",
	
	    "south": __DIR__"yizhan",
		"east" : "/d/city/nandajie3",
		"west" : __DIR__"bathgate",
		"down":"/d/wizard/trashroom",	
	]));

    set("outdoors", "xinfang");
    set("no_reset",1);
    set("no_clean_up",1);

    set("room_location", "/d/city/");

//        remove_call_out("touch_xinfang");
//        call_out("touch_xinfang",60);
	setup();
}

void init()
{
	add_action("do_enter","enter");
	add_action("do_zuan", "zuan");
}

int do_zuan(string arg)
{
	if (arg != "dong"  || !arg) return notify_fail("你要钻什么？\n");
	message_vision("$N猫着腰钻进了地下垃圾站。\n", this_player());
	this_player()->move("d/wizard/trashroom");
	return 1;
}

int do_enter(string arg)
{ 
	object room, me, lover, ob, old_room;
	string roomname;

	me = this_player();
    old_room = environment(me);

	if (!arg)
	{
		write("你要进入哪间房？\n");
		return 1;
	}

	if (arg==me->query("marry/lover") ||  arg==me->query("id") )
	{
		if (arg==me->query("marry/lover"))
		{
			if (objectp(lover=find_player(arg)))
			{
				if (undefinedp(lover->query("myroom")))
				{
					write("你的爱人还没有自己的房间!\n"); 
					return 1;
				}
				
				tell_object(lover,"你爱人进入了你的房间。\n");
				if ( !lover->query("xinfang") || !objectp(room=find_object(lover->query("xinfang"))) )
				{
					room=new("/d/xinfang/xinfang");
					lover->set("xinfang", file_name(room));
				}
			}
			else 
			{
				ob = FINGER_D->acquire_login_ob(arg);
				if( !ob ) {
						write("你的爱人已经不在了。\n");
						destruct(ob);
						return 1;
					}
				if (objectp(lover = LOGIN_D->make_body(ob)))
				if ( lover->restore())
				{
					if (undefinedp(lover->query("myroom")))
					{
						write("你的爱人还没有自己的房间!\n"); 
						 READWRITE_D->dest_ob(lover);
						destruct(ob);
						return 1;
					}
					room=new("/d/xinfang/xinfang");
					lover->set("xinfang",file_name(room));
				}
				destruct(ob);
			}
			if (room->query("change_name")==0) 
			{     
				if (undefinedp(lover->query("myroom/short"))&&
						lover->query("myroom/long")!="")        
				room->set("short",lover->query("name")+"的甜蜜小屋");
				else room->set("short",lover->query("myroom/short"));
			
				if (!undefinedp(lover->query("myroom/long"))&&
						lover->query("myroom/long")!="")
					room->set("long",lover->query("myroom/long")+"\n");             
				room->set("owner",lover->query("id"));
				room->set("change_name",1);
			}
			if (!objectp(find_player(arg))) READWRITE_D->dest_ob(lover);

            if(me->move(room)) me->set_temp("xinfang/from","/d/xinfang/bieshuqu");
            else return 0;
			message("vision", me->name() + "进入了爱人的房间。\n", old_room, ({ me }) );
		}               
	
		if (arg==me->query("id"))
		{
			if (undefinedp(me->query("myroom")))
			{
				write("你还没有自己的房间!\n"); 
				return 1;
			}
			roomname = me->query("xinfang");
			if ( !stringp(roomname) || strwidth(roomname) == 0 || !objectp(room=find_object(roomname)))
			{								
				{
					room=new("/d/xinfang/xinfang");
					me->set("xinfang", file_name(room));
					if (room->query("change_name")==0) 
					{     
						if (undefinedp(me->query("myroom/short"))&&
								me->query("myroom/long")!="")        
							room->set("short",me->query("name")+"的甜蜜小屋");
						else room->set("short",me->query("myroom/short"));
		
						if (!undefinedp(me->query("myroom/long"))&&
								me->query("myroom/long")!="")
							room->set("long",me->query("myroom/long")+"\n");             
						room->set("owner",this_player()->query("id"));
						room->set("change_name",1);
					}
				}
			}
            if(me->move(room)) me->set_temp("xinfang/from","/d/xinfang/bieshuqu");
            else return 0;
			message("vision", me->name() + "进入了自己的房间。\n", old_room, ({ me }) );
		}
/*
		room_list = children("/d/xinfang/xinfang");
		for(i=sizeof(room_list)-1; i>=0; i--) {
			if (!( room == room_list[i] ) && (room_list[i]->query("owner") == room->query("owner"))) 
			{
				ob_list = all_inventory(room_list[i]);
				for(j=0;j<sizeof(ob_list);j++)
					ob_list[j]->move(room);
				destruct(room_list[i]);
			}
		}
*/
		message("vision", me->name() + "走了进来！\n", environment(me), ({ me }) );
		return 1;
	}
	else 
	{
		if (arg!=me->query_temp("invited"))
		{
			write("你并没有受到主人的邀请！\n");
			return 1;
		}
		else if (!find_player(arg)||undefinedp(environment(find_player(arg))->query("owner"))||environment(find_player(arg))->query("owner")!=find_player(arg)->query("id"))
		{
			write("可惜主人不在家，没有人给你开门！\n" );
			return 1;
		}
        else if (file_name(old_room)!=find_player(arg)->query_temp("xinfang/from"))
        {
            write("你去错地方了，"+find_player(arg)->query("name")+"("+find_player(arg)->query("id")+")邀请你去的是他在"+load_object(find_player(arg)->query_temp("xinfang/from"))->query_location_name()+"的家！\n");
            return 1;
        }
		else
		{
			if(me->move(environment(find_player(arg)))) me->set_temp("xinfang/from","/d/xinfang/bieshuqu");
            else return 0;
            message("vision", me->name() + "应邀走进了"+find_player(arg)->name()+"的房间。\n", environment(me), ({ me }) );
			tell_room(environment(me), me->name()+"走了进来！\n", ({me}));
			return 1;
		}
	}
}


int touch_xinfang()
{
    object* room_list;
    int i;
    room_list = children("/d/xinfang/xinfang");
	for(i=sizeof(room_list)-1; i>=0; i--) 
	{
	    room_list->query("owner");
	}    
    remove_call_out("touch_xinfang");
    call_out("touch_xinfang",60);        	
}
