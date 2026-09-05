// suanming.c 算命先生
#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC"算卦先生"NOR, ({"suangua xiansheng","xiansheng"}) );
        set("nickname",YEL"包准"NOR);
        set("str",20);
        set("long",
                "他是一位老道的算命先生。\n");
	set("age",40);
        set("shen_type",0);
	set("gender","男性");
	set("combat_exp",200000);
	set_skill("unarmed",30);
	set_skill("force",30);
	set_skill("dodge",30);
	set_skill("parry",30);
	set("chat_chance_combat",30);
	set("chat_chance",4);
	setup();
	set("chat_msg",({HIC"谁想算命啊?\n"NOR,
            HIC"算一次三两黄金，不对不要钱。\n"NOR,
	}));
	carry_object("/d/city/obj/cloth")->wear();
}

int accept_object(object who,object ob)
{
	object me=this_player();
	int qi,sk;
	string skill;
//        if((string)ob->query("name")=="黄金"||(string)ob->query("id")=="gold")
                if (ob->query("money_id") && ob->value() >= 2000) 
		
	{	
		qi = (int)me->query("qi");
        	sk=(int)me->query_skill("damage_skill",1);
		printf("算命先生稍微翻了翻白眼，说道:你的名字叫%s.今年%d岁,是%s的。\n",
		me->name(),(int)me->query("age"),(string)me->query("family/family_name"));
                printf("算命先生又对你说道:你的福缘是%d,容貌是%d,灵性是%d\n",(int)me->query("kar"),(int)me->query("per"),(int)me->query("spi")+30);
                printf("算命先生嘿嘿奸笑了几声说：你现在的杀气是%d\n",(int)me->query("shaqi"));
       		printf("算命先生又低下头去思索了一番，说道：%s的战斗力是:%d\n",
                me->name(),
                (sk*sk*sk) * (100 +qi) / 100 + ((int)me->query("combat_exp")/100) );
		if((int)me->query("shen")>=100000)
		{if((string)me->query("gender")=="女性")
			command("chat 哈哈!旷世侠女"+me->name()+"真是难得一遇啊。\n");
		else 
			command("chat 哈哈!旷世大侠"+me->name()+"真是难得一见啊.\n");
		}
                  if((int)me->query("shen")<= -100000)
                  {if((string)me->query("gender")=="女性")
                         command("chat 嘿嘿!女魔王"+me->name()+"真是难得一遇啊。\n");
                  else 
                         command("chat 嘿嘿！盖世魔王"+me->name()+"真是难得一见啊.\n");
                              }
        	return 1;
	}
}
