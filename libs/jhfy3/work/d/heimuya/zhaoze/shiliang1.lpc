// Room: /d/heimuya/zhaoze/shiliang1.c

inherit ROOM;

void create()
{
        set("short", "石梁");
        set("long", @LONG
石梁凹凸不平，又加终年在云雾之中，石上溜滑异常，走得越慢，反
是越易倾跌。奔一段，跃过一个缺口，接连过了七个断崖，眼见对面山上
是一大片平地，缺口彼端盘膝坐着一个书生，手中拿着一卷书，正自朗诵。
LONG
);
        set("exits", ([ 
  "south" : __DIR__"shiliang",
]));
        set("outdoors", "shiliang1");

        setup();
}
void init()
{
       this_player()->delete_temp("reply_message");
      if (query("message"))  return;
   add_action("do_reply","answer");
      remove_call_out("send_message");
      call_out("send_message",3,this_player());
}

void send_message(object me)
{
        object room;

    if (!me || environment(me)!=this_object()) return;
        if (!room=find_object(__DIR__"shimao"))
        room=load_object(__DIR__"shimao");
   if (present("shu sheng",room)){
    switch (random(3)){
        case 0:
       message("vision",BOLD+"书生轻吟道：琴瑟琵琶，八大王一般头面。\n"+NOR,this_object());
        set("message",1);
       break;
        case 1:
       message("vision",BOLD+"书生轻吟道：风摆棕榈，千手佛摇折叠扇。\n"+NOR,this_object());
        set("message",2);
       break;
        case 2:
       message("vision",BOLD+"书生轻吟道：大漠孤烟直。\n"+NOR,this_object());
        set("message",3);
       break;
    }
    remove_call_out("reply_message");
    call_out("reply_message",2,me);
    }
}
void reply_message(object me)
{
    if (!me || environment(me)!=this_object()) return;
    message_vision("书生缓缓站了起来，手中折扇指着$N，这位"+RANK_D->query_respect(me)+"可否对出(answer)下联？\n",me);
    me->set_temp("reply_message",1);
}

int do_reply(string str)
{
     if (!str) return notify_fail("你皱起了眉头，愁眉苦脸之状。\n");
      message_vision(BOLD+"$N大声回答："+str+"\n"+NOR,this_player());
     if (!this_player()->query_temp("reply_message")) return notify_fail("好象不是问你耶！\n");
    switch (str){
    case "霜凋荷叶，独脚鬼戴逍遥巾":
    case "霜凋荷叶，独脚鬼戴逍遥巾。":
    case "霜凋荷叶,独脚鬼戴逍遥巾":
      if (query("message")==2){
          message("vision","这下联一说，那书生哈哈大笑，说道：“妙极，妙极！不但对仗工整，而且敏捷之至。”\n",this_object());
      remove_call_out("do_out");
      call_out("do_out",5,this_player());
    return 1;
       }
    case "魑魅魍魉，四小鬼各自肚肠":
    case "魑魅魍魉，四小鬼各自肚肠。":
    case "魑魅魍魉,四小鬼各自肚肠":
      if (query("message")==1){
       message_vision("那书生大惊，站起身来，长袖一挥，向$N一揖到地，说道：“在下拜服。”\n",this_player());
      remove_call_out("do_out");
      call_out("do_out",5,this_player());
    return 1;
      }
    case "长河落日圆。":
    case "长河落日圆":
      if (query("message")==3){
       message_vision("那书生嘿嘿地冷笑了两声，说道：“算你还读过点书。”\n",this_player());
      remove_call_out("do_out");
      call_out("do_out",5,this_player());
    return 1;
        }
    }
          message("vision","那书生气道：“什么屁对？”\n",this_object());
      
   return 1;
}

void do_out(object me)
{
    if (!me || environment(me)!=this_object()) return;
    message("vision","那书生笑了一笑，转身纵过小缺口，道：“请罢。”\n",this_object());
    message_vision("$N一个纵身，跳过缺口。\n",me);
    me->move(__DIR__"shimao");
    delete("message");
}
int valid_leave(object me, string dir)
{
    if (dir=="south")   delete("message");
    return 1;
}

