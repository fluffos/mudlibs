// xiaozhao

#include <ansi.h>
inherit NPC;
mapping *step_phase;
mapping *read_table(string file);
int j; 

int ask_zhang();  
int ask_qian();
int ask_mishi();
void heal();   
void create()
{
	set_name("小昭", ({ "xiao zhao", "zhao" }));
	set("long", 
		"她是杨不悔的丫鬟，双手被一条长链锁着，若有所思。\n");
		
        set("title", CYN "杨不悔" NOR + MAG "丫鬟" NOR);
       
	set("gender", "女性");
	set("age", 16);
	set("shen_type", 1);

	set("neili", 800);
	set("max_neili", 800);
	set("max_qi", 800);
	set("max_jing", 700);
	set("jiali", 10);
	set("per", 30);     
	

        set("chat_chance", 5);
        set("chat_msg", ({
                (: heal :),  
                    "小昭低声吟道：天涯思君不可忘 武当山顶松柏长\n",
                    "小昭低声吟道：宝刀百炼生玄光 字作丧乱意彷徨\n",
                    "小昭低声吟道：皓臂似玉梅花妆 浮槎北溟海茫茫\n",
                    "小昭低声吟道：谁送冰舸来仙乡 穷发十载泛归航\n",
                    "小昭低声吟道：七侠聚会乐未央 百岁寿宴摧肝肠\n",
                    "小昭低声吟道：有女长舌如利枪 针其膏兮药其肓\n",
                    "小昭低声吟道：不悔仲子逾我墙 当道时见中山狼\n",
                    "小昭低声吟道：奇谋妙计梦一场 剥极而复参九阳\n",
                    "小昭低声吟道：青翼出没一笑扬 倚天长剑飞寒芒\n",
                    "小昭低声吟道：祸起萧墙破金汤 与子共穴相扶将\n",
                    "小昭低声吟道：排难解纷当六强 群雄归心约三章\n",
                    "小昭低声吟道：灵芙醉客绿柳庄 太极初传柔克刚\n",
                    "小昭低声吟道：举火燎天何煌煌 俊貌玉面甘损伤\n",
                    "小昭低声吟道：百尺高塔任回翔 恩断义绝紫衫王\n",
                    "小昭低声吟道：四女同舟何所望 东西永隔如参商\n",
                    "小昭低声吟道：刀剑齐失人云亡 冤蒙不白愁欲狂\n",
                    "小昭低声吟道：箫长琴短衣流黄 新妇素手裂红裳\n",
                    "小昭低声吟道：屠狮有会孰为殃 夭矫三松郁青苍\n",
                    "小昭低声吟道：天下英雄莫能当 君子可欺之以方\n",
                    "小昭低声吟道：秘笈兵书此中藏 不识张郎是张郎\n",
                        
        }));

        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );

	set_skill("force", 50);
	set_skill("taiji-shengong", 40);
	set_skill("cuff", 50);
	set_skill("taiji-quan", 40);
	set_skill("dodge", 60);
	set_skill("tiyunzong", 50);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("taiji-jian", 40);

	map_skill("sword", "taiji-jian");
	map_skill("parry", "taiji-jian");
	map_skill("dodge", "tiyunzong");
	map_skill("force", "taiji-shengong");
	map_skill("cuff", "taiji-quan");

	prepare_skill("cuff", "taiji-quan");

	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);  
	  set("inquiry", ([
                "阳顶天" : "小昭说：他老人家是上代明教教主。\n",
                "紫衫龙王" : "小昭说：她老人家是我的母亲。哎。。。\n",
                "张无忌" : (: ask_zhang :),  
		"乾坤大挪移" : (: ask_qian :),
                "密室" : (: ask_mishi :), 
	     ]));

	setup();    
 carry_object("/clone/weapon/changjian")->wield();
	
	
}
    
int ask_zhang()
{ 
     
   if ((string)this_player()->query("family/master_id")!="zhang wuji")
   {
      say("小昭说：他是我教教主，你问他干什么？\n");
      return 1;
    }
  else
   {
      say("小昭说：他是我教教主,怎么，他让你找我干什么？\n");
      this_player()->set_temp("marks/张1", 1);
    return 1;
   }
}
   
int ask_qian()
{ 
     
  if ((int)this_player()->query_temp("marks/张1")) 
   {
      say("小昭说：这是本教镇教之宝，无忌哥哥说好象在密室中。\n");  
 this_player()->set_temp("marks/张2", 1);
      return 1;
    }
  else
   {
      say("小昭说：这是本教镇教之宝，我不知道在哪。\n");
     
    return 1;
   }
}

int ask_mishi()
{      
       // int i; 
	object ob,me;
//	object inv2;
//	object *inv;
   ob = this_object();
   me = this_player();   
//   inv = all_inventory(me); 

   if ((int)this_player()->query_temp("marks/张2")) 
    {
	 say("小昭说：密室里机关重重，只有跟着我才能进去。\n");
/*	for( i = 0; i<sizeof(inv); i++)
	{
	inv2 = inv[i];
	if( interactive(inv2) ) 
	{
	command("say 你带着别的人，是不能进去的。\n");
	return 1;
	}
   }   */
      if ( me->query_encumbrance() * 100 / me->query_max_encumbrance() > 40)
        {
                write("你身上背的东西太多，密道的路不好走，你还是放下一些吧。\n");
                return 1;
        }

        if((string)this_player()->query("family/master_id") != "zhang wuji")
        { 
     
         	command("say 你的身份不够吧 。");
        }
     else{
        
        command("say 跟我来。follow me 。");
	ob->move("/d/mingjiao/path1");
	me->move("/d/mingjiao/path1");
        
       	step_phase = read_table("/d/mingjiao/step");
        j=0;                   
	remove_call_out("step");
	call_out("step",5);
       	return 1; 
	
	}      
    }
  else {
     say("小昭说：密室是我教重地，你怎么知道的？\n");
     return 1;
       }
}

mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]==	'#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]]);
		fn = (++fn) % sizeof(field);        
		if( !fn ) ++rn;
	}
	return data;
}



void step()
{        
	
	command(step_phase[j]["command"]);
        j++;
        if (j==sizeof(step_phase))
	{
	command("say 到了，就这里了。"); 
        command("say 我该走了，不悔姑娘发现我不在，会生气的。");
    destruct(this_object());    
       
         	 return;
         }
	call_out("step", 2);
}        


void heal()
{
        object ob=this_object();

        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("enforce 10");
                return;
        }

        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("jing") < ob->query("eff_jing"))
                command("exert regenerate");

        return;
}
