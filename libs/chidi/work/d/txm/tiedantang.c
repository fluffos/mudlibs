inherit ROOM;

void create()
{
        set("short", HIC"碧血铁胆堂"NOR);                                              
  set("long", ""GRN"                                                                          
                "NOR""BRED+HIG"┌───────┐"NOR"  
                "BRED+HIG"│碧  血  铁  胆│"NOR"  
                "BRED+HIG"└───────┘"NOR+GRN"  

    来到这里，你眼前一亮，展现出一间气势辉宏的宽敞厅堂。厅堂
上常年点着牛油巨烛，四下一片雪亮。正中靠前起一个平台，平台上
设有两把红木交椅。只见左边交椅上端坐着一位星目剑眉神彩飞扬的
中年汉子。平台下左右分设着十数把交椅，端地十分庄严。这里便是
盟中的议事大厅，寻常人不得入内。你看到靠左有排楼梯。

  \n"NOR );

        set("exits", ([ /* sizeof() == 2 */
                "north" : __DIR__"juxieting",
                "up"    : __DIR__"zoulang",
        ]));
       set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/npcdoga" : 1,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "txm");


        setup();
        replace_program(ROOM);
}

