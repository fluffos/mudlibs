// hongniang.c 红娘
// honest create

#include <ansi.h>
#include <diary_write.h>
inherit NPC;

int do_hunli();

int do_qingtie();

int do_begin();

int do_jz();


void create()
{
        set_name("红娘", ({ "hong niang", "hong" }));
        set("long", 
                "她是一个长得很好看的小姑娘。\n"
                "你可以可她关于<婚礼>方面的事。\n");
        set("gender", "女性");
        set("age", 16);
        set("per", 27);
        set("no_clean_up",1);

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 5);

        set("combat_exp", 3000);
        set("shen_type", 1);
        set("inquiry", ([
                "婚礼"    : (: do_hunli :),
                "请贴"    : (: do_qingtie :),
                "开始婚礼": (: do_begin :),
                "打扮"    : (: do_jz :),
        ])); 
        setup();

}
int do_hunli()
{ 
        object me,obj,ob;

        me=this_player();

        ob=this_object();

if (!me) return 1;
        if(!me->query("couple/have_couple")) 
          {
            say ("红娘摇摇头说:“你还没结婚呢。”\n");
            return 1;
          }

        obj = find_player(me->query("couple/couple_id"));

        if(!obj || (!wizardp(me) && !me->visible(obj)))
          { say ("红娘摇摇头说:“你的伴侣现在不在....”\n");
            return 1;
          }

        if(!present((string)obj,environment()))
          {
            say("红娘摇摇头说:“"+obj->query("name")+"现在不在这里。”\n");
            return 1;
          }

        if (me->query("marry_ok")) 
         { 
          say("红娘摇摇头说:“你已经举行过婚礼了，还想要？”\n");
          return 1;
         }

        say (HIW "红娘福了福说:“好吧,既然你们真心相爱...,我自当把二位的婚礼办的热热闹闹。”\n" NOR);

        say (HIB "红娘拉着"+(string)me->query("name")+"和"+(string)obj->query("name")+"的手走到了一个神秘的地方。\n" NOR);

        me->move(__DIR__"honglou");
 
        obj->move(__DIR__"honglou");

        ob->move(__DIR__"honglou");

        me->set("marry_ok",1);
 
        obj->set("marry_ok",1);

        ob->set("xingren1",me->query("name"));

        ob->set("xingren2",obj->query("name"));

        say (HIR "红娘对着你俩一笑说：“你们想请什么人呢？想好了就向我要"+HIW+"请贴"+HIR+"吧。”\n" NOR );

        return 1;
}

int do_qingtie()
{
       object me, tie, ob, *all, ke, ma;
       
       int i;

       me=this_player();

       ob=this_object();
       
       all = users();
      
       if (ob->query("qingtie")) 
       {
        say ("红娘说：“请贴已经发过了。”\n");
        return 1;
       }

       if (!(me->query("marry_ok"))) 
        { 
          say ( (string)me->query("name")+"你不是新人要什么请贴？\n" );
          return 1;
        }

       
       message_vision(HIW "$N拍了拍手，无数的白鸽带着请贴噼里啪啦冲天而去。\n" NOR,this_object()); 

       for(i=0; i<sizeof(all); i++) 
        {
          ke = all[i];

          if ( (string)ke->query("id") !=(string)me->query("id") 
                 && (string)ke->query("id") != (string)me->query("couple/couple_id")) 

              { tie =clone_object(__DIR__"obj/qingtie");
                tie->set("name",HIR+(string)me->query("name")+"和"+(string)me->query("couple/couple_name")+"的结婚请贴" NOR);
                tell_object(ke,HIR"一只白鸽飞到你身上，带给你一张请贴，然后飞走了。\n\n"NOR); 
                tie->move(ke);}
        }

       ob->set("qingtie",1);

       ma=clone_object(__DIR__"mafu1");
   
       ma->move("/d/pingan/guangchang");

       say(HIY "红娘轻笑一声说：“客人到齐了就告诉我一声。我们就『开始婚礼』。开始前新娘子可要『打扮』一下喔。”\n" NOR);

       return 1;
}

int do_begin()
{
       object me,ob,obj,ke,check;

       me = this_player();

       if(!me) return 0;
       if(!me->query("couple/couple_id")) return 0;
if (me->query_temp("coup")) return 0;
       if(!(obj = find_player(me->query("couple/couple_id")))) return 0;

       ob = this_object();
       
       if (me->query("gender")!="男性") 
 
          { check = me; }
         
         else { check = obj; }

       if (!(check->query("dress_ok"))) 
         { 
           say(HIC "红娘吃吃笑道：“新娘子还没打扮呢这么心急啊。”\n" NOR);
           return 1;
         }
me->set_temp("coup",1); 
       message("shout", HIR "【婚礼】：司仪高叫：“" + me->query("name") + "和" 
         +obj->query("name") + "婚礼现在开始！”\n" NOR,users());
        diary_write(me,"和"+ob->query("name")+"举行婚礼");
        diary_write(obj,"和"+me->query("name")+"举行婚礼");
       call_out("ke1", 3, ob);
   
       return 1;
} 
            
