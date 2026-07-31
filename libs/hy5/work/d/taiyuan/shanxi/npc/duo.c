inherit NPC;
//inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("吕迪", ({ "master lv", "master"}) );
        set("nickname", HIR "权法天王"NOR);
        set("gender", "男性" );
        set("age", 31);
        set("per", 30);
        set("npc_difficulty",8);
        set("organization/性质","邪");
        set("agi",25);
        set("int",30);
        set("cor",40);
        set("combat_exp",80000000);
        set("max_kee",200000);
        set("max_gin",100000);
        set("max_sen",100000);
        set("max_force", 8000);
        set("force", 8000);
        set("force_factor", 120);
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
        set("long",
"
没有人的脸上会发出这种青光的，除非他脸上戴着个青铜面具。
这人的脸上就戴着青铜面具，在星光下看来，显得更狰狞而怪异。
他身上穿着的，却是件美丽的绣花长袍，腰带上斜插着三柄弯刀。
惨碧色的刀鞘上，缀满了明珠美玉。 
\n"
        );
        create_family("西方神教", 2, "天主"); 
        set("score", 20000);
  set("jing", 20000);
        set("eff_jing", 20000);
        set("max_jing", 20000);        
        set("qi", 22000);
        set("eff_qi", 22000);
        set("max_qi", 22000);
        set("max_jingli", 22000);
        set("neili", 40000);
        set("max_neili", 40000);
        set("max_jingqi",1000);
        set("combat_exp", 9000000);
        set_skill("dodge",300);
        set_skill("cuff",320);
        set_skill("unarmed",300);
        set_skill("parry",300);
        set_skill("blade",380);
         set_skill("feitian-yujianliu",380);
         set_skill("wuxing-dun",380);
        set_skill("shayi",380);
         set_skill("aikido",380);
         set_skill("shayi-xinfa",380);
        set_skill("shiren-jianfa",380);
        set_skill("shiren-quanfa",380);
        set_skill("force",300);
set_skill("huoxinliu-jianfa",380);

        set_skill("literate",250);
        map_skill("blade", "feitian-yujianliu");
        map_skill("force", "shayi-xinfa");
              map_skill("unarmed", "aikido");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");

         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
                (: perform_action, "blade.tianxiang" :),
                (: perform_action, "blade.longlianda" :),
                (: perform_action, "blade.suodi" :),
                (: perform_action, "blade.jiu" :),
                (: perform_action, "unarmed.sanchong" :),
        }));
        setup();
        carry_object(__DIR__"obj/xiuhuacloth")->wear();
        carry_object(__DIR__"obj/duomianju")->wear();
        carry_object(__DIR__"obj/duoblade")->wield();
} 
int accept_fight(object me)
{
	command("heng");
        command("say 不知死活的家伙出招吧！");
        return 1;
}