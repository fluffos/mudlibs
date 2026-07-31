 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
inherit ROOM;
void create()
{
        set("short", "船行");
        set("long", @LONG
本船行专门为各位出海人士提供各种价格合理、服务一流的海船出租业务，具体
细节请各位参看价格牌。在船行的大厅中间挂有价格牌（ｓｉｇｎ）一块。
LONG
           );
        set("exits", 
           ([
             "west" : __DIR__"southsearoad1",
            ]) );
        set("item_desc", 
           ([
             "sign": @TEXT
本字号提供的租船服务有： 
木筏 (raft)：简易轻便，搏击海浪，回归自然，古朴风情，只需50 两白银。
小舟 (boat)：一叶扁舟，随波逐流，情人合乘，浪漫风情，只需5000 两白银。
海船 (ship)：豪华之旅，劈波斩浪，如履平川，宫廷风情，只需50000 两白银。;
TEXT
            ]) );
        set("objects", 
           ([
             __DIR__"npc/boatowner" : 1,
            ]) );
        set("coor/x",20);
        set("coor/y",-660);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
/*
//我们提供的租船服务有：
//
//木筏 (raft)             10 两白银。
//小船 (boat)            100 两白银。
//海船 (ship)           1000 两白银。
//
//欢迎再次光临本店。*/       
