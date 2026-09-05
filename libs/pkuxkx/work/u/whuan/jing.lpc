inherit ITEM;
#include <ansi.h>;
int des();
void create()
{
        set_name(WHT"通天镜"NOR, ({"tongtian jing", "jing"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "面");
                set("long", "一个亮闪闪的铜镜，是一个预测宝物位置的神奇东西，似乎可以（detect）探察宝物位置。\n");
                set("value", 0);
          }
        setup();
		
}

void init()
{
        add_action("do_detect", "detect");
        add_action("do_detect", "zhao");
		    add_action("do_dig", "dig");
		    add_action("do_dig", "wa");
		    call_out("des",600);
}

int do_detect()
{
    if(!query("owner") || query("owner")!=this_player()->query("id"))
	  return notify_fail("什么？\n");
	  if(!query("region")) 
	  	{
	  		tell_object(this_player(),"通天镜探测了半天，似乎什么都没有找到。\n");
	  		return 1;
	  	}
	  if(!query("desc")) 	  	
	  	{
	  		tell_object(this_player(),"通天镜探测了半天，似乎什么都没有找到。\n");
	  		return 1;
	  	}
    tell_object(this_player(),HIY"宝物的地点似乎在"NOR+query("region")+"。\n\n"); 	
    tell_object(this_player(),query("desc")+"\n"); 
	  return 1;
}

int do_dig()
{
	object room, me,book;
	string master;
	string name;
	me=this_player();
	master=query("owner");
  if(master!=me->query("id"))
	  return notify_fail("什么？\n");
	 
	if(me->query("qi")<=50)
	  return notify_fail("你太累了，休息一下在挖吧。\n"); 

	if(me->is_busy())
	  return notify_fail("你忙着呢，等下再挖吧。\n"); 
  
  if ( query("dig_num") > 2)
  {
    message_vision(HIY"只听“铛”的一声，铁铲断成两节!\n"NOR,me); 
    destruct(this_object());
    return 1;
  }
  
  room=environment(me);	  	     
	if(file_name(room)!=query("file_name"))
	{
		message_vision(HIR"$N俯下身来，小心翼翼的挖着，生怕弄坏了什么。\n"NOR,me);
		tell_object(me,HIR+"你挖了半天，发现什么都没有，似乎找错地方了。\n"NOR);
		me->start_busy(5);
		me->receive_damage("qi",30);
		add("dig_num",1);
		return 1;
	}	
	
		message_vision(HIR"$N俯下身来，小心翼翼的挖着，生怕弄坏了什么。\n"NOR,me);
		message_vision(HIY"$N过了一会儿，从土里掏出一件东西，不禁欢呼起来。\n"NOR,me);
		book=new("/d/city/player/obj/baowu");
		book->set("owner",me->query("id"));
		book->move(me);
		me->start_busy(5);
	  me->receive_damage("qi",30);
	  call_out("des",2);
    return 1;  
}	
int des()
{
	message_vision(HIW"忽然一道白光，$N身上的通天镜消失的无影无踪。\n"NOR,this_player());
	destruct(this_object());
	return 1;
}


