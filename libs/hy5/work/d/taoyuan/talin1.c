 inherit ROOM;
void create()
{
        set("short", "桃林");
        set("long", @LONG
这是一片茂密的桃树林，林中芳草鲜美，落英缤纷，一层淡淡的薄雾，混
合着青青的草香，弥漫在空气之中。偶尔的一两声鸟鸣，愈发地显出幽静来。
这里的小路已被落花铺满，早已辨不出痕迹来。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"taolin2",
  "west" : __DIR__"taolin",
])); 
        set("item_desc", ([
            "桃树": "桃树上结满了大蜜桃。\n",
            "peach tree": "桃树上结满了大蜜桃。\n",
        ]) ); 
        set("outdoors","taoyuan");
        set("coor/x",120);
        set("coor/y",-30);
        set("coor/z",0);
        set("peach_amount",5);
        setup();
} 
void init() 
{
   add_action("do_pick", "pick");
} 
int do_pick(string arg)
{
   object me, zhi; 
   me = this_player(); 
   if(!arg || arg != "peach" && arg != "蜜桃") return 0;        
   zhi = new(__DIR__"obj/taozi");
   zhi->move(me);
 
   message_vision("\n$N伸手摘了一个鲜美的桃子下来。\n", me);
        
   return 1;    
}       
