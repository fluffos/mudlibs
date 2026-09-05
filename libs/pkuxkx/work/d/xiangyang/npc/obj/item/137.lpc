// book0.c

inherit ITEM;
int do_study(string arj);

void create()
{
set_name("洗髓经",({"book","shu","jing"}));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
set("long", "这就是与易筋经并称少林二宝的洗髓经,
由于书是梵文所著，所以少有人读懂. \n");
                 set("value", 10000);
 set("material","paper");
	}
setup();
}

void init()
{
add_action("do_study","study");
}

int do_study(string arg)
    {
        object me;
me = this_player();
if(arg == "book")
{
if( (int)me->query_skill("fanwen",1)<1)
    {
            write("你不懂梵文,无法领悟上面的东西. \n");
               return 1;
}
if((int)me->query("jing")>40)
{
me->add("jing",-40);
if( (int)me->query_skill("force",1) < 100)
{
write("你的内力修为太差了，对书上的心法无法理解.\n");
return 1;
}
if( (int)me->query_skill("force",1) < 180)
{
 message_vision("$N正专心研读洗髓经. \n", me);
me->improve_skill("force", (int)me->query_skill("fanwen",1)/5+1);
write("你对洗髓经研读了一会,似乎有些心得, \n");
}
else
{
write("你对洗髓经琢磨了一会，发现上面的太过浅薄,
对你来说已毫无意义了.  \n");
}
}
else 
{
  write("你现在有些疲倦，无法专心下来研读新知. \n");
}
}
 return 1;
}
