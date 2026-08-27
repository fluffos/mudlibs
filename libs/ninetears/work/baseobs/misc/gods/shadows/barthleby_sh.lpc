// anhadido query_god_shadow()
object myp;

void dest_barthleby_shadow()
{
	destruct(TO);
}

void setup_shadow(object ob)
{
	shadow(ob, 1);
	myp = ob;
}

int query_barthleby_shadow()
{
	return 1;
}

string query_god_shadow()
{
	return "Barthleby";
}

int adjust_hp(int amount, object hitter)
{
	int danyo;

	if (!hitter || !living(hitter) || hitter==myp || amount >= 0 ||
	myp->query_mirror_spell() || myp->query_stoneskin_spell())
		return myp->adjust_hp(amount, hitter);
	if (random(1000) <= myp->query_cha()) {
		tell_object(myp, "Tu %^BOLD%^brazalete %^RESET%^brilla cegadoramente y devuelve el danyo a su origen!\n");
		tell_object(hitter, "El %^BOLD%^brazalete %^RESET%^de "+myp->QCN+" brilla cegadoramente para devolverte tu ataque!\n");
		tell_room(ENV(myp), "El %^BOLD%^brazalete %^RESET%^de "+myp->QCN+" brilla cegadoramente al devolver el ataque!!\n", ({myp, hitter}));
		hitter->really_adjust_hp(amount, myp);
		return 0;
	}
	switch (random(400)) {
		case 0..2:
			tell_object(myp, "Tu %^BOLD%^brazalete %^RESET%^detiene el impacto!\n");
			tell_room(ENV(myp), "El %^BOLD%^brazalete %^RESET%^de "+myp->QCN+" detiene el impacto!\n", myp);
			return 0;
			break;
		case 3..12:
			tell_object(myp, "Tu %^BOLD%^brazalete %^RESET%^brilla intensamente al absorber parte del danyo!\n");
			tell_room(ENV(myp), "El %^BOLD%^brazalete %^RESET%^de "+myp->QCN+" brilla intensamente para absorver parte del danyo!\n", myp);
			danyo = random(-(amount * 0.5)) - 4;
			if (danyo <= 0)
				danyo = 1;
			break;
		case 13..32:
			tell_object(myp, "Tu %^BOLD%^brazalete %^RESET%^brilla ligeramente al absorber parte del danyo!\n");
			tell_room(ENV(myp), "El %^BOLD%^brazalete %^RESET%^de "+myp->QCN+" brilla ligeramente para absorver parte del danyo!\n", myp);
			danyo = -(amount * 0.75) - 3;
			if (danyo <= 0)
				danyo = 1;
			break;
		case 33..99:
			danyo = -amount - 3;
			if (danyo <= 0)
				danyo = 1;
			break;
		case 100..299:
			danyo = -amount - random(3)+1;
			if (danyo <= 0)
				danyo = 1;
			break;
		case 380..399:
			tell_object(myp, "Tu %^BOLD%^brazalete %^RESET%^libera parte de su energia sobre ti!\n");
			tell_room(ENV(myp), "El %^BOLD%^brazalete %^RESET%^de "+myp->QCN+" libera parte de su energia sobre "+ ((myp->query_gender() == 1) ? "el":"ella") + "!\n", myp);
			danyo = -amount + random(10) + 1;
		default:
			danyo = -amount;
	}
	return myp->adjust_hp(-danyo, hitter);
}
