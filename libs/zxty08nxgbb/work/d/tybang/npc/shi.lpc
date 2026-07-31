// write By zjb@TY

inherit NPC;
inherit F_SAVE;
string query_save_file()
{
    return "/data/npc/tyshi";
}

void create()
{
    seteuid(getuid());
    if (!restore()) {
    set_name(HIC"天涯使者"NOR, ({ "ty shizhe", "shizhe", "shi" }) );
    set("title", HIR"天涯第一城"NOR );
    set("gender", "男性" );
    set("age", 35);
    set("long","他就是天涯第一城的天涯使者，负责教授帮内弟子武功。\n");
    set("attitude", "heroism");
    set("generation",0);
    set("shizhe","NONE");
    set("shen_type", 0);
    set("no_clean_up",1);
    set("combat_exp", 400000);
    set("my_weapon", "/d/shaolin/obj/changjian");
    set("my_armor", "/d/city/obj/cloth");
    setup();
    carry_object("/d/shaolin/obj/changjian")->wield();
    carry_object("/d/city/obj/cloth")->wear();        
    }
    else {
        set("id", "ty shizhe");
        set_name(query("name"), ({ "ty shizhe", "shizhe", "shi" }));
        set("startroom","/d/tybang/guangchang");
        set("no_get",1);
        set("neili",query("max_neili")*2);        
        setup();
      UPDATE_D->check_user(this_object());
    }
        set("no_suck",1);    
}
void init()
{
    add_action("do_recopy", "recopy");
    add_action("do_xuexi",  "xuexi");
    add_action("do_skills", "skills");
    add_action("do_skills", "cha");    
}
int do_recopy()
{
    object me, ob, newob, lp;
    mapping skill_status;
    string *sname;
    int i;

    me = this_object();
    ob = this_player();
    lp=new("/clone/misc/lingpai");
    lp->create("天涯第一城");
   
    if( lp->query("tybanghui") != ob->query("banghui") ) {
          destruct(lp);
          return notify_fail("对不起您好象不是我们帮派的人吧？\n");
    }
          
    if (lp->query("bangzhu_id")!=ob->query("id") && !lp->query("recopy/"+ob->query("id"))) {
          destruct(lp);
          return notify_fail("您没有使用这个指令的权利。\n");
    }

    destruct(lp);
    
    if (!living(me))    me->revive();

    if ( mapp(skill_status = ob->query_skills()) ) {
        skill_status = ob->query_skills();
        sname  = keys(skill_status);
        for(i=0; i<sizeof(skill_status); i++) {
            me->set_skill(sname[i], skill_status[sname[i]]);
        }
    }

    me->set("title", ob->query("tybang/banghui") );
    me->save();
    tell_object(ob, "状态储存完毕。\n");
    newob = new("/d/tybang/npc/shi");
    newob->move("/d/tybang/guangchang");
    destruct(me);
    return 1;
}
int do_xuexi(string arg)
{
        string skill, teacher, master, skill_name, bh;
        object ob, me, lp;
        int master_skill, my_skill, jing_cost, grade, times;
        int pertimes, my_combat_exp, dj = this_player()->query("zjb_dj/dj");
        
        me = this_player();
        lp = new("/clone/misc/lingpai");        
        bh = "天涯第一城";                
        lp->create(bh);

        if( lp->query("tybanghui") != me->query("banghui") ) {
                destruct(lp);
                return notify_fail("对不起您好象不是我们帮派的人吧？\n");
        }
        destruct(lp);        
        
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if(!arg || (sscanf(arg, "%s %s %d", teacher, skill, times)!=3 ))
                return notify_fail("指令格式：xuexi <某人> <技能> <次数>\n");

        if (times < 1 || times > 400)
                return notify_fail("学习次数最少一次，最多也不能超过四百次。\n");

        if( me->is_fighting() )
                return notify_fail("临阵磨枪？来不及啦。\n");

        if( !(ob = present(teacher, environment(me))) || !ob->is_character())
                return notify_fail("你要向谁求教？\n");

        if( me->query("tybang/gxd") < 1 )       
                return notify_fail("您的帮派贡献度不够了，无法学习！\n");

        if( !living(ob) )
                return notify_fail("嗯....你得先把" + ob->name() + "弄醒再说。\n");

        if( !master_skill = ob->query_skill(skill, 1) )
                return notify_fail("这项技能你恐怕必须找别人学了。\n");
 
        if( lp->query("tybanghui") != me->query("banghui") ) {
                destruct(lp);
                return notify_fail("对不起您好象不是我们帮派的人吧？\n");
        }
                
        if( ob->query("id") != query("id") )
                return notify_fail("您好象不能跟他学习吧？\n");
         
        my_skill = me->query_skill(skill, 1);

        if( my_skill >= master_skill )
                return notify_fail("这项技能你的程度已经不输你师父了。\n");
      
        if( !SKILL_D(skill)->valid_learn(me) ) return 0;

        jing_cost = 150 / (int)me->query("int");

        if( !my_skill ) {
                jing_cost *= 2;
                me->set_skill(skill,0);
        }

        if( (me->query("potential") - me->query("learned_points")) < times*2 )
                return notify_fail("你的潜能不够学习这么多次了。\n");
                
        printf(HIC"你向%s请教了"+chinese_number(times)+"句有关「%s」的问。\n"NOR,
                ob->name(), to_chinese(skill));

        tell_object(ob, sprintf("%s向你请教有关「%s」的问题。\n",
                me->name(), to_chinese(skill)));

        if( (int)ob->query("jing") > jing_cost*times/5 + 1 )
        {
                if( userp(ob) ) ob->receive_damage("jing", jing_cost/5 + 1);
        } else
        {
                write("但是" + ob->name() + "显然太累了，没有办法教你什麽。\n");
                tell_object(ob, "但是你太累了，没有办法教" + me->name() + "。\n");
                return 1;
        } 

// 判断等级学skill的经验限制 By zjb
        my_combat_exp = me->query_exp();
        grade = 11;

        if( (int)me->query("jing") > jing_cost * times )
        {

                if ( my_skill < 12500 ) {
                if ( (string)SKILL_D(skill)->type()!="knowledge"
                && (my_skill/10) * (my_skill/10) * (my_skill/10) > my_combat_exp )
                        return notify_fail("也许是缺乏实战经验，你对"+ob->name()+"的回答总是无法领会。\n");
                }
                else {
                if ( (string)SKILL_D(skill)->type()!="knowledge"
                && (my_skill/100) * (my_skill/100) * (my_skill/100) > my_combat_exp/1000 )
                        return notify_fail("也许是缺乏实战经验，你对"+ob->name()+"的回答总是无法领会。\n");
                }

                        if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
                                printf("你听了%s的指导，对「%s」这一招似乎有些心得。\n", ob->name(), skill_name);
                        else
                                printf("你听了%s的指导，似乎有些心得。\n", ob->name());
                        for (pertimes = 1; pertimes <= times ; pertimes ++) 
                        me->improve_skill(skill, (grade * (10 + random((int)me->query_int() - 9)*3)));
                        me->add("learned_points", times*2);
        } else
        {
                if (jing_cost > me->query("jing"))
                jing_cost = me->query("jing");
                return notify_fail("你今天太累了，结果什么也没有学到。\n");
        }
        me->add("tybang/gxd",-1);
        me->receive_damage("jing", jing_cost * times );
        me->start_busy(1);
        return 1;
}
int do_skills(string arg)
{
        object me, ob;
        mapping skl, lrn, map;
        string *sname, *mapped, str;
        int i,j;
        
        me = this_player();
        ob = this_object();
        str = "";

        seteuid(getuid());

        if( arg != "shizhe" && arg != "ty shizhe" && arg != "shi" )
            return 0;
         
        skl = ob->query_skills();
        j = (int)sizeof(skl);
        if(!sizeof(skl)) {
                write( ob->name() + "目前并没有学会任何技能。\n");
                return 1;
        }
        write( ob->name() + "目前所学过的技能有：\n"NOR);

        str = "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";
        sname  = sort_array( keys(skl), (: strcmp :) );

        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);

        for(i=0; i<sizeof(skl); i++) {
                str = sprintf("%s%s%s%-40s" NOR " -  %3d/%5d\n", str,
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": "□"),
                        to_chinese(sname[i]) + " (" + sname[i] + ")",
                        skl[sname[i]], (int)lrn[sname[i]],
                );
        }
        str += "\n━━━━━━━━━━━━━━━━━━━━━"HIW"TY"NOR"━━━━━━━━━━\n";
        str += "                                             "HIG"目前共会 "+HIY""+ chinese_number(j) + ""HIG" 种技能" NOR;
        me->start_more(str);

        return 1;
}
void unconcious()
{
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));
        set("jingli", query("eff_jingli"));
        say( "星空突然出现在你的面前，说道你怎么可以杀死我的手下呢 ？！\n");
      }

void die()
{
        unconcious();
}

