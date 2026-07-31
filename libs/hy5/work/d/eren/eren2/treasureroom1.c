 inherit ROOM;
void create()
{
        set("short", "石像室");
        set("long", @LONG
小小的一间屋子里放满了石像，有的还没有完工，胡乱地堆在地上。
这些石像全雕成移花宫主姊妹和魏无牙的模样，而且都和真人差不多大
小。有的是移花宫主姊妹两人跪在地上，拉着魏无牙的衣角，在向他苦
苦哀求。有的是魏无牙在用鞭子抽着她们，不但移花宫主姊妹面上的痛
苦之色栩栩如生，样子也好像活的一样。
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"mouseroom3",
                
                        ]));
        set("item_desc", ([
                "石像": "每一个石像都雕得活灵活现，纤毫毕露。\n",
                "statue": "每一个石像都雕得活灵活现，纤毫毕露。\n",
                "shixiang":"每一个石像都雕得活灵活现，纤毫毕露。\n"
        ]) );
        set("objects", ([ 
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
