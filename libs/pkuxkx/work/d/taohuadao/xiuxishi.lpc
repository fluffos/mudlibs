// Room: xiuxishi.c
// By llx

inherit ROOM;

void init();
//void close_men();

void create()
{
        set("short", "休息室");
        set("long", @LONG
        这是间整洁的休息室，只有中间放着一张收拾得很干净的石板床，
坐上去舒舒服服，让人看着看着就想躺上去睡上一觉。
LONG
        );
	set("exits",([
	"south" : __DIR__"zoulang",
	"west" : __DIR__"shangyuetai",
	]));

        set("sleep_room", 1);
        set("no_fight", 1);

        setup();
}



int valid_leave(object me, string dir)
{
	object room;

	if ( !::valid_leave(me, dir) ) 
		return 0;
	
	if(!(room = find_object(__FILE__)) )
		room = load_object(__FILE__);
	if(objectp(room))
	{
		room->add_temp("person_inside", -1);	
		if ((int)room->add_temp("person_inside", -1) <= 0)
			room->delete_temp("person_inside");	
	}
	
	return 1;
}
