inherit ROOM;
void create()
{
          set("short", "ÑÆ¹Ö¾Ó");
        set("long", @LONG
ÑÆ¹Ö¾Ó£¬Í¨³Ô°ïÁù¹ÖÖ®Ò»ÑÆ¹ÖÖ£ÎŞÑÔµÄ¾ÓËù£¬¬
ÑÆ¹ÖÓÉÓÚ²»ÄÜÑÔÓï£¬Ò»°ã¶¼´ôÔÚÎİ×ÓÀï¡£
LONG
        );
        set("exits", ([
                  "west" : __DIR__"qinjv",
        ]));
        set("objects", ([
        "/d/tongchi/npc/yaguai":1,
        ]));
        setup();
        replace_program(ROOM);
}
