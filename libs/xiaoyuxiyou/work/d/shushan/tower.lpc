inherit ROOM;                                                        
#include <ansi.h>                                                                     

void create ()                                                       
{                                                                    
	set ("short", "锁妖塔");                                   
  	set ("long", @LONG                                                 
一座高耸入云的石塔，乃金刚白玉石筑成。外层由无数铁链拴起，纵横交错。塔身上贴有无数符纸，霞光四射。
    旁边有一石碑(stone)。
LONG);                                                          
        set("item_desc", ([
                "stone": @TEXT
前梁武帝信奉佛教，诉蜀山为邪魔歪道，召集无数高僧，法师上蜀山修建锁妖塔。遍采
天下金刚白玉石，花费二十余年完成，并由高僧，法师对塔下了符咒。当时山中诸多修
仙之辈奋力抗争，夺得佛塔，改名为『锁妖塔』，作为囚禁妖类之用。
后九天玄女感蜀山除妖卫道之功，赐化妖水，降下结界，塔中诸妖再难逃遁。此塔乃成
蜀山象征。
TEXT        
]) );
	set("exits", ([
  		"enter" : __DIR__"entrance",                                                                              
  		"south" : __DIR__"bamboo",
]));

	set("objects",([
        	__DIR__"npc/daowu" : 1,
	]));                                                                 
     	set("outdoors", "shushan");                                                                  
  	setup();                                                           
}

