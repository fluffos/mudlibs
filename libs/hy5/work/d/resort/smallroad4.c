 inherit ROOM;
void create()
{
        set("short", "羊肠小道");
        set("long", @LONG
一条被在恰克卜里山中砍柴的樵夫踏出的小道弯弯曲曲的向北面的
山幽伸展。道旁的茅草高达五尺，遮住了天光。山幽中的一切都显的阴
森幽暗。这里的茅草(grass)似乎更密更厚了。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"smallroad3",
  "north" : __DIR__"smallroad2",
]));
        set("objects", ([
                __DIR__"npc/woodcutter" :2,
        ]) ); 
        set("item_desc", ([
                "grass": "这里的茅草(grass)很密，但你似乎可以拨开(pushaside)它们。\n",
                "茅草": "这里的茅草(grass)很密，但你似乎可以拨开(pushaside)它们。\n" 
        ]) ); 
        set("outdoors", "resort");
        set("coor/x",-1190);
        set("coor/y",30);
        set("coor/z",0);
        setup();
}
void init()
{
        add_action("do_push", "pushaside");
}
int do_push(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要拨开什么？\n");
                return 1;
        }
        if( arg == "grass" || arg == "茅草" || arg == "草")
        {
        me = this_player();
        message_vision("$N拨开路边的茅草，发现了一条向西的路。\n", me);
        if(!me->query("m_success/铁雪"))
        {
                me->set("m_success/铁雪",1);
                me->add("score",70); 
        }
        if( !query("exits/west") ) {
        set("exits/west", __DIR__"secret_road");
        call_out("close_path", 5);
        }
        return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/west") ) return;
        message("vision",
"一阵风吹过，茅草晃了晃，又淹没了向西的路。\n",
                this_object() );
                delete("exits/west");
}    
