//houdian.c

inherit ROOM;
void create()
{
	set("short", "后殿");
	set("long", @LONG
后殿规模不大。两边都是水磨石壁，镂刻着佛门各位先贤大德的肖像及
慧心妙语，正中有一口大水缸(gang)，以济寺内僧人练武口渴及日常饮用之
需。每日都有专职僧侣从寺前佛心井中担水来此。
LONG 
);
        
        set("exits", ([
                     "west" : __DIR__ "hguangz4",
                     "east" : __DIR__ "hguangz5",
                     "north" : __DIR__ "taijie",
        ]));

        set("objects",([
          CLASS_D("shaolin") + "/hui-kong" : 1,
          __DIR__"npc/zjseng" : 1
         ]));

        set("item_desc", ([
        "gang" : "这是一口铜制的大缸，足可以盛下几百桶水。\n",
	]));

//        set("resource/water",1); 
        set("coor/x",50);
  set("coor/y",340);
   set("coor/z",120);
   set("coor/x",50);
 set("coor/y",340);
   set("coor/z",120);
   setup();
}           
