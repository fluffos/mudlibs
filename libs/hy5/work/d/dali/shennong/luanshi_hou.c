// 乱石后 /d/menpai/shennong/luanshi_hou.c

inherit ROOM;



void create()
{   
    set("short",    "乱石后");
    set("long", @LONG
在大堆的乱石丛中，放着几口大铁锅，几个神农帮帮众在一条大汉的指挥下
正忙着烧火煮炼毒药。那大股大股的青烟就是从这里冒出的。这烟的味道颇为古
怪，一嗅就知道煮的是剧毒之物。旁边的茅草在这股烟中都变得枯黄了。
LONG
    );
    set("exits",    ([
        "southwest" :   __DIR__"dong_shanyao",
        "northwest" :   __DIR__"luanshi1",
    ]) );
    set("objects",  ([
        __DIR__"npc/asheng"         :   1,
        __DIR__"npc/bangzhong"      :   2,
    ]) );
    set("outdoors", "wuliang");
    setup();
}

