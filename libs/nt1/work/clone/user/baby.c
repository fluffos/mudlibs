// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit BABY;
inherit F_NOCLONE;  

void consider();
void provide(); 
mixed ask_father();
mixed ask_mother(); 
int check_legal_name(string name, int max_len);
 
int  is_baby(){ return 1; }


void create()
{
        set_name("宝宝", ({"xiao baobao", "baby"}) );
        set("long", "一个白白拚胖的乖宝宝，不知道是谁家的孩子。\n");        
        set("gender", "女性");
        set("age", 1);
        set("attitude", "friendly");
        set("no_clean_up", 1); 
        set("env/halt_age", 1); 
        set("combat_exp", 10000);

        setup();
        carry_object("/clone/cloth/cloth")->wear();
        
        remove_call_out("check_me");
        call_out("check_me", 2, this_object());
}

void check_me(object me)
{
        if (me && ! mapp(me->query("parents")))
                destruct(me);
        return;
}

int load_baby(object me)
{   
        string file, info, name, id;   

        if (! userp(me)) return 0;

        if (me->query("gender") == "女性")
                file = "/data/baby/" + me->query("id") + ".o";
        else 
        if (me->query("couple/id"))
                file = "/data/baby/" + me->query("couple/id") + ".o";

        if (stringp(read_file(file)))
        {
                restore_object(file);
                reset_action();

                    /*
                set("max_neili", query_skill("force") * 20 + query("combat_exp") / 1000);
                set("neili", query("max_neili"));
                set("max_jingli", query_skill("magic") * 10 + query_skill("taoism") * 10 + query("combat_exp") / 3000); 
                set("jingli", query("max_jingli"));
                    */
                set("max_qi", 150 + query("max_neili") / 2 + query("age") * query("con"));
                set("eff_qi", query("max_qi"));
                set("qi", query("max_qi"));
                set("max_jing", 100 + query("max_jingli") / 3 + query("age") * query("con"));
                set("eff_jing", query("max_jing"));
                set("jing", query("max_jing"));
                set_name(query("name"), ({query("id"), "baby"})); 

                set("chat_chance", query("int") / 10);
                set("chat_chance_combat", query("con") / 5 * 10); 

                set("chat_msg", ({
                        (: consider :),
                        (: provide :), 
                }));
                
                set("inquiry", ([ 
                        "父亲" : (: ask_father :), 
                        "爹爹" : (: ask_father :), 
                        "爸爸" : (: ask_father :), 
                        "母亲" : (: ask_mother :), 
                        "妈妈" : (: ask_mother :), 
                ]));
                
                set("perform_skills", 0); 

                setup();

                UPDATE_D->check_user(this_object());
                remove_call_out("consider");
                call_out("consider", 10);
        } else 
                return 0;
} 

void init()
{
        add_action("do_kill", ({"kill", "fight", "hit", "steal"}));
        add_action("do_get", "get");
        add_action("do_drop", "drop");
        add_action("do_home", "home_baby");   
        add_action("do_nick", "nick_baby"); 
        add_action("do_changename", "name_baby");   
}

int do_nick(string arg)
{
        object ob = this_object();       
        object me = this_player();        
        
        if (query("parents/father") != me->query("id") &&
            query("parents/mother") != me->query("id"))
                return notify_fail("看清楚了，他可不是你的孩子！\n");
                
        if (! arg)
                return notify_fail("你要替孩子取什么绰号？\n");

        if (arg == "none")
        {
                ob->delete("nickname");
                write("你的孩子绰号取消了。\n");
                ob->save();
                return 1;
        }

        if (strlen(arg) > 80)
                return notify_fail("你为孩子取的绰号占用的资源过多，请重新设置。\n");

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);

        if (strlen(filter_color(arg)) > 30)
                return notify_fail("你为孩子取的绰号太长了，想一个短一点的、响亮一点的。\n");

        ob->set("nickname", arg + NOR);
        ob->save();
        write("你为孩子取好了绰号。\n");
        return 1;
}

