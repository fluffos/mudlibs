#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "慈恩寺");
  set ("long", @LONG

走进慈恩寺，进入眼帘的是雄伟的大雁塔，七层突兀于灵空，甚是壮
观。寺内古柏森森，绿阴成片，左右钟鼓楼遥遥相对。院内有两组石
碑群，为一些著名进士所题刻。
LONG);

  set("exits", ([
        "out"      : __DIR__"ciensiw",
        "east"     : __DIR__"dyt",
      ]));
  set("objects", ([
        __DIR__"npc/sengren"     : 3,
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave(object who,string dir)
{
	object fo;
	if( dir!="enter" && dir!="east" )
		return ::valid_leave(who,dir);
	if( !userp(who) )
		return ::valid_leave(who,dir);
	if( !wizardp(who) && !who->query("env/test") 
	  && (who->query_level()<30||who->query_level()>=40) )
		return ::valid_leave(who,dir);
	if( time()<who->query("maze/dayan-ta")+1800 
	 || !who->query_temp("maze/faming_ask2") ) 
		return ::valid_leave(who,dir);
			
	who->delete_temp("maze");
	if( MAZE_D->enter_maze(who, "dayan-ta") )
	{
		if( fo && !wizardp(who) )
			destruct(fo);
        	who->set_temp("maze/dayan",1);
        	who->set("maze/dayan-ta",time());
        	tell_object(who,HIY"你受法明长老所托，行至此地，一旁早有慈恩寺的大和尚将你从一旁带入塔下地宫。\n"NOR);
        	return 2;
	}		
	return ::valid_leave(who,dir);
}




