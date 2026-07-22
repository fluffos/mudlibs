// jiuyin-zhenjing  by:pipip
inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>; 
void setup()
{}
void init()
{
        add_action("do_du", "zuanyan");
}
void create()
{
        set_name(HIW"「"HIC"九阴真经"HIW"」"NOR, ({ "jiuyin zhenjing","zhenjing", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("material", "paper");
                set("no_give", 1);
                set("no_drop", 1);
                set("no_get", 1);
                set("long",
        "一本薄薄的小册子，记载着江湖中人梦寐以求的九阴心经大法。\n", );
        }
}

int do_du(string arg)
{
   object ob;
   int c_exp,c_skill;
   ob = this_player();

   c_skill=(int)ob->query_skill("literate", 1);
   if (c_skill <2000)
   {
      message_vision("$N的领悟力不够强，完全看不懂书上深奥的道理。\n",ob);
      return 1; 
   }

   if (ob->query("jing")<20000)
   {
      message_vision("$N太累了，再学下去只怕要晕倒。\n",ob);
      return 1; 
   }
   if (ob->query("max_jingli")<100000)
   {
      message_vision("$N的精力太少了，怕钻研不来这么深奥的武功。\n",ob);
      return 1; 
   }
   if (ob->query("max_neili")<600000)
   {
     message_vision("$N的内力不够深厚，怕钻研不来这么深奥的武功。\n",ob);
     return 1; 
   }
   if( environment(ob)->query("no_fight"))
                return notify_fail("这里不适合研读真经。\n");

     if (ob->query_skill("jiuyin-xinjing", 1)>1000)
   {
      message_vision("$N钻研了一会，发现自己已经完全掌握了书上的武学奥秘。\n",ob);
      return 1; 
   }

// 65     message_vision(RED"$N正在专心的研读九阴真经密本。\n"NOR,ob);
     write(RED"你正在专心的研读九阴真经密本。\n"NOR);
   ob->improve_skill("jiuyin-xinjing", (int)ob->query_skill("parry", 1)/20);
   ob->add("jing",-15000);
   return 1;
}

int move(mixed dest)
{
        if(! userp(dest))       return ::move(dest);
        if( ::move(dest)==0)    return 0;
         message("channel:rumor",HIR"【武林宝典】"+ "某人：九阴真经被"+
        dest->query("name")+"抢到手了！\n"NOR,users());
        return 1;
}