int do_changename(string arg)
{
        object ob = this_object();  
        object me = this_player();   
        string  arg_old;                  
        
        if (query("parents/father") != me->query("id") &&
            query("parents/mother") != me->query("id"))
                return notify_fail("看清楚了，他可不是你的孩子！\n");
                
        if (! arg)
                return notify_fail("你要替孩子取什么名字？\n");  
                 
        arg_old = arg; 

        arg = replace_string(arg, "$BLK$", "");
        arg = replace_string(arg, "$RED$", "");
        arg = replace_string(arg, "$GRN$", "");
        arg = replace_string(arg, "$YEL$", "");
        arg = replace_string(arg, "$BLU$", "");
        arg = replace_string(arg, "$MAG$", "");
        arg = replace_string(arg, "$CYN$", "");
        arg = replace_string(arg, "$WHT$", "");
        arg = replace_string(arg, "$HIR$", "");
        arg = replace_string(arg, "$HIG$", "");
        arg = replace_string(arg, "$HIY$", "");
        arg = replace_string(arg, "$HIB$", "");
        arg = replace_string(arg, "$HIM$", "");
        arg = replace_string(arg, "$HIC$", "");
        arg = replace_string(arg, "$HIW$", "");
        arg = replace_string(arg, "$NOR$", "");
                                
        if (! check_legal_name(arg, 8))  
                return notify_fail("请重新设定你的孩子名字！\n");
        
        arg = arg_old;

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
                
        ob->set("name", arg + NOR);
        ob->save();
        write("你为孩子取好了姓名。\n");
        return 1;
}

int check_legal_name(string name, int max_len)
{
        int i;
        string  *legalname;             //not implemented..may add later
        
        i = strlen(name);
        if ((strlen(name) < 4) || (strlen(name) > max_len )) 
        {
                write(sprintf("对不起，姓名必须是 2 到 %d 个中文字。\n",
                      max_len / 2));
                return 0;
        }
        
        if (max_len < 13 && strsrch(NAME_D->who_is(name), "泥") >= 0)
        {
                write("对不起，孩子的名字不能和玩家的名字重复。\n"); 
                return 0;
        }

        if (max_len < 13 && ! is_chinese(name))
        {
                write("对不起，请您用「中文」为孩子取名字或描述。\n");
                return 0;
        }
        return 1; 
}

int do_home(string arg)
{
        object me = this_object(), who = this_player();

        if (! arg) return 0;
        if (! this_object()->id(arg)) return 0;

        if (who->query("id") == query("parents/father")
        ||  who->query("id") == query("parents/mother"))
        {                           
                message_vision("$N对着$n轻声说道：现在我有些事情，你先回家去吧。\n", who, me);
                me->save();
                destruct(me);
                return 1;
        } else
                command("say 你是谁啊，为什么要听你的话？\n");
        return 1;
}

int do_drop(string arg)
{
        object me = this_object(), who = this_player();
        
        if (! arg || ! this_object()->id(arg)) return 0;
        
        if (! present(me->query("id"), who))
                return notify_fail("你身上没有这个孩子。\n"); 

        if (me->move(environment(who)))
        {
                message_vision("$N把$n从怀里放了下来。\n", who, me);
                return 1;
        }
        return 0;
}

