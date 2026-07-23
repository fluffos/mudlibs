int update(object obj)
{
int i;
object *inv;
inv = all_inventory(obj);
i = sizeof(inv);

while(i--)
	if( userp(inv[i]) ) inv[i]->move(VOID_OB, 1);
	else inv[i] = 0;
destruct(obj);
return 1;
}

void fullup(object obj) 
{
  if (!obj) return;
  obj->set("kee",(int)obj->query("max_kee"));
  obj->set("eff_kee",(int)obj->query("max_kee"));
  obj->set("sen",(int)obj->query("max_sen"));
  obj->set("eff_sen",(int)obj->query("max_sen"));
  obj->set("force",(int)obj->query("max_force")*2);
  obj->set("mana",(int)obj->query("max_mana")*2);
}

int do_none( )
{
message_vision(HIR"四周毒雾弥漫，$N失去了方向感！\n"NOR,this_player() );
return 1;
}

int do_pfm(string arg)
{
int i;
string fam;
object me = this_player();
fam = me->query("family/family_name");
i = me->query_kar();

if ( !arg || arg=="lingshi" )
	return notify_fail("你想使用什么外功？\n");

if ( fam )
        message_vision("$N大叫一声，看我"+HIW+fam+NOR"的绝招！\n",me);
if ( random(i)>10 )
	return 0;
else	{
	message_vision("$N想使用外功战斗，不想修为不够，失败了！\n",me);
	return 1;
	}
}

int do_cast(string arg) //容易出bug的法术限制，有漏则补
{
string dir;

if ( arg=="chuqiao"
  || arg=="huimeng"
  || arg=="qiankun"
  || arg=="heijie"
  || arg=="yinshen"
  || arg=="taijitu"
  || arg=="arrest"
  || arg=="chongsheng" )  
        {
        tell_object(this_player(),"你结结巴巴念了几句咒语，结果什么反应也没有？\n"); 
        return 1;
        } 

if( sscanf(arg, "huimeng on %s", dir)==1 
 || sscanf(arg, "qiankun on %s", dir)==1 
 || sscanf(arg, "heijie on %s", dir)==1 
 || sscanf(arg, "arrest on %s", dir)==1 
 || sscanf(arg, "chongsheng on %s", dir)==1 ) 
        {
        tell_object(this_player(),"还是正大光明的战斗吧。\n"); 
        return 1;
        }
return 0;
}

void alternative_die(object me)
{
  if ( userp(me) )
	{
	fullup(me);
	me->move("/d/changan/westseastore");
	message("chat",HIY"【"+BLU"死亡岛"+HIY"】沙织(Sha zhi):"+HIW+me->name()+ HIY"输掉了死亡岛的战斗!\n"NOR,users());  
	message_vision("$N输掉了死亡岛战役，灰溜溜的离开死亡凤凰岛。\n",this_player() );  
	update(this_object());
	}
else  destruct(me);
}

void init() 
{ 
add_action("do_none","move"); 
add_action("do_none","mark"); 
add_action("do_none","recall"); 
add_action("do_pfm","perform");
add_action("do_cast","cast");
} 

void die(object who)
{
    alternative_die(who);
}

void unconcious(object who)
{
    alternative_die(who);
}
