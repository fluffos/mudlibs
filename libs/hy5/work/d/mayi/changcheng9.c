inherit ROOM;
void create()
{
	set("short", "隘口");
	set("long", @LONG
这里是长城的一个隘口，秦朝连接长城，每隔数十里建造一个隘口
用来驻扎军队，这里是马邑西边的隘口，平常由马邑的官兵来到这里巡
逻，现在马邑是突厥的天下了，这里也就没有人拉。
LONG
	);
set("outdoors", "mayi");
set("valid_startroom", 1);
set("exits", ([
	        "west" : __DIR__"changcheng8",
	        "northeast" : __DIR__"changcheng10",
                "northdown" : __DIR__"s-road",
                "southdown" : __DIR__"sroad",
	]));
       setup();
	replace_program(ROOM);
}
