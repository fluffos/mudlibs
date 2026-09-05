/* Version 1.o of the necro who listing */

necro_who() {

int a, b;
string who, loc, gld;
object ob;

ob = users();

write("--------------------------------------------------------------------------\n");
write(" -> Name          Race      Lvl/Xl   Guild      Location\n");
write("--------------------------------------------------------------------------\n");

for(b=0; b<sizeof(ob); b+=1) {
  if(!ob[b]->query_invis()) {
write("   ");
write(pad(ob[b]->query_name(),15));
  if(ob[b]->query_name() == "Pain"){
write(pad("fool",9)); }
else {
write(pad(ob[b]->query_race(),9));
}
write(" ");
write(pad(ob[b]->query_level(),3));
write("/");
write(pad(ob[b]->query_extra_level(),5));
if(ob[b]->query_guild_name() == 0) {
   gld = "none"; }
if(ob[b]->query_guild_name() == "NONE"){
  gld = "none"; }
if(ob[b]->query_guild_name() == "necromancer"){
   gld = "necromncr"; }
if(ob[b]->query_guild_name() == "Knights Templar"){
   gld = "templar"; }
if(ob[b]->query_guild_name() == "polymorph"){
   gld = "polymorph"; }
if(ob[b]->query_guild_name() == "vampire"){
   gld = "vampire"; }
if(ob[b]->query_guild_name() == "healer"){
   gld = "healer"; }
if(ob[b]->query_guild_name() == "dervish"){
   gld = "dervish"; }
if(ob[b]->query_guild_name() == "symbiote"){
   gld = "symbiote"; }
if(ob[b]->query_guild_name() == "cyberninja"){
   gld = "cyberninj"; }
if(ob[b]->query_guild_name() == "rangers"){
   gld = "ranger"; }
if(ob[b]->query_guild_name() == "dark rangers"){
   gld = "dark rangr"; }
if(ob[b]->query_level() > 20){
   gld = "wizard"; }
write(pad(gld,9));
write("  ");
if(!environment(ob[b])) loc = "LOGIN";
else
loc = environment(ob[b])->short();
write(pad(loc,26));
write(NORM+NORM);
write("\n");
   }
}

write("--------------------------------------------------------------------------\n");
return 1; }

