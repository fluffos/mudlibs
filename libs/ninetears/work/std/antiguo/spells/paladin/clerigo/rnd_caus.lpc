object attackboy, defendboy, sucker;
int times=0;
object my_player;

void setshadow(object ob) 
{  
   shadow(ob,1);
  my_player=ob;
}


void destruct_rnd_caus_shadow()
{
  destruct(this_object());
}



int weapon_attack(object defdr, object atckr)
{
 object *alist;
 int num;
 attackboy=atckr;
 defendboy=defdr;
 alist=defendboy->query_attacker_list();
 num=random(sizeof(alist));
 sucker=alist[num];
 if(attackboy==sucker)
{
   times=times+1;
}
 if(times>4 && !attackboy->is_player())
 {
   attackboy->do_command("unwield weapon");
   attackboy->do_command("unwield weapon");
}
 return my_player->weapon_attack(sucker,atckr);
}
/**
void apply_damage(int hps)
{
  tell_object("at the top\n",attackboy);
if(attackboy==sucker)
{
  times=times+1;
 }
if (times > 3)
{
  printf("got here\n");
  attackboy->command("unwield weapon");
}
 //sucker->adjust_hp(-hps,attackboy);
 return;
}
**/
void write_message(int damage, string w_type, object attr, object defdr)
{
 return my_player->write_message(damage,w_type,attr,sucker);
}