int do_jz()
{     
       object me,obj,check,dress;
     
       me = this_player();

       if(!me) return 0;
       if (!me->query("couple/couple_id")) return 0;
       if(!(obj = find_player(me->query("couple/couple_id")))) return 0;
       
       if (me->query("gender")!="男性")
          
          { check = me; }
       
         else { check = obj; }
       
       if (check->query("dress_ok")) 
         { 
           say ("红娘叹了口气说：“我可只有一套妆衣。”\n");
           return 1;
         }

       if ( me->query("gender")=="男性")

       { 
          dress=clone_object(__DIR__"obj/clasp");
          dress->move(obj);
          dress=clone_object(__DIR__"obj/marry_dress");
          dress->move(obj);
          dress=clone_object(__DIR__"obj/bracelet");
          dress->move(obj);
          message_vision(HIW "$N拍了拍手，一位青衣小厮送上了一套妆衣。\n" NOR,this_object()); 
          message_vision(HIB "$N对$n说新娘子可要好好打扮一下。\n" NOR,this_object(),obj); 
          message_vision(HIY "$N给$n一只凤翅金钗。\n" NOR,this_object(),obj); 
          message_vision(HIW "$N给$n一件白色婚纱。\n" NOR,this_object(),obj); 
          message_vision(HIG "$N给$n一只翡翠手镯。\n" NOR,this_object(),obj); 
          obj->set("dress_ok",1);
          message_vision(HIY "$N对$n说：“快穿起来吧。”\n" NOR,this_object(),obj); 
       }
       else
        {
          dress=clone_object(__DIR__"obj/clasp");
          dress->move(me);
          dress=clone_object(__DIR__"obj/marry_dress");
          dress->move(me);
          dress=clone_object(__DIR__"obj/bracelet");
          dress->move(me);
          message_vision(HIW "$N拍了拍手，一位青衣小厮送上了一套妆衣。\n" NOR,this_object()); 
          message_vision(HIB "$N对$n说新娘子可要好好打扮一下。\n" NOR,this_object(),me); 
          message_vision(HIY "$N给$n一只凤翅金钗。\n" NOR,this_object(),me); 
          message_vision(HIW "$N给$n一件白色婚纱。\n" NOR,this_object(),me); 
          message_vision(HIG "$N给$n一只翡翠手镯。\n" NOR,this_object(),me); 
          me->set("dress_ok",1);
          message_vision(HIY "$N对$n说：“新娘子快穿起来吧。”\n" NOR,this_object(),me); 
        }
      return 1;

}


int ke1(object ob)
{
         string xingren1,xingren2;

         xingren1= (string)ob->query("xingren1");

         xingren2= (string)ob->query("xingren2");

         ob = this_object();

         message("shout", HIR "【婚礼】：司仪高叫：“一拜天地”\n" NOR,users());

         say ("\n"+ HIW + xingren1 + "和" + xingren2 + "对天磕了一个头。\n" NOR); 
    
         call_out("ke2",3,ob);

         return 1;
}

int ke2(object ob)
{
        string xingren1,xingren2;

        xingren1= (string)ob->query("xingren1");

        xingren2= (string)ob->query("xingren2");

        ob = this_object();

        message("shout", HIR "【婚礼】：司仪高叫：“二拜高堂”\n" NOR,users());
  
        say ("\n"+HIB + xingren1 + "和" + xingren2 + "对各位巫师磕了一个头。\n" NOR);

        call_out("ke3",3,ob);
 
        return 1;
}
int ke3(object ob)
{
        string xingren1,xingren2;

       xingren1= (string)ob->query("xingren1");

       xingren2= (string)ob->query("xingren2");

       ob = this_object();

       message("shout", HIR "【婚礼】：司仪高叫：“夫妻对拜”\n" NOR,users());

       say ("\n"+HIY + xingren1 + "和" + xingren2 + "含情脉脉的相互对拜。\n" NOR);
    
       call_out("sanhua",3,ob);
    
       return 1;
}
int sanhua(object ob)
{   
       object flower;
    
       message("shout", HIR "【婚礼】：司仪高叫：“花童散花”\n" NOR,users());
   
       message("shout", HIR "整个平安城的街道下起了一阵缤纷的花雨。\n\n" NOR,users());

       flower=clone_object(__DIR__"obj/flower"+random(6));

       flower->move("/d/pingan/guangchang");
    
       flower=clone_object(__DIR__"obj/flower"+random(6));

       flower->move("/d/pingan/nan1");
    
       flower=clone_object(__DIR__"obj/flower"+random(6));

       flower->move("/d/pingan/nan2");

       flower=clone_object(__DIR__"obj/flower"+random(6));

       flower->move("/d/pingan/nan3");

       flower=clone_object(__DIR__"obj/flower"+random(6));

       flower->move("/d/pingan/west1");

       flower=clone_object(__DIR__"obj/flower"+random(6));

       flower->move("/d/pingan/west2");

       flower=clone_object(__DIR__"obj/flower"+random(6));

       flower->move("/d/pingan/west3");

       flower=clone_object(__DIR__"obj/flower"+random(6));

       flower->move("/d/pingan/bei1");

       flower=clone_object(__DIR__"obj/flower"+random(6));

       flower->move("/d/pingan/dong1");

       flower=clone_object(__DIR__"obj/flower"+random(6));

       flower->move("/d/pingan/pinganmen");

       
       ob = this_object();

       call_out("eateat",3,ob);

       return 1;

}

int eateat(object ob)
{
      object food,ke,*all;
      
      int i;

      all=users();

      message("shout", HIR "【婚礼】：司仪高叫：“夫妻洞房,大宴宾客”\n" NOR,users());
 
      for(i=0; i<sizeof(all); i++) 
        {
          ke = all[i];
          food = clone_object(__DIR__"obj/wlywine");
          food->move(ke);
          tell_object(ke,"你得到一瓶"+(string)food->query("name")+"。\n"); 
          food = clone_object(__DIR__"obj/cigarette");
          food->move(ke);
          tell_object(ke,"你得到一包"+(string)food->query("name")+"。\n"); 
          food = clone_object(__DIR__"obj/sugar"); 
          food->move(ke);
          tell_object(ke,"你得到一粒"+(string)food->query("name")+"。\n"); 
        }
     message("shout", HIR "【婚礼】：司仪高叫：“婚礼完毕”\n" NOR,users());
}   