int do_get(string arg)
{
        object  me = this_object(), who = this_player();
        object  ob1, ob2;
        string  fid, mid;
        mapping bro;
        string *ids;

        if (! arg) return 0;
        if (! this_object()->id(arg)) return 0;   

        if (environment(me) != environment(who))
                return notify_fail("这里没有这个孩子。\n"); 

        fid = me->query("parents/father");
        mid = me->query("parents/mother");
        
        ob1 = UPDATE_D->global_find_player(fid);
        ob2 = UPDATE_D->global_find_player(mid);

        if (who->query("id") == fid
        ||  who->query("id") == mid)
        {
                if (query("age") < 15 && me->move(who))
                {
                        message_vision("$N弯下腰把$n抱了起来，搂在怀里。\n", who, me);
                }
                else
                {
                        message_vision("$N弯下腰一抱却没把$n抱起来，小家伙好沉哪！\n", who, me);
                }
        } else        
        if (mapp(bro = ob1->query("brothers")) && sizeof(bro) > 0) 
        {
                ids = keys(bro);
                if (member_array(who->query("id"), ids) != -1)
                {
                        if (query("age") < 15 && me->move(who))
                        {
                                message_vision("$N弯下腰把$n抱了起来，搂在怀里。\n", who, me);
                        }
                        else
                        {
                                message_vision("$N弯下腰一抱却没把$n抱起来，小家伙好沉哪！\n", who, me);
                        }  
                }                      
        } else        
        if (mapp(bro = ob2->query("brothers")) && sizeof(bro) > 0) 
        {
                ids = keys(bro);
                
                if (member_array(who->query("id"), ids) != -1)
                {
                        if (query("age") < 15 && me->move(who))
                        {
                                message_vision("$N弯下腰把$n抱了起来，搂在怀里。\n", who, me);
                        }
                        else
                        {
                                message_vision("$N弯下腰一抱却没把$n抱起来，小家伙好沉哪！\n", who, me);
                        } 
                } 
        }  
        else
        {
                message_vision("$N蹲下身朝$n伸开双手，$n却一下子闪开了．．．\n",who,me);
        }
                     
        UPDATE_D->global_destruct_player(ob1, 1); 
        UPDATE_D->global_destruct_player(ob2, 1); 
                
        return 1;
}

int do_kill(string arg)
{       
        object me, who;
        string name, verb, what, obj;
        
        if (! arg) return 0;
        
        verb = query_verb();
        me = this_player();
   
        if (verb == "steal")
        {
                if (sscanf(arg, "%s from %s", what, obj) != 2) 
                        return 0;
        }
        else obj = arg;

        if (! objectp(who = present(obj, environment(me))) 
        ||  ! living(who)) 
                return 0;
                
        if (who == this_object())
        {
                switch(verb)
                {
                case "kill":
                        // command("chat* " +
                        tell_object(environment(this_object()),
                                    who->query("name") + "拼命地哭了起来：爹～～，娘～～，" +
                                    me->query("name") + "要杀我．．．快回来呀！\n");
                        break;
                case "hit":
                        //  command("chat* " +
                        tell_object(environment(this_object()),
                                    who->query("name") + "大哭了起来：爹～～，娘～～，" +
                                    me->query("name") + "欺负我．．．快回来呀！\n");
                        break;
                case "fight":
                        // command("chat* " +
                        tell_object(environment(this_object()),
                                    who->query("name") + "哭了起来：爹～～，娘～～，" +
                                    me->query("name") + "要抢我的糖吃．．．快回来呀！\n");
                        break;
                case "steal":
                        // command("chat* " +
                        tell_object(environment(this_object()),
                                    who->query("name") + "哭了起来：爹～～，娘～～，" +
                                    me->query("name") + "要偷吃我的糖！\n");
                        break;
                case "beg":
                        // command("chat* " +
                        tell_object(environment(this_object()),
                                    who->query("name") + "小嘴一歪哭了起来：爹～～，娘～～，" +
                                    me->query("name") + "要骗我的糖吃！\n");
                        break;
                }
        }
        command(verb);
        return 0;
}

void relay_emote(object ob, string verb)
{
        if (! userp(ob)) return;

        switch(verb)
        {
        case "kick":
                command("say 爹～～，娘～～，"  + ob->query("name") + "踢我耶！");
                command("kick " + ob->query("id"));
                 break;
        case "slap":
                command("say 爹～～，娘～～，"  + ob->query("name") + "打我耶，好痛啊～～～～");
                command("slap " + ob->query("id"));
                break;
        case "hit":
                command("pain " + ob->query("id"));
                break;
        case "bite":
                command("face " + ob->query("id"));
                break;  
        case "papaya":
                command("angry");
                break;  
        }
}

