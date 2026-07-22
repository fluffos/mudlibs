inherit NPC;
#define SDS_D "/d/newguai/npc/sdsd"

void heart_beat()
{
object ob,me = this_object();
string str;
::heart_beat();
if ( !me || !me->is_fighting() || !living(me) || me->is_busy() )
        return;

if ( query("eff_kee") < query("max_kee") )
        SDS_D->addEffKee(me);
if ( query("kee") < query("eff_kee") )
        SDS_D->addKee(me);
if ( query("sen") < query("eff_sen") )
        SDS_D->addSen(me);
if ( query("eff_sen") < query("max_sen") )
        SDS_D->addEffSen(me);
if ( random(5)==1 )   {
ob = query_temp("weapon");
if ( !ob )
        {
        ob = new("/d/city/npc/obj/fork");
        if ( ob && ob->move(me) )
                {
                me->command("wield all");
                me->command("perform fengbo");
                ob->unequip();
                destruct(ob);
                me->reset_action();
                }
        }
else if ( ob->query("skill_type")!="fork" )
        {
        ob->unequip();
        destruct(ob);
        me->reset_action();
        ob = new("/d/city/npc/obj/fork");
        if ( ob && ob->move(me) )
                {
                me->command("wield all");
                me->command("perform fengbo");
                ob->unequip();
                destruct(ob);
                me->reset_action();
                }
        }
  }
                
if ( objectp(query_temp("weapon")) )
      str = query_temp("weapon")->query("skill_type");
else      str = "unarmed";
if ( random(3)==1 )
        SDS_D->randomPfm(this_object(),str);
}


