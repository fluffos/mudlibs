 inherit ROOM;
void create()
{
        set("short", "树林");
        set("long", @long
树林里光线暗淡，只能听见头顶上传来一些鸟儿的啼鸣。偶而从茂
密的叶间透过的一线光伴着落叶在飞舞。朽木腐烂的气味和身後传来野
兽的啸声使人不觉犹豫了前进的脚步。
long
        );
        set("exits", ([ 
  "north" :__DIR__"men",
  "east" : __DIR__"shulin",
  "west" : __DIR__"shulin",
  "south" : __DIR__"road",
  
]));
        set("outdoors", "shanxi");
        set("coor/x",-500);
        set("coor/y",-390);
        set("coor/z",100);
        setup();
}
void init()
{
        add_action("do_go","go"); 
} 
int do_go()
{
if(random(3)){
this_player()->move(this_object());
return 1;
}
} 
