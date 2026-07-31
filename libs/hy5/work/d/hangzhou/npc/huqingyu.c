// huqingyu.c
#include <ansi.h>
#include <command.h>
//inherit F_CLEAN_UP;
inherit NPC;

void create()
{
        set_name("胡庆余",({ "hu qingyu","hu" }));
        set("gender", "男性" );
        set("age", 63);
        set("no_kill",1);
        set("no_fight",1);
        set_temp("no_kill",1);
        set("no_get",1);
        set("long",
"胡庆余是当世一大巫医，他的本事神奇无比。真有生死肉骨之功。\n");
        set("combat_exp", 200000);
        set("attitude", "friendly");
        set("inquiry", ([
            "改名": "好说，一百两黄金，款到即办！",
            "叛师": "找扬州城的李半仙吧！",
            "年龄": "这个价格嘛...!嘿嘿,一律一百两黄金年轻一岁。",
        ]) );
        set("chat_msg",({
            "胡庆余翘着二郎腿:要想唤回你们的青春,拿出你的诚意来!!\n",
            "胡庆余冷笑道:要叛师? 容易。快快拿出你的银子来!\n",
            "胡庆余淡淡说道:改个名,就是新人了。\n",
        }));
        setup();
}
void init()
{
        object ob,me;
        add_action("do_name","name");
        add_action("do_betrayer","betrayer");
        add_action("do_age","age");
}
int accept_object(object me, object ob)
{
        if( ob->query("money_id") && ob->value() >= 1000000)
        {
        command("nod");
        command("say 好吧，"+me->query("name")+"你说个章程！\n");
        me->set_temp("marks/huqingyu",1);
        return 1;
        }
}
int do_name(string arg,object me)
{
	string *banned_name = ({
	"你", "你", "我", "他", "她", "它", "它", "爸", "　",
	"翔少爷", "方舟子", "草鱼", "时空", "丁",
        "江泽民", "邓小平", "李鹏", "朱榕基",
        "自己", "某人", "尸体", "我们","你们", "他们", "大家",
        "他妈的", "去你的", "毛泽东", "巫师", "他奶奶的",
	"仙子", "天马行空", "迪阳", "风儿","星星","小人物","曹斌","胡锦涛","温家保","温家宝","薄熙来","刘延东","习近平","吴邦国","贾庆林","李长春","李克强","贺国强","周永康","李源潮","汪洋","俞振声","李克强","张德江","王岐山","李源潮","张高丽","刘云山"
	});
	int i;

        me = this_player();
        if(!(int)me->query_temp("marks/huqingyu"))
        {
            return notify_fail("胡庆余翻着黑白眼：钱呢？没给钱想占便宜？\n");
        }
        if( !arg ) return notify_fail("胡庆余笑道：名字总该写全吧。\n");
        if( strlen(arg) > 10 )
        return notify_fail("胡庆余惊呼起来：哪有这么长的名字？\n");
        if( strlen(arg) < 4 )
        return notify_fail("胡庆余哼了一声：这么短算啥名字？\n");
	while(i--) {
		if( arg[i]<=' ' ) {
			write("对不起，你的中文名字不能用控制字元。\n");
			return 0;
		}
		if( (strsrch(arg, "　") >= 0) ||
		    (strsrch(arg, "爸") >= 0)) {
			write("对不起，你的中文名字不能用引起误会的单字。\n");
			return 0;
		}
		if( (strsrch(arg, "(") >= 0) ||
		    (strsrch(arg, "小人物") >= 0)) {
			write("对不起，你的中文名字不能用引起误会的单字。\n");
			return 0;
		}
		if( (strsrch(arg, ")") >= 0) ||
		    (strsrch(arg, "小人物") >= 0)) {
			write("对不起，你的中文名字不能用引起误会的单字。\n");
			return 0;
		}

		if( i%2==0 && !is_chinese(arg[i..<0]) ) {
			write("对不起，请您用「中文」取名字。\n");
			return 0;
		}
	}
	if( member_array(arg, banned_name)!=-1 ) {
		write("对不起，这种名字会造成其他人的困扰。\n");
		return 0;
	}
	if( (strlen(arg) < 2) || (strlen(arg) > 10 ) ) {
		write("对不起，你的中文名字必须是 1 到 5 个中文字。\n");
		return 0;
	}

        me->delete_temp("marks/huqingyu");
        if (me->query("gender")=="女性")
        message_vision(CYN"胡大夫大笔一挥就改了$N的芳名 !真爽呆了....\n"NOR,me);
        else
        message_vision(CYN"胡大夫大笔一挥就改了$N的大名..真神!!\n"NOR,me);
        me->set("name",arg);

        return 1;
}

int do_betrayer(object me)
{
        mapping my_skl;
        string *skl_name;
        int i,*level;
        me = this_player();
        if(!(int)me->query_temp("marks/huqingyu"))
        {
            return notify_fail("胡庆余翻着黑白眼：钱呢？没给钱想占便宜？\n");
        }

        me->delete_temp("marks/huqingyu");
        if (me->query("combat_exp")<10000)
            return notify_fail("真冤枉!!你的经验还可以随便叛师的! \n");

        my_skl=me->query_skills();
        if(mapp(my_skl)) {
        		skl_name = keys(my_skl);
        		level=values(my_skl);
        		for (i=0;i<sizeof(skl_name);i++)
{
if (level[i]>3)
        		me->set_skill(skl_name[i],level[i]-2);
}
if (me->query("max_neili")>200)
{
me->add("max_neili",-100);
}
                  }
me->apply_condition("psgc",800);
        me->add("betrayer",1);
        me->set("title","普通百姓");
        me->set("class","0");
        me->delete("family");
        me->delete("party");
    message_vision(CYN"胡大夫笑道: 江湖上海阔天空, 都是$N的天地了! \n"NOR,me);

        return 1;
}

int do_age(object me)
{
        object obj;
        me = this_player();

        if(!(int)me->query_temp("marks/huqingyu"))
        {
            return notify_fail("胡庆余翻着黑白眼：钱呢？没给钱想占便宜？\n");
        }
//        me->delete_temp("marks/huqingyu");
//        return notify_fail("胡庆余翻着黑白眼：年龄暂时就不考虑了！\n");

        if (me->query("age")<49)
        {
            return notify_fail("胡大夫道: 你还不到七老八十的, 这一百两黄金白花了! \n");
        }

        if (me->query("mud_age")<864000)
        {
            return notify_fail("胡大夫道: 你还很年轻的, 这一百两黄金白花了! \n");
        }

        me->delete("last_alert");
        me->delete_temp("marks/huqingyu");
          me->add("mud_age",-86400);
          me->add("age",-1);
        message_vision(CYN"胡大夫道: 果然有钱能使鬼推磨, $N现在看是年轻多了! \n"NOR,me);

        return 1;
}                                           