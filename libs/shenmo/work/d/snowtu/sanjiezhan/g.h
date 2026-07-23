#include <ansi.h>

int player_number;

void check_place(object env,object who);
int check_success(object who);

void alternative_die(object me)
{
int pot,wx,dx;
string msg;
object ob;

if ( !userp(me) )
        return;
me->remove_all_killer();
all_inventory(environment(me))->remove_killer(me);
SDS_D->powerup(me);
if ( check_success(me) )
	{
	message_vision("$N决定退出比赛。\n",me);
	SDS_D->powerup(me);
	msg = HIC" %s(%s) 历经苦战，赢得了"NOR+this_object()->query("short")+HIC"的胜利。\n"NOR;
	msg = sprintf(msg,me->query("name"),capitalize(me->query("id")) );
	message("channel:chat",WHT"【"NOR HIY"三界战"NOR WHT"】"NOR+msg,users());
	pot = me->query_temp("sanjiezhan_win");         //取得此人战胜者的数量
	if ( pot<1 )
		pot = 1;
        wx = me->query("combat_exp");
        wx/= 1000000;
        if ( wx<1 )
                wx = 1;
        wx*= (pot*1000);
        wx = wx/2+random(wx);
        dx = wx/10;
        if ( dx<100 )
                dx = 100;
        pot = wx/100;
        if ( pot<100 )
                pot = 100;
        msg+= sprintf( HIC"特奖励"HIY" %d "HIC"点武学，%s "HIC"道行，"HIY" %d "HIC"点潜能。\n"NOR,
                         wx,COMBAT_D->chinese_daoxing(dx),pot );
        me->add("combat_exp",wx);
        me->add("daoxing",dx);
        me->add("potential",pot);
        tell_object(me,BLINK+HIY"你得到了 "+wx+" 点武学经验, "+COMBAT_D->chinese_daoxing(dx)+BLINK HIY" 道行和 "+pot+" 点潜能。\n"NOR);
        message("channel:chat",WHT"【"NOR HIY"三界战"NOR WHT"】"NOR+msg,users() );
        me->set("sanjiezhan_lost",time());
        me->add("sanjiezhan_win",1);
        me->delete_temp("sanjiezhan");
	me->delete_temp("sanjiezhan_win");
        me->save();
        if ( objectp(me->query_temp("sanjie_place")) )
        	me->move(me->query_temp("sanjie_place"));
        else	me->move("/d/city/under");
        me->delete_temp("sanjie_place");
        message_vision("$N赢得了比赛，高高兴兴的下场了。\n",me);
	return;
	}

message_vision("$N死了。\n",me);

me->set("kee", 1);
me->set("sen", 1);
me->set("eff_kee",me->query("max_kee"));
me->set("eff_sen",me->query("max_sen"));

ob = me->query_temp("last_damage_from");

if ( !ob )
        msg = HIC" %s(%s) 中途受伤，退出了"NOR+this_object()->query("short")+HIC"。\n"NOR;
else    msg = HIC" %s(%s) 受到 "+ob->name()+"("+capitalize(ob->query("id"))+") 的攻击，退出了"+this_object()->query("short")+HIC"。\n"NOR;
message("channel:chat",sprintf(WHT"【"NOR HIY"三界战"NOR WHT"】"NOR+msg,me->query("name"),capitalize(me->query("id")) ),users());

if ( ob )
        {
        if ( query_ip_number(me)==query_ip_number(ob) )
                {
                msg = HIC" %s(%s) 涉嫌使用大米赚取比赛分值，扣去一点比赛分值。\n"NOR;
                message("channel:chat",sprintf(WHT"【"NOR HIY"三界战"NOR WHT"】"NOR+msg,
                                        ob->query("name"),
                                        capitalize(ob->query("id"))
                        ),users());
                ob->add_temp("sanjiezhan_win",-1);
                tell_object(ob,BLINK HIY"你的比赛分值减少了一点\n"NOR);
                }
        else    ob->add_temp("sanjiezhan_win",1);
        tell_object(ob,HIR"你杀死了一名对手，你的目前的比赛分值为 "HIG+me->query_temp("sanjiezhan_win")+HIR" 。\n");
        }

pot = me->query_temp("sanjiezhan_win");         //取得此人战胜者的数量
if ( pot<1 )
        {
        msg = HIC"此轮比赛 %s(%s) 攻无建树，没有奖励。\n"NOR;
        msg = sprintf(msg,me->query("name"),capitalize(me->query("id")) );
        }
else    {
        msg = HIC"此轮比赛 %s(%s) 共杀敌 "HIY+chinese_number(pot)+HIC" "NOR;
        msg = sprintf(msg,me->query("name"),capitalize(me->query("id")) );
        wx = me->query("combat_exp");
        wx/= 1000000;
        if ( wx<1 )
                wx = 1;
        wx*= (pot*1000);
        wx = wx/2+random(wx/2);
        dx = wx/10;
        if ( dx<100 )
                dx = 100;
        pot = wx/200;
        if ( pot<1 )
                pot = 1;
        msg+= sprintf( HIC"特奖励"HIY" %d "HIC"点武学，%s "HIC"道行，"HIY" %d "HIC"点潜能。\n"NOR,
                         wx,COMBAT_D->chinese_daoxing(dx),pot );
        me->add("combat_exp",wx);
        me->add("daoxing",dx);
        me->add("potential",pot);
        tell_object(me,BLINK+HIY"你得到了 "+wx+" 点武学经验, "+COMBAT_D->chinese_daoxing(dx)+BLINK HIY" 道行和 "+pot+" 点潜能。\n"NOR);
        me->save();
        }
message("channel:chat",WHT"【"NOR HIY"三界战"NOR WHT"】"NOR+msg,users() );
if ( me->move("/d/city/kezhan") )
        {
        me->clear_condition();
        me->set("sanjiezhan_lost",time());	//下场时间
        me->set("sanjiezhan_die",time());	//失败时间
        message_vision("$N输掉了比赛，灰溜溜的退了出来。\n",me);
        }
else	error(sprintf("%O 出不了赛场?!\n",me));
me->delete_temp("sanjiezhan");
me->delete_temp("sanjiezhan_win");
}

