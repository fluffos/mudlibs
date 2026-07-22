inherit NPC;
void create()
{	string name;
        set_name("老妇人", ({"fu ren","furen"}));
        set("age", 48);
        set("gender", "女性");
        set("attitude", "friendly");
        set("combat_exp", 3000);
        set_skill("unarmed", 10);
        set_skill("dodge", 20);
        setup();
}

int accept_object(object me, object ob)
{
        object book;
        
        if(userp(ob)) return 0;

        if( (string)ob->query("name")=="饭篮" && !me->query_temp("jiushu_get"))
        {
                command("say 多谢这位" + RANK_D->query_respect(me) + "！\n我这里有本附近拾到的旧书。\n");
                book=new("/d/obj/book/misc");
		book->move(me);
                return 1;
        }
        else
        {
            return 1;
        }
}
