
// Room: /d/taishan/newplayer.c
// Date: CSWORD 96/03/25
inherit ROOM;
void create()
{
      set("short", "江湖新秀厅");
    set("long", YEL@LONG
  所谓长江后浪推前浪，青出于蓝胜于蓝.江湖新秀称霸天下。
  这里是给江湖新玩家建立的一个武林争霸台，所有的新玩家都
可以来这里一分高低。
LONG
    );
        set("valid_startroom", 1);
    set("exits", 
       (["down" : __DIR__"fengchan",
    ]));
    set("objects",
    ([ __DIR__"npc/wei-shi1" : 2,
       __DIR__"npc/xin-xiu" : 1,
    ]));
        set("no_clean_up", 1);
    set("outdoors", "taishan");
    setup();
}
void init()
{
 add_action("discmds",({"get","give","put"}));
}
int discmds()
{
tell_object(this_player(),"你想干什么? \n");
return 1;
}
