#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(CYN"武功秘籍"NOR, ({"miji"}));
        set("unit", "本");
        set("long", "这是一个无名高手记录自己的练武经历的书籍，阅读(read)此书可以开阔你的眼界，提升你的潜力。\n");
        setup();
}

void init()
{
        add_action("do_read", "read");
}

int do_read(string arg)
{
  object me=this_player();
  
  if ( me->query("id") !=query("owner") )
  {
    tell_object(me, "这不是你的书籍，你不能阅读。\n");
    return 1;
  }
  
  if ( me->is_busy() )
  {
    tell_object(me, "你现在没有功夫阅读书籍。\n");
    return 1;
  }
  
  me->add_busy(5);
  tell_object(me, "你专心地阅读他人写的学武经历，你的潜能提升了！\n");
  me->add("potential", 5000);
  call_out("dest_me",1);
  return 1; 
}

void dest_me()
{
  destruct(this_object());
}