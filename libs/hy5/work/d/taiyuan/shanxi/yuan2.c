#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "荷花园"); 
        set("long", @long
园内叠石理水，临水筑有亭、廊、楼、阁，陈列着各式盆景和
金石书画。水面种有红、白、粉、洒金、并蒂等多种颜色和种类的
荷花名品。四周有迎熏阁，环碧桥，风微亭，红绡翠盖廊，波香亭
等临水小筑。
long); 
        set("type","waterbody");
        set("exits",([
                "south":__DIR__"shulin1",
                "north":__DIR__"shulin4",
        ]) );
       set("outdoors", "shanxi");
        set("item_desc", ([
                "boat": "一叶小舟，洒满鲜花，在湖心飘飘荡荡。\n",
                "小舟": "一叶小舟，洒满鲜花，在湖心飘飘荡荡。\n",
                "lake": "湖水清澈，你很想跳进湖中，洗掉多年的江湖尘埃(swim)。\n",
                "荷花湖": "湖水清澈，你很想跳进湖中，洗掉多年的江湖尘埃(swim)。\n",
                "湖心": "湖心离岸边三四丈，轻功好的话当可一跃而至(charge)。\n",
                "center": "湖心离岸边三四丈，轻功好的话当可一跃而至(charge)。\n",

        ]) );
        set("coor/x",-550);
        set("coor/y",-360);
        set("coor/z",100);
        setup();
} 
void init(){ 
        add_action("do_swim", "swim");
        add_action("do_charge", "charge"); 
}   
int do_charge(string arg)

{
        object room;
        object me;
        if(!arg || arg=="")
        {
                write("你要向哪里跳？\n");

                return 1;
        }
        if( arg == "湖心" || arg == "center" )
        {
                me = this_player();
                if ( me->is_busy() )
                        return notify_fail("你现在忙得很，不能移动。\n");
            if ( me->query_skill("dodge") >= 100 )
                {
                        message_vision("$N脚下一蹬，落入小舟，驶向湖心金阁......\n", me);
                        room = find_object(__DIR__"zhubaoge");
                        if(!objectp(room)) room = load_object(__DIR__"zhubaoge");
                        me->move(room);
                        message_vision("$N轻巧的落在小舟上。\n", me);
                        return 1;
                }
                else
                {
                        message_vision(HIY"$N拍拍屁股，鼓足勇气，准备向湖心飞跃。\n"NOR, me);
                        message_vision(HIY"$N助跑几步，突然“啊呀！”一声，脸色苍白的停在湖边。\n"NOR, me);
                        me->start_busy(3);
                        return 1;
                }                       
        }
        else
        {
                write("你不可以跃向"+arg+"\n");
                return 1;
        }
} 
int do_swim(string arg)
{
        object room;
        object me;
        if(!arg || arg=="")
        {
                write("你要在哪里游？\n");
                return 1;
        }
        if( arg == "荷花湖" || arg == "lake" )

        {
                me = this_player();
                if ( me->is_busy() )
                        return notify_fail("你现在忙得很，不能移动。\n");
                if ( random(100) > 5 )
                {
                        message_vision(HIY"$N如苍鹭戏水，姿势曼妙的跃入湖中。\n"NOR, me);
                        message_vision(HIY"$N突然觉得有些滑滑的东西钻入....，$N手忙脚乱一阵乱划，游回岸边。\n"NOR, me);
                        me->start_busy(2);
                        return 1;
                }
                else
                {
                        message_vision(HIY"$N高高跃起，半空中一个转折，做自由落体，直落湖中。\n"NOR, me);
                        message_vision(HIY"湖水水位突然下降，$N一头扎到湖底岩石上。\n"NOR, me);
                        me->start_busy(3);
                        me->unconcious();
                        return 1;
                }                       
        }
        else
        {
                write("你不可以游"+arg+"\n");
                return 1;
        }
}
