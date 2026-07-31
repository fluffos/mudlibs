inherit NPC;
string *name=({"书生","侍女","员外","夫人","公子","小姐","强盗"});
string *gender=({"男","女","男","女","男","女","男"});
string *id=({"shusheng","shinu","yuanwai","furen","gongzi","xiaojie","qiangdao"});
void create()
{
    int i;
    i=random(sizeof(name));
    set_name(name[i],({id[i]}));
    set("gender",gender[i]+"性");
    set("attitude","friendly");
    set_skill("unarmed",10);
    set("chat_chance",1);
       set("chat_msg",({
            (:random_move:),
     }));
    setup();
add_money("coin",30);
carry_object("/clone/cloth/cloth")->wear();
}
