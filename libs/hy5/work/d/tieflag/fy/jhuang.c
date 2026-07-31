inherit ROOM;
void create()
{
        set("short", "黄衣室");
        set("long", @LONG
黄衣警卫专门负责金钱帮总舵的安全。来往的人都要经过他们的仔细盘查。这
里是他们轮班休息的所在。屋中有几张小床，几张小几。每张床头都有小钩，警卫
们都把兵器挂在钩上，一伸手就可以以最快的速度拔出自己的兵刃。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"jting",
  "east" : __DIR__"tang1",
  "west" : __DIR__"tang2",
  "north" : __DIR__"tang3",
]));
        set("objects", ([
        __DIR__"npc/huangyi" : 2,
        __DIR__"npc/huangyi2" : 1,
                        ]) ); 
    set("coor/x",-20);
        set("coor/y",-15);
        set("coor/z",0);
        setup();
        }      
int valid_leave(object me, string dir)
{
        object ob;
        if( !me->query_temp("jinqian") && me->query("class") != "assassin" && (dir == "north"|| dir== "west") && ob=present("guard leader", this_object())) {
        if(ob=present("guard leader", this_object())){
                return notify_fail("黄衣卫统领怒斥：闲杂人等不要随处走动！\n\n这个方向的路被"+ob->name()+"挡住了。\n");
                } else if(ob=present("guard", this_object())){
                        return notify_fail(ob->name()+"冷笑：那不是你可以去的地方！\n\n这个方向的路被"+ob->name()+"挡住了。\n");
                }
        }
        return 1;
}  