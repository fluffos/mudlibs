// yunu-xinjing2.c

#include <skill.h>
#include <ansi.h>

inherit ITEM;

void create()
{

        set_name(GRN "玉女心经「下」" NOR, ({ "yunu xinjing", "xinjing" }));
        set_weight(200);
        set("unit", "本");
        set("long", "这是一册玉女心经「下」，记着古墓的内功心法。\n");
        set("value", 500);
        set("material", "paper");
        set("skill", ([
                        "name": "yunu-xinjing",          // name of the skill
                        "exp_required": 10000,  	// minimum combat experience required
                        "jing_cost": 20+random(20),	// jing cost every time study this skill
                        "difficulty":   25,     	// the base int to learn this skill
                        "max_skill":    99      // the maximum level you can learn
        ]) );
}
void init()
{
add_action("do_study","study");
add_action("do_study","du");
}
   int do_study(string arg, object me, int my_level)
    {
me = this_player();
         my_level=me->query_skill("yunu-xinfa",1);
    if (arg != "xinjing")
{
        return notify_fail("你要读什么？\n");
}
if ( (int)me->query_skill("literate", 1) < 50)
        {
                write("你看了半天，还是看不出头绪，只隐隐觉的好象自己读书写字水平不够。\n");
                return 1;
        }
 if ( (int)me->query_skill("yunu-xinfa", 1) < 50)
        {
                write("你看了半天，觉得很难理会其中含义，也许是你的玉女心经等级不够。\n");
                return 1;
        }
if ((int)(my_level*my_level*my_level/10)>(int)me->query("combat_exp"))
      {
printf("也许是缺乏实战经验，你对玉女心经上面所说的东西总是无法领会。\n");
        return 1;
   }

if((int)me->query("jing")>50)
{
me->add("jing",-40);
 if ( (int)me->query_skill("yunu-xinfa", 1) < 100)
{
write("你正专心研读玉女心经下册. \n", me);
 me->improve_skill("yunu-xinfa", (int)(((int)me->query_skill("literate",1)+(int)me->query_skill("yunu-xinfa"))/10+(int)me->query("int")/7));
write("你对玉女心法似乎有了更新的理解, \n");
}
else
{
write("你对玉女心经下册研读了一会，发现上面的对你来说已经太浅了。\n");
}
}
else 
{
  write("你现在有些疲倦，无法专心下来研读新知. \n");
}
 return 1;

}
