//farm_menu.c this is used to give order to leader of a base 
// command by fire on Jan 2000

#include <menu.h>
#include <mudlib.h>
#include <verb.h>
#include <ppl.h>

#define LOG_FILE "/sgdomain/base/base.log"

inherit MENUS;
inherit M_ACCESS;
inherit M_GRAMMAR;
inherit M_GLOB;
MENU toplevel;
MENU_ITEM quit_item;
MENU_ITEM seperator;
MENU_ITEM space;

protected object master,slave;
protected int poped;
protected string p_id,p_area,f_id;
protected string p_roomname,p_basename,p_headname;
protected string p_rumor="";

int log_me(string msg) {
	unguarded(1, (: write_file, LOG_FILE, msg :));
	return 1;
}

void set_rumor(string msg) {
	p_rumor=msg;
}
void do_nothing() {
        poped=0;
        modal_pop();

    call_out("quit_menu_application",2);

        if(objectp(slave)&&objectp(master)) {
                master->responda("nothing");
                slave->responda("doubt");
        }
}

object get_master() {
        return SGBASE(p_area,f_id);
}
void real_quit()
{
        if(poped&&(objectp(master)))
                modal_pop();
        remove_call_out("quit_menu_application");

        if(objectp(slave))
              slave->set_busy(0);
		if(sizeof(p_rumor)>0) 
		CHANNEL_D->deliver_tell("rumor","system",p_rumor);

		destruct(this_object());

}

void quit_menu_application()
{
        if(objectp(master)) {
                if(poped)
                        modal_pop();
                poped=0;
                if(objectp(slave))
                master->targetted_action(
                        "$N对$T道：现在没事了，先退下吧。\n",slave);
                DELAY_D->delay_simple_action(slave,
                        "$N一鞠躬道：是，然后退到一边！\n",2);
        }
        call_out("real_quit",4);
}

void do_query() {
        poped=0;
        modal_pop();

    call_out("quit_menu_application",5);

        if(objectp(slave)&&objectp(master)) {
            master->targetted_action("$N对$T道：这里情况怎么样啊？\n",slave);
            DELAY_D->delay_targetted_action(slave,master,
                        "$N对$T道："+
						get_master()->stat_me_total(),2);
        }
}

