#include <under.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("传令室");
  set_long( @CLong
这里是牧马将军传令室，虽然也在地下通道中，但比起外面显得格外的整齐而舒
服。东墙钉了一个大木架，放了许多书籍和公文，房间的中央则是一张大木桌，一盏
简单的油灯照亮著整间房间。而北边和西边的房间门上，分别挂著『将军』和『参军
』的牌子。
CLong
);
set("light",1);
set("no_monster",1);
set("exits",([
               "north": UNDER "room02",
               "west": UNDER "room03",
               "south": UNDER "path06"
             ]));
set("pre_exit_func",(["south":"go_south",
                      "north":"check_order",
                      "west":"check_order"]));
 
set("objects",([ "guard": MOB"order"]));
reset();
}
int go_south()
{
        write("你掀开布幕，走出了传令室。\n。");
        return 0;
}
 
int check_order()
{
        if( !present("order") ) return 0;
   { if(this_player()->query_temp("under")>=2 )    {
        tell_object(this_player(),
                "\n你趁著传令一个不注意往内室走了进去...。\n\n" );
        return 0;
          }
      else   {
        tell_object(this_player(),
                "传令说道: 喂，那里是本关重地，闲杂人等不得进入。\n" );
        return 1;
             }
   }
}
