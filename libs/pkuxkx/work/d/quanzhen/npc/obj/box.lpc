// box.c
inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_open", "open");
}

void create()
{
        set_name("木箱", ({"mu xiang", "xiang", "box"}));
        set_weight(200000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一只又大又笨的木箱子，有些腐朽了。\n");
                set("unit", "只");
                set("material", "iron");
        }
        setup();
}



int do_open(string arg)
{ object zhi,me;
  me=this_player(); 
    
 if( !arg || arg=="" ) 
     return 0;
 
 if ((random(10)>8) 
   &&!present("damo sword",this_player()))

  {
  zhi=new(__DIR__"damosword");

  zhi->move(me);
  
  write( "\n你打开木箱，发现一把蓝茔茔的宝剑，便拿在手里。\n");
  /*  me->set_temp("havedamo", 1); */
  return 1;
  }
  write("木箱里面什么都没有。\n");  
/*    me->set_temp("havedamo", 1); */

   return 1;

}
