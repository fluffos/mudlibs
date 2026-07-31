#include <ansi.h>
inherit ROOM;

void create ()
{
set("short",HIR "[1;31m〖中帆在线工作室〗[2;37;0m"NOR);

set("long",@LONG
这里是云中帆的家,空荡荡的左边有一扇小门,看来象是个书房
里面摆着几台框子一样的家伙,仔细一看原来是P4服务器,晕倒
在电脑台边上摆着一个靓女的相片,不用看了他家宝宝啦,啊哈.
LONG );

        set("exits",([ /* sizeof() == 1 */
                "gc":"/d/city/guangchang",        
               "down":"/d/wizard/wizard_room" ]));
        set("objects", ([
                "/u/freebird/yutu" : 2,
                "/u/freebird/thousand-gold" : 1,       
                "/u/freebird/msgd" : 1,        
        ]));

        set("valid_startroom", 1);
        set("no_suck", "1");
        set("no_fight", "1");
        set("no_clean_up", 0);
        setup();
}