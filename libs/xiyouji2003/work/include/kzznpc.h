// Last modified by waiwai@2001/05/04

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
	 set("max_force",(int)query_skill("force")*10);
	 set("max_kee",220+(int)query_skill("force")*10/4);
	 set("max_mana",(int)query_skill("spells")*10);
	 set("max_sen",220+(int)query_skill("spells")*10/4);

	 set("bellicosity",0);
        set("gin",query("max_gin")*2);
        set("eff_gin",query("max_gin")*2);
        set("kee",query("max_kee")*2);
        set("eff_kee",query("max_kee")*2);
        set("sen",query("max_sen")*2);
        set("eff_sen",query("max_sen")*2);
        set("force",query("max_force")*2);
        set("mana",query("max_mana")*2);
        set("food",query("max_kee"));
        set("water",query("max_sen"));