void relay_whisper(object me, string msg)
{
        if (me->query("id") != query("parents/father")
        &&  me->query("id") != query("parents/mother"))
        {
                message_vision((string)this_object()->query("name") + "疑惑地看着$N。\n", me);
                return;
        }

        /*
        // note, do not allow the order contain "chat", "tell"...
        // may need disable more later...
        if (strsrch(msg, "chat") != -1 ||
            strsrch(msg, "tell") != -1 ||
            strsrch(msg, "sos")  != -1 ||
            strsrch(msg, "recruit") != -1)
                return;
        */

        if (msg)
        {
                remove_call_out ("relaying");
                call_out ("relaying", random(2), msg);
        }
}

void relaying (string msg)
{
        // execute the order.
        if (command(msg)) 
                return;
        else 
                command("say 好象不行呀。。。\n");
        return;        

}

mixed ask_father()
{
        object me, ob;
        string id, name;
        
        me = this_object();
        
        id = me->query("parents/father");
        ob = UPDATE_D->global_find_player(id); 
        
        if (! objectp(ob))
                return notify_fail(me->name() + "露出痛苦的表情道：“家父已经去世了，你问家父有何贵干？！”\n");
                
        name = ob->query("name");
        command("say 我的父亲是个顶天立地的大英雄，" + name + "(" + id + ")就是他的尊号，你听说过他吗？");
        UPDATE_D->global_destruct_player(ob, 1); 
        return 1;
}
        
mixed ask_mother()
{
        object me, ob;
        string id, name;
        
        me = this_object();
        
        id = me->query("parents/mother");
        ob = UPDATE_D->global_find_player(id); 
        
        if (! objectp(ob))
                return notify_fail(me->name() + "露出痛苦的表情道：“家母已经去世了，你问家母有何贵干？！”\n");
                
        name = ob->query("name");
        command("say 我的母亲是武林第一美女，" + name + "(" + id + ")就是他的尊号，你听说过她吗？");
        UPDATE_D->global_destruct_player(ob, 1); 
        return 1;
}

