// by smzz
// 2002/9/26
#define BLADE
#define weapon
inherit NPC;
void create()
{
     set_name("物保管", ({ "wu baoguan","wu","baoguan" }));
     set("long", 
"他是穆仁清派来协助黄真开好扬州钱庄，负责物品寄存。\n"
);
     set("gender", "男性");
     set("age", 60);
     set("con",30);
     set("str",40);
     set("dex",20);
     set("int",23);
     set("max_jing", 100000);
     set("jing", 100000);
     set("max_jing", 9000);
     set("max_neili", 20000);
     set("neili", 20000);
     set("qi", 9000);
     set("max_qi", 9000);
     set("max_jing", 9000);
     set("jing", 9000);
     set("combat_exp", 3000000);
     set("shen_type", 1);
     set("attitude", "friendly");
     set_skill("force", 400);
     set_skill("zixia-gong", 400);
     set_skill("dodge", 400);
     set_skill("pishi-poyu", 400);
     set_skill("cuff", 400);
      map_skill("dodge","huashan-shenfa");
      map_skill("force","zixia-gong");
      map_skill("cuff","pishi-poyu");
     set_skill("huashan-shenfa", 400);

create_family("华山派",19,"弟子");
setup();
}
int accept_object(object who, object ob)
{
     if ( ob->query("weapon_id") ) 
{
return notify_fail(name() + "对着你笑笑道：切莫拿老夫开玩笑！\n");
command("protect " + who->query("id"));
return 1;
}
}
