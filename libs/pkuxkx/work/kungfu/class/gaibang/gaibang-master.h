//modify by gudu 2002.9.13
//modified by Zine 2011-5-23

#include <command.h>

void heal()
{
        object ob=this_object();
        
        if (ob->query("bihua"))
                return;
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("exert lifeheal");
                return;
        }
        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                ob->set("water",ob->max_water_capacity() );
                ob->set("food",ob->max_food_capacity() );
                return;
        }
        if (ob->query("jing") < ob->query("eff_jing"))
                command("exert regenerate");
        return;
}

void combat_heal()
{
        object ob = this_object();
        
        if(ob->query("qi") < ( ob->query("eff_qi") * 2/3 ) )
                command("exert recover"); 
        return;
}

int accept_object(object ob, object obj)
{
        object me = this_object();
        object shengdairoom;


        mapping my_fam  = me->query("family");
        mapping ob_fam  = ob->query("family");
        int n;
        n=ob->query("dai");

        if((obj->query("id") == "qingzhu ling")
        && ((string)ob->query("family/family_name")== "丐帮"))
        {       
            if ((int)ob->query("score")<n*100)
             {
               command("say "+"好小子，杀害帮中同门盗得帮中升袋信物青竹令还敢来诳我，受死吧.");
               
               call_out("kill_ob", 0, this_player());
               return 0;
             }
            if (ob->query("combat_exp")<(2000+500*(n-1))*n*n)
             {
               command("say "+RANK_D->query_respect(ob)+"经验不够，那里来的青竹令");
               command("say "+"好小子，杀害帮中同门盗得帮中升袋信物青竹令还敢来诳我，受死吧.");
               call_out("kill_ob", 0, this_player());
               return 0;
             }
             if (ob->query("dai") == me->query("dai"))
             {
                ob->set_temp("fight_ok_" + n,1);
                command("say 好，既然已得到简长老许可，我们就到升袋室去验证一下武功。");
                command("drop all");
				message_vision("旁边的一个丐帮弟子走过来说：升袋室里已经预备了兵器装备，你的物品由我暂时保管，你从升袋室出来后再给你。\n",me);
                shengdairoom = new("/d/gaibang/shengdai-room");
                call_out("move_to",1,ob,shengdairoom);
                message_vision(me->query("name") + "说着转身向丐帮升袋室走去，$N也赶紧追了上去，跟在后面。\n",ob);
                me->move(shengdairoom);
                message( "channel:" + "chat",HIY + "【江湖公告】" + ob->query("title") + ob->query("name") + 
                "现在开始挑战" + me->query("title") + me->query("name") + "升袋！\n" + NOR, users() );
                remove_call_out("destroying");
                call_out("destroying", 1, me, obj);
                return 1;
             }
             else
             {
                command("say "+ RANK_D->query_respect(ob) +"袋位不对，我们不能比划。");
                return 1;
             }
        }
        command("smile");
        command("say 这东西给我可没有什麽用。");
        command("give " + obj->query("id") + " to " + me->query("id"));
        return 0;

}
void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
void move_to(object ob,object room)
{
		int i;
		object *inv;
		object temproom;

		if (!objectp(ob))
                return;
        inv = all_inventory(ob);
		temproom = new(VOID_OB);
		temproom->set("no_clean_up",1);
		temproom->set("no_reset",1);
		ob->set_temp("shengdai/temproom",temproom);
        for(i=0; i<sizeof(inv); i++) {
			inv[i]->move(temproom);
		}
        ob->move(room);
        return;
}
        
int accept_fight(object ob)
{
        object me,obj,weapon,armor;
        int dai;

        me=this_object();
        dai = me->query("dai");
        if (!me->is_fighting())//add by zine,会有不删除bihua,一直无法fight的状况，checking 里ob不在场直接return 1，但是那里不能删记号，不然可能出现ob再出现2打1的状况。
        {
            me->delete("bihua");
        }
        if ( !ob->query_temp("fight_ok_" + dai) ) return 0;
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi",     me->query("max_qi"));
        me->set("jing",   me->query("max_jing"));
        me->set("neili",  me->query("max_neili"));
        if (!objectp(armor = me->query_temp("armor/cloth")))
        {
                armor = new("/clone/armor/tiejia");
                armor->move(me);
                command("wear armor");
        }
        if (me->query_skill_mapped("blade") == "liuhe-dao")
        {
                if (!me->query_temp("weapon"))
                {
                        weapon = new("/clone/weapon/gangdao");
                        weapon->move(me);
                        command("wield blade");
                }
                if (!me->query_temp("secondary_weapon"))
                {
                        weapon = new("/clone/weapon/gangdao");
                        weapon->move(me);
                        command("wield blade");
                }
        }               
        remove_call_out("checking");
        call_out("checking", 1, me, ob);

        me->set("bihua",1);
        return 1;
}

int checking(object me, object ob)
{

        object obj;
        int my_max_qi, his_max_qi;

        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");

        if (me->is_fighting())
        {
                call_out("checking",2, me, ob);
                return 1;
        }

        if ( !present(ob, environment()) ) return 1;

        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 )
        {
                command("say 看来" + RANK_D->query_respect(ob) +
                        "还得多加练习，方能在本帮诸多弟子中出人头地 !\n");
                me->delete("bihua");
                return 1;
        }

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 )
        {
                command("say 青出於蓝胜於蓝，不愧是丐帮的佳弟子 ! 恭喜你了 !\n");
                message( "channel:" + "chat",HIY + "【江湖公告】" + ob->query("title") + ob->query("name") +
                "战胜" + me->query("title") + me->query("name") + "，" + HIM + "成功升袋！\n" + NOR, users() );
                message_vision("$N交给$n一个青竹令。\n", me, ob);
                ob->set_temp("have_win",1);
                obj=new("/d/gaibang/obj/qingzhu-ling2");
                obj->move(ob);
                me->delete("bihua");
                return 1;
        }
        me->delete("bihua");
        return 1;
}

