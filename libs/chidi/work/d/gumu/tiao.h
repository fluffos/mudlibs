#include <ansi.h>
// fang.c 

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIC"石室"NOR);
        set("long",@long
一间空荡荡的石室，正前方放着一个祭坛，上面呈放着一些瓜果，两边香
烛散发出摇曳的火光，一些古墓弟子正将侵犯古墓的叛逆的首级呈放在祭坛两
侧用来告慰先祖的英灵。
long);

        set("exits",([
        "north" : __DIR__"gmqs",
        "south" : __DIR__"gmcc",
        "east" : __DIR__"yaofang",
        ]));

        setup();
}

void init()
{
     add_action("do_jibai","jibai");
     add_action("do_ketou","ketou"); 
}

int do_jibai(string arg)
{
        object me,ob;
        int exp,pot,score;
        me=this_player();       
        ob = present("head", me);
        if ( arg == "head") {
        if ( ! ob )
              return notify_fail("你没有人头，祭拜什么？\n");        
        if ( !me->query_temp("gm/job")) 
              return notify_fail("你还没去巡逻呢，哪里捡来的首级？\n");
        if(ob->query("name") != "蒙面女子的首级")
              return notify_fail("你哪里弄来的人头，这人好象不是古墓叛逆啊？\n");        
        if( ob->query("victim_user")) 
              return notify_fail("你哪里弄来的首级，杀错人了吧？\n");
//        if( ob->query("kill_by") != me)
//              return notify_fail("这好象不是你杀的吧？你是怎么得到这个人头的？\n");
        message_vision(HIY"$N恭恭敬敬地磕了几个响头，然后慢慢将$n呈放在祭坛两侧。\n"NOR,me,ob);
        exp =30+random(20);
        me->add("combat_exp",exp);
        pot= 20+random(10);
        me->add("potential",pot);
        score= 5+random(5);
        me->add("score",score);
        me->delete_temp("gm/job");        
        me->delete_temp("meet_nuzi");        
        call_out("destroying", 1, ob);
        tell_object(me,HIW"你被奖励了：\n" + 
        chinese_number(exp) + "点实战经验\n" +
        chinese_number(pot) + "点潜能\n" +
        chinese_number(score) + "点师门忠诚度\n"NOR);        
        return 1;       
        }
      return notify_fail("你拿什么祭拜啊？\n");
}

void destroying(object ob)
{
        destruct(ob);
        return;
}

int do_ketou(string arg)
{
        mapping fam;
        object me=this_player();
        if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
           return notify_fail("你不是古墓传人，在此磕头作甚？\n");
        if ( arg == "jitan"){
        if ( me->query("combat_exp")<30000)
           return notify_fail("你看着祭坛，心感武艺太差，不由惶恐不安，又慢慢站起了身。\n");
        if ( me->query("combat_exp") > 180000)
           return notify_fail("你还是去江湖上多干些事来告慰祖师吧！\n");
        if ( me->query_temp("bishou") < 2 ){
          if(objectp(present("bi shou", me)))        
           return notify_fail("你发现盒子里已经空荡荡的，什么也没有了。\n");   
          me->add_temp("bishou", 1);
          message_vision(HIY"$N恭恭敬敬地对着祭坛磕起头来。\n"NOR, me);
          return 1;
          }                      
          message_vision(YEL"祭坛缓缓转动，$N从里面的小盒子里拿出一把匕首。\n"NOR, me);
          me->delete_temp("bishou");
          new(__DIR__"obj/bishou")->move(me);
          return 1;
          }
     return notify_fail("你对着什么磕头啊？\n");
}


int do_tiao(string arg)
{
        object me;
        me=this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
        if ( !arg || arg != "shenyuan")
                return notify_fail("你要往哪跳？\n");
        if( !me->query_temp("tiaoya") )
        {
                write(HIR"这个悬崖如此凶险，你就这么跳下去只怕凶多吉少，你还是再考虑一下吧。\n"NOR);
                write(HIR"决定跳就敲（yes），改变主意就敲（no）。\n"NOR);
                me->set_temp("tiaoya", 1);
                return 1;
        }
        write("你到底怎么决定的？\n");
        return 1;
}

