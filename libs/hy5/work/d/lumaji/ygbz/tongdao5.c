// zjb /2002/3/15/
#include <ansi.h>
inherit ROOM;
int do_an(string arg); 
void on_wang();
void on_wang2();
void create()
{
        set("short", "秘道极端");
        set("long", @LONG 
这条花岗石建成的秘道，已是巧夺天工，当年不知
动用多少人力物力!左壁有一石突出,似乎可以按(an)
一按!
LONG
        );
        set("exits", ([
                "north" : __DIR__"tongdao4",
                      ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_an", "an");
}
int do_an(string arg)
{
        object me; 
    object room;
    string dir;
             me = this_player();
      if( !arg || arg=="" ) return notify_fail("你要按什么东西!\n");
   if( arg=="wall" ) {
   write(HIM"制钮在左边呢!\n");
        return 1;
}
    if( sscanf(arg, "%s wall", dir)==1 ) {
   if( dir=="right" ) {
if (me->query_temp("tongguo"))
{
            message_vision("$N按向了右边石壁的那个制钮。\n", this_player());
            message_vision("机括声响起，右方一壁凹进去，现出一个方洞!\n", this_player());
me->delete_temp("tongguo");
        set("exits/enter", __DIR__"langdao");
call_out("on_guan", 5);
return 1;
}
return 0;
}
 else if( dir=="left" ) {
                    write("你把凸出左璧的制钮用力下按,「轧轧」声再响。\n");
       write("你身处的一截通道忽然移动起来，带着你往下滑行。\n");
           remove_call_out("on_wang"); 
  call_out("on_wang", 1);
return 1;
        }
        else {
            write("你想按什么东西?!\n");
            return 1;
        }
}
}
void on_wang()
{
    object room; 
    object me;
    me = this_player();
       write(HIB"你心叫我命休矣，「轰」的一声，活动通道在俯冲近二十丈後，不知撞在甚麽地方，蓦地煞止。\n");
    write(HIB"你却没有通道煞停的好运道，给强猛的冲力撞带至茫茫黑暗中另一空间，\n");
  write(HIB"你身子凌空下跌，蓬蓬两声，分别一头栽进一幅像鱼网般的东西内。\n"NOR);
  me->move(__DIR__"wang");
 remove_call_out("on_wang2"); 
  call_out("on_wang2", 1);
   }

        
void on_wang2()
{
    object room; 
    object me;
    me = this_player();
       write(HIR"弹起又再跌下，震得"+ me->name() +"浑身酸  麻，晕头转向，不知人间何世。\n"NOR);
       write(HIR"你的噩梦尚未完结，网子忽往下堕，疾跌近丈後，随跌势网子往下束收，\n"NOR);
       write(HIR"到跌定的一刻，刚好把你网个结实，动弹不得\n"NOR);
    this_player()->unconcious();
   }

void on_guan(object room)
{
      message_vision(HIG"突然出现咔咔的响声，墙壁又合上了!\n"NOR, this_player());
delete("exits/enter");
}
