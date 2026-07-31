#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "真宝库大厅");
        set("long", @LONG 
这是一个圆形的石室，中央有张圆形的石桌，置有八张
石椅，面绘有一张图文并茂缮析详尽的宝库地图，更显示出
宝库与地面上鹿马集的关系。这正圆形的地室另有四道普通
的木门，分别通往四个藏宝室，桌下尚备有火石、火熠和纸
煤，以供点燃平均分布在四周室壁上的八盏墙灯。
LONG );
	set("objects", ([
		__DIR__"obj/corpse" : 3,
	]));

               set("exits", ([
                "north"  : __DIR__"baokun",
                "west"   : __DIR__"baokuw",          
                "east"   :  __DIR__"baokue",
                "south"  : __DIR__"baokus",
                                
        ]));
        set("item_desc", ([ 
          "石桌" : MAG"你发现宝库里有四条地道，入口分别在四库之内
，其中一条直达城外一座小丘处。」\n"NOR, 
  
 ]));


  set("no_clean_up", 1);
        setup();
}


void init()
{
    object *obj;
  object me = this_player();
   obj=children(__DIR__"obj/ssl");
delete_temp("ssl");
   if (sizeof(obj)>4)  set_temp("ssl",1);
        add_action("do_zhuan", "zhuan");
        add_action("do_ba", "ba"); 
        add_action("do_pai", "pai");
        add_action("do_pick", "pick");
}

int do_pai(string arg)
{
        object me;
        me = this_player();
      if( !arg || arg=="" ) return notify_fail("你要住批拍什么东西!\n");
            if( arg=="石桌" ) {
write(HIB"你拍上去时感觉传入手掌的震荡力，似是可以活动的样子。\n"
HIB"莫非内有蹊跷??\n"NOR);
             this_player()->set_temp("paizhuo", 1);
             return 1;
       }
}

int do_ba(string arg)
{
        object me;
        me = this_player();
      if(! me->query_temp("paizhuo")) return 0;
      if( !arg || arg=="" ) return notify_fail("你要把什么东西!\n");
            if( arg=="桌沿" ) {
 write(HIB"你双手抓着桌沿，朝上拔起。桌子应手上升两寸，发出一声轻响。
\n"NOR); 
         write(HIC"桌沿似乎可以往左右转动，到底转哪边好呢? \n"NOR);
             this_player()->set_temp("bazhuo", 1);
             this_player()->delete_temp("paizhuo");
             return 1;
       }
}

int do_zhuan(string arg)
{
        object me; 
    object room;
    string dir;
             me = this_player();
 if (!me->query_temp("bazhuo")) 
return 0;
      if( !arg || arg=="" ) return notify_fail("你要转什么东西!\n");
      if( sscanf(arg, "%s", dir)==1 ) {

    if( dir=="left" ) {
   message_vision(HIC"$N把桌沿往左转了一转。\n"NOR, this_player()); 
 call_out("on_kai", 1);
               this_player()->delete_temp("bazhuo");
return 1;
}
 else if( dir=="right" ) {
                     
            message_vision(HIC"$N把桌沿往右转了一转。\n"NOR, this_player()); 
     message_vision(HIC"突然$N的脚底下出现一个洞，$N掉了下去。\n"NOR, this_player());

     this_player()->move("/d/lumaji/pomiao");
     this_player()->unconcious();
     this_player()->delete_temp("bazhuo");
        return 1;
        }
        else {
            write("你想转向哪个方向?\n");
            return 1;
        }
}
} 

int do_pick(string arg)
{
   object ssl, hezi, me=this_player();

        if( !arg || arg=="" ) return 0;
if (!me->query_temp("pick_shen")) 
return 0;
if (query_temp("picktime")>time())
return notify_fail("刚刚才有人拿了圣舍利,你还是再等几分钟看看吧!\n");

        if( arg=="小铜盒" )
                             {  
if(query_temp("ssl")){ 
   message_vision("$N想去拿铜盒结果发现已经给人拿了\n", this_player());
     this_player()->move("/d/lumaji/pomiao");
     return 1;
 }
                                message_vision(
HIY"$N在小空间里拿出了一个小铜盒!\n"NOR, this_player());
           ssl = new(__DIR__"obj/ssl");
                 hezi = new(__DIR__"obj/hezi");
  ssl->set("zhuren",""+me->query("id")+"");
                      ssl->move(hezi);   
                      hezi->move(me);   
set_temp("ssl",1);
set_temp("picktime",time()+1800);
me->delete_temp("pick_shen");
// message("channel:chat", HBWHT HIC"【海洋】"+me->query("name")+"在杨公宝库里发现了神秘的小铜盒了!\n"NOR,users()); 

return 1;
                }
       return 0;
}

void on_kai(object room)
{
message_vision(HIG"桌旁一方地板突然往下沉去，现出内里窄小的空间!\n
这个空间里似乎有个小铜盒,你似乎可以拿(pick)出来!\n"NOR, this_player());
this_player()->set_temp("pick_shen",1);
}

