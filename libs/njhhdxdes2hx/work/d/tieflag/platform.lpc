// searoad.c
inherit ROOM;
void create()
{
        set("short", "平台");
        set("long", @LONG
上山数百丈，道旁一角小亭，绿石朱栏，玲珑可观。一人倚栏相候。前面是一道
长阶直达峰巅。
LONG
        );
        set("objects",([
        	__DIR__"npc/qinggirl" : 1,
        ]) );
        set("exits", ([ 
	  	"west" : __DIR__"uproad3",
  		"eastup" : __DIR__"uproad4",
	]));
        set("outdoors", "tieflag");
        setup();
}
int valid_leave(object who,string dir)
{   
    object girl;
    girl=present("girl",this_object());
    if(girl && living(girl) && userp(who) && who->query("gender")=="男性" && dir=="eastup")
   	{
   		message("vision",girl->name()+"说道：“这位公子请留步。”\n",this_object());
   		return 0; 
   	}
   	return 1;
}