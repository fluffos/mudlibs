#include <ansi.h>;
void init()

{        object ob,me,what;

        ::init();

        ob = this_player();

        me = this_object();

        if( living(ob) && !is_fighting() && living(me) && !is_fighting(ob)
        && !ob->query_temp("no_kill"))
        {

                if( 1 )

                        {


if (userp(ob) && ob->query("combat_exp") > 1800000
&& ob->query("family/family_name")!= me->query("family/family_name"))
{
ob->start_busy(2);
command("hit "+ob->query("id"));
                                me->fight_ob(ob);
                                ob->fight_ob(me);
                                fight_ob(ob);
                                ob->fight(me);
me->start_busy(1);
if (random(3)==0)
                                say(HIR+me->query("name")+

                                "嘿嘿冷笑了几声：奉掌门之命，让你们"+me->query("hated")+"的人从此在江湖上消失。\n我看"+ob->query("name")+"还是乖乖的束手就擒吧!\n\n"NOR);
}
else if (!ob->query_temp("no_kill")
&& !userp(ob)
&& !ob->query("hated")
&&  ob->query("id")!="renwu shi"
)
{
ob->start_busy(2);
command("kill "+ob->query("id"));
                                me->kill_ob(ob);
                                ob->fight_ob(me);
                                kill_ob(ob);
                                ob->fight(me);
me->start_busy(1);
if (random(3)==0)
                                say(HIR+me->query("name")+

                                "嘿嘿冷笑了几声：奉掌门之命，让你们"+me->query("hated")+"的人从此在江湖上消失。\n我看"+ob->query("name")+"还是乖乖的束手就擒吧!\n\n"NOR);
}
                        }else{

                remove_call_out("greeting");

                call_out("greeting",1,ob,me);

                }

        }

        if(!me->query("have_init")){

                me->set("have_init",1);

                call_out("dest_me",480,me);

        }

}

void greeting(object ob,object me)

{

        if( !ob || environment(ob) != environment() ) return;

        switch( random(5) ) {

                case 0:

                        say(me->query("name")+"恶狠狠的说到：杀啊，一个活口也不要留!!\n");

                        break;



        }

}

void dest_me(object me)

{

        if( living(me) && !is_fighting(me))

        {

                say(HIR+me->query("name")+

                                "忽然纵声高叫道：这次先放过你们，下次再决个高低。\n说罢一个转身，消失的无影无踪。\n"NOR);

                destruct(me);

        }else{

        remove_call_out("dest_me");

        call_out("dest_me",5,me);

        }

}