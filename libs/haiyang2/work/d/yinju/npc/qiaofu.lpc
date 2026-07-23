inherit NPC;
#include <ansi.h>
void create()
{
	set_name("樵夫", ({ "qiao fu", "qiao" }));
	set("title",  "大理国大将军" );
	set("long", 
"他就是大理国的原大将军，一灯大师的四大弟子之一。
左手提着一捆松柴，右手握着一柄斧头，但见他容色豪
壮，神态虎虎，举手迈足间似是大将军有八面威风。若
非身穿粗布衣裳而在这山林间樵柴，必当他是个叱咤风
云的统兵将帅。\n");
              set("nickname", HIY "渔樵耕读" NOR );   
        set("gender", "男性");
        set("age", 45);

        set("class", "officer");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("per", 25);
        set("str", 30);
        set("int", 20);
        set("con", 25);
        set("dex", 25);     
        set("max_qi", 11000);
        set("max_jing", 1500);
        set("neili", 12000);
        set("max_neili", 12000);
        set("jiali", 50);
        set("combat_exp", 1500000);
        set("score", 100000);

        set_skill("kurong-changong", 150);
        set_skill("tiannan-step", 150);
        set_skill("jinyu-quan", 150);
        set_skill("unarmed", 150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("cuff", 180);
        set("inquiry", ([
                "一灯大师"   : "师父他老人家在上面。\n",
                "段智兴"     : "那是我师父俗世的名讳。\n",
                "刘瑛姑"     : "她是我师父俗世的妃子。\n",
        ]) );
       map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-step");
        map_skill("cuff",  "jinyu-quan");  
        map_skill("parry", "jinyu-quan");
        prepare_skill("cuff", "jinyu-quan");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 100);

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
        
