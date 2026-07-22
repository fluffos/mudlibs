void init()
{
        object me,ob;
        me=this_object();
        ob=this_player();
       
        ::init();
       
        if(ob->query_condition("no_pk_time"))
          {
                message_vision("杀了人还敢到处乱跑不想活了。”，$N一脚把$n踢了出去。\n",me,ob);
                ob->move("/d/obj/qlj/room/dao");
                message_vision("$N被人踢了过来倒在地。\n",ob);
                ob->start_busy(5);
          }
           
       else if( interactive(ob) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
             
        }
        add_action("do_perform", "perform");
        add_action("do_ji", "ji");
        add_action("do_throw","throw");
}
int do_perform(string arg)
{
        object who = this_player();
        object me = this_object();
        message_vision("$N脸色不大对，好象动了杀机！\n", who);
        message_vision ("$N对$n摇了摇头。\n", me, who);  
        return 1;
}   
int do_ji(string arg)
{
        object who = this_player();
        object me = this_object();
        message_vision("$N偷偷把手伸进怀里，想用什么法宝！\n", who);
        message_vision ("$N对$n摇了摇头。\n", me, who);  
        return 1;
}
int do_throw(string arg)
{
  object who = this_player();
  object me = this_object();
  message_vision("$N掏出暗器，向$n射去。\n",who,me);
  return 1;
}

void die ()
{
  object me = this_object();
  message_vision ("\n$N大喝一声，又恢复了体力。\n",me);
  set("kee", 30000);
  set("sen", 30000);
  set("eff_kee", 30000);
  set("eff_sen", 30000);
  set("max_kee",30000);
  set("max_sen",30000);
  set("max_mana", 30000);
  set("max_force", 30000);
  set("force", 80000);
  set("mana", 80000);
  set("combat_exp",99999999);
}
