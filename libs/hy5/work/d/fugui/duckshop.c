#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "麦老广烧腊店"); 
        set("long", @LONG
这里便是麦老广的烧腊店，虽然四处都是积年未去的油垢烟渍。但那独有的烧
鸭的味道便几乎可以让人忘却一切，往里走还有间厨房，也是麦老广睡觉的地方。
这间房门总是关着的，因为麦老广的烧腊卤味也是“独门秘方”，若是被别人偷偷
学去了，他的饭碗也就砸破了。
LONG); 
        set("type","house");
        set("exits",([
                "east":__DIR__"xiaojie3",
                "west":__DIR__"neishi",
        ]) );
        set("objects",([
                __DIR__"npc/mai":1,
        ]) ); 
        set("coor/x",-590);
        set("coor/y",100);
        set("coor/z",0);
        setup();
} 
void init()
{
        add_action("do_look", "look");
} 
int valid_leave(object me, string dir)
{
        if( userp(me) && dir=="west" && present("mai laoguang", this_object()) ) 
                return notify_fail("麦老广咧嘴笑道：“后面呢又系脏又系油，您还系别去的。”\n");
        return 1;
} 
int show_notify(object obj, int i)
{
        object me;
        object room, mai;
        object feng;
        me = this_player();
   mai = present("mai laoguang", environment(me));
   	if(mai)
        if (mai->is_fighting())
        {
                return notify_fail("麦老广正在打架，没功夫理你！”\n");
        }
        else
        {
                if (!me->query_temp("yaopai")) {
                        message_vision("麦老广赫赫笑了起来，对$N缓缓地摇了摇头。\n",me);
                        return 1;
                }
                if (!(room=find_object(__DIR__"neishi")))
                        room=load_object(__DIR__"neishi");
                write(HIY"麦老广神色突然变得很紧张。\n"NOR);
                write(HIY"麦老广趁你不注意，偷偷挪回里屋。\n"NOR);
                destruct(mai);
                feng = new(__DIR__"npc/feng");
                feng->move(room);
                me->set_temp("fugui_mai_showyaopai",1);
                return 1;
        }
} 
int do_look(string arg)
{
        object  me;
        me = this_player();
        if( arg == "west") 
        {
                tell_object(me,"里边黑漆漆的，什么都看不到。\n"); 
                return 1;
        }
        return 0;
}
