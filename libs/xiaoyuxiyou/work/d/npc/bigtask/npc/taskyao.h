#include <ansi.h>
inherit NPC;
int random_place(object me, string dirs);
void copy_status(object me);

void _leave();
void leave();
string *dirs = ({
"/d/xueshan",
"/d/lingtai",
"/d/moon",
"/d/nanhai",
"/d/death",
"/d/pansi",
"/d/jjf",
"/d/sea",
"/d/qujing/wudidong",
"/d/qujing/wuzhuang",
"/d/qujing/kusong",
"/d/qujing/shushan",
"/d/qujing/changan",
"/d/qujing/wuji",
"/d/qujing/baoxiang",
"/d/qujing/tianzhu",
"/d/qujing/nuerguo",
"/d/qujing/yuhua",
});

void init()
{
object me=this_object();
object who=this_player();
int type;
int t=query("stay_time");

::init();
    
if(t && time()>(t+300)) 
        {
        remove_call_out("leave");
        call_out("leave",1);
        return;
        }
if(t && time()>t) 
        {
        remove_call_out("_leave");
        call_out("_leave",300);
        }
if(!living(this_object())) return;
if(!living(who)) return;
remove_call_out("check_room");
call_out("check_room",2);
}

void check_room()
{
object me=this_object();
object env=environment(me);
if(!living(me)) return;
if( env && (env->query("no_fight") 
 || env->query("no_magic"))) 
        random_move();
}

int invocation(int i)
{
object me=this_object();
copy_status(me);
if(!random_place(me, dirs[i]))
        return 0;
return 1;
}

int random_place(object me, string dirs)
{
int  j, k;
object  newob;
mixed*  file, exit;
file = get_dir( dirs+"/*.lpc", -1 );

if( !sizeof(file) )             return 1;

for(k=0;k<30;k++) { // try 30 times
        j = random(sizeof(file));
        if( file[j][1] > 0 ) {
                newob=load_object(dirs+"/"+file[j][0]);
                if (newob) {  
                        if(newob->query("no_fight") ||
                           newob->query("no_magic") ||
                           !(exit=newob->query("exits")) ||
                             sizeof(exit)<1)
                                continue;
                        if(me->move(newob)) {
                                message_vision("$N走了过来。\n",me);
                                return 1;
                                }
                        }
                }
        }
return 0;
}

varargs int receive_damage(string type, int damage, object who)
{
object me=this_object();
remove_call_out("exertheal");
call_out("exertheal",1,me);
return ::receive_damage(type,damage,who);
}

void exertheal(object me) 
{
me->command("exert recover");
}

