#include <under.h>
inherit ROOM;
inherit DOORS;
 
void create()
{
        ::create();
  set_short("牧马关警闭室");
  set_long( @CLong
你走进了一间灯光昏暗而摆设简单的房间，这儿除了房间角落一张放著小油灯的
木桌外，什麽也没有。牧马关的警闭室平常也少有违纪的官兵进来，因此，这里的人
们也显得特别清闲。西边是一间铁门深锁的牢房，从这儿你彷佛听见里面传出一些声
响，东边则是回到地下密道的小门。
亮不少。
CLong
);
set("light",1);
set("exits",([
               "east": UNDER "path02",
               "west": UNDER "jail"
             ]));
set("objects",([
               "officer": MOB"jian"
               ]));
 
create_door( "west","east",
           (["keyword" : ({"iron","gate"}),
             "name"    : "iron gate",
             "c_name"  : "大铁门",
             "c_desc"  : "一扇厚重的大铁门，甚至连把手都是铁铸的。\n",
             "status"  : "locked",
             "lock"    : "MUMARKEY"
            ]) );
reset();
}
