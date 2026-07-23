 inherit ROOM;
void create()
{
        set("short", "蜀道");
        set("long", @LONG
自古蜀道路难行，一代诗仙李白诗曰：噫吁戏，危乎高哉！蜀道之难难于上青
天！但见青山映赤水。一路蜿蜒曲折，急流险滩，天梯石栈犬错勾连，猿鸟哀号古
木遮天，岩峦九折青泥盘盘。因此巴蜀中人又称这条路为登天道，世人难行。
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"hutiao",
  "northeast" : __DIR__"shudao2",
]));
        set("outdoors", "guanwai");
        set("coor/x",-810);
        set("coor/y",-660);
        set("coor/z",0);
        set("objects", ([
                __DIR__"obj/tianti" : 1,
        ]));
        setup();
} 
int valid_leave(object me, string dir)
{
        
        int max_jing;
        if (dir == "northeast")
        {
        if(random(5))
                {
                        max_jing = me->query("max_jing");
                        max_jing = me->query("max_jing"); 
                        if (me->query("jing") <= max_jing /5)
                        {
                                  return notify_fail("你现在太累了，还是先休息一下吧。\n");
                        }
                        me->add("jing",-(max_jing*(10+random(10))/100));
                        me->add("qi",-(max_jing*(10+random(10))/100));
                        me->move(this_object());
                   tell_object(me,"你沿着蜿蜒的山道拾级而上。\n");
                        if(me->query("sen") <= max_jing/2)
                        {
                                tell_object(me,"你汗滴如雨，每一步都是艰辛，但仍不愿放弃，咬牙前行。\n",);
                        }else
                        {
                                tell_object(me,"放眼望去，虽是奇峰叠峦，美景无尽，行来却步步艰难。\n");
                        }
                        return notify_fail("");
                }
        }
        return 1;
}    
