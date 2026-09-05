// book0.c

inherit ITEM;
int do_study(string arj);

void create()
{
     set_name("天竺梵语",({"shu","book"}));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
                set("long","这是一本薄薄的小册子,翻开一看，都是一些奇形怪状的文字. \n");
set("value", 200000);
 set("material","paper");
	}
setup();
}

void init()
{
add_action("do_study","study");
}

int do_study(string arj)
    {
        object me;
me = this_player();
if( (int)me->query_skill("fanwen",1)<1)
    {
            write("你不懂梵文,无法领悟上面的东西. \n");
               return 1;
}
 if((int)me->query("jing")>20)
{
    me->add("jing",-20);
if( (int)me->query_skill("fanwen",1) < 100)
{
 message_vision("$N正专心研读梵文. \n", me);
 me->improve_skill("fanwen", (int)me->query_skill("fanwen",1)/5+1);
write("你对天竺梵文琢磨了一会，似乎有些心得. \n");
}
else
{
write("你对天竺梵文研读了一会，发现上面的太过浅薄，?
对你来说已毫无意义了. \n");
}
}
else 
{
  write("你现在有些疲倦，无法专心下来研读新知. \n");
}
 return 1;
}
