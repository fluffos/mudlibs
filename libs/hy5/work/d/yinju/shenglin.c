inherit ROOM;

void create()
{
  set("short","黑森林");
  set("long",@LONG
这是一片茂密的黑森林。很多棵几十丈高的大树聚在一块，象一把把琼天
大伞，连日月都被遮蔽得暗然无光。黑森林中阴森恐怖。
LONG);
  set("outdoors","yinju");
set("exits",([
   "west"  : __DIR__"nitang1",
  "east"  : __DIR__"damen",
     ]));
   
  setup();
}
