// identifier.c
#include <ansi.h>
inherit NPC;
string ask_pu();
int ask_tiaozhan();
int ask_cancel();
int ask_finish();
mapping all_effect = ([
       "armor":"防御力",
       "armor_effect_armor_vs_force":"降伤害",
       "armor_effect_healup":"恢  复",
       "armor_effect_poison":"淬  毒",
       "armor_effect_rebound":"回  伤",
       "attack":"攻击力",
       "claw":"爪  法",
       "cuff":"拳  法",
       "damage":"伤害力",
       "dodge":"躲  闪",
       "finger":"指  法",
       "hand":"手  法",
       "magic":"魔法值",
       "parry":"防御力",
       "strength":"膂  力",
       "strike":"掌  法",
       "unarmed":"拳  脚",
       "weapon_effect_jing":"吸精神",
       "weapon_effect_poison":"淬  毒",
       "weapon_effect_suck":"吸  血"]);

void create()
{
	set_name("百晓生", ({ "bai xiaosheng", "bai" }) );
	set("gender", "男性" );
	set("age", 48);
	set("long", 
"百晓生乃是江湖奇书《江湖兵器谱》的作者，他对于兵器防具的研究天下闻名，他也正是依靠此艺为生。\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 15);
	set("shen_type", -1);
	set("chat_chance", 30);
	set("chat_msg", ({
		"百晓生说道: 鉴定天下兵器防具，粗鉴一次二两黄金，细鉴一次十两黄金。\n",
	}) );
  set_skill("unarmed", 30);
	set_skill("dodge", 25);
  set_temp("apply/attack", 25);
  set_temp("apply/defense", 25);
  set("combat_exp", 2500);

	set("attitude", "peaceful");
        set("inquiry", ([
		"鉴定" : "不是我百晓生吹牛，兵器鉴定，我要自认第二，天下无人敢说第一！不信你随便那件东西来我看看！\n",
		"粗鉴" : "所谓粗鉴就是只鉴定兵器防具有哪些功能，而不细查其效力。\n",
		"细鉴" : "细鉴就是告诉你兵器防具的所有功能和其效力，甚是耗费精力，收费当然也高。\n",
		"鉴定之术" : "想学习鉴定之术可先从兵器谱上学习50级，之后就要通过我的挑战才能提高。\n",
		"兵器谱":(: ask_pu :),
		"挑战":(: ask_tiaozhan :),
		"cancel":(: ask_cancel :),
		"finish":(: ask_finish :),
        ]) );
   set("pu_count",random(6)-4);

	setup();
//        if (!"/clone/book/bingqipu"->in_mud())
//	carry_object("/clone/book/bingqipu");
}

string ask_pu()
{
        object ob,me;
        me = this_player();
        if(!me->query("ludingshan"))
                return "你还没解开鹿鼎山的秘密，给你兵器谱有屁用啊！";
  
        if (query("pu_count") < 1)
        return "你来晚了，兵器谱被个混球拿走拉。";
        add("pu_count", -1);
        ob = new("clone/book/bingqipu");
        ob->move(this_player());
        return RANK_D->query_respect(this_player()) + "武功盖世，此兵器谱就赠与你吧!";
}


int accept_object(object me, object ob)
{
		int source,i;
		string temp;
		mapping prop;
		source = 0;
		if (ob->query("money_id"))
		{
			me->add_temp("id_price",ob->value());
			message_vision("百晓生满脸堆笑：不知这位" + RANK_D->query_respect(me) + "有什么需要在下鉴定的，尽管拿给我瞧瞧。\n",me);
			return 1;
		}
        if(!ob->is_gems()||(!ob->query("weapon_prop") && !ob->query("armor_prop")))
        {
        	message_vision("百晓生愤然作色道：这种东西还需要鉴定么？\n",me);
        	return 0;
        }
        this_object()->start_busy(2);
        if (me->query_temp("id_price") >= 100000)
        {
        	source = 2; //细鉴
            me->add_temp("id_price",-100000);       	
        	message_vision("百晓生说道：这位" + RANK_D->query_respect(me) + "出手如此阔绰，在下定会施展平生之所学为你仔细鉴定此宝！。\n",me);
        } else if (me->query_temp("id_price") >= 20000)
        {
        	source = 1; //粗鉴
            me->add_temp("id_price",-20000);       	
        	message_vision("百晓生漫不经心地说道：哦，且让我看看这是个什么东西。\n",me);
        } else
        {
        	message_vision("百晓生愕然道：我平白无故为什么要为你鉴定？让我鉴定一次至少二两黄金呢！你兹到不？\n",me);
        	return 0;
        }
      	if (source == 1)
        	message_vision("百晓生捧着$n上上下下仔仔细细的打量了一遍。\n",me,ob);
        else message_vision("百晓生捧着$n上上下下仔仔细细的打量了一遍，又掏出怀中的兵器谱反复对照一番。\n",me,ob);
        temp = "百晓生告诉你：\n";
        if(ob->query("weapon_prop"))
        {//武器类
                temp+= CYN"=========="NOR+ob->query("name")+NOR+"("+ob->query("id")+")"+CYN"==========\n"NOR;
                temp+= HIY"★"NOR+MAG"基本属性：\n"NOR;
                temp+= "      凹  槽:"+HIC+ob->query("sockets/max")+"("+ob->query("sockets/filled")+")\n"+NOR;
                temp+= "      耐久度:"+HIC+ob->query("rigidity")+"\n"NOR;
                temp+= "\n"+HIY"★"NOR+MAG"其他属性：\n"NOR;
                prop=ob->query("weapon_prop");
                for (i=0;i<sizeof(prop);i++)
                {
	                if (source == 2)
                        temp+="      " + all_effect[keys(prop)[i]] + ":" + HIC + values(prop)[i] + "\n" + NOR;
                    else temp+="      " + all_effect[keys(prop)[i]] + ":" + HIC + "有\n" + NOR;
                }
        }
        if(ob->query("armor_prop"))
        {//盔甲类
                temp+= CYN"=========="NOR+ob->query("name")+NOR+"("+ob->query("id")+")"+CYN"==========\n"NOR;
                temp+= HIY"★"NOR+MAG"基本属性：\n"NOR;
                temp+= "      凹  槽:"+HIC+ob->query("sockets/max")+"("+ob->query("sockets/filled")+")\n"+NOR;
                temp+= "\n"+HIY"★"NOR+MAG"附加属性：\n"NOR;            
                prop=ob->query("armor_prop");
                for (i=0;i<sizeof(prop);i++)
                {
	                if (source == 2)
                        temp+="      " + all_effect[keys(prop)[i]] + ":" + HIC + values(prop)[i] + "\n" + NOR;
                    else temp+="      " + all_effect[keys(prop)[i]] + ":" + HIC + "有\n" + NOR;
                }
        }        
        tell_object(me,temp);
        call_out("giveback",0,ob,me);
        return 1;

}	

int giveback(object ob,object me)
{
        ob->move(me);
        message_vision("百晓生把" + ob->name() + "还给了" + me->name() + "。\n",me);
		return 1;
}

int ask_tiaozhan()
{
	
	    object me = this_player();
	    object ob=this_object();
	    
	    int ydexp, mrexp, xfexp, hbexp;
	    
	    ydexp = ((int)me->query("yidao/times"));
	    mrexp = ((int)me->query("exp/murong"));
	    xfexp = ((int)me->query("exp/xiaofeng"));
	    hbexp = ((int)me->query("exp/hubiao"));
	    
	    if ( me->query("combat_exp") < 3000000 )
	     	{
         message_vision("$N笑道：你经验太低了，根本完成不了我的挑战。\n",ob);
         return 1;
        }
      
      if (me->query("baixiaosheng/tiaozhan"))
      	{
         message_vision("$N说道：挑战已经开始了，还不快去做？\n",ob);
         return 1;
        }
      
      if (me->query("yidao/on_job"))
      	{
         message_vision("$N说道：胡一刀大侠交给你的任务完成了吗？搞定再说吧。\n",ob);
         return 1;
        }
      
      if (me->query("in_dart"))
      	{
         message_vision("$N说道：林镇南大侠交给你的任务完成了吗？搞定再说吧。\n",ob);
         return 1;
        }
      
      if (me->query("murong/yuxi"))
      	{
         message_vision("$N说道：慕容复大侠交给你的任务完成了吗？搞定再说吧。\n",ob);
         return 1;
        }
      
      if(me->query("xiaofeng/on_job"))
      	{
         message_vision("$N说道：萧峰大侠交给你的任务完成了吗？搞定再说吧。\n",ob);
         return 1;
        }
      if(!wizardp(me) && time() - me->query("baixiaosheng/tz_time") < 600)
	      {
		     message_vision("$N说道：歇会，等等再要吧。\n",ob);
		     return 1;
	      }
	      
	    me->set("baixiaosheng/tiaozhan",1);
	    me->set("baixiaosheng/tz_time",time());
	    me->set("baixiaosheng/yd_exp",ydexp);
	    me->set("baixiaosheng/xf_exp",xfexp);
	    me->set("baixiaosheng/mr_exp",mrexp);
	    me->set("baixiaosheng/hb_exp",hbexp);
      
      message_vision("$N说道：好，既然大侠武功盖世，想接受挑战，那就请在8分钟之内完成慕容，萧峰，胡一刀，护镖任务各一次吧。现在开始，马上行动！\n",ob);
      return 1;

} 

int ask_cancel()
{
      object me = this_player();
	    object ob=this_object();
	    
	    if (!me->query("baixiaosheng/tiaozhan"))
      	{
         message_vision("$N说道：你啥也没要，取消个屁呀！\n",ob);
         return 1;
        } 
        
      message_vision("$N说道：完不成就算了，对你来说，是有点难度。\n",ob);
      me->delete("baixiaosheng/tiaozhan");
      return 1;   
}

int ask_finish()
{
	    object me = this_player();
	    object ob=this_object();
	    object obj;
	    string gem,msg;
	    
	    int sk,i,num;
	    sk = ((int)me->query_skill("identification",1));
	    
	    if (!me->query("baixiaosheng/tiaozhan"))
      	{
         message_vision("$N说道：你问我这个问题，心里不惭愧吗？\n",ob);
         return 1;
        } 
      
      if(time() - me->query("baixiaosheng/tz_time") > 600)
	      {
		     message_vision("$N说道：很可惜，你已经超时了，重新挑战吧。\n",ob);
		     me->delete("baixiaosheng/tiaozhan");
		     return 1;
	      }
	      
	    if( me->query("yidao/times") <= me->query("baixiaosheng/yd_exp"))
	    	{
		     message_vision("$N说道：很可惜，你没能够完成胡一刀任务，再来吧。\n",ob);
		     me->delete("baixiaosheng/tiaozhan");
		     return 1;
	      }
	    
	    if( me->query("exp/murong") <= me->query("baixiaosheng/mr_exp"))
	    	{
		     message_vision("$N说道：很可惜，你没能够完成慕容任务，再来吧。\n",ob);
		     me->delete("baixiaosheng/tiaozhan");
		     return 1;
	      }
	    
	    if( me->query("exp/xiaofeng") <= me->query("baixiaosheng/xf_exp"))
	    	{
		     message_vision("$N说道：很可惜，你没能够完成萧峰任务，再来吧。\n",ob);
		     me->delete("baixiaosheng/tiaozhan");
		     return 1;
	      }
	    
	    if( me->query("exp/hubiao") <= me->query("baixiaosheng/hb_exp"))
	    	{
		     message_vision("$N说道：很可惜，你没能够完成护镖任务，再来吧。\n",ob);
		     me->delete("baixiaosheng/tiaozhan");
		     return 1;
	      }
	      obj = new("/obj/gem/gem");
	      
	      i = random(20);
	      if (i < 3) gem = "yan";
        else if (i < 6) gem = "mu";
        else if (i < 9) gem = "sui";
        else if (i < 12) gem = "jin";
        else if (i < 15) gem = "bing";
        else if (i < 16) gem = "gu";
        else if (i < 17) gem = "yu";
        else if (i < 18) gem = "jiao";
        else gem = "jia";
        num = 10000 - random(200);   
	    obj->set_level(num,num,gem);    
	    obj->move(this_player());
	    message_vision("$N说道：大侠果然身手不凡，过挑战一次，我奖励你颗宝石，并教你一些鉴定技术吧。\n",ob);
	    write(HIC"\n你的「鉴定之术」进步了！\n"NOR);  
	    write("\n百晓生给你一颗"+obj->name()+"！\n");  
	    CHANNEL_D->do_channel(this_object(), "rumor", "听说" + me->name(1) +
                              "在百晓生任务中获得一颗"+obj->name()+"!");
	    msg = this_player()->name()+"在百晓生任务中得到一"+obj->query("unit")+obj->name()
  					   +"[等级："+obj->query("level")+"]。";   
  	  MONITOR_D->report_system_msg(msg);   
	    me->delete("baixiaosheng/tiaozhan");
	    me->set_skill("identification",sk+1);
	    return 1;      
}