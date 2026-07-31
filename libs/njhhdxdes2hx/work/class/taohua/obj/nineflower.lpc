// medicine: nineflower.c
// Jay 3/18/96

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("九花玉露丸", ({"jiuhua wan", "nineflower", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("long", "这是一粒九花玉露丸。\n");
     set("no_get",1);
                set("value", 500);
        }
        setup();
}

int do_eat(string arg)
{       
        
        if (!id(arg))
                return notify_fail("你要吃什么？\n"); 
        
         if ((string)this_player()->query("family/family_name")!="桃花岛")
         {    this_player()->add("max_neili", 10);
             this_player()->add("max_jingli",3);
         write("你吃了一粒九花玉露丸,只觉得一阵清凉!\n");         
          }
          else
         {write("你吃下一粒九花玉露丸，顿时间觉得全身充满了活力 !\n");
             this_player()->add("max_neili", 50);
             this_player()->add("max_jingli",6);
          }
       destruct(this_object());
       return 1;
}

