// Room: /d/huashan/sgyhole.c

inherit ROOM;

void create()
{
        set("short", "山洞");
        set("long", @LONG
飞天御剑流历代领悟杀意的地方，在墙角有不少骸骨．
你可以在这里静坐领悟杀意.
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "out"     : __DIR__"pingtai",
        ]));
        set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("do_jingzuo", "jingzuo");
}

int do_jingzuo()
{
   object ob;
   int c_exp,c_skill;
   ob = this_player();

   c_skill=(int)ob->query_skill("shayi", 1);
   if (c_skill <50)
   {
      message_vision("$N的杀意太低了，无法体会到更深的杀意。\n",ob);
      return 1; 
   }
   c_exp=ob->query("combat_exp");

   if ((c_skill*c_skill*c_skill/10)> c_exp)
   {
      message_vision("$N的实战经验不足，静坐了半天没有任何领悟。\n",ob);
      return 1; 
   }
   if (ob->query("jing")<50)
   {
      message_vision("$N太累了，在坐下去只怕要晕倒。\n",ob);
      return 1; 
   }
   if (c_skill>301)
   {
      message_vision("$N觉得静坐已对自己起不了什么作用了。\n",ob);
      return 1; 
   }

   message_vision("$N盘膝坐下,片刻过后对杀意有了些领悟。\n",ob);
   ob->improve_skill("shayi", random(2*ob->query("int")));
   ob->add("jing",-ob->query("eff_jing")/20);
   return 1;
}

