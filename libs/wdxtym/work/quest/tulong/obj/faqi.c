// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */

//by night 
string test_name(string);

#include <ansi.h>
inherit ITEM;

string *names = ({
  "法铃",
  "木鱼",
  "经纶",
  "罗衣",
  "禅杖",
  "念珠",
  "袈裟",
});

string *ids = ({
  "fa ling",
  "mu yu",
  "jing lun",
  "luo yi",
  "chan zhang",
  "nian zhu",
  "jia sha",
});

string *units = ({
  "个",
  "个",
  "盘",
  "件",
  "根",
  "串",
  "件",
});

void create()
{
        int i = random(sizeof(names));
        set_name(names[i], ({ids[i],"fa qi"}));
        set("unit", units[i]);   
        if (clonep())
                set_default_object(__FILE__);
        else {      
                set("no_drop","这是佛家法器，不可随便丢弃。\n");
                set("no_put",1);
                set("long", "这是佛家法器，你可以用它来布道（budao）。\n");
                set("value", 0);
             }
        setup();
}

void init()
{
        add_action("do_budao", "budao");
        add_action("do_check", "kan");
        add_action("do_check", "chakan");                
}

int do_budao(string arg)
{
        object me=this_player();
        int nforce,nmana,skl,i;
        int j = 0;
        string people = "";
        object *obs = all_inventory(environment(me));
        
        nforce = (int)me->query("force")/4;
        nmana = (int)me->query("mana")/4;
        skl = random(60) + 140 - (int)me->query_skill("chanting", 1);
        if(skl>180) skl = 180;
        if(skl<10) skl = 10 + random(5);
        i = sizeof (obs);
        while (i--)
        {
        if (living (obs[i]) && obs[i]!=me && me->visible(obs[i]) )
                {
                j++;
                people = people + obs[i]->name();
                }
        }

        if (me->query_temp("obj/done") >= 1)
        {
          tell_object(me,"你已经完成布道了，回去报告吧。\n");
          return 1;
        }
        else
        if (me->query_temp("obj/budao") < 1)
        {
          tell_object(me,"现在好像没有轮到你去布道？\n");
          return 1;
        }
        else
        if (me->query_temp("obj/where") != test_name(base_name(environment(me))))
        {
          tell_object(me,"你布道的地方不是这里吧？\n");
          return 1;
        }
        else
        if (environment(me)->query_temp("budao") >= 1)
        {
          tell_object(me,"这儿不久前有人来布过道，现在恐怕来得不是时候。\n");
          return 1;
        }
        else          
        if ((me->query("sen") < 20))
        {  
          tell_object(me,"你的精力不能集中，不可以布道！\n");
          return 1;
        }
        else
        if ((me->query("kee") < 30 ))
        {
          tell_object(me,"你的身体状态太差，不能传经布道！\n");
          return 1;
        }
        else          
        if (j == 0 || !me)
        {
          tell_object(me,"这儿人都没有，布什么道？\n");
          return 1;
        }
        else
        if (me->is_busy())
        {
          tell_object(me,"你现在正忙着呢，没法布道。\n");
          return 1;
        }
        else
        if (!arg || arg == "" )
        { 
          tell_object(me,"你要用什么道具进行布道？\n");
          return 1;
        }
        else
        if ( arg == "fa ling" || arg == "mu yu")
        {
          if(!present(arg,me)) return notify_fail("你身上没有这样东西。\n");        
          if ( nforce < 30 || (me->query("force") < nforce))
            return notify_fail("唱梵曲需要内息悠长，你的内力不足，力不能及。\n");
          
          message_vision(HIW"$N清了清噪子，法像庄严，吟出一曲梵唱。\n"NOR,me);          
          me->start_busy(skl);
          me->add("force", -nforce);
        remove_call_out ("reacting");
        call_out ("reacting",1+random(3),me,people,j);
          remove_call_out("fanchang");             
          call_out("fanchang",skl,me);
          return 1;
        }
        else
        if ( arg == "luo yi" || arg == "jia sha")
        {
          if(!present(arg,me)) return notify_fail("你身上没有这样东西。\n");
          if (nmana < 30 || (me->query("mana") < nmana))
            return notify_fail("讲经必须法力充盈，你法力不足，神思难以集中。\n");
            
          message_vision(HIW"$N垂目低首，合什于胸，讲起了《法华经》。\n"NOR,me);          
          me->start_busy(skl);
          me->add("mana", -nmana);
        remove_call_out ("reacting");
        call_out ("reacting",1+random(3),me,people,j);
          remove_call_out("jiangjing");                       
          call_out("jiangjing",skl,me);
          return 1;
        }
        else
        if ( arg == "chan zhang" || arg == "jing lun" || arg == "nian zhu")
        {
          if(!present(arg,me)) return notify_fail("你身上没有这样东西。\n");        
          if ((nmana < 30 || nforce < 30) || (me->query("mana") < nmana) || (me->query("force") < nforce))
            return notify_fail("开设祭坛必须内力法力融而为一，天地交汇，你的状态还不允许。\n");

          message_vision(HIW"$N开设祭坛，祈天默祷，为百姓降福。\n"NOR,me);          
          me->start_busy(skl); 
          me->add("mana", -nmana);
          me->add("force", -nforce);  
        remove_call_out ("reacting");
        call_out ("reacting",1+random(3),me,people,j);
          remove_call_out("kaitan");                                         
          call_out("kaitan",skl,me);
          return 1;
        }
}

int fanchang(object me)
{
        message_vision(HIY"$N声音渐微，曲意不散，围观的群众似乎有所领悟。\n"NOR,me);
        me->set_temp("obj/done",1);
        environment(me)->set_temp("budao",1);        
        return 1;
}

int jiangjing(object me)
{
        message_vision(HIY"$N舌绽莲花，天花乱坠。周围的群众听得啧啧不已。\n"NOR,me);
        me->set_temp("obj/done",1);
        environment(me)->set_temp("budao",1); 
        return 1;
} 

int kaitan(object me)
{
        message_vision(HIY"$N慈悲普渡，宝像庄严。周围的群众都看得目瞪口呆。\n"NOR,me);
        me->set_temp("obj/done",1);
        environment(me)->set_temp("budao",1); 
        return 1;
}  

string test_name(string arg)
{
  string *temp;
  temp=explode(arg,"/");
  return temp[2];
}

int do_check(string arg)
{
        object me;

        me = this_player();

        if(!arg) return 0;
        if( (arg=="fa qi"||arg=="faqi")&&me->query_temp("obj/budao")) {
                write(
                        "这是一件法器，你布道的目的地是："
                        HIG"「"+me->query_temp("obj/budaowhere")+"」"NOR"。\n"NOR);
        }
        else
        {
        if( (arg=="fa qi"||arg=="faqi")&&!me->query_temp("obj/budao")) 
        write("这是一件法器，隐蕴无上法力。\n");
         }
        return 1;
}

void reacting (object me, string people, int j)
{
  if (j == 0 || !me)
    return;

  if (j == 1)
    message_vision (people+"看见有人在此布道，不禁停了下来，看个究竟。\n",me);
  else
    message_vision (people+"等人见有人在此布道，都围了过去，看个究竟。\n",me);
}

