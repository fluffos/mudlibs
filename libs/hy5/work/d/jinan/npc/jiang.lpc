 inherit NPC;
void do_drink(); 
void create()
{
        seteuid(getuid());
        set_name("江重威", ({"jiang", "jiang chongwei"}));
        set("long",
"江重威本是朝廷重臣，但自从护送恭品被绣花大盗所劫，双目又被其\n刺瞎后，便终日接酒销愁，一蹶不振。殷正廉失意官场，与之同病相怜，\n因此安排他做手下的师爷，平日也没什么事。\n");
        set("title", "衙门师爷");
        set("gender","男性");
        set("age", 50);
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_force", 300);
        set("force", 300);
        set("max_mana", 300);
        set("mana", 300);
        set("combat_exp", 999999);
        set("can_carry", 1);
        set("no_heal",1);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70);
        set("fly_target",1);

        map_skill("unarmed", "meihua-shou");
        map_skill("dodge", "fall-steps");  
        set("chat_chance",3);
        set("chat_msg", ({
                "江重威瞎了的眼睛空洞无光，喃喃自语：酒。。酒。。。我要喝酒。。 \n江重威一把抓住快喝光的酒瓶，似乎要舔尽最后一滴酒。\n",
                (: do_drink :), 
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
void do_drink()
{
    object *list, ob;
    int i, can_drink;
    if ((int)this_object()->query("water") >= 380) return;
    list = all_inventory(this_object());
    i = sizeof(list);
    can_drink = 0;
    while (i--) {
        if ((string)list[i]->query("liquid/type") == "alcohol") {
            ob = list[i];
            can_drink = 1;
        }
    }
    if (can_drink) {
        command("drink "+(string)ob->query("id"));
        if ((int)ob->query("liquid/remaining") == 0)
            command("drop wineskin");
    }
    else
message_vision("$N用力吸了吸那因为酗酒而发红的鼻子．\n", this_object());
    return;
} 
int accept_object(object who, object ob)
{
    object obj;
    if ((string)ob->query("liquid/type")=="alcohol") 
    {
        if ((int)ob->query("liquid/remaining") == 0) 
        {
            command("shake");
            command("say 空的我不要...");
            return 0;
        }
        else if ((int)ob->query("value")<100)
        {
                message_vision("$N扫了一眼$n手中的"+ob->query("name")+"，\n骂了句：我好歹也是堂堂知府师爷，又岂能喝这种东西。。。\n",this_object(),who);
                return 0;
        }
        else 
        {
                message_vision("$N一把抓过$n手中的"+ob->query("name")+"，一饮而尽，大着舌头道：不过瘾，不过瘾，再来，再来。。。\n",this_object(),who);
                   this_object()->add("drink_wine",1);
                if (this_object()->query("drink_wine")==10)
                {
                        message_vision("$N醉眼朦胧，还想拿起酒袋往嘴里灌，却一个踉跄，摔倒在地。 \n",this_object());
                        message_vision("一张文谍从$N衣袖里掉了下来。 \n",this_object());
                        obj = new(__DIR__"obj/miling");
                        obj->move(environment(this_object()));
                }
                return 1;
        }
    }
    else
        return 0;
}   
