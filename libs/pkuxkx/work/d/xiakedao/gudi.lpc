// for xiakedao
// modified by aiai 98/10/27
#include <ansi.h>
#include <command.h>

inherit ROOM;

      string look_river();
void create ()
{
   set ("short", "谷底");
   set ("long", @LONG

    这里是山谷底部，四周都是悬崖峭壁(cliff)，高耸入云。但谷底倒
不只是一个荒芜的地方，有很多奇怪花草(grass)生长在这里。在谷底深
处有一条清澈的小溪(river)缓缓而流，不知它通向什么地方。
LONG);

  
   set("exits", 
   ([ 
   ]));
   
   set("objects", 
   ([ //sizeof() == 1

          __DIR__"obj/flower" : 1,
   ]));
   set("item_desc", ([
         "river": ( : look_river : ),
              "花草": "鲜艳的花草丛中上露出一角旧布。\n",
              "grass": "鲜艳的花草丛中上露出一角旧布。\n",
              "悬崖": "崖壁如同刀削的一样般，滑不留人，上面寸草不生。抬头望，\n你隐约可见半崖上突出一块白色的山石。\n",
              "cliff": "崖壁如同刀削的一样般，滑不留人，上面寸草不生。抬头望，\n你隐约可见半崖上突出一块白色的山石。\n",
   ]) );


   set("outdoors", "xiakedao");

   setup();
}


string look_river()
{
    object me;
    me = this_player();
      me->move("/d/xiakedao/gudi");
            return "这是谷底的一条小溪，也许你可以潜水(dive)到下面看看。\n";
}



void init()
{
	add_action("do_climb", "climb");
	add_action("do_dive", "dive");
}

void reset()
{
        object          *inv;
        object          con, item;
        int             i;

        ::reset();
        con = present("flower", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/oilbag");
                item->move(con);
        }
}

int do_climb(string arg)
{
        object 	me;
	int	mlvl;

          if(!arg || arg != "悬崖" && arg != "cliff") {
		write("你要爬什么？\n");
		return 1;
	}
	me = this_player();
	if(  random (me->query_skill("dodge",1)) < 150)  
		message_vision(HIY "\n$N奋力向上爬去，爬了不到两三丈，只觉的手脚发软，向下滑了下去。\n" NOR, me);
	else {
		message_vision(HIY "\n$N小心翼翼地向上爬去，身形慢慢被云雾遮掩。\n" NOR, me);
		me->move(__DIR__"gukou");
	}
	return 1;
}

int do_dive()
{
        object *inv,me;
        object bottom;
           me = this_player();
       if (me->query_temp("xkd/gudi"))
   {
        int i;
	string	objname;

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
		objname = (string)inv[i]->query("name");
		if( objname != "油皮袋" && objname != "花草")
	       		DROP_CMD->do_drop(me, inv[i]);
	}
        message_vision("$N脱光了所有衣服，一个猛子扎入湖水中．\n",me);
        bottom = load_object(__DIR__"bottom1");
        if(bottom) me->move(bottom);
        return 1;
        }
        else
      {
   message_vision("水太冷了，还是上来吧。\n",me);
     return 1;
   }
}
