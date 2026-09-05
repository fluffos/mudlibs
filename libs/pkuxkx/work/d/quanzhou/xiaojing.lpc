// /d/jiaxing/xiaojing1.c 江南乡间小径

inherit ROOM;

void create()
{
        set("short", "乡间小径");
        set("long", @LONG
江南乡间阡陌纵横，小路弯来绕去，道路狭窄，你数次踏入
田中，双脚全是烂泥。
LONG
        );

        set("exits", ([
                "northeast" : __DIR__"jxnanmen",
                "southwest" : __DIR__"shulin",
                     "west" : __DIR__"river",
        ]));

        set("outdoors", "嘉兴");
        setup();
//       replace_program(ROOM);
}
void init()
{   object me = this_player();
    int luck = me->query_temp("oyf_meet");
      if(!me->query("oyf_son")) {
       if((random((int)me->query("kar")) <= 5 || random((int)me->query("kar")) >= 20)&&
          me->query_condition("bing_poison") > 30 &&
          me->query("age") < 19){
          if(!luck) {
          write("你突然觉得好象有人在你身后，转过头来却发现什么也没有。\n");
          me->set_temp("oyf_meet", 1);
          }   
       if (luck >= 1) {
          write("你突然觉得好象有人在你身后，转过头来却发现什么也没有。\n"); 
          me->add_temp("oyf_meet", 1); 
          } 
        }      
     }                         
}
int valid_leave(object me, string dir)
{
        if ((int)me->query("jingli")<11 &&
            dir == "west")
                return notify_fail("你突然觉得很累，走不动路，也许是精力不够了！\n");
        return ::valid_leave(me, dir);
}

