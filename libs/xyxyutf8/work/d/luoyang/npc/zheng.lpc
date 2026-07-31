#include <ansi.h>
inherit NPC;
//inherit F_SAVE;

void create()
{
set_name("郑广泉",({"cun zhang","zheng","zheng guangquan"}));
set("title","村长");
set("long","郑家集的村长，一位慈祥的老者。\n");
set("age",70);
set("gender","男性");
set("per",30);
set("int",30);
setup();
//restore();
}
/*
string query_save_file()
{
return sprintf(DATA_DIR "npc/boss/%s","禽兽五常");
}

void init()
{
add_action("do_cmds","",1);
}

int in_job()
{
object who;
string id,str;  
if ( !query("owner_id") )
        return 0;
id = query("owner_id");
who = find_player(id);
if ( !who || !objectp(who) )
        {
        who = new(LOGIN_OB);
        who->set("id", id);
        if( !who->restore() )                           
                {
                delete("owner_id");
                destruct(who);
                return 0;
                }
        str = sprintf("%s(%s)",who->name(1),capitalize(id));
        destruct(who);
        }
else    str = sprintf("%s(%s)",who->name(1),capitalize(id));
write(name()+"说道：真是抱歉，现在"+str+"正在帮老朽的忙呢，不敢劳您大驾。\n");
return 1;
}                       
        
string start_job(object me)
{
int i,k;        
object *npcs,npc;
string str,dir,*id_dir = ({"/quest/禽兽五常/npc"});
string *npc_file = RENWU_D->get_dir_file(id_dir);

if ( !npc_file || !arrayp(npc_file) )
        return "本村向来太平无事";
for(i=0;i<sizeof(npc_file);i++)
        {
        dir = "/quest/禽兽五常/npc/"+npc_file[i];
        npcs = children(dir);
        if ( npcs && arrayp(npcs) )
                {
                for(k=0;k<sizeof(npcs);k++)
                        {
                        npc = npcs[k];
                        if ( !npc || !environment(npc) )
                                continue;
                        tell_object(environment(npc),HIY+npc->name()+HIY"掀开纱帐，准备上床了。\n"NOR);
                        destruct(npc);
                        }
                }
        }
set_temp("npc_file",npc_file);
npc = new("/quest/禽兽五常/npc/"+npc_file[random(sizeof(npc_file))]);
if ( !npc )
        return "最近好似没什么怪异的事";
str = npc->information(me);
if ( !str || !stringp(str) )
        return "老朽见你印堂发黑，估计最近要有大麻烦了";
this_object()->set("owner_id",me->query("id"));
save();
return str;
}                               
        
int do_cmds(string arg)
{
object me = this_player();
string id,str = query_verb();
if ( !userp(me) || str!="ask" )
        return 0;
if ( !arg )
        return 0;
if ( sscanf(arg,"%s about %s",id,arg)!=2 )
        return 0;               
if ( !id(id) )  return 0;
message_vision("$N向$n打听有关『"+arg+"』的消息。\n",me,this_object());
if ( arg=="all" )
        write(name()+"说道：这里现在虽是小村庄，不过听老人们说，以前可是个卧虎藏龙的地方。\n");
else if ( arg=="name" )
        write(name()+"说道：承蒙乡亲抬爱，老朽便做了这里的村长。\n");
else if ( arg=="here" )
        write(name()+"说道：这里现在虽是小村庄，不过听老人们说，以前可是个卧虎藏龙的地方。\n");     
else if ( !is_chinese(arg) )
        write(name()+"说道：这位"+RANK_D->query_respect(me)+"，你说的是番语，老朽不知。\n");
else if ( arg!="帮助" )
        write(name()+"说道：这位"+RANK_D->query_respect(me)+"，老朽这里有礼了。\n");        
else    write(name()+"说道：这位"+RANK_D->query_respect(me)+"，"+start_job(me)+"。\n");     
return 1;
}
*/
