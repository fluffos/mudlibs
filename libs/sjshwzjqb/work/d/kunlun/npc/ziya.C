// add by xiuxiu
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("姜子牙", ({"jiang ziya","jiang","ziya"}));
       set("long","本名姜尚，在元始天尊门下修行多年，在助周朝夺得天下后返回昆仑。\n");
       set("title",HIG"周朝开国宰相"NOR);
       set("gender", "男性");
       set("age", 51);
       set("class", "kunlun");
       set("attitude", "friendly");
       set("rank_info/respect", "仙人");
       set("per", 30);
	set("int", 30);
       set("max_kee", 1000);
       set("max_sen", 1000);
       set("sen", 1000);
       set("kee", 1000);
       set("max_gin", 1000);
       set("max_force", 1000);
       set("max_mana", 1000);
       set("mana", 1000);
       set("force", 1000);
       set("force_factor", 100);
       set("mana_factor", 60);
       set("combat_exp", 800000);
       set("daoxing", 1800000);
       set("eff_dx", 200000);
       set("nkgain", 350);
       set_skill("unarmed", 180);
       set_skill("literate", 180);
       set_skill("dodge", 180);
       set_skill("force", 180);
       set_skill("parry", 180);
       set_skill("sword", 180);
       set_skill("mace", 180);
       set_skill("spells", 180);
       set_skill("xuanzong-force", 180);
       set_skill("wugou-jian", 180);
       set_skill("lingyunbu", 180);
       set_skill("yuxu-spells", 180);
       set_skill("kaitian-zhang", 180);
       set_skill("dashen-bian", 180);
       map_skill("sword", "wugou-jian");
       map_skill("mace", "dashen-bian");
       map_skill("unarmed", "kaitian-zhang");
       map_skill("dodge", "lingyunbu");
       map_skill("force", "xuanzong-force");
       map_skill("spells", "yuxu-spells");
       map_skill("unarmed", "jinding-zhang");
       create_family("昆仑山玉虚洞", 2, "弟子");

setup();

           carry_object("/d/lingtai/obj/cloth")->wear();
          carry_object("/d/kunlun/obj/mace")->wield();
        
}

void attempt_apprentice(object ob,object me)
   {
   if ( (string)ob->query("family/family_name")=="昆仑山玉虚洞") {
   if (((int)ob->query("daoxing") < 800000 )) {
   command("say 道兄的道行差了些，又怎么能学我的鞭法呢？" + RANK_D->query_respect(ob) + "还需多加努力才能学到真功夫。\n");
   return;
   }
              if (me->query_skill("yuxu-spells")  < 110 ) {
   command("say 道兄的玉虚仙法差了些，又怎么能学我的鞭法呢？" + RANK_D->query_respect(ob) + "还需多加努力才能学到真功夫。\n");
   return;
   }

        command("smile");
   command("say 好极，好极，时下妖魔当道，鬼怪横行。象"  + RANK_D->query_respect(ob) +"这样的正义之士却是少见！\n");;
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。\n");
       command("recruit " + ob->query("id") );
        ob->set("title", HIM"昆仑山玉虚洞打神鞭传人"NOR);
        ob->set("class","kunlun" );
   return;
   }
   command("shake");
   command("say 老夫不收外门弟子，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}



