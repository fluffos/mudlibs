// hp_d.c this is used to handle hp system
// by fire on Jan 1999

#define GROWAGE 30  // below this age, hp increases
#define DAMPAGE 50  // above this age, hp decreases
#define GROWHP 10   // how much hp increases in one year
#define DAMPHP 2    // how much hp decreases in one year
#define WXHP 2      // how much hp increases with one level of WX

int query_max_hp(int age,int wxxy) {
	int ret = 100;
	int tmp = 0;
	if (age > 14) {
		tmp = age - 14;
                tmp = bmin(tmp, GROWAGE-14);
		ret += tmp*GROWHP;
		if(age > DAMPAGE) {
			ret -= (age-DAMPAGE)*DAMPHP;
		}
	}
	if(wxxy > 30) {
		ret += (wxxy-30)*WXHP;
	}
	return ret;
}

int set_max_hp(object o,int force) {
	int age, wxxy;
	int maxhp;
	if (!objectp(o)) return -1;
	age = o->query_age();
	wxxy = o->query_sk_level("sk_wuli");
	maxhp = query_max_hp(age, wxxy);
	o->set_sg_max_hp(maxhp);
	if(force||(!objectp(o->query_link()))) {
		o->set_cur_max_hp(maxhp);
		o->set_cur_hp(maxhp);
		o->set_last_hp_check(time());
	}
	return 1;
}

int query_max_mp(int age, int sk_zhimou) {
	int ret = 100;
	int tmp;
	if (age > 14) {
		tmp = age-14;
		tmp = bmin(tmp, GROWAGE-14);
		ret += tmp*GROWHP;
		if (age > DAMPAGE) {
			ret -= (age-DAMPAGE)*DAMPHP;
		}
	}
	if(sk_zhimou > 30) {
		ret += (sk_zhimou - 30)*WXHP;
	}
	return ret;
}

int set_max_mp(object o,int force) {
	int age, sk_zhimou;
	int maxmp;
        if(!objectp(o)) return -1;
	age = o->query_age();
	sk_zhimou = o->query_sk_level("sk_zhimou");
        maxmp = query_max_mp(age, sk_zhimou);
	o->set_sg_max_mp(maxmp);
	if(force||(!objectp(o->query_link()))) {
		o->set_cur_max_mp(maxmp);
                o->set_chr_mp(maxmp);
                o->set_last_hp_check(time());
	}
	return 1;
}

int recover_full(object o) {
    set_max_hp(o,1);
    set_max_mp(o,1);
    o->add_food(1000);
    o->add_drink(1000);
}