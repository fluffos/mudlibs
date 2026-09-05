// Room: xiuxishi.c
inherit ROOM;

void create()
{
        set("short", "月儿台");
        set("long", @LONG
    这是一个小小的楼台，台中一间小阁，阁上半轮月儿牙阁顶淡淡地
闪着“月光”。
LONG
        );
	set("exits",([
	"west" : __DIR__"quanjing",
	]));

//      set("sleep_room", 1);
        set("no_fight", 1);
        set("out_door", 1);

        setup();
}
void init()
{
object me;
me=this_player();
if(me->query("enterholefaint")==1)
{
 tell_object(me,"过了良久，你终于醒来，$N发现你居然落到了洞底，这里居然又是别有洞天！\n");
me->set("enterholefaint",0);
}
}


