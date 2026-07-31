#include <ansi.h>
mixed names = ({
        ({
         "罗汉拳", "韦托掌","寂灭爪","摩诃指","龙爪功","风云手",
         "少林弹腿", "般若掌", "如来千叶手", "大金刚拳","一指禅",
         "散花掌","拈花指", "如影随形腿",
          }),
         });

mixed skills = ({
          ({
            "luohan-quan","weituo-zhang","jimie-zhua","mohe-zhi","longzhua-gong","fengyun-shou",
            "shaolin-tantui","banruo-zhang","qianye-shou","jingang-quan","yizhi-chan","sanhua-zhang",
            "nianhua-zhi","ruying-suixingtui",
           }),
          });
mixed types =({
          ({
            "cuff","strike","claw","finger","claw","hand","leg","strike","hand",
            "cuff","finger","strike","finger","leg",
           }),
          });
string* names1 = ({
 "/d/shaolin/cjlou1",
 "/d/shaolin/fatang",
 "/d/shaolin/sblu-3",
 "/d/shaolin/jietan2",
 "/d/shaolin/xiaolu5",
 "/d/shaolin/fzjs2",
 "/d/shaolin/xiaolu2",
 "/d/shaolin/bydian",
 "/d/shaolin/dzdian",
 "/d/shaolin/putiyuan",
 "/d/shaolin/fota3",
 "/d/shaolin/zhlou7",
 "/d/shaolin/gulou7",
 "/d/shaolin/qyping",
 "/d/shaolin/caidi",
 "/d/shaolin/celang1",
 "/d/shaolin/celang2",
 "/d/shaolin/gchange",
 "/d/shaolin/gchangw",
 "/d/shaolin/shifang",
 "/d/shaolin/fxjing",
 "/d/shaolin/damodong",
});
void init()
{
        object ob;
this_object()->set("no_get",1);

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_teach", "teach");
}
        
string ask_me()
{
        int lvl;
       object fighter,me;
        string skill_name,skill_id,skill_type;
        int i;
        fighter = this_player();
        me = this_object();
      
       if(!(fighter->query_temp("lh_teacher")))
           return "这个可不能乱说。";
//     if( me->query("teacher") && me->query("teacher") != fighter->query("id"))
//         return "我现在正由"+ me->query("teach") +"("+me->query("teacher")+")教着呢！";
       if (me->query("learn")){
        lvl=(int)me->query_skill(me->query("skill"),1);
//      slvl=string(lvl);
        return "我在学"+me->query("learn")+RED"当前的等级是"+lvl+HIY"请你指点（teach monk)"NOR;          
        }    
       i=random(sizeof(names[0]));
        skill_name=names[0][i];
        skill_id=skills[0][i];
        skill_type=types[0][i];
        me->set("learn",skill_name);
        me->set("skill",skill_id);
        me->set_skill(skill_id,1);
//      me->set("teacher", fighter->query("id"));
//      me->set("teach", fighter->query("name"));
        me->map_skill(skill_type,skill_id);
        me->map_skill("parry",skill_id);
        me->prepare_skill(skill_type, skill_id);
        me->set("no_clean_up",1);
        return "我想学"+me->query("learn")+HIY"请你指点(teach monk)"NOR;
}

