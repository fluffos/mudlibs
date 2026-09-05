// baby.c
inherit NPC;
void try_move();

void create()
{
        set_name("宝宝", ({"xiao baobao","baby"}) );
        set("gender", "男性");
        set("age", 10);
        set("attitude", "friendly");
        set("title","没人要的孩子");
        set("long","乖宝宝。\n");
        set("combat_exp",100);
        set("str",15);
        set("int",15);
        set("con",15);
        set("dex",15);
        set("per",20);
        set("kar",15);
        set("parents",({"dad","mom"}));
        set("father",({"dad"}));
        set("mother",({"mom"}));
        set("msg_lost","$N好象找不到它的爸妈啦，在那哭丧着脸！");
        set("msg_meet","$N找不到它的爸妈啦，在高兴着呢！");
        
        set("chat_chance", 2);
        set("chat_msg", ({
                (: random_move :)
                }));                   

        set("is_baby",1);
        // to allow the identification of baby. by mon.

        setup();
}

void init()
{
	object ob;
        ::init();
        if(!query_heart_beat())  set_heart_beat(1);
        command("get all");

        add_action("do_kill",({"kill","fight","steal"}));
        add_action("do_get","get");
        add_action("do_drop","drop");
        
        if(member_array(this_player()->query("id"),
          this_object()->query("parents"))>-1)
        {
          this_object()->set_leader(this_player());
        }
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 4, ob);
        }
        
        remove_call_out("try_move");
        call_out("try_move",1);
}

void greeting(object ob)
{
        object owner = find_player(query("mother"));
        object owner1 = find_player(query("father"));
        
        if( owner ) 
        {
        	set_leader(owner);
        };
                
        if( !owner ) 
        {
                if (owner1) set_leader(owner1);
       		else 
       		{
       		message_vision(query("msg_lost"),environment(this_object()), this_object());
                return;
       		}
        };
        
        if((!present(owner, environment())||!present(owner1, environment()))) 
        {
                random_move();
                return;
        };
        if( ob == query_leader() ) {
                message_vision(query("msg_meet"), this_object());
                return;
        }
}


void try_move()
{
    if(random(30)==0) {
        remove_call_out("random_move");
        call_out("random_move",10);
    }
}


int do_drop(string arg)
{
     object me=this_object(),who=this_player(),env;
     if(!arg) return 0;
     env = environment(who);
     if(present(arg,who)!=me) return 0;
     if(me->move(env)) {
       message_vision("$N把$n从怀里放了下来。\n",who,me);
       return 1;
     }
     return 0;
}

int do_get(string arg)
{    object me=this_object(),who=this_player(),env;
     
     if(!arg) return 0;
     env = environment(who);
     if(present(arg,env)!=me) return 0;
     
     if( who->query("id")!=me->query("mother")||who->query("id")!=me->query("father"))
      {
      	  if(me->move(who))
      	  {
     		  message_vision("$N弯下腰把$n抱了起来，搂在怀里。\n",who,me);
          }
     	 else  {
      	 message_vision("$N弯下腰一抱却没把$n抱起来，小家伙好沉哪！\n",who,me);
            }
     }
     else {
      message_vision("$N蹲下身朝$n伸开双手，$n却一下子闪开了．．．\n",who,me);
     }
     return 1;
}

int do_kill(string arg)
{       
        object me,who;
        string name,verb,what,obj;
        if (!arg) return 0;
        verb=query_verb();
        me=this_player();
        
        if(verb=="steal") {
          if(sscanf(arg, "%s from %s", what, obj)!=2 ) 
            return 0;
          }
        else obj=arg;

        if(!objectp(who=present(obj,environment(me))) 
           || !living(who)) return 0;
        if(who==this_object()) {
          switch(verb) {
            case "kill":
              tell_object(environment(this_object()),
                who->query("name")+"拼命地哭了起来：爹～～，娘～～，"+
                me->query("name")+"要杀我．．．快回来呀！\n");
              break;
            case "fight":
              tell_object(environment(this_object()),
                who->query("name")+"哭了起来：爹～～，娘～～，"+
                me->query("name")+"要抢我的糖吃．．．快回来呀！\n");
              break;
            case "steal":
              tell_object(environment(this_object()),
                who->query("name")+"哭了起来：爹～～，娘～～，"+
                me->query("name")+"要偷吃我的糖！\n");
              break;
          }
        }
//     command(verb); 暂时不然杀小孩
        return 0;
}

void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;

        switch(verb) {
        case "kick":
                command("say 爹～～，娘～～，"  + ob->query("name") + "踢我耶！");
                command("kick " + ob->query("id"));
                        break;
        case "slap":
                command("say 爹～～，娘～～，"  + ob->query("name") +
"打我耶，好痛啊～～～～");
                command("slap " + ob->query("id"));
                        break;
        case "hit":
                command("pain " + ob->query("id"));
                        break;
        case "bite":
                command("face " + ob->query("id"));
                        break;  
        case "papaya":
                command("pout");
                        break;  

                }
}

void relay_whisper(object me, string msg)
{        
        object who;
	me=this_player();
        if (who->query("id")!=me->query("mother") || who->query("id")!=me->query("father"))
        {
                message_vision((string)this_object()->query("name")
                        + "疑惑地看着$N。\n", me);
                return;
        }

        //note, do not allow the order contain "chat", "tell"...
        //may need disable more later...
        if( strsrch(msg, "chat") != -1 ||
            strsrch(msg, "wiz") != -1 ||
            strsrch(msg, "sys") != -1 ||
            strsrch(msg, "rumor") != -1 ||  
            strsrch(msg, "xkx") != -1 ||  
            strsrch(msg, "tell") != -1 ||
            strsrch(msg, "follow") != -1 ||
            strsrch(msg, "apprentice") != -1 ||
            strsrch(msg, "recruit") != -1 )
                return;

        if (msg)
        {
                remove_call_out ("relaying");
                call_out ("relaying", 1+random(3), msg);
        }
}

void relaying (string msg)
{//execute the order.
        command (msg);
}

string query_save_file()
{
        return BABY_DIR + query("owner_id")[0..0] + "/" + query("father")+"h"+query("mother");
}

