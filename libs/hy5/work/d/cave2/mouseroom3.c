 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "主室");
        set("long", @LONG
石门後竟是一间六角形的石室，再也没有别的门户。嵌在石墙中的十来盏
铜灯，一盏盏燃了起来。里面有一口很大的石棺，还有许多石像。这些石
像竟全都雕成移花宫主姊妹和魏无牙的模样，而且都和真人差不多大小，
自成一组，每一个的姿态都不同。每一个石像都雕得活灵活现，纤毫毕露。
第一组石像是移花宫主姊妹两人跪在地上，拉着魏无牙的衣角，在向他苦
苦哀求。
第二组石像是魏无牙在用鞭子抽着她们，不但移花宫主姊妹面上的痛苦之
色栩栩如生，样子也好像活的一样。
第叁组石像是移花宫主姊趴在地上，魏无牙就踏着她们的背脊，手还举个
杯子在喝酒。 
LONG
        );
        set("exits", ([ 
            "south" : __DIR__"mouseroom3",
                ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
}    
