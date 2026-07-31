//for birthday
#include <room.h>
#include <ansi.h>

string look_cake();
inherit ROOM;
void create()
{
 set("short","快乐寿星予安的家");
set("long", @LONG
这是予安的寿星居, 是在她 20岁时泥潭的虫子们群策群力为她盖的
正堂之上摆着一张八仙桌, 予安坐在那里笑眯眯得等着大家拜寿.
桌子上有一块巨大的蛋糕(cake). 香气袭人, 哇, 予安的口水都流
下来了.
LONG );
set("exits",([
             "west"     :  __DIR__"home",
           "south" : "/u/xinyue/sunrise_room",
         ]) );
set("item_desc",(["cake" : (: look_cake :), 
                 ]));

setup();
}

string look_cake()
{
string cake;
       cake = read_file(__DIR__"cake.txt",1,39);
return cake;
}
