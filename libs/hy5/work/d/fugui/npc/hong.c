#include <ansi.h>
inherit NPC;
void create()
{
        set_name("红娘子", ({ "hong niangzi", "hong" }) );
        set("gender", "女性" );
        set("long",
         "她身上好像也在发光，一种红得耀眼，红得令人心跳的光。红娘子身\n上当然穿着红衣服，但光不是从她衣服上发出来的，事实上除了衣服\n外，她身上每个地方好像都在发光，尤其是她的眼睛，她的笑。\n");
        set("nickname", HIR "救苦救难"NOR);
        set("chat_chance",1);
        set("chat_msg", ({
        "红娘子眼波流动，向你抛了个媚眼，似笑非笑道：“我长得怎样？你\n动不动心啊？”\n",
                                })  ); 
        set("combat_exp", 1000000);
        set("force",500);
        set("max_neili",500);
        set_temp("apply/damage",50);
        set("no_arrest",1);
        
		set_skill("fengmo-zhang",380);
	set_skill("liuhe-zhang",380);
	set_skill("strike",390);
	set_skill("force", 300);             // 基本内功
	set_skill("huntian-qigong", 380);    // 混天气功
	set_skill("unarmed", 260);           // 基本拳脚
	set_skill("xianglong-zhang", 380);   // 降龙十八掌
	set_skill("dodge", 260);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 380);        // 逍遥游
	set_skill("parry", 260);             // 基本招架
	set_skill("staff", 380);             // 基本棍杖
	set_skill("dagou-bang", 380);        // 打狗棒法
	set_skill("begging", 380);           // 叫化绝活
	set_skill("checking", 380);          // 道听途说
	set_skill("training", 380);         // 驭兽术
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.zhuan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: command("unwield yuzhu zhang") :),
                (: command("wield yuzhu zhang") :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.qu" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );

        
        setup();
        carry_object(__DIR__"obj/redcloth")->wear();
} 
void init()
{       
        object ob;
        ::init();
   if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) 
                return;
        message_vision(HIW"$N眼波流动，瞟了$n一眼，似笑非笑道：“我早知道会有人来的，\n怎么王动他自己不来？哎，解药就在坟头，自己去拿吧。”\n"NOR,this_object(),ob);
                
} 
