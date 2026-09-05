#include <ansi.h>
inherit ITEM;
void init()
{
        add_action("do_read", "du");
	add_action("do_read","read");
}

void create()
{
        set_name( HIC"道德经"NOR, ({ "shu", "book" }));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一册道德经。\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name": "daoxue-xinfa", // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost": 20+random(20),// jing cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                        "max_skill":    100     // the maximum level you can learn
                ]) );
        }
}

int do_read(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        mapping skill;
        int pxlevel; 
	int neili_lost;

	if (!(arg=="shu" || arg == "book"))	return 0;

        if (where->query("pigging")){
                write("你还是专心拱猪吧！\n");
                return 1;
        }
        if (me->is_busy()) {
                write("你现在正忙着呢。\n");
                return 1;
        }

        if( me->is_fighting() ) {
                write("你无法在战斗中专心下来研读新知！\n");
                return 1;
        }

        if (!id(arg)) {	
                write("你要读什么？\n");
                return 1;
        }
         if( !me->query_skill("literate", 1) ){
                write("你是个文盲，先学点文化(literate)吧。\n");
                return 1;
        }

        switch(random(3)) {
          case 0:
          if(me->query("attitude")=="aggressive")
          {
 			tell_object(me,"你静心阅读书中的文字，似乎觉得心智有点清晰。\n");
			me->add_temp("cuer_crazy",1);
            if( (int)me->query_temp("cuer_crazy") > random(3000) )
			{
				tell_object(me,HIR "你终于战胜了心魔，心智完全恢复了！\n" NOR);
				me->set("attitude","peaceful");
				me->delete_temp("cuer_crazy");
				me->unconcious();
        	}
        	}
        
 	}
 //	me->improve_skill("daoxue-xinfa", (int)me->query_skill("literate", 1)/3+1);

		return 1;
}        