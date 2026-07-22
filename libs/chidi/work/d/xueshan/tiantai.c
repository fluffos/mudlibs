//      tiantai.c 天台
//      Designed by secret (秘密)
//      97/04/09
inherit ROOM;
void create()
{
        set("short","天台");
        set("long",@LONG
这里是雪山寺的高处。北边可见雄伟的大雪山，几千年的白雪
将整个山脉染成白色，眼前一片白色连绵不绝，太阳光照射在上面
泛出点点五彩斑斓的闪光点。南边蔚蓝色的圣湖，在阳光下反射出
点点的蓝光。
LONG
        );
        set("exits",([
                "west" : __DIR__"neidian",
        ]));
        setup();
        replace_program(ROOM);
}

