inherit ROOM;
void create()
{
set("short", "烟波瀛洲楼一楼大厅");
set("long", @LONG
這裡是煙波瀛洲樓大廳，進門對面一幅巨大的飛馬圖，定睛一看，
居然是唐人韓干所作，門後屏風為幾幅侍女撲雀圖，為徽宗之落款。
架上桌上無不是歷代之珍品古跡，當中一八仙桌，上面放著文房四寶
和一疊湖州宣紙。這裡就是煙波瀛洲閣成員的聚會大廳了。

LONG
);
        set("exits", ([
"south" : "/p/residence/bluemoon1208363382.c",
]));
set("objects", ([
       ]) );
        set("owner", "bigtie7001");
        set("banghui", "$HIC$烟$HIW$波$HIB$瀛洲$HIR$阁");
        set("no_fight", 1);
setup();
      call_other("/p/residence/board/bluemoon1208363906", "???");
}
