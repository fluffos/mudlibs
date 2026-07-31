void die()
{
        int kaifa;
        int kf;
        string banghui;
        object area;
        if(base_name(environment())+".lpc"!=query("area_file"))
                return ::die();
        if(! stringp(banghui=query("banghui")))
                return ::die();
        area=new("/clone/misc/area");
        area->create(query("area_name"));
        if(area->query("no_use"))       {
                destruct(area);
                return ::die();
        }
        kaifa=area->query("kaifa");
        kf=query("kaifa");
        if( kf==kaifa)  {
                destruct(area);
                return ::die();
        }
        kaifa=kaifa-(random(10)+1);
        if(kaifa<=kf)    kaifa=kf;
        area->set("kaifa",kaifa);
        area->save();
        destruct(area);
        message("channel:rumor",YEL"【谣言】某人：由于"+query("name")+
        "被杀，"+query("area_name")+"的开发度降为"+kaifa+"！\n"NOR,users());
        return ::die();
}