int accept_ask(object who, string topic) 
{
        object  ob, ob1, ob2, me = this_object();
        string  fid, mid, name, fname, mname;
        mapping bro;
        string *ids;
        string  id; 
        
        fid = me->query("parents/father");
        mid = me->query("parents/mother");
        
        ob1 = UPDATE_D->global_find_player(fid);
        fname = ob1->query("name");
        
        if (mapp(bro = ob1->query("brothers")) && sizeof(bro) > 0) 
        {
                ids = keys(bro);
                
                foreach (id in ids)
                {
                        ob = UPDATE_D->global_find_player(id);
                        name = ob->query("name");
                        if (topic == id || topic == name)
                        {
                                if (ob->query("gender") == "男性")
                                {
                                        if (ob->query("mud_age") > ob1->query("mud_age"))
                                                command("say 那是家父的结义兄长，也就是我的伯父。");
                                        else
                                                command("say 那是家父的义弟，也就是我的叔叔。");

                                } else
                                {
                                        if (ob->query("mud_age") > ob1->query("mud_age"))
                                                command("say 那是家父的义姐，也就是我的大姑。");
                                        else
                                                command("say 那是家父的结义妹子，也就是我的小姑。");                                            
                                }
                                UPDATE_D->global_destruct_player(ob, 1);
                                UPDATE_D->global_destruct_player(ob1, 1); 
                                return 1;                                   
                        }
                        UPDATE_D->global_destruct_player(ob, 1);
                }
        }                                                
                       
        UPDATE_D->global_destruct_player(ob1, 1); 
         
        ob2 = UPDATE_D->global_find_player(mid);
        mname = ob2->query("name");
        
        if (mapp(bro = ob2->query("brothers")) && sizeof(bro) > 0) 
        {
                ids = keys(bro);
                
                foreach (id in ids)
                {
                        ob = UPDATE_D->global_find_player(id);
                        name = ob->query("name");
                        if (topic == id || topic == name)
                        {
                                if (ob->query("gender") == "男性")
                                {
                                        if (ob->query("mud_age") > ob1->query("mud_age"))
                                                command("say 那是家母的结义兄长，也就是我的大舅。");
                                        else
                                                command("say 那是家母的义弟，也就是我的小舅。");

                                } else
                                {
                                        if (ob->query("mud_age") > ob1->query("mud_age"))
                                                command("say 那是家母的义姐，也就是我的大姨。");
                                        else
                                                command("say 那是家母的结义妹子，也就是我的小姨。");                                            
                                }
                                UPDATE_D->global_destruct_player(ob, 1);
                                UPDATE_D->global_destruct_player(ob2, 1); 
                                return 1;                                   
                        }                        
                        UPDATE_D->global_destruct_player(ob, 1);
                }
        }  
                     
        UPDATE_D->global_destruct_player(ob2, 1); 
        
        if (topic == fid || topic == fname)
        {
                if (who->query("id") == me->query("parents/father") ||
                    who->query("id") == me->query("parents/mother"))
                        command("say 那是父亲大人的名讳啊，孩儿怎敢忘！");
                else
                        command("say 那是家父的名讳，你认识家父吗？");
                return 1;
        }

        if (topic == mid || topic == mname)
        {
                if (who->query("id") == me->query("parents/father") ||
                    who->query("id") == me->query("parents/mother"))
                        command("say 那是母亲大人的名讳啊，孩儿怎敢忘！");
                else
                        command("say 那是家母的名讳，你认识家母吗？");
                return 1;
        }
                                
        switch (topic) 
        {
        case "叫爹爹" : 
        case "叫爸爸" : 
                if (who->query("id") == me->query("parents/father"))
                        command("say 父亲大人好！");
                else
                        command("say 想占我便宜，门都没有！");
                return 1;
                      
        case "叫母亲" : 
        case "叫妈妈" : 
                if (who->query("id") == me->query("parents/mother"))
                {
                        command("say 母亲大人吉祥！");
                        command("cat " + who->query("id"));
                }
                else
                        command("say 想占我便宜，门都没有！");
                return 1;
        
        case "叫叔叔" :
                if (who->query("gender") != "男性")
                        command("say 你不是男人，我怎么能叫你叔叔呢？");
                else
                        command("say 叔叔好！");
                return 1;
        case "叫阿姨" : 
                if (who->query("gender") != "女性")
                        command("say 你不是女人，我怎么能叫你阿姨呢？");
                else
                        command("say 阿姨吉祥！");
                return 1;
        case "叫姑姑" : 
                if (who->query("gender") != "女性")
                        command("say 你不是女人，我怎么能叫你姑姑呢？");
                else
                        command("say 姑姑吉祥！");
                return 1;                
        default: 
                return 0;
        }
}
                       
