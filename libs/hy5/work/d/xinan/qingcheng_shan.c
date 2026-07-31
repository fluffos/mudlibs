inherit ROOM;


void create()
{
   set("short","青城山脚");
   set("long",@LONG
这里是青城山脚下，属青城县地界。西边山高路险，莽林蔽日，据说常有强人
出没。向东跨过岷江，就离成都城不远了。
LONG);
   set("exits",([
     	"east" 		:	__DIR__"dujiang_yan",
     	"north" 	:	 __DIR__"cunzi/lroad1",
  	"west"		:	 __DIR__"after_qingcheng/qingcheng_shan1",
        "south"    : "/d/qingcheng/path1",
  	
    ]));
    
	set("objects", ([
                "quest/skills2/wunon/dalie/dalie" : 2,
	]));
    
   setup();
   set("outdoors","xinan");
} 
