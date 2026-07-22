        object lingpai;
        restore();
        if(query("banghui"))    {
                lingpai=new("/obj/lingpai");
                lingpai->create(query("banghui"));
                if(lingpai->query("no_use"))    {
                        delete("banghui");
                        save();
                        destruct(lingpai);
                }
                else    destruct(lingpai);
        }
        set_name(query("name"),({query("id")}));
	set("max_neili",(int)query_skill("force")*10);
	set("max_qi",220+(int)query_skill("force")*10/4);
	set("bellicosity",0);
        set("qi",query("max_qi"));
        set("eff_qi",query("max_qi"));
        set("jing",query("max_jing"));
        set("eff_jing",query("max_jing"));
        set("neili",query("max_neili"));
