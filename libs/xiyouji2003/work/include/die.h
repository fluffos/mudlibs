/******************************************/
/* MUDLIB：Biographies         〓悟空传〓  */
/* Created Admin By Waiwai@2001/02/18     */
/* Admin Email：wkzstory@21cn.com         */
/******************************************/
// Last modified by waiwai@2001/05/04
// 帮会配套文件

#include "ansi.h"

void die()
{
        int kaifa;
        int kf;
        string banghui;
        object area, killer;

	// 异地驻留NPC特殊设置
	if(query("lead_S")) {
	new(this_object()->query("Snpc"))->move("/obj/empty"); 
	return ::die();
	}

        if(base_name(environment())+".lpc"!=query("area_file"))
                return ::die();
        if(! stringp(banghui=query("banghui")))
                return ::die();

        area=new("/obj/area");
        area->create(query("area_name"));
        if(area->query("no_use")) {
                destruct(area);
                return ::die();
        }
        kaifa=area->query("kaifa");
        kf=query("kaifa");
        if( kf==kaifa) {
		destruct(area);
		return ::die();
        }
        kaifa=kaifa-(random(10)+1);
        if(kaifa<=kf)    kaifa=kf;
        area->set("kaifa",kaifa);
        area->save();
        destruct(area);
        message("channel:rumor",WHT"〖帮会消息〗由于"+query("name")+NOR WHT
        "被杀，"+query("area_name")+"地盘的开发度降为 "HIR+kaifa+" \n"NOR,users());
        return ::die();
}
