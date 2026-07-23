int help()
{
	write("2000 Ontario Tax Income Tax Calculator by YUJ@SJ\n");
	write("tc <your income> [<your spouse's income> [<children amount> [<rent>]]]\n");
	write("spouse's income < 0 means no spouse\n");
	return 1;
}

int width;

private void output(int no, string desc, float val)
{
	write(sprintf("%6d %'.'-43s %*.2f\n", no, desc, width, val));
}

private float tc(float income, float sp, int ch)
{
	float tmp, t260, t350, t6150, t419 = 0.0, t420, t428, t435;

	if (sp < 0.0)
		t350 = 0.0;
	else {
		t350 = 6754.0 - sp;
		if (t350 < 0.0)
			t350 = 0.0;
		else if (t350 > 6140)
			t350 = 6140.0;
	}
	t260 = income;
	output(260, "Taxable income ", t260);
	t350 += 7231.0;
	t6150 = t350 * 0.0637;
	t350 *= 0.17;
	output(350, "Total federal non-refundable tax credits ", t350);
	output(6150, "Total Ontario non-refundable tax credits ", t6150);
	write("\n");
	if (t260 <= 30004.0)
		t420 = t260 * 0.17;
	else if (t260 <= 60009.0)
		t420 = (t260 - 30004.0) * 0.25 + 5101.0;
	else
		t420 = (t260 - 60009.0) * 0.29 + 12602.0;
	t420 -= t350;
	if (t420 < 0)
		t420 = 0.0;
	if (t420 > 15500.0)
		t420 += t419 = (t420 - 15500.0) * 0.05;
	output(419, "Federal individual surtax ", t419);
	output(420, "Net federal tax ", t420);
	if (t260 <= 30004.0)
		t428 = t260 * 0.0637;
	else if (t260 <= 60009.0)
		t428 = (t260 - 30004.0) * 0.0962 + 1911.0;
	else
		t428 = (t260 - 60009.0) * 0.1116 + 4798.0;
	t428 -= t6150;
	if (t428 > 3561.0)
		t428 += (t428 - 3561.0) * 0.2;
	if (t428 > 4468.0)
		t428 += (t428 - 4468.0) * 0.36;
	tmp = 156;
	if (income > sp)
		tmp += ch * 317.0;
	tmp += tmp - t428;
	if (tmp > 0.0) {
		t428 -= tmp;
		if (t428 < 0.0)
			t428 = 0.0;
	}
	output(428, "Net Ontario tax ", t428);
	t435 = t420 + t428;
	output(435, "Total payable ", t435);
	write("\n");
	output(999, "Real income ", income -= t435);
	return income;
}

private float cc(float income, float sp, int ch, float rent)
{
	if (sp >= 0.0)
		income += sp;
	income -= 4000;
	income *= 0.02;
	if (income < 0.0)
		income = 0.0;
	rent *= 0.2;
	sp = sp < 0.0 ? 100.0 : 200.0;
	sp += rent * 0.1;
	if (rent > 250.0)
		rent = 250.0;
	rent += sp;
	rent += 50.0 * ch;
	rent -= income;
	if (rent < 0.0)
		rent = 0.0;
	else if (rent > 1000.0)
		rent = 1000.0;
	output(479, "Ontario property and sales tax credits ", rent);
	return rent;
}

int main(object me, string arg)
{
	float income = 0.0, sp = -1, rent = 0.0, total = 0.0;
	int ch = 0;

	if (!arg)
		return help();
	if (sscanf(arg, "%f %f %d %f", income, sp, ch, rent) != 4)
	if (sscanf(arg, "%f %f %d", income, sp, ch) != 3)
	if (sscanf(arg, "%f %f", income, sp) != 2)
	if (sscanf(arg, "%f", income) != 1)
		return help();
	if (income < 0.0 || income > 10000000.0)
		return help();
	if (ch < 0 || rent < 0.0)
		return help();
	width = strlen(sprintf("%.2f", income + sp + rent));
	write("\nYour income:\n");
	total = tc(income, sp, ch);
	if (sp >= 0.0) {
		write("Your spouse's income:\n");
		total += tc(sp, income, ch);
	}
	write("Family credits:\n");
	total += cc(income, sp, ch, rent);
	output(999, "Total family income ", total);
	output(999, "After taking out rent ", total - rent);
	return 1;
}
