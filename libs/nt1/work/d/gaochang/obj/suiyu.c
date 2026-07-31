// book4.c
inherit ITEM;

void create()
{
    set_name("碎了的玉简", ({ "suiyu", "yu"}));
    set_weight(500);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "块");
        set("long",
           "这是一块碎了的玉简。\n");
        set("value", 500);
        set("material", "stone");
        set("no_get",1);
		setup ();
    }
}
void init()
{
        add_action("do_study", "study");
}


int do_study(string arg)
{
        object me;
        int    jing_cost;
		int leiting;
        me = this_player();

        if (!me->query_temp("break_suiyu"))
		       return notify_fail("你要读什么？");
		
		if ( !arg || ( arg != "suiyu" ) )
                return notify_fail("你要读什么？");

        if ( (int)me->query_skill("literate", 1) < 1){
                write("你是个文盲，先学点文化(literate)吧。\n");
                return 1;
        }

        if ( (int)me->query_int() < 55){
                write("你的悟性不够，先学点文化(literate)吧。\n");
                return 1;
        }
        leiting = me->query_skill("leiting-axe", 1);
        if( (int)me->query("combat_exp") < (int)leiting*leiting*leiting/20 ) {
                write("你的实战经验不足，再怎么读也没用。\n");
                return 1;
		}
        jing_cost = me->query("max_jing")/5;
        if((int)me->query("jing") < jing_cost){
                write("你看了看地上的碎玉，似乎悟出了一些东西。\n");
                return 1;
        }
        me->receive_damage("jing", jing_cost );
        me->delete_temp("stone_learned");

        message_vision("$N正专心研读地上的碎玉。\n", me);
        
        write("你对着碎玉琢磨了一回儿，似有所悟。\n");
        if ( (int)me->query_skill("leiting-axe", 1) >= (int)me->query_skill("axe",1) ) return 1;

        if ( (int)me->query_skill("leiting-axe", 1) < 450 && random(10)>3 ){
                        me->improve_skill("leiting-axe", me->query_int());
                        me->set_temp("stone_learned",1);
                }
        return 1;
}