void consider()
{
        string *basic = ({ "force", "dodge", "unarmed", "cuff", "strike", "finger",
                           "hand", "claw", "sword", "blade", "staff", "hammer", 
                           "club", "whip", "dagger", "throwing", "parry", "magic",
                           "medical", "poison", "chuixiao-jifa", "tanqin-jifa",
                           "guzheng-jifa", "cooking",
        });       
        string skill;
        string *chat_chance_combat_here = ({(: exert_function, "powerup" :)}), *my_skill,
               *basic_skill = ({}), *use_skill = ({}), dir;
        mapping skills;
        int i, j, k;
        mixed *file;
        object me = this_object();
        
        if (! environment())  
                return;   
        skills = me->query_skills();        
        if (sizeof(skills) && sizeof(skills) > query("skills_learned"))
        {
                my_skill = keys(skills);
                for (i = 0; i < sizeof(basic); i++)
                        if (member_array(basic[i], my_skill) != -1)
                                basic_skill += ({basic[i]});

                for (i = 0; i < sizeof(my_skill); i++)   
                        if (SKILL_D(my_skill[i])->type() != "knowledge" 
                        &&  member_array(my_skill[i], basic) == -1)
                                use_skill += ({my_skill[i]});                               

                for (i = 0; i < sizeof(basic_skill); i++)
                for (j = 0; j < sizeof(use_skill); j++)
                if (SKILL_D(use_skill[j])->valid_enable(basic_skill[i]) 
                &&  ! stringp(query_skill_mapped(basic_skill[i])))
                {
                        map_skill(basic_skill[i], use_skill[j]);
                        if (sizeof(me->query_skill_prepare()) < 2)
                        if (basic_skill[i] == "finger" 
                        ||  basic_skill[i] == "strike" 
                        ||  basic_skill[i] == "hand" 
                        ||  basic_skill[i] == "cuff" 
                        ||  basic_skill[i] == "claw" 
                        ||  basic_skill[i] == "unarmed")
                                prepare_skill(basic_skill[i], use_skill[j]);
                                                
                } else 
                        continue;
                                
                if (sizeof(skills) > query("skills_learned"))
                        set("perform_skills", 0);
                                
                if (! query("perform_skills"));  
                {
                        for (i = 0; i < sizeof(basic_skill); i++)
                        if (basic_skill[i] != "magic" && basic_skill[i] != "medical"
                        &&  basic_skill[i] != "cooking"
                        &&  stringp(query_skill_mapped(basic_skill[i])))
                        {
                                dir = "/kungfu/skill/" + query_skill_mapped(basic_skill[i]) + "/";
                                if (SKILL_D(query_skill_mapped(basic_skill[i]))->valid_enable("force"))
                                        dir += "perform/";
                                if (file_size(dir) != -2)
                                        continue;
                                file = get_dir(dir, -1);
                                if (! sizeof(file))
                                        continue;

                                for (k = 0; k < sizeof(file); k++)
                                {
                                        if (file[k][0][strlen(file[k][0])-2..strlen(file[k][0])] != ".c")
                                                        continue;
                                        file[k][0] = replace_string(file[k][0], ".c", "");
                                        chat_chance_combat_here += 
                                                ({( : perform_action, basic_skill[i] + "." + file[k][0]: )}); 
                                }
                        } else 
                                continue;     

                        set("chat_msg_combat", chat_chance_combat_here);                        
                        set("perform_skills", 1); 
                }

                set("chat_msg_combat", chat_chance_combat_here);
                reset_action();
                set("skills_learned", sizeof(skills));  
                command("say 嘻嘻，我知道了，我会用了！\n");  
        }

        set("jiali", query_skill("force") / 2 + 10);
        save();

        command("say 嘻嘻，都记住了，可以了！\n");
        return;
}

int accept_object(object who, object ob)
{
        if (who->query("id") == query("parents/father")
        ||  who->query("id") == query("parents/mother"))
        {
                remove_call_out("provide");
                call_out("provide", 1);
                return 1;
        } else 
                return 0;
}

void provide()
{
        object *ilist, ob;
        object weapon, armor;
        int i;
        
        if (! environment()) return;
        ilist = all_inventory(this_object());
        if (sizeof(ilist) < 1) return;

        for (i = 0; i < sizeof(ilist); i++)
        {
                ob = ilist[i];
                if (ob->query("weapon_prop/damage"))
                {
                        if (objectp(weapon = query_temp("weapon")) && weapon != ob 
                        &&  ob->query("weapon_prop/damage") > 
                            weapon->query("weapon_prop/damage"))
                                weapon->unequip();
                        command("wield " + ob->query("id"));
                }

                if (ob->query("armor_prop/armor"))
                { 
                        if (objectp(armor = query_temp("armor/" + ob->query("armor_type")))
                        &&  armor != ob 
                        &&  ob->query("armor_prop/armor") > 
                            armor->query("armor_prop/armor"))
                                armor->unequip();
                        command("wear " + ob->query("id")); 
                }    

                if (ob->query("food_remaining"))
                        command("eat " + ob->query("id"));
                else 
                if (ob->query("liquid/remaining"))
                        command("drink " + ob->query("id"));
        }

        set("jiali", query_skill("force") / 2 + 10);   

        command("sweat");
        return;
}


