 inherit ROOM;
void create()
{
        set("short", "地道尽头");
        set("long", @LONG
地道越走越窄，前面一块巨石，如屏风般隔绝了去路。洞壁上生满了盘旋
纠缠的藤萝，尽掩没了山石的颜色。不知为什么，这儿的老鼠特别多，似乎也
不怕人，吱吱地往人裤腿，袖管里钻。
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"jailroad4",
        ]));
        set("objects", ([
                __DIR__"npc/rat" : 3,
                __DIR__"obj/jadedoor" : 1,
        ]) );
        set("item_desc", ([
                "巨石": "一块巨大的山石挡住了去路。\n",
                "rock": "一块巨大的山石挡住了去路。\n",
                "藤萝": "这片青苔长得最密，但却有大半已枯死，拨开青苔，就露出扇小门。\n",
                "青苔": "这片青苔长得最密，但却有大半已枯死，拨开青苔，就露出扇小门。\n",
                "vine": "这片青苔长得最密，但却有大半已枯死，拨开青苔，就露出扇小门。\n",
                "小门": "一扇白玉做成的小门，门上有个钥匙孔。\n",
                "door": "一扇白玉做成的小门，门上有个钥匙孔。\n",
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
} 
reset() {
        delete("exits/north");
        ::reset();
}