void die()
{

        int reward;
        object ob,me,book;
        ob = query_temp("last_damage_from");
        me=this_object();
        if (!ob)
        {
                leave();
                return; 
        }
        reward = query("nk_gain") * query("nk_factor");
        ob->add("kill/nkgain",reward);
        ob->add("daoxing",reward);
        ob->add("combat_exp",reward);
        ob->add("potential", reward/3);
        ob->add("jobmark/bigtask_kill",1);
//    CHANNEL_D->do_channel(this_object(), "job",""+ob->query("name")+WHT"杀死"HIG+me->query("name")+NOR WHT"。"NOR); 
CHANNEL_D->do_channel(this_object(), "job","杀死:"+query("name")+HIR"("+ob->name(1)+")"NOR HIG"───>"+HIG"奖励:"+reward+"道行"+reward+"经验"+ reward/3 + "潜能。"NOR); 
//CHANNEL_D->do_channel(this_object(), "job","分配任务完成>>>>>杀死"YEL+query("name")+WHT">>>>>"+WHT"奖励"+reward+"道行"+reward+"经验"+ reward/3 + "潜能。"NOR);
log_file("bigtask","["+ctime(time())+"] "+sprintf("%s(%s)杀死"HIW+query("name")+NOR"获得%d的道行和%d点潜能.\n",
                ob->query("name"),ob->query("id"),reward,reward/3));
if (random(10) == 5 && (int)ob->query("jobmark/bigtask_kill") > 100)
        {
        book = new("/d/obj/book/tujian1");       
        book->move(ob);
        CHANNEL_D->do_channel(this_object(),"rumor","听说"+ob->query("name")+"得到了"HIR"《神兵图鉴》"HIM"上册！！"NOR);
        tell_object(ob,HIY"你得到了《神兵图鉴》上册。\n"NOR);
        ob->set("mark/tujian1", "get");
        }
if (random(50) == 5 && (int)ob->query("jobmark/bigtask_kill") > 300)
        {
        book = new("/d/obj/book/tujian21");       
        book->move(ob);
        CHANNEL_D->do_channel(this_object(),"rumor","听说"+ob->query("name")+"得到了"HIR"《神兵图鉴》"HIM"中册！！"NOR);
        tell_object(ob,HIY"你得到了《神兵图鉴》中册。\n"NOR);
        ob->set("mark/tujian21", "get");
        }
if (random(50) == 5 && (int)ob->query("jobmark/bigtask_kill") > 300)
        {
        book = new("/d/obj/book/tujian22");       
        book->move(ob);
        CHANNEL_D->do_channel(this_object(),"rumor","听说"+ob->query("name")+"得到了"HIR"《神兵图鉴》"HIM"中册！！"NOR);
        tell_object(ob,HIY"你得到了《神兵图鉴》中册。\n"NOR);
        ob->set("mark/tujian22", "get");
        }
if (random(50) == 5 && (int)ob->query("jobmark/bigtask_kill") > 300)
        {
        book = new("/d/obj/book/tujian23");       
        book->move(ob);
        CHANNEL_D->do_channel(this_object(),"rumor","听说"+ob->query("name")+"得到了"HIR"《神兵图鉴》"HIM"中册！！"NOR);
        tell_object(ob,HIY"你得到了《神兵图鉴》中册。\n"NOR);
        ob->set("mark/tujian23", "get");
        }
if (random(50) == 5 && (int)ob->query("jobmark/bigtask_kill") > 300)
        {
        book = new("/d/obj/book/tujian24");  
        book->move(ob);
        CHANNEL_D->do_channel(this_object(),"rumor","听说"+ob->query("name")+"得到了"HIR"《神兵图鉴》"HIM"中册！！"NOR);
        tell_object(ob,HIY"你得到了《神兵图鉴》中册。\n"NOR);
        ob->set("mark/tujian24", "get");
        }
destruct(this_object());
}

void unconcious()
{
if (query("kee")<0 || query("sen")<0) die();
else ::unconcious();
}

void heart_beat()
{
if (!query_temp("weapon") && !query_temp("added"))
        {
        set_temp("added", 1);
        set("force_factor",100);
        set("force",2000);
        }
if (query("eff_kee")<query("max_kee"))
        {
        if (random(10))
                command("eat yao");
        else    {
                command("surrender");
                remove_call_out("exertheal");
                call_out("exertheal",1,this_object());
                }
        }
::heart_beat();
}

void _leave()
{
object me=this_object();
if(me->is_fighting() || me->is_busy())
        return;
leave();
}

void leave()
{
if(this_object()) 
        {
        if(environment())
                {
                command("say 嘿嘿，躲了这么久了，看来是风平浪静了。。。");
                message("vision",HIB + name() + "身子一晃，变成一股青烟散去了。\n" NOR,environment());
                }
        destruct(this_object());
        }
return;
}

int attack()
{
object opponent;
clean_up_enemy();
opponent = select_opponent();
if( objectp(opponent) ) 
        {
        if(opponent->query("family/family_name")==this_object()->query("target")
         && userp(opponent)
         && !living(opponent)
         && environment()==environment(opponent)) 
                {
                remove_call_out("leave");
                call_out("leave",1);
                return 0;
                }
        set_temp("last_opponent", opponent);
        COMBAT_D->fight(this_object(), opponent);
        return 1;
        } 
else    return 0;
}

