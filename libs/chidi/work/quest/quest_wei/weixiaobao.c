inherit BHNPC;
#include <ansi.h>;
int time_period(int timep,object me);
void create()
{
        set_name("Î¤Ð¡±¦", ({ "wei xiaobao","wei","xiaobao" }));
        set("title", HIC"´óÇå¹ú¸§Ô¶´ó½«¾ü"HIY"Ò»µÈÂ¹¶¦¹«"NOR);
        set("nickname",HIW"Ð¡°×Áú"NOR);
        set("gender", "ÄÐÐÔ");
        set("age", 24);
        set("str", 50);
        set("int", 50);
        set("con", 50);
        set("dex", 50);
        set("per", 50);
        set("long", 
"[33mËû¿ÉÊÇ¿µÎõÉíÅÔµÄ´óºìÈËÅ¶£¬ÕâÎ»ÉÙÄêÍ·´÷ºì¶¥×Ó£¬Éí´©»ÆÂí
¹Ó£¬Ã¼»¨ÑÛÐ¦£¬Ôôß¯ÙâÙâ¡£Ëû¿ÉÔøÊÇÌìµØ»áÇàÄ¾ÌÃÏãÖ÷£¬ÉñÁú
µºµÄ°×ÁúÊ¹£¬ÕÆ¹Ü°×ÁúÁî£¬Ò²ÊÇÂÞÉ²¹úµÄ¾ôÒ¯¡£ÕâÈËÊÇºÜ½²Òå
ÆøµÄ£¬¿É¾ÍÊÇ°®Ë£ÐÄÑÛ¡¢¸£´óÃü´ó£¬Ò»¹²È¢ÁËÆß¸öÀÏÆÅÄØ¡£½­
ºþÉÏÈË³Æ[2;37;0m¡¸[1;31m¡®ÎÞËù²»Öª ÎÞËù²»Ïþ¡¯[1;37mÐ¡°×Áú [2;37;0m¡¹[33m¡£[2;37;0m\n");
        set("combat_exp", 9000000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set("max_qi", 15000);
        set("qi", 15000);
        set("max_jing", 12000);
        set("jing", 12000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 70);
        set("score", 200000);

        set_skill("force", 50);
        set_skill("parry", 50);
        set_skill("hand", 50);
        set_skill("dodge", 150);
        set_skill("shenxing-baibian", 150);
        set_skill("yunlong-shengong", 50);
        set_skill("qianye-shou", 90);

        map_skill("force", "yunlong-shengong");
        map_skill("parry", "qianye-shou");
        map_skill("dodge", "shenxing-baibian");
        map_skill("hand", "qianye-shou");
        prepare_skill("hand", "qianye-shou");
        set("inquiry", ([
            "°ïÖú"    : "ÎÒ¿ÉÒÔ¸æËßÄã¼¸¸öÃÅÅÉµÄ·½Ïò¡£ÇëÎÊ£ºÄ½ÈÝ£¬ÈÕÔÂ£¬É±ÊÖ£¬ä½»¨£¬ÍòÃ·,À¥ÂØ¡£\n",
            "Ä½ÈÝ"    : "¹ÃËÕÄ½ÈÝÑ½£¬ÔÚÌ©É½ÒÔ¶«£¬Ì«ºþÄÇÀï×ø´¬È¥¡£\n",
            "ÈÕÔÂ"    : "ÈÕÔÂÉñ½Ì£¿ºÃÏóÊÇÔÚÈªÖÝÄÇ±ß¡£\n",
            "É±ÊÖ"    : "É±ÊÖÂ¥!£¬É±ÊÖÂ¥!£¬ºÇºÇ£¬È¥ÄÏÃÅ¸½½üÕÒÕÒ£¿\n",
            "ä½»¨"    : "Õâ¸ö£¬ºÙºÙ£¡ÎÒ¼Ç²»Çå³þÁË£¬¾Í¼ÇµÃÊÇÔÚÈÕÔÂºóÃæµÄ¹ÈÖÐ¡£\n",
            "ÍòÃ·"    : "Î÷ÃÅ´µÑ©µÄÍòÃ·É½×¯£¬ÎÒÖªµÀ£¬¾ÍÊÇ´Ó¾©³ÇµÄÎ÷ÃÅÒ»Ö±³¯Î÷×ß¡£\n",
            "À¥ÂØ"    : "Äã»¹ÊÇÈ¥ÌìÉ½½ÅÏÂ¿´¿´È¥°É¡£\n",
            "ÐÛ°ÔÌìÏÂ"  : "ÄãÄÌÄÌµÄÁ¬ÐÛ°ÔÌìÏÂ¶¼²»ÖªµÀ£¬»¹»ì¸öÊ²Ã´Ñ½£¡\n",
            "ÌìµØ»á"  : "ÄãÄÌÄÌµÄ·³²»·³Ñ½£¡\n",
            "³Â½üÄÏ"  : "ÄÇÊÇÎÒÄÐÊ¦¸¸£¡\n",
            "Ã©Ê®°Ë"  : "¾ÍÊÇÄÇ¸öËÀÅÖ×ÓÑ½£¡Ëû»¹Ã»ËÀ°É£¡\n",
            "¶À±ÛÉñÄá": "ÄÇÊÇÎÒµÄÅ®Ê¦¸¸£¡Ëý¿ÉÊÇºÜÓÐÀ´Í·µÄÅ¶¡£\n",
            "Î¤´º·¼"  : "ÎÒÄïÏÖÔÚÒªºÃºÃÏíÏó¸£ÁË£¬ÏÖÔÚËýÒÑ¾­ÊÇ¼ËÔºµÄÀÏ°åÄïÁË£¡\n",
            "Î¤Ð¡±¦"  : "ÄãÄÌÄÌµÄË£ÎÒÑ½£¬ÕÒËÀÑ½Äã£¡¹ö£¡\n",
            "¿µÎõ"    : "ÄÇÊÇÎÒ»ÊµÛÊ¦¸¸£¡\n",
            "Ð¡Ðþ×Ó"  : "Ëû¿ÉÊÇÎÒµÄºÃÅóÓÑ£¬µ«ÊÇÉí·ÝÌØ³ö£¬ÄãÎÊËû×öÊ²÷á£¿£¡\n",
            "Ð¡¹ð×Ó"  : "±ðÌáÕâ¸öÃû×ÖÁË£¬ÎÒÅÂ£¡\n",
            "°¢çæ"    : "ËýÊÇÎÒÃ÷Ã½ÕýÈ¢µÄ´óÀÏÆÅ£¡\n",
            "Ë«¶ù"    : "Ëý¿ÉÊÇÎÒÐ¡±¦µÄÒ»±¦Ñ½£¬ÊÇÎÒµÄ´ó´óÀÏÆÅ£¡ÄãÈÏÊ¶Ëý£¿¾¯¸æÄã£¬ÀëËýÔ¶µã£¡\n",
            "ÔøÈá"    : "ÎÒÀÏÆÅÄãÎÊÄÇÃ´¶à¸ÉÂï£¿»ÊÉÏºé¸£ÆëÌì£¬ÎÒÑÞ¸£ÆëÌì£¡\n",
            "·½âù"    : "ÎÒÀÏÆÅÄãÎÊÄÇÃ´¶à¸ÉÂï£¿»ÊÉÏºé¸£ÆëÌì£¬ÎÒÑÞ¸£ÆëÌì£¡\n",
            "ËÕÜõ"    : "ÎÒÀÏÆÅÄãÎÊÄÇÃ´¶à¸ÉÂï£¿»ÊÉÏºé¸£ÆëÌì£¬ÎÒÑÞ¸£ÆëÌì£¡\n",
            "ãå½£ÆÁ"  : "ÎÒÀÏÆÅÄãÎÊÄÇÃ´¶à¸ÉÂï£¿»ÊÉÏºé¸£ÆëÌì£¬ÎÒÑÞ¸£ÆëÌì£¡\n",
            "½¨Äþ¹«Ö÷": "Õâ¸öÉ§ÄïÆ¤£¬Ç×ºñ²»¼°Ë«¶ù¡¢ÃÀÃ²²»¼°°¢çæ¡¢Îä¹¦²»
¼°ËÕÜõ¡¢»úÇÉ²»¼°·½âù¡¢ÌìÕæ´¿ÉÆ²»¼°ãå½£ÆÁ¡¢ÎÂÈáË¹ÎÄ²»¼°ÔøÈá£¬
²îÓÐÒ»ÈÕÖ®³¤Õß£¬²»¹ýºáÂùÆÃÀ±¶øÒÑ£¡\n",
        ]) );
        set("chat_chance_combat",50);
        set("chat_msg_combat", ({
                (: command("haha") :),
                (: command("chat Ë­°ïÎÒÕÒµ½Ë«¶ù£¬ÎÒ»áÊ®·ÖµÄ¸ÐÐ»ËûµÄ¡£\n") :),
                (: command("say Äã»îµÃ²»ÄÍ·³ÁËÕÒËÀ°¡£¿\n") :),
                     }) );
        setup();
        carry_object("/d/city2/obj/jinduan")->wear();
}
void init()
{
        add_action("give_quest", "quest");
}
int give_quest()
{
        mapping quest ;
        object me;
        int j, combatexp, timep,factor,num;
        string tag = "1000000";
        string *levels = ({
                        "1000",
                        "1500",
                        "2000",
                        "3000",
                        "5000",
                        "8000",
                        "10000",
                        "13000",
                        "17000",
                        "22000",
                        "30000",
                        "45000",
                        "60000",
                        "80000",
                        "100000",
                        "200000",
                        "350000",
                        "600000",
                        "1000000",
                        "1500000",
                        "2500000",
        });
        me = this_player();
        combatexp = (int) (me->query("combat_exp"));
        if(combatexp<10000)
        {
             message_vision("Î¤Ð¡±¦¶Ô$NºßÁËÒ»ÉùµÀ£º¡°À±¿éÂèÂè£¬¶«Î÷»¹Ã»³¤ÆëÏë¸ÉÂï£¿¡±\n",me);
             return 1;
        }
        if((quest =  me->query("quest")))
        {
             if( ((int) me->query("task_time")) >  time() )
             {
                   message_vision("Î¤Ð¡±¦¶Ô$NÐ¦µÀ£ºËµÄã²»ÐÐ°É£¬»¹²»·þÆø£¿\n", me);
                   message_vision("Î¤Ð¡±¦î©ÁË$NÒ»ÑÛËµµÀ£ºÄãÒªÊÇÃ»±¾ÊÂ£¬¾ÍÄÃµã¶ùÇ®Âò¾ÍµÃÁË¡£\n",me);
                   return 0;
             }
             else
             {
                   message_vision("Î¤Ð¡±¦¶Ô×Å$NÌ¾ÁËÒ»¿ÚÆø£ºÃ»¹ØÏµÈ¥ÄÃ±ðµÄÒ²³É¡£\n", me);
                   me->add("qi",-(int)(me->query("qi")/6));
             }
        }
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
             if( atoi(levels[j])  <= combatexp )
             {
                   num=j;
                   factor=30;
                   break;
             }
        }
        if (num>0)
        {
             if (random(50)>45)
             {
                   num=num-1;
             }
        } 
        else
        {
             if ((num<sizeof(levels)-1)&&(random(100)>95))
             {
                   num=num+1;
                   factor=50;
             }
        }
        tag=levels[num];
        quest = QUEST_D(tag)->query_quest();
        timep = quest["time"];
        time_period(timep, me);
        if(quest["quest_type"]=="É±")
             message_vision("ÏÈÌæÎÒ°Ñ¡º"+quest["quest"]+HIW"¡»×¥»ØÀ´£¬ÎÒÏë¿´¿´Ëû³¤µÃÉ¶Ä£Ñù¡£\n" NOR,me);
        else
             message_vision("ÕÒµ½¡º"+quest["quest"]+HIW"¡»¸øÎÒ£¬ÎÒ»áºÃºÃÐ»Äã¡£\n" NOR,me);
        quest["exp_bonus"]=quest["exp_bonus"];
        quest["pot_bonus"]=quest["pot_bonus"];
        quest["score"]=quest["score"];

        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) quest["time"]);
        me->set("quest_factor",factor);
        return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "Ìì";
        else time = "";

        if(h) time += chinese_number(h) + "Ð¡Ê±";
        if(m) time += chinese_number(m) + "·Ö";
        time += chinese_number(s) + "Ãë";
        message_vision(HIW"Î¤Ð¡±¦¶Ô$N·Ô¸ÀµÀ£º¸øÄã"+time+"£¬",me);  
        return 1;
}

int accept_object(object who, object ob)
{
        int exp, pot, score,factor;
        string test;
        mapping quest;

        if (ob->query("money_id"))
        {
             if(!who->query("quest"))
             {
                   message_vision("Î¤Ð¡±¦Ð¦µÀ£ºÄÇÎÒ¿É¾Í²»¿ÍÆøÁË¡£\n",who);
                   return 1;
             }
             if ( ob->value() < 10000)
             {
                   message_vision("Î¤Ð¡±¦Ò»Ë«¼âÕë°ãµÄÑÛ¾¦Ö±¶¢×Å$N£ºÕâµãÇ®¿É²»¹»ÎÒÃÇµÄ¿ªÏú£¡\n", who);
                   return 1;
             }
             else
             {
                   message_vision("Î¤Ð¡±¦Ð¦µÀ£ºÄÇºÃ£¬ÔÛÃÇÂòÂô²»³ÉÈÊÒåÔÚ¡£ÏëÒªºÃ´¦ÔÙÕÒÎÒ°É£¡\n",who);
                   who->set("quest",0);
                   return 1;
             }
        }

        if(!(quest =  who->query("quest")))
        {
             tell_object(who,"Î¤Ð¡±¦ËµµÀ£ºÕâ²»ÊÇÎÒÏëÒªµÄ¡£\n");
             return 0;
        }

        if( ob->query("name") == "Ë«¶ù")
        {
          tell_object(who,"Î¤Ð¡±¦ËµµÀ£ºÐ»Ð» £¿£¡\n");
          command("chat Å¶£¬ÎÒµÄºÃË«¶ù»ØÀ´ÁË£¬Ð»Ð»Äã" +who->query("name")+ ",  Ð»Ð»°ïÎÒÕÒµ½ÁËË«¶ù£¡\n");
          who->add("combat_exp",1300+random(700));
          who->add("potential",40+random(60));
          who->add("shen",100+random(3000));
          who->add("score",10+random(40));
          who->add("weiwang",3+random(7));
          who->set("quest",0);
          return 1;
        }
        if( ob->query("name") != quest["quest"])
        {
             tell_object(who,"Î¤Ð¡±¦ËµµÀ£ºÕâÊÇÊ²Ã´¶«Î÷£¿ÎÒ½ÐÄã°ìµÄÊÂÄã¾ÍÕâÑùºýÅªÎÒ£¿£¡\n");
             return 0;
        }

        if ((int) who->query("task_time") < time() )
        {
             tell_object(who,"Î¤Ð¡±¦ËµµÀ£ºÕæÊÇ·ÏÎï£¡ÄãÃ»ÓÐÔÚÖ¸¶¨µÄÊ±¼äÄÚ»ØÀ´£¡\n");
             return 1;
        }
        else
        {
             tell_object(who,"Î¤Ð¡±¦ÔÞÐíµØµãÍ·ËµµÀ£º²»´í£¡²îÊ¹°ìµÃ»¹²»´í£¡\n");
             exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
             pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2);
             score = quest["score"]/2 + random(quest["score"]/2);
             factor=who->query("quest_factor");
             
             if (factor)
             {
                  exp=exp*factor/10;
                  pot=pot*factor/10;
                  score=score*factor/10;
             }
             who->add("combat_exp", exp);
             who->add("potential", pot);
             who->add("score", score);
             tell_object(who,HIW"Äã±»½±ÀøÁË£º" + chinese_number(exp)
               + "µãÊµÕ½¾­Ñé£¬"+ chinese_number(pot) + "µãÇ±ÄÜ£¬"
               + chinese_number(score)+"µã½­ºþÔÄÀú¡£\n"NOR);
             who->set("quest", 0 );
             tell_object(who,HIW"¹§Ï²ÄãÍê³ÉÒ»¸ö²îÊ¹£¡\n"NOR);
             return 1;
        }
}

