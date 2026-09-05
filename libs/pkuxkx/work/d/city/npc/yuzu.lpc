

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;
int ask_for_chuyu();
void create()
{
	set_name("狱卒", ({ "yu zu", "zu" }));
	set("shen_type", 1);

	set("str", 30);
	set("gender", "男性");
	set("age", 25);
	set("long","一个平凡的狱卒\n");
	set("combat_exp", 5500);
	set("attitude", "friendly");
	set("inquiry", ([
		"出狱" :(:ask_for_chuyu:),

	]));
		setup();
}


int ask_for_chuyu()
{
   object me=this_player();
   if(!me->query("canchuyu")) 
     {
        message("vision","狱卒鄙夷的对你说道：出狱？来了这里就的给我把牢底坐穿!\n",me);    
        return 1;
     }
    message("vision","想不到还有人保你这样的走私犯，算你走运，滚吧!\n",me);
    me->delete("fanfa");
me->delete("canchuyu");
    me->move("/d/city/kedian");
    return 1;
}

