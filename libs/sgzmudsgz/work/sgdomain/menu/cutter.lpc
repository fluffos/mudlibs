// cutter.c by fire 三国销刀
// this cmd is used create quick char
inherit CMD;
   
string p_area,p_id,p_name,p_zi;
int p_age,p_wuli,p_meili,p_zhimou;
int p_gender,p_rongmao;
object p_usr;


void over() {
   this_object()->remove();
   return;
}
void create_char() {
   CHAR_D->add_char(p_id);
   CHAR_D->set_char(p_id,"name",p_name);
   CHAR_D->set_char(p_id,"zi",p_zi);
   if(!sizeof(p_zi)) CHAR_D->set_char(p_id,"zi",0);
   CHAR_D->set_char(p_id,"age",p_age);
   CHAR_D->set_char(p_id,"gender",p_gender);

   CHAR_D->set_char(p_id,"rongmao",p_rongmao);
   CHAR_D->set_char(p_id,"wuli",p_wuli);
   CHAR_D->set_char(p_id,"zhimou",p_zhimou);
   CHAR_D->set_char(p_id,"meili",p_meili);

   CHAR_D->set_char(p_id,"area",p_area);
   CHANNEL_D->deliver_tell("rumor","system",
   p_name+"在"+AREA_D->get_area(p_area,"name")+"诞生。");

}
void input_area(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //  
   if(!AREA_D->area_exist(s)) {
      string *ars;
      ars=AREA_D->list_areas();
      s=ars[random(sizeof(ars))];
   }
   p_area=s;
   write("ID是："+p_id+"\n");
   write("名称是："+p_name+"\n");
   write("年龄是："+p_age+"\n");
   write("性别是："+(p_gender==1 ? "男": "女")+"\n");
   write("容貌是："+p_rongmao+"\n");
   write("字是："+ p_zi+"\n");
   write("武力是"+p_wuli+"\n");
   write("智谋是"+p_zhimou+"\n");
   write("魅力是"+p_meili+"\n");
   write("地区是"+p_area+"\n");
   create_char();  
   over();
}

void input_meili(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //  
   p_meili=to_int(s);
   if((p_meili<1)||(p_meili>30))
     p_meili=10+random(20);
   write("输入角色的地区，缺省为随机。\n");
   p_usr->modal_push((:input_area:),"",0,0);
}

void input_zhimou(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //  
   p_zhimou=to_int(s);
   if((p_zhimou<1)||(p_zhimou>30))
     p_zhimou=10+random(20);
   write("输入角色的魅力，[1-30]，缺省为随机。\n");
   p_usr->modal_push((:input_meili:),"",0,0);
}

void input_wuli(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //  
   p_wuli=to_int(s);
   if((p_wuli<1)||(p_wuli>30))
     p_wuli=10+random(20);
   write("输入角色的智谋，[1-30]，缺省为随机。\n");
   p_usr->modal_push((:input_zhimou:),"",0,0);
}

void input_rongmao(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //  
   p_rongmao=to_int(s);
   if((p_rongmao<10)||(p_rongmao>30))
     p_rongmao=10+random(20);
   write("输入角色的武力，[1-30]，缺省为随机。\n");
   p_usr->modal_push((:input_wuli:),"",0,0);
}

void input_zi(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //  
   p_zi=s;
   write("输入角色的容貌，[10-30]:缺省为随机。\n");
   p_usr->modal_push((:input_rongmao:),"",0,0);
}

void input_gender(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //  
   if(!sizeof(s)) {
     s="1";
   }
   p_gender=to_int(s);
   if(p_gender!=2) p_gender=1;
   write("输入角色的字，可以缺省。\n");
   p_usr->modal_push((:input_zi:),"",0,0);
}

void input_age(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //  
   p_age=to_int(s);

   if((p_age>70)||(p_age<10)) p_age=random(50)+10;
   write("输入角色性别[1 男|2 女]，缺省男。\n");
   p_usr->modal_push((:input_gender:),"",0,0);
}

void input_name(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //
   if(!sizeof(s)) {
     write("没有角色姓名。\n");
     over();
     return;
   }
   p_name=s;
     write("输入角色年龄[10-70],缺省为随机。\n");
   p_usr->modal_push((:input_age:),"",0,0);
}

void input_id(string s) {
   string fn,sn;
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //
   if(!sizeof(s)) {
     write("没有角色ID。\n");
	over();
     return;
   }
   if(sscanf(s, "%s %s", fn,sn)!=2) {
     write("角色ID必需有一空格。\n");
	over();
     return;
   }
   if(CHAR_D->char_exist(s)) {
     write("该角色已经存在。\n");
	over();
     return;
   }
   p_id=s;
   write("请输入角色名称：\n");
   p_usr->modal_push((:input_name:),"",0,0);
}

void main(object usr)
{
   object o;
   p_usr=usr;
   CHANNEL_D->deliver_tell("rumor","system",
   usr->query_body()->short()+"手持LIMA削刀，嚓，嚓削了起来。");
   write("请输入角色ID。\n");
   p_usr->modal_push((:input_id:),"",0,0);
}

