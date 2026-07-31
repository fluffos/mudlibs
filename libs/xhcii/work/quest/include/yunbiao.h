// 运镖任务
// derondog@ZLZY

object OBJ, BS;
#include <copy_player.h>

string ask_job()
{
        object me;
        int time, swt;
        string str;
        me = this_player();
        time = 400 + random(100);
        swt = random(2);

        if ( base_name(environment(this_object()))!="/d/city/biaoju1" )
                return "嗯～～，难办啊……\n";

        if ( me->query("combat_exp") < 400000 )
                return "就你这点本事，怎么能让我放心的把花红交给你啊？\n";

        if ( me->query("quest/type")=="运镖" )
                return "我不是给了你任务了吗？\n";

        if ( me->query("quest") )
                return "你还有其他的任务吧？”\n";

        if ( me->query("fail_time") && me->query("fail_time") + 300 > time() )
                return "你上一次任务失败了，你还是回去好好反省吧！”\n";

        me->set("quest/type", "运镖");
        me->set("quest/task_time", time() + time); 

        OBJ = new("/quest/obj/biaoche_y");
        OBJ->move(environment(this_object()));
        OBJ->set("time", time() + time);
        OBJ->set_name(me->name(1) + "的镖车", ({ me->query("id") + "'s che", "che" }));
        BS = new("/quest/npc/biaoshi");
        BS->move(environment(this_object()));
        message_vision(CYN "$N推着$n走了过来。\n" NOR, BS, OBJ);
        BS->set("target", me->query("id"));
        copy_player(me, BS, -10);
        
        switch(swt) {
                case 0:
                        OBJ->set("dst", "/d/city/qianzhuang");
                        str = "你来得正好，请你和这位镖师一起把这宗镖护送到扬州钱庄。\n";
                        break;
                case 1:
                        OBJ->set("dst", "/d/city/datiepu");
                        str = "你来得正好，请你和这位镖师一起把这宗镖护送到扬州打铁铺。\n";
                        break;
                default :
                        str = "出错啦！！请通知在线的管理员解决！！\n";
                        }
        return str;
}

string ask_fail()
{
        object me = this_player();
        
        if ( me->query("quest/type")!="运镖" || !me->query("quest") )
                return "你脑袋有包啊？我又没有给你什么任务！";

        if ( objectp(OBJ) )
                if ( objectp(BS) ) {
                        message_vision(CYN "$N推着$n向前方离去了。" NOR, BS, OBJ);
                        destruct(OBJ);
                        destruct(BS);
                        } 
                else {            
                        message_vision("一个镖局弟子跑了过来，推着$N向前方离去了。\n", OBJ);
                        destruct(OBJ);
                        }

        me->delete("quest");
        me->set("fail_time", time());
        return "不要以为赔了钱就没事了，哼！\n";
}

