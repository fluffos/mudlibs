inherit ROOM;
void create()
{
  set ("short", "小河边");
  set ("long", @LONG

你走到这里感觉到处充满春的洋溢，让你奇怪的是，外面已经是寒冬
腊月，这里怎么处处生机勃勃，片片都是绿色的涵蕴。一条小河拦在
你的面前，涓涓细流之中时不时的还能看见鱼儿在水中戏游。不远处
一位慈祥的白胡子老大爷在那里垂钓，让你惊奇的他手中的鱼杆的前
端的鱼线上面居然没有鱼钩，你好奇的经不住想问点他什么...

LONG);
        set("exits", ([
        "north": __DIR__"diaoyu3",
//        "south": __DIR__"diaoyu2",
]));

        set("no_fight", 1);
    set("outdoors", "xy1");
  setup();
}
