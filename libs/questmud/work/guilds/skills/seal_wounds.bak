
#define MASTERY_D "/daemons/mastery_d"
get_time() {
  return random(3)+2;
}
query_type() { return "neutral"; }
ep_cost() { return 5; }

resolve_skill(str) {
    object target, fa_ob;
    int effect;
    if(!str) {
                write("Use seal wounds at what?\n");
                return 1;
        }
        if(this_player()->query_attack()) {
                write("You can't seal wounds in combat.\n");
                return 1;
        }
        if(this_player()->query_hp() == this_player()->query_max_hp()) {
                write("You aren't wounded!\n");
                return 1;
        }
        target = present(str, environment(this_player()));
        if(!target || !living(target)) {
         write(capitalize(str)+" is not a valid target.\n");
         return 1;
    }
    fa_ob = present("seal_wounds_ob", target);
    effect = this_player()->query_sp()/2+this_player()->query_skill("knowledge of meditation");
    effect += MASTERY_D->mastery("Mastery of mind focusing",this_player(),target)*3;
    write("You try to seal "+capitalize(str)+"'s wounds.\n");
    say(this_player()->query_name()+" tries to seal "+capitalize(str)+"'s wounds.\n");
    if(target != this_player()) {
        tell_object(target, this_player()->query_name()+" tries to seal your wounds.\n");
    }
    target->heal_hp(effect);
    if(target->query_bleeding()) {
        target->end_bleeding();
    }
  this_player()->set_sp( ( this_player()->query_sp() - effect + MASTERY_D->mastery("Mastery of mind focusing",this_player(),target) + this_player()->query_skill("knowledge of meditation")));
}
fail_skill(str) {
    write("You fail the skill.\n");
    say(this_player()->query_name()+" fails the skill.\n");
}

