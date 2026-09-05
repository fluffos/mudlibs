// 牧人
// create by zine Aug 30 2010

inherit NPC;
#include <ansi.h>
int ask_path();
void create()
{
	set_name(WHT"老年牧人"NOR, ({"mu ren", "ren", "muren"}));
    set("long","这是一个上了年纪的牧人，最熟悉草原和大漠的就是他们这些人了。\n");
	set("gender", "男性");
	set("age", 50+random(15));
    set("combat_exp", 7500);
    set_skill("unarmed", 35);
    set_skill("force", 35);
    set_skill("dodge", 40);
    set_temp("apply/attack", 30);
    set_temp("apply/defense", 40);
	set("shen_type", -1);
    set("inquiry", ([
            
			"path" : (: ask_path :),
            "指路" : (: ask_path :),
            
       	]) );
	setup();
	carry_object(__DIR__"items/pixue")->wear();
	carry_object(__DIR__"items/cloth2")->wear();
	
}
	
int ask_path()
{
    object migong,env,me=this_player(),ob=this_object();
    string posi,path_n,path_e,path_w,path_s;
    env=environment(ob);
    if (this_object()->query("startroom")!=base_name(env))
    {
        command("say 我也不知道怎么到了这里，我都自身难保了，还怎么指点别人？");
        return 1;
    }
    else if (ob->is_busy())
    {
        tell_object(me,ob->query("name")+"正忙着呢！\n");
        return 1;
    }
    else 
    {
        if (!env->query("migong")||!env->query("migong_posi"))
        {
            command("say 现在大漠草原的路途经常变化，我也不是很清楚了！");
            return 1;
        }
        migong=load_object(env->query("migong"));
        if (!migong->query("pathways"))
        {
            command("say 现在大漠草原的路途经常变化，我也不是很清楚了！");
            return 1;
        }
        posi=env->query("migong_posi");
        if (posi=="north")
        {
            path_e=migong->query("pathways/n_path")+migong->query("pathways/path_e");
            path_w=migong->query("pathways/n_path")+migong->query("pathways/path_w");
            path_s=migong->query("pathways/n_path")+migong->query("pathways/path_s");
        }
        if (posi=="south")
        {
            path_e=migong->query("pathways/s_path")+migong->query("pathways/path_e");
            path_w=migong->query("pathways/s_path")+migong->query("pathways/path_w");
            path_n=migong->query("pathways/s_path")+migong->query("pathways/path_n");
        }
        if (posi=="east")
        {
            path_n=migong->query("pathways/e_path")+migong->query("pathways/path_n");
            path_w=migong->query("pathways/e_path")+migong->query("pathways/path_w");
            path_s=migong->query("pathways/e_path")+migong->query("pathways/path_s");
        }
        if (posi=="west")
        {
            path_n=migong->query("pathways/w_path")+migong->query("pathways/path_n");
            path_e=migong->query("pathways/w_path")+migong->query("pathways/path_e");
            path_s=migong->query("pathways/w_path")+migong->query("pathways/path_s");
        }
        if (path_e)
        {
            if (random(2))
            {
                command("tell "+me->query("id")+" 要穿过"+migong->query("migong_name")+"，到达东边，路径是"+path_e+"，千万不要走错了！");
            }
            else
            {
                command("whisper "+me->query("id")+" 要穿过"+migong->query("migong_name")+"，到达东边，路径是"+path_e+"，千万不要走错了！");
            }
        }
        if (path_s)
        {
            if (random(2))
            {
                command("tell "+me->query("id")+" 要穿过"+migong->query("migong_name")+"，到达南边，路径是"+path_s+"，千万不要走错了！");
            }
            else
            {
                command("whisper "+me->query("id")+" 要穿过"+migong->query("migong_name")+"，到达南边，路径是"+path_s+"，千万不要走错了！");
            }
        }
        if (path_w)
        {
            if (random(2))
            {
                command("tell "+me->query("id")+" 要穿过"+migong->query("migong_name")+"，到达西边，路径是"+path_w+"，千万不要走错了！");
            }
            else
            {
                command("whisper "+me->query("id")+" 要穿过"+migong->query("migong_name")+"，到达西边，路径是"+path_w+"，千万不要走错了！");
            }
        }
        if (path_n)
        {
            if (random(2))
            {
                command("tell "+me->query("id")+" 要穿过"+migong->query("migong_name")+"，到达北边，路径是"+path_n+"，千万不要走错了！");
            }
            else
            {
                command("whisper "+me->query("id")+" 要穿过"+migong->query("migong_name")+"，到达北边，路径是"+path_n+"，千万不要走错了！");
            }
        }
        ob->add_busy(random(2)+1);
        return 1;
    }
}