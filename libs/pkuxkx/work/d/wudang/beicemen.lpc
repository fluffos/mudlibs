// beicemen.c 北侧门
// by llin

inherit ROOM;

void create()
{
	set("short", "北侧门");
	set("long", 
"一道虚掩着的小木门，透过门缝可以看到外面的竹林，一\n"
"条小路曲曲折折的通入竹林中。\n"
	);
	set("exits", ([
		"west" : __DIR__"zhulin1",
		"east" : __DIR__"xilang",
	]));
	set("objects",([
		CLASS_D("wudang") +"/zhangcui" : 1,
		]));
	setup();
}

int valid_leave(object me,string dir)
{       
    if (dir == "west" && me->query("family/master_id")!="zhang sanfeng"
        && objectp(present("zhang cuishan",environment(me))) 
	      && living(present("zhang cuishan",environment(me))))
	  {
	  	if ( me->query("family/family_name")=="武当派" &&
	  		   me->query("shen")>=100000 &&
	  		   me->query("score")>=1000 )
	    {
	    	tell_object(me,"张翠山说道：师傅正在里面等着你呢！\n");
	    	return ::valid_leave(me, dir);
	    }
      
      return notify_fail("张翠山拦住你说道：师傅正在静修，没什么事就不要去打扰。\n");
    }
    
    return ::valid_leave(me, dir);
}
