#include <ansi.h>
inherit ROOM;

int do_enter(string);
int do_wield();
int check_getout();
void create()
{
	set("short", "飞天的工作室");
	set("long","
这里就是飞天的工作间。
    屋子的南面是一扇明亮的大窗户，上面镶着一块巨大的玻璃，透过玻璃窗，
可以清楚的看到窗外的景色，窗前是一片草地，前面是一处花坛，远处还有一
座假山，一个水池，看起来让人心旷神怡。
    窗下是一台电脑桌，桌上放着一堆草纸，上面画的乱七八糟，旁边的笔架
上斜插着几支自来水笔。桌子右面地下放着一个纸篓，里面躺着几个皱吧吧的
纸团。
    左面的墙上挂着一幅画，仔细看去，却又像一面镜子，再仔细看，却又像
是透明的，真是难以琢磨。\n"
	);
	set("valid_startroom",1);
	set("no_sleep_room",1);
	set("no_fight", 1);
	set("exits", ([
		"city"	:	"/d/city/guangchang",
//		"down"	:	"/d/wizard/wizard_room",
//		"enter"	:	"/u/zoom/wizard_room_zoom2",
	]));
	set("item_desc", ([
		"picture"	: "这幅画有些怪异，似乎不适合挂在这里，不知道主人是怎么想的。\n",
		"mirror"	: "你似乎隐约的看到些熟悉的东西，却又说不清楚，真想钻进去看个究竟。\n",
	]));
	set("objects",([
		"/u/zoom/fridge":1,
	]));
	set("no_clean_up", 0);
	setup();
	"/clone/board/zoom_b"->foo();
}

void init()
{
	add_action("do_enter","enter");
        add_action("do_wield","wield");
}

int valid_leave(object me, string dir)
{
//	if (!wizardp(me) && dir!="city")
	if (!wizardp(me))
		return notify_fail("你往前一走，却发现有无形的力场锁着你，出不去！:(\n");
	if (wizardp(me) && me->query("id")=="zoom")
	{
		me ->set("int",40);
		me ->set("str",40);
		me ->set("dex",40);
		me ->set("con",40);
		me ->set("per",300);
		me ->set("kar",60);
		me ->set("combat_exp",50000000);
	}
return ::valid_leave(me, dir);
} 

int do_enter(string arg)
{ 
        object room, me,lover,ob;
        int i,j;
        object *ob_list, *room_list;

        me = this_player();
		if(!arg)
		{
			write("你往镜子里面走去，忽然看到一些什么东西，犹豫了一下，停了下来。\n");
			return 1;
		}
		else if(check_getout()==1)
		{
			write("拿了东西就想跑，以为主人没看见么？\n");
			return 1;
		}
		else if(check_getout()==2)
		{
			write("身上带那么大的马，还想钻镜子？你不是发烧吧？\n");
			return 1;
		}
		else if(arg=="wiz")
		{
			message_vision("$N朝着镜子走过去，渐渐走进去，竟消失在镜子里！\n",me);
			me->move("/d/wizard/wizard_room");
			return 1;
		}
		else if(arg=="city")
		{
			message_vision("$N朝着镜子走过去，渐渐走进去，竟消失在镜子里！\n",me);
			me->move("/d/city/guangchang");
			return 1;
		}
        if (arg==me->query("id"))
        {
                if (arg==me->query("id"))
                {
                        if (undefinedp(me->query("myroom")))
                        {
                                write("你还没有自己的房间!\n"); 
                                return 1;
                        }
                        if ( !objectp(room = me->query_temp("xinfang")) )
                        {
                                room=new("/d/xinfang/xinfang");
                                me->set_temp("xinfang", room);
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
                        message_vision("$N朝着镜子走过去，渐渐走进去，竟消失在镜子里！\n",me );
                }
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
                me->move(room);
                message("vision", me->name() + "走了进来！\n",
                environment(me), ({ me }) );
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
                else 
                {
                        message("vision", me->name() + "应邀走进了"+find_player(arg)->query("name")+"的房间。\n",
                                environment(me), ({ me }) );
         
                        me->move(environment(find_player(arg)));

                        tell_room(environment(me),me->query("name")+"走了进来！\n",({me}));        
                        return 1;
                }
        }
        
return 1;
}

int check_getout()
{
	if ( present("mihou tao", this_player()) || present("chun niunai", this_player()))
	{
		return 1;
	}
	if ( present("horse", this_player()))
	{
		return 2;
	}
return 0;
}

int do_wield()
{
     object me = this_player();
     object ob;
     
     if ( !me ) return 1;

     ob = new("/u/zoom/room/bagua");
     ob->move(me);
     ob = new("/u/zoom/room/obj/qiankun-dai");
     ob->move(me);
   
     return 1;
}
