// /u/beyond/mr/obj/shu1.c
// this is made by beyond
// update 1997.6.29

inherit ITEM;

string* titles = ({
	"斗转星移秘籍",
});

void create()
{
	set_name(titles[random(sizeof(titles))], ({ "douzhuan xingyi", "shu", "book" }));    
	set("long", "
斗转星移初级阶段研读此书即可。
");
	set_weight(200);       
	
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("value", 500);
		set("material", "paper");

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
        object ob;
        mapping skill;
        int dzlevel; 
        int neili_lost;
        if (!(arg=="douzhuan xingyi" ||arg=="book" || arg=="shu"))
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
	if (me->query_skill("douzhuan-xingyi",1)>(me->query_skill("parry",1)+10)){
		write("由于你的基本招架的火侯不够，不能再进行更高一层的提高。\n");
		return 1;
	}
if(me->query_skill("douzhuan-xingyi",1)>(me->query_skill("shenyuan-gong",1)+30)){
write("由于你的神元功火侯不够，不能再进行更高一层的提高。\n");
return 1;
}
if(me->query_skill("douzhuan-xingyi",1)>(me->query_skill("literate",1)+50)){
write("由于你的读书写字火侯不够，不能再进行更高一层的提高。\n");
return 1;
}
	if( (int)me->query("neili") < neili_lost) {
		write("你内力不够，无法钻研这么高深的武功。\n");
                return 1;
        }

        dzlevel = me->query_skill("douzhuan-xingyi", 1);
        if( (int)me->query("combat_exp") < (int)dzlevel*dzlevel*dzlevel/10 ) {
                write("你的实战经验不足，再怎么读也没用。\n");
                return 1;
        }
if ((int)me->query_skill("douzhuan-xingyi", 1) > 50 ){
           write("这本书对于你来说已经太肤浅了！\n");
return 1;
}
                 neili_lost = 5;
		me->receive_damage("jing", 15);
		me->set("neili",(int)me->query("neili")-neili_lost);
		me->improve_skill("douzhuan-xingyi", (int)me->query_skill("parry", 1)/3+1);
		write("你正在研习斗转星移的武功秘籍，似乎有点心得。\n");
		return 1;

}
