// /d/kunming/lianhua
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "莲花峰" NOR);
        set("long", @LONG
爬上莲花峰，石林风光尽收眼底，眼见北边刻有一大字(zi),西边
有一小亭(ting)，峰壁上刻有一小诗(shi)，向下观望，只见一潭碧水
荡漾(tang)。奇景迭出，险象环生，峰回路转，异境天开，悉心观察，
难穷奥妙，常使人心动神驰，乐而忘返矣。

LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                
                "southdown"  :__DIR__"shilin2",        
               
        ]));

        set("item_desc", ([
                     "zi" :  "  ~~~~~~~~ \n" +  
                             "  ~      ~ \n" +  
                             "  ~  天  ~ \n" +
                             "  ~      ~ \n" +
                             "  ~  下  ~ \n" +
                             "  ~      ~ \n" +       
                             "  ~  第  ~ \n" +  
                             "  ~      ~ \n" +  
                             "  ~  一  ~ \n" +  
                             "  ~      ~ \n" +  
                             "  ~  奇  ~ \n" +  
                             "  ~      ~ \n" +  
                             "  ~  观  ~ \n" +
                             "  ~      ~ \n" +   
                             "  ~~~~~~~~ \n\n\n" ,
                     "shi" : " 攀 登 直 欲 夺 天 工，\n\n" +
                             " 一 顶 凌 云 挈 众 峰；\n\n" +
                             " 不 是 猱 升 挥 汗 水，\n\n" +
                             " 何 来 双 手 抚 晴 空。\n\n\n",

                     "tang" : "一个深不见底的水潭，名曰：剑池。池中有一石，名曰：试剑石。\n",
                     "ting" : "一个小亭子，名为：望峰亭。建在一座独峰上，四周都是峭壁，无法\n"+
                              "攀登，如果要过去的话，只有从这里跳了!\n",
                  ]));
        setup();
        }

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me ;
	int  i_dodge;
	me=this_player();
	i_dodge=(int)me->query_skill("dodge");
        
	if (!arg || arg=="" ) return 0;
	if (arg!="down" && arg!="ting") return 0;
        switch (arg){
               case "down" :
			 message("vision",me->name() + "向下跳去。\n",environment(me), ({me}) );
                     	if (i_dodge < 30)  {me->move(__DIR__"shijianchi");
                                         message("vision",
			                "只啪的一大声，一个人从上面掉了下来，摔了个四荤五素。\n",
			                 environment(me), ({me}) );
                                         me->unconcious();
                                       } 
                     else {me->move(__DIR__"shijianchi");
			   message("vision",
		        	"只见人影一闪"+me->name() + "从上面跳了下来。\n",
			    environment(me), ({me}) );
	                   message("vinson","你纵身向下一跳，稳稳的落在试剑池中间。\n" , me);
                          }
                     break; 
               case "ting" :
                     if (i_dodge < 60)  return notify_fail("你的轻功还不足以跳过去！\n");
                     else { message("vision",
			me->name() + "向望峰亭跃了过去。\n",
			environment(me), ({me}) );
			 me->move(__DIR__"wfting");
                            message("vinson","你纵身一跳，只觉身子轻飘飘的飞了出去！\n" +
                                             "睁眼一看，已落在望峰亭上。 \n", me);
                          }
                     break; 
                    }
    return 1;
	}