void do_addroom() {
        string p_ld;
        mixed ret;
        string job_id="buildbase";
        poped=0;
        modal_pop();

    call_out("quit_menu_application",5);

        if(objectp(slave)&&objectp(master)) {
            master->targetted_action("$N对$T道：生产不够呀，我看我们要再多开发一片"+
		p_roomname+"。\n",slave);
                if(CHAR_D->get_char(p_id,"level")>2) {
                        ret=get_master()->can_have_more_room();
                        if(stringp(ret)) {
                                DELAY_D->delay_targetted_action(slave,master,
                                        "$N对$T道："+ret+"\n",2);
                                DELAY_D->delay_simple_action(master,
                                        "$N轻轻的「哦」了一声，似乎明白了什么，又好像没懂。\n",3);
                                return;
                        } else if ( master->query_job(job_id,"count_lasttimes") > 
             JOB_D->query_job(job_id,"count_lasttimes")){
                                DELAY_D->delay_targetted_action(slave,master,
                                        "$N对$T道：$R今天做的"+JOB_D->query_job(job_id,"name")+
                                        "已经够多的了，应该休息一下了。\n",2);
                                DELAY_D->delay_simple_action(master,
                                        "$N轻轻的「哦」了一声，似乎明白了什么，又好像没懂。\n",3);
                                return;
                        } else {
                                p_ld=get_master()->get_leader();
                                master->set_asklist("buildbase","target",p_ld);
                                master->set_asklist("buildbase","filename",PJOB+"buildbase/buildbase")
;
                                master->set_asklist("buildbase","funname","ask_buildbase");

                                master->resign_job(job_id);
                                master->add_job("buildbase");
                                master->set_job("buildbase","status","begin");
                                master->set_job("buildbase","area",p_area);
                                master->set_job("buildbase","f_id",f_id);
                                master->set_job("buildbase","memo","征求"+CHAR_D->get_char(p_ld,"name")+"同意");

                                DELAY_D->delay_targetted_action(slave,master,
                                        "$N对$T道：修建新"+p_roomname+"是大事情，$R必须征求到本"+
                                        p_basename+"总监"+CHAR_D->get_char(p_ld,"name")+
                                        "的同意才可以，你去直接问他好了。\n",2);
                                DELAY_D->delay_simple_action(master,
                                        "$N轻轻的「哦」了一声，似乎明白了什么，又好像没懂。\n",3);
                                return;
                        }
                }
                else {
                                DELAY_D->delay_targetted_action(slave,master,
                                        "$N对$T道：$R职位不高，这样的事，下人也做不得主呀。\n",2);
                                DELAY_D->delay_simple_action(master,
                                        "$N轻轻的「哦」了一声，似乎明白了什么，又好像没懂。\n",3);

                }
        }

}
void do_gethead() {
        string p_ld;
        mixed ret;
        string job_id="gethead";
        poped=0;
        modal_pop();

    call_out("quit_menu_application",5);

        if(objectp(slave)&&objectp(master)) {
            master->targetted_action("$N对$T道：我们这个"+p_basename+
                        "有些"+p_roomname+"还没有"+p_headname+"，我们还需要雇佣一些"
                        +p_headname+"。\n",slave);
                ret=get_master()->no_head_room();
                if(!stringp(ret)) {
                        DELAY_D->delay_targetted_action(slave,master,
                                "$N对$T道：$R搞错了吧，我们人手已经够了。\n",2);
                        DELAY_D->delay_simple_action(master,
                                "$N轻轻的「哦」了一声，似乎明白了什么，又好像没懂。\n",3);
                        return;
                } else if ( (master->query_job(job_id,"beg_time")>0) &&(
         (time()-master->query_job(job_id,"beg_time"))<300)){
                        DELAY_D->delay_targetted_action(slave,master,
                                "$N对$T道：$R还没有去找"+master->query_job(job_id,"memo")+"呀。\n",2);
                        DELAY_D->delay_simple_action(master,
                                "$N轻轻的「哦」了一声，似乎明白了什么，又好像没懂。\n",3);
                        return;

                } else if ( master->query_job(job_id,"count_lasttimes") > 
         JOB_D->query_job(job_id,"count_lasttimes")){
                        DELAY_D->delay_targetted_action(slave,master,
                                "$N对$T道：$R今天做的"+JOB_D->query_job(job_id,"name")+
                                "已经够多的了，应该休息一下了。\n",2);
                        DELAY_D->delay_simple_action(master,
                                "$N轻轻的「哦」了一声，似乎明白了什么，又好像没懂。\n",3);
                        return;
                } else {
                        string m_area,m_id,m_name,m_zhou;
                        object o_guy;
                        m_area=AREA_D->pick_area();
                        m_zhou=AREA_D->get_area(m_area,"zhou");
                        o_guy="/sgdomain/event/ev_guy"->create_ppl(m_area);
                        m_id=o_guy->query_primary_id();
                        m_name=o_guy->query_name();
                        master->set_asklist(job_id,"target",m_id);
                        master->set_asklist(job_id,"filename",PJOB+job_id+"/"+job_id);
                        master->set_asklist(job_id,"funname","ask_"+job_id);

                        master->resign_job(job_id);
                        master->add_job(job_id);
                        master->set_job(job_id,"status","begin");
                        master->set_job(job_id,"area",p_area);
                        master->set_job(job_id,"f_id",f_id);
                        master->set_job(job_id,"memo",m_zhou+m_name);

                        DELAY_D->delay_targetted_action(slave,master,"$N对$T道：$R之言甚是有理，\n"+
                                DIRECTION_D->cdir(ret)+
                                "的"+p_basename+"还没有"+p_headname+"，听说"+m_zhou+
                                "有个叫"+m_name+"的人老实，能干。\n"+
                                "$R不妨去把他请来。\n",2);
                        DELAY_D->delay_simple_action(master,
                                "$N轻轻的「哦」了一声，似乎明白了什么，又好像没懂。\n",3);
                        return;
                }
        }
}