void init()
{
object *inv;
int i;
::init();
if ( userp(this_player()) )
        {
        add_action("do_none","",1);
        add_action("do_pfm","perform");
        add_action("do_kill","kill");
        add_action("do_kill","fight");
        add_action("do_quit","quit");
        }
inv = all_inventory();
for(i=0;i<sizeof(inv);i++)
	{
	if ( inv[i]==this_player()
	  || !userp(inv[i]) )
		continue;
	message_vision(HIW"$N"HIW"和$n"HIW"一碰面，二话不说就打了起来！\n"NOR,inv[i],this_player());
	inv[i]->kill_ob(this_player());
	message_vision(HIW"$N"HIW"喝道：「$n"HIW"，看招！」\n"NOR,this_player(),inv[i]);
	this_player()->kill_ob(inv[i]);
	}
}

int do_none()
{
object me = this_player();
string verb = query_verb();
string *no_cmds = ({
        "gongji","ji","apply","steal","whisper","bian","surrender",
        "cast chuqiao",                 //all
        "cast yinshen",                 //bonze
        "cast shuidun",                 //dragon
        "cast huimeng",                 //moon
        "cast escape","cast chongsheng",//emei swordman
        "burn",                         //jjf
        "cast townportal",              //hell
        "cast yin",                     //gumu
        "cast arrest","cast drift","cast taijitu",
                                        //kunlun ... so BT..
        "cast mysticism",               //sanxian
        "cast jieti",                   //xueshan
        "cast tuoqiao",                 //shushan
        "cast bagua",                   //youxia
        "cast qimen","cast qiankun",    //wzg
        "cast tudun",                   //wdd
});
if ( member_array(verb,no_cmds)!=-1 )
        {
        tell_object(me,"这个命令在此处不能使用。\n");
        return 1;
        }
return 0;
}

int do_pfm()
{
object me = this_player();
if ( time()<me->query_temp("sanjiezhan_pfm")+5 )
        {
        tell_object(me,"频繁使用绝招，小心身体。\n");
        return 1;
        }
me->set_temp("sanjiezhan_pfm",time());
return 0;
}

int do_kill(string arg)
{
object who,me = this_player();
if ( !who=present(arg) )
    {
    tell_object(me,"这里没有这个人。\n");
    return 1;
    }
if ( me->is_fighting(who) )
    {
    tell_object(me,"加油加油。\n");
    return 1;
    }
me->kill_ob(who);
who->kill_ob(me);
return 1;
}

int do_quit()
{
object me = this_player();
if ( !valid_move(me) )
   {
   tell_object(me,"你现在正忙着呢。\n");
   return 1;
   }
me->delete_temp("last_damage_from");
me->die();
return 1;
}

void broadcast(string str)
{
string prefix = this_object()->query("short")+"\t";
string s1 = str, s2 = "";
while (strsrch(s1,"\n\n") != -1)
        s1 = replace_string(s1,"\n\n","\n");

if (s1[strlen(s1)-1]=='\n')
        {
        s1 = s1[0..strlen(s1)-2];
        s2 = "\n";
        }
if (strlen(s1) == 0)
        return;
s1 = replace_string(s1,"\n","\n"+prefix)+"";
reset_eval_cost();
tell_room("/d/city/under","\n"+prefix+s1+"\n" );
}

int check_success(object who)
{
int i,k,num=0;
object *inv,room;
string msg = HIR"\n搜索目前赛事：\n"NOR;

if ( !who )
        return 0;
player_number = 0;
for(i=1;i<5;i++) //i = 1..5
	{
	who->move(__DIR__"ground"+sprintf("%d",i));
	if ( !objectp(room=environment(who)) )
		error("no this room\n");
	inv = all_inventory(room);
	msg+= sprintf(HIY"\t\t 地点 : %s "HIY">>> "NOR,room->query("short"));
	inv = all_inventory(room);
	for(k=0;k<sizeof(inv);k++)
		{
		if ( !userp(inv[k]) || inv[k]==who )
			continue;
		else	player_number++;
		}
	msg+= sprintf(HIY">>> 生命存在 %d >>>"NOR,player_number);
	if ( player_number>0 )
		msg+= HIY">>> 结果：比赛失败！\n"NOR;
	else	{
		msg+= HIY">>> 结果：赛区通过！\n"NOR;
		num = 1;
		}
	}
write(msg);
return num;
}
