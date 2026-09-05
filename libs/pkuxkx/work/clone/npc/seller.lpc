// modify by chui
#include <ansi.h>

inherit NPC;

string *pets = ({ "dog", "hawk", "cat", "pig", "rat" });

void setup_it(object owner, object pet, string ctype);

void create()
{
        set_name("殷老板", ({ "yin laoban", "yin" }) );
        set("gender", "男性" );
        set("age", 50);
        set("long","他整天不苟言笑，给人一种很阴沉的感觉，似乎曾经饱经风霜的样子。\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");

        set_skill("dodge", 100);
        set_skill("unarmed", 100);

        set("shen_type",1);set("score",500);setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_ding", "ding");
        add_action("do_fuhuo", "fuhuo");
        add_action("do_fuhuo", "relive");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        message_vision( "殷老板用低沉的声音向$N问道：这位" + RANK_D->query_respect(ob)+ "，想买小动物吗？\n找我就对了，可以用ding <type> <color> <name> <English name>。\n殷老板偷偷对$N说道：这位" + RANK_D->query_respect(ob)+ "，如果想复活你的小宠物吗？找我就对了，用fuhuo、relive\n", ob);

}

int do_ding(string arg)
{
        string ctype, cname, ccolor, cid;
        object pet, me, gold;
        me = this_player();

        if( !arg || sscanf(arg,"%s %s %s %s",ctype,ccolor,cname,cid ) != 4 )
                return notify_fail("指令格式：ding <type> <color> <name> <English name>\n");
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");
        if( (int)me->query("created_pet") >= 1 )
                return notify_fail("你已经有一个宠物了。\n");
        if( me->query("age") < 16 )
                return notify_fail("你的年龄太小了，恐怕连自身都难保，靠什么来保护它呀？\n");

        gold = present("gold_money", this_player());
        if( !gold )
                return notify_fail("你身上没有金子。\n");
        if( (int)gold->query_amount() < 100 )
                return notify_fail("你身上没有那麽多金子。\n");
        if( !LOGIN_D->check_legal_name(cname) )
                return notify_fail("");
        if( !LOGIN_D->check_legal_id(cid) )
                return notify_fail("");

        if( ccolor != "$BLK$" && 
            ccolor != "$NOR$" &&
            ccolor != "$RED$" &&
            ccolor != "$GRN$" &&
            ccolor != "$YEL$" &&
            ccolor != "$BLU$" &&
            ccolor != "$MAG$" &&
            ccolor != "$CYN$" &&
            ccolor != "$WHT$" &&
            ccolor != "$NOR$" &&
            ccolor != "$HIR$" &&
            ccolor != "$HIG$" &&
            ccolor != "$HIY$" &&
            ccolor != "$HIB$" &&
            ccolor != "$HIM$" &&
            ccolor != "$HIC$" &&
            ccolor != "$HIW$" )
                return notify_fail("你到底要什么颜色呀？\n");

        if( ccolor == "$NOR$" )
                return notify_fail("对不起，为了避免混淆，你必须指定一种颜色。\n");
        
        if( member_array(ctype, pets) == -1 )
                return notify_fail("这里没有你想要的小动物。\n");

        cname = ccolor + cname;
        cname = replace_string(cname, "$BLK$", BLK);
        cname = replace_string(cname, "$RED$", RED);
        cname = replace_string(cname, "$GRN$", GRN);
        cname = replace_string(cname, "$YEL$", YEL);
        cname = replace_string(cname, "$BLU$", BLU);
        cname = replace_string(cname, "$MAG$", MAG);
        cname = replace_string(cname, "$CYN$", CYN);
        cname = replace_string(cname, "$WHT$", WHT);
        cname = replace_string(cname, "$HIR$", HIR);
        cname = replace_string(cname, "$HIG$", HIG);
        cname = replace_string(cname, "$HIY$", HIY);
        cname = replace_string(cname, "$HIB$", HIB);
        cname = replace_string(cname, "$HIM$", HIM);
        cname = replace_string(cname, "$HIC$", HIC);
        cname = replace_string(cname, "$HIW$", HIW);
        cname = replace_string(cname, "$NOR$", NOR);
        cname += NOR;
        pet = new(PET_OB);
        setup_it(me, pet, ctype);
        pet->set("shen_type",1);set("score",500);setup();
        pet->set_name(cname, ({ cid }));
        pet->setup_pet(me->query("id"));
        if( !pet->save() )
                return notify_fail("无法写入文件。\n");
        if( pet->move(environment(me)) ) {
                gold->add_amount(-100);
                me->set("created_pet", 1);
                me->set_temp("create_pet", pet);
                me->start_busy(1);
                message_vision(this_object()->name() + "从身后的笼子里抱出一" + pet->query("unit")
                        + pet->name() + "交给$N，叮嘱道：“可要好好照顾啊！”\n", me);
                return 1;
        }
        return 0;
}

