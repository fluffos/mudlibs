#include <ansi.h>
//#include <diary_write.h>

void init()
{
//        ::init();
        add_action("do_chat", "chat");
        add_action("do_chat","chat*");
        add_action("do_jiehun","jiehun");
        add_action("do_jiehun","marry");
        add_action("do_lihun","lihun");
}
int do_chat()
{
   object ob;
   ob=this_player(1);
  
   say(HIW "知府脸色一沉，喝道：“大堂之上，竟敢喧哗！”\n" NOR);
   tell_object(ob, HIR "两边衙役冲上前来，不由分说，一阵大板打得你"
                  +"皮开肉绽,昏了过去。\n" NOR);
   ob->unconcious();
   return 0;
}


int do_lihun(string arg)
{
object me;
object ob;
object card;

object *inv;
int i;

me=this_player(1);

if(!arg)   {
             tell_object(me,"你要和谁离婚啊？\n");
             return 1;
            }

if( !objectp(ob = find_player(arg)))
         {
            tell_object(me,"此人这会不在。\n");
            return 1;
         }


 say(me->query("name")+"想要和"+ob->query("name")+"离婚.\n");

      if( me->query("couple/couple_id") !=arg )
        {
          say("知府疑惑的看了看"+me->query("name")+
                "说：“有没搞错啊？”\n");
          return 1;
        }

      if(!me->query("couple/have_couple"))
        {
         say("知府惊讶道："+me->query("name")+
             "“你没有伴侣，如何离婚?”\n");
         return 1;
        }

      if(!present(arg,environment()))
        {
         say("知府摇摇头说:“"+ob->query("name")+"现在不在这里。”\n");
         return 1;
        }
      if( ob->query("want_lihun")==me->query("id") )
        {
         say("知府叹息道：“你们真让本府失望。”\n");

//         inv=all_inventory(me);
//         for(i=0;i<sizeof(inv);i++)      
//            {
//             if(inv[i]->query("id")=="jiehunzheng") 
//              {
//                destruct(inv[i]);
//              }
//            }
//         inv=all_inventory(ob);
//         for(i=0;i<sizeof(inv);i++)
//            {
//             if(inv[i]->query("id")=="jiehunzheng")
//              {
//                /destruct(inv[i]);
//
//              }
//            /}

         me->delete("couple");
         me->delete("want_marry");
         me->delete("want_lihun");
         me->delete("marry_ok");
         ob->delete("couple");
         ob->delete("want_marry");
         ob->delete("want_lihun");
         ob->delete("marry_ok");
         tell_object(me,"你的婚姻关系被解除了\n");
         tell_object(ob,"你的婚姻关系被解除了\n");
//        diary_write(me,"和"+ob->query("name")+"婚姻关系被解除了");
//        diary_write(ob,"和"+me->query("name")+"婚姻关系被解除了"); 
        message("shout", HIC "【官府通告】：" + HIB + "现今" + me->query("name") + "和" 
         +ob->query("name") + "婚姻关系解除！\n" NOR,users());        
      }
      else
        {
         say("知府道:“"+me->query("name")+"你的想法我知道了"+
             ",不过还要问问"+ob->query("name")+"的意思。”\n");
         me->set("want_lihun",arg);
         return 1;
        }

return 1;
}



int do_jiehun(string arg)
{
object me;
object ob;
object card;
string mes1;
me=this_player(1);

if ( me->query("gender")=="无性") 
           
           { tell_object(me,"你乃无根之人如何结婚？\n");
             return 1;}
if(!arg)   {
             tell_object(me,"你自己和自己结婚啊？\n");
             return 1;
            }

if( (string)me->query("class")=="bonze" ) 
            {
             tell_object(me,"哈哈！怎么，和尚也想开色戒了吗?\n");
             return 1;
            }

if( !objectp(ob = find_player(arg)))
         {
            tell_object(me,"你提的人目前不在这世界吧？\n");
            return 1;
         }


      say(me->query("name")+"想要和"+ob->query("name")+"结婚.\n");
      
      if(me->query("age") <16)
        {
         say("知府摇摇头，显然你没达到结婚年龄。\n");
         return 1;
        }

      if(me->query("couple/couple_id")== arg )
        {
          say("知府疑惑的看了看"+me->query("name")+
                "说：“你俩想二婚？”\n");
          return 1;
        }
      if(me->query("id")== arg )
        {
          say("知府疑惑的看了看"+me->query("name")+
                "说:“你是自恋狂啊？”\n");
          return 1;
        }
      if(me->query("couple/have_couple")) 
        {
         say(HIW "知府大怒，一拍桌子喝道：“"+me->query("name")+
             "你已有伴侣，胆敢重婚！”\n" NOR);
         say("两边衙役冲上前来，不由分说，一阵大板打得"+
               me->query("name")+"皮开肉绽,昏了过去。\n");
         me->unconcious();
         return 1;
        }
      
if(!present(arg,environment()))
        {
         say("知府摇摇头说:“"+ob->query("name")+"现在不在这里。”\n");
         return 1;
        }
      if( ob->query("want_marry")== me->query("id") )
        {
         say("知府微笑道：“祝你们俩白头谐老，永无二心。”\n");   
         
         ob->set("couple/have_couple",1);
         ob->set("couple/couple_id", me->query("id"));
         ob->set("couple/couple_name", me->query("name"));
         if (me->query("gender")=="男性")
          { ob->set("couple/couple_gender","老公");}
         else
           { ob->set("couple/couple_gender","老婆");}
         
         me->set("couple/have_couple",1);
         me->set("couple/couple_id",ob->query("id"));
         me->set("couple/couple_name",ob->query("name"));
         if (ob->query("gender")=="男性")
          { me->set("couple/couple_gender","老公");}
         else
           {me->set("couple/couple_gender","老婆");}

//         card= clone_object(__DIR__"obj/marry_card");
//         card->set("name","你和"+arg+"的结婚证");
//         card->move(me);
//         card= clone_object(__DIR__"obj/marry_card");
//         card->set("name","你和"+me->query("id")+"的结婚证");
//         card->move(ob);
//         say("知府递给"+ob->query("name")+"和"+me->query("name")
//                  +"一人一张结婚证书.\n");
//         diary_write(me,"和"+ob->query("name")+"喜结连理");
//         diary_write(ob,"和"+me->query("name")+"喜结连理");
         me->delete("want_marry");
         ob->delete("want_marry");
         message("shout", HIC "【官府通告】：" + HIR + "恭喜" + me->query("name") + "和" 
         +ob->query("name") + "喜结连理！\n"+"\n"+
         " 
         ■        ■ 
    ■■■■■■■■■■■
         ■        ■
     ■■■■■■■■■■
       ■■■    ■■■
       ■  ■    ■  ■
       ■■■    ■■■
        ◆◆      ◆◆
     ■■■■■■■■■■
       ■■■    ■■■
       ■  ■    ■  ■
       ■■■    ■■■\n"             
          NOR,users());
         return 1 ;
       } 
      else
        {
         if( me->query("gender") == ob->query("gender") )
          {
           say ("知府被"+me->query("name")+
                  "气得口吐白沫昏了过去。喝道：“莫非你有断袖之癖？”\n");
           return 1;
          }
         say("知府微笑道:“"+me->query("name")+",你的心意我知道了"+
             ",不过还要问问"+ob->query("name")+"的意思。”\n");
         me->set("want_marry",arg);
         return 1;
        }

return 1;
}

