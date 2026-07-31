 inherit ROOM;
void create()
{
        object          con, item; 
        set("short", "练武厅");
        set("long", @LONG
正面墙上挂著武当开山祖师－张三丰的画像。画像下一张供台上，
放著一只铜炉，几只缓缓冒著青烟的供香插在其中。左右两面墙上挂
著太极拳的练功图。图下则是兵器架，上有各式兵刃，但以剑为多。
几个武当道人正在练功。
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"wudang3",
        ]));
        set("objects", ([
                __DIR__"npc/taoist" : 2,
                __DIR__"obj/wshelf" : 1,
                __DIR__"obj/taiji_book" : 1,
                
        ]));
        set("coor/x",150);
        set("coor/y",-140);
        set("coor/z",50);
        setup();
}  
void reset()
{
        object          *inv;
        object          con, item;
        int             i;
        ::reset();
        con = present("weapon shelf", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/sword");
                item->move(con);
        }
} 
/*
void init()
{
        add_action("do_get", "get");
} 
int do_get(string arg)
{
        string          obj, from;
        object          me, wall, shelf, table, target, taro; 
        if(sscanf(arg, "%s from %s", obj, from)==2 ) {
                if(obj == "all") {
                        write("一次拿太多东西会太明显。\n");
                        return 1;
                }
                table =  present("tong lu",this_object());
                wall =  present("wall",this_object());
                shelf =  present("weapon shelf",this_object());
                target =  present(from,this_object());
                me = this_player();
                if(target == table || target == wall || target == shelf) {
                        taro =  present(obj, target);
                        if(taro && random(10) > 4) {
                                message_vision("$N趁没人注意的时候，鬼鬼祟祟地拿了点什么，放进怀里！\n", me);
                                me->set_temp("marks/偷书", 1); 
                        }
                }
        }
        return 0;
} 
int valid_leave(object me, string dir)
{
        object *inv, ob;
        int i; 
        if( userp(me) && me->query_temp("marks/偷书")) {
                if( dir == "north"  && ob=present("xie", this_object())) {
                        return notify_fail(ob->name()+"向你喝道：大胆！竟敢在武当偷东西！\n");
                }
        } 
        return 1;
}
*/    