void setup_it(object owner, object pet, string ctype)
{
        switch( ctype ) {
        case "dog":
                pet->set("race", "野兽");
                pet->set("unit", "条");
                pet->set("age", 1);
                pet->set("combat_exp", 1);
                pet->set("birthday", time());
                pet->set("long", "这是一条刚出生不久的小狗。\n");
                pet->set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
                pet->set("verbs", ({ "bite", "claw", "hoof" }) );
                pet->set("msg_lost", "$N好象找不到它的主人了，一副好可怜的样子。\n");
                pet->set("msg_meet", "$N高兴地向" + owner->name() + "摇了摇尾巴，「汪汪」地叫了几声。\n");
                pet->set("msg_come", "$N跑了过来。\n");
                pet->set("msg_leave", "$N向$E离开。\n");
                break;
        case "hawk":
                pet->set("race", "飞禽");
                pet->set("unit", "只");
                pet->set("age", 1);
                pet->set("combat_exp", 1);
                pet->set("birthday", time());
                pet->set("long", "这是一只雄赳赳的小鹰。\n");
                pet->set("limbs", ({ "头部", "身体", "脚", "左翅", "右翅", "尾巴" }) );
                pet->set("verbs", ({ "claw", "poke", "sao" }) );
                pet->set("msg_lost", "$N好象找不到它的主人了，一副好可怜的样子。\n");
                pet->set("msg_meet", "$N在空中盘旋几圈，落在" + owner->name() + "的肩上。\n");
                pet->set("msg_come", "$N飞了过来。\n");
                pet->set("msg_leave", "$N向$E离开。\n");
                break;
        case "pig":
                pet->set("race", "野兽");
                pet->set("unit", "头");
                pet->set("age", 1);
                pet->set("combat_exp", 1);
                pet->set("birthday", time());
                pet->set("long", "这是一头整天哼哼叽叽的小猪。\n");
                pet->set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴", "耳朵" }) );
                pet->set("verbs", ({ "bite", "claw", "hoof" }) );
                pet->set("msg_lost", "$N好象找不到它的主人了，一副好可怜的样子。\n");
                pet->set("msg_meet", "$N高兴地往" + owner->name() + "身上蹭了蹭，哼哼了几声。\n");
                pet->set("msg_come", "$N跑了过来。\n");
                pet->set("msg_leave", "$N向$E离开。\n");
                break;
        case "cat":
                pet->set("race", "野兽");
                pet->set("unit", "只");
                pet->set("age", 1);
                pet->set("combat_exp", 1);
                pet->set("birthday", time());
                pet->set("long", "这是一只好温顺的小猫。\n");
                pet->set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
                pet->set("verbs", ({ "bite", "claw", "hoof" }) );
                pet->set("msg_lost", "$N好象找不到它的主人了，一副好可怜的样子。\n");
                pet->set("msg_meet", "$N高兴地跳到了" + owner->name() + "的怀里，「喵喵」地叫了几声。\n");
                pet->set("msg_come", "$N跑了过来。\n");
                pet->set("msg_leave", "$N向$E离开。\n");
                break;
        case "rat":
                pet->set("race", "野兽");
                pet->set("unit", "只");
                pet->set("age", 1);
                pet->set("combat_exp", 1);
                pet->set("birthday", time());
                pet->set("long", "这是一只贼眉鼠眼的小老鼠。\n");
                pet->set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
                pet->set("verbs", ({ "bite", "claw", "hoof" }) );
                pet->set("msg_lost", "$N好象找不到它的主人了，一副好可怜的样子。\n");
                pet->set("msg_meet", "$N高兴地在" + owner->name() + "身边转了几圈，「吱吱」地叫了几声。\n");
                pet->set("msg_come", "$N跑了过来。\n");
                pet->set("msg_leave", "$N向$E离开。\n");
                break;
        }
}
int do_fuhuo()
{
        object pet, me, gold;
        me = this_player();

        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");
        if( (int)me->query("created_pet") < 1 )
        	return notify_fail("你连宠物都没有，恐怕不能复活吧。\n");
        if (!me->query("pet_died")||(!(0<(int)me->query("pet_died")<86401)))
                return notify_fail("你宠物活的吧。\n");
        gold = present("gold_money", this_player());
        if( !gold )
                return notify_fail("你身上没有金子。\n");
        if( (int)gold->query_amount() < 50)
                return notify_fail("你身上没有那麽多金子。\n");
        
        if( me->query("created_pet") )
        {
          me->set("pet_died", 90001);
               gold->add_amount(-50);
        tell_object(me, PET_D->create_pet(me));
message_vision(this_object()->name() + "从把小宠物笼子里抱出交给$N，叮嘱道：“可要好好照顾啊！”\n", me);
        	return 1;
         }     
        return 0;
}
