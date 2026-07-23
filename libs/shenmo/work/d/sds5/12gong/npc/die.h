void story_end(object where,object me,object ob,object npc1,object npc2,object npc3)
{
string msg;
if ( environment(me)!=where )
        return;
msg = CYN"$1、$2和$3一声不吭，迈步向白羊宫走去，穆上前拦住。\n
穆冷冷的看着众人。\n里昂对着穆一声大喝：穆！想违抗我的命令吗？！\n
穆无奈的停住了脚步。\n"NOR"
$1向北离去。\n
$2向北离去。\n
$3向北离去。\n
$N不由感到失望、愤怒一齐涌上心头。\n";
msg = replace_string(msg,"$1",npc1->name());
msg = replace_string(msg,"$2",npc2->name());
msg = replace_string(msg,"$3",npc3->name());
message_vision(msg,me);
me->command("say 你管得了穆先生，可管不得我！！\n");
message_vision("$N摆好架势，准备挑战这位前任教皇！\n",me);
me->start_busy(1);
destruct(npc1);
destruct(npc2);
destruct(npc3);
destruct(ob);
return;
}

void story2(object me,object ob,object where)
{
object npc1,npc2,npc3;
if ( environment(me)!=where )
        return;
message_vision(CYN"穆「嗯」的一声，一副欲言又止的样子。\n"NOR,me);
message_vision("忽然从黑暗中又出现了三人！\n",me);
npc1=new(__DIR__"shuangzi");
npc2=new(__DIR__"shanyang");
npc3=new(__DIR__"shuiping");
npc1->move(where);
npc2->move(where);
npc3->move(where);
npc1->command("heng");
npc2->command("sigh");
npc3->command("hmm");
me->command("ah");
message_vision(CYN"穆叹了口气道：想不到你们三个也投靠了冥王。\n"NOR,me);
me->start_busy(1);
call_out("story_end",1+random(3),where,me,ob,npc1,npc2,npc3);
}

void story(object me ,object ob,object where)
{
if ( environment(me)!=where )
        return;
message_vision("$N终于战胜了二人,不过也累的吁吁直喘。里昂冷冷的看着$N。\n",me);
me->command("say 老匹夫，下一个就轮到你了！\n");
me->start_busy(3);
call_out("story2",1+random(3),me,ob,where);
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

message_vision("$n惨叫道：我不甘心......我不甘心.....\n",me,ob);
if ( me->query("sds5/lushan")=="done" )
        {
        name = ob->query("name");
        if ( name == "迪斯马斯克" )
                {
                if ( me->query("sds5/baiyang1")!="done" )
                        {
                        tell_object(me,"你得到了一百年道行。\n");
                        me->add("daoxing",100000);
                        me->set("sds5/baiyang1","done");
                        me->save();
                        }
                if ( !present("aphrodite",where) )
                        {
                        call_out("story",1+random(3),me,ob,where);
                        return;
                        }
                }
        if ( name == "阿布罗狄" )
                {
                if ( me->query("sds5/baiyang2")!="done" )
                        {
                        tell_object(me,"你得到了一百年道行。\n");
                        me->add("daoxing",100000);
                        me->set("sds5/baiyang2","done");
                        me->save();
                        }
                if ( !present("death mask",where) )
                        {
                        call_out("story",1+random(3),me,ob,where);
                        return;
                        }
                }
        }
message_vision(HIB"$n化作一阵尘土，消散在晚风中。\n"NOR,me,ob);
destruct(this_object());
::die();
}

