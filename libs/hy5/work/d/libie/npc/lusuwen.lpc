#include <ansi.h>
inherit NPC;
void dreamsay();
void create()
{
        set_name("吕素文", ({ "lu suwen","lu" }) ); 
        set("gender", "女性" );
        set("age", 22);
        set("str", 100);
        set("per", 50);
        set("long", @LONG
一身素衣，打点的干干净净，无情的岁月在一张本是清秀动人的面庞上
留下了些许苍老与疲倦。
LONG
); 
        
        set("combat_exp", 10); 
        set("attitude", "friendly"); 
        setup();
        this_object()->disable_player( HIG "<睡梦中>"NOR);
//      this_object()->set_temp("is_unconcious",1);
//      set_temp("block_msg/all", 1);
//      COMBAT_D->announce(this_object(), "unconcious"); 
        carry_object(__DIR__"obj/white_cloth")->wear();
} 
int accept_fight(object me)
{
        command("emote 睡得正香，一点反应都没有。");
        return 0;
}  
void init()
{
        if( !query_heart_beat(this_object()) ) set_heart_beat(1);
        add_action("do_answer","answer");       
        if(!living(this_object()))
        if(!query("开始说梦话"))
        {
                set("开始说梦话",1);
        call_out("dreamsay",10+random(100));
        }
   ::init();
} 
void dreamsay() 
{       object room; 
        if(!living(this_object())&&this_object()->query("disable_type")==HIG"<睡梦中>"NOR)
        {
                room=environment(this_object());
                message("vision",HIG "吕素文翻过身，长长的睫毛闪着幸福的泪光，睡梦中喃喃道：杨铮哦，你回来了，\n饭菜凉了。。。我这就去热。。\n"NOR,room);
                call_out("dreamsay",10+random(100));
        }
        else
                delete("开始说梦话");
        return;
} 
void heart_beat()
{
        int msg;
        object me,lu,sheet;
         
        if(!living(this_object())&&this_object()->query("disable_type")==HIG"<睡梦中>"NOR)
        if(!query("开始说梦话"))
        {
                set("开始说梦话",1);
                call_out("dreamsay",10+random(10));
        }
        if(msg=query("dying_msg"))
        {
                me=environment()->query("结局1人物");
                lu=this_object();
                if(msg==4)
            message_vision("$N平静地问：我夫君是不是已经不在人世了？\n",lu);
                if(msg==3)
                        me->ccommand("hmm");
                if(msg==2)
            message_vision("$N眼神变得迷离，口中轻呓道：杨郎。。。我来了。。\n
吕素文的声音越来越微弱。。。\n",lu);
                if(msg==1)
                {
            message_vision(HIG"\n$N似又睡着了，疲倦的脸上露出安详的微笑。。。
微风在轻轻叹息，窗外飞过的雀儿在低低啁啾，一切归于宁寂。。。\n"NOR,lu);
                   sheet=new(__DIR__"obj/sheet");
                        sheet->move(this_object());
                        me->set("libie/离别钩_尾声",1);
                        lu->die();
                }
                add("dying_msg",-1);
        }
        ::heart_beat();
} 
void sleep()
{
        message("vision","吕素文打了个呵欠，重新睡了过去。\n",environment());
        this_object()->set_temp("is_unconcious",1);
        this_object()->disable_player(HIG "<睡梦中>"NOR);
} 
void wake(object me)
{       string msg;
        object room;
        
        
        this_object()->delete_temp("is_unconcious");
        this_object()->enable_player();
        room=environment();
        if (present(me->query("id"),room)) 
                message_vision(HIG"吕素文睁开双眸，惊呼一声。盯着$N。\n"NOR,me);
        else message("vision",HIG"吕素文睁开双眸，惊呼一声。\n"NOR,room); 
} 
int dying(object me)
{
        set("dying_msg",4);
        heart_beat();
        return 1;
} 
void die()
{       object me,corpse,*inv,room;
        int i; 
        room=environment();
        if(me=room->query("结局1人物"))
                me->delete_temp("离别钩_目睹最后结局");
        corpse=new("/d/libie/obj/lucorpse");
   corpse->move(room);
        inv=all_inventory(this_object());
        i=sizeof(inv);
        while(i--)
                inv[i]->move(corpse);
        message_vision("吕素文死了\n",this_object());
        destruct(this_object());
                
}  
int ask_question(object me)
{       
        if(environment(me)!=environment()) return 0; 
    message_vision(HIY "吕素文看了眼热气滕滕的饭菜，若有所思，整了整衣襟，正色道：阁下
是蓝大侠差来送食的吧？(answer yes or no)\n"NOR,me);
        this_object()->set("add_answer",me);
        return 1;
} 
int do_answer(string arg)
{
    object ob, me, book;
    ob = this_object();
    
    if(!ob->query("add_answer")) return 0;
    me = ob->query("add_answer");
    if (objectp(ob))
    if( living(ob))
    {
    if( arg == "yes" )
    {
        if(!me->query("libie/离别钩_送饭")){
        message_vision(HIY "吕素文道了个万福，沉思片刻，取出本残破古书给$N：这位"+RANK_D->query_respect(me)+"衔食之恩，无
以为报，这乃我夫君的『离别剑谱』，就赠与阁下吧。\n"NOR, me);
        book=new(__DIR__"obj/swordbook");
        if(book) {
                book->move(me);
        }
        me->set("libie/离别钩_送饭",1);
        message("vision",HIC "吕素文微笑而坚定的说：顺请阁下告知蓝大侠，素文立过重誓，余生只
与我夫郎共饮。\n吕素文轻咳几声，又闭目无语。\n"NOR,me);
                } else {
           message_vision(HIY "吕素文道：贱妾心意已决，阁下请不必多言。\n"NOR,me);
        }
    } else if( arg == "no" ) {
        message_vision(HIG"吕素文微叹一声，闭目不语。\n"NOR, me);
    }
    remove_action("do_answer","answer");
    me->delete_temp("libie/离别钩_准备送饭");
    return 1;
    }
    
    return 0;
} 
