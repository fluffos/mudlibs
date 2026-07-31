 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "石室");
        set("long", @LONG
拉开门，里面竟然是间宽阔百丈的石室，更加令人奇怪的便是，一个人背负着
双手，站在各式各样的佛像、神像之中，圆圆的脸，头顶已经半秃，脸上带着种很
和气的笑容，若不是脸上那和气但不屑一顾的笑容，真让人会以为是个木匠。他笑
眯眯地看着你，似乎在欣赏一件艺术品般。
LONG
           );
        set("exits", 
           ([ 
       "north" : __DIR__"didao1",
       "up" : __DIR__"hetang",
        ]));
    set("objects", 
       ([ 
//           __DIR__"obj/sand" : 1, 
        ]));
        set("indoors", "baiyun");
        set("coor/x",10);
    set("coor/y",-1680);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}
