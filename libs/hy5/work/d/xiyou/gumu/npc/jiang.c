inherit NPC;
#include <ansi.h>
string gloat();
string ask_me();

void create()
{
  set_name("姜子牙", ({ "jiang ziya", "jiang" }));
  set("title", HIW"封神榜天神"NOR);
  set("nickname", HIR"太公望"NOR  );
  set("gender", "男性");
  set("age", 65);
  set("str", 100);
  set("per", 100);
  set("cor", 100);
  set("cps", 100);
  set("long","他就是当年封神台上一统众神的太公望·姜子牙");
  set("combat_exp", 3000000);
  set("daoxing", 2000000);

 set("family/family/name", "轩辕古墓"); 
 

  setup();
  carry_object("/d/obj/weapon/whip/longsuo")->wield();
  carry_object("/d/obj/armor/tongjia")->wear();
}

