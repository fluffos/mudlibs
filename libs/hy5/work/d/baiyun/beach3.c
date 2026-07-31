  //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
inherit ROOM;
void create()
{
        set("short", "沙滩");
        set("long", @LONG
在这里，你已分不清天上人间。阳光灿烂，沙滩洁白柔细，海水湛蓝如碧，浪涛
带着新鲜美丽的白沫轻拍着海岸。极目而望，海中有天，天中有海。仰视碧空，但见
天做沧海，云做轻帆。沙滩上摆放着几张渔网，三两个渔家姑娘正在一边修补渔网，
一边哼着渔家小调。海水荡漾下，软软的沙子踏上去格外舒服。
LONG
           );
        set("exits", 
           ([ 
             "east"  : __DIR__"beach1",
            ]));
        set("item_desc", 
           ([
             "海水": "透过清澈碧蓝的海水，你可以看到在水中嘻戏的鱼虾，还有随著海浪婆娑起舞的海藻。\n",
             "seawater":"透过清澈碧蓝的海水，你可以看到在水中嘻戏的鱼虾，还有随著海浪波婆娑起舞的海藻。\n",
            ]));
        set("objects", 
           ([ 
             __DIR__"obj/sand" : 1,
             __DIR__"npc/xian3" : 1,
            ]));
        set("littlething", 10);
        set("outdoors", "baiyun");
        set("coor/x",-30);
        set("coor/y",-680);
        set("coor/z",0);
        setup();
}         
