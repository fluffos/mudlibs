// searoad.c
inherit ROOM;
void create()
{
        set("short", "海边路");
        set("long", @LONG
路面上的沙石越来越细，空气中弥漫着一股咸味，越往前走，咸味越明显。远处
隐隐传来波涛拍岸的声音。偶尔走过去一两个满脸水纹的老渔夫。
LONG
        );
        set("objects",([
        	__DIR__"npc/fishman" : 1,
       	]) );
        set("exits", ([ 
  "east" : __DIR__"searoad1",
  "west" : __DIR__"plain",
]));
        set("outdoors", "tieflag");
        setup();
}
int valid_leave(object who,string dir)
{
   	if(userp(who) && random(5))
   	{
   		who->move(this_object());
   		return notify_fail(""); 
   	}
   	return 1;
}