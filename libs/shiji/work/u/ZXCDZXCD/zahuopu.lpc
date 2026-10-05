inherit ROOM;
void create()
{
 set("short", "兽族杂货铺");
        set("long", @LONG
这是一家很特别的杂货铺,里面摆满了各式各样的兵器和防具.
还有一些稀奇小玩意不知道是干什么用的,而老板正在旁边睡
觉,如果你要买东西的话随时可以叫醒他.你一抬头就可以看到
一块招牌(zhaopai)。
LONG );
        set("item_desc", ([
                "zhaopai": "请用 \"list\" 列出货物表，\"buy\" 向老板购物。\n",
        ]));
            set("objects", ([
              __DIR__"obj/gangzhua" : 1,
              __DIR__"obj/hujian" : 1,
              __DIR__"obj/tiedun" : 1,
        ]));
//      set("no_clean_up", 0);
        set("exits", ([
   "east" : __DIR__"wangshougu",
        ]));

        setup();
        replace_program(ROOM);
}
