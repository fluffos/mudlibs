string party_auth(int auth)
{
	string zw;

	switch(auth)
	{
		case 1:
			zw = HIY "帮主" NOR;	break;
		case 2:
			zw = HIC "长老" NOR;	break;
		case 3:
			zw = HIG "护法" NOR;	break;
		case 4:
			zw = HIM "高级成员" NOR;	break;
		case 5:
			zw = HIW "普通帮众" NOR;	break;
	}
	return zw;
}
