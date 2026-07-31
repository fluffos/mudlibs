// Room: /d/new_taohua/haitan.c

inherit ROOM;




void create()
{
	set("short", "望海亭");
	set("long", @LONG
面前是一座石亭，倚海而建。在亭内望远处海面波浪
起伏，鳞光片片。不时有海风吹来，令人心旷神怡。你不
禁有下海畅游一番的冲动。
LONG
	); 
              set("exits", ([
                "southwest" :__DIR__"taijie1",
	]));

	  setup();
}

 void init()
{       object ob;
        add_action("do_swim", "swim");
        
}

int do_swim(string arj)
{this_player()->move(__DIR__"hai");  
  return 1;
}
