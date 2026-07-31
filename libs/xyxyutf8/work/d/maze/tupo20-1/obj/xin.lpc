#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("信笺",({"xin jian","xin"}));
	if(clonep())
		set_default_object(__FILE__);
        else 
        {
                set("unit", "张");
                set("value", 0);
		set("long","一张带着微微清香的笺纸，好似是从哪本笔记中裁下的。\n");
	}
        setup();
}

int init_owner(object who)
{
	int i;
	string *name,long,str,*yao,arg;
	if( !who || ( !wizardp(who)&& who->query_level()!=19 ) )
		return 0;
	if( !stringp(long=who->query_temp("tupo20/xin")) )
	{
		long = "一张带着微微清香的笺纸，好似是从哪本笔记中裁下的。上面数行纤细秀气的小字：\n";
		long+= "\t    余尚于古山中偶得一丹方，虽于某者无用，然此方对初习之辈大善，\n";
		long+= "\t今录之，以期有缘者得之，吾道不孤。\n";
		long+= "\t    此丹无名，有洗髓炼气之效，故余将之名曰：炼气丹。\n";
		name = ({
  			"野参果","人参","雪莲","枸杞","灵芝","铜皮石斛",
  			"佛手","肉豆蔻","连翘","荆芥","茯苓",
		});
  		i = 3+random(3);
  		yao = ({});
  		arg = "";
  		while(i--)
  		{
  			str = name[random(sizeof(name))];
  			arg+= str;
  			if( i!=0 )
  				arg+= "、";
  			yao+= ({str});
  			name-= ({str});
  		}
  		who->set_temp("tupo20/yao",yao);
  		long+= "\t      "+arg+chinese_number(sizeof(yao))+"味药材乃成。\n";
  		who->set_temp("tupo20/xin",long);
	}
	set("long",long);
	return 1;
}
	