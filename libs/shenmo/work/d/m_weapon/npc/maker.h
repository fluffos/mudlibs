void setup()
{
set("str", 25);
set("per", 25);
set("kar", 17);
set("int", 30);
set("age", 20);
set("max_kee", 2000);
set("max_gin", 2000);
set("max_sen", 2000);
set("force", 2500);
set("max_force", 2500);
set("force_factor", 100);
set("mana", 2450);
set("max_mana", 2500);
set("mana_factor", 100);
set("daoxing", 3000000);
set("combat_exp", 5000000);
set("maker_name",query("name"));
set("nickname",HIR+sprintf("%s",query("name")[2..3])+NOR);
::setup();
}       

void make_weapon(object me,object npc,string arg)
{
string o_name,id,w_name,msg;
object weapon,make_time;   //生成的武器句柄
int i,k;

if ( !me || !npc )  return;
if ( !me->query_temp("m_"+query("weapon_type")) ) 
        {
        npc->command("say 我不认识你。。。。"); 
        return;
        }
me->delete_temp("m_"+query("weapon_type"));
me->delete_temp("or");
if ( me->query("weapon/make") )
        {
        write(name()+"一脸茫然：您已经有一把自造的武器了，还来干什么？难到不可手么？\n");
        return;
        }
if ( sscanf(arg ,"%s %s" ,w_name ,id)!=2 )
        {
        write("请这位"+RANK_D->query_respect(me)+"给要制作的武器起名字<格式：中文名称 英文代号 ：\n");
        input_to( (: call_other, __FILE__, "make_weapon", me,npc :) );
        return;
        }
        
i = strlen(id);
while(i--)
        if( id[i]<'a' || id[i]>'z' )
                {
                write("对不起，英文代号只能用英文字母，请这位"+RANK_D->query_respect(me)+"给要制作的武器起名字<格式：中文名称 英文代号 ：\n");
                input_to( (: call_other, __FILE__, "make_weapon", me,npc :) );
                return;
                }

o_name = me->query_temp("get_orc");
make_time=NATURE_D->game_time();
i = sizeof(o_name);
k = i-4;
if ( k<0 )  k = 0;
msg = NOR"\n$N沉吟了一会，对$n巧声说了几句话。$n点了点头。说：好吧！\n";
msg+= "$n回过身，拿出一把寒气逼人的匕首，交到了$N的手中，自己拿出"+o_name+"说：开始吧！\n";
msg+= "$N双手紧紧握住匕首，用尽全身的力气向"+o_name[k..i]+"削去！\n";
msg+= "只听得嗤的一声轻响，匕首一滑竟刺到了$N的手上！\n";
msg+= "$N只觉得手背的伤口一热，随着鲜血的流出，浑身的血液似乎都沸腾了起来！\n";
msg+= HIM"一身精血胶合着汩汩的内气，源源不断的向$n"NOR HIM"手中的"+o_name+NOR HIM"涌去。\n";
message_vision(msg,me,this_object());
if ( me->query("kee")<me->query("max_kee") 
  || me->query("sen")<me->query("max_sen") 
  || me->query("force")<me->query("max_force") )
        {
        message_vision(HIR "突然$N觉得气血一阵翻涌，一口真气接不上来。。。。 \n" NOR, me);
        me->set("force",0);
        me->unconcious();
        return;
        }
message_vision(HIR"只听咯的一声轻响，一道光华从炉中倏然跃起，似一道赤电猛的向$N"NOR HIR"的前胸刺来！！\n" NOR,me );
write(name()+"见状大叫：神兵初成，人血以祭！！闪开！\n");
message_vision("$N只觉得眼前一花，$n已迅捷无比的挡在了$P的身前。\n",me,this_object());   
message_vision(HIR"只听$n"NOR HIR"惨号一声，鲜血溅得$N"NOR HIR"满脸都是！\n" NOR,me,this_object());
message_vision("那道光华又折了起来，飞到半空，扑的一声落回到地上。\n一室的劲气化于无形，一切又归于沉寂。\n\n\n",me );

me->set("weapon/name",w_name);          //武器的名称
me->set("weapon/id",id);                //武器的代号
me->set("weapon/or",o_name);            //记录制造原料
me->set("weapon/value",0);              //记录武器升级已有的点数        
me->set("weapon/type/"+query("weapon_type"),1); //武器类型和等级 NPC不同而不同
me->set("weapon/time",make_time);
me->delete_temp("get_orc");
weapon = new("/obj/weapon");
if ( weapon->check_owner(me) && weapon->move(me) )
        {
        me->set("weapon/make",1);               //武器制造后防止再造的标志              
        write(CYN+name()+NOR CYN"有气无力的说：神兵...已成...您...收好，...我该走了...\n"NOR);
        }
else    write(CYN"\n"+name()+NOR CYN"有气无力的说：神兵炼制...失败了...看来......我仍需回去重新修炼一番...\n"NOR);
write("眨眼之间，"+name()+"已消失不见。。。。\n");      
weapon->init_weapon(query("weapon_type"),1);
me->set("kee",10);
me->set("sen",10);
me->set("force",0);
message_vision("$N得到了"+weapon->name()+"。\n",me);
destruct(npc);
return; 
}

void do_check(object me,object npc)
{
remove_call_out("do_check");    
if ( !me || !npc || !living(me) || !living(npc) )
        return;
write(name()+"低头检视了一下手中的"+this_object()->query_temp("get_or")+"点了点头说：。。。好我们现在就开始吧。\n");
write("请这位"+RANK_D->query_respect(me)+"给自制武器起个名字<格式：中文名称 英文代号 ：");
input_to( (: call_other, __FILE__, "make_weapon", me,npc :) );
return;
}

int accept_object(object who, object ob)
{
string *str,arg = "";
int i;  

str = query("weapon_need_or");
for(i=0;i<sizeof(str);i++)
        arg+= str[i]+" ";
if ( !who->query_temp(query("weapon_type")) )
        {
        message_vision(HIC"师傅没有同意，您请回吧！\n"NOR, who);
        remove_call_out("destrory");
        call_out("destrory",1,ob);
        return 1;
        }
if ( member_array(ob->query("name"),str)==-1 
  || !ob->query("m_weapon_item") )
        { 
        command("say 这是什么！师傅说打造神兵必须使用"+arg+"！");
        return 0;
        }
who->delete_temp(query("weapon_type"));
who->set_temp("m_"+query("weapon_type"),1);
who->set_temp("get_orc",ob->name());
set_temp(who->query("id")+"_weapon_or",ob->name());
command("think");
command("ok");
this_object()->set_temp("get_or",ob->name());
remove_call_out("do_check");
call_out("do_check",1+random(3),who,this_object());
return 1;
}
