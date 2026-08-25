{\rtf1\ansi\ansicpg936\deff0\deftab720{\fonttbl{\f0\fswiss MS Sans Serif;}{\f1\froman\fcharset2 Symbol;}{\f2\fnil\fcharset134 \'cb\'ce\'cc\'e5;}}
{\colortbl\red0\green0\blue0;}
\deflang2052\horzdoc{\*\fchars !),.:\'3b?\}]\'a1\'a2\'a1\'a3\'a1\'a4\'a1\'a5\'a1\'a6\'a1\'a7\'a1\'a8\'a1\'a9\'a1\'aa\'a1\'ab\'a1\'ac\'a1\'ad\'a1\'af\'a1\'b1\'a1\'b3\'a1\'b5\'a1\'b7\'a1\'b9\'a1\'bb\'a1\'bd\'a1\'bf\'a1\'c3\'a3\'a1\'a3\'a2\'a3\'a7\'a3\'a9\'a3\'ac\'a3\'ae\'a3\'ba\'a3\'bb\'a3\'bf\'a3\'dd\'a3\'e0}{\*\lchars ([\{\'a1\'ae\'a1\'b0\'a1\'b2\'a1\'b4\'a1\'b6\'a1\'b8\'a1\'ba\'a1\'bc\'a1\'be\'a3\'a8\'a3\'db\'a3\'fb\'a3\'ae\'a1\'a4}\pard\nowwrap\nooverflow\plain\f2\fs21 // offspring.c
\par 
\par inherit PMODULES+"m_charnpc";
\par inherit M_GETTABLE;
\par 
\par void setup(string m_id,string u_id)
\par \{
\par \tab object jia,o_h;
\par \tab mixed c;
\par \tab o_h=SGHOME(m_id);
\par \tab c=o_h->get_npc(u_id);
\par \tab 
\par \tab set_gettable(1);
\par \tab set_name(c["id"],c["name"]);
\par \tab set_gender(c["gender"]);
\par \tab set_age(c["age"]);
\par \tab set_sg_rongmao(c["rongmao"]);
\par \tab set_in_room_desc(c["pre_name"]+"("+c["id"]+")");
\par \tab jia=OBJ_D->clone_obj((NAME)->get_dress(typ));
\par \tab jia->move(this_object());
\par \tab jia->do_wear();
\par 
\par    \tab add_question("age","age");
\par \tab 
\par \tab add_ask_str("age","$N\'ce\'ca$T\'a3\'ba\'c4\'e3\'b6\'e0\'b4\'f3\'c1\'cb\'a3\'bf\\n");
\par \tab 
\par \}
\par 
\par void special_answer(object who, string matt)
\par \{
\par \tab string p_id;
\par \tab p_id=who->query_primary_id();
\par         switch(matt)
\par         \{
\par                 case "age" :
\par \tab \tab \tab if(p_id==master) \{
\par \tab \tab \tab         this_object()->targetted_action(
\par \tab \tab \tab \tab "$N\'c3\'a6\'c9\'cf\'c7\'b0\'be\'cf\'b9\'aa\'b5\'c0\'a3\'ba$R\'d3\'d0\'ba\'ce\'b7\'d4\'b8\'c0\'a3\'bf\\n",who);
\par \tab \tab \tab \tab is_busy=1;
\par \tab \tab \tab \tab new(__DIR__+"free_menu")->start_menu(who,this_object());
\par \tab \tab \tab \tab return;
\par \tab \tab \tab \}
\par \tab \tab         this_object()->targetted_action(
\par \tab \tab \tab \tab "$N\'b5\'c9\'c1\'cb$T\'d2\'bb\'d1\'db\'a1\'a3\\n",who);
\par \tab \tab \tab \tab return;
\par         \}
\par \}
\par 
\par }