int do_teach(string arg)
{
        object me,teacher,ob;
        string my_skill,where,na;
        int my_lvl,gin_cost,exp;
        me=this_object();
        teacher=this_player();
        if (arg!="monk")
           return notify_fail("你要干什么?\n");
        if( me->query("teacher") && me->query("teacher") != teacher->query("id")){
           command ("say 我现在正由"+ me->query("teach") +"("+me->query("teacher")+")教着呢！");
           return 0;
           }
        if (teacher->is_busy())
           return notify_fail("你正忙着呢。\n");
        if (!(me->query("skill")))
           return notify_fail("你问我想学什么了吗?\n");  
        if (interactive(teacher)
         && (int)teacher->query_condition("lh_job")){
//      if (!(teacher->query_temp("lh_teacher")))
//          return 0;
        my_skill=me->query("skill");
        my_lvl=(int)me->query_skill(my_skill,1);
        if (my_lvl>(int)teacher->query_skill(my_skill,1))
           return notify_fail("你的修为还不如我呢，还想教我?!");
        if (me->is_busy())
           return notify_fail(me->query("name")+"正忙着呢。"); 
        me->set("teacher", teacher->query("id"));
        me->set("teach", teacher->query("name"));
        gin_cost = 150/me->query("int");
        if( (int)me->query("jing") > gin_cost)
          me->receive_damage("jing", gin_cost);
        else {
            tell_object(teacher, "但是"+me->name()+"太累了，现在没有办法学 。\n");
            message("vision", HIY "\n但是"+me->name()+"太累了，现在没有办法学到什么。\n" NOR, environment(teacher));
            return 1;
            }        
        if (!random(5)) message("vision",
            teacher->name() + "正在向" + me->name() + "指点武功。\n", environment(teacher));
        if (teacher->query("jing")<=(gin_cost*2))
            teacher->unconcious();
            me->receive_damage("jing", gin_cost );
            teacher->receive_damage("jing",gin_cost);
            me->add_skill(my_skill, me->query_int() / 4 + random(me->query_int() * 5 / 3));
       if (random(6)>3){
            tell_object(teacher,"在教弟子的过程中，你也领悟了一些武学的道理。\n");
            teacher->improve_skill(my_skill, teacher->query_int() / 5 + random(teacher->query_int() * 5 / 6));
        exp = (me->query_skill(my_skill,1))/5+1;
       if ( exp > 15 ) exp = 15 + random(7);
            teacher->add("combat_exp",exp);
       if (teacher->query("potential") > teacher->query("max_pot")){
            teacher->set("potential", teacher->query("max_pot"));   
            return 1;
            }
                teacher->add("potential", random(me->query_skill(my_skill,1))/10+1);
    if (random(my_lvl)>60&&random(my_lvl)%10==0)
         {
           where = names1[random(sizeof(names1))];  
           tell_object(environment(me),HIC"一阵紧急的锣声响起，有外贼偷进少林寺图谋不轨！\n"NOR);
           message("vision", HIY +me->name()+"神情振奋，一声大叫向"+where->query("short")+"奔去!\n" NOR, environment(teacher));
           na=teacher->query("id");
           ob=new(__DIR__"motou"); 
           ob->move(where);
           ob->set_temp("killer",na);
           me->set("place",environment(me));
           me->move(where);
           remove_call_out("waiting");
           call_out("waiting", 1, me,0);
         }             

                            }
       else {
           tell_object(teacher,"你尽心竭力，对"+me->name()+"指点武学的道理.\n");
           }         
           me->start_busy(random(3));
           teacher->start_busy(random(3));
           return 1;
           }
     return notify_fail("也不知道哪的骗子，跑少林寺行骗来了。\n");
}    
 int waiting(object me,int wait_time)
{
        object teacher;
        string place;
        
        if( wait_time >= 100 )
        {
               tell_object(environment(me),HIY+me->name()+"伤痕累累，眼看就要支持不住了!\n"NOR);
               me->die();
               return 1;                
        }
        if( !objectp( teacher = present( me->query("teacher"), environment(me) ) ) )
        {
        remove_call_out("waiting");
        call_out("waiting", 1, me, wait_time + 1);
        }
        else
        {
          message_vision(HIC+me->name()+"正已精疲力尽，见到援兵到来喜出望外，转身离开战场。\n"NOR,me);
          place=me->query("place");
          me->move(place);              
          message_vision(BLU"一个面色灰暗，满脸凶光的大汉一把拦住"+teacher->name()+"，说道：小和尚跑了，老的别想逃！\n"NOR,teacher);
          teacher->start_busy(3);
        }
        return 1;
}

varargs void add_skill(string skill, int amount, int weak_mode)
{
        int spi;

        if( !find_object(SKILL_D(skill))
        &&      file_size(SKILL_D(skill)+".lpc") < 0 )
                error("F_SKILL: No such skill (" + skill + ")\n");
        if( !weak_mode||userp(this_object()) ) {
                if( !mapp(skills) ) skills = ([]);
                if( undefinedp(skills[skill]) ) skills[skill] = 0;
        }
        spi = query("spi");
        if( sizeof(learned) > spi )
                amount /= sizeof(learned) - spi;

        if( !amount ) amount = 1;

        if( !mapp(learned) ) learned = ([ skill : amount ]);
        else (int)learned[skill] += amount;

        if( (!weak_mode||userp(this_object()))
        &&      learned[skill] > (skills[skill] + 1) * (skills[skill] + 1) ) {
                skills[skill]++;
                learned[skill] = 0;
                this_object()->set_skill(skill,skills[skill]+1);        
          }
}

void greeting(object ob)
{
   object me;
   me=this_object();  
   if( !ob || environment(ob) != environment() ) return;
   if (interactive(ob) &&
        (int)ob->query_condition("lh_job"))  
     say( me->name()+"说道；这位是来指点小僧的吗?\n");
}

