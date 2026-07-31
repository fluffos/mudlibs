inherit ROOM;

void create()
{
        set("short", "云海石");
        set("long", @LONG
这里放着一座硕大的石头。是白自在从雪山绝谷中找到的奇
石，上面云气缭绕，布满了奇形怪状的花纹。听说在要下雨的时
候，还会散发出不同形状的云雾，缭绕四周，经久不散，是白自
在最喜欢来赏玩的宝物。
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"meiroad2",
        ]));
        set("item_desc", ([
      "stone" : "这是块布满了云气花纹的大石,凝望着它，只见一团团云雾似乎在不断向前推涌，直如意欲破石飞出。\n",
        ]));
       set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("do_think", "think");
}

int do_think()
{
   object ob;
   int c_exp,c_skill;
   ob = this_player();

   c_skill=(int)ob->query_skill("dodge", 1);
   if (c_skill <150)
   {
      message_vision("$N的基本轻功显然太低，无法领悟云海石内容。\n",ob);
      return 1; 
   }
   c_exp=ob->query("combat_exp");

   if ((c_skill*c_skill*c_skill/10)> c_exp)
   {
      message_vision("$N的实战经验不足，无法领悟云海石内容。\n",ob);
      return 1; 
   }
   if (ob->query("jing")<20)
   {
      message_vision("$N太累了，现在无法领悟云海石内容。\n",ob);
      return 1; 
   }
   if (c_skill>350)
   {
      message_vision("$N觉得石面内容太肤浅了。\n",ob);
      return 1; 
   }

   message_vision("$N面对着云海石上的云气花纹冥思苦想.对基本轻功稍有心得。\n",ob);  
   ob->improve_skill("dodge", ((int)ob->query("int") + (int)ob->query("dex") + random(10)));
   ob->add("jing",-30);
   return 1;
}

