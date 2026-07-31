// chen.c
inherit NPC;
#include <ansi.h>;

void init()
{
        object me = this_player();
        if (me->query_temp("thd/onquest")==2) { 
           message_vision(HIY"$N见到黑风双煞来势猛恶，顿时想起靴旁的匕首(bishou)。\n"NOR,me);
           add_action("do_chou","chou");
        }
}

void create()
{
        set_name( "陈玄风" ,({ "chen xuanfeng", "chen" }));
        set("title", "黑风双煞");
        set("nickname", HIY"铜尸"NOR);
        set("gender", "男性");
        set("age", 35);
        set("long",
            "此人是黄药师的二弟子，他浓眉大眼，背厚膀宽，躯体甚是壮健，只是\n"
            "面色微微泛黄。\n");
        set("attitude", "aggressive");
        set("str", 37);
        set("int", 32);
        set("con", 35);
        set("unique", 1);
        set("no_quest", 1);
        set("max_qi",3500);
        set("qi",3500);
        set("max_jing",1000);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 100);
        set("shen",-50000);

        set("combat_exp", 800000);

        set_skill("claw", 200);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("leg", 200);
        set_skill("jiuyin-baiguzhua", 200);
        set_skill("bihai-chaosheng", 200);
        set_skill("suibo-zhuliu", 200);
        set_skill("xuanfeng-tui", 200);

        map_skill("force", "bihai-chaosheng");
        map_skill("parry", "jiuyin-baiguzhua");
        map_skill("dodge", "suibo-zhuliu");
        map_skill("claw", "jiuyin-baiguzhua");
        map_skill("leg", "xuanfeng-tui");
        prepare_skill("claw", "jiuyin-baiguzhua");

        create_family("桃花岛", 2, "被逐弟子");
        set("inquiry", ([
           "铜尸":     "江湖上的人都这么叫我的，你怕不怕？哈哈哈哈。",
           "东邪":     "那是我师父的绰号。",
           "西毒":     "那是与家师齐名的高手之一，是个老毒物，住在白驼山。",
           "南帝":     "段王爷已出家当和尚去了，法名叫一灯。",
           "北丐":     "北丐统领中原的丐帮，势力颇为强大。",
           "洪七公":   "洪七公武功高强，而且教会郭靖那小儿降龙十八掌，可恨！",
           "黄蓉":     "她是我师父的独女，最是刁蛮任性。",
           "梅超风":   "她是我的师妹，也是我的内室。",
           "陈玄风":   "不就是我么？你是白痴啊？",
           "黄药师":   "他是我师父。"]) );
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
}

void kill_ob(object me)
{
        object ob=this_object();
        command("say 想抢我的九阴真经？没那么容易！");
        message_vision(HIY"陈玄风向$N急攻数招，夺路向外跑去。\n\n"NOR,me);
        COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 3);
        COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 3);
        COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 3);
        command("out");
        ::kill_ob(me);
}

void do_dest(object ob)
{
      ::die();
}


int do_chou(string arg)
{
        object me = this_player();
        object ob = this_object();
        object obj;
        string msg;
        if (!arg||arg!="bishou")
                return notify_fail("什么？\n");
        if (me->query_temp("thd/onquest")!=2)
                return notify_fail("什么？\n");         
        if(arg=="bishou"&&me->query_temp("thd/onquest")==2)
        {
                msg = HIR"$N见到黑风双刹袭来，心中一惊，抽出匕首胡乱挥舞起来。\n";
                msg+= HIR"陈玄风冷笑一声，在$N肩头青门穴一弹，$N手一沉，竟然正好插在\n";
                msg+= HIR"他的肚脐上！\n\n"NOR;
                msg+= HIY"陈玄风瞪著$N，身子慢慢的软倒。\n\n"NOR;
                msg+= HIC"梅超风惨叫一声，不故性命的向你攻来！\n"NOR;
                        if (!objectp(obj = present("mei chaofeng",environment(me))))
                        {
                                call_out("do_dest",1,ob);
                                return 1;
                        }
                obj->set_temp("target",me->query("id"));
                message_vision(msg, me);
                me->set_temp("thd/onquest",3);
                ob->die();
                return 1;
         }
}

void die()
{
        object me = query_temp("last_damage_from");
        object skin;
        if (!objectp(me)) return;
        if((random(me->query_kar()) > 22
         || me->query("jiuyin/emei")
         || me->query("jiuyin/gumu")
         || me->query("jiuyin/chenpass"))
         && me->query("jiuyin/chenfail") < 3
         && me->query("combat_exp", 1) > 1000000
         && me->query("jiuyin-xj/chenfail") < 3){
          skin = unew(__DIR__"obj/jiuyin-book2");
          if(!clonep(skin)){
           ::die();
           return;
          }
          if(clonep(skin) && skin->violate_unique()){
             destruct(skin);
             ::die();
             return;
          }                 
          message_vision(HIY"$N看到陈玄风身上有一片皮革，顺手拿了起来。\n"NOR,me);
          skin->set("owner", me->query("id"));
          skin->move(me);
          if(! me->query("jiuyin/chenpass"))
          log_file("quest/jiuyin",sprintf("%s %s(%s)失败%s次后，从陈玄风处得到九阴真经下卷。\n",
            ctime(time())[4..19], me->name(1),capitalize(getuid(me)),chinese_number(me->query("jiuyin/chenfail")) ));
          me->set("jiuyin/chenpass", 1);
          ::die();
          return;
        }
        if (!me->query("jiuyin/chenpass"))
        me->add("jiuyin/chenfail", 1);
        if(!me->query("jiuyin/chen") && me->query("jiuyin/chenfail") < 4){
          if(me->query("jiuyin/chenfail") < 3 )
          log_file("quest/jiuyin",sprintf("%s %s(%s)想从陈玄风处得到九阴真经下卷，失败%s次。\n",
            ctime(time())[4..19], me->name(1),capitalize(getuid(me)),chinese_number(me->query("jiuyin/chenfail")) ));
          else
          log_file("quest/jiuyin",sprintf("%s %s(%s)失败三次后，无法再从陈玄风处得到九阴真经下卷。\n",
            ctime(time())[4..19], me->name(1),capitalize(getuid(me)),chinese_number(me->query("jiuyin/chenfail")) ));
        }
        ::die();
        return;
}