mixed can_fire_head(string r_id) {
	int pplnum;
	mixed head;
	head=get_master()->get_room(r_id);
	if(!mapp(head))
		return r_id+"方向没有"+p_roomname+"吧。";
	head=get_master()->get_room(r_id,"head");
	if(!mapp(head))
		return DIRECTION_D->cdir(r_id)+"方向的"+p_roomname+"还没有"+p_headname+"吧。";

	if(CHAR_D->get_char(p_id,"level")<3)
		return "$R职位不高，这样的事，下人也做不得主呀。";
	return 1;
	
}


void do_firehead(string r_id) {
	mapping head;
	string r_headname,c_rid;
	mixed ret;
	poped=0;
   	modal_pop();
    call_out("quit_menu_application",7);
	c_rid=DIRECTION_D->cdir(r_id);
	if(sizeof(c_rid)==0) c_rid=r_id;
    master->targetted_action("$N对$T道：我看"+c_rid+"方向的"+p_headname+"办事不利，不如解雇了。\n",slave);
	ret=can_fire_head(r_id);
	if(stringp(ret)) {
		DELAY_D->delay_targetted_action(slave,master,
			"$N对$T道："+ret+"\n",2);
		DELAY_D->delay_simple_action(master,
			"$N轻轻的「哦」了一声，似乎明白了什么，又好像没懂。\n",3);
		return;
	}
	head=get_master()->get_room(r_id,"head");
	r_headname=head["sname"]+head["gname"];
	get_master()->set_room(r_id,"head",0);

	DELAY_D->delay_targetted_action(slave,master,
		"$N对$T道：$R果然高明，$s也认为"+c_rid+
		p_roomname+"的"+p_headname+r_headname+
		"是个只吃饭不干活的人。只是解雇了"+p_headname+"该"+
		p_roomname+"就会停工。\n",2);
	DELAY_D->delay_targetted_action(master,slave,
		"$N对$T道：不用担心，我们很快就会找新人。\n",3);
	DELAY_D->delay_targetted_action(slave,master,
		"$N「哦」了一声对$T道：$R放心，$s这就去办。\n",4);
	DELAY_D->delay_simple_action(master,
		"$N满意地点了点头。\n",5);
	DELAY_D->delay_simple_action(master,
		p_headname+r_headname+"被解雇了。\n",6);
	get_master()->update_room(r_id);

	set_rumor(AREA_D->get_area(p_area,"name")+"解雇了"+p_headname+r_headname+"。");
	log_me(AREA_D->get_area(p_area,"name")+"解雇了"+p_headname+r_headname+"。");
	return;
}
void do_destroyroom() {
        do_nothing();

}

void create( )
{
    set_privilege(1);
}

void init_base_menu() {
    toplevel = new_menu("\n请问有和贵干：");
    quit_item = new_menu_item("退下", (:quit_menu_application:), "q");
    seperator = new_seperator
    ("----------------------------------------------------------------------");
    space = new_seperator
    ("                                                                     ");

    add_menu_item(toplevel, seperator);
    add_menu_item(toplevel, space);
    add_menu_item(toplevel, new_menu_item("询问情况",   (: do_query :),"1"));
    add_menu_item(toplevel, new_menu_item("增加"+p_roomname,   (: do_addroom :),"2"));

    add_menu_item(toplevel, new_menu_item("招募"+p_headname,   (: do_gethead :),"3"));
    add_menu_item(toplevel, new_menu_item("解雇"+p_headname,   (: get_input_then_call,
                (: do_firehead :) ,"解雇哪个"+p_roomname+"的"+p_headname+"：" :) ,"4"));


    add_menu_item(toplevel, new_menu_item("荒弃"+p_roomname,   (: get_input_then_call,
                (: do_destroyroom :) ,"荒弃哪个"+p_roomname+"：" :) ,"0"));



    add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, space);
    set_menu_prompt (toplevel, "输入指令[12340q]: ");

}

void start_menu(object m, object s,string a, string f)
{
        master=m;
        slave=s;
        p_id=master->query_primary_id();
        p_area=a;
        f_id=f;
        p_roomname=BASE_D->get_base(f_id,"roomname");
        p_basename=BASE_D->get_base(f_id,"name");
        p_headname=BASE_D->get_base(f_id,"headname");
	init_base_menu();

        poped=1;
        init_menu_application( toplevel );
        call_out("quit_menu_application",50);
}

void sp_quit_menu_application()
{
        remove_call_out("quit_menu_application");
		destruct(this_object());
}

