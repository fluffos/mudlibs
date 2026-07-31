#include <ansi.h>
inherit NPC;
int ask_fail();
void create()
{
    set_name(HIY"康熙皇帝"NOR,({"kang xi"}));
    set("gender","男性");
    set_temp("no_kill",1);
    set("qi",1000000);
    set("eff_qi",1000000);
    set("max_qi",1000000);
set("jing",1000000);
    set("eff_jing",1000000);
       set("inquiry", ([
                "大清国宝藏" : (: ask_fail() :),
                "四十二章经" : (: ask_fail() :),
       ]) );

    setup();
carry_object(__DIR__"obj/longpao")->wear();
}
void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N沮丧地发现康熙皇帝根本不理会作战请求。\n", ob);
}

void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
	say( "康熙皇帝笑着说：动武对我没有用！\n");
	command("hehe");
}

void die()
{
	unconcious();
}


int ask_fail()
{
        object me = this_player(),obn;
if (random(3)==0)
this_object()->set("alr",1);
        
if (this_object()->query("alr"))
{
                command("say 已经有人找到宝藏了！");
                return 1;
                }
        if (me->query("huanggong/haspi1") != 1) {
                command("say 四十二章经一，你找到了吗");
                return 1;
                }
        if (me->query("huanggong/haspi2") != 1) {
                command("say 四十二章经二，你找到了吗");
                return 1;
                }
        if (me->query("huanggong/haspi3") != 1) {
                command("say 四十二章经三，你找到了吗");
                return 1;
                }
        if (me->query("huanggong/haspi4") != 1) {
                command("say 四十二章经四，你找到了吗");
                return 1;
                }
        if (me->query("huanggong/haspi5") != 1) {
                command("say 四十二章经五，你找到了吗");
                return 1;
                }
        if (me->query("huanggong/haspi6") != 1) {
                command("say 四十二章经六，你找到了吗");
                return 1;
                }
        if (me->query("huanggong/haspi7") != 1) {
                command("say 四十二章经七，你找到了吗");
                return 1;
                }
        if (me->query("huanggong/haspi8") != 1) {
                command("say 四十二章经八，你找到了吗");
                return 1;
                }
obn = new(__DIR__"obj/baotu");
obn->move(me);
me->delete("huanggong");
obn->set("bid",me->query("id"));
command("say 既然你知道了宝藏的位置,你要好好保存这份大清国宝藏图!");
command("say 你要用这份宝藏，来造福我大清子民!");
command("chat 今授于" + me->query("name") + "大清国宝藏图，望其能为百姓造逼!");
this_object()->set("alr",1);
return 1;
}