int do_yes()
{
        object me;
        me= this_player();
        //int j;
        //j=(int)me->query("kar", 1);
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
        if( !me->query_temp("tiaoya") )
                return 0;
        message_vision(HIR"$N犹豫再三，终于下定决心，两眼一闭，涌身向崖底跳去！\n"NOR, me);
        //write("你犹豫再三，终于下定决心，两眼一闭，涌身向崖底跳去！\n");
        me->delete_temp("tiaoya");
        message_vision(HIR"\n$N身体冲开迷雾，只感觉耳边生风，向崖底直坠下去。\n"NOR,me);
        if ((int)me->query("kar",1) >=28)
        //if (random(25) >= 1)
        {
                call_out("win", 1);
                return 1;
        }       
        //write("你身体距离谷底越来越近，定睛看去，谷底原来是一片水潭！\n",);
        call_out("fail", 1);
        return 1;       
        
}

int do_no()
{
        object me;
        me=this_player();
        
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
        if( !me->query_temp("tiaoya") )
                return 0;
        write(HIG"你思虑再三取消了跳下去的决定。\n"NOR);
        me->delete_temp("tiaoya");
        return 1;
}

int win()
{
        object me;
        me=this_player();
        write(HIR"\n你身体距离谷底越来越近，定睛看去，谷底原来是一片水潭！\n"NOR,);
        write(HIR"\n你在空中，身体已经不受控制，直接向水中落去。\n"NOR);
        write(HIR"\n扑通一声，你肚子首先入水，五脏六腑一阵翻滚。张嘴想要惊呼，咕噜咕噜，
反而被灌了一肚子水。\n"NOR);
       me->move(__DIR__"guditan1");
       tell_room(environment(me), "只听到一声惨叫，"+me->name() + "从天空直坠了下来。\n", ({ me }));
       tell_room(environment(me), me->name() + "向下面径直沉了下去。\n", ({ me }));
       me->receive_damage("jingli", 100);
       me->receive_damage("qi", 100);
       me->move(__DIR__"guditan2");
       tell_room(environment(me), me->name() + "从上面直坠了下来。\n", ({ me }));
       tell_room(environment(me), me->name() + "向下面径直沉了下去。\n", ({ me }));
       me->receive_damage("jingli", 200);
       me->receive_damage("qi", 200);
       me->move(__DIR__"guditan3");
       tell_room(environment(me), me->name() + "从上面直坠了下来。\n", ({ me }));
       tell_room(environment(me), me->name() + "向下面径直沉了下去。\n", ({ me }));
       me->receive_damage("jingli", 300);
       me->receive_damage("qi", 300);
       me->set("water", me->max_water_capacity()+200);
       me->move(__DIR__"guditan4");       
       tell_room(environment(me), me->name() + "从上面直坠了下来。\n", ({ me }));
       message_vision (HIB"$N只觉得头晕晕的，身体浸在冰冷的水中，不住的颤抖。\n"NOR,me);
       return 1;
        
}

int fail()
{
        object me, tmp;
        object *ob;
        int i;
        me= this_player();
        write(HIR"\n你身体距离谷底越来越近，定睛看去，谷底原来是一片水潭！\n"NOR,);
        write(HIR"\n你在空中，身体已经不受控制，直接向潭边一块大石头坠去！\n"NOR, );
        write(HIR"\n你急转身形，想要调整方向，无耐四体悬在空中，飘忽忽的浑不着力，眼看着
距离石头越来越近了！这时侯你心中不禁泛起一丝悔意：小龙女爱的又不是我，
我跳下来干什么？\n"NOR);
       me->move(__DIR__"gudi");
       me->set_temp("last_damage_from","跳下山崖摔");
       me->unconcious();
       me->die();
        if (tmp = present("corpse", this_object())) 
        {
                ob = deep_inventory(tmp);
                i = sizeof(ob);
                while (i--) if (userp(ob[i])) ob[i]->move(this_object());
                destruct(tmp);
               destruct("corpse");
               if (me) tell_room(this_object(), me->name()+"的尸骨都找不到了。\n");
        }
        return 1;
}

