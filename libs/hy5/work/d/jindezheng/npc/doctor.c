inherit NPC;

string query_save_file() { return DATA_DIR +"npc/叶天士";}
int ask_heal();
void create()
{
	set_name("叶天士", ({ "ye", "ye", "ye" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位叶天士正笑咪咪地忙著。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");

set("long","叶天士妙手回春,你治病可以向他打听(ask ye tianshi about heal).\n");
set("inquiry",([
"heal":(:ask_heal:),
]));
	set("area_name","景德镇天医阁");
	set("area_file","/d/jindezheng/doctor-room.c");
	setup();
//	carry_object("/obj/std/armor/yinjia")->wear();
	carry_object("/clone/misc/cloth")->wear();
}
int ask_heal()
{
 string *gifts=({"qi","jing","jingli"}),
        *strs=({"精亏肾虚","气血受损","神伤心悸"}),
        str;
 object ob;
 int i,num=0,max=0,count=0;
 ob=this_player();str="";
if (!living(ob)||environment(ob)!=environment()) return 0;
          for (i=0;i<sizeof(gifts);i++)   {
       max=(int)ob->query("max_"+gifts[i]);
       num=(int)ob->query("eff_"+gifts[i]);
              if (max-num>0)   { 
                    str+="     "+strs[i]+"\n";
                    ob->set_temp("doctor/"+gifts[i],max-num);
       }
          count+=max-num;
         }
          if (count==0) {
  command("say 你没有什么毛病,回去休息一下就好.\n");
  return 1;
  }
count/=10;
if(count<=0)	count=1;
command("say 你的病况如下:\n"+str+"完全治好需要"+count+"两银子.\n");
ob->set_temp("doctor/checked",count);
 return 1;

}
int accept_object(object who,object ob)
{
  int val,wound,i;
  string *gift=({"qi","jing","jingli"}),
         *port=({"涌泉穴","足三里","百会穴","迎香穴","合谷穴","肩井穴"});
  if (!ob->query("money_id")) return 0;
  if (!who->query_temp("doctor/checked")) return 0;
  val=(int)ob->value()/10;
  if ((int)ob->value()<100)  
       return notify_fail("这点钱要治你的病好象不够吧!\n");
 message_vision("$N用金针在$n的"+port[random(sizeof(port))]+"刺了下去,
  $n轻轻地吁出一口长气,觉得轻松多了.\n",this_object(),who);

 for (i=0;i<sizeof(gift);i++)   {
        wound=(int)who->query_temp("doctor/"+gift[i]);
    if (wound>val)   {
          who->add("eff_"+gift[i],val);
          who->delete_temp("doctor");
          return 1;                 }
       who->add("eff_"+gift[i],wound);
       val-=wound;
     }
 who->delete_temp("doctor");
  return 1;
}

