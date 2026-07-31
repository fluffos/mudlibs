 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "九曲桥");
        set("long", @LONG
荷塘南行，须经过一座蜿蜒盘绕的九曲桥，而四周彷佛在一个空谷中，唯有远
远望去的一盏灯火若隐若现，荷塘四周远远近近，高高低低都是树，树色一例是阴
阴的，乍看像一团烟雾，一切似乎笼罩在梦中一般，缥缈不定。走过九曲桥，不远
处便是一个彷佛建在池塘上的朱栏绿瓦的水阁。
LONG
           );
        set("exits", 
           ([ 
       "down" : __DIR__"hetang",
       "southeast" : __DIR__"shuige",
        ]));
    set("objects", 
       ([ 
//           __DIR__"obj/sand" : 1, 
        ]));
        set("outdoors", "baiyun");
        set("coor/x",10);
    set("coor/y",-1680);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}   
