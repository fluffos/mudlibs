 inherit ROOM;
void create()
{
        set("short", "坑底");
        set("long", @LONG
这是一个深坑的底部。在这里风声凄历，迷雾更浓。抬头仰望，不见天
日。四下鬼影重重，也不知是真是假。转目四望，但见坑中满是被石蛇缠住
的石人。哪有活人的人影。乎听身旁隐约有人喘息的声音，你不禁毛骨悚然。
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"keng",
]));
        set("objects", ([
        __DIR__"obj/eren" : 1,
                        ]) );  
        set("coor/x",220);
        set("coor/y",-40);
        set("coor/z",10);
        setup();
} 
void init()
{
        add_action("do_open", "touch");
}
int do_open(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要打开什么？\n");
                return 1;
        }
        if( arg == "statue" || arg == "恶人像" || arg == "被石蛇缠住的恶人像")
        {
        me = this_player();
        message_vision("$N俯身走了两步，伸手扳了扳地上的石像．
＂呀＂地一声，深坑边的石壁上，竟裂开了一重门户。\n", me);
        if( !query("exits/east") ) {
        set("exits/east", __DIR__"secretpath0");
        if(!me->query("m_success/帝王谷"))
        {
                me->set("m_success/帝王谷",1);
                me->add("score",300); 
        }
        call_out("close_path", 1);
        }
        return 1;
        }
        else
        {
                write("你伸手扳了扳"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/east") ) return;
        message("vision",
"石壁上的门户又无声无息的合了起来．\n",
                this_object() );
                delete("exits/east");
}    
