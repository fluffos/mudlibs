inherit ROOM;
void create()
{
        set("short", "浴室");
        set("long", @LONG
杀手帮的浴室，弟子们在一天的劳作之后，都喜欢到这里来泡泡，消除疲劳
这里也是探听江湖消息的好地方.旁边挂着一个牌子(paizi)
LONG
        );
        
        set("no_fight",1);
        set("exits", ([
                "south" : __DIR__"dadao11",
                
                ]));
          set("objects", ([
       
           ]));
		   set("hsz_no_task",1);
        set("count",5+random(4));
      set("item_desc", ([
       "paizi":"男浴室\n",]));
        setup();
       
}


void init()
{
    object me=this_player();
    add_action("bath","bath");
    if (!userp(me))
    {
        me->move(__DIR__"dadao11");
    }
}

int bath()
{
    object me=this_player();
    object ob=this_object();
    int my_qi,my_jing,eff_qi,eff_jing,qi,jing,busy;
    if(ob->query("count")<=0)
     {
        write("今天浴室就营业到这，明天再来吧!\n");
        return 1;
     }
    eff_qi=me->query("eff_qi");
    eff_jing=me->query("eff_jing");
    qi=me->query("qi");
    jing=me->query("jing");
    busy=((eff_qi-qi)+(eff_jing-jing))/50+1;
    if(busy>6) busy=6;
    me->start_busy(busy);
    message("vision","你舒舒服服的躺了下来，好舒服啊!\n",me);
    my_qi=eff_qi;
    my_jing=eff_jing;
    me->set("qi",my_qi);
    me->set("jing",my_jing);
    ob->add("count",-1);
    return 1;
} 
