// Room: huangdi.c
//Created by Atlus 1999.10.9
// Modified by Atlus 1999.10.9
// 

inherit ROOM;

void init();
int do_zhao(string);
int do_push(string arg);
void delete_served(object);

void create ()
{
        set ("short", "荒地");
        set ("long", @LONG
这里是一片荒地，看来已经很旧无人使用了，野草长了一地越看越觉
得这里荒凉。突然你发现来时的路找不到了！
LONG);
        set("area","飞鱼");
        set("valid_startroom", 1);

        setup();
}

void init()
{
        add_action("do_zhao", "zhao");
	add_action("do_push", "push");
}

int do_zhao(string arg)
{

        object me;

        me = this_player();

        if ( !arg || arg != "路")
        {
                return notify_fail("你要找什么？\n");	
        }
		
        message_vision("$N到处乱找，竟然找到向东一条小路。\n",me);
        if( !query("exits/east") ) {
        set("exits/east", __DIR__"jzroad3");
        call_out("close_path", 3);
        }
        return 1;
        
}

int do_push(string arg)
{
        object me;
        if(!arg || arg=="")
        {
                write("什么？\n");
                return 1;
        }
        if( arg == "zacao" || arg == "杂草" || arg == "cao")
        {
        me = this_player();
        message_vision("$N静下心来屏息细看，发现了一边的杂草有被动过的痕迹。\n于是，$N推开那堆杂草，一条土路现于眼前\n", me);
        if( !query("exits/southdown") ) {
        set("exits/southdown", __DIR__"tulu");
        call_out("close_path", 3);
        }
        return 1;
        }
        
}
void close_path()
{
        if( !query("exits/east") ) return;
        message("vision",
"一阵风吹过，杂草中的路又不见了。\n",
                this_object() );
                delete("exits/east");
        if( !query("exits/southdown") ) return;
        message("vision",
"一阵风吹过，杂草中的路又不见了。\n",
                this_object() );
                delete("exits/southdown");
}

