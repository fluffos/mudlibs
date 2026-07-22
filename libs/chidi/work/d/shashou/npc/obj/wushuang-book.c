inherit ITEM;

string* titles = ({
        "无双剑谱",
});

void create()
{
        set_name(titles[random(sizeof(titles))], ({ "wushuang jianpu", "shu", "book" }));    
        set("long", "
无双剑法秘籍。
");
        set_weight(200);       
        
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本无双剑谱。\n");
                set("value", 500);
                set("material", "paper");
                set("no_drop",1);
                set("no_get",1);
                set("unique", 1);


        }
}
void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}    
int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        int dzlevel; 
        int neili_lost;
        if (!(arg=="wushuang jianpu" ||arg=="book" || arg=="shu"))
        return 0;

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

        if( (int)me->query("jing") < 15 ) {
                write("你现在过于疲倦，无法专心下来研读新知。\n");
                return 1;
        }
        if( (int)me->query("neili") < neili_lost) {
                write("你内力不够，无法钻研这么高深的武功。\n");
                return 1;
        }

               dzlevel = me->query_skill("wushuang-jian", 1);
        if( (int)me->query("combat_exp") < (int)dzlevel*dzlevel*dzlevel/10 ) {
                write("你的实战经验不足，再怎么读也没用。\n");
                return 1;
        }
    if ( me->query_skill("wushuang-jian", 1) > 200) {
        write("你已经无法从这本书里领悟到更高深的武功了。\n");
 	return 1;}
        if ( me->query_skill("wushuang-jian", 1) > 100) {
                neili_lost = 5;
                me->receive_damage("jing", 15);
                me->set("neili",(int)me->query("neili")-neili_lost);
                me->improve_skill("wushuang-jian", (int)me->query_skill("parry", 1)/3+1);
                write("你正在研习无双剑法的武功秘籍，似乎有点心得。\n");
                return 1;
        }
        else  write("你的无双剑法等级太低，领悟不到更高深的功夫。\n");

        return 1;
}
