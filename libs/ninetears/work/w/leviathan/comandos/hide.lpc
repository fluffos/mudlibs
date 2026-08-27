/* The hide in shadows shadow.  Cute huh? Dimmak. Evitar que los souls te 
 * descubran. Oct'98/ Vaeleth. kitando el desfase del callout de 0 (que no es 
 * 0), te escondes, gritas ya no te escondes Aokromes Mayo 2001, te proteges, 
 * ya no te escondes, intentas seguir mas de lo mismo. Aokromes Junio 2001 */
 
#define LEVEL_MOD 2
 
object tp;
 
int found;
 
void dest_hide_shadow();
 
void setup_shadow(object ob) {
   if(ob->query_hide_shadow())
   {
      return;
   }
  tp = ob;
  shadow(ob,1);
}
 
attack_by(object him)
{
  call_out("dest_hide_shadow",0);
  tp->dest_disfraz_shadow(); 
  return tp->attack_by(him);
}
 
int cast(string str)
{
  call_out("dest_hide_shadow",0);
  return tp->cast(str);
}
 
attack_ob(object him)
{
  call_out("dest_hide_shadow",0);
  tp->dest_disfraz_shadow();
  return tp->attack_ob(him);
}
 
object *move_player(string dir, string dest, string mess, object ob) {
  if ( !ob || ob != tp )
   call_out("dest_hide_shadow",0);
  return (object *)tp->move_player(dir, dest, mess, ob);
}
 
int do_death(string str) {
  call_out("dest_hide_shadow",0);
  tp->dest_disfraz_shadow();
  return (int)tp->do_death(str);
}
 
int do_loud_say(string str) {
   call_out("dest_hide_shadow",0);
  return (int)tp->do_loud_say(str);
}
 
int do_emote(string str) {
  call_out("dest_hide_shadow",0);
  return (int)tp->do_emote(str);
}
 
int do_echo(string str) {
  call_out("dest_hide_shadow",0);
  return (int)tp->do_echo(str); 
}
 
int do_protect(string str) {
  call_out("dest_hide_shadow",0);
  return (int)tp->do_protect(str); 
}
 
int do_unprotect(string str) {
  call_out("dest_hide_shadow",0);
  return (int)tp->do_unprotect(str); 
}
 
int follow(string str) {
  call_out("dest_hide_shadow",0);
  return (int)tp->follow(str); 
}
 
int follow_dummy(string str) {
  call_out("dest_hide_shadow",0);
  return (int)tp->follow(str); 
}
int do_shout(string str) {
  call_out("dest_hide_shadow",0);
  return (int)tp->do_shout(str);
}
 
int do_say(string str) {
  call_out("dest_hide_shadow",0);
  return (int)tp->do_say(str);
}
 
int give(string str) {
  call_out("dest_hide_shadow",0);
  return (int)tp->give(str);
}
 
int do_read(string str) {
  call_out("dest_hide_shadow",0);
  return (int)tp->do_say(str);
}
 
int event_player_search() {
  dest_hide_shadow(); //aqui es directo
}
 
int soul_com(string str) {
  int i;
  if ((i = (int)tp->soul_com(str)) == 1)
    dest_hide_shadow();
  return i;
}
 
void dest_hide_shadow() {
  if (!tp->query_disfrazado())
  	tell_room(environment(tp), "Notas a "+tp->query_cap_name()+" moverse "
      		"a tu alrededor.\n",({ tp }));
  else
  	tell_room(environment(tp), "Notas a "+tp->short()+" moverse "
      		"a tu alrededor.\n",({ tp }));
  
  tell_object(tp, "Te han descubierto!\n");
 TP->remove_timed_property("noguild");
 TP->remove_property("oculto",0);
 environment(tp)->add_timed_property("ENCONTRADO_ESCONDIDO",1,30);
  found = 1;
  tp->add_timed_property("recien_descubierto",environment(tp),2);
  destruct(this_object());
}
 
int query_hide_shadow()
{
  int i;
  i = random((int)tp->query_level() * LEVEL_MOD );
  i = (i==0) ? 1 : i;
  return i;
}
 
string pretty_short() { 
  if ((found && tp) || this_player()->query_property("sense_life"))
    return (string)tp->pretty_short();
  return 0;
}
 
string short() {
  if(found && tp || (query_verb() &&(query_verb()=="who" || query_verb()=="whopaged")) || this_player()->query_property("sense_life"))
    return (string)tp->short();
  return 0;
  return "";
}
 
string pretty_plural() {
  if (found && tp || this_player()->query_property("sense_life"))
    return (string)tp->pretty_plural();
  return 0; 
}
 
string query_plural() {
  if (found && tp || this_player()->query_property("sense_life"))
    return (string)tp->query_plural();
 return 0;
}
 
void soul_com_force(string str)
{
  return ;
}
 
string *parse_command_id_list()
{
  if (found || ENV(this_player())!=ENV(tp) || this_player()->query_property("sense_life") || tp==this_player()) return tp->parse_command_id_list();
  return ({ });
}

void destruct_hide_shadow_silencioso()
{
	destruct(this_object());	
}