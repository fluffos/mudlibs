///////////////////////////////////////////////////////////////
/////////////////////three_star.h 血泪三人之卷//////////////////
///////////////////////////////////////////////////////////////

void powerup()
{
object me = this_object();
string title = WHT"【"NOR HIB"圣战"NOR HIY"十二宫"NOR HIB"之卷"NOR WHT"】"NOR;
title+=HIC+me->query("name")+HIC"("+capitalize(me->query("id"))+")："HIC; 
random(2)?
message("channel:music",title+"燃烧吧，小宇宙！\n"NOR,users()):
message("channel:chat",title+"小宇宙！给我力量！\n"NOR,users());
me->set("kee",query("max_kee"));
me->set("eff_kee",query("max_kee"));
me->set("sen",query("max_sen"));
me->set("eff_sen",query("max_sen"));
me->set("force",query("max_force"));
me->set("mana",query("max_mana"));
me->clean_condition();
return;
}

int do_none()
{
if ( random(3)==1 )
        tell_object(this_player(),"安心战斗吧。\n");
return 1;
}

int do_cast(string arg)
{
string args;
object me = this_player();
object ob = this_object();
if ( arg=="huimeng" || arg=="qiankun" || arg=="yinshen" )
        {
        if ( random(3)==1 )
                message("vision",YEL+ob->name()+YEL"深深吸了几口气，脸色看起来好多了。\n"NOR,environment(),me);
        if ( random(10)==1 )     powerup();
        return 1;
        }
else  if ( sscanf(arg, "on %s",args)==1 && (arg=="huimeng"||arg=="qiankun"||arg=="yinshen") )
        {
        if ( random(3)==1 )
                message("vision",YEL+ob->name()+YEL"深深吸了几口气，脸色看起来好多了。\n"NOR,environment(),me);
        if ( random(10)==1 )     powerup();
        return 1;
        }
return 0;
}

int do_pfm(string arg)
{
string args;
object me = this_player();
object ob = this_object();
if ( arg=="fengchan" || arg=="meihua" )
        {
        if ( random(3)==1 )
                message("vision",RED+ob->name()+RED"深深吸了几口气，脸色看起来好多了。\n"NOR,environment(),me);
        if ( random(10)==1 )     powerup();
        return 1;
        }
else  if ( sscanf(arg, "on %s",args)==1 && (arg=="fengchan" || arg=="meihua") )
        {
        if ( random(3)==1 )
                message("vision",RED+ob->name()+RED"深深吸了几口气，脸色看起来好多了。\n"NOR,environment(),me);
        if ( random(10)==1 )     powerup();
        return 1;
        }
return 0;
}

void die_sp(object me,object ob)
{
object npc,where;
string title = WHT"【"NOR HIB"圣战"NOR HIY"十二宫"NOR HIB"之卷"NOR WHT"】"NOR;

if ( !me || !ob || environment(me)!=environment(ob) )
        return;

where = environment(ob);

if ( me->query("sds5/shinu1")!="done" )
        {
        title+=HIC"穆(Mu)："+me->query("name")+"战败了"+ob->name()+"！\n"NOR;
        message("channel:chat",title,users());
        tell_object(me,"你得到了一百年道行。\n");
        me->add("daoxing",100000);
        me->set("sds5/shinu1","done");
        me->save();
        }
if ( me->query("sds5/shinu2")=="done" && me->query("sds5/shinu3")=="done" )
        {
        me->set("sds5/shinu","done");
        me->save();
        }
message_vision("忽然上方传来一声“雅典娜召见”，$n听到，径直去了。\n",me,ob);
destruct(ob);
return;
}

void die_sz(object me,object ob)
{
object npc,where;
string title = WHT"【"NOR HIB"圣战"NOR HIY"十二宫"NOR HIB"之卷"NOR WHT"】"NOR;

if ( !me || !ob || environment(me)!=environment(ob) )
        return;

where = environment(ob);
if ( me->query("sds5/shinu2")!="done" )
        {
        title+=HIC"穆(Mu)："+me->query("name")+"战败了"+ob->name()+"！\n"NOR;
        message("channel:chat",title,users());
        tell_object(me,"你得到了一百年道行。\n");
        me->add("daoxing",100000);
        me->set("sds5/shinu2","done");
        me->save();
        }
if ( me->query("sds5/shinu1")=="done" && me->query("sds5/shinu3")=="done" )
        {
        me->set("sds5/shinu","done");
        me->save();
        }
message_vision("忽然上方传来一声“雅典娜召见”，$n听到，径直去了。\n",me,ob);
destruct(ob);
return;
}

void die_sy(object me,object ob)
{
object npc,where;
string title = WHT"【"NOR HIB"圣战"NOR HIY"十二宫"NOR HIB"之卷"NOR WHT"】"NOR;

if ( !me || !ob || environment(me)!=environment(ob) )
        return;

where = environment(ob);
if ( me->query("sds5/shinu3")!="done" )
        {
        title+=HIC"穆(Mu)："+me->query("name")+"战败了"+ob->name()+"！\n"NOR;
        message("channel:chat",title,users());
        tell_object(me,"你得到了一百年道行。\n");
        me->add("daoxing",100000);
        me->set("sds5/shinu3","done");
        me->save();
        }
if ( me->query("sds5/shinu1")=="done" && me->query("sds5/shinu2")=="done" )
        {
        me->set("sds5/shinu","done");
        me->save();
        }
message_vision("忽然上方传来一声“雅典娜召见”，$n听到，径直去了。\n",me,ob);
destruct(ob);
return;
}

void die()
{
string name;
object ob = this_object();
object me = ob->query_temp("last_opponent");
object where = environment(ob);
powerup();
if ( !me || !present(me,environment(ob)) )
	return;

if ( random(20)==1 )
	{
	say(HIB"\n"+name()+HIB"点了点头：不错不错，再来再来！\n"NOR);
	me->kill_ob(ob);
	ob->kill_ob(me);
	return;
	}

me->remove_killer(ob);
ob->remove_killer(me);
message_vision("$n惨笑一声：尔来四万八千里，可惜时不利兮，奈何，奈何....\n",me,ob);
if ( me->query("sds5/shizi")=="done" && me->query("sds5/shinu")!="done" )
        {
        name = ob->query("name");
        switch ( name )
                {
                case "卡妙" : call_out("die_sp",1,me,ob);break;
                case "修罗" : call_out("die_sy",1,me,ob);break;
                case "撒加" : call_out("die_sz",1,me,ob);break;
                }
        return;
        }
message_vision(HIB"$n化作一阵尘土，消散在晚风中。\n"NOR,me,ob);
destruct(this_object());
::die();
}

void unconcious()
{
  die();
}

 